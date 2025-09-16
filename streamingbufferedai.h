#ifndef STREAMINGBUFFEREDAI_H
#define STREAMINGBUFFEREDAI_H

#include <QWidget>
#include <QMessageBox>
#include "ui_streamingbufferedai.h"
#include "simplegraph.h"
#include "configuredialog.h"

// 对Menu类进行前向声明，以确保两个h文件中的类可以互相引用且不发生编译报错
class Menu;

class AI_StreamingBufferedAi : public QDialog
{
	Q_OBJECT
public:
    AI_StreamingBufferedAi(QDialog *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
	~AI_StreamingBufferedAi();
	void Initialize();

	void SetConfigureDialog(ConfigureDialog * dialog){configureDialog = dialog;}
	void SetConfigureParameter(ConfigureParameter value){configure = value;}

	void ConfigureDevice();
	void ConfigureGraph();
	void InitializeList();
    void SetXCord();
	void CheckError(ErrorCode errorCode);

    void cursor(QCustomPlot *widget);
    void setupGraph(QCustomPlot *widget, const QColor &color);

    static void BDAQCALL OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void * userParam);
    static void BDAQCALL OnOverRunEvent(void * sender, BfdAiEventArgs * args, void * userParam);
    static void BDAQCALL OnCacheOverflowEvent(void * sender, BfdAiEventArgs * args, void * userParam);
    static void BDAQCALL OnStoppedEvent(void * sender, BfdAiEventArgs * args, void * userParam);

private:
    Ui::AI_StreamingBufferedAiClass ui;
	SimpleGraph *graph;
	ConfigureDialog *configureDialog;
	ConfigureParameter configure;
    WaveformAiCtrl * waveformAiCtrl;
	double *scaledData;

	static const int sectionCount = 0;	
	int rawDataBufferLength;
	TimeUnit timeUnit;
    double xInc;

    QMap<QCustomPlot*, QCPItemTracer*> tracerMap;     // 游标
    QMap<QCustomPlot*, QCPItemText*> tracerLabelMap;// 游标说明

    int num = 0; // num/3为绘图的横坐标
        // TODO: 如果不使用一个依托于类对象更新的横坐标，那么用于在绘制函数中使用了do while和for循环嵌套
        // (该操作为读取采集卡数据的特性还是非法操作有待考证)，使用临时变量i/3作为横坐标会造成图像重叠的问题。

public slots:
    void myMove(QCustomPlot *widget, QMouseEvent *e);
    void handleMouseMove(QMouseEvent *event);
    //void handleReplotNeeded(QCustomPlot *plot);

signals:
    //void replotNeeded(QCustomPlot *plot);

//private slots: // 为了能够在menu.cpp中显式调用而改为公有成员
public slots:
    void DivValueChanged(int value);
    void ButtonConfigureClicked();
    void ButtonStartClicked();
    void ButtonPauseClicked();
    void ButtonStopClicked();

    void on_pushButton_clicked();

public:
    static const QString elecFilePath; // 保存文件的路径(txt)
    static const QString voltFilePath;
    static const QString soundFilePath;
    static QString elecValue; // 实时电流
    static QString voltValue; // 实时电压
    static QString soundValue; // 实时声音
    static QList<double> elecList; // 电流列表
    static QList<double> voltList; // 电压列表
    static QList<double> soundList;// 声音列表

    static std::vector<double> I_features;
    static std::vector<double> U_features;
    static std::vector<double> S_features;


};

#endif // STREAMINGBUFFEREDAI_H
