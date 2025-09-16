#include "streamingbufferedai.h"
#include "qcustomplot.h"
#include <QMessageBox>
#include <QPalette>
#include <QWidget>
#include <qmath.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// 确保两个h文件中定义的类可以互相引用
//#include "menu.h"
//#include "ui_menu.h"

// const QString AI_StreamingBufferedAi::filePath = "./Temp_DAQ_Data.txt"; // 保存文件的路径(txt)

const QString AI_StreamingBufferedAi::elecFilePath = "./elec_Data.txt";
const QString AI_StreamingBufferedAi::voltFilePath = "./volt_Data.txt";
const QString AI_StreamingBufferedAi::soundFilePath = "./sound_Data.txt";
QString AI_StreamingBufferedAi::elecValue = QString("无数据");
QString AI_StreamingBufferedAi::voltValue = QString("无数据");
QString AI_StreamingBufferedAi::soundValue = QString("无数据");
QList<double> AI_StreamingBufferedAi::elecList = QList<double>();
QList<double> AI_StreamingBufferedAi::voltList = QList<double>();
QList<double> AI_StreamingBufferedAi::soundList = QList<double>();
std::vector<double> AI_StreamingBufferedAi::I_features = std::vector<double>();
std::vector<double> AI_StreamingBufferedAi::U_features = std::vector<double>();
std::vector<double> AI_StreamingBufferedAi::S_features = std::vector<double>();

AI_StreamingBufferedAi::AI_StreamingBufferedAi(QDialog *parent, Qt::WindowFlags flags)
    : QDialog(parent, flags)
{
    ui.setupUi(this);

    //Set the minimum and close button of the main frame.
    this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

    //Set the background image for the main frame.
    //this->setAutoFillBackground(true);
    //QPixmap pixMap("Background.png");
    //QPalette backPalette;
    //backPalette.setBrush(this->backgroundRole(), QBrush(pixMap));
    //this->setPalette(backPalette);

    graph = new SimpleGraph(ui.graphFrame);
    graph->setFixedSize(ui.graphFrame->size());

    timeUnit = Millisecond;
    rawDataBufferLength = 0;
    scaledData = NULL;

    waveformAiCtrl  = WaveformAiCtrl::Create();

    waveformAiCtrl->addDataReadyHandler(OnDataReadyEvent, this);
    waveformAiCtrl->addOverrunHandler(OnOverRunEvent, this);
    waveformAiCtrl->addCacheOverflowHandler(OnCacheOverflowEvent, this);
    waveformAiCtrl->addStoppedHandler(OnStoppedEvent, this);

    connect(ui.btnConfigure, SIGNAL(clicked()), this, SLOT(ButtonConfigureClicked()));
    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(ButtonStartClicked()));
    connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(ButtonPauseClicked()));
    connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(ButtonStopClicked()));
    connect(ui.sldDiv, SIGNAL(valueChanged(int)), this, SLOT(DivValueChanged(int)));
    connect(ui.sldDiv, SIGNAL(valueChanged(int)), this, SLOT(DivValueChanged(int)));

    //connect(this->OnDataReadyEvent, SIGNAL(replotNeeded(QCustomPlot *)), this, &AI_StreamingBufferedAi::handleReplotNeeded(QCustomPlot *));

    // 将图表背景设置为透明
    ui.currentPlot->setBackground(Qt::transparent); // 电流图表
    ui.currentPlot->setStyleSheet("background: transparent;");
    ui.voltagePlot->setBackground(Qt::transparent); // 电压图表
    ui.voltagePlot->setStyleSheet("background: transparent;");
    ui.soundPlot->setBackground(Qt::transparent); // 声音图表
    ui.soundPlot->setStyleSheet("background: transparent;");

    //if (pToMenu) connect(this, &AI_StreamingBufferedAi::updateAcquiCardPlot, pToMenu, &Menu::updateAcquiCardPlot);
        // 连接此线程与主线程更新采集卡图形的信号与槽

    cursor(ui.currentPlot);
    setupGraph(ui.currentPlot,Qt::green);

    cursor(ui.voltagePlot);
    setupGraph(ui.voltagePlot,Qt::red);

    cursor(ui.soundPlot);
    setupGraph(ui.soundPlot,Qt::blue);
}

//void AI_StreamingBufferedAi::handleReplotNeeded(QCustomPlot *plot) {
//    // 在这里调用replot函数重新绘制图形
//    plot->replot();
//}

AI_StreamingBufferedAi::~AI_StreamingBufferedAi()
{
   if (waveformAiCtrl != NULL)
   {
      waveformAiCtrl->Dispose();
      waveformAiCtrl = NULL;
   }

    if (scaledData != NULL)
    {
        delete []scaledData;
        scaledData = NULL;
    }
}

void AI_StreamingBufferedAi::Initialize()
{
    setWindowTitle(tr("Streaming AI - Run(") + configure.deviceName + tr(")"));

    ConfigureDevice();
    ConfigureGraph();
    InitializeList();

    ui.btnConfigure->setEnabled(true);
    ui.btnStart->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStop->setEnabled(false);
    ui.sldDiv->setEnabled(true);
}

void AI_StreamingBufferedAi::ConfigureDevice()
{
    ErrorCode errorCode = Success;
    if (scaledData != NULL)
    {
        delete []scaledData;
        scaledData = NULL;
    }

    rawDataBufferLength = configure.sectionLength * configure.channelCount;

    scaledData = new double[rawDataBufferLength];
    if (scaledData == NULL)
    {
        QMessageBox::information(this, tr("Warning Information"),
            tr("Sorry! Error in allocating memory...."));
        return;
    }

    // Select a device with AccessWrite/AccessWriteWithReset mode with device number
    // or device description.
    std::wstring description = configure.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());

    errorCode = waveformAiCtrl->setSelectedDevice(selected);
    CheckError(errorCode);

    std::wstring profile = configure.profilePath.toStdWString();
    errorCode = waveformAiCtrl->LoadProfile(profile.c_str());
    CheckError(errorCode);

    //Set the streaming mode.
    errorCode = waveformAiCtrl->getConversion()->setChannelCount(configure.channelCount);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getConversion()->setChannelStart(configure.channelStart);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getConversion()->setClockRate(configure.clockRatePerChan);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getRecord()->setSectionLength(configure.sectionLength);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getRecord()->setSectionCount(sectionCount);//The 0 means setting 'streaming' mode.
    CheckError(errorCode);

   for (int i = 0; i < waveformAiCtrl->getChannels()->getCount(); i++)
    {
        errorCode = waveformAiCtrl->getChannels()->getItem(i).setValueRange(configure.valueRange);
        CheckError(errorCode);
    }

    errorCode = waveformAiCtrl->Prepare();
    CheckError(errorCode);
}

void AI_StreamingBufferedAi::ConfigureGraph()
{
   double clockRate = waveformAiCtrl->getConversion()->getClockRate();
   int tUnit = (int)Millisecond;
   double timeInterval = 100.0 * graph->rect().width() / clockRate;
   while (clockRate >= 10 * 1000)
   {
       timeInterval *= 1000;
       clockRate /= 1000;
       --tUnit;
   }
   timeUnit = (TimeUnit)tUnit;

   int divValue = (int)timeInterval;
   ui.sldDiv->setMaximum(4 * divValue);
   int divMin = divValue / 10;
   if ( divMin == 0 )
   {
       divMin = 1;
   }
   ui.sldDiv->setMinimum(divMin);
   ui.sldDiv->setValue(divValue);
   SetXCord();

    ValueUnit unit;
    MathInterval rangeY;
    QString yRanges[3];
    ErrorCode errorCode = AdxGetValueRangeInformation(configure.valueRange, 0, NULL,
        &rangeY, &unit);
    CheckError(errorCode);

    graph->GetYCordRange(yRanges, rangeY.Max, rangeY.Min, unit);
    ui.lblYCoordinateMax->setText(yRanges[0]);
    ui.lblYCoordinateMin->setText(yRanges[1]);
    ui.lblYCoordinateMid->setText(yRanges[2]);

    graph->m_yCordRangeMax = rangeY.Max;
    graph->m_yCordRangeMin = rangeY.Min;
    graph->Clear();
}

void AI_StreamingBufferedAi::InitializeList()
{
    ui.listWidget->clear();
    QListWidgetItem *item = NULL;
    for (int i = 0; i < configure.channelCount; i++)
    {
        item = new QListWidgetItem(tr(""), ui.listWidget);
        item->setBackground(QBrush(SimpleGraph::lineColor[i]));
        item->setSizeHint(QSize(54, 21));
    }
}

void AI_StreamingBufferedAi::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode))
    {
        QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
            QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "Warning Information", message);
    }
}

void AI_StreamingBufferedAi::SetXCord()
{
    graph->m_xCordTimeDiv = (double)ui.sldDiv->value();
    QString xRanges[2];

    double shiftMaxValue = qRound(graph->m_xCordTimeDiv * 10 + graph->m_xCordTimeOffset);
    graph->GetXCordRange(xRanges, shiftMaxValue, graph->m_xCordTimeOffset, timeUnit);
    ui.lblXCoordinateStart->setText(xRanges[1]);
    ui.lblXCoordinateEnd->setText(xRanges[0]);
}

void AI_StreamingBufferedAi::DivValueChanged(int value)
{
    graph->Div(value);
    SetXCord();
}

void AI_StreamingBufferedAi::ButtonConfigureClicked()
{
    configureDialog->RefreshConfigureParameter();
    int resultDialog = configureDialog->exec();
    if (resultDialog == QDialog::Accepted)
    {
        configure = configureDialog->GetConfigureParameter();
        Initialize();
    }
}

void AI_StreamingBufferedAi::ButtonStartClicked()
{
    ui.btnConfigure->setEnabled(false);
    ui.btnStart->setEnabled(false);
    ui.btnPause->setEnabled(true);
    ui.btnStop->setEnabled(true);

    ErrorCode errorCode = waveformAiCtrl->Start();
    CheckError(errorCode);
    xInc = 1.0 / waveformAiCtrl->getConversion()->getClockRate();
}

void AI_StreamingBufferedAi::ButtonPauseClicked()
{
    ErrorCode errorCode = waveformAiCtrl->Stop();
    CheckError(errorCode);

    ui.btnStart->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStop->setEnabled(true);
}

void AI_StreamingBufferedAi::ButtonStopClicked()
{
    ErrorCode errorCode = waveformAiCtrl->Stop();
    CheckError(errorCode);

    graph->Clear();

    ui.btnConfigure->setEnabled(true);
    ui.btnStart->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStop->setEnabled(false);
}

void AI_StreamingBufferedAi::OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void * userParam)
{
    AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
    int32 remainingCount = args->Count; // 剩余总数
    int32 getDataCount = 0, returnedCount = 0;
    int32 bufSize = uParam->configure.sectionLength * uParam->configure.channelCount;

    // 打开文件以追加写入
    QFile elecFile(elecFilePath);
    QFile voltFile(voltFilePath);
    QFile soundFile(soundFilePath);

    if (!elecFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qWarning("Cannot open %s for writing", qUtf8Printable(elecFilePath));
        // 考虑更健壮的错误处理
        return;
    }
    if (!voltFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qWarning("Cannot open %s for writing", qUtf8Printable(voltFilePath));
        elecFile.close(); // 关闭已打开的文件
        return;
    }
    if (!soundFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qWarning("Cannot open %s for writing", qUtf8Printable(soundFilePath));
        elecFile.close();
        voltFile.close(); // 关闭已打开的文件
        return;
    }

    QTextStream elecStream(&elecFile);
    QTextStream voltStream(&voltFile);
    QTextStream soundStream(&soundFile);


    do {
        getDataCount = qMin(bufSize,  remainingCount);  // 当前读取大小
        // 读取到scaledData，大小为returnedCount
        ErrorCode ret = ((WaveformAiCtrl*)sender)->GetData(getDataCount, uParam->scaledData, 0, &returnedCount, NULL, NULL, NULL);
        //(int32, double[]数据, 0超时时间设置, int32读取数据量, NULL第一个数据读取时间, NULL, NULL数据标记)
        remainingCount -= returnedCount;
        if (ret != Success && ret != WarningRecordEnd)
        {
            QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
                QString::number(ret, 16).right(8);
            QMessageBox::information(uParam, "Warning Information", message);
            // 确保在出错时关闭文件
            elecFile.close();
            voltFile.close();
            soundFile.close();
            return;
        }

        /// 分离并保存数据 ///
       int channelCount = uParam->configure.channelCount;
       // 假设 channelCount 为 3，分别对应 elec, volt, sound
       if (channelCount == 3) { // 增加检查以确保安全
           for (int i = 0; i < returnedCount; ++i) {
               int channelIndex = i % channelCount; // 计算当前数据点属于哪个通道
               double value = uParam->scaledData[i];
               switch (channelIndex) {
                   case 0: // Elec
                       value = value * 100;
                       elecStream << QString::number(value) << "\n";
                       if (elecList.size() >= 500) {elecList.removeFirst();}
                       elecList.append(value);
                       break;
                   case 1: // Volt
                       value = value * 20;
                       voltStream << QString::number(value) << "\n";
                       if (voltList.size() >= 500) {voltList.removeFirst();}
                       voltList.append(value);
                       break;
                   case 2: // Sound
                       soundStream << QString::number(value) << "\n";
                       if (soundList.size() >= 500) {soundList.removeFirst();}
                       soundList.append(value);
                       break;
                   default:
                       // 如果 channelCount 是 3，这里不应该执行
                       break;
               }
           }
       } else {
           // 处理通道数不为 3 的情况
           qWarning("Channel count (%d) is not 3. Data saving logic needs adjustment. Saving to default file.", channelCount);
                }
                            //     数据                通道数                          每个通道的数据大小                            每秒x轴增加的值
       //uParam->graph->Chart(uParam->scaledData, uParam->configure.channelCount, returnedCount / uParam->configure.channelCount, uParam->xInc);
    }while(remainingCount > 0);

    // 循环结束后关闭文件
    elecFile.close();
    voltFile.close();
    soundFile.close();
}



void AI_StreamingBufferedAi::setupGraph(QCustomPlot *widget, const QColor &color) {
    QPen pen;
    pen.setColor(color);
    pen.setWidth(0.1);  //线段宽度？

    widget->addGraph();
    widget->graph(0)->rescaleAxes(true);
    widget->graph(0)->setPen(pen);
    widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,4));
    widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    widget->legend->setVisible(false);
    widget->xAxis->setRange(0,10);  //横向缩放?
    widget->yAxis->setRange(-10,10);
}

//游标:显示曲线上点坐标信息
void AI_StreamingBufferedAi::cursor(QCustomPlot *widget)
{
    // 生成游标
    QCPItemTracer *tracer = new QCPItemTracer(widget);                                // 生成游标
    tracer->setPen(QPen(Qt::red));                                         // 轮廓颜色
    tracer->setBrush(QBrush(Qt::red));                                     // 填充颜色
    tracer->setStyle(QCPItemTracer::tsCircle);                             // 圆圈样式
    tracer->setSize(5);                                                    // 大小
    // 游标说明
    QCPItemText *tracerLabel = new QCPItemText(widget);                             // 游标说明
    tracerLabel->setLayer("overlay");                                      // 设置图层为overlay，因为需要频繁刷新
    tracerLabel->setPen(QPen(Qt::black));                                  // 设置游标说明颜色
    tracerLabel->setPositionAlignment(Qt::AlignLeft | Qt::AlignTop);       // 位置
    tracerLabel->position->setParentAnchor(tracer->position);              // 将游标说明锚固在tracer位置处，实现自动跟随

    tracerMap[widget] = tracer;
    tracerLabelMap[widget] = tracerLabel;
    connect(widget,&QCustomPlot::mouseMove,this,&AI_StreamingBufferedAi::handleMouseMove);
}

// 中间函数 获取鼠标事件在那个控件
void AI_StreamingBufferedAi::handleMouseMove(QMouseEvent *event) {
    QCustomPlot *widget = qobject_cast<QCustomPlot*>(sender()); // 获取信号的发送者
    if (widget) {
        myMove(widget, event);
    }
}

void AI_StreamingBufferedAi::myMove(QCustomPlot *widget, QMouseEvent *e)
{
    // 获得鼠标位置处对应的横坐标数据x
    double x = widget->xAxis->pixelToCoord(e->pos().x());
    tracerMap[widget]->setGraph(widget->graph(0));         // 将游标和该曲线图层连接
    tracerMap[widget]->setGraphKey(x);                         // 将游标横坐标设置成刚获得的横坐标数据x
    tracerMap[widget]->setInterpolating(true);                 // 游标的纵坐标可以通过曲线数据线性插值自动获得
    tracerMap[widget]->updatePosition();                       // 使得刚设置游标的横纵坐标位置生效
    // 更新游标说明的内容
    double xValue = tracerMap[widget]->position->key();
    double yValue = tracerMap[widget]->position->value();
    tracerLabelMap[widget]->setText(QString("x = %1, y = %2").arg(xValue).arg(yValue));
    widget->replot();                           // 重绘
}

// 每秒重绘20000点
void AI_StreamingBufferedAi::on_pushButton_clicked()
{
     QTimer::singleShot(1000,this,[=]{
         on_pushButton_clicked();
     });
}


void AI_StreamingBufferedAi::OnOverRunEvent(void * sender, BfdAiEventArgs * args, void * userParam)
{
   /*
   AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
   QString message = tr("The event over run has happened!");
   QMessageBox::information(uParam, "Warning Information", message);
   */
}
void AI_StreamingBufferedAi::OnCacheOverflowEvent(void * sender, BfdAiEventArgs * args, void * userParam)
{
   /*
   AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
   QString message = tr("The event cache over flow has happened!");
   QMessageBox::information(uParam, "Warning Information", message);
   */
}

void AI_StreamingBufferedAi::OnStoppedEvent(void * sender, BfdAiEventArgs * args, void * userParam)
{
   /*
   AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
   QString message = tr("The event stopped has happened!");
   QMessageBox::information(uParam, "Warning Information", message);
   */
}
