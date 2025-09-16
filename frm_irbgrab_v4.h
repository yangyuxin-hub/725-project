#ifndef irbgrab_H
#define irbgrab_H

#include <QMainWindow>
#include <oIRBgrabDLL.h>
#include <QMutex>
#include "ui_frm_irbgrab_v4.h"
// #include "infraredthread.h"
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class irbgrab; }

QT_END_NAMESPACE

//without index, one value
const ushort IRBG_PARAMTYPE_Int32    = 0;
const ushort IRBG_PARAMTYPE_Int64    = 1;
const ushort IRBG_PARAMTYPE_Single   = 2;
const ushort IRBG_PARAMTYPE_Double   = 3;
const ushort IRBG_PARAMTYPE_String   = 4;

//with index, one value
const ushort IRBG_PARAMTYPE_IdxInt32   = 5;
const ushort IRBG_PARAMTYPE_IdxInt64   = 6;
const ushort IRBG_PARAMTYPE_IdxSingle  = 7;
const ushort IRBG_PARAMTYPE_IdxDouble  = 8;
const ushort IRBG_PARAMTYPE_IdxString  = 9;

//without index, two values
const ushort IRBG_PARAMTYPE_2Int32   = 10;
const ushort IRBG_PARAMTYPE_2Int64   = 11;
const ushort IRBG_PARAMTYPE_2Single  = 12;
const ushort IRBG_PARAMTYPE_2Double  = 13;
const ushort IRBG_PARAMTYPE_2String  = 14;

//with index, two values
const ushort IRBG_PARAMTYPE_2IdxString  = 15;

const ushort IRBG_PARAMTYPE_Command = 16;

class irbgrab : public QMainWindow
{
    Q_OBJECT

public:
    irbgrab(QWidget *parent = nullptr);
    ~irbgrab();

    void on_NewFrame(TITSDK_Handle aHandle, int aStreamIndex);
    void LogInfo(QString aLog);

    // 一步连接设备函数
    void ConnectDeviceOneStep(int connectionIndex = 0);

    void Device_Grab(int aStreamIndex, bool aGrabbing);
    void capture(TITSDK_Handle aMemHandle);

    Ui::irbgrab *ui;

    QPixmap infraImage;

    static irbgrab* getInstance(); // 单例模式
    static std::vector<double> infrared_features;

    QGraphicsScene *f_scene;
    typedef struct
    {
        int     InUse;
        int     TriggerCount;
        TITSDK_Handle MemHandle;
        TITSDK_UInt32 MemTypeWant;
    }TStreamInfo;

    typedef struct
    {
        TITSDK_Handle   DeviceHandle;
        int             FoundDevices;
        int             StreamCount;
        TStreamInfo     StreamInfo[16];
    }TIRBGRAB_DeviceInfo;
    TIRBGRAB_DeviceInfo FDeviceInfo[4];
    TIRBgrabLib *FIRBgrab;
    QImage FImage;

protected:

private:


    int FDeviceSelection;
    int FStreamSelection;


    QAtomicInt FAtomicMemCrit;

    int spnTimerInterval = 100;
     QTimer *tmrMain;


    static irbgrab* instance; // 单例模式

    // InfraredThread *f_thread;





    //typedef void (*TIRBgrabOnNewFrame) (HANDLE aHandle, int aStreamIndex)
signals:
    void newInfraImage(const QImage &pix);

private slots:
    void tmrMainTimeout();

    void on_spnTimerInterval_valueChanged(int arg1);
    void on_btnRemote_clicked();
    void on_cmbParamType_currentIndexChanged(int index);
    void on_btnGetParam_clicked();
    void on_btnSetParam_clicked();
    void on_btnSearchDevices_clicked();
    void on_cbxLoadLib_stateChanged(int arg1);
    void on_cbxDeviceAssign_stateChanged(int arg1);
    void on_cbxConnect_stateChanged(int arg1);
    void on_cbDeviceSlot_currentIndexChanged(int index);

    void Device_Connect();
    void Device_Disconnect();

    void DeviceState_Read(void);
    void StreamState_Read(void);
    void DeviceOutputOptions_Read(int aChannel);
    void on_cbxStream0_stateChanged(int arg1);
    void on_cbxStream1_stateChanged(int arg1);
    void on_cbxStream2_stateChanged(int arg1);
    void on_cbCalibrations_currentIndexChanged(int index);
    void on_cbOutputChannelOptions_currentIndexChanged(int index);
    void on_cbOutputChannel_currentIndexChanged(int index);
    void on_btnNUCExecute1Point_clicked();
    void on_spnStreamIndex_valueChanged(int arg1);
};
#endif // irbgrab_H
