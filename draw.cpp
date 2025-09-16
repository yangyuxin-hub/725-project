#include "draw.h"
#include "ui_draw.h"

// TODO：draw.cpp文件是杨雨欣测试用的，可以删掉
Draw::Draw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Draw)
{
    ui->setupUi(this);
    cursor(ui->currentPlot);
    cursor(ui->voltagePlot);
    cursor(ui->soundPlot);

    QPen pen1;
    pen1.setColor(Qt::green);
    setupGraph(ui->currentPlot, pen1.color());

    QPen pen2;
    pen2.setColor(Qt::red);
    setupGraph(ui->voltagePlot, pen2.color());

    QPen pen3;
    pen3.setColor(Qt::yellow);
    setupGraph(ui->soundPlot, pen3.color());

    dynamicPlot(1024, 3); //数据个数 通道数
}
//初始化 section大小1024 采集频率1000 三通道


void Draw::setupGraph(QCustomPlot *widget, const QColor &color) {
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

//动态绘制  加入number个数据 时间间隔
void Draw::dynamicPlot(int number, int channel) {
    QTimer *timer = new QTimer(this);
    static int count = 0;
    static QFile file("C:/Users/18113/Desktop/Qt_learning/715/715-master/715/715/test1.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file:" << file.errorString();
            return;
        }
    static QTextStream in(&file);

    connect(timer, &QTimer::timeout, this, [=]() {
        for (int i=0;i<channel;i++)
        {
            if (in.atEnd()) {
                timer->stop();
                file.close();
            }
            QString line = in.readLine();
            double y = line.toDouble();
            ui->currentPlot->graph(0)->addData(count, y);
            ui->currentPlot->xAxis->setRange((count - 200), 200, Qt::AlignLeft); //x轴数据点个数 目前400个
            ui->currentPlot->replot();

            if (in.atEnd()) {
                timer->stop();
                file.close();
            }
            line = in.readLine();
            y = line.toDouble();
            ui->voltagePlot->graph(0)->addData(count, y);
            ui->voltagePlot->xAxis->setRange((count - 200), 200, Qt::AlignLeft);
            ui->voltagePlot->replot();

            if (in.atEnd()) {
                timer->stop();
                file.close();
            }
            line = in.readLine();
            y = line.toDouble();
            ui->soundPlot->graph(0)->addData(count, y);
            ui->soundPlot->xAxis->setRange((count - 200), 200, Qt::AlignLeft);
            ui->soundPlot->replot();

            count = count + 1;
            if (count >= number){
                timer->stop();
                file.close();
            }
        }
       });
    timer->start(50); //超时时间设置  更新点频率
}

Draw::~Draw()
{
    delete ui;
}

//游标:显示曲线上点坐标信息
void Draw::cursor(QCustomPlot *widget)
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
    connect(widget,&QCustomPlot::mouseMove,this,&Draw::handleMouseMove);
}

//中间函数 获取鼠标事件在那个控件
void Draw::handleMouseMove(QMouseEvent *event) {
    QCustomPlot *widget = qobject_cast<QCustomPlot*>(sender()); // 获取信号的发送者
    if (widget) {
        myMove(widget, event);
    }
}

void Draw::myMove(QCustomPlot *widget, QMouseEvent *e)
{
    // 检查图表是否有数据
    if (widget->graphCount() == 0 || widget->graph(0)->dataCount() == 0) {
        return; // 没有数据，不更新游标
    }

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
void Draw::on_pushButton_clicked()
{
     QTimer::singleShot(1000,this,[=]{
         on_pushButton_clicked();
     });
}
