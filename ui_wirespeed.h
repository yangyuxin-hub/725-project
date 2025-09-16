/********************************************************************************
** Form generated from reading UI file 'wirespeed.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIRESPEED_H
#define UI_WIRESPEED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WireSpeed
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btn_open;
    QPushButton *btn_write;
    QPushButton *btn_close;
    QPushButton *btn_clear;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WireSpeed)
    {
        if (WireSpeed->objectName().isEmpty())
            WireSpeed->setObjectName("WireSpeed");
        WireSpeed->resize(800, 600);
        centralwidget = new QWidget(WireSpeed);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        btn_open = new QPushButton(centralwidget);
        btn_open->setObjectName("btn_open");

        gridLayout->addWidget(btn_open, 0, 0, 1, 1);

        btn_write = new QPushButton(centralwidget);
        btn_write->setObjectName("btn_write");

        gridLayout->addWidget(btn_write, 3, 0, 1, 1);

        btn_close = new QPushButton(centralwidget);
        btn_close->setObjectName("btn_close");

        gridLayout->addWidget(btn_close, 1, 0, 1, 1);

        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName("btn_clear");

        gridLayout->addWidget(btn_clear, 2, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 0, 1, 4, 1);

        WireSpeed->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WireSpeed);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        WireSpeed->setMenuBar(menubar);
        statusbar = new QStatusBar(WireSpeed);
        statusbar->setObjectName("statusbar");
        WireSpeed->setStatusBar(statusbar);

        retranslateUi(WireSpeed);

        QMetaObject::connectSlotsByName(WireSpeed);
    } // setupUi

    void retranslateUi(QMainWindow *WireSpeed)
    {
        WireSpeed->setWindowTitle(QCoreApplication::translate("WireSpeed", "MainWindow", nullptr));
        btn_open->setText(QCoreApplication::translate("WireSpeed", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        btn_write->setText(QCoreApplication::translate("WireSpeed", "\345\206\231\345\205\245\345\257\204\345\255\230\345\231\250", nullptr));
        btn_close->setText(QCoreApplication::translate("WireSpeed", "\345\201\234\346\255\242\346\265\213\351\207\217", nullptr));
        btn_clear->setText(QCoreApplication::translate("WireSpeed", "\346\270\205\347\251\272\350\256\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WireSpeed: public Ui_WireSpeed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIRESPEED_H
