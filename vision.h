#ifndef VISION_H
#define VISION_H

#include <QMainWindow>

namespace Ui {
class Vision;
}

class Vision : public QMainWindow
{
    Q_OBJECT

public:
    explicit Vision(QWidget *parent = nullptr);
    ~Vision();

    static Vision* getInstance(); // 单例模式

private:
    Ui::Vision *ui;
    static Vision* instance; // 单例模式
};

#endif // VISION_H
