/****************************************************************************
** Meta object code from reading C++ file 'streamingbufferedai.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../streamingbufferedai.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'streamingbufferedai.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22AI_StreamingBufferedAiE_t {};
} // unnamed namespace

template <> constexpr inline auto AI_StreamingBufferedAi::qt_create_metaobjectdata<qt_meta_tag_ZN22AI_StreamingBufferedAiE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AI_StreamingBufferedAi",
        "myMove",
        "",
        "QCustomPlot*",
        "widget",
        "QMouseEvent*",
        "e",
        "handleMouseMove",
        "event",
        "DivValueChanged",
        "value",
        "ButtonConfigureClicked",
        "ButtonStartClicked",
        "ButtonPauseClicked",
        "ButtonStopClicked",
        "on_pushButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'myMove'
        QtMocHelpers::SlotData<void(QCustomPlot *, QMouseEvent *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Slot 'handleMouseMove'
        QtMocHelpers::SlotData<void(QMouseEvent *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 8 },
        }}),
        // Slot 'DivValueChanged'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'ButtonConfigureClicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'ButtonStartClicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'ButtonPauseClicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'ButtonStopClicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AI_StreamingBufferedAi, qt_meta_tag_ZN22AI_StreamingBufferedAiE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AI_StreamingBufferedAi::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22AI_StreamingBufferedAiE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22AI_StreamingBufferedAiE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22AI_StreamingBufferedAiE_t>.metaTypes,
    nullptr
} };

void AI_StreamingBufferedAi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AI_StreamingBufferedAi *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->myMove((*reinterpret_cast< std::add_pointer_t<QCustomPlot*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[2]))); break;
        case 1: _t->handleMouseMove((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 2: _t->DivValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->ButtonConfigureClicked(); break;
        case 4: _t->ButtonStartClicked(); break;
        case 5: _t->ButtonPauseClicked(); break;
        case 6: _t->ButtonStopClicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCustomPlot* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *AI_StreamingBufferedAi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AI_StreamingBufferedAi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22AI_StreamingBufferedAiE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AI_StreamingBufferedAi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
