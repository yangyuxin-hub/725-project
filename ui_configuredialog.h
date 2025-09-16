/********************************************************************************
** Form generated from reading UI file 'configuredialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREDIALOG_H
#define UI_CONFIGUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfigureDialog
{
public:
    QComboBox *cmbDevice;
    QGroupBox *groupBox;
    QLabel *lblChannelCount;
    QLineEdit *edtClockRatePerChan;
    QComboBox *cmbValueRange;
    QLabel *lblValueRange;
    QLabel *lblClockRate;
    QComboBox *cmbChannelStart;
    QLabel *lblChannelStart;
    QLabel *lblRateUnit;
    QComboBox *cmbChannelCount;
    QLabel *lblSectionLength;
    QLineEdit *edtSectionLength;
    QPushButton *btnCancel;
    QLabel *lblDevice;
    QPushButton *btnOK;
    QLabel *lblProfilePath;
    QLineEdit *txtProfilePath;
    QPushButton *btnBrowse;

    void setupUi(QDialog *ConfigureDialog)
    {
        if (ConfigureDialog->objectName().isEmpty())
            ConfigureDialog->setObjectName("ConfigureDialog");
        ConfigureDialog->resize(340, 325);
        cmbDevice = new QComboBox(ConfigureDialog);
        cmbDevice->setObjectName("cmbDevice");
        cmbDevice->setGeometry(QRect(80, 20, 181, 20));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbDevice->sizePolicy().hasHeightForWidth());
        cmbDevice->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(ConfigureDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 100, 301, 181));
        lblChannelCount = new QLabel(groupBox);
        lblChannelCount->setObjectName("lblChannelCount");
        lblChannelCount->setGeometry(QRect(17, 56, 91, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblChannelCount->sizePolicy().hasHeightForWidth());
        lblChannelCount->setSizePolicy(sizePolicy1);
        edtClockRatePerChan = new QLineEdit(groupBox);
        edtClockRatePerChan->setObjectName("edtClockRatePerChan");
        edtClockRatePerChan->setGeometry(QRect(110, 120, 161, 20));
        edtClockRatePerChan->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cmbValueRange = new QComboBox(groupBox);
        cmbValueRange->setObjectName("cmbValueRange");
        cmbValueRange->setGeometry(QRect(110, 90, 161, 20));
        sizePolicy.setHeightForWidth(cmbValueRange->sizePolicy().hasHeightForWidth());
        cmbValueRange->setSizePolicy(sizePolicy);
        lblValueRange = new QLabel(groupBox);
        lblValueRange->setObjectName("lblValueRange");
        lblValueRange->setGeometry(QRect(17, 88, 71, 21));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblValueRange->sizePolicy().hasHeightForWidth());
        lblValueRange->setSizePolicy(sizePolicy2);
        lblClockRate = new QLabel(groupBox);
        lblClockRate->setObjectName("lblClockRate");
        lblClockRate->setGeometry(QRect(17, 120, 61, 21));
        sizePolicy2.setHeightForWidth(lblClockRate->sizePolicy().hasHeightForWidth());
        lblClockRate->setSizePolicy(sizePolicy2);
        cmbChannelStart = new QComboBox(groupBox);
        cmbChannelStart->setObjectName("cmbChannelStart");
        cmbChannelStart->setGeometry(QRect(110, 30, 161, 20));
        sizePolicy.setHeightForWidth(cmbChannelStart->sizePolicy().hasHeightForWidth());
        cmbChannelStart->setSizePolicy(sizePolicy);
        lblChannelStart = new QLabel(groupBox);
        lblChannelStart->setObjectName("lblChannelStart");
        lblChannelStart->setGeometry(QRect(17, 26, 71, 21));
        lblRateUnit = new QLabel(groupBox);
        lblRateUnit->setObjectName("lblRateUnit");
        lblRateUnit->setGeometry(QRect(280, 121, 21, 20));
        sizePolicy2.setHeightForWidth(lblRateUnit->sizePolicy().hasHeightForWidth());
        lblRateUnit->setSizePolicy(sizePolicy2);
        cmbChannelCount = new QComboBox(groupBox);
        cmbChannelCount->setObjectName("cmbChannelCount");
        cmbChannelCount->setGeometry(QRect(110, 60, 161, 20));
        sizePolicy.setHeightForWidth(cmbChannelCount->sizePolicy().hasHeightForWidth());
        cmbChannelCount->setSizePolicy(sizePolicy);
        lblSectionLength = new QLabel(groupBox);
        lblSectionLength->setObjectName("lblSectionLength");
        lblSectionLength->setGeometry(QRect(10, 150, 91, 21));
        sizePolicy2.setHeightForWidth(lblSectionLength->sizePolicy().hasHeightForWidth());
        lblSectionLength->setSizePolicy(sizePolicy2);
        edtSectionLength = new QLineEdit(groupBox);
        edtSectionLength->setObjectName("edtSectionLength");
        edtSectionLength->setGeometry(QRect(110, 150, 161, 21));
        btnCancel = new QPushButton(ConfigureDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(230, 290, 75, 23));
        btnCancel->setAutoDefault(false);
        lblDevice = new QLabel(ConfigureDialog);
        lblDevice->setObjectName("lblDevice");
        lblDevice->setGeometry(QRect(30, 20, 41, 16));
        sizePolicy2.setHeightForWidth(lblDevice->sizePolicy().hasHeightForWidth());
        lblDevice->setSizePolicy(sizePolicy2);
        btnOK = new QPushButton(ConfigureDialog);
        btnOK->setObjectName("btnOK");
        btnOK->setGeometry(QRect(140, 290, 75, 23));
        lblProfilePath = new QLabel(ConfigureDialog);
        lblProfilePath->setObjectName("lblProfilePath");
        lblProfilePath->setGeometry(QRect(30, 60, 41, 21));
        sizePolicy2.setHeightForWidth(lblProfilePath->sizePolicy().hasHeightForWidth());
        lblProfilePath->setSizePolicy(sizePolicy2);
        txtProfilePath = new QLineEdit(ConfigureDialog);
        txtProfilePath->setObjectName("txtProfilePath");
        txtProfilePath->setGeometry(QRect(80, 60, 181, 21));
        btnBrowse = new QPushButton(ConfigureDialog);
        btnBrowse->setObjectName("btnBrowse");
        btnBrowse->setGeometry(QRect(270, 60, 51, 21));
#if QT_CONFIG(shortcut)
        lblChannelCount->setBuddy(cmbChannelCount);
        lblValueRange->setBuddy(cmbValueRange);
        lblClockRate->setBuddy(cmbValueRange);
        lblChannelStart->setBuddy(cmbChannelStart);
        lblRateUnit->setBuddy(cmbValueRange);
        lblSectionLength->setBuddy(cmbValueRange);
        lblDevice->setBuddy(cmbDevice);
        lblProfilePath->setBuddy(cmbDevice);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(cmbDevice, cmbChannelStart);
        QWidget::setTabOrder(cmbChannelStart, cmbChannelCount);
        QWidget::setTabOrder(cmbChannelCount, cmbValueRange);
        QWidget::setTabOrder(cmbValueRange, edtClockRatePerChan);
        QWidget::setTabOrder(edtClockRatePerChan, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(ConfigureDialog);

        QMetaObject::connectSlotsByName(ConfigureDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigureDialog)
    {
        ConfigureDialog->setWindowTitle(QCoreApplication::translate("ConfigureDialog", "Streaming AI - Configuration", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ConfigureDialog", "Streaming AI settings", nullptr));
        lblChannelCount->setText(QCoreApplication::translate("ConfigureDialog", "Channel count:", nullptr));
        edtClockRatePerChan->setText(QCoreApplication::translate("ConfigureDialog", "1000", nullptr));
        lblValueRange->setText(QCoreApplication::translate("ConfigureDialog", "Value range:", nullptr));
        lblClockRate->setText(QCoreApplication::translate("ConfigureDialog", "Clock rate:", nullptr));
        lblChannelStart->setText(QCoreApplication::translate("ConfigureDialog", "Channel start:", nullptr));
        lblRateUnit->setText(QCoreApplication::translate("ConfigureDialog", "Hz", nullptr));
        lblSectionLength->setText(QCoreApplication::translate("ConfigureDialog", "Section Length:", nullptr));
        edtSectionLength->setText(QCoreApplication::translate("ConfigureDialog", "1024", nullptr));
        btnCancel->setText(QCoreApplication::translate("ConfigureDialog", "Cancel", nullptr));
        lblDevice->setText(QCoreApplication::translate("ConfigureDialog", "Device:", nullptr));
        btnOK->setText(QCoreApplication::translate("ConfigureDialog", "OK", nullptr));
        lblProfilePath->setText(QCoreApplication::translate("ConfigureDialog", "Profile:", nullptr));
        btnBrowse->setText(QCoreApplication::translate("ConfigureDialog", "Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigureDialog: public Ui_ConfigureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREDIALOG_H
