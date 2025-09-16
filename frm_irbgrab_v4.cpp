#include "frm_irbgrab_v4.h"
#include "ui_frm_irbgrab_v4.h"
#include "QMessageBox"
#include <QTimer>
#include <QDateTime>
#include <windows.h>

#include <QDir>

bool processing = false;

void __CALLCONV IRBGonNewFrame(TITSDK_Handle aContext, TITSDK_Handle aDevHandle, int aStreamIndex)
{
    if (aContext == NULL) return;
    irbgrab *mm = reinterpret_cast<irbgrab *>(aContext);
    mm->on_NewFrame(aDevHandle, aStreamIndex);
}
std::vector<double> irbgrab::infrared_features = std::vector<double>();

irbgrab* irbgrab::instance = nullptr; // 单例模式

irbgrab* irbgrab::getInstance() // 单例模式
{
    if (!instance) instance = new irbgrab();
    return instance;
}

irbgrab::irbgrab(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::irbgrab)
{
    ui->setupUi(this);

    FIRBgrab = new TIRBgrabLib();

    tmrMain = new QTimer(this);
    QTimer::singleShot(0, this, [this](){
        tmrMain->setObjectName("tmrMain");
        // tmrMain->setInterval(100);
        // connect(tmrMain, SIGNAL(timeout()), this, SLOT(tmrMainTimeout()));
        // tmrMain->setSingleShot(true);
        // tmrMain->singleShot(100, this, SLOT(tmrMainTimeout()));

        ui->lblImage->setScaledContents(true);


        ui->cmbParamType->addItem("IRBG_PARAMTYPE_Int32 = 0");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_Int64 = 1");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_Single = 2");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_Double = 3");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_String = 4");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_IdxInt32 = 5");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_IdxInt64 = 6");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_IdxSingle = 7");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_IdxDouble = 8");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_IdxString = 9");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_2Int32 = 10");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_2Int64 = 11");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_2Single = 12");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_2Double = 13");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_2String = 14");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_2IdxString = 15");
        ui->cmbParamType->addItem("IRBG_PARAMTYPE_Command = 16");
        ui->cmbParamType->setCurrentIndex(0);


        //initialize structures
        for (int ii=0;ii< int(std::size(FDeviceInfo)); ii++)
        {


            FDeviceInfo[ii].DeviceHandle = 0;
            FDeviceInfo[ii].FoundDevices = 0;
            FDeviceInfo[ii].StreamCount  = 0;

            for (int kk=0;kk<int(std::size(FDeviceInfo[ii].StreamInfo)); kk++)
            {
                FDeviceInfo[ii].StreamInfo[kk].InUse = 0;
                FDeviceInfo[ii].StreamInfo[kk].MemHandle = 0;
                FDeviceInfo[ii].StreamInfo[kk].MemTypeWant = 0;
                FDeviceInfo[ii].StreamInfo[kk].TriggerCount = 0;
            }

            ui->cbDeviceSlot->addItem("Device " + QString::number(ii));
        }
        ui->cbDeviceSlot->setCurrentIndex(0);

        FDeviceSelection = 0;

        ui->cbxStream0->setVisible(false);
        ui->cbxStream1->setVisible(false);
        ui->cbxStream2->setVisible(false);


#ifdef ITSDK_OS_WINDOWS
        ui->btnRemote->setEnabled(true);
#else
        ui->btnRemote->setEnabled(false);
#endif
    });
}

irbgrab::~irbgrab()
{

    delete ui;
    delete FIRBgrab;
    delete tmrMain;

}





void irbgrab::LogInfo(QString aLog)
{
    ui->textBrowser->moveCursor(QTextCursor::End);
    ui->textBrowser->insertPlainText(aLog + "\n");
}

void irbgrab::on_NewFrame(TITSDK_Handle aDevHandle, int aStreamIndex)
{
    TITSDK_Handle aMemHandle = 0;

    if (FIRBgrab->FObjectHandler_Dev.dev_getdata(aDevHandle, IRBG_MEMOBJ_IR_DIGITFRAME, &aMemHandle) != ITSDK_RET_OK) return;
    int ii;
    uint32_t ww, hh, datatype;

    void *pData;
    unsigned short maxDV,minDV;


    if (   (FIRBgrab->FObjectHandler_Mem.mem_GetDimension(aMemHandle, &ww, &hh, &datatype) == ITSDK_RET_OK)
        && (FIRBgrab->FObjectHandler_Mem.mem_GetDataPtr(aMemHandle, &pData, &ii) == ITSDK_RET_OK)
        && FIRBgrab->FObjectHandler_Mem.mem_GetDigitalValues(aMemHandle,&minDV,&maxDV) == ITSDK_RET_OK)
    {
        float multi = maxDV - minDV;
        if (multi > 0)  {multi = 255 / multi;}
        else            {multi = 1;}

        int32_t len = ww * hh;
        FImage = QImage(ww, hh, QImage::Format_RGB32);

        uint32_t *pixTo = (uint32_t *) FImage.bits();

        uint16_t *pSrc = (uint16_t*) pData;


        while(len > 0)
        {
            ii = ((*pSrc - minDV) * multi);
            if (ii < 0) ii = 0;
            if (ii > 255) ii = 255;
            ii = ii | (ii << 8) | (ii << 16);
            *pixTo = ii;
            pSrc++;
            pixTo++;
            len--;
        }

        // infraImage = QPixmap::fromImage(FImage);
        emit newInfraImage(FImage);
        // ui->lblImage->setPixmap(infraImage);


        // QString fileName = "./data/" +
        //                    QDateTime::fromMSecsSinceEpoch(QDateTime::currentMSecsSinceEpoch()).toString("yyyyMMdd_HHmmss_zzz") + ".png";
        // QString currentDir = QDir::currentPath();
        // qDebug() << "当前工作目录:" << currentDir;
        // qDebug()<<fileName;
        // FImage.save(fileName);
    }

    FIRBgrab->FObjectHandler_Mem.Mem_Free(&aMemHandle);
    // qDebug()<<"内存清零";
    processing = false;

}

void irbgrab::capture(TITSDK_Handle aMemHandle)
{


}

void irbgrab::on_spnTimerInterval_valueChanged(int arg1)
{
    tmrMain->setInterval(arg1);
}


void irbgrab::on_btnRemote_clicked()
{
    TITSDK_Ret ret = FIRBgrab->FObjectHandler_Dev.SetParam_Int32(FDeviceInfo[FDeviceSelection].DeviceHandle,IRBG_PARAM_RemoteWindow,0);
    QString ss = "";

    if (ret == ITSDK_RET_OK)
    {
        ss = "Remote succeed";
    }
    else
    {
        ss = "Remote failed";
    }
    LogInfo(ss);
}


void irbgrab::on_cmbParamType_currentIndexChanged(int index)
{
    switch (index)
    {
    case IRBG_PARAMTYPE_Command:
        ui->edtParamIndex1->setText("1000");  //Default value
        ui->edtParamWhat->setText(QString::number(IRBG_PARAM_SendCommand));
        ui->edtParamWhat->setEnabled(false);
        ui->lblParamValue1->setText("Command");
        ui->lblParamValue2->setText("Answer");
        ui->lblParamIndex1->setText("Timeout [ms]");
        ui->btnGetParam->setEnabled(false);
        break;

    default:
        ui->lblParamValue1->setText("Value1");
        ui->lblParamValue2->setText("Value2");
        ui->lblParamIndex1->setText("Index1");
        ui->lblParamIndex2->setText("Index2");
        ui->edtParamIndex1->setText("");  //Default value
        //ui->edWhat->setText("");
        ui->edtParamWhat->setEnabled(true);
        ui->btnGetParam->setEnabled(true);
        break;
    }

    //Visibility
    switch (index)
    {
    case IRBG_PARAMTYPE_Int32:
    case IRBG_PARAMTYPE_Int64:
    case IRBG_PARAMTYPE_Single:
    case IRBG_PARAMTYPE_Double:
    case IRBG_PARAMTYPE_String:
        ui->lblParamIndex1->setEnabled(false);
        ui->lblParamValue2->setEnabled(false);
        ui->lblParamIndex2->setEnabled(false);

        ui->edtParamIndex1->setEnabled(false);
        ui->edtParamValue2->setEnabled(false);
        ui->edtParamIndex2->setEnabled(false);
        break;

    case IRBG_PARAMTYPE_IdxInt32:
    case IRBG_PARAMTYPE_IdxInt64:
    case IRBG_PARAMTYPE_IdxSingle:
    case IRBG_PARAMTYPE_IdxDouble:
    case IRBG_PARAMTYPE_IdxString:
        ui->lblParamIndex1->setEnabled(true);
        ui->edtParamIndex1->setEnabled(true);
        ui->lblParamValue2->setEnabled(false);

        ui->edtParamValue2->setEnabled(false);
        ui->edtParamIndex2->setEnabled(false);
        ui->lblParamIndex2->setEnabled(false);
        break;

    case IRBG_PARAMTYPE_2Int32:
    case IRBG_PARAMTYPE_2Int64:
    case IRBG_PARAMTYPE_2Single:
    case IRBG_PARAMTYPE_2Double:
    case IRBG_PARAMTYPE_2String:
        ui->lblParamIndex1->setEnabled(false);
        ui->lblParamIndex2->setEnabled(false);
        ui->lblParamValue2->setEnabled(true);

        ui->edtParamIndex1->setEnabled(false);
        ui->edtParamIndex2->setEnabled(false);
        ui->edtParamValue2->setEnabled(true);
        break;

    case IRBG_PARAMTYPE_2IdxString:
        ui->lblParamIndex1->setEnabled(true);
        ui->lblParamIndex2->setEnabled(true);
        ui->lblParamValue2->setEnabled(true);

        ui->edtParamIndex1->setEnabled(true);
        ui->edtParamIndex2->setEnabled(true);
        ui->edtParamValue2->setEnabled(true);
        break;

    case IRBG_PARAMTYPE_Command:
        ui->lblParamIndex1->setEnabled(true);
        ui->lblParamIndex2->setEnabled(false);
        ui->lblParamValue2->setEnabled(true);

        ui->edtParamIndex1->setEnabled(true);
        ui->edtParamIndex2->setEnabled(false);
        ui->edtParamValue2->setEnabled(true);
        break;
    }
}


void irbgrab::on_btnGetParam_clicked()
{
    TITSDK_Ret ret = ITSDK_RET_ERR_NOT_SUPPORTED;
    int what,i32val;
    int64_t i64val;
    float SingleVal;
    double DblVal;
    int iIdx1,iIdx2;

    if (ui->edtParamIndex1->isEnabled())
    {
        iIdx1 = ui->edtParamIndex1->text().toInt();
        if (iIdx1 > 1000)
        {
            LogInfo("Invalid Index");
            return;
        }
    }
    else
    {
        iIdx1 = 0;
    }

    if (ui->edtParamIndex2->isEnabled())
    {
        iIdx2 = ui->edtParamIndex2->text().toInt();
        if (iIdx2 > 1000)
        {
            LogInfo("Invalid Index");
            return;
        }
    }
    else
    {
        iIdx2 = 0;
    }

    what = ui->edtParamWhat->text().toInt();
    if (what > 1000)
    {
        LogInfo("Invalid What");
        return;
    }

    switch (ui->cmbParamType->currentIndex())
    {
    case IRBG_PARAMTYPE_Int32://int32
        i32val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_Int32(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&i32val);
        ui->edtParamValue1->setText(QString::number(i32val));
        break;

    case IRBG_PARAMTYPE_Int64://int64;
        i64val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_Int64(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&i64val);
        ui->edtParamValue1->setText(QString::number(i64val));
        break;

    case IRBG_PARAMTYPE_Single://Single;
        SingleVal = ui->edtParamValue1->text().toFloat();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_Single(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&SingleVal);
        ui->edtParamValue1->setText(QString::number(SingleVal, 'f', 2));
        break;

    case IRBG_PARAMTYPE_Double://Double;
        DblVal = ui->edtParamValue1->text().toDouble();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_Double(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&DblVal);
        ui->edtParamValue1->setText(QString::number(DblVal, 'f', 2));
        break;

    case IRBG_PARAMTYPE_String://String;
    {
        std::string text = "";
        text.resize(1024);
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_String(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&text);
        ui->edtParamValue1->setText(QString::fromStdString(text));
        break;
    }

    case IRBG_PARAMTYPE_IdxInt32://IdxInt32
        i32val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_IdxInt32(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx1,&i32val);
        ui->edtParamValue1->setText(QString::number(i32val));
        break;

    case IRBG_PARAMTYPE_IdxInt64://IdxInt64;
        i64val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_IdxInt64(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx1,&i64val);
        ui->edtParamValue1->setText(QString::number(i64val));
        break;

    case IRBG_PARAMTYPE_IdxSingle://IdxSingle;
        SingleVal = ui->edtParamValue1->text().toFloat();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_IdxSingle(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx1,&SingleVal);
        ui->edtParamValue1->setText(QString::number(SingleVal, 'f', 2));
        break;

    case IRBG_PARAMTYPE_IdxDouble://IdxDouble;
        DblVal = ui->edtParamValue1->text().toDouble();
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_IdxDouble(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx1,&DblVal);
        ui->edtParamValue1->setText(QString::number(DblVal, 'f', 2));
        break;

    case IRBG_PARAMTYPE_IdxString://IdxString;
    {
        std::string text = "";
        text.resize(1024);
        ret = FIRBgrab->FObjectHandler_Dev.GetParam_IdxString(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx1,&text);
        ui->edtParamValue1->setText(QString::fromStdString(text));
        break;
    }

    default: ret = ITSDK_RET_ERR_NOT_SUPPORTED;
    }

    /*
        IRBG_PARAMTYPE_2Int32:
        begin
          i32val  := StrToIntDef(edtParamValue1.Text,high(i32val));
          i32val2 := StrToIntDef(edtParamValue2.Text,high(i32val2));
          ret := FIRBGrab.getParam2Int32(FDevHandle,what,i32val, i32val2);
          edtParamValue1.Text:=inttostr(i32val);
          edtParamValue2.Text:=inttostr(i32val2);
        end;
        IRBG_PARAMTYPE_2Int64:
        begin
          i64val  := StrToInt64Def(edtParamValue1.Text,high(i64val));
          i64val2 := StrToInt64Def(edtParamValue2.Text,high(i64val2));
          ret := FIRBGrab.getParam2Int64(FDevHandle,what,i64val, i64val2);
          edtParamValue1.Text:=inttostr(i64val);
          edtParamValue2.Text:=inttostr(i64val2);
        end;
        IRBG_PARAMTYPE_2Single:
        begin
          SingleVal   := StrToFloatDef(edtParamValue1.Text,MaxSingle);
          SingleVal2  := StrToFloatDef(edtParamValue2.Text,MaxSingle);
          ret := FIRBGrab.getParam2Single(FDevHandle,what,SingleVal, SingleVal2);
          edtParamValue1.Text:=FormatFloat('0.0#####',SingleVal);
          edtParamValue2.Text:=FormatFloat('0.0#####',SingleVal2);
        end;
        IRBG_PARAMTYPE_2Double:
        begin
          DblVal := StrToFloatDef(edtParamValue1.Text,MaxDouble);
          DblVal2 := StrToFloatDef(edtParamValue2.Text,MaxDouble);
          ret := FIRBGrab.getParam2Double(FDevHandle,what,DblVal, DblVal2);
          edtParamValue1.Text:=FormatFloat('0.0#####',DblVal);
          edtParamValue2.Text:=FormatFloat('0.0#####',DblVal2);
        end;
        IRBG_PARAMTYPE_2String:
        begin
          ss  := edtParamValue1.Text;
          ss2 := edtParamValue1.Text;
          ret := FIRBGrab.getParam2String(FDevHandle,what,ss, ss2);
          edtParamValue1.Text := ss;
          edtParamValue2.Text := ss2;
        end;
        IRBG_PARAMTYPE_2IdxString:
        begin
          ss    := '';
          ss2   := '';
          ret := FIRBGrab.getParam2IdxString(FDevHandle,what,iIdx1,ss,iIdx2, ss2);
          edtParamValue1.Text := ss;
          edtParamValue2.Text := ss2;
        end;
        else ret := IRBG_RET_NOT_SUPPORTED;
      end;


    */

    if (ret == ITSDK_RET_OK)
        LogInfo("GetParam succeed");
    else
        LogInfo("failed (0x" + QString::number(ret,8) + ")");
}


void irbgrab::on_btnSetParam_clicked()
{
    TITSDK_Ret ret = ITSDK_RET_UNDEF;
    int what,i32val;
    long long i64val;
    float SingleVal;
    double DblVal;
    int iIdx;

    if (ui->edtParamIndex1->isEnabled())
    {
        iIdx = ui->edtParamIndex1->text().toInt();
        if (iIdx > 1000)
        {
            LogInfo("Invalid What");
            return;
        }
    }
    else
    {
        iIdx = 0;
    }

    what = ui->edtParamWhat->text().toInt();
    if (what > 1000)
    {
        LogInfo("Invalid What");
        return;
    }

    switch (ui->cmbParamType->currentIndex())
    {
    case IRBG_PARAMTYPE_Int32://int32
        i32val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_Int32(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&i32val);
        break;

    case IRBG_PARAMTYPE_Int64://int64;
        i64val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_Int64(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&i64val);
        break;

    case IRBG_PARAMTYPE_Single://Single;
        SingleVal = ui->edtParamValue1->text().toFloat();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_Single(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&SingleVal);
        break;

    case IRBG_PARAMTYPE_Double://Double;
        DblVal = ui->edtParamValue1->text().toDouble();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_Double(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&DblVal);
        break;

    case IRBG_PARAMTYPE_String://String;
    {
        std::string text = "";
        text.resize(1024);
        text = ui->edtParamValue1->text().toUtf8();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_String(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&text);
        break;
    }
    case IRBG_PARAMTYPE_IdxInt32://IdxInt32
        i32val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_IdxInt32(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx,&i32val);
        break;

    case IRBG_PARAMTYPE_IdxInt64://IdxInt64;
        i64val = ui->edtParamValue1->text().toInt();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_IdxInt64(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx,&i64val);
        break;

    case IRBG_PARAMTYPE_IdxSingle://IdxSingle;
        SingleVal = ui->edtParamValue1->text().toFloat();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_IdxSingle(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx,&SingleVal);
        break;

    case IRBG_PARAMTYPE_IdxDouble://IdxDouble;
        DblVal = ui->edtParamValue1->text().toDouble();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_IdxDouble(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx,&DblVal);
        break;

    case IRBG_PARAMTYPE_IdxString://IdxString;
    {
        std::string text = "";
        text.resize(1024);
        text = ui->edtParamValue1->text().toUtf8();
        ret = FIRBgrab->FObjectHandler_Dev.SetParam_IdxString(FDeviceInfo[FDeviceSelection].DeviceHandle,what,iIdx,&text);
        break;
    }

        /*
        IRBG_PARAMTYPE_2Int32: //2Int32
        begin
          i32val := StrToIntDef(edtParamValue1.Text,high(i32val));
          i32val2 := StrToIntDef(edtParamValue2.Text,high(i32val2));
          if (i32val = high(i32val)) or (i32val2 = high(i32val2)) then
          begin
            lblInfo.Text:='invalid Value';
            exit;
          end;
          ret := FIRBGrab.setParam2Int32(FDevHandle, what, i32val, i32val2);
        end;
        IRBG_PARAMTYPE_2Int64: //2Int64
        begin
          i64val  := StrToIntDef(edtParamValue1.Text,high(i64val));
          i64val2 := StrToIntDef(edtParamValue2.Text,high(i64val2));
          if (i64val = high(i64val)) or (i64val2 = high(i64val2)) then
          begin
            lblInfo.Text:='invalid Value';
            exit;
          end;
          ret := FIRBGrab.setParam2Int64(FDevHandle, what, i64val, i64val2);
        end;
        IRBG_PARAMTYPE_2Single: //2Int64
        begin
          SingleVal  := StrToFloatDef(edtParamValue1.Text,MaxSingle);
          SingleVal2 := StrToFloatDef(edtParamValue2.Text,MaxSingle);
          if (SingleVal = MaxSingle) or (SingleVal2 = MaxSingle) then
          begin
            lblInfo.Text:='invalid Value';
            exit;
          end;
          ret := FIRBGrab.setParam2Single(FDevHandle, what, SingleVal, SingleVal2);
        end;
        IRBG_PARAMTYPE_2Double: //2Int64
        begin
          DblVal  := StrToFloatDef(edtParamValue1.Text,MaxDouble);
          DblVal2 := StrToFloatDef(edtParamValue2.Text,MaxDouble);
          if (DblVal = MaxDouble) or (DblVal2 = MaxDouble) then
          begin
            lblInfo.Text:='invalid Value';
            exit;
          end;
          ret := FIRBGrab.setParam2Double(FDevHandle, what, DblVal, DblVal2);
        end;
        IRBG_PARAMTYPE_2String:
        begin
          ret := FIRBGrab.setParam2String(FDevHandle, what, edtParamValue1.Text, edtParamValue2.Text);
        end;
        IRBG_PARAMTYPE_Command:
        begin
          i32val := StrToIntDef(edtParamIndex1.Text,high(i32val2));
          if (i32val = high(i32val)) then
          begin
            lblInfo.Text:='invalid Value';
            exit;
          end;
          ret := FIRBGrab.SendCommand(FDevHandle, what, edtParamValue1.Text, ss1, i32val);
          edtParamValue2.Text := ss1;
        end*/

    default: ret = ITSDK_RET_ERR_NOT_SUPPORTED;
    }

    if (ret == ITSDK_RET_OK)
        LogInfo("SetParam succeed");
    else
        LogInfo("failed (0x" + QString::number(ret,8) + ")");
}


void irbgrab::on_btnSearchDevices_clicked()
{
    ui->cbConnectionString->clear();

    int32_t iCount = 0;
    TITSDK_Ret ret = FIRBgrab->FObjectHandler_Dev.dev_search(FDeviceInfo[FDeviceSelection].DeviceHandle, &iCount);

    QString ss = "";
    if (ret == ITSDK_RET_OK)
        ss = "Search devices succeed (Count=" + QString::number(iCount) + ")";
    else
    {
        ss = "ERR: 0x" + QString::number(ret,16);
        return;
    }

    LogInfo(ss);
    std::string text = "";

    QString qs = "";

    for (int32_t ii=0; ii<iCount; ii++)
    {
        text = "";
        if (FIRBgrab->FObjectHandler_Dev.dev_Get_Device_ConnectionString(FDeviceInfo[FDeviceSelection].DeviceHandle, ii, &text))
        {qs = QString::fromStdString(text);}
        else
        {qs = QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16);}
        ui->cbConnectionString->addItem(qs);
        LogInfo(QString::number(ii) + ": " + qs);
    }

    ui->cbConnectionString->setCurrentIndex(0);
}




void irbgrab::on_cbxLoadLib_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        QString ss = "";

        ui->cmbDevices->clear();
        if (FIRBgrab->UnloadLib())
        {
            ss = "UnloadLib succed";
        }
        else
        {
            ss = "UnloadLib failed";
        }
        LogInfo(ss);
    }
    else
    {
        ui->cmbDevices->clear();
        if (!FIRBgrab->LoadLib())
        {
            LogInfo("LoadLib failed");
            return;
        }

        for (int ii = 0; ii < FIRBgrab->DeviceCount(); ii++)
        {
            ui->cmbDevices->addItem(FIRBgrab->DeviceName(ii));
        }

        LogInfo("LoadLib success");
    }
}




void irbgrab::on_cbxDeviceAssign_stateChanged(int arg1)
{
    QString ss = "";
    TITSDK_Ret ret = 0;

    FIRBgrab->FObjectHandler_Dev.dev_free(&FDeviceInfo[FDeviceSelection].DeviceHandle);

    if (ret == ITSDK_RET_OK)
        ss = "FreeDevice succeed";
    else
        ss = "ERR: 0x" + QString::number(ret,16);

    LogInfo(ss);


    if (arg1 != 0)
    {
        ret = FIRBgrab->FObjectHandler_Dev.dev_create(&FDeviceInfo[FDeviceSelection].DeviceHandle,ui->cmbDevices->currentIndex(),nullptr);

        if (ret == ITSDK_RET_OK)
        {
            ss = "Device " +QString::number(FDeviceSelection) + ": " + ui->cmbDevices->itemText(ui->cmbDevices->currentIndex());
            ui->cbDeviceSlot->setItemText(FDeviceSelection, ss);
            ss = "CreateDevice succeed";
        }
        else
        {
            ss = "Device " +QString::number(FDeviceSelection);
            ui->cbDeviceSlot->setItemText(FDeviceSelection, ss);
            ss = "ERR: 0x" + QString::number(ret,16);
        }


    }
    LogInfo(ss);
}


void irbgrab::on_cbxConnect_stateChanged(int arg1)
{
    if (arg1 == 0){
        Device_Disconnect();}
    else{
        Device_Connect();}

    return ;
}


void irbgrab::on_cbDeviceSlot_currentIndexChanged(int index)
{
    int idx = index;
    if ((idx < 0) || (idx > 3))
    {idx = 0;}

    if (idx != index)
    {ui->cbDeviceSlot->setCurrentIndex(idx);}

    FDeviceSelection = idx;

    DeviceState_Read();
    StreamState_Read();
}

void irbgrab::Device_Connect()
{
    TITSDK_Handle devHandle = FDeviceInfo[FDeviceSelection].DeviceHandle;
    TITSDK_Ret ret = 0;
    QString ss = "";

    char text[1024];
    strncpy(text, ui->cbConnectionString->currentText().toUtf8(), 1023);

    ret = FIRBgrab->FObjectHandler_Dev.dev_connect(devHandle, text);

    if (ret == ITSDK_RET_OK)
    {ss = "Connect succeed";}
    else
    {ss = "ERR: 0x" + QString::number(ret, 16);}

    qDebug()<<"devHandle="<<devHandle;
    FIRBgrab->FObjectHandler_Dev.dev_Set_Callback_OnNewFrame(devHandle, IRBGonNewFrame, this);

    LogInfo(ss+"\n");

    int libstate = 0;
    for (int ii = 0; ii< 300; ii++){

        libstate = FIRBgrab->FObjectHandler_Dev.dev_Get_libstate(devHandle);
        if (libstate < 0 ) {
            LogInfo("ERR: Get library state returns: 0x"+ QString::number(FIRBgrab->FObjectHandler_Dev.LastError(),16));
            return ;
        }
        if (libstate != 7) {break;}
        Sleep(100);
    }

    if (libstate <= 7){
        LogInfo("ERR: initialization failed: 0x"+QString::number(FIRBgrab->FObjectHandler_Dev.LastError(),16));
    }
    else{
        LogInfo("camera is ready");
    }


    LogInfo("\nVersion information");
    int ii = 0;
    while (true)
    {
        std::string verid = "";
        std::string ver = "";
        if (!FIRBgrab->FObjectHandler_Dev.dev_Get_Device_Version(devHandle, ii, &verid, &ver)) {break;}


        LogInfo(" > " + QString::fromStdString(verid) + ":\n     " + QString::fromStdString(ver));
        ii++;
    }



    int cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_Count(devHandle);
    LogInfo("\nCamera has " + QString::number(cnt) + " stream(s)...");
    for (ii = 0; ii < 3; ii++){
        bool bb = ii < cnt;

        std::string scap = "";
        int stype = 0;
        if (bb){
            FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_Info(devHandle, ii, &scap, &stype);
        }
        else{
            scap = "Stream " + std::to_string(ii);
            stype = 0;
        }

        QString qs = QString::fromStdString(scap);

        switch(ii){
        case 0:
            ui->cbxStream0->setText(qs);
            ui->cbxStream0->setVisible(bb);
            break;
        case 1:
            ui->cbxStream1->setText(qs);
            ui->cbxStream1->setVisible(bb);
            break;
        case 2:
            ui->cbxStream2->setText(qs);
            ui->cbxStream2->setVisible(bb);
            break;
        }
        if (bb){
            LogInfo(" > " + qs + " (" + QString::number(stype) +")");
        }
    }
    ui->spnStreamIndex->setMaximum(cnt- 1);
    ui->spnStreamIndex->setValue(0);
    FStreamSelection = 0;


    DeviceState_Read();
    cnt = ui->cbCalibrations->count();
    LogInfo("\nCamera has " + QString::number(cnt) + " calibration(s)...");
    for (ii = 0; ii < cnt; ii++){
        LogInfo(" > " + ui->cbCalibrations->itemText(ii));
    }


}

void irbgrab::Device_Disconnect()
{
    TITSDK_Handle devHandle = FDeviceInfo[FDeviceSelection].DeviceHandle;
    TITSDK_Ret ret = FIRBgrab->FObjectHandler_Dev.dev_disconnect(devHandle);
    QString ss = "";

    if (ret == ITSDK_RET_OK)
    {ss = "Disconnect succeed";}
    else
    {ss = "Disconnect failed " + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16);}

    LogInfo(ss);

    DeviceState_Read();
}

// bool irbgrab::Device_Grab(int aStreamIndex, bool aGrabbing)
// {

//   LogInfo("");
//   QString ss = "";
//   TITSDK_Handle devHandle = FDeviceInfo[FDeviceSelection].DeviceHandle;
//   TITSDK_Ret ret = 0;
//   ret = FIRBgrab->FObjectHandler_Dev.dev_stopgrab(devHandle, aStreamIndex);
//   if (ret == ITSDK_RET_SUCCESS){
//       ss = "Stop grab ("+QString::number(aStreamIndex) + ") succeeded";
//   }
//   else {
//       ss = "Stop grab failed " + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16);
//   }
//   LogInfo(ss);


//   if (aGrabbing){
//       //return false;
//       tmrMain->start(this->spnTimerInterval);
//       FDeviceInfo[FDeviceSelection].StreamInfo[0].MemTypeWant = IRBG_MEMOBJ_IR_DIGITFRAME;


//       ret = FIRBgrab->FObjectHandler_Dev.dev_startgrab(devHandle, aStreamIndex, false);
//       if (ret == ITSDK_RET_SUCCESS){
//           ss = "Start grab ("+QString::number(aStreamIndex) + ") succeeded";
//       }
//       else {
//           ss = "Start grab failed " + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16);
//       }
//       LogInfo(ss);
//   }
//   return true;
// }

void irbgrab::DeviceState_Read(void)
{
    //
    bool bConnected = false;


    ui->cbCalibrations->clear();
    ui->cbOutputChannel->clear();

    if (FIRBgrab == NULL) {return;}
    if (!FIRBgrab->LibLoaded()) {return;}


    TITSDK_Handle devHandle = FDeviceInfo[FDeviceSelection].DeviceHandle;
    int ii = 0;
    int idx = 0;
    int cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Calib_Count(devHandle);
    for (ii = 0; ii<cnt; ii++){
        std::string calname = "";
        if (!FIRBgrab->FObjectHandler_Dev.dev_Get_Calib_Name(devHandle, ii, &calname)){
            calname = "calib " + std::to_string(ii);
        }

        QString qs = QString::fromStdString(calname);
        ui->cbCalibrations->addItem(qs);
    }

    ii = FIRBgrab->FObjectHandler_Dev.dev_Get_Calib_Active(devHandle);
    ui->cbCalibrations->setCurrentIndex(ii);

    std::string sChnl = "";

    //read output channels
    cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Out_ChannelCount(devHandle);
    for (ii = 0; ii < cnt; ii++){
        FIRBgrab->FObjectHandler_Dev.dev_Get_Out_ChannelName(devHandle, ii, &sChnl);
        ui->cbOutputChannel->addItem(QString::fromStdString(sChnl));
    }
    ui->cbOutputChannel->setCurrentIndex(0);

    //read frame mark options
    ui->cbTriggerMark->clear();
    idx = FIRBgrab->FObjectHandler_Dev.dev_Get_Trigger_FrameMark_Option(devHandle);
    cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Trigger_FrameMark_OptionCount(devHandle);
    for (ii = 0; ii < cnt; ii++){
        FIRBgrab->FObjectHandler_Dev.dev_Get_Trigger_FrameMark_OptionName(devHandle, ii, &sChnl);
        ui->cbTriggerMark->addItem(QString::fromStdString(sChnl));
    }
    ui->cbTriggerMark->setCurrentIndex(idx);

    //read detector sync options
    ui->cbTriggerSync->clear();
    idx = FIRBgrab->FObjectHandler_Dev.dev_Get_Trigger_DetectorSync_Option(devHandle);
    cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Trigger_DetectorSync_OptionCount(devHandle);
    for (ii = 0; ii < cnt; ii++){
        FIRBgrab->FObjectHandler_Dev.dev_Get_Trigger_DetectorSync_OptionName(devHandle, ii, &sChnl);
        ui->cbTriggerSync->addItem(QString::fromStdString(sChnl));
    }
    ui->cbTriggerSync->setCurrentIndex(idx);
    /*

    FIRBGrab.ObjectHandler_Dev.dev_Get_Out_Channels(FDeviceSelection^.DeviceHandle, ii, ss);
    cbOutputChannel.Items.Text:=ss;
    cbOutputChannel.ItemIndex := 0;
**/





}

void irbgrab::StreamState_Read(void)
{
    if (!FIRBgrab->LibLoaded()){return;}

    TITSDK_Handle devHandle = FDeviceInfo[FDeviceSelection].DeviceHandle;

    int cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_Count(devHandle);
    //if (cnt < 0) {return;}

    ui->cbxStream0->setVisible(false);
    ui->cbxStream1->setVisible(false);
    ui->cbxStream2->setVisible(false);

    for (int ii = 0; ii < 3; ii++){
        bool bb = ii < cnt;
        Qt::CheckState checkstate = Qt::CheckState::Unchecked;

        std::string scap = "";
        int stype = 0;
        if (bb){
            FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_Info(devHandle, ii, &scap, &stype);

            if (FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_IsGrabbing(devHandle, ii)){
                checkstate = Qt::CheckState::Checked;
            }
        }
        else{
            scap = "Stream " + std::to_string(ii);
            stype = 0;
        }

        QString qs = QString::fromStdString(scap);

        switch(ii){
        case 0:
            ui->cbxStream0->setText(qs);
            ui->cbxStream0->setVisible(bb);
            ui->cbxStream0->setCheckState(checkstate);
            break;
        case 1:
            ui->cbxStream1->setText(qs);
            ui->cbxStream1->setVisible(bb);
            ui->cbxStream1->setCheckState(checkstate);
            break;
        case 2:
            ui->cbxStream2->setText(qs);
            ui->cbxStream2->setVisible(bb);
            ui->cbxStream2->setCheckState(checkstate);
            break;
        }
        if (bb){
            LogInfo(" > " + qs + " (" + QString::number(stype) +")");
        }
    }
}

void irbgrab::DeviceOutputOptions_Read(int aChannel)
{
    ui->cbOutputChannelOptions->clear();

    int idx = FIRBgrab->FObjectHandler_Dev.dev_Get_Out_ChannelOption(FDeviceInfo[FDeviceSelection].DeviceHandle, aChannel);

    int cnt = FIRBgrab->FObjectHandler_Dev.dev_Get_Out_ChannelOptionCount(FDeviceInfo[FDeviceSelection].DeviceHandle, aChannel);
    for (int ii=0; ii < cnt; ii++)
    {
        std::string sopt = "";
        FIRBgrab->FObjectHandler_Dev.dev_Get_Out_ChannelOptionName(FDeviceInfo[FDeviceSelection].DeviceHandle, aChannel, ii, &sopt);
        ui->cbOutputChannelOptions->addItem(QString::fromStdString(sopt));
    }

    ui->cbOutputChannelOptions->setCurrentIndex(idx);
}


void irbgrab::on_cbxStream0_stateChanged(int arg1)
{
    Device_Grab(0, arg1 != 0);
}


void irbgrab::on_cbxStream1_stateChanged(int arg1)
{
    Device_Grab(1, arg1 != 0);
}


void irbgrab::on_cbxStream2_stateChanged(int arg1)
{
    Device_Grab(2, arg1 != 0);
}


void irbgrab::on_cbCalibrations_currentIndexChanged(int index)
{
    FIRBgrab->FObjectHandler_Dev.dev_Set_Calib_Active(FDeviceInfo[FDeviceSelection].DeviceHandle, index);
}


void irbgrab::on_cbOutputChannelOptions_currentIndexChanged(int index)
{
    int idx = index;
    int chnl = ui->cbOutputChannel->currentIndex();
    FIRBgrab->FObjectHandler_Dev.dev_Set_Out_ChannelOption(FDeviceInfo[FDeviceSelection].DeviceHandle, chnl, idx);
}


void irbgrab::on_cbOutputChannel_currentIndexChanged(int index)
{
    DeviceOutputOptions_Read(index);
}


void irbgrab::on_btnNUCExecute1Point_clicked()
{
    FIRBgrab->FObjectHandler_Dev.dev_Set_NUC_Execute_1Point(FDeviceInfo[FDeviceSelection].DeviceHandle);
}



void irbgrab::on_spnStreamIndex_valueChanged(int arg1)
{
    FStreamSelection = ui->spnStreamIndex->value();
}

// 一步连接设备函数
void irbgrab::ConnectDeviceOneStep(int connectionIndex)
{
    qDebug()<<("开始一步连接设备...");

    // 步骤1: 加载库
    if (!FIRBgrab->LoadLib())
    {
        qDebug()<<("错误: 加载库失败");
        return;
    }

    qDebug()<<("✓ 库加载成功");



    // 步骤3: 创建设备 "variocamhr"
    TITSDK_Ret ret = FIRBgrab->FObjectHandler_Dev.dev_create(&FDeviceInfo[0].DeviceHandle, 1, nullptr);
    if (ret != ITSDK_RET_OK)
    {
        qDebug()<<("错误: 创建设备失败 (0x" + QString::number(ret, 16) + ")");
        return;
    }
    QString ss = "Device " +QString::number(0) + ": " + ui->cmbDevices->itemText(1);

    qDebug()<<(ss);
    qDebug()<<("✓ 设备创建成功");

    // 步骤4: 搜索设备
    int32_t deviceCount = 0;
    ret = FIRBgrab->FObjectHandler_Dev.dev_search(FDeviceInfo[0].DeviceHandle, &deviceCount);
    if (ret != ITSDK_RET_OK)
    {
        qDebug()<<("错误: 搜索设备失败 (0x" + QString::number(ret, 16) + ")");
        return;
    }
    qDebug()<<("✓ 找到 " + QString::number(deviceCount) + " 个设备");

    if (deviceCount == 0)
    {
        qDebug()<<("错误: 没有找到设备");
        return;
    }

    // 步骤5: 获取连接字符串
    std::string connectionString = "";
    if (connectionIndex < deviceCount)
    {
        if (!FIRBgrab->FObjectHandler_Dev.dev_Get_Device_ConnectionString(FDeviceInfo[0].DeviceHandle, connectionIndex, &connectionString))
        {
            qDebug()<<("错误: 获取连接字符串失败");
            return ;
        }
    }
    else
    {
        qDebug()<<("错误: 连接索引超出范围");
        return;
    }

    // 步骤6: 连接设备
    char connStr[1024];
    strncpy(connStr, QString::fromStdString(connectionString).toUtf8(), 1023);
    ret = FIRBgrab->FObjectHandler_Dev.dev_connect(FDeviceInfo[0].DeviceHandle, connStr);
    if (ret != ITSDK_RET_OK)
    {
        qDebug()<<("错误: 连接设备失败 (0x" + QString::number(ret, 16) + ")");
        return;
    }
    qDebug()<<("✓ 设备连接成功");

    // 步骤7: 设置回调函数
    qDebug()<<" FDeviceInfo[0].DeviceHandle = "<<FDeviceInfo[0].DeviceHandle;
    FIRBgrab->FObjectHandler_Dev.dev_Set_Callback_OnNewFrame(FDeviceInfo[0].DeviceHandle, IRBGonNewFrame, this);
    qDebug()<<("✓ 回调函数设置成功");

    // 步骤8: 等待库状态就绪
    int libState = 0;
    qDebug()<<("等待库状态就绪...");
    for (int i = 0; i < 300; i++)
    {
        libState = FIRBgrab->FObjectHandler_Dev.dev_Get_libstate(FDeviceInfo[0].DeviceHandle);
        if (libState < 0)
        {
            qDebug()<<("错误: 获取库状态失败 (0x" + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16) + ")");
            return ;
        }

        if (i % 10 == 0) // 每10次循环输出一次状态
        {
            qDebug()<<("等待中... 库状态: " + QString::number(libState) + " (循环 " + QString::number(i) + "/300)");
        }

        if (libState != 7)
        {
            qDebug()<<("库状态已改变，当前状态: " + QString::number(libState));
            break;
        }
        Sleep(100);
    }

    qDebug()<<("最终库状态: " + QString::number(libState));
    if (libState <= 7)
    {
        qDebug()<<("警告: 初始化可能失败 - 库状态 " + QString::number(libState) + " 小于等于7 (0x" + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16) + ")");
        qDebug()<<("继续执行后续步骤...");
    }
    else
    {
        qDebug()<<("✓ 相机就绪");
    }

    // 步骤9: 读取设备状态
    try {
        DeviceState_Read();
        StreamState_Read();
        qDebug()<<("✓ 设备状态读取完成");
    }
    catch (...) {
        qDebug()<<("警告: 设备状态读取时出现异常，但继续执行");
    }


    // 步骤11: 显示流信息
    int streamCount = 0;
    try {
        streamCount = FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_Count(FDeviceInfo[0].DeviceHandle);
        qDebug()<<("相机有 " + QString::number(streamCount) + " 个流:");
        for (int i = 0; i < 3; i++)
        {
            bool hasStream = i < streamCount;
            std::string streamCap = "";
            int streamType = 0;

            if (hasStream)
            {
                FIRBgrab->FObjectHandler_Dev.dev_Get_Stream_Info(FDeviceInfo[0].DeviceHandle, i, &streamCap, &streamType);
                qDebug()<<(" > " + QString::fromStdString(streamCap) + " (" + QString::number(streamType) + ")");
            }
        }
    }
    catch (...) {
        qDebug()<<("警告: 流信息读取时出现异常");
        streamCount = 0;
    }

    // 步骤12: 设置流选择
    try {
        ui->spnStreamIndex->setMaximum(streamCount - 1);
        ui->spnStreamIndex->setValue(0);
        FStreamSelection = 0;
    }
    catch (...) {
        qDebug()<<("警告: 流选择设置时出现异常");
        FStreamSelection = 0;
    }

    qDebug()<<("✓ 设备连接完成！");

    int what;
    float SingleVal;

    //焦距466 0.725
    what = 466;
    SingleVal = 0.725;
    ret = FIRBgrab->FObjectHandler_Dev.SetParam_Single(FDeviceInfo[FDeviceSelection].DeviceHandle,what,&SingleVal);

    if (ret == ITSDK_RET_OK)
        qDebug()<<("SetParam succeed");
    else
        qDebug()<<("failed (0x" + QString::number(ret,8) + ")");

    irbgrab::Device_Grab(0,1);
}

void irbgrab::Device_Grab(int aStreamIndex, bool aGrabbing)
{

    qDebug()<<("");
    QString ss = "";
    TITSDK_Handle devHandle = FDeviceInfo[0].DeviceHandle;
    TITSDK_Ret ret = 0;
    ret = FIRBgrab->FObjectHandler_Dev.dev_stopgrab(devHandle, 0);
    if (ret == ITSDK_RET_SUCCESS){
        ss = "Stop grab ("+QString::number(0) + ") succeeded";
    }
    else {
        ss = "Stop grab failed " + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16);
    }
    qDebug()<<(ss);


    if (aGrabbing){
        //return false;
        // tmrMain->start(100); //定时器启动，回调函数tmrMainTimeout
        FDeviceInfo[0].StreamInfo[0].MemTypeWant = IRBG_MEMOBJ_IR_DIGITFRAME;


        ret = FIRBgrab->FObjectHandler_Dev.dev_startgrab(devHandle, 0, false);
        if (ret == ITSDK_RET_SUCCESS){
            ss = "Start grab ("+QString::number(0) + ") succeeded";
        }
        else {
            ss = "Start grab failed " + QString::number(FIRBgrab->FObjectHandler_Dev.LastError(), 16);
        }
        qDebug()<<(ss);
    }
}

void irbgrab::tmrMainTimeout()
{
    if (FAtomicMemCrit.testAndSetAcquire(0, 1))  //原子锁，保护内存句柄
    {
        TITSDK_Handle aMemHandle = FDeviceInfo[0].StreamInfo[0].MemHandle;
        FDeviceInfo[0].StreamInfo[0].MemHandle = 0;
        FAtomicMemCrit.testAndSetRelease(1,0);
        // qDebug()<<aMemHandle;

        if (aMemHandle != 0)
        {
            int ii;
            uint32_t ww, hh, datatype;

            void *pData;
            unsigned short maxDV,minDV;


            if (   (FIRBgrab->FObjectHandler_Mem.mem_GetDimension(aMemHandle, &ww, &hh, &datatype) == ITSDK_RET_OK)
                && (FIRBgrab->FObjectHandler_Mem.mem_GetDataPtr(aMemHandle, &pData, &ii) == ITSDK_RET_OK)
                && FIRBgrab->FObjectHandler_Mem.mem_GetDigitalValues(aMemHandle,&minDV,&maxDV) == ITSDK_RET_OK)
            {
                float multi = maxDV - minDV;
                if (multi > 0)  {multi = 255 / multi;}
                else            {multi = 1;}

                int32_t len = ww * hh;
                FImage = QImage(ww, hh, QImage::Format_RGB32);

                uint32_t *pixTo = (uint32_t *) FImage.bits();

                uint16_t *pSrc = (uint16_t*) pData;


                while(len > 0)
                {
                    ii = ((*pSrc - minDV) * multi);
                    if (ii < 0) ii = 0;
                    if (ii > 255) ii = 255;
                    ii = ii | (ii << 8) | (ii << 16);
                    *pixTo = ii;
                    pSrc++;
                    pixTo++;
                    len--;
                }
                infraImage = QPixmap::fromImage(FImage);
                // ui->lblImage->setPixmap(infraImage);


                // QString fileName = "./data/" +
                //                    QDateTime::fromMSecsSinceEpoch(QDateTime::currentMSecsSinceEpoch()).toString("yyyyMMdd_HHmmss_zzz") + ".png";
                // QString currentDir = QDir::currentPath();
                // qDebug() << "当前工作目录:" << currentDir;
                // qDebug()<<fileName;
                // FImage.save(fileName);
            }
        }
        FIRBgrab->FObjectHandler_Mem.Mem_Free(&aMemHandle);
    }
    // tmrMain->singleShot(100, this, SLOT(tmrMainTimeout()));
}


