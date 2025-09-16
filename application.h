#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include "avaspec.h"

class application : public QApplication
{
    Q_OBJECT

public:
    application(int &argc, char *argv[]);
    void emitsignal(int WParam, int LParam);
    static void callback(AvsHandle *handle, int *result );
    void emitsignalConn(int WParam, int LParam);
    static void connCb(AvsHandle *handle, int connStat);
	void emitsignalDstr(int WParam, int LParam);
	static void dstrCb(AvsHandle *handle, unsigned int dstrStat);

signals:
    void DataIsHere(int WParam, int LParam);
    void ConnStatus(int WParam, int LParam);
	void DstrStatus(int WParam, int LParam);
};

#endif // APPLICATION_H
