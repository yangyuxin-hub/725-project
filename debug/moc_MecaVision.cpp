/****************************************************************************
** Meta object code from reading C++ file 'MecaVision.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MecaVision.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MecaVision.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MecaVisionE_t {};
} // unnamed namespace

template <> constexpr inline auto MecaVision::qt_create_metaobjectdata<qt_meta_tag_ZN10MecaVisionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MecaVision",
        "on_radioButton_trigger_hardware_clicked",
        "",
        "checked",
        "on_radioButton_software_trigger_clicked",
        "on_radioButton_collect_clicked",
        "on_flashlight_l_clicked",
        "on_flashlight_h_clicked",
        "on_flashlight_manual_clicked",
        "on_flashlight_auto_clicked",
        "on_lineEdit_exposure_time_returnPressed",
        "on_radioButton_raw_clicked",
        "on_radioButton_bmp_clicked",
        "on_pushButton_snap_catch_released",
        "on_pushButton_snap_path_released",
        "on_pushButton_para_load_released",
        "on_pushButton_para_save_released",
        "on_pushButton_para_acquiesce_released",
        "on_radioButton_D_clicked",
        "on_radioButton_C_clicked",
        "on_radioButton_B_clicked",
        "on_horizontalSlider_isp_acutance_valueChanged",
        "value",
        "on_checkBox_isp_v_clicked",
        "on_checkBox_isp_h_clicked",
        "on_contrast_horizontalSlider_valueChanged",
        "on_gamma_horizontalSlider_valueChanged",
        "on_horizontalSlider_saturation_valueChanged",
        "on_horizontalSlider_gain_b_valueChanged",
        "on_horizontalSlider_gain_g_valueChanged",
        "on_horizontalSlider_gain_r_valueChanged",
        "on_horizontalSlider_exposure_time_valueChanged",
        "on_horizontalSlider_gain_valueChanged",
        "on_AWB_once_button_released",
        "on_res_combobox_activated",
        "index",
        "Image_process",
        "img",
        "camera_statues",
        "on_radioButton_A_clicked",
        "on_exposure_mode_manual_clicked",
        "on_exposure_mode_auto_clicked",
        "on_radioButton_60HZ_clicked",
        "on_radioButton_50HZ_clicked",
        "on_software_trigger_once_button_clicked",
        "on_flicker_checkBox_clicked",
        "on_AE_horizontalSlider_valueChanged",
        "radioChange"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_radioButton_trigger_hardware_clicked'
        QtMocHelpers::SlotData<void(bool)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_radioButton_software_trigger_clicked'
        QtMocHelpers::SlotData<void(bool)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_radioButton_collect_clicked'
        QtMocHelpers::SlotData<void(bool)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_flashlight_l_clicked'
        QtMocHelpers::SlotData<void(bool)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_flashlight_h_clicked'
        QtMocHelpers::SlotData<void(bool)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_flashlight_manual_clicked'
        QtMocHelpers::SlotData<void(bool)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_flashlight_auto_clicked'
        QtMocHelpers::SlotData<void(bool)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_lineEdit_exposure_time_returnPressed'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButton_raw_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButton_bmp_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_snap_catch_released'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_snap_path_released'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_para_load_released'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_para_save_released'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_para_acquiesce_released'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButton_D_clicked'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_radioButton_C_clicked'
        QtMocHelpers::SlotData<void(bool)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_radioButton_B_clicked'
        QtMocHelpers::SlotData<void(bool)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_horizontalSlider_isp_acutance_valueChanged'
        QtMocHelpers::SlotData<void(int)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_checkBox_isp_v_clicked'
        QtMocHelpers::SlotData<void(bool)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_checkBox_isp_h_clicked'
        QtMocHelpers::SlotData<void(bool)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_contrast_horizontalSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_gamma_horizontalSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_horizontalSlider_saturation_valueChanged'
        QtMocHelpers::SlotData<void(int)>(27, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_horizontalSlider_gain_b_valueChanged'
        QtMocHelpers::SlotData<void(int)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_horizontalSlider_gain_g_valueChanged'
        QtMocHelpers::SlotData<void(int)>(29, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_horizontalSlider_gain_r_valueChanged'
        QtMocHelpers::SlotData<void(int)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_horizontalSlider_exposure_time_valueChanged'
        QtMocHelpers::SlotData<void(int)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_horizontalSlider_gain_valueChanged'
        QtMocHelpers::SlotData<void(int)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'on_AWB_once_button_released'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_res_combobox_activated'
        QtMocHelpers::SlotData<void(int)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 35 },
        }}),
        // Slot 'Image_process'
        QtMocHelpers::SlotData<void(QImage)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QImage, 37 },
        }}),
        // Slot 'camera_statues'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButton_A_clicked'
        QtMocHelpers::SlotData<void(bool)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_exposure_mode_manual_clicked'
        QtMocHelpers::SlotData<void(bool)>(40, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_exposure_mode_auto_clicked'
        QtMocHelpers::SlotData<void(bool)>(41, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_radioButton_60HZ_clicked'
        QtMocHelpers::SlotData<void(bool)>(42, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_radioButton_50HZ_clicked'
        QtMocHelpers::SlotData<void(bool)>(43, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_software_trigger_once_button_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_flicker_checkBox_clicked'
        QtMocHelpers::SlotData<void(bool)>(45, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_AE_horizontalSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(46, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'radioChange'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MecaVision, qt_meta_tag_ZN10MecaVisionE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MecaVision::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MecaVisionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MecaVisionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MecaVisionE_t>.metaTypes,
    nullptr
} };

void MecaVision::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MecaVision *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_radioButton_trigger_hardware_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_radioButton_software_trigger_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_radioButton_collect_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_flashlight_l_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_flashlight_h_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_flashlight_manual_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_flashlight_auto_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_lineEdit_exposure_time_returnPressed(); break;
        case 8: _t->on_radioButton_raw_clicked(); break;
        case 9: _t->on_radioButton_bmp_clicked(); break;
        case 10: _t->on_pushButton_snap_catch_released(); break;
        case 11: _t->on_pushButton_snap_path_released(); break;
        case 12: _t->on_pushButton_para_load_released(); break;
        case 13: _t->on_pushButton_para_save_released(); break;
        case 14: _t->on_pushButton_para_acquiesce_released(); break;
        case 15: _t->on_radioButton_D_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_radioButton_C_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_radioButton_B_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_horizontalSlider_isp_acutance_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_checkBox_isp_v_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_checkBox_isp_h_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_contrast_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_gamma_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_horizontalSlider_saturation_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_horizontalSlider_gain_b_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_horizontalSlider_gain_g_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->on_horizontalSlider_gain_r_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_horizontalSlider_exposure_time_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_horizontalSlider_gain_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_AWB_once_button_released(); break;
        case 30: _t->on_res_combobox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->Image_process((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 32: _t->camera_statues(); break;
        case 33: _t->on_radioButton_A_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 34: _t->on_exposure_mode_manual_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 35: _t->on_exposure_mode_auto_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->on_radioButton_60HZ_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 37: _t->on_radioButton_50HZ_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: _t->on_software_trigger_once_button_clicked(); break;
        case 39: _t->on_flicker_checkBox_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: _t->on_AE_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 41: _t->radioChange(); break;
        default: ;
        }
    }
}

const QMetaObject *MecaVision::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MecaVision::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MecaVisionE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MecaVision::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 42;
    }
    return _id;
}
QT_WARNING_POP
