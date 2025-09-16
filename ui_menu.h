/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame_16;
    QLabel *label_15;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *saveButton;
    QFrame *frame_2;
    QLabel *label_2;
    QLineEdit *elecShow;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *voltShow;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *soundShow;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *flowShow;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLineEdit *wireSpeedShow;
    QFrame *frame_3;
    QLabel *label_11;
    QLineEdit *weldingstatus;
    QLabel *label_13;
    QFrame *frame_4;
    QLabel *label_34;
    QCustomPlot *currentPlot;
    QFrame *currentground;
    QFrame *frame_5;
    QLabel *label_35;
    QCustomPlot *voltagePlot;
    QFrame *voltageground;
    QFrame *frame_6;
    QLabel *label_36;
    QCustomPlot *soundPlot;
    QFrame *soundground;
    QFrame *frame_7;
    QLabel *label_37;
    QCustomPlot *specPlot;
    QFrame *specground;
    QFrame *frame_8;
    QLabel *label_38;
    QGraphicsView *gvMain;
    QFrame *frame_9;
    QLabel *label_39;
    QLabel *lblImage;
    QLabel *label_14;
    QFrame *frame_17;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QLabel *label_speed_total;
    QLabel *label_16;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(1280, 809);
        Menu->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"boeder-image:url(:/new/prefix1/background.png);\n"
"background:url(:/new/prefix1/background.png)\n"
"}"));
        centralWidget = new QWidget(Menu);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 25, 220, 241));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color:rgb(243, 243, 243);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(15, 10, 81, 21));
        label->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(15, 120, 190, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 170, 0);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
"color:rgb(255, 255, 255);\n"
"pressed{\n"
"background-color:rgb(0, 106, 0);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
"color:rgb(255, 255, 255);\n"
"}"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(15, 160, 190, 30));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
"color:rgb(255, 255, 255)"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(15, 200, 190, 30));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color:rgb(217, 217, 217);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
""));
        frame_16 = new QFrame(frame);
        frame_16->setObjectName("frame_16");
        frame_16->setGeometry(QRect(0, 0, 220, 241));
        frame_16->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color:rgb(243, 243, 243);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_16->setFrameShape(QFrame::Shape::NoFrame);
        label_15 = new QLabel(frame_16);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(15, 10, 81, 21));
        label_15->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        comboBox_3 = new QComboBox(frame_16);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(15, 40, 190, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(12);
        comboBox_3->setFont(font1);
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border: 1px solid rgb(195, 195, 195);\n"
""));
        comboBox_3->setFrame(true);
        comboBox_4 = new QComboBox(frame_16);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(15, 75, 190, 25));
        comboBox_4->setFont(font1);
        comboBox_4->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border: 1px solid rgb(195, 195, 195);\n"
""));
        comboBox_4->setFrame(true);
        startButton = new QPushButton(frame_16);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(15, 120, 190, 30));
        startButton->setFont(font);
        startButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 170, 0);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
"color:rgb(255, 255, 255);\n"
"pressed{\n"
"background-color:rgb(0, 106, 0);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
"color:rgb(255, 255, 255);\n"
"}"));
        stopButton = new QPushButton(frame_16);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(15, 160, 190, 30));
        stopButton->setFont(font);
        stopButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
"color:rgb(255, 255, 255)"));
        saveButton = new QPushButton(frame_16);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(15, 200, 190, 30));
        saveButton->setFont(font);
        saveButton->setStyleSheet(QString::fromUtf8("background-color:rgb(217, 217, 217);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;\n"
""));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 375, 220, 185));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{\n"
"background-color:rgb(243, 243, 243);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(15, 10, 80, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        elecShow = new QLineEdit(frame_2);
        elecShow->setObjectName("elecShow");
        elecShow->setGeometry(QRect(90, 10, 91, 20));
        elecShow->setStyleSheet(QString::fromUtf8("background-color:rgb(234, 234, 234);\n"
"border:rgb(234, 234, 234)"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(15, 45, 80, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 10, 21, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        voltShow = new QLineEdit(frame_2);
        voltShow->setObjectName("voltShow");
        voltShow->setGeometry(QRect(90, 45, 91, 20));
        voltShow->setStyleSheet(QString::fromUtf8("background-color:rgb(234, 234, 234);\n"
"border:rgb(234, 234, 234)"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 45, 21, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(15, 80, 80, 20));
        label_6->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        soundShow = new QLineEdit(frame_2);
        soundShow->setObjectName("soundShow");
        soundShow->setGeometry(QRect(90, 80, 91, 20));
        soundShow->setStyleSheet(QString::fromUtf8("background-color:rgb(234, 234, 234);\n"
"border:rgb(234, 234, 234)"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(190, 80, 21, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(15, 115, 80, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        flowShow = new QLineEdit(frame_2);
        flowShow->setObjectName("flowShow");
        flowShow->setGeometry(QRect(90, 115, 61, 20));
        flowShow->setStyleSheet(QString::fromUtf8("background-color:rgb(234, 234, 234);\n"
"border:rgb(234, 234, 234)"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(160, 115, 51, 20));
        label_9->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(15, 150, 80, 20));
        label_10->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(160, 150, 51, 20));
        label_12->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        wireSpeedShow = new QLineEdit(frame_2);
        wireSpeedShow->setObjectName("wireSpeedShow");
        wireSpeedShow->setGeometry(QRect(90, 150, 61, 20));
        wireSpeedShow->setStyleSheet(QString::fromUtf8("background-color:rgb(234, 234, 234);\n"
"border:rgb(234, 234, 234)"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 570, 221, 91));
        frame_3->setStyleSheet(QString::fromUtf8("#frame_3{\n"
"background-color:rgb(243, 243, 243);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::NoFrame);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(65, 0, 91, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setItalic(false);
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8("font: 25 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"font-weight: bold; /* \350\256\276\347\275\256\345\255\227\351\207\215\357\274\210\345\212\240\347\262\227\357\274\211 */\n"
""));
        weldingstatus = new QLineEdit(frame_3);
        weldingstatus->setObjectName("weldingstatus");
        weldingstatus->setGeometry(QRect(15, 35, 190, 45));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font4.setPointSize(28);
        font4.setBold(true);
        weldingstatus->setFont(font4);
        weldingstatus->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:;\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 5px;\n"
"}"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(340, 30, 661, 91));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font5.setPointSize(44);
        font5.setBold(false);
        label_13->setFont(font5);
        label_13->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(260, 140, 325, 250));
        frame_4->setStyleSheet(QString::fromUtf8("#frame_4{\n"
"background-color:rgb(234, 234, 234);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_4->setFrameShape(QFrame::Shape::NoFrame);
        label_34 = new QLabel(frame_4);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(120, 10, 91, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setItalic(false);
        label_34->setFont(font6);
        label_34->setStyleSheet(QString::fromUtf8(""));
        currentPlot = new QCustomPlot(frame_4);
        currentPlot->setObjectName("currentPlot");
        currentPlot->setGeometry(QRect(20, 40, 285, 191));
        currentPlot->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        currentground = new QFrame(frame_4);
        currentground->setObjectName("currentground");
        currentground->setGeometry(QRect(20, 40, 285, 191));
        currentground->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        currentground->setFrameShape(QFrame::Shape::NoFrame);
        label_34->raise();
        currentground->raise();
        currentPlot->raise();
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(600, 139, 325, 251));
        frame_5->setStyleSheet(QString::fromUtf8("#frame_5{\n"
"background-color:rgb(234, 234, 234);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::NoFrame);
        label_35 = new QLabel(frame_5);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(130, 10, 91, 21));
        label_35->setFont(font6);
        label_35->setStyleSheet(QString::fromUtf8(""));
        voltagePlot = new QCustomPlot(frame_5);
        voltagePlot->setObjectName("voltagePlot");
        voltagePlot->setGeometry(QRect(20, 40, 285, 191));
        voltagePlot->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        voltageground = new QFrame(frame_5);
        voltageground->setObjectName("voltageground");
        voltageground->setGeometry(QRect(20, 40, 285, 191));
        voltageground->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        voltageground->setFrameShape(QFrame::Shape::NoFrame);
        label_35->raise();
        voltageground->raise();
        voltagePlot->raise();
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(940, 139, 325, 251));
        frame_6->setStyleSheet(QString::fromUtf8("#frame_6{\n"
"background-color:rgb(234, 234, 234);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_6->setFrameShape(QFrame::Shape::NoFrame);
        label_36 = new QLabel(frame_6);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(120, 10, 91, 21));
        label_36->setFont(font6);
        label_36->setStyleSheet(QString::fromUtf8(""));
        soundPlot = new QCustomPlot(frame_6);
        soundPlot->setObjectName("soundPlot");
        soundPlot->setGeometry(QRect(20, 40, 285, 191));
        soundPlot->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        soundground = new QFrame(frame_6);
        soundground->setObjectName("soundground");
        soundground->setGeometry(QRect(20, 40, 285, 191));
        soundground->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        soundground->setFrameShape(QFrame::Shape::NoFrame);
        label_36->raise();
        soundground->raise();
        soundPlot->raise();
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(260, 410, 325, 250));
        frame_7->setStyleSheet(QString::fromUtf8("#frame_7{\n"
"background-color:rgb(234, 234, 234);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_7->setFrameShape(QFrame::Shape::NoFrame);
        label_37 = new QLabel(frame_7);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(120, 10, 91, 21));
        label_37->setFont(font6);
        label_37->setStyleSheet(QString::fromUtf8(""));
        specPlot = new QCustomPlot(frame_7);
        specPlot->setObjectName("specPlot");
        specPlot->setGeometry(QRect(20, 40, 285, 191));
        specPlot->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        specground = new QFrame(frame_7);
        specground->setObjectName("specground");
        specground->setGeometry(QRect(20, 40, 285, 191));
        specground->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        specground->setFrameShape(QFrame::Shape::NoFrame);
        label_37->raise();
        specground->raise();
        specPlot->raise();
        frame_8 = new QFrame(centralWidget);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(600, 410, 325, 250));
        frame_8->setStyleSheet(QString::fromUtf8("#frame_8{\n"
"background-color:rgb(234, 234, 234);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_8->setFrameShape(QFrame::Shape::NoFrame);
        label_38 = new QLabel(frame_8);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(130, 10, 91, 21));
        label_38->setFont(font6);
        label_38->setStyleSheet(QString::fromUtf8(""));
        gvMain = new QGraphicsView(frame_8);
        gvMain->setObjectName("gvMain");
        gvMain->setGeometry(QRect(20, 40, 285, 191));
        gvMain->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195);\n"
"border: 2px solid rgb(195, 195, 195);\n"
"border-radius: 0px;"));
        frame_9 = new QFrame(centralWidget);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(940, 410, 325, 250));
        frame_9->setStyleSheet(QString::fromUtf8("#frame_9{\n"
"background-color:rgb(234, 234, 234);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_9->setFrameShape(QFrame::Shape::NoFrame);
        label_39 = new QLabel(frame_9);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(120, 10, 91, 21));
        label_39->setFont(font6);
        label_39->setStyleSheet(QString::fromUtf8(""));
        lblImage = new QLabel(frame_9);
        lblImage->setObjectName("lblImage");
        lblImage->setGeometry(QRect(20, 50, 291, 181));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblImage->sizePolicy().hasHeightForWidth());
        lblImage->setSizePolicy(sizePolicy);
        lblImage->setStyleSheet(QString::fromUtf8("color: black; border: 1px solid black"));
        lblImage->setScaledContents(true);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1040, 50, 191, 61));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo2.png")));
        frame_17 = new QFrame(centralWidget);
        frame_17->setObjectName("frame_17");
        frame_17->setGeometry(QRect(20, 275, 221, 91));
        frame_17->setStyleSheet(QString::fromUtf8("#frame_17{\n"
"background-color:rgb(243, 243, 243);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame_17->setFrameShape(QFrame::Shape::NoFrame);
        pushButton_9 = new QPushButton(frame_17);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(15, 10, 190, 30));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font7.setPointSize(12);
        font7.setBold(true);
        pushButton_9->setFont(font7);
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color:rgb(217, 217, 217);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;"));
        pushButton_5 = new QPushButton(frame_17);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(15, 50, 190, 30));
        pushButton_5->setFont(font7);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color:rgb(217, 217, 217);\n"
"border: 1px solid rgb(195, 195, 195);\n"
"border-radius: 8px;"));
        label_speed_total = new QLabel(centralWidget);
        label_speed_total->setObjectName("label_speed_total");
        label_speed_total->setGeometry(QRect(20, 690, 250, 20));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 670, 91, 16));
        Menu->setCentralWidget(centralWidget);
        frame_17->raise();
        frame->raise();
        frame_2->raise();
        frame_3->raise();
        label_13->raise();
        frame_4->raise();
        frame_5->raise();
        frame_6->raise();
        frame_7->raise();
        frame_8->raise();
        frame_9->raise();
        label_14->raise();
        label_speed_total->raise();
        label_16->raise();
        menuBar = new QMenuBar(Menu);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        Menu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Menu);
        mainToolBar->setObjectName("mainToolBar");
        Menu->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\346\226\271\345\274\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Menu", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Menu", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Menu", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label_15->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\346\226\271\345\274\217", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Menu", "\346\211\223\345\272\225\347\204\212", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Menu", "\345\241\253\345\205\205\347\204\212", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("Menu", "\346\250\252\347\204\212", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Menu", "\347\253\213\347\204\212", nullptr));

        startButton->setText(QCoreApplication::translate("Menu", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        stopButton->setText(QCoreApplication::translate("Menu", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        saveButton->setText(QCoreApplication::translate("Menu", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\347\224\265\346\265\201", nullptr));
        label_3->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\347\224\265\345\216\213", nullptr));
        label_4->setText(QCoreApplication::translate("Menu", "A", nullptr));
        label_5->setText(QCoreApplication::translate("Menu", "V", nullptr));
        label_6->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\345\243\260\345\216\213", nullptr));
        label_7->setText(QCoreApplication::translate("Menu", "V", nullptr));
        label_8->setText(QCoreApplication::translate("Menu", "\346\260\224\344\275\223\346\265\201\351\207\217", nullptr));
        label_9->setText(QCoreApplication::translate("Menu", "L/min", nullptr));
        label_10->setText(QCoreApplication::translate("Menu", "\351\200\201\344\270\235\351\200\237\345\272\246", nullptr));
        label_12->setText(QCoreApplication::translate("Menu", "mm/s", nullptr));
        label_11->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\347\212\266\346\200\201", nullptr));
        label_13->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\345\244\232\344\277\241\346\201\257\345\234\250\347\272\277\347\233\221\346\265\213\350\275\257\344\273\266", nullptr));
        label_34->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\347\224\265\346\265\201", nullptr));
        label_35->setText(QCoreApplication::translate("Menu", "\347\224\265\345\274\247\347\224\265\345\216\213", nullptr));
        label_36->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\345\243\260\351\237\263", nullptr));
        label_37->setText(QCoreApplication::translate("Menu", "\345\205\211\350\260\261\350\260\261\347\272\277", nullptr));
        label_38->setText(QCoreApplication::translate("Menu", "\347\206\224\346\261\240\345\233\276\345\203\217", nullptr));
        label_39->setText(QCoreApplication::translate("Menu", "\347\272\242\345\244\226\345\233\276\345\203\217", nullptr));
        lblImage->setText(QCoreApplication::translate("Menu", "Image", nullptr));
        label_14->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\345\267\245\350\211\272\346\225\260\346\215\256\345\272\223", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\347\274\272\351\231\267\346\225\260\346\215\256\345\272\223", nullptr));
        label_speed_total->setText(QCoreApplication::translate("Menu", "\347\251\272\351\227\264\345\220\210\351\200\237\345\272\246\357\274\232-- mm/s", nullptr));
        label_16->setText(QCoreApplication::translate("Menu", "\343\200\220\346\234\272\345\231\250\344\272\272\351\200\237\345\272\246\343\200\221", nullptr));
        menu->setTitle(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\345\244\232\344\277\241\346\201\257\345\234\250\347\272\277\347\233\221\346\265\213\350\275\257\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
