#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <qwidget.h>
#include "ui_configuredialog.h"
#include "bdaqctrl.h"

using namespace Automation::BDaq;

struct ConfigureParameter 
{
	QString deviceName;
	int channelCount;
	int channelStart;
	ValueRange valueRange;
    qint32 clockRatePerChan;
    qint32 sectionLength;
    QString profilePath;
};

class ConfigureDialog : public QDialog
{
	Q_OBJECT

public:
	ConfigureDialog(QDialog *parent = 0);
	~ConfigureDialog();
	void Initailization();
	void CheckError(ErrorCode errorCode);
	ConfigureParameter GetConfigureParameter(){return configure;}
	void RefreshConfigureParameter();

private:
	Ui::ConfigureDialog ui;
	ConfigureParameter configure;

	private slots:
		void DeviceChanged(int index);
		void ButtonOKClicked();
		void ButtonCancelClicked();
		void ButtonBrowseClicked();
};

#endif // CONFIGUREDIALOG_H
