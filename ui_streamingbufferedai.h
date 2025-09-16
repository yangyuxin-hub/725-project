/********************************************************************************
** Form generated from reading UI file 'streamingbufferedai.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMINGBUFFEREDAI_H
#define UI_STREAMINGBUFFEREDAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AI_StreamingBufferedAiClass
{
public:
    QLabel *lblDiv;
    QLabel *lblXCoordinateEnd;
    QLabel *lblXCoordinateStart;
    QPushButton *btnConfigure;
    QLabel *lblColor;
    QListWidget *listWidget;
    QLabel *lblYCoordinateMin;
    QFrame *graphFrame;
    QPushButton *btnStart;
    QLabel *lblYCoordinateMid;
    QSlider *sldDiv;
    QLabel *lblYCoordinateMax;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QCustomPlot *currentPlot;
    QLabel *lblXCoordinateEnd_2;
    QLabel *lblXCoordinateEnd_3;
    QCustomPlot *voltagePlot;
    QCustomPlot *soundPlot;
    QLabel *lblXCoordinateEnd_4;

    void setupUi(QDialog *AI_StreamingBufferedAiClass)
    {
        if (AI_StreamingBufferedAiClass->objectName().isEmpty())
            AI_StreamingBufferedAiClass->setObjectName("AI_StreamingBufferedAiClass");
        AI_StreamingBufferedAiClass->setEnabled(true);
        AI_StreamingBufferedAiClass->resize(1436, 627);
        AI_StreamingBufferedAiClass->setMinimumSize(QSize(762, 515));
        lblDiv = new QLabel(AI_StreamingBufferedAiClass);
        lblDiv->setObjectName("lblDiv");
        lblDiv->setGeometry(QRect(550, 417, 31, 16));
        lblDiv->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblXCoordinateEnd = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateEnd->setObjectName("lblXCoordinateEnd");
        lblXCoordinateEnd->setGeometry(QRect(618, 381, 90, 16));
        lblXCoordinateEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblXCoordinateStart = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateStart->setObjectName("lblXCoordinateStart");
        lblXCoordinateStart->setGeometry(QRect(50, 382, 71, 16));
        lblXCoordinateStart->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnConfigure = new QPushButton(AI_StreamingBufferedAiClass);
        btnConfigure->setObjectName("btnConfigure");
        btnConfigure->setEnabled(true);
        btnConfigure->setGeometry(QRect(270, 473, 111, 23));
        btnConfigure->setAutoDefault(false);
        lblColor = new QLabel(AI_StreamingBufferedAiClass);
        lblColor->setObjectName("lblColor");
        lblColor->setGeometry(QRect(42, 404, 61, 41));
        lblColor->setMinimumSize(QSize(41, 41));
        listWidget = new QListWidget(AI_StreamingBufferedAiClass);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(100, 400, 440, 45));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));
        lblYCoordinateMin = new QLabel(AI_StreamingBufferedAiClass);
        lblYCoordinateMin->setObjectName("lblYCoordinateMin");
        lblYCoordinateMin->setGeometry(QRect(0, 360, 46, 16));
        lblYCoordinateMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        graphFrame = new QFrame(AI_StreamingBufferedAiClass);
        graphFrame->setObjectName("graphFrame");
        graphFrame->setGeometry(QRect(49, 39, 660, 340));
        graphFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        graphFrame->setFrameShape(QFrame::StyledPanel);
        graphFrame->setFrameShadow(QFrame::Raised);
        btnStart = new QPushButton(AI_StreamingBufferedAiClass);
        btnStart->setObjectName("btnStart");
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(430, 473, 81, 23));
        btnStart->setAutoDefault(true);
        lblYCoordinateMid = new QLabel(AI_StreamingBufferedAiClass);
        lblYCoordinateMid->setObjectName("lblYCoordinateMid");
        lblYCoordinateMid->setGeometry(QRect(0, 200, 46, 16));
        lblYCoordinateMid->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sldDiv = new QSlider(AI_StreamingBufferedAiClass);
        sldDiv->setObjectName("sldDiv");
        sldDiv->setEnabled(false);
        sldDiv->setGeometry(QRect(586, 414, 121, 21));
        sldDiv->setMinimum(10);
        sldDiv->setMaximum(1000);
        sldDiv->setSingleStep(10);
        sldDiv->setValue(200);
        sldDiv->setOrientation(Qt::Horizontal);
        sldDiv->setTickPosition(QSlider::NoTicks);
        lblYCoordinateMax = new QLabel(AI_StreamingBufferedAiClass);
        lblYCoordinateMax->setObjectName("lblYCoordinateMax");
        lblYCoordinateMax->setGeometry(QRect(0, 40, 46, 20));
        lblYCoordinateMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnPause = new QPushButton(AI_StreamingBufferedAiClass);
        btnPause->setObjectName("btnPause");
        btnPause->setEnabled(false);
        btnPause->setGeometry(QRect(530, 473, 81, 23));
        btnPause->setAutoDefault(false);
        btnStop = new QPushButton(AI_StreamingBufferedAiClass);
        btnStop->setObjectName("btnStop");
        btnStop->setEnabled(false);
        btnStop->setGeometry(QRect(630, 473, 81, 23));
        btnStop->setAutoDefault(false);
        currentPlot = new QCustomPlot(AI_StreamingBufferedAiClass);
        currentPlot->setObjectName("currentPlot");
        currentPlot->setGeometry(QRect(800, 40, 611, 181));
        lblXCoordinateEnd_2 = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateEnd_2->setObjectName("lblXCoordinateEnd_2");
        lblXCoordinateEnd_2->setGeometry(QRect(710, 120, 90, 16));
        lblXCoordinateEnd_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblXCoordinateEnd_3 = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateEnd_3->setObjectName("lblXCoordinateEnd_3");
        lblXCoordinateEnd_3->setGeometry(QRect(710, 310, 90, 16));
        lblXCoordinateEnd_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        voltagePlot = new QCustomPlot(AI_StreamingBufferedAiClass);
        voltagePlot->setObjectName("voltagePlot");
        voltagePlot->setGeometry(QRect(800, 230, 611, 181));
        soundPlot = new QCustomPlot(AI_StreamingBufferedAiClass);
        soundPlot->setObjectName("soundPlot");
        soundPlot->setGeometry(QRect(800, 420, 611, 181));
        lblXCoordinateEnd_4 = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateEnd_4->setObjectName("lblXCoordinateEnd_4");
        lblXCoordinateEnd_4->setGeometry(QRect(710, 500, 90, 16));
        lblXCoordinateEnd_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        QWidget::setTabOrder(btnConfigure, btnStart);
        QWidget::setTabOrder(btnStart, btnPause);
        QWidget::setTabOrder(btnPause, btnStop);
        QWidget::setTabOrder(btnStop, sldDiv);
        QWidget::setTabOrder(sldDiv, listWidget);

        retranslateUi(AI_StreamingBufferedAiClass);

        QMetaObject::connectSlotsByName(AI_StreamingBufferedAiClass);
    } // setupUi

    void retranslateUi(QDialog *AI_StreamingBufferedAiClass)
    {
        AI_StreamingBufferedAiClass->setWindowTitle(QCoreApplication::translate("AI_StreamingBufferedAiClass", "AI_StreamingAI", nullptr));
        lblDiv->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "Div:", nullptr));
        lblXCoordinateEnd->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "10Sec", nullptr));
        lblXCoordinateStart->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "0Sec", nullptr));
        btnConfigure->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "Configure", nullptr));
        lblColor->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "Color of\n"
"channel:", nullptr));
        lblYCoordinateMin->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "-10.0V", nullptr));
        btnStart->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "Start", nullptr));
        lblYCoordinateMid->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "0", nullptr));
        lblYCoordinateMax->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "10.0V", nullptr));
        btnPause->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "Pause", nullptr));
        btnStop->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "Stop", nullptr));
        lblXCoordinateEnd_2->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "<html><head/><body><p align=\"center\">channel1</p></body></html>", nullptr));
        lblXCoordinateEnd_3->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "<html><head/><body><p align=\"center\">channel2</p></body></html>", nullptr));
        lblXCoordinateEnd_4->setText(QCoreApplication::translate("AI_StreamingBufferedAiClass", "<html><head/><body><p align=\"center\">channel3</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AI_StreamingBufferedAiClass: public Ui_AI_StreamingBufferedAiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMINGBUFFEREDAI_H
