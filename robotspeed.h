#ifndef ROBOTSPEED_H
#define ROBOTSPEED_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <snap7.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class RobotSpeed;

// 对Menu类进行前向声明，以确保两个h文件中的类可以互相引用且不发生编译报错
class Menu;
}
QT_END_NAMESPACE

class RobotSpeed : public QMainWindow
{
    Q_OBJECT

public:
    RobotSpeed(QWidget *parent = nullptr);
    ~RobotSpeed();
    TS7Client *client;

    Ui::Menu *ui;

//private slots:
public slots:
    void on_Connect_buttom_clicked();

    void on_Disconnect_buttom_clicked();

//private:
public:
    //Ui::RobotSpeed *ui;

    QTimer *readTimer;
    void initStyles();

    void readRobotPosition();

    QElapsedTimer positionTimer;    // 用于计时（两个坐标之间的时间间隔）
    float lastX = 0.0f;             // 上一次的 X 坐标
    float lastY = 0.0f;             // 上一次的 Y 坐标
    float lastZ = 0.0f;             // 上一次的 Z 坐标
    bool hasLast = false;           // 用于判断是否已有上一次数据（第一帧跳过计算）

    QVector<QVector3D> recentPos;

    static const QString filePath; // 保存文件的路径

};
#endif // ROBOTSPEED_H
