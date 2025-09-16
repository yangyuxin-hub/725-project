#include "robotspeed.h"
//#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QDateTime>
#include <cmath>

#include <cstring>

// 确保两个h文件中定义的类可以互相引用
#include "menu.h"
#include "ui_menu.h"

const QString RobotSpeed::filePath = "Temp_RobotSpeed.txt"; // 保存文件的路径(txt)

void RobotSpeed::initStyles()
{
//    // ✅ 设置“连接”按钮样式
//    ui->Connect_buttom->setStyleSheet(
//        "QPushButton {"
//        "   background-color: #4CAF50;"        // 绿色背景
//        "   color: white;"                     // 白色字体
//        "   font: bold 14px;"                  // 字体加粗
//        "   border-radius: 10px;"              // 圆角
//        "   padding: 6px 12px;"                // 内边距
//        "}"
//        "QPushButton:hover {"
//        "   background-color: #45a049;"        // 悬停变色
//        "}"
//        );

//    // ✅ 设置“断开”按钮样式
//    ui->Disconnect_buttom->setStyleSheet(
//        "QPushButton {"
//        "   background-color: #f44336;"        // 红色背景
//        "   color: white;"
//        "   font: bold 14px;"
//        "   border-radius: 10px;"
//        "   padding: 6px 12px;"
//        "}"
//        "QPushButton:hover {"
//        "   background-color: #e53935;"
//        "}"
//        );

//    // ✅ 设置焊接速度标签样式
//    ui->label_speed_x->setStyleSheet(
//        "QLabel {"
//        "   color: #2196F3;"                   // 蓝色字体
//        "   font: bold 18px;"                  // 加粗、大字体
//        "   qproperty-alignment: AlignCenter;" // 居中显示
//        "}"
//        );
//    ui->label_speed_y->setStyleSheet(
//        "QLabel {"
//        "   color: #2196F3;"                   // 蓝色字体
//        "   font: bold 18px;"                  // 加粗、大字体
//        "   qproperty-alignment: AlignCenter;" // 居中显示
//        "}"
//        );
//    ui->label_speed_z->setStyleSheet(
//        "QLabel {"
//        "   color: #2196F3;"                   // 蓝色字体
//        "   font: bold 18px;"                  // 加粗、大字体
//        "   qproperty-alignment: AlignCenter;" // 居中显示
//        "}"
//        );
//    ui->label_speed_total->setStyleSheet(
//        "QLabel {"
//        "   color: #2196F3;"                   // 蓝色字体
//        "   font: bold 18px;"                  // 加粗、大字体
//        "   qproperty-alignment: AlignCenter;" // 居中显示
//        "}"
//        );
//    ui->label_status_text->setStyleSheet(
//        "QLabel {"
//        "   color: #555;"
//        "   font: 14px;"
//        "}"
//        );
//    ui->label_status_text->setText("状态：未连接");

}


// 构造函数：初始化界面、Snap7客户端和定时器
RobotSpeed::RobotSpeed(QWidget *parent)
{
    readTimer = new QTimer(this);

    //ui->setupUi(this);
    client = new TS7Client();
    connect(readTimer, &QTimer::timeout, this, &RobotSpeed::readRobotPosition);
    initStyles();
//    readTimer->start(100000); // 每100ms刷新一次

//    positionTimer.start();  // 启动计时器
//    on_Connect_buttom_clicked();
}
// 析构函数：释放资源
RobotSpeed::~RobotSpeed()
{
    //delete ui;
    //on_Disconnect_buttom_clicked();

}

void RobotSpeed::readRobotPosition()
{
    if (!client->Connected()) {
        QMessageBox::information(this, "提示", "PLC未连接！");
        return;
    }

    byte buffer[256] = {0};
    //int result = client->DBRead(1, 0, 24, buffer);  // 本地调试
    int result = client->DBRead(202, 184, 24, buffer);  // 修改为实际DB
    if (result == 0) {
        float pos[6] = {0};

        for (int i = 0; i < 6; ++i) {
            byte temp[4];
            memcpy(temp, buffer + i * 4, 4);
            std::reverse(temp, temp + 4);  // S7大端转PC小端

            memcpy(&pos[i], temp, sizeof(float));
//            // 打印偏移和数值，方便调试
//            qDebug() << QString("偏移 %1: %2").arg(184 + i * 4).arg(value);

//            //更新UI显示
//            switch (i) {
//            case 0: ui->label_pos_x->setText(QString::number(value, 'f', 2)); break;
//            case 1: ui->label_pos_y->setText(QString::number(value, 'f', 2)); break;
//            case 2: ui->label_pos_z->setText(QString::number(value, 'f', 2)); break;
//            case 3: ui->label_pos_a->setText(QString::number(value, 'f', 2)); break;
//            case 4: ui->label_pos_b->setText(QString::number(value, 'f', 2)); break;
//            case 5: ui->label_pos_c->setText(QString::number(value, 'f', 2)); break;
//            }
        }

        QVector3D currentPos(pos[0], pos[1], pos[2]);
        recentPos.push_back(currentPos);
        if (recentPos.size() > 10)
            recentPos.pop_front();

        if (recentPos.size() >= 2 && hasLast) {
            float dt = positionTimer.elapsed() / 1000.0f;
            if (dt > 0.01f) {
                QVector3D dir = recentPos.back() - recentPos.front();
                QVector3D v = currentPos - QVector3D(lastX, lastY, lastZ);

                QVector3D unitDir = dir.normalized();
                float v_proj = QVector3D::dotProduct(v, unitDir) / dt;

//                qDebug() << QString("主方向速度: %1 mm/s").arg(v_proj, 0, 'f', 2);
                ui->label_speed_total->setText(QString::number(v_proj, 'f', 2));


                // txt中保存数据
                QFile file(filePath); // 相对路径
                if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
                    qWarning("Cannot open file for writing");
                }
                QTextStream textStream(&file);
                textStream << QString::number(v_proj, 'f', 2) << "\n";
                file.close();
            }
        }

        lastX = pos[0];
        lastY = pos[1];
        lastZ = pos[2];
        positionTimer.restart();
        hasLast = true;
    }
}

//void MainWindow::readRobotPosition()
//{
//    if(!client->Connected()) {
//        QMessageBox::information(this, "提示", "PLC未连接！");
//        return;
//    }

//    byte buffer[256] = {0};
//    // 读取DB块202，从偏移180开始，长度128字节（确认这是否你想要的偏移和长度）
//    int result = client->DBRead(202, 180, 128, buffer);
//    if(result != 0) {
//        qDebug() << "DBRead失败，错误码：" << result;
//        return;
//    }

//    qDebug() << "==== DB202 偏移180开始，128字节数据按 float 解析 ====";

//    // 每4字节作为一个float，偏移范围从0到124（128字节），步长4
//    for (int offset = 0; offset < 128; offset += 4) {
//        byte temp[4];
//        memcpy(temp, buffer + offset, 4);
//        std::reverse(temp, temp + 4);  // S7大端转小端

//        float value;
//        memcpy(&value, temp, sizeof(float));

//        qDebug() << QString("偏移 %1: %2").arg(offset + 180).arg(value); // 打印实际偏移地址
//    }

//    qDebug() << "======================================";
//}




// 槽函数：连接按钮点击事件
void RobotSpeed::on_Connect_buttom_clicked()
{
    QString ip = "192.168.1.91"; // 改成中船PLC的ip地址即可
    //QString ip = "127.0.0.1"; // 本地调试
    int rack = 0;
    int slot = 1;
    int reg = client->ConnectTo(ip.toStdString().c_str(), rack, slot);
    qDebug() << "连接结果：" << reg;
    if (reg == 0)
    {
        QMessageBox::information(this, "提示", "连接成功！");
        readTimer->start(1000);
//        ui->label_status_text->setText("状态：已连接");
    }
    else
    {
        QMessageBox::warning(this, "提示", QString("连接失败，错误码：%1").arg(reg));
    }
}

// 槽函数：断开按钮点击事件
void RobotSpeed::on_Disconnect_buttom_clicked()
{
    if (client->Connected())
    {
        client->Disconnect();
        readTimer->stop();
        QMessageBox::information(this, "提示", "已断开连接！");
    }
    else
    {
        QMessageBox::information(this, "提示", "当前未连接！");
    }
}
