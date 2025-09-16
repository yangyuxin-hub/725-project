#include "oitsdk_objecthandler_irbgrabdev.h"
#include "hitsdkconstants.h"


TITSDK_ObjectHandler_IRBGrabDev::TITSDK_ObjectHandler_IRBGrabDev()
{
    _ITObjectFree = nullptr;
    _GetParam = nullptr;
    _SetParam = nullptr;
}

TITSDK_ObjectHandler_IRBGrabDev::~TITSDK_ObjectHandler_IRBGrabDev()
{

}

bool TITSDK_ObjectHandler_IRBGrabDev::Init(PITSDK_LibHandle aLibHandle)
{
    TITSDK_ObjectHandler::Init(aLibHandle);
    if (!LibHandle_IsValid()) {return false;}

    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_create), "irbgrab_dev_create")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_ITObjectFree), "irbgrab_dev_free")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_search), "irbgrab_dev_search")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_connect), "irbgrab_dev_connect")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_disconnect), "irbgrab_dev_disconnect")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_startgrab), "irbgrab_dev_startgrab")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_stopgrab), "irbgrab_dev_stopgrab")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_GetParam), "irbgrab_dev_getparam")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_SetParam), "irbgrab_dev_setparam")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_getdata), "irbgrab_dev_getdata")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_getdataex), "irbgrab_dev_getdataex")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_getstate), "irbgrab_dev_getstate")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_clearringbuffer), "irbgrab_dev_clearringbuffer")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_pollframegrab), "irbgrab_dev_pollframegrab")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_dev_pollframefinish), "irbgrab_dev_pollframefinish")) return false;


    return true;
}

void TITSDK_ObjectHandler_IRBGrabDev::Deinit()
{
    FProc_dev_create = NULL;
    FProc_dev_search = NULL;
    FProc_dev_connect = NULL;
    FProc_dev_disconnect = NULL;
    FProc_dev_startgrab = NULL;
    FProc_dev_stopgrab = NULL;
    FProc_dev_getdata = NULL;
    FProc_dev_getdataex = NULL;
    FProc_dev_getstate = NULL;
    FProc_dev_clearringbuffer = NULL;
    FProc_dev_pollframegrab = NULL;
    FProc_dev_pollframefinish = NULL;

    TITSDK_ObjectHandler::Deinit();
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_create(TITSDK_Handle *aDevHandle, int aDeviceIndex, const char *aIniFile)
{
    if (!FProc_dev_create) return ITSDK_RET_ERR_GENERIC;
    TITSDK_Ret ret = FProc_dev_create(aDevHandle, aDeviceIndex, aIniFile);
    return ret;
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_free(PITSDK_Handle aDevHandle)
{
    return ITObject_Free(aDevHandle);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_search(TITSDK_Handle aDevHandle, int *aDeviceCount)
{
    if (!FProc_dev_search) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_search(aDevHandle, aDeviceCount);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_connect(TITSDK_Handle aDevHandle, const char* aConnectString)
{
    if (!FProc_dev_connect) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_connect(aDevHandle, aConnectString);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_disconnect(TITSDK_Handle aDevHandle)
{
    if (!FProc_dev_disconnect) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_disconnect(aDevHandle);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_startgrab(TITSDK_Handle aDevHandle, int aStreamIndex, bool aPolling)
{
    TITSDK_Ret ret = ITSDK_RET_ERR_GENERIC;

    TITSDK_CallBack callb;

    if (!aPolling)  // OnNewFrame
    {
        //callb.FuncPtr = (void**)(&IRBGonNewFrame);
        //callb.Context = FParent;

        //ret = SetParam(aDevHandle, IRBG_PARAM_OnNewFrame, &callb, ITSDK_DATATYPE_CALLBACK);
        //if (ret != ITSDK_RET_OK) return ret;
        ret = ITSDK_RET_OK;
    }
    else
    {
        TITSDK_Int32 i32 = 1;
        ret = SetParam_Int32(aDevHandle, IRBG_PARAM_SDK_PollingEnable, &i32);
        if (ret != ITSDK_RET_OK) return ret;
    }

    if (!FProc_dev_startgrab) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_startgrab(aDevHandle, aStreamIndex);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_stopgrab(TITSDK_Handle aDevHandle, int aStreamIndex)
{
    if (!FProc_dev_stopgrab) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_stopgrab(aDevHandle, aStreamIndex);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_getdata(TITSDK_Handle aDevHandle, int aWhat, TITSDK_Handle *aMemHandle)
{
    if (!FProc_dev_getdata) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_getdata(aDevHandle, aWhat, aMemHandle);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_getdataex(TITSDK_Handle aDevHandle, TITSDK_Handle *aMemHandle, int aStreamIndex, int aWhat)
{
    if (!FProc_dev_getdataex) return ITSDK_RET_ERR_GENERIC;
    TIRBG_GetData aGetData;
    aGetData.StructSize  = sizeof(TIRBG_GetData);
    aGetData.StreamIndex = aStreamIndex;
    aGetData.What		 = aWhat;
    return FProc_dev_getdataex(aDevHandle, aMemHandle, &aGetData);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_getstate(TITSDK_Handle aDevHandle)
{
    if (!FProc_dev_getstate) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_getstate(aDevHandle);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_clearringbuffer(TITSDK_Handle aDevHandle)
{
    if (!FProc_dev_clearringbuffer) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_clearringbuffer(aDevHandle);
}


TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_pollframegrab(TITSDK_Handle aDevHandle, int aStreamIndex, int aTimeout)
{
    if (!FProc_dev_pollframegrab) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_pollframegrab(aDevHandle, aStreamIndex, aTimeout);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabDev::dev_pollframefinish(TITSDK_Handle aDevHandle, int aStreamIndex)
{
    if (!FProc_dev_pollframefinish) return ITSDK_RET_ERR_GENERIC;
    return FProc_dev_pollframefinish(aDevHandle, aStreamIndex);
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_libstate(TITSDK_Handle aDevHandle)
{
    int resval = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Library_State, &resval) != ITSDK_RET_SUCCESS) {
        resval = -1;
    }
    return resval;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Callback_OnNewFrame(TITSDK_Handle aDevHandle, TIRBGonNewFrame aCallback, TITSDK_Pointer aContext)
{
    TITSDK_CallBack callb;
    callb.FuncPtr = (void**)aCallback;// (&IRBGonNewFrame);
    callb.Context = aContext;

    return SetParam(aDevHandle, IRBG_PARAM_OnNewFrame, &callb, ITSDK_DATATYPE_CALLBACK) == ITSDK_RET_OK;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Count(TITSDK_Handle aDevHandle)
{
  int resval = -1;
  if (GetParam_Int32(aDevHandle, IRBG_PARAM_Camera_Device_Count, &resval) != ITSDK_RET_SUCCESS) {
      resval = -1;
  }
  return resval;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Info(TITSDK_Handle aDevHandle, int aIndex, std::string *aDevInfo)
{
    aDevInfo->resize(1024);
    return (GetParam_IdxString(aDevHandle, IRBG_PARAM_Camera_Device_Info, aIndex, aDevInfo) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_ConnectionString(TITSDK_Handle aDevHandle, int aIndex, std::string *aConnectString)
{
    aConnectString->resize(1024);
    return (GetParam_IdxString(aDevHandle, IRBG_PARAM_Camera_Device_ConnectStr, aIndex, aConnectString) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Connected(TITSDK_Handle aDevHandle)
{
    return (dev_Get_libstate(aDevHandle) >= 7);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Name(TITSDK_Handle aDevHandle, std::string *aName)
{
    aName->resize(128);
    return (GetParam_String(aDevHandle, IRBG_PARAM_Camera_Name, aName) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_SerialNumber(TITSDK_Handle aDevHandle, std::string *aSerialNo)
{
    aSerialNo->resize(128);
    return (GetParam_String(aDevHandle, IRBG_PARAM_Camera_SerialNum, aSerialNo) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Temperature(TITSDK_Handle aDevHandle, int aIndex, TITSDK_Single *aTemp)
{
    return (GetParam_IdxSingle(aDevHandle, IRBG_PARAM_Camera_Temperature, aIndex, aTemp) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Temperature_Sensor(TITSDK_Handle aDevHandle, int aIndex, std::string *aSensorName)
{
    aSensorName->resize(128);
    return (GetParam_IdxString(aDevHandle, IRBG_PARAM_Camera_Temperature_Name, aIndex, aSensorName) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Version(TITSDK_Handle aDevHandle, int aIndex, std::string *aIdentifier, std::string *aVersion)
{
    std::string val = "";
    val.resize(256);
    TITSDK_Ret ret = GetParam_IdxString(aDevHandle, IRBG_PARAM_Camera_Version, aIndex, &val);
    if (ret != ITSDK_RET_SUCCESS) {return false;}

    int sep = val.find("###");
    aIdentifier->resize(sep);

    val.copy(aIdentifier->data(), sep,0);
    sep +=3;
    aVersion->resize(val.size() - sep);
    val.copy(aVersion->data(), aVersion->size(), sep);
    return true;

}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Device_Standby(TITSDK_Handle aDevHandle, bool *aStandBy)
{
    TITSDK_Ret ret = GetParam_Bool(aDevHandle, IRBG_PARAM_Camera_Standby, aStandBy);
    if (ret != ITSDK_RET_SUCCESS){
        *aStandBy = false;
        return false;
    }
    return true;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Device_Standby(TITSDK_Handle aDevHandle, bool *aStandBy)
{
    return SetParam_Bool(aDevHandle, IRBG_PARAM_Camera_Standby, aStandBy);
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Stream_Count(TITSDK_Handle aDevHandle)
{
    int resval = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Stream_Count, &resval) != ITSDK_RET_SUCCESS){
        resval = -1;
    }
    return resval;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Stream_Info(TITSDK_Handle aDevHandle, int aStreamIndex, std::string *aStreamName, int *aStreamType)
{
    if (GetParam_IdxInt32(aDevHandle, IRBG_PARAM_Stream_Type, aStreamIndex, aStreamType) != ITSDK_RET_SUCCESS){
        *aStreamType = 0;
    }

    aStreamName->resize(64);
    if (GetParam_IdxString(aDevHandle, IRBG_PARAM_Stream_Name, aStreamIndex, aStreamName) != ITSDK_RET_SUCCESS){
        *aStreamName = "Unknown stream";
    }

    return true;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Stream_IsGrabbing(TITSDK_Handle aDevHandle, int aStreamIndex)
{
    TITSDK_Int32 ival = 0;
    if (GetParam_IdxInt32(aDevHandle, IRBG_PARAM_Stream_IsGrabbing, aStreamIndex, &ival) != ITSDK_RET_SUCCESS){
        ival = 0;
    }
    return (ival != 0);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_IsGrabbing(TITSDK_Handle aDevHandle)
{
    bool val = false;
    if (GetParam_Bool(aDevHandle, IRBG_PARAM_Stream_IsGrabbing, &val) != ITSDK_RET_SUCCESS){
        val = false;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_Count(TITSDK_Handle aDevHandle)
{
    int resval = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Calib_Count, &resval) != ITSDK_RET_SUCCESS){
        resval = -1;
    }
    return resval;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_Name(TITSDK_Handle aDevHandle, int aCalibIndex, std::string *aCalibName)
{
    aCalibName->resize(128);
    return (GetParam_IdxString(aDevHandle, IRBG_PARAM_Calib_Name, aCalibIndex, aCalibName) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_ChangeInProgress(TITSDK_Handle aDevHandle)
{
    bool val = false;
    if (GetParam_Bool(aDevHandle, IRBG_PARAM_Calib_ChangeInProgress, &val) != ITSDK_RET_SUCCESS){
        val = false;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_Active(TITSDK_Handle aDevHandle)
{
    int resval = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Calib_Active, &resval) != ITSDK_RET_SUCCESS){
        resval = -1;
    }
    return resval;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Calib_Active(TITSDK_Handle aDevHandle, int aCalibIndex)
{
    int resval = aCalibIndex;
    if (SetParam_Int32(aDevHandle, IRBG_PARAM_Calib_Active, &resval) != ITSDK_RET_SUCCESS){
        resval = -1;
    }
    return resval;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_Range(TITSDK_Handle aDevHandle, TITSDK_Single *aMinK, TITSDK_Single *aMaxK, int aMITIndex)
{
    if (aMITIndex < 0){
        if (GetParam_Single(aDevHandle, IRBG_PARAM_Calib_MinKelvin, aMinK) != ITSDK_RET_SUCCESS) {return false;}
        if (GetParam_Single(aDevHandle, IRBG_PARAM_Calib_MaxKelvin, aMaxK) != ITSDK_RET_SUCCESS) {return false;}
    }
    else{
        if (GetParam_IdxSingle(aDevHandle, IRBG_PARAM_Calib_MinKelvin, aMITIndex, aMinK) != ITSDK_RET_SUCCESS) {return false;}
        if (GetParam_IdxSingle(aDevHandle, IRBG_PARAM_Calib_MaxKelvin, aMITIndex, aMaxK) != ITSDK_RET_SUCCESS) {return false;}
    }
    return true;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_Active(TITSDK_Handle aDevHandle, std::string *aCalibName)
{
    return (GetParam_String(aDevHandle, IRBG_PARAM_Calib_Active, aCalibName) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_Active(TITSDK_Handle aDevHandle, int *aCount, std::string *aCalibNames)
{
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Calib_MIT_Count, aCount) != ITSDK_RET_SUCCESS){
        *aCount = 0;
        *aCalibNames = "";
        return false;
    }

    aCalibNames->resize(0);
    std::string optn = "";
    for (int ii = 0; ii< *aCount; ii++)
    {
        optn="";
        optn.resize(64);

        if (GetParam_IdxString(aDevHandle, IRBG_PARAM_Calib_Active, ii, &optn) != ITSDK_RET_SUCCESS){
            optn = "Calib " + std::to_string(ii);
        }

        if (ii < *aCount){
            optn.append("\n");
        }

        aCalibNames->append(optn);
    }
    return true;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_FramerateMax(TITSDK_Handle aDevHandle, TITSDK_Single *aFramerateMax)
{
    return (GetParam_Single(aDevHandle, IRBG_PARAM_Calib_MaxFrameRate, aFramerateMax) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Calib_MITInfo(TITSDK_Handle aDevHandle, TITSDK_Int32 *aMITCount, TITSDK_Int32 *aMITmaxCount)
{
    *aMITCount = 1;
    *aMITmaxCount = 1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Calib_MIT_Count, aMITCount) != ITSDK_RET_SUCCESS){
        *aMITCount = 1;
    }
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Calib_MIT_MAX_Count, aMITmaxCount) != ITSDK_RET_SUCCESS){
        *aMITmaxCount = 1;
    }
    return true;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_NUC_Enabled(TITSDK_Handle aDevHandle)
{
    bool val = false;

    switch (GetParam_Bool(aDevHandle, IRBG_PARAM_NUC_Enable, &val)){
        case ITSDK_RET_SUCCESS:
            break;
        case ITSDK_RET_ERR_NOT_SUPPORTED:
            val = true;
            break;
        default:
            val = false;
            break;
    }
    return val;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Set_NUC_Enabled(TITSDK_Handle aDevHandle, bool *aNUCEnable)
{
    return (SetParam_Bool(aDevHandle, IRBG_PARAM_NUC_Enable, aNUCEnable) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_NUC_InProgress(TITSDK_Handle aDevHandle)
{
    bool val = false;
    if (GetParam_Bool(aDevHandle, IRBG_PARAM_NUC_InProgress, &val) != ITSDK_RET_SUCCESS){
        val = false;
    }
    return val;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_NUC_Interval(TITSDK_Handle aDevHandle, TITSDK_Int32 *aNUCInterval)
{
    return (GetParam_Int32(aDevHandle, IRBG_PARAM_NUC_Interval, aNUCInterval) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Set_NUC_Interval(TITSDK_Handle aDevHandle, TITSDK_Int32 *aNUCInterval)
{
    return (SetParam_Int32(aDevHandle, IRBG_PARAM_NUC_Interval, aNUCInterval) == ITSDK_RET_SUCCESS);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Set_NUC_Execute(TITSDK_Handle aDevHandle, TITSDK_Int32 aNUCMode, TITSDK_Int32 aNUCFlags)
{
    return SetParam_2Int32(aDevHandle, IRBG_PARAM_NUC_Execute, aNUCMode, aNUCFlags);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Set_NUC_Execute_1Point(TITSDK_Handle aDevHandle)
{
    return dev_Set_NUC_Execute(aDevHandle, 2, 0);
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_BPR_Enabled(TITSDK_Handle aDevHandle)
{
    bool val = false;

    switch (GetParam_Bool(aDevHandle, IRBG_PARAM_BPR_Enable, &val)){
        case ITSDK_RET_SUCCESS:
            break;
        case ITSDK_RET_ERR_NOT_SUPPORTED:
            val = true;
            break;
        default:
            val = false;
            break;
    }
    return val;
}


int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_ChannelCount(TITSDK_Handle aDevHandle)
{
    TITSDK_Int32 cnt = 0;

    if (GetParam_Int32(aDevHandle, IRBG_PARAM_OutChannel_Count, &cnt) != ITSDK_RET_SUCCESS){
        cnt = -1;}
    return cnt;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_ChannelName(TITSDK_Handle aDevHandle, int aChannelIndex, std::string *aChannelName)
{
    aChannelName->resize(64);
    if (GetParam_IdxString(aDevHandle, IRBG_PARAM_OutChannel_Name, aChannelIndex, aChannelName) != ITSDK_RET_SUCCESS){
        return false;
    }
    return true;
}


bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_Channels(TITSDK_Handle aDevHandle, int *aChannelCount, std::string *aChannelNames)
{
    int cnt = dev_Get_Out_ChannelCount(aDevHandle);
    if (cnt < 0 ){
        *aChannelCount = 0;
        *aChannelNames = "";
        return false;
    }

    *aChannelCount = cnt;

    aChannelNames->resize(0);
    std::string chnl = "";
    for (int ii = 0; ii< cnt; ii++)
    {
        if (!dev_Get_Out_ChannelName(aDevHandle, ii, &chnl)) {
            chnl = "Output " + std::to_string(ii);
        }

        if (ii < cnt){
            chnl.append("\n");
        }

        aChannelNames->append(chnl);
    }
    return true;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_ChannelOptionCount(TITSDK_Handle aDevHandle, int aChannel)
{
    int cnt = 0;
    if (GetParam_IdxInt32(aDevHandle, IRBG_PARAM_OutChannel_OptionCount, aChannel, &cnt) != ITSDK_RET_SUCCESS){
        cnt = -1;
    }
    return cnt;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_ChannelOptionName(TITSDK_Handle aDevHandle, int aChannel, int aOption, std::string *aOptionName)
{
    *aOptionName= std::to_string(aOption);
    aOptionName->resize(64);

    bool bb = (GetParam_IdxString(aDevHandle, IRBG_PARAM_OutChannel_OptionName, aChannel, aOptionName) == ITSDK_RET_SUCCESS);
    if (!bb){
        *aOptionName = "Option " + std::to_string(aOption);
    }
    return bb;
}


bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_ChannelsOptions(TITSDK_Handle aDevHandle, int aChannel, int *aOptionCount, std::string *aOptions)
{
    int cnt = dev_Get_Out_ChannelOptionCount(aDevHandle, aChannel);
    if (cnt < 0){
        *aOptionCount = 0;
        *aOptions = "";
        return false;
    }

    *aOptionCount = cnt;

    aOptions->resize(0);
    std::string optn = "";
    for (int ii = 0; ii< *aOptionCount; ii++)
    {
        dev_Get_Out_ChannelOptionName(aDevHandle, aChannel, ii, &optn);

        if (ii < *aOptionCount){
            optn.append("\n");
        }

        aOptions->append(optn);
    }
    return true;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Out_ChannelOption(TITSDK_Handle aDevHandle, int aChannel)
{
    TITSDK_Int32 val = 0;
    if (GetParam_IdxInt32(aDevHandle, IRBG_PARAM_OutChannel_OptionIndex, aChannel, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Out_ChannelOption(TITSDK_Handle aDevHandle, int aChannel, int aOption)
{
    TITSDK_Int32 val = aOption;
    if (SetParam_IdxInt32(aDevHandle, IRBG_PARAM_OutChannel_OptionIndex, aChannel, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_DetectorSync_OptionCount(TITSDK_Handle aDevHandle)
{
    int cnt = 0;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_SyncItemCount, &cnt) != ITSDK_RET_SUCCESS){
        cnt = -1;
    }
    return cnt;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_DetectorSync_OptionName(TITSDK_Handle aDevHandle, int aOption, std::string *aOptionName)
{
    aOptionName->resize(64);

    bool bb = (GetParam_IdxString(aDevHandle, IRBG_PARAM_Trigger_SyncItem, aOption, aOptionName) == ITSDK_RET_SUCCESS);
    if (!bb){
        *aOptionName = "Option " + std::to_string(aOption);
    }
    return bb;
}


int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_DetectorSync_Option(TITSDK_Handle aDevHandle)
{
    TITSDK_Int32 val = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_SyncIdx, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Trigger_DetectorSync_Option(TITSDK_Handle aDevHandle, int aOption)
{
    TITSDK_Int32 val = aOption;
    if (SetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_SyncIdx, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_FrameMark_OptionCount(TITSDK_Handle aDevHandle)
{
    int cnt = 0;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_MarkItemCount, &cnt) != ITSDK_RET_SUCCESS){
        cnt = -1;
    }
    return cnt;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_FrameMark_OptionName(TITSDK_Handle aDevHandle, int aOption, std::string *aOptionName)
{
    aOptionName->resize(64);

    bool bb = (GetParam_IdxString(aDevHandle, IRBG_PARAM_Trigger_MarkItem, aOption, aOptionName) == ITSDK_RET_SUCCESS);
    if (!bb){
        *aOptionName = "Option " + std::to_string(aOption);
    }
    return bb;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_FrameMark_Option(TITSDK_Handle aDevHandle)
{
    TITSDK_Int32 val = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_MarkIdx, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Trigger_FrameMark_Option(TITSDK_Handle aDevHandle, int aOption)
{
    TITSDK_Int32 val = aOption;
    if (SetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_MarkIdx, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_Gate_OptionCount(TITSDK_Handle aDevHandle)
{
    int cnt = 0;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_GateItemCount, &cnt) != ITSDK_RET_SUCCESS){
        cnt = -1;
    }
    return cnt;
}

bool TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_Gate_OptionName(TITSDK_Handle aDevHandle, int aOption, std::string *aOptionName)
{
    aOptionName->resize(64);

    bool bb = (GetParam_IdxString(aDevHandle, IRBG_PARAM_Trigger_GateItem, aOption, aOptionName) == ITSDK_RET_SUCCESS);
    if (!bb){
        *aOptionName = "Option " + std::to_string(aOption);
    }
    return bb;
}


int TITSDK_ObjectHandler_IRBGrabDev::dev_Get_Trigger_Gate_Option(TITSDK_Handle aDevHandle)
{
    TITSDK_Int32 val = -1;
    if (GetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_GateIdx, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}

int TITSDK_ObjectHandler_IRBGrabDev::dev_Set_Trigger_Gate_Option(TITSDK_Handle aDevHandle, int aOption)
{
    TITSDK_Int32 val = aOption;
    if (SetParam_Int32(aDevHandle, IRBG_PARAM_Trigger_GateIdx, &val) != ITSDK_RET_SUCCESS){
        val = -1;
    }
    return val;
}




