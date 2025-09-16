#ifndef MENU_H
#define MENU_H


#include <QMainWindow>
#include "configuredialog.h"
#include "MecaVision.h"
#include "frm_irbgrab_v4.h"
#include "Modbus.h"
#include "ui_Modbus.h" // 为了确保能够在主控界面的类中调用子界面的控件
// #include "infraredtemp.h" // 红外测温
#include "spectrum.h" // 光谱

// 在引用采集卡的h文件前先对Menu类进行前向声明，以确保两个h文件中的类可以互相引用且不发生编译报错
class Menu;

#include "streamingbufferedai.h"
#include "taskthread.h"
#include "wirespeed.h" // 送丝速度

#include <QPixmap> // 图片
#include <QPainter> // 绘图
#include <QDateTime> // 获取日期时间
#include <string>
#include <QList>

#include "application.h"

#include "robotspeed.h" // 机器人速度

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
//    void on_configButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_saveButton_clicked();
public:
    Ui::Menu *ui;

    void openSubModule(); // 在打开软件时即打开子模块并隐藏子模块界面
    void openConfiguredialog(); // 打开configuredialog.ui，对应电弧、声音传感界面
    bool ConnectInfraDevice(int connectionIndex); //连接红外设备
    bool Device_Grab(int aStreamIndex, bool aGrabbing);


//private:
public:
    //Ui::Menu *ui; // 已改为公有成员
    AI_StreamingBufferedAi buffer;
    ConfigureDialog dialog;
    //MecaVision w; // 已改为指针
    MecaVision *w;
    irbgrab *f;
    Modbus m; // 改为指针得到话会crash，原因暂未知
    //Modbus *m;

    bool stopCollection = true; // 停止采集信号
    QList<TaskThread*> threads; // 储存所有子线程的列表
    TaskThread* updatePlot; // 数据采集卡绘图的线程
    QString timeStamp = "null"; // 时间戳

    /// 气体 ///
    bool ifPause = false; // 用于判别目前是否处于暂停状态

    /// 熔池图 ///
    QTimer *captureTimer = new QTimer(this); // 熔池保存图像的QTimer

   QPixmap *weldPoolMap = nullptr; // 熔池瞬时图像
   QGraphicsPixmapItem* pixmapItem; // 图形项的容器，在QGraphicsView中显示QPixmap所必须的包装
   QPainter *weldPoolMapPainter = nullptr; // 绘制熔池瞬时图像的对象
   QGraphicsScene* singleShot; // 用于显示瞬时图像的scene

   QTimer *infraTimer = new QTimer(this); // 红外保存图像的QTimer
   bool ifcapture = false;

    /// 采集卡 ///
    bool ifDrawAcquiCard = false; // 用于确认是否采集数据绘制采集卡图像的成员
    QTimer* dataTimer = new QTimer(this); // 计时器
    int count = 0; // x轴坐标
    double scaledData = 0; // y轴数值
    std::vector<double> combined;

//    /// 红外测温 ///
//    InfraredTemp infTemp;
//    bool getInfTempData(); // 进行红外测温并获取数据-test

    /// 光谱 ///
    application *app;
    spectrum *spec;
    QTimer *specTimer = new QTimer(this); // 光谱保存的QTimer

    /// 送丝速度 ///
    WireSpeed wireSpeed;

    /// 机器人速度 ///
    RobotSpeed robotSpeed;



    static QString timeValue; // 实时运行时间
    double startTime; // 开始采集时间
    std::streampos lastReadFilePos = 0; // 上次文件读取位置





public slots:
    void updateAcquiCardPlot(); // 更新采集卡图像的函数
    void captureFrame(); // 采集熔池图像的函数
    void captureInfrared(); // 采集红外图像的函数
    void updateLineEditContent(); // 更新左侧文本框内容
    //void getSpecData(); // 获取光谱数据-测试
};

#endif // MENU_H
