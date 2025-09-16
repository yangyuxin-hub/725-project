#include <QtGui>
#include "application.h"
#include "avaspec.h"
//#include "qtdemo.h"

application::application(int &argc, char *argv[])
	: QApplication(argc, argv)
{
    setStyle("plastique");
#ifdef Q_OS_MAC
	setStyleSheet("QWidget{font-size:10px}");
#endif
}

void application::emitsignal(int WParam, int LParam)
{
    emit DataIsHere(WParam, LParam);
}

void application::callback(AvsHandle *handle, int *result )
{
    if (*result >= 0) {
    application *m = static_cast<application*>(qApp);
    // qApp is a predefined pointer to the QApplication instance
    if (m != NULL)
        m->emitsignal(*result, *handle); 
    }
}

void application::emitsignalConn(int WParam, int LParam)
{
    emit ConnStatus(WParam, LParam);
}

void application::connCb(AvsHandle *handle, int connStat)
{
    application *m = static_cast<application*>(qApp);
    // qApp is a predefined pointer to the QApplication instance
    if (m != NULL)
        m->emitsignalConn(connStat, *handle);
}

void application::emitsignalDstr(int WParam, int LParam)
{
	emit DstrStatus(WParam, LParam);
}

void application::dstrCb(AvsHandle *handle, unsigned int dstrStat)
{
	application *m = static_cast<application*>(qApp);
	// qApp is a predefined pointer to the QApplication instance
	if (m != NULL)
		m->emitsignalDstr(dstrStat, *handle);
}

