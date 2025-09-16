#include "vision.h"
#include "ui_vision.h"
#include "qcustomplot.h"

Vision* Vision::instance = nullptr; // 单例模式

Vision* Vision::getInstance() // 单例模式
{
    if (!instance) instance = new Vision();
    return instance;
}

Vision::Vision(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Vision)
{
    ui->setupUi(this);
}

Vision::~Vision()
{
    delete ui;
}
