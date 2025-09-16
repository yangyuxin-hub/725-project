#ifndef HITSDKIDE_H
#define HITSDKIDE_H

#include <qglobal.h>
#include <QObject>

#ifdef Q_OS_UNIX //QT-Creator Project for Linux

#include <dlfcn.h>
#define ITSDK_OS_UNIX

#else

#ifdef Q_OS_WIN
#define ITSDK_OS_WINDOWS
#endif


#endif



#endif // HITSDKIDE_H
