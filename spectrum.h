#ifndef SPECTRUM_H
#define SPECTRUM_H

#define AVS_POSTMESSAGE
#include "avaspec.h"

#include <windows.h>
#include <QDebug>
#include <QFile>
#include <QThread>
#include <QDateTime>
#include <QTimer>

#include "application.h"

typedef struct
{
    AvsIdentityType  avsID;
    int              avsDeviceHandle;
    DeviceConfigType avsparam;
    MeasConfigType   PrepareMeasParam;
    long             NrMeas;
    uint             PreviousTimeStamp;
    long             m_Failures;
} Device;

#define  MAX_NR_DEVICES 20

// 对Menu类进行前向声明，以确保两个h文件中的类可以互相引用且不发生编译报错
class Menu;

class spectrum: public QObject
{
    Q_OBJECT
public:
    spectrum(application *app, QObject *parent = nullptr); // 设备连接和初始化
    ~spectrum();
public:
    Menu* pToMenu = nullptr; // 指向主控界面的指针

    AvsHandle a_hDevice; // 设备句柄
    DeviceConfigType l_DeviceData; // 设备设置参数
    MeasConfigType l_PrepareMeasData; // 测量参数

    int m_NrOfDevices = 0; // 设备数量

    static double m_Spectrum[MAX_NR_DEVICES][MAX_NR_PIXELS];
    static double m_Lambda[MAX_NR_DEVICES][MAX_NR_PIXELS];

    int chkSync = 1; // 同步模式状态 0表示非同步模式，1表示同步模式
    int cbMaster = 0; // 主设备设备号

    const short a_Nmsr = -1; // 一次调用AVS_Measure后要执行的测量数（-1为无穷大，-2用于启动Dynamic StoreToRam）
    unsigned int a_TimeLabel = 0;
        // ticks count lasr pixel of spectrum is received by microcontroller
        //     ticks in 10μs units since spectrometer started
    double a_pSpectrum[MAX_NR_PIXELS]; // 保存数据使用的数组，MAX_NR_PIXELS=4096
    static const QString filePath; // 保存文件的路径(txt)

    bool UpdateList(); // 更新设备列表
    bool activateDevice(); // 激活所有设备
    bool setParams(); // 设置参数
    //bool startMeasure(HWND hwnd); // 开始测量
    bool startMeasure(); // 开始测量
    //bool getData(); // 获取测量数据
    bool stopMeasure(); // 停止测量

    //bool test(); // TODO:修改

    void save2txt(int i); // 保存数据到文件

public slots:
    void ReceiveDataIsHere(int WParam, int LParam);
    // avoid a name starting with "on_" here, otherwise you will get a
    // warning, as there is no defined signal, just an emit in "application.cpp"
    void timerSlot();

    void update_plot(); // 更新menu的光谱图
private:
    QTimer *timer; // 定时器
    QDateTime m_StartTicks; // 开始测量时间
    int m_TotalFailures = 0;
    Device m_Device[MAX_NR_DEVICES]; // 设备

    unsigned int m_Time[MAX_NR_DEVICES];   // timestamp value
    unsigned int m_Dif[MAX_NR_DEVICES];    // timestamp value
    QDateTime m_Ticks[MAX_NR_DEVICES];
    QDateTime m_Ticks_all;

private:
    application *m_app; // 持有 application 对象的指针
};

#endif // SPECTRUM_H
