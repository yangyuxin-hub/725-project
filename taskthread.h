#ifndef TASKTHREAD_H
#define TASKTHREAD_H

#include <QThread>
#include <QDateTime>
#include <QPixmap>
#include <QString>

// 对Menu类进行前向声明，以确保两个h文件中的类可以互相引用且不发生编译报错
class Menu;

class TaskThread : public QThread {
    Q_OBJECT
public:
    enum TaskType {
        CollectWeldMap, // 采集熔池图像
        UpdateAcquiCardPlot // 更新数据采集卡图表
    };

    TaskThread(Menu *MainWindow, TaskType type, QString timeStamp, QObject* parent = nullptr)
        : QThread(parent), stopCollection(false), MainWindow(MainWindow), taskType(type), timeStamp(timeStamp) {}

    void run() override;



    void stop() { stopCollection = true; }

private:
    volatile bool stopCollection; // 控制线程停止的标志位
    Menu *MainWindow; // 主界面的类对象
    TaskType taskType; // 任务类型
    QString timeStamp; // 时间戳
};

#endif // TASKTHREAD_H
