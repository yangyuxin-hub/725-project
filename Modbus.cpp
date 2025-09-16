#include "Modbus.h"
#include "ui_Modbus.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>
#include <QTextStream>
#include <iomanip>
#include <QThread>
#include <Windows.h>
#include <QDebug>

// 确保两个h文件中定义的类可以互相引用
#include "menu.h"
#include "ui_menu.h"

const QString Modbus::filePath = "Temp_Flow.txt"; // 保存文件的路径(txt)

QString Modbus::flowValue = QString("无数据");

Modbus::Modbus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modbus)
{
    ui->setupUi(this);
//    initialPort();
    connect(ui->stopflowButton, &QPushButton::clicked, this, &Modbus::on_stopflowButton_clicked);

    // 气流图表
    ui->airstreamPlot->setBackground(Qt::transparent); // 将图表背景设置为透明
    ui->airstreamPlot->setStyleSheet("background: transparent;"); // 将图表背景设置为透明
    ui->airstreamPlot->addGraph(); // 添加一个图表
    ui->airstreamPlot->graph(0)->setPen(QPen(Qt::red)); // 设置图表颜色为红色
    ui->airstreamPlot->yAxis->setRange(0,100);
}

Modbus::~Modbus()
{
    // 关闭串口
    if (this->hSerial != INVALID_HANDLE_VALUE) // 确保句柄有效再关闭
    {
        CloseHandle(this->hSerial); // 关闭串口句柄
    }
    delete ui;
}

void Modbus::initialPort()
{
    // 如果句柄有效，先关闭它
    if (this->hSerial != INVALID_HANDLE_VALUE)
    {
        CloseHandle(this->hSerial);
        this->hSerial = INVALID_HANDLE_VALUE; // 重置句柄
    }
    this->dcbSerialParams = {0};
    this->timeouts = {0};

    // 打开串口
    this->hSerial = CreateFileW(L"COM9", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (this->hSerial == INVALID_HANDLE_VALUE) {
           qDebug() << "无法打开串口";
           return;
       }

       // 配置串口参数
       this->dcbSerialParams.DCBlength = sizeof(this->dcbSerialParams);

       if (!GetCommState(this->hSerial, &this->dcbSerialParams)) {
           qDebug() << "获取串口状态失败";
           CloseHandle(this->hSerial);
           return;
       }

       this->dcbSerialParams.BaudRate = CBR_9600;
       this->dcbSerialParams.ByteSize = 8;
       this->dcbSerialParams.StopBits = ONESTOPBIT;
       this->dcbSerialParams.Parity = NOPARITY;

       if (!SetCommState(this->hSerial, &this->dcbSerialParams)) {
           qDebug() << "设置串口参数失败";
           CloseHandle(this->hSerial);
           return;
       }

       // 设置超时时间
       this->timeouts.ReadIntervalTimeout = 50;
       this->timeouts.ReadTotalTimeoutConstant = 50;
       this->timeouts.ReadTotalTimeoutMultiplier = 10;
       this->timeouts.WriteTotalTimeoutConstant = 50;
       this->timeouts.WriteTotalTimeoutMultiplier = 10;

       if (!SetCommTimeouts(this->hSerial, &this->timeouts)) {
           qDebug() << "设置超时时间失败";
           CloseHandle(this->hSerial);
           return;
       }
}

void Modbus::on_startflowButton_clicked()
{
    // //QDateTime currentTime = QDateTime::currentDateTime();
    // //qint64 msecsTimestamp = currentTime.toMSecsSinceEpoch(); // 获取毫秒时间戳
    // //double msecsTimestampDouble = static_cast<double>(msecsTimestamp); // 转换为double类型
    initialPort(); // 重新初始化串口
    if (this->hSerial == INVALID_HANDLE_VALUE) // 检查串口是否成功打开
    {
        qDebug() << "串口未打开，无法开始采集";
        return;
    }
    this->readornot = true;

    // 获取当前毫秒时间戳
    startTime = static_cast<double>(QDateTime::currentDateTime().toMSecsSinceEpoch());

    connect(dataTimer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    dataTimer->start(100); // 更新频率，单位毫秒（更新频率可以调整）

    // //qApp->processEvents();
    // this->readornot = true;
    // int n=0;
    // const int buf_size = 32;
    // unsigned char read_buf[buf_size];
    // DWORD bytes_written;
    // DWORD bytes_read;
    // QString hexString;
    // QTextStream stream(&hexString);
    // stream.setIntegerBase(16);
    // stream.setFieldWidth(2);
    // stream.setPadChar('0');
    // // 向串口写入十六进制数据
    //    unsigned char msg[] = {0x01, 0x03, 0x00, 0x3A, 0x00, 0x02, 0xE4, 0x06};  //CRC十六进制modbus 校验方式（8005）
    //    //while (this->readornot == true)
    //    {
    //        bytes_written = 0;
    //        if (!WriteFile(this->hSerial, msg, sizeof(msg), &bytes_written, NULL)) {
    //            qDebug() << "向串口写入数据失败";
    //            CloseHandle(this->hSerial);
    //            return;
    //        }

    //         qDebug() <<  n++;
    //        // 实时地从串口读取数据
    //        memset(read_buf, 0, buf_size * sizeof(unsigned char));
    //        bytes_read = 0;
    //        if (!ReadFile(this->hSerial, read_buf, buf_size, &bytes_read, NULL)) {
    //            qDebug() << "从串口读取数据失败";
    //            CloseHandle(this->hSerial);
    //            return;
    //        }
    //        //01 03 04 00 00 23 32 62 d6(0~8)
    //        //00 00 23 32(3~6)
    //        hexString.clear();
    //        if (bytes_read > 0) {
    //            qDebug() << "接收到的数据（十六进制格式）: ";
    //            for (DWORD i = 3; i < bytes_read - 2; ++i) {
    //                stream << static_cast<int>(read_buf[i]) << " ";
    //            }
    //            double flow = (read_buf[3] << 24) | (read_buf[4] << 16) | (read_buf[5] << 8) | read_buf[6];
    //            qDebug() << "气体流量: " << flow/1000.0;
    //            ui->recvTextEdit->append(QString::number(flow/1000.0, 'f', 3) + "\n");

    //             // 绘图
    //             ui->airstreamPlot->graph(0)->addData \
    //                     (static_cast<double>((QDateTime::currentDateTime().toMSecsSinceEpoch())-startTime)/1000.0, flow/1000.0);
    //             //uParam->ui.currentPlot->graph(0)->addData(i/3, uParam->scaledData[i]);
    //             //uParam->ui.currentPlot->xAxis->setRange((i/3 - 500), 500, Qt::AlignLeft);
    //        }

    //        Sleep(100); // 可以添加适当的延迟以降低 CPU 负载
    //    }
}


void Modbus::on_stopflowButton_clicked()
{
    this->readornot = false;
    dataTimer->stop(); // 停止定时器

    // 关闭串口句柄
    if (this->hSerial != INVALID_HANDLE_VALUE)
    {
        CloseHandle(this->hSerial);
        this->hSerial = INVALID_HANDLE_VALUE; // 将句柄设置为无效，避免重复关闭
        qDebug() << "串口已关闭";
    }
}

void Modbus::on_clearRecvPushButton_clicked()
{
    ui->recvTextEdit->clear();
}

// 更新图表的槽函数
void Modbus::updatePlot()
{
    //qApp->processEvents();
    //this->readornot = true;
    int n=0;
    const int buf_size = 32;
    unsigned char read_buf[buf_size];
    DWORD bytes_written;
    DWORD bytes_read;
    QString hexString;
    QTextStream stream(&hexString);
    stream.setIntegerBase(16);
    stream.setFieldWidth(2);
    stream.setPadChar('0');
    // 向串口写入十六进制数据
       unsigned char msg[] = {0x01, 0x03, 0x00, 0x3A, 0x00, 0x02, 0xE4, 0x06};  //CRC十六进制modbus 校验方式（8005）
       //while (this->readornot == true)
       if (this->readornot == true)
       {
           bytes_written = 0;
           if (!WriteFile(this->hSerial, msg, sizeof(msg), &bytes_written, NULL)) {
               qDebug() << "向串口写入数据失败";
//               CloseHandle(this->hSerial);
               return;
           }

           //qDebug() <<  n++;
           // 实时地从串口读取数据
           memset(read_buf, 0, buf_size * sizeof(unsigned char));
           bytes_read = 0;
           if (!ReadFile(this->hSerial, read_buf, buf_size, &bytes_read, NULL)) {
               qDebug() << "从串口读取数据失败";
//               CloseHandle(this->hSerial);
               return;
           }
           //01 03 04 00 00 23 32 62 d6(0~8)
           //00 00 23 32(3~6)
           hexString.clear();
           //qDebug() << "bytes_read: " << bytes_read; //debug
           if (bytes_read > 0) {
               // qDebug() << "接收到的数据（十六进制格式）: ";
               for (DWORD i = 3; i < bytes_read - 2; ++i) {
                   stream << static_cast<int>(read_buf[i]) << " ";
               }
               double flow = (read_buf[3] << 24) | (read_buf[4] << 16) | (read_buf[5] << 8) | read_buf[6];
               double real_flow = (flow/1000.0 );
               qDebug() << "气体流量: " << real_flow;
               flowValue = QString::number(real_flow, 'f', 3) + "L/min";
               ui->recvTextEdit->append(QString::number(real_flow, 'f', 3) + "\n");


                /// 在主控界面绘图 ///
                if (pToMenu && ifMenuView)
                {
                    double timeStamp = static_cast<double>((QDateTime::currentDateTime().toMSecsSinceEpoch())-startTime)/1000.0;


                    // txt中保存数据
                    QFile file(filePath); // 相对路径
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
                        qWarning("Cannot open file for writing");
                    }
                    QTextStream textStream(&file);
                    textStream << timeStamp << " " << real_flow << "\n";
                    file.close();
                }



           }

//           Sleep(100); // 可以添加适当的延迟以降低 CPU 负载
       }
}


