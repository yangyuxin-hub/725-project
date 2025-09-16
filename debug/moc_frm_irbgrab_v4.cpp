/****************************************************************************
** Meta object code from reading C++ file 'frm_irbgrab_v4.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../frm_irbgrab_v4.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frm_irbgrab_v4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7irbgrabE_t {};
} // unnamed namespace

template <> constexpr inline auto irbgrab::qt_create_metaobjectdata<qt_meta_tag_ZN7irbgrabE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "irbgrab",
        "newInfraImage",
        "",
        "pix",
        "tmrMainTimeout",
        "on_spnTimerInterval_valueChanged",
        "arg1",
        "on_btnRemote_clicked",
        "on_cmbParamType_currentIndexChanged",
        "index",
        "on_btnGetParam_clicked",
        "on_btnSetParam_clicked",
        "on_btnSearchDevices_clicked",
        "on_cbxLoadLib_stateChanged",
        "on_cbxDeviceAssign_stateChanged",
        "on_cbxConnect_stateChanged",
        "on_cbDeviceSlot_currentIndexChanged",
        "Device_Connect",
        "Device_Disconnect",
        "DeviceState_Read",
        "StreamState_Read",
        "DeviceOutputOptions_Read",
        "aChannel",
        "on_cbxStream0_stateChanged",
        "on_cbxStream1_stateChanged",
        "on_cbxStream2_stateChanged",
        "on_cbCalibrations_currentIndexChanged",
        "on_cbOutputChannelOptions_currentIndexChanged",
        "on_cbOutputChannel_currentIndexChanged",
        "on_btnNUCExecute1Point_clicked",
        "on_spnStreamIndex_valueChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'newInfraImage'
        QtMocHelpers::SignalData<void(const QImage &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QImage, 3 },
        }}),
        // Slot 'tmrMainTimeout'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_spnTimerInterval_valueChanged'
        QtMocHelpers::SlotData<void(int)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_btnRemote_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_cmbParamType_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'on_btnGetParam_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetParam_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSearchDevices_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_cbxLoadLib_stateChanged'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_cbxDeviceAssign_stateChanged'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_cbxConnect_stateChanged'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_cbDeviceSlot_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'Device_Connect'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Device_Disconnect'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'DeviceState_Read'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'StreamState_Read'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'DeviceOutputOptions_Read'
        QtMocHelpers::SlotData<void(int)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_cbxStream0_stateChanged'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_cbxStream1_stateChanged'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_cbxStream2_stateChanged'
        QtMocHelpers::SlotData<void(int)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'on_cbCalibrations_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'on_cbOutputChannelOptions_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(27, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'on_cbOutputChannel_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'on_btnNUCExecute1Point_clicked'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_spnStreamIndex_valueChanged'
        QtMocHelpers::SlotData<void(int)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<irbgrab, qt_meta_tag_ZN7irbgrabE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject irbgrab::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7irbgrabE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7irbgrabE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7irbgrabE_t>.metaTypes,
    nullptr
} };

void irbgrab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<irbgrab *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->newInfraImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->tmrMainTimeout(); break;
        case 2: _t->on_spnTimerInterval_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_btnRemote_clicked(); break;
        case 4: _t->on_cmbParamType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_btnGetParam_clicked(); break;
        case 6: _t->on_btnSetParam_clicked(); break;
        case 7: _t->on_btnSearchDevices_clicked(); break;
        case 8: _t->on_cbxLoadLib_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_cbxDeviceAssign_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_cbxConnect_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_cbDeviceSlot_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->Device_Connect(); break;
        case 13: _t->Device_Disconnect(); break;
        case 14: _t->DeviceState_Read(); break;
        case 15: _t->StreamState_Read(); break;
        case 16: _t->DeviceOutputOptions_Read((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_cbxStream0_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_cbxStream1_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_cbxStream2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_cbCalibrations_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_cbOutputChannelOptions_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_cbOutputChannel_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_btnNUCExecute1Point_clicked(); break;
        case 24: _t->on_spnStreamIndex_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (irbgrab::*)(const QImage & )>(_a, &irbgrab::newInfraImage, 0))
            return;
    }
}

const QMetaObject *irbgrab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *irbgrab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7irbgrabE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int irbgrab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void irbgrab::newInfraImage(const QImage & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
