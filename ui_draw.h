/********************************************************************************
** Form generated from reading UI file 'draw.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAW_H
#define UI_DRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Draw
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *currentPlot;
    QCustomPlot *voltagePlot;
    QCustomPlot *soundPlot;
    QPushButton *startButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Draw)
    {
        if (Draw->objectName().isEmpty())
            Draw->setObjectName(QString::fromUtf8("Draw"));
        Draw->resize(915, 672);
        centralwidget = new QWidget(Draw);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 28, 160, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(260, 30, 591, 521));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        currentPlot = new QCustomPlot(verticalLayoutWidget_2);
        currentPlot->setObjectName(QString::fromUtf8("currentPlot"));

        verticalLayout_2->addWidget(currentPlot);

        voltagePlot = new QCustomPlot(verticalLayoutWidget_2);
        voltagePlot->setObjectName(QString::fromUtf8("voltagePlot"));

        verticalLayout_2->addWidget(voltagePlot);

        soundPlot = new QCustomPlot(verticalLayoutWidget_2);
        soundPlot->setObjectName(QString::fromUtf8("soundPlot"));

        verticalLayout_2->addWidget(soundPlot);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(80, 570, 141, 28));
        Draw->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Draw);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 915, 26));
        Draw->setMenuBar(menubar);
        statusbar = new QStatusBar(Draw);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Draw->setStatusBar(statusbar);

        retranslateUi(Draw);

        QMetaObject::connectSlotsByName(Draw);
    } // setupUi

    void retranslateUi(QMainWindow *Draw)
    {
        Draw->setWindowTitle(QCoreApplication::translate("Draw", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Draw", "<html><head/><body><p align=\"center\">\347\224\265\346\265\201\357\274\210\351\235\231\346\200\201\347\273\230\345\233\276\357\274\211</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Draw", "<html><head/><body><p align=\"center\">\347\224\265\345\216\213\357\274\210\351\235\231\346\200\201\347\273\230\345\233\276\357\274\211</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Draw", "<html><head/><body><p align=\"center\">\345\243\260\351\237\263\357\274\210\351\235\231\346\200\201\347\273\230\345\233\276\357\274\211</p></body></html>", nullptr));
        startButton->setText(QCoreApplication::translate("Draw", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Draw: public Ui_Draw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAW_H
