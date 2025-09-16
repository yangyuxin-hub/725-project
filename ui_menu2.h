/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *visionButton;
    QPushButton *arcButton;
    QPushButton *soundButton;
    QPushButton *airstreamButton;
    QPushButton *tempButton;
    QPushButton *rayButton;
    QPushButton *configButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *elecShow;
    QLineEdit *voltShow;
    QLineEdit *soundShow;
    QLineEdit *flowShow;
    QLineEdit *wireSpeedShow;
    QLineEdit *timeShow;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *saveButton;
    QLabel *label_6;
    QLabel *label_8;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *currentPlot;
    QCustomPlot *voltagePlot;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QCustomPlot *soundPlot;
    QCustomPlot *airstreamPlot;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_4;
    QGraphicsView *gvMain;
    QCustomPlot *specPlot;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_F;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(1371, 836);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 90, 161, 205));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        visionButton = new QPushButton(verticalLayoutWidget);
        visionButton->setObjectName(QString::fromUtf8("visionButton"));

        verticalLayout->addWidget(visionButton);

        arcButton = new QPushButton(verticalLayoutWidget);
        arcButton->setObjectName(QString::fromUtf8("arcButton"));

        verticalLayout->addWidget(arcButton);

        soundButton = new QPushButton(verticalLayoutWidget);
        soundButton->setObjectName(QString::fromUtf8("soundButton"));

        verticalLayout->addWidget(soundButton);

        airstreamButton = new QPushButton(verticalLayoutWidget);
        airstreamButton->setObjectName(QString::fromUtf8("airstreamButton"));

        verticalLayout->addWidget(airstreamButton);

        tempButton = new QPushButton(verticalLayoutWidget);
        tempButton->setObjectName(QString::fromUtf8("tempButton"));

        verticalLayout->addWidget(tempButton);

        rayButton = new QPushButton(verticalLayoutWidget);
        rayButton->setObjectName(QString::fromUtf8("rayButton"));

        verticalLayout->addWidget(rayButton);

        configButton = new QPushButton(centralwidget);
        configButton->setObjectName(QString::fromUtf8("configButton"));
        configButton->setGeometry(QRect(20, 720, 161, 28));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(21, 330, 165, 181));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        elecShow = new QLineEdit(horizontalLayoutWidget);
        elecShow->setObjectName(QString::fromUtf8("elecShow"));

        verticalLayout_2->addWidget(elecShow);

        voltShow = new QLineEdit(horizontalLayoutWidget);
        voltShow->setObjectName(QString::fromUtf8("voltShow"));

        verticalLayout_2->addWidget(voltShow);

        soundShow = new QLineEdit(horizontalLayoutWidget);
        soundShow->setObjectName(QString::fromUtf8("soundShow"));

        verticalLayout_2->addWidget(soundShow);

        flowShow = new QLineEdit(horizontalLayoutWidget);
        flowShow->setObjectName(QString::fromUtf8("flowShow"));

        verticalLayout_2->addWidget(flowShow);

        wireSpeedShow = new QLineEdit(horizontalLayoutWidget);
        wireSpeedShow->setObjectName(QString::fromUtf8("wireSpeedShow"));

        verticalLayout_2->addWidget(wireSpeedShow);

        timeShow = new QLineEdit(horizontalLayoutWidget);
        timeShow->setObjectName(QString::fromUtf8("timeShow"));

        verticalLayout_2->addWidget(timeShow);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(20, 539, 161, 151));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(verticalLayoutWidget_4);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout_4->addWidget(startButton);

        pauseButton = new QPushButton(verticalLayoutWidget_4);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        verticalLayout_4->addWidget(pauseButton);

        stopButton = new QPushButton(verticalLayoutWidget_4);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        verticalLayout_4->addWidget(stopButton);

        saveButton = new QPushButton(verticalLayoutWidget_4);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout_4->addWidget(saveButton);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 480, 31, 281));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(760, 600, 31, 51));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(210, 90, 41, 371));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(250, 90, 501, 371));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        currentPlot = new QCustomPlot(verticalLayoutWidget_6);
        currentPlot->setObjectName(QString::fromUtf8("currentPlot"));

        verticalLayout_6->addWidget(currentPlot);

        voltagePlot = new QCustomPlot(verticalLayoutWidget_6);
        voltagePlot->setObjectName(QString::fromUtf8("voltagePlot"));

        verticalLayout_6->addWidget(voltagePlot);

        verticalLayoutWidget_7 = new QWidget(centralwidget);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(800, 90, 501, 371));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        soundPlot = new QCustomPlot(verticalLayoutWidget_7);
        soundPlot->setObjectName(QString::fromUtf8("soundPlot"));

        verticalLayout_7->addWidget(soundPlot);

        airstreamPlot = new QCustomPlot(verticalLayoutWidget_7);
        airstreamPlot->setObjectName(QString::fromUtf8("airstreamPlot"));

        verticalLayout_7->addWidget(airstreamPlot);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(760, 90, 41, 371));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, -10, 471, 91));
        gvMain = new QGraphicsView(centralwidget);
        gvMain->setObjectName(QString::fromUtf8("gvMain"));
        gvMain->setGeometry(QRect(250, 480, 501, 281));
        QBrush brush(QColor(127, 127, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        gvMain->setBackgroundBrush(brush);
        specPlot = new QCustomPlot(centralwidget);
        specPlot->setObjectName(QString::fromUtf8("specPlot"));
        specPlot->setGeometry(QRect(800, 540, 499, 181));
        Menu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);
        menuBar = new QMenuBar(Menu);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1371, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        Menu->setMenuBar(menuBar);

        menuBar->addAction(menu_F->menuAction());

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "MainWindow", nullptr));
        visionButton->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\350\247\206\350\247\211\346\250\241\345\235\227", nullptr));
        arcButton->setText(QCoreApplication::translate("Menu", "\347\224\265\345\274\247\344\274\240\346\204\237\346\250\241\345\235\227", nullptr));
        soundButton->setText(QCoreApplication::translate("Menu", "\345\243\260\351\237\263\351\207\207\351\233\206\346\250\241\345\235\227", nullptr));
        airstreamButton->setText(QCoreApplication::translate("Menu", "\347\204\212\346\216\245\346\260\224\346\265\201\346\250\241\345\235\227", nullptr));
        tempButton->setText(QCoreApplication::translate("Menu", "\347\272\242\345\244\226\346\265\213\346\270\251\346\250\241\345\235\227", nullptr));
        rayButton->setText(QCoreApplication::translate("Menu", "\345\205\211\350\260\261\344\274\240\346\204\237\346\250\241\345\235\227", nullptr));
        configButton->setText(QCoreApplication::translate("Menu", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\347\204\212\346\216\245\347\224\265\346\265\201</p><p align=\"center\">\347\204\212\346\216\245\347\224\265\345\216\213</p><p align=\"center\">\347\224\265\345\274\247\345\243\260\351\237\263</p><p align=\"center\">\347\204\212\346\216\245\346\260\224\346\265\201</p><p align=\"center\">\351\200\201\344\270\235\351\200\237\345\272\246</p><p align=\"center\">\351\207\207\351\233\206\346\227\266\351\227\264</p></body></html>", nullptr));
        startButton->setText(QCoreApplication::translate("Menu", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pauseButton->setText(QCoreApplication::translate("Menu", "\346\232\202\345\201\234\351\207\207\351\233\206", nullptr));
        stopButton->setText(QCoreApplication::translate("Menu", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        saveButton->setText(QCoreApplication::translate("Menu", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label_6->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\347\206\224</p><p align=\"center\">\346\261\240</p><p align=\"center\">\345\233\276</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\347\204\212\346\216\245</p><p align=\"center\">\347\212\266\345\206\265</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\347\224\265\346\265\201</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\347\224\265\345\216\213</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\345\243\260\351\237\263</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\">\346\260\224\344\275\223</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Menu", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">\344\270\255\350\210\271725\347\204\212\346\216\245\350\264\250\351\207\217\345\234\250\347\272\277\347\233\221\346\265\213\347\263\273\347\273\237</span></p></body></html>", nullptr));
        menu_F->setTitle(QCoreApplication::translate("Menu", "\346\226\207\344\273\266(&F)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
