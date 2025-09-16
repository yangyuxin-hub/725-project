/********************************************************************************
** Form generated from reading UI file 'vision.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISION_H
#define UI_VISION_H

#include <../../qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vision
{
public:
    QWidget *centralwidget;
    QCustomPlot *widget_2;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Vision)
    {
        if (Vision->objectName().isEmpty())
            Vision->setObjectName("Vision");
        Vision->resize(1280, 800);
        centralwidget = new QWidget(Vision);
        centralwidget->setObjectName("centralwidget");
        widget_2 = new QCustomPlot(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(40, 60, 1011, 631));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(1090, 240, 161, 28));
        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(1090, 60, 161, 151));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget_4);
        pushButton->setObjectName("pushButton");

        verticalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget_4);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget_4);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_4->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget_4);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout_4->addWidget(pushButton_4);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(1090, 290, 171, 89));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        textBrowser = new QTextBrowser(horizontalLayoutWidget);
        textBrowser->setObjectName("textBrowser");

        horizontalLayout->addWidget(textBrowser);

        Vision->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Vision);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        Vision->setMenuBar(menubar);
        statusbar = new QStatusBar(Vision);
        statusbar->setObjectName("statusbar");
        Vision->setStatusBar(statusbar);

        retranslateUi(Vision);

        QMetaObject::connectSlotsByName(Vision);
    } // setupUi

    void retranslateUi(QMainWindow *Vision)
    {
        Vision->setWindowTitle(QCoreApplication::translate("Vision", "MainWindow", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Vision", "\350\256\276\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("Vision", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Vision", "\346\232\202\345\201\234\351\207\207\351\233\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Vision", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Vision", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label->setText(QCoreApplication::translate("Vision", "<html><head/><body><p align=\"center\">\347\206\224\346\261\240\351\225\277\345\272\246\357\274\232</p><p align=\"center\">\347\206\224\346\261\240\345\256\275\345\272\246\357\274\232</p><p align=\"center\">\345\270\247\347\216\207\357\274\232</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Vision: public Ui_Vision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISION_H
