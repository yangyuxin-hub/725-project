#ifndef WIRESPEED_H
#define WIRESPEED_H

#include <QMainWindow>
#include <QWidget>
#include <QtSerialPort/QSerialPort>         // 提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>     // 提供系统中存在的串口信息
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <Windows.h>
#include <QPlainTextEdit>

#include <QDateTime> // 时间
#include <QTimer> // 计时器

QT_BEGIN_NAMESPACE
namespace Ui { class WireSpeed; }
QT_END_NAMESPACE

class QPlainTextEdit; // 前置声明

class WireSpeed : public QMainWindow
{
    Q_OBJECT

public:
    WireSpeed(QWidget *parent = nullptr);
    void initialPort();
    ~WireSpeed();

//private slots:
public slots:
    void on_btn_open_clicked();// 处理打开按钮点击事件

    void on_btn_close_clicked();

    void on_btn_clear_clicked();

private:
    Ui::WireSpeed *ui;
    QPlainTextEdit* plainTextEdit; // 显示串口数据的文本编辑框
    HANDLE hSerial; // 串口句柄
    DCB dcbSerialParams;
    COMMTIMEOUTS timeouts;

    bool readornot;//读取标志

    static WireSpeed* instance; // 单例模式

 public:
    double startTime; // 数据开始采集的毫秒时间戳
    QTimer* dataTimer = new QTimer(this); // 计时器

    static WireSpeed* getInstance(); // 单例模式

    static QString speedValue; // 实时转速
    static const QString filePath; // 保存文件的路径

public slots:
    void updatePlot(); // 更新图表的槽函数
};
#endif // WIRESPEED_H
