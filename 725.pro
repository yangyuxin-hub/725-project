QT       += core gui printsupport opengl
QT       += multimedia
QT       += serialport
QT       += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

QMAKE_CXXFLAGS += -msse4.1 -mavx
QMAKE_LFLAGS += -msse4.1 -mavx

#CONFIG += console
#CONFIG += c++11
CONFIG += c++17
CONFIG -= app_bundle
INCLUDEPATH += ./include


# Python配置
PYTHON_HOME = C:/Users/Admin/miniconda3/envs/py38
INCLUDEPATH += $$PYTHON_HOME/include
INCLUDEPATH += $$PYTHON_HOME/Lib/site-packages/pybind11/include

LIBS += -L$$PYTHON_HOME/libs -lpython38


# 熔池相机
LIBS += -L$$PWD -lMVCAMSDK_X64 #-lMVCAMSDK
#LIBS += -lMVCAMSDK

# 红外测温
LIBS += -L$$PWD -lirbgrab_win64
#LIBS += -L$$PWD/DIASDAQ -lDIASDAQ #-lDIASDAQ_X32

# 光谱
LIBS += -L$$PWD/Avaspec -lavaspecx64 #-lavaspec

unix|win64: LIBS += -L$$PWD/./ -lsnap7
unix|win32: LIBS += -L$$PWD/./ -lsnap7

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MecaVision.cpp \
    Modbus.cpp \
    application.cpp \
    capturethread.cpp \
    configuredialog.cpp \
    #infraredtemp.cpp \
    main.cpp \
    menu.cpp \
    qcustomplot.cpp \
    robotspeed.cpp \
    simplegraph.cpp \
    #spectrum.cpp \
    snap7.cpp \
    spectrum.cpp \
    streamingbufferedai.cpp \
    taskthread.cpp \
    vision.cpp \
    wirespeed.cpp \
    frm_irbgrab_v4.cpp \
    oIRBgrabDLL.cpp \
    oitsdk_objecthandler.cpp \
    oitsdk_objecthandler_irbgrabdev.cpp \
    oitsdk_objecthandler_irbgrabmem.cpp \
    oitsdk_objecthandler_mem.cpp

HEADERS += \
    DIASDAQDLL.h \
    MecaVision.h \
    Modbus.h \
    Windows.h \
    _T_DIASDAQDLL.h \
    #avaspec.h \
    application.h \
    avaspec.h \
    bdaqctrl.h \
    capturethread.h \
    configuredialog.h \
    #infraredtemp.h \
    menu.h \
    qcustomplot.h \
    robotspeed.h \
    simplegraph.h \
    snap7.h \
    spectrum.h \
    streamingbufferedai.h \
    taskthread.h \
    type.h \
    vision.h \
    wirespeed.h \
    frm_irbgrab_v4.h \
    hitsdkconstants.h \
    hitsdkide.h \
    hitsdktypes.h \
    oIRBgrabDLL.h \
    oitsdk_objecthandler.h \
    oitsdk_objecthandler_irbgrabdev.h \
    oitsdk_objecthandler_irbgrabmem.h \
    oitsdk_objecthandler_mem.h

FORMS += \
    MecaVision.ui \
    Modbus.ui \
    configuredialog.ui \
    menu.ui \
    streamingbufferedai.ui \
    vision.ui \
    wirespeed.ui \
    frm_irbgrab_v4.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.





