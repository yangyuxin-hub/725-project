/********************************************************************************
** Form generated from reading UI file 'Modbus.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUS_H
#define UI_MODBUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Modbus
{
public:
    QTextEdit *recvTextEdit;
    QLabel *label_7;
    QPushButton *clearRecvPushButton;
    QPushButton *startflowButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *stopflowButton;
    QLabel *label_8;
    QCustomPlot *airstreamPlot;

    void setupUi(QWidget *Modbus)
    {
        if (Modbus->objectName().isEmpty())
            Modbus->setObjectName("Modbus");
        Modbus->resize(1199, 645);
        recvTextEdit = new QTextEdit(Modbus);
        recvTextEdit->setObjectName("recvTextEdit");
        recvTextEdit->setGeometry(QRect(440, 90, 421, 251));
        label_7 = new QLabel(Modbus);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(430, 50, 121, 31));
        clearRecvPushButton = new QPushButton(Modbus);
        clearRecvPushButton->setObjectName("clearRecvPushButton");
        clearRecvPushButton->setGeometry(QRect(890, 260, 93, 28));
        startflowButton = new QPushButton(Modbus);
        startflowButton->setObjectName("startflowButton");
        startflowButton->setGeometry(QRect(890, 130, 93, 28));
        textEdit = new QTextEdit(Modbus);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(310, 70, 106, 31));
        textEdit_2 = new QTextEdit(Modbus);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(310, 120, 106, 31));
        textEdit_3 = new QTextEdit(Modbus);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(310, 170, 106, 31));
        textEdit_4 = new QTextEdit(Modbus);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(310, 220, 106, 31));
        textEdit_5 = new QTextEdit(Modbus);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(310, 260, 106, 31));
        label = new QLabel(Modbus);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 80, 45, 17));
        label_2 = new QLabel(Modbus);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 130, 45, 17));
        label_3 = new QLabel(Modbus);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 180, 45, 17));
        label_4 = new QLabel(Modbus);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 230, 45, 17));
        label_5 = new QLabel(Modbus);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 270, 45, 17));
        stopflowButton = new QPushButton(Modbus);
        stopflowButton->setObjectName("stopflowButton");
        stopflowButton->setGeometry(QRect(890, 190, 93, 28));
        label_8 = new QLabel(Modbus);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(370, 380, 39, 181));
        airstreamPlot = new QCustomPlot(Modbus);
        airstreamPlot->setObjectName("airstreamPlot");
        airstreamPlot->setGeometry(QRect(430, 380, 499, 181));

        retranslateUi(Modbus);

        QMetaObject::connectSlotsByName(Modbus);
    } // setupUi

    void retranslateUi(QWidget *Modbus)
    {
        Modbus->setWindowTitle(QCoreApplication::translate("Modbus", "Widget", nullptr));
        label_7->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\260\224\344\275\223\346\265\201\351\207\217</span></p></body></html>", nullptr));
        clearRecvPushButton->setText(QCoreApplication::translate("Modbus", "\346\270\205\347\251\272\346\230\276\347\244\272", nullptr));
        startflowButton->setText(QCoreApplication::translate("Modbus", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Modbus", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">COM2</p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("Modbus", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">9600</p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("Modbus", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">8</p></body></html>", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("Modbus", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\227\240</p></body></html>", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("Modbus", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\">\344\270\262\345\217\243</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\">\346\263\242\347\211\271\347\216\207</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\">\346\225\260\346\215\256\344\275\215</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\">\346\240\241\351\252\214\344\275\215</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\">\345\201\234\346\255\242\344\275\215</p></body></html>", nullptr));
        stopflowButton->setText(QCoreApplication::translate("Modbus", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        label_8->setText(QCoreApplication::translate("Modbus", "<html><head/><body><p align=\"center\">\346\260\224\344\275\223</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modbus: public Ui_Modbus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUS_H
