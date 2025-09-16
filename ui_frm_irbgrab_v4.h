/********************************************************************************
** Form generated from reading UI file 'frm_irbgrab_v4.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_IRBGRAB_V4_H
#define UI_FRM_IRBGRAB_V4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_irbgrab
{
public:
    QWidget *centralwidget;
    QComboBox *cmbDevices;
    QLabel *lblTest;
    QLabel *lblImage;
    QSpinBox *spnTimerInterval;
    QPushButton *btnRemote;
    QPushButton *btnSetParam;
    QPushButton *btnGetParam;
    QLabel *lblParamWhat;
    QLabel *lblParamDataType;
    QLabel *lblParamValue1;
    QLabel *lblParamValue2;
    QLabel *lblParamIndex1;
    QLabel *lblParamIndex2;
    QLineEdit *edtParamValue1;
    QLineEdit *edtParamIndex1;
    QLineEdit *edtParamValue2;
    QLineEdit *edtParamIndex2;
    QLineEdit *edtParamWhat;
    QComboBox *cmbParamType;
    QComboBox *cbConnectionString;
    QPushButton *btnSearchDevices;
    QCheckBox *cbxLoadLib;
    QComboBox *cbDeviceSlot;
    QTextBrowser *textBrowser;
    QCheckBox *cbxDeviceAssign;
    QCheckBox *cbxConnect;
    QGroupBox *gbxStreamControl;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QCheckBox *cbxStream0;
    QCheckBox *cbxStream1;
    QCheckBox *cbxStream2;
    QSpinBox *spnStreamIndex;
    QWidget *widget;
    QLabel *lblSubStreamCaption;
    QLabel *lblSubStreamMax;
    QSpinBox *spnSubStreamIndex;
    QGroupBox *gbxCalibration;
    QComboBox *cbCalibrations;
    QComboBox *cbOutputChannelOptions;
    QComboBox *cbOutputChannel;
    QComboBox *cbTriggerMark;
    QComboBox *cbTriggerSync;
    QPushButton *btnNUCExecute1Point;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *irbgrab)
    {
        if (irbgrab->objectName().isEmpty())
            irbgrab->setObjectName("irbgrab");
        irbgrab->resize(1265, 934);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(9);
        irbgrab->setFont(font);
        irbgrab->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(irbgrab);
        centralwidget->setObjectName("centralwidget");
        cmbDevices = new QComboBox(centralwidget);
        cmbDevices->setObjectName("cmbDevices");
        cmbDevices->setGeometry(QRect(10, 70, 209, 24));
        lblTest = new QLabel(centralwidget);
        lblTest->setObjectName("lblTest");
        lblTest->setGeometry(QRect(10, 870, 81, 16));
        lblImage = new QLabel(centralwidget);
        lblImage->setObjectName("lblImage");
        lblImage->setGeometry(QRect(240, 10, 1001, 661));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblImage->sizePolicy().hasHeightForWidth());
        lblImage->setSizePolicy(sizePolicy);
        lblImage->setStyleSheet(QString::fromUtf8("color: black; border: 1px solid black"));
        lblImage->setScaledContents(true);
        lblImage->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spnTimerInterval = new QSpinBox(centralwidget);
        spnTimerInterval->setObjectName("spnTimerInterval");
        spnTimerInterval->setGeometry(QRect(94, 867, 61, 22));
        spnTimerInterval->setMinimum(1);
        spnTimerInterval->setMaximum(1000);
        spnTimerInterval->setValue(100);
        btnRemote = new QPushButton(centralwidget);
        btnRemote->setObjectName("btnRemote");
        btnRemote->setGeometry(QRect(10, 620, 209, 24));
        btnRemote->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        btnRemote->setFlat(false);
        btnSetParam = new QPushButton(centralwidget);
        btnSetParam->setObjectName("btnSetParam");
        btnSetParam->setGeometry(QRect(116, 586, 101, 23));
        btnSetParam->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        btnSetParam->setFlat(false);
        btnGetParam = new QPushButton(centralwidget);
        btnGetParam->setObjectName("btnGetParam");
        btnGetParam->setGeometry(QRect(16, 586, 101, 23));
        btnGetParam->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        btnGetParam->setFlat(false);
        lblParamWhat = new QLabel(centralwidget);
        lblParamWhat->setObjectName("lblParamWhat");
        lblParamWhat->setGeometry(QRect(16, 446, 81, 16));
        lblParamDataType = new QLabel(centralwidget);
        lblParamDataType->setObjectName("lblParamDataType");
        lblParamDataType->setGeometry(QRect(16, 466, 81, 16));
        lblParamValue1 = new QLabel(centralwidget);
        lblParamValue1->setObjectName("lblParamValue1");
        lblParamValue1->setGeometry(QRect(16, 486, 81, 16));
        lblParamValue2 = new QLabel(centralwidget);
        lblParamValue2->setObjectName("lblParamValue2");
        lblParamValue2->setGeometry(QRect(16, 526, 81, 16));
        lblParamIndex1 = new QLabel(centralwidget);
        lblParamIndex1->setObjectName("lblParamIndex1");
        lblParamIndex1->setGeometry(QRect(16, 506, 81, 16));
        lblParamIndex2 = new QLabel(centralwidget);
        lblParamIndex2->setObjectName("lblParamIndex2");
        lblParamIndex2->setGeometry(QRect(16, 546, 81, 16));
        edtParamValue1 = new QLineEdit(centralwidget);
        edtParamValue1->setObjectName("edtParamValue1");
        edtParamValue1->setGeometry(QRect(106, 488, 113, 20));
        edtParamIndex1 = new QLineEdit(centralwidget);
        edtParamIndex1->setObjectName("edtParamIndex1");
        edtParamIndex1->setGeometry(QRect(106, 508, 113, 20));
        edtParamValue2 = new QLineEdit(centralwidget);
        edtParamValue2->setObjectName("edtParamValue2");
        edtParamValue2->setGeometry(QRect(106, 528, 113, 20));
        edtParamIndex2 = new QLineEdit(centralwidget);
        edtParamIndex2->setObjectName("edtParamIndex2");
        edtParamIndex2->setGeometry(QRect(106, 548, 113, 20));
        edtParamWhat = new QLineEdit(centralwidget);
        edtParamWhat->setObjectName("edtParamWhat");
        edtParamWhat->setGeometry(QRect(106, 446, 113, 20));
        cmbParamType = new QComboBox(centralwidget);
        cmbParamType->setObjectName("cmbParamType");
        cmbParamType->setGeometry(QRect(106, 466, 113, 22));
        cmbParamType->setStyleSheet(QString::fromUtf8("QComboBox QAbstractItemView { min-width: 200px;}"));
        cmbParamType->setMinimumContentsLength(0);
        cmbParamType->setModelColumn(0);
        cbConnectionString = new QComboBox(centralwidget);
        cbConnectionString->setObjectName("cbConnectionString");
        cbConnectionString->setGeometry(QRect(10, 160, 209, 24));
        cbConnectionString->setEditable(true);
        btnSearchDevices = new QPushButton(centralwidget);
        btnSearchDevices->setObjectName("btnSearchDevices");
        btnSearchDevices->setGeometry(QRect(10, 130, 209, 25));
        cbxLoadLib = new QCheckBox(centralwidget);
        cbxLoadLib->setObjectName("cbxLoadLib");
        cbxLoadLib->setGeometry(QRect(10, 10, 201, 22));
        cbDeviceSlot = new QComboBox(centralwidget);
        cbDeviceSlot->setObjectName("cbDeviceSlot");
        cbDeviceSlot->setGeometry(QRect(10, 40, 211, 24));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(240, 680, 1001, 192));
        cbxDeviceAssign = new QCheckBox(centralwidget);
        cbxDeviceAssign->setObjectName("cbxDeviceAssign");
        cbxDeviceAssign->setGeometry(QRect(20, 100, 191, 22));
        cbxConnect = new QCheckBox(centralwidget);
        cbxConnect->setObjectName("cbxConnect");
        cbxConnect->setGeometry(QRect(20, 190, 171, 22));
        gbxStreamControl = new QGroupBox(centralwidget);
        gbxStreamControl->setObjectName("gbxStreamControl");
        gbxStreamControl->setGeometry(QRect(10, 249, 211, 171));
        scrollArea = new QScrollArea(gbxStreamControl);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 30, 201, 101));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 99));
        cbxStream0 = new QCheckBox(scrollAreaWidgetContents);
        cbxStream0->setObjectName("cbxStream0");
        cbxStream0->setGeometry(QRect(10, 0, 191, 22));
        cbxStream1 = new QCheckBox(scrollAreaWidgetContents);
        cbxStream1->setObjectName("cbxStream1");
        cbxStream1->setEnabled(true);
        cbxStream1->setGeometry(QRect(10, 20, 181, 22));
        cbxStream2 = new QCheckBox(scrollAreaWidgetContents);
        cbxStream2->setObjectName("cbxStream2");
        cbxStream2->setGeometry(QRect(10, 40, 181, 22));
        spnStreamIndex = new QSpinBox(scrollAreaWidgetContents);
        spnStreamIndex->setObjectName("spnStreamIndex");
        spnStreamIndex->setGeometry(QRect(10, 70, 51, 25));
        spnStreamIndex->setMinimum(-1);
        spnStreamIndex->setMaximum(0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 90, 201, 51));
        lblSubStreamCaption = new QLabel(widget);
        lblSubStreamCaption->setObjectName("lblSubStreamCaption");
        lblSubStreamCaption->setGeometry(QRect(0, 20, 71, 16));
        lblSubStreamMax = new QLabel(widget);
        lblSubStreamMax->setObjectName("lblSubStreamMax");
        lblSubStreamMax->setGeometry(QRect(140, 20, 49, 16));
        spnSubStreamIndex = new QSpinBox(widget);
        spnSubStreamIndex->setObjectName("spnSubStreamIndex");
        spnSubStreamIndex->setGeometry(QRect(80, 20, 51, 25));
        spnSubStreamIndex->setMinimum(-1);
        spnSubStreamIndex->setMaximum(0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        gbxCalibration = new QGroupBox(centralwidget);
        gbxCalibration->setObjectName("gbxCalibration");
        gbxCalibration->setGeometry(QRect(10, 650, 201, 51));
        cbCalibrations = new QComboBox(gbxCalibration);
        cbCalibrations->setObjectName("cbCalibrations");
        cbCalibrations->setGeometry(QRect(11, 20, 181, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbCalibrations->sizePolicy().hasHeightForWidth());
        cbCalibrations->setSizePolicy(sizePolicy1);
        cbOutputChannelOptions = new QComboBox(centralwidget);
        cbOutputChannelOptions->setObjectName("cbOutputChannelOptions");
        cbOutputChannelOptions->setGeometry(QRect(10, 740, 171, 24));
        cbOutputChannel = new QComboBox(centralwidget);
        cbOutputChannel->setObjectName("cbOutputChannel");
        cbOutputChannel->setGeometry(QRect(10, 710, 171, 24));
        cbTriggerMark = new QComboBox(centralwidget);
        cbTriggerMark->setObjectName("cbTriggerMark");
        cbTriggerMark->setGeometry(QRect(10, 770, 171, 24));
        cbTriggerSync = new QComboBox(centralwidget);
        cbTriggerSync->setObjectName("cbTriggerSync");
        cbTriggerSync->setGeometry(QRect(10, 800, 171, 24));
        btnNUCExecute1Point = new QPushButton(centralwidget);
        btnNUCExecute1Point->setObjectName("btnNUCExecute1Point");
        btnNUCExecute1Point->setGeometry(QRect(20, 830, 161, 24));
        irbgrab->setCentralWidget(centralwidget);
        menubar = new QMenuBar(irbgrab);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1265, 22));
        irbgrab->setMenuBar(menubar);
        statusbar = new QStatusBar(irbgrab);
        statusbar->setObjectName("statusbar");
        irbgrab->setStatusBar(statusbar);

        retranslateUi(irbgrab);

        btnRemote->setDefault(false);
        btnSetParam->setDefault(false);
        btnGetParam->setDefault(false);
        cmbParamType->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(irbgrab);
    } // setupUi

    void retranslateUi(QMainWindow *irbgrab)
    {
        irbgrab->setWindowTitle(QCoreApplication::translate("irbgrab", "IRBGRAB SDK v4 - Demo Qt/C++", nullptr));
        lblTest->setText(QCoreApplication::translate("irbgrab", "Timer interval", nullptr));
        lblImage->setText(QCoreApplication::translate("irbgrab", "Image", nullptr));
        spnTimerInterval->setSuffix(QCoreApplication::translate("irbgrab", "ms", nullptr));
        btnRemote->setText(QCoreApplication::translate("irbgrab", "Remote", nullptr));
        btnSetParam->setText(QCoreApplication::translate("irbgrab", "Set", nullptr));
        btnGetParam->setText(QCoreApplication::translate("irbgrab", "Get", nullptr));
        lblParamWhat->setText(QCoreApplication::translate("irbgrab", "What", nullptr));
        lblParamDataType->setText(QCoreApplication::translate("irbgrab", "DataType", nullptr));
        lblParamValue1->setText(QCoreApplication::translate("irbgrab", "Value1", nullptr));
        lblParamValue2->setText(QCoreApplication::translate("irbgrab", "Value2", nullptr));
        lblParamIndex1->setText(QCoreApplication::translate("irbgrab", "Index1", nullptr));
        lblParamIndex2->setText(QCoreApplication::translate("irbgrab", "Index2", nullptr));
        cmbParamType->setCurrentText(QString());
        btnSearchDevices->setText(QCoreApplication::translate("irbgrab", "Search Devices", nullptr));
        cbxLoadLib->setText(QCoreApplication::translate("irbgrab", "Load Library", nullptr));
        cbxDeviceAssign->setText(QCoreApplication::translate("irbgrab", "Create Device", nullptr));
        cbxConnect->setText(QCoreApplication::translate("irbgrab", "Connect", nullptr));
        gbxStreamControl->setTitle(QCoreApplication::translate("irbgrab", "Stream Control", nullptr));
        cbxStream0->setText(QCoreApplication::translate("irbgrab", "Stream 0", nullptr));
        cbxStream1->setText(QCoreApplication::translate("irbgrab", "Stream 1", nullptr));
        cbxStream2->setText(QCoreApplication::translate("irbgrab", "Stream 2", nullptr));
        lblSubStreamCaption->setText(QCoreApplication::translate("irbgrab", "Substream", nullptr));
        lblSubStreamMax->setText(QCoreApplication::translate("irbgrab", "| 0", nullptr));
        gbxCalibration->setTitle(QCoreApplication::translate("irbgrab", "Calibration", nullptr));
        btnNUCExecute1Point->setText(QCoreApplication::translate("irbgrab", "NUC 1 Point", nullptr));
    } // retranslateUi

};

namespace Ui {
    class irbgrab: public Ui_irbgrab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_IRBGRAB_V4_H
