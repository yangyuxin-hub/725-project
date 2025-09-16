#include "spectrum.h"
#include "application.h"

const QString spectrum::filePath = "Temp_Spec_"; // 保存文件的路径(txt)
double spectrum::m_Spectrum[MAX_NR_DEVICES][MAX_NR_PIXELS];
double spectrum::m_Lambda[MAX_NR_DEVICES][MAX_NR_PIXELS];

// 确保两个h文件中定义的类可以互相引用
#include "menu.h"
#include "ui_menu.h"

// 注意：本代码只支持USB连接，其他连接方式暂时未写。

spectrum::spectrum(application *app, QObject *parent)
    : QObject(parent), m_app(app)
{
    // // 连接设备
    // qDebug() << "[光谱]检测到的USB连接数量：" << AVS_Init(0);
    //     // AVS_Init(0)初始化通信，使用USB接口

    // m_NrOfDevices = AVS_UpdateUSBDevices(); // 检测到的光谱设备数量
    // qDebug() << "[光谱]检测到的光谱设备数量：" << m_NrOfDevices;

    // unsigned int RequiredSize = m_NrOfDevices * sizeof(AvsIdentityType);
    // unsigned int *pRequiredSize = & RequiredSize;
    // char *pDataIds = new char[RequiredSize];
    // AvsIdentityType *pList = (AvsIdentityType*)pDataIds; // 设备列表
    // qDebug() << "[光谱]列表中的设备数量：" << AVS_GetList(RequiredSize, pRequiredSize, pList); // 获取设备列表

    // a_hDevice = AVS_Activate(pList);
    // if (a_hDevice==INVALID_AVS_HANDLE_VALUE) qDebug() << "光谱仪通信激活失败";
    // else qDebug() << "光谱仪通信激活成功";

    // delete [] pDataIds;



    // 多通道采集 新增

    // 初始化
    timer = new QTimer(this);
    connect(m_app, SIGNAL(DataIsHere(int, int)), this, SLOT(ReceiveDataIsHere(int, int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_plot()));

    qDebug() << "[光谱]检测到的USB连接数量：" << AVS_Init(0);

    for (int i = 0; i < MAX_NR_DEVICES; i++)
    {
        m_Device[i].avsDeviceHandle = INVALID_AVS_HANDLE_VALUE;
        m_Device[i].NrMeas = 0;
    }

    // 更新设备列表
    UpdateList();

    // 激活所有设备
    activateDevice();
}

spectrum::~spectrum()
{
    AVS_Done(); // 大概是断开连接
}

bool spectrum::UpdateList() // 更新设备列表
{
    uint l_Size = 0;  // 定义一个无符号整型变量l_Size，用于存储数据大小
    uint l_RequiredSize = 0;  // 定义一个无符号整型变量l_RequiredSize，用于存储所需数据大小
    int lUsbDevListSize = 0;  // 定义一个整型变量lUsbDevListSize，用于存储USB设备列表的大小
    char* l_pDataIds = NULL;  // 定义一个字符指针l_pDataIds，用于存储设备ID列表数据
    AvsIdentityType* l_pId;  // 定义一个指向AvsIdentityType结构体的指针l_pId，用于存储设备ID信息

    lUsbDevListSize = AVS_UpdateUSBDevices();  // 更新USB设备列表，并返回设备数量
    l_RequiredSize = lUsbDevListSize;  // 设置所需数据大小为USB设备列表大小

    if (l_RequiredSize > 0)  // 如果设备列表大小大于0
    {
        // 第一次调用AVS_GetList()，仅用于确定DLL中设备ID数组的大小
        m_NrOfDevices = AVS_GetList(0, &l_RequiredSize, NULL);  // 获取设备ID列表所需大小
        l_pDataIds = new char[l_RequiredSize];  // 动态分配内存以存储设备ID列表数据
        l_pId = (AvsIdentityType*)l_pDataIds;  // 将数据指针转换为AvsIdentityType类型
        l_Size = l_RequiredSize;  // 设置实际数据大小为所需大小
        m_NrOfDevices = AVS_GetList(l_Size, &l_RequiredSize, l_pId);  // 获取设备ID列表
    }

    for (int i = 0; i < m_NrOfDevices; i++)  // 遍历所有设备
    {
        m_Device[i].avsID = *l_pId;  // 将设备ID信息存储到设备结构体中
        l_pId++;  // 移动到下一个设备ID
    }

    delete[] l_pDataIds;  // 释放设备ID列表数据内存
    return m_NrOfDevices > 0;
}

bool spectrum::activateDevice() // 激活所有设备
{
    for (int i = 0; i < m_NrOfDevices; i++)  // 遍历所有设备
    {
        int l_hDevice = AVS_Activate(&m_Device[i].avsID);  // 激活当前设备，并获取设备句柄
        if (INVALID_AVS_HANDLE_VALUE == l_hDevice) qDebug() << "设备句柄无效，设备激活失败";
            // 如果设备句柄无效，表示设备激活失败
        else  // 如果设备激活成功
        {
            m_Device[i].avsDeviceHandle = l_hDevice;  // 将设备句柄存储到设备结构体中
            int l_Ret = AVS_UseHighResAdc(l_hDevice, true);  // 启用设备的高分辨率ADC模式
            if (ERR_SUCCESS != l_Ret)  // 如果高分辨率模式启用失败
                qDebug() << "高分辨率模式启用失败";  // 弹出错误信息
            // 默认状态是异步模式
            AVS_SetSyncMode(m_Device[i].avsDeviceHandle, 0);  // 设置设备为异步模式
        }
    }
    UpdateList(); // 更新设备列表（可能是界面上的显示）
    //GetDeviceData(); // 从所有设备中获取配置数据，将其显示在界面的表格中，并根据设备的状态启用或禁用相关按钮和复选框
    return 1;
}

bool spectrum::setParams() // 设置参数
{
//    // 设备设置参数 l_DeviceData
//    unsigned int l_Size = sizeof(DeviceConfigType);
//    int res = AVS_GetParameter(a_hDevice, l_Size, &l_Size, &l_DeviceData); // 获取l_DeviceData
//    if (res != ERR_SUCCESS) return false;

    // 测量参数 l_DeviceData.m_StandAlone.m_Meas = l_PrepareMeasData
    //    详见AvaSpec Library Manual.pdf的2.6和3.4
    l_PrepareMeasData.m_StartPixel = 0; // 开始像素
    l_PrepareMeasData.m_StopPixel = 4095; // 结束像素
    l_PrepareMeasData.m_IntegrationTime = 100; // 积分时间
    l_PrepareMeasData.m_IntegrationDelay = 0; // 积分延迟
    l_PrepareMeasData.m_NrAverages = 1; // 范围数据的信噪比
    l_PrepareMeasData.m_CorDynDark.m_Enable = 1; // 启用/禁用(0/1)动态暗校正
    l_PrepareMeasData.m_CorDynDark.m_ForgetPercentage = 100; // 推荐值为100
    l_PrepareMeasData.m_Smoothing.m_SmoothPix = 0; // 用于平滑的邻居像素数
    l_PrepareMeasData.m_Smoothing.m_SmoothModel = 0; // 平滑类型，目前只有一种，该参数不用改动
    l_PrepareMeasData.m_SaturationDetection = 0; // 饱和度检测
    l_PrepareMeasData.m_Trigger.m_Mode = 0; // 触发模式(0=软件, 1=硬件, 2=单次扫描)
    l_PrepareMeasData.m_Trigger.m_Source = 0; // 触发源(0=外部触发, 1=同步输入)
    l_PrepareMeasData.m_Trigger.m_SourceType = 0; // 源类型(0=边缘触发, 1=水平触发)
    l_PrepareMeasData.m_Control.m_StrobeControl = 0; // 积分期间频闪脉冲数
    l_PrepareMeasData.m_Control.m_LaserDelay = 0; // 触发时的激光延时
    l_PrepareMeasData.m_Control.m_LaserWidth = 0; // 激光脉冲宽度
    l_PrepareMeasData.m_Control.m_LaserWaveLength = 780.0; // 激光峰值波长
    l_PrepareMeasData.m_Control.m_StoreToRam = 0; // 存储到RAM的光谱数据大小(0xFFFF对应16bytes)
//    l_DeviceData.m_StandAlone.m_Meas = l_PrepareMeasData;

//    l_DeviceData.m_StandAlone.m_Nmsr = -1;
//    l_DeviceData.m_DynamicStorage.m_Nmsr = -1;

//    res = AVS_SetParameter(a_hDevice, &l_DeviceData);
//    if (res != ERR_SUCCESS) return false;

//    res = AVS_PrepareMeasure(a_hDevice, &l_PrepareMeasData);
//    if (res != ERR_SUCCESS) return false;
//    else return true;

    // 其他可能用到的参数
    chkSync = 0; // 0表示非同步模式，1表示同步模式
    cbMaster = 0; // 主设备设备号
    return 1;
}

//bool spectrum::startMeasure(HWND hwnd) // 开始测量
//{
////    //int res = AVS_Measure(a_hDevice, (void*)hwnd, a_Nmsr);
////    int res = -5; // ERR_OPERATION_PENDING

////    int loopNum = 0; // 最大循环次数
////    while(res!=ERR_SUCCESS && loopNum!=100)
////    {
////        loopNum++;
////        qDebug() << "正在进行第" << loopNum << "次测量";
////        QThread::sleep(1);
////        res = AVS_MeasureCallback(a_hDevice, &application::callback, a_Nmsr); // TODO: 把application删掉
////    }

////    if (res==ERR_SUCCESS){ qDebug() << "开始测量成功"; return true; }
////    else { qDebug() << "开始测量失败，错误代码为：" << res; return false; }
//    int res = AVS_Measure(a_hDevice, (void*)hwnd, a_Nmsr);

//    if (res==ERR_SUCCESS){ qDebug() << "开始测量成功"; return true; }
//    else { qDebug() << "开始测量失败，错误代码为：" << res; return false; }
//}

bool spectrum::startMeasure() // 多通道开始测量 测试
{
    setParams(); // 设置测量参数l_PrepareMeasData

    for (int i=0; i<m_NrOfDevices; i++) // 遍历每个设备
    {
        m_Device[i].m_Failures = 0;  // 初始化每个设备的失败次数为0
        if (m_Device[i].avsDeviceHandle != INVALID_AVS_HANDLE_VALUE)  // 检查设备句柄是否有效
        {
            m_Device[i].PrepareMeasParam = l_PrepareMeasData; // 测量参数赋值
            int l_Res = AVS_PrepareMeasure(m_Device[i].avsDeviceHandle, &m_Device[i].PrepareMeasParam);  // 准备测量
            if (ERR_SUCCESS != l_Res)  // 如果准备测量失败
                qDebug() << "准备测量失败";  // 显示错误消息
            m_Device[i].NrMeas = 0;  // 初始化测量次数为0
            AVS_GetLambda(m_Device[i].avsDeviceHandle, m_Lambda[i]);  // 获取波长数据
        }
    }

     // 开始测量。如果启用了同步模式，则最后启动主设备
     short l_NrOfScans = a_Nmsr;  // 获取扫描次数
     m_StartTicks = QDateTime::currentDateTime();  // 记录开始时间
     if (chkSync == 1)  // 如果启用了同步模式
     {
         for (int i = 0; i < m_NrOfDevices; i++)
         {
             if ((i != cbMaster) && (m_Device[i].avsDeviceHandle != INVALID_AVS_HANDLE_VALUE))  // 如果当前设备不是主设备且设备句柄有效
                 AVS_MeasureCallback(m_Device[i].avsDeviceHandle, &application::callback, l_NrOfScans);  // 启动从设备的测量回调
         }
         // 在同步模式下最后启动主设备
         if (m_Device[cbMaster].avsDeviceHandle != INVALID_AVS_HANDLE_VALUE)  // 如果主设备句柄有效
             AVS_MeasureCallback(m_Device[cbMaster].avsDeviceHandle, &application::callback, l_NrOfScans);  // 启动主设备的测量回调
     }
     else
     {
         for (int i = 0; i < m_NrOfDevices; i++)
         {
             if (m_Device[i].avsDeviceHandle != INVALID_AVS_HANDLE_VALUE)  // 如果设备句柄有效
                 AVS_MeasureCallback(m_Device[i].avsDeviceHandle, &application::callback, l_NrOfScans);  // 启动设备的测量回调
         }
     }
     timer->start(100);  // 启动定时器，间隔为100毫秒
     return 1;
}

//bool spectrum::getData() // 获取测量数据
//{
//    unsigned int *a_pTimeLabel = &a_TimeLabel;
//    int res = AVS_GetScopeData(a_hDevice, a_pTimeLabel, a_pSpectrum);

//    if (res==ERR_SUCCESS)
//    {
//        if (a_pSpectrum) // 保存数据
//        {
//           QFile file(filePath); // 相对路径
//           if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
//               qWarning("Cannot open file for writing");
//           }

//           QTextStream textStream(&file);
//           for (int i = 0; i < MAX_NR_PIXELS; ++i) {
//               textStream << QString::number(a_pSpectrum[i]) << " ";
//               //if ((i+1)%4096==0) textStream << "\n"; // 每行4096个数据
//           }

//           file.close();
//        }

//        qDebug() << "获取测量数据成功";
//        return true;
//    }
//    else { qDebug() << "获取测量数据失败，错误代码为：" << res; return false; }
//}

//bool spectrum::stopMeasure() // 停止测量
//{
//    int res = AVS_StopMeasure(a_hDevice);

//    if (res==ERR_SUCCESS){ qDebug() << "停止测量成功"; return true; }
//    else { qDebug() << "停止测量失败"; return false; }
//}

bool spectrum::stopMeasure() // 停止测量
{
    for (int i = 0; i < m_NrOfDevices; i++)
    {
        int l_Res = AVS_StopMeasure(m_Device[i].avsDeviceHandle);
        if (ERR_SUCCESS != l_Res) qDebug() << "停止测量失败，错误代码为" << l_Res;
    }
//    ui.btnStartMeasurement->setEnabled(true);
//    ui.chkSync->setEnabled(true);
//    ui.chkHardwareTriggered->setEnabled(true);
    timer->stop();
    return 1;
}

void spectrum::ReceiveDataIsHere(int WParam, int LParam)
{
    // 定义一个字符串变量 l_Line，用于后续可能的日志或消息显示
    QString l_Line;

    // 检查 WParam 是否大于等于 ERR_SUCCESS（表示成功或正常状态）
    if (WParam >= ERR_SUCCESS)
    {
        {
            // 如果 WParam 等于 ERR_SUCCESS，表示正常测量
            if (ERR_SUCCESS == WParam) // normal measurements
            {
                // LParam 是接收到数据的设备句柄
                int i = 0;
                bool l_found = false;

                // 遍历设备列表，查找与 LParam 匹配的设备句柄
                while ((!l_found) && (i < m_NrOfDevices)) {
                    if (LParam == m_Device[i].avsDeviceHandle)
                        l_found = true; // 找到匹配的设备句柄
                    else
                        i++; // 继续查找下一个设备
                }

                // 如果找到匹配的设备句柄
                if (l_found)
                {
                    // 在状态栏显示测量成功的消息
                    //ui.statusBar->showMessage(tr("Meas.Status: success"));

                    // 增加该设备的测量次数
                    m_Device[i].NrMeas++;

                    // 调用 AVS_GetScopeData 获取光谱数据
                    if (ERR_SUCCESS == AVS_GetScopeData(m_Device[i].avsDeviceHandle, &m_Time[i], m_Spectrum[i]))
                    {
                        // 保存数据到文件
                        save2txt(i);



                        // 计算当前时间戳与前一次时间戳的差值（单位为 10 微秒）
                        m_Dif[i] = m_Time[i] - m_Device[i].PreviousTimeStamp;  // l_Time in 10 us ticks

                        // 更新前一次时间戳为当前时间戳
                        m_Device[i].PreviousTimeStamp = m_Time[i];

                        // 获取当前时间并保存到 m_Ticks_all 和 m_Ticks[i]
                        m_Ticks_all = QDateTime::currentDateTime();
                        m_Ticks[i] = m_Ticks_all;

                        // 如果设置了扫描次数（ui.edtNrOfScans->text() 的值大于 0）
                        //if (QString(ui.edtNrOfScans->text()).toInt() > 0)
                        if (a_Nmsr > 0)
                        {
                            bool l_Ready = true;

                            // 检查所有设备的测量次数是否达到设置的扫描次数
                            for (int j = 0; j < m_NrOfDevices; j++)
                            {
                                //if (m_Device[j].NrMeas < ui.edtNrOfScans->text().toInt())
                                if (m_Device[j].NrMeas < a_Nmsr)
                                    l_Ready = false; // 如果某个设备未完成测量，设置 l_Ready 为 false
                            }

//                            // 根据 l_Ready 的值启用或禁用开始测量按钮
//                            ui.btnStartMeasurement->setEnabled(l_Ready);

                            // 如果所有设备都完成了测量
                            if (l_Ready) {
                                timer->stop(); // 停止计时器
                                timerSlot();  // 调用 timerSlot 函数进行最后一次屏幕更新
                            }

//                            // 根据 l_Ready 的值启用或禁用同步和硬件触发复选框
//                            ui.chkSync->setEnabled(l_Ready);
//                            ui.chkHardwareTriggered->setEnabled(l_Ready);
                        }
                    }
                    else
                    {
                        // 如果获取光谱数据失败，显示无数据可用的消息
//                        ui.statusBar->showMessage(tr("Meas.Status: no data available"));
                        qDebug() << "Meas.Status: no data available";

                        // 增加该设备的失败次数
                        m_Device[i].m_Failures++;
                    }
                }
            }
        }
    }
    else  // 如果 WParam 小于 0，表示发生错误
    {
        // 在状态栏显示测量失败的消息，并包含错误代码
//        ui.statusBar->showMessage(tr("Meas.Status: failed. Error %1").arg(WParam));
        qDebug() << "Meas.Status: failed. Error " << WParam;

        // 增加总失败次数
        m_TotalFailures++;
    }
}

void spectrum::timerSlot()
{
    // 计算从 m_StartTicks 到当前时间的秒数
    qint64 l_Seconds = m_StartTicks.secsTo(QDateTime::currentDateTime());

    // 将计算得到的秒数显示在 ui.edtTotalTime 文本框中
    //ui.edtTotalTime->setText(QString("%1").arg(l_Seconds));

    // 遍历所有设备
    for (int i = 0; i < m_NrOfDevices; i++)
    {
//        // 创建一个 QTableWidgetItem 并设置其内容为设备的序列号
//        QTableWidgetItem *lserial = new QTableWidgetItem(m_Device[i].avsID.SerialNumber);
//        // 将序列号显示在 sgTimeInfo 表格的第 i 行第 0 列
//        ui.sgTimeInfo->setItem(i, 0, lserial);

//        // 创建一个 QTableWidgetItem 并设置其内容为设备的测量次数
//        QTableWidgetItem *lnummeas = new QTableWidgetItem(QString("%1").arg(m_Device[i].NrMeas));
//        // 将测量次数显示在 sgTimeInfo 表格的第 i 行第 1 列
//        ui.sgTimeInfo->setItem(i, 1, lnummeas);

        // 计算从 m_StartTicks 到 m_Ticks[i] 的毫秒数
        qint64 l_milliSeconds = m_StartTicks.msecsTo(m_Ticks[i]);

        // 初始化平均时间变量
        double lavg = 0.0;

        // 如果设备的测量次数大于 0，计算平均时间
        if (m_Device[i].NrMeas > 0)
            lavg = double(l_milliSeconds) / double(m_Device[i].NrMeas);  // 单位为毫秒

//        // 创建一个 QTableWidgetItem 并设置其内容为计算得到的平均时间
//        QTableWidgetItem *lavgtime = new QTableWidgetItem(QString("%1").arg(lavg, -7, 'f', 3));
//        // 将平均时间显示在 sgTimeInfo 表格的第 i 行第 2 列
//        ui.sgTimeInfo->setItem(i, 2, lavgtime);

//        // 如果 m_Dif[i] 不为 0 且设备的测量次数大于 1，计算并显示时间差
//        if ((m_Dif[i] != 0) && (m_Device[i].NrMeas > 1))
//        {
//            // 创建一个 QTableWidgetItem 并设置其内容为计算得到的时间差
//            QTableWidgetItem *ldif = new QTableWidgetItem(QString("%1").arg(m_Dif[i] / 100.0, -7, 'f', 3));  // 时间差单位为毫秒
//            // 将时间差显示在 sgTimeInfo 表格的第 i 行第 3 列
//            ui.sgTimeInfo->setItem(i, 3, ldif);
//        }
    }

//    // 更新 sgTimeInfo 表格的显示
//    ui.sgTimeInfo->update();
}

void spectrum::update_plot() // 绘图并保存数据
{
    int dataSize = l_PrepareMeasData.m_StopPixel - l_PrepareMeasData.m_StartPixel + 1; // 获取数据范围

    QVector<double> xData(dataSize); // x轴数据
    QVector<double> yData(dataSize); // y轴数据

    /// 在主控界面绘图 ///
    if (pToMenu)
    {
        //for (int i = 0; i < MAX_NR_DEVICES; i++)
        for (int i = 0; i < m_NrOfDevices; i++)
        {
//            // 保存数据
//            QFile file(filePath+QString::number(i)+".txt"); // 相对路径（第i个设备/通道）
//            //QFile file("test.txt"); // 相对路径（第i个设备/通道）
//            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
//                qWarning("Cannot open file for writing");
//            }
//            QTextStream textStream(&file);

            // 绘图
            pToMenu->ui->specPlot->addGraph(); // 添加一个图表
            pToMenu->ui->specPlot->graph(i)->setPen(QPen(QColor(Qt::GlobalColor(i % MAX_NR_DEVICES)))); // 设置曲线颜色（循环使用 Qt 的颜色）

            for (int j = 0; j < dataSize; ++j) {
                xData[j] = m_Lambda[i][l_PrepareMeasData.m_StartPixel + j];
                yData[j] = m_Spectrum[i][l_PrepareMeasData.m_StartPixel + j];
                // 保存数据
                //textStream << xData[j] << " " << yData[j] << "\n";
            }

            pToMenu->ui->specPlot->graph(i)->setData(xData, yData); // 设置数据到 QCustomPlot 的图表
            pToMenu->ui->specPlot->replot(); // 刷新图表

//            // 保存数据
//            file.close(); // 关闭文件
        }
    }
}

void spectrum::save2txt(int i) // 保存数据到文件
{
    int dataSize = l_PrepareMeasData.m_StopPixel - l_PrepareMeasData.m_StartPixel + 1; // 获取数据范围

    QVector<double> xData(dataSize); // x轴数据
    QVector<double> yData(dataSize); // y轴数据

    // 保存数据
    QFile file(filePath+QString::number(i)+".txt"); // 相对路径（第i个设备/通道）
    //QFile file("test.txt"); // 相对路径（第i个设备/通道）
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
        qWarning("Cannot open file for writing");
    }
    QTextStream textStream(&file);

    for (int j = 0; j < dataSize; ++j) {
        xData[j] = m_Lambda[i][l_PrepareMeasData.m_StartPixel + j];
        yData[j] = m_Spectrum[i][l_PrepareMeasData.m_StartPixel + j];
        textStream << xData[j] << " " << yData[j] << "\n";
    }

    file.close(); // 关闭文件
}
