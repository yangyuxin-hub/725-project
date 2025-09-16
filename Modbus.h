#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>         // 提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>     // 提供系统中存在的串口信息
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <Windows.h>

#include <QDateTime> // 时间
#include <QTimer> // 计时器

// 对Menu类进行前向声明，以确保两个h文件中的类可以互相引用且不发生编译报错
class Menu;

namespace Ui {
class Modbus;
}

class Modbus : public QWidget
{
    Q_OBJECT

public:
    explicit Modbus(QWidget *parent = nullptr);
    void initialPort();
    ~Modbus();

//private slots: // 为了能够在menu.cpp中显式调用而改为公有成员
public slots:
    void on_startflowButton_clicked();

    void on_stopflowButton_clicked();

    void on_clearRecvPushButton_clicked();
public:
    Ui::Modbus *ui;

private:
    //Ui::Modbus *ui; // 已转为public
    HANDLE hSerial;
    DCB dcbSerialParams;
    COMMTIMEOUTS timeouts;
    bool readornot;

public:
    double startTime; // 气体流量开始采集的毫秒时间戳
    QTimer* dataTimer = new QTimer(this); // 计时器


public slots:
    void updatePlot(); // 更新图表的槽函数

public:
    Menu* pToMenu = nullptr; // 指向主控界面的指针
    bool ifMenuView = false; // 用于判别是否在主控界面显示采集卡信息，true代表显示
    static const QString filePath; // 保存文件的路径
    static QString flowValue; // 实时气流s
};

#endif // WIDGET_H
