QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
LIBS += -L$$PWD -lirbgrab_win64

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frm_irbgrab_v4.cpp \
    main.cpp \
    oIRBgrabDLL.cpp \
    oitsdk_objecthandler.cpp \
    oitsdk_objecthandler_irbgrabdev.cpp \
    oitsdk_objecthandler_irbgrabmem.cpp \
    oitsdk_objecthandler_mem.cpp

HEADERS += \
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
    frm_irbgrab_v4.ui

TRANSLATIONS += \
    irbgrab_v4_demo_cpp_qt.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
