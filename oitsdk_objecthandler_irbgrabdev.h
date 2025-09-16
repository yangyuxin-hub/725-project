#ifndef OITSDK_OBJECTHANDLER_IRBGRABDEV_H
#define OITSDK_OBJECTHANDLER_IRBGRABDEV_H


#include "hitsdktypes.h"
#include "oitsdk_objecthandler.h"

#pragma once

#define IRBG_PARAM_Library_State           109 // R ITSDK_DATATYPE_INT32

/// Acquisition - Streaming
#define IRBG_PARAM_OnNewFrame               103 // IRBG_DATATYPE_CALLBACK
#define IRBG_PARAM_SDK_PollingEnable        184 // R/W	ITSDK_DATATYPE_INT32 as boolean; Availability of polling

/// Camera - Status
#define IRBG_PARAM_Camera_Device_Count       200 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Camera_Device_Info        201 // R ITSDK_DATATYPE_IDXString; [0 <= Index < IRBG_PARAM_CameraDevice_Count]; string value contains camera information
#define IRBG_PARAM_Camera_Device_ConnectStr	 202 // R ITSDK_DATATYPE_IDXString;  can be set as parameter in function irbgrab_dev_connect

#define IRBG_PARAM_Camera_Name              203 // R ITSDK_DATATYPE_String
#define IRBG_PARAM_Camera_SerialNum         211 // R ITSDK_DATATYPE_INT64
#define IRBG_PARAM_Camera_Temperature       213 // R ITSDK_DATATYPE_IDXSingle [K]
#define IRBG_PARAM_Camera_Temperature_Name	214 // R ITSDK_DATATYPE_IDXString
#define IRBG_PARAM_Camera_Version           216 // R ITSDK_DATATYPE_IDXString; 'Object###Version'

#define IRBG_PARAM_Camera_Standby           215 // R/W ITSDK_DATATYPE_INT32 as Boolean

#define IRBG_PARAM_Stream_Count             229 // ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Stream_Name              228 // ITSDK_DATATYPE_IDXSTRING; Index: StreamIndex; Value: Name
#define IRBG_PARAM_Stream_Type              227 // ITSDK_DATATYPE_IDXINT32; Index: StreamIndex; Value: StreamType as stream type constant
#define IRBG_PARAM_Stream_IsGrabbing        226 // ITSDK_DATATYPE_IDXINT32; Index: StreamIndex; Value: IsGrabbing as boolean

/// Camera - Calibration
#define IRBG_PARAM_Calib_Count              119 //R ITSDK_DATATYPE_INT32; Count of calibration and MIT-Presets
#define IRBG_PARAM_Calib_Active             120 //R/W ITSDK_DATATYPE_IDXINT32; .Value Index of calibration in range [0..CalibCount-1]. Set it to -1 to deselect the calibration from .Index; .Index must always be set in Range [0..3]. Set it to 0 to select a MIT-Preset.
#define IRBG_PARAM_Calib_Name               121 //R ITSDK_DATATYPE_IDXString; Name of calibration or MIT-preset
#define IRBG_PARAM_Calib_ChangeInProgress	118 //R ITSDK_DATATYPE_INT32 as Boolean; if not 0, change of calibration is still in progress
#define IRBG_PARAM_Calib_MaxFrameRate       117 //R ITSDK_DATATYPE_SINGLE [Hz]
#define IRBG_PARAM_Calib_MinKelvin          124	//R ITSDK_DATATYPE_IDXSingle [K]; lower limit of calibration
#define IRBG_PARAM_Calib_MaxKelvin          125	//R ITSDK_DATATYPE_IDXSingle [K]; upper limit of calibration
#define IRBG_PARAM_Calib_Window             116 //R IRBG_WindowMode

#define IRBG_PARAM_Calib_MIT_Count                260 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Calib_MIT_MAX_Count            261 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Calib_MIT_Name                 263 // R ITSDK_DATATYPE_STRING
#define IRBG_PARAM_Calib_MIT_Mode                 264 // R ITSDK_DATATYPE_INT32 (see 5.4.12)

/// Camera – Measurement Control - NUC (Non-Uniformity Correction)
#define IRBG_PARAM_NUC_Enable               410 // R ITSDK_DATATYPE_INT32 as Boolean; activates the correction
#define IRBG_PARAM_NUC_InProgress           412 // R ITSDK_DATATYPE_INT32 as Boolean; information if NUC is in progress
#define IRBG_PARAM_NUC_Interval             415 // R/W ITSDK_DATATYPE_INT32 [s] (0=off)
#define IRBG_PARAM_NUC_Execute              411 // W ITSDK_DATATYPE_2INT32; performs a NUC (see 5.4.6)

/// Camera – Measurement Control - BPR (Bad Pixel Replacement)
#define IRBG_PARAM_BPR_Enable              430 // R ITSDK_DATATYPE_INT32 as Boolean; activates the BPR-correction

/// IO - Out channels
#define  IRBG_PARAM_OutChannel_Count        375   // IT_DATATYPE_INT32     ReadOnly: Value = Anzahl der TriggerOut-Kanäle
#define  IRBG_PARAM_OutChannel_Name         376   // IT_DATATYPE_IDXSTRING
#define  IRBG_PARAM_OutChannel_OptionCount  377   // IT_DATATYPE_IDXINT32  ReadOnly: Index = Index des Out-Kanals, Value = Anzahl der TriggerOut1-Optionen
#define  IRBG_PARAM_OutChannel_OptionName   378   // IT_DATATYPE_IDXSTRING ReadOnly: Index = Index des Out-Kanals, Value = In: Index des Item, Out: Name des Items
#define  IRBG_PARAM_OutChannel_OptionIndex  379   // IT_DATATYPE_IDXINT32  Index = Index des Out-Kanals, Value = selektierter Index des Out-Kanals

/// Camera - Hardware Control - External Trigger
#define IRBG_PARAM_Trigger_SyncItemCount	346 // R ITSDK_DATATYPE_INT32; = number of TriggerSync options
#define IRBG_PARAM_Trigger_SyncItem         347 // R ITSDK_DATATYPE_IDXString; index must be set
#define IRBG_PARAM_Trigger_SyncIdx          348 // R/W ITSDK_DATATYPE_INT32; = Index

#define IRBG_PARAM_Trigger_MarkItemCount    343 // R ITSDK_DATATYPE_INT32; = number of TriggerMark options
#define IRBG_PARAM_Trigger_MarkItem         344 // R ITSDK_DATATYPE_IDXString; index must be set
#define IRBG_PARAM_Trigger_MarkIdx          345 // R/W ITSDK_DATATYPE_INT32; = Index

#define IRBG_PARAM_Trigger_GateItemCount	340 // R ITSDK_DATATYPE_INT32; = number of TriggerGate options
#define IRBG_PARAM_Trigger_GateItem         341 // R ITSDK_DATATYPE_IDXString; index must be set
#define IRBG_PARAM_Trigger_GateIdx          342 // R/W ITSDK_DATATYPE_INT32; = Index

struct TIRBG_GetData
{
    uint32_t	StructSize;
    int32_t	What;
    uint32_t	StreamIndex;
};

typedef void (__CALLCONV *TIRBGonNewFrame)(TITSDK_Handle aContext, TITSDK_Handle aDevHandle, int aStreamIndex);
typedef void(*TIRBGOnNewFrameObject)(TITSDK_Handle aDevHandle, int aStreamIndex);




class TITSDK_ObjectHandler_IRBGrabDev : public TITSDK_ObjectHandler
{
    private:
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_create)(TITSDK_Handle *aDevHandle,int aDeviceIndex,const char *aIniFile);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_free)(TITSDK_Handle aDevHandle);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_search)(TITSDK_Handle aDevHandle,int *aDeviceCount);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_connect)(TITSDK_Handle aDevHandle, const char *aConnectString);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_disconnect)(TITSDK_Handle aDevHandle);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_startgrab)(TITSDK_Handle aDevHandle,int aStreamIndex);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_stopgrab)(TITSDK_Handle aDevHandle,int aStreamIndex);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_setparam)(TITSDK_Handle aDevHandle, int aWhat, void *aDataPtr, uint32_t aDataType);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_getparam)(TITSDK_Handle aDevHandle, int aWhat, void *aDataPtr, uint32_t aDataType);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_getdata)(TITSDK_Handle aDevHandle, int aWhat, TITSDK_Handle *aMemHandle);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_getdataex)(TITSDK_Handle aDevHandle, TITSDK_Handle *aMemHandle, TIRBG_GetData *aGetData);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_getstate)(TITSDK_Handle aDevHandle);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_clearringbuffer)(TITSDK_Handle aDevHandle);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_pollframegrab)(TITSDK_Handle aHandle, int aStreamIndex, int aTimeout);
        typedef TITSDK_Ret(__CALLCONV *TProc_dev_pollframefinish)(TITSDK_Handle aHandle, int aStreamIndex);

        TProc_dev_create		    FProc_dev_create;
        TProc_dev_search		    FProc_dev_search;
        TProc_dev_connect		    FProc_dev_connect;
        TProc_dev_disconnect	    FProc_dev_disconnect;
        TProc_dev_startgrab		    FProc_dev_startgrab;
        TProc_dev_stopgrab		    FProc_dev_stopgrab;
        TProc_dev_getdata		    FProc_dev_getdata;
        TProc_dev_getdataex		    FProc_dev_getdataex;
        TProc_dev_getstate  	    FProc_dev_getstate;
        TProc_dev_clearringbuffer   FProc_dev_clearringbuffer;
        TProc_dev_pollframegrab     FProc_dev_pollframegrab;
        TProc_dev_pollframefinish   FProc_dev_pollframefinish;

    protected:
    //public declarations for object infrastructure
    public:
      TITSDK_ObjectHandler_IRBGrabDev();
      ~TITSDK_ObjectHandler_IRBGrabDev();

      bool Init(PITSDK_LibHandle aLibHandle);
      void Deinit();

    //public declarations of exported library functions
    public:
      TITSDK_Ret dev_create(TITSDK_Handle *aDevHandle, int aDeviceIndex, const char *aIniFile);
      TITSDK_Ret dev_free(PITSDK_Handle aDevHandle);
      TITSDK_Ret dev_search(TITSDK_Handle aDevHandle, int *aDeviceCount);
      TITSDK_Ret dev_connect(TITSDK_Handle aDevHandle, const char *aConnectString);
      TITSDK_Ret dev_disconnect(TITSDK_Handle aDevHandle);
      TITSDK_Ret dev_startgrab(TITSDK_Handle aDevHandle, int aStreamIndex, bool aPolling);
      TITSDK_Ret dev_stopgrab(TITSDK_Handle aDevHandle, int aStreamIndex);

      TITSDK_Ret dev_getdata(TITSDK_Handle aDevHandle, int aWhat, TITSDK_Handle *aMemHandle);
      TITSDK_Ret dev_getdataex(TITSDK_Handle aDevHandle, TITSDK_Handle *aMemHandle, int aStreamIndex, int aWhat);
      TITSDK_Ret dev_getstate(TITSDK_Handle aDevHandle);
      TITSDK_Ret dev_clearringbuffer(TITSDK_Handle aDevHandle);
      TITSDK_Ret dev_pollframegrab(TITSDK_Handle aDevHandle, int aStreamIndex, int aTimeout);
      TITSDK_Ret dev_pollframefinish(TITSDK_Handle aDevHandle, int aStreamIndex);

    //public declarations of derivated library functions
    //Read property "LastError" to get more information of failure
    public:
      int   dev_Get_libstate(TITSDK_Handle aDevHandle);
      //bool dev_SendCommand(TITSDK_Handle aDevHandle, aCmd: String, var aAnswer: String, int aTimeoutMS)

      bool  dev_Set_Callback_OnNewFrame (TITSDK_Handle aDevHandle, TIRBGonNewFrame aCallback, TITSDK_Pointer aContext);

      int   dev_Get_Device_Count            (TITSDK_Handle aDevHandle);
      bool  dev_Get_Device_Info             (TITSDK_Handle aDevHandle, int aIndex, std::string *aDevInfo);
      bool  dev_Get_Device_ConnectionString (TITSDK_Handle aDevHandle, int aIndex, std::string *aConnectString);

      bool  dev_Get_Device_Connected        (TITSDK_Handle aDevHandle);
      bool  dev_Get_Device_Name             (TITSDK_Handle aDevHandle, std::string *aName);
      bool  dev_Get_Device_SerialNumber     (TITSDK_Handle aDevHandle, std::string *aSerialNo);
      bool  dev_Get_Device_Temperature      (TITSDK_Handle aDevHandle, int aIndex, TITSDK_Single *aTemp);
      bool  dev_Get_Device_Temperature_Sensor(TITSDK_Handle aDevHandle, int aIndex, std::string *aSensorName);
      bool  dev_Get_Device_Version          (TITSDK_Handle aDevHandle, int aIndex, std::string *aIdentifier, std::string *aVersion);

      bool  dev_Get_Device_Standby      (TITSDK_Handle aDevHandle, bool *aStandBy);
      bool  dev_Set_Device_Standby      (TITSDK_Handle aDevHandle, bool *aStandBy);

      int   dev_Get_Stream_Count        (TITSDK_Handle aDevHandle);
      bool  dev_Get_Stream_Info         (TITSDK_Handle aDevHandle, int aStreamIndex, std::string *aStreamName, int *aStreamType);
      bool  dev_Get_Stream_IsGrabbing   (TITSDK_Handle aDevHandle, int aStreamIndex);
      bool  dev_Get_IsGrabbing          (TITSDK_Handle aDevHandle);

      int   dev_Get_Calib_Count             (TITSDK_Handle aDevHandle);
      bool  dev_Get_Calib_Name              (TITSDK_Handle aDevHandle, int aCalibIndex, std::string *aCalibName);
      bool  dev_Get_Calib_ChangeInProgress  (TITSDK_Handle aDevHandle);
      int   dev_Get_Calib_Active            (TITSDK_Handle aDevHandle);
      bool  dev_Get_Calib_Active            (TITSDK_Handle aDevHandle, std::string *aCalibName);
      int   dev_Set_Calib_Active            (TITSDK_Handle aDevHandle, int aCalibIndex);
      bool  dev_Get_Calib_Active            (TITSDK_Handle aDevHandle, int *aCount, std::string *aCalibNames);
      bool  dev_Get_Calib_Range             (TITSDK_Handle aDevHandle, TITSDK_Single *aMinK, TITSDK_Single *aMaxK, int aMITIndex);
      bool  dev_Get_Calib_FramerateMax      (TITSDK_Handle aDevHandle, TITSDK_Single *aFramerateMax);
      bool  dev_Get_Calib_MITInfo           (TITSDK_Handle aDevHandle, TITSDK_Int32 *aMITCount, TITSDK_Int32 *aMITmaxCount);


      bool  dev_Get_NUC_Enabled         (TITSDK_Handle aDevHandle);
      bool  dev_Set_NUC_Enabled         (TITSDK_Handle aDevHandle, bool *aNUCEnable);
      bool  dev_Get_NUC_InProgress      (TITSDK_Handle aDevHandle);
      bool  dev_Get_NUC_Interval        (TITSDK_Handle aDevHandle, TITSDK_Int32 *aNUCInterval);
      bool  dev_Set_NUC_Interval        (TITSDK_Handle aDevHandle, TITSDK_Int32 *aNUCInterval);
      bool  dev_Set_NUC_Execute         (TITSDK_Handle aDevHandle, TITSDK_Int32 aNUCMode, TITSDK_Int32 aNUCFlags);
      bool  dev_Set_NUC_Execute_1Point  (TITSDK_Handle aDevHandle);

      bool  dev_Get_BPR_Enabled         (TITSDK_Handle aDevHandle);

      int   dev_Get_Out_ChannelCount    (TITSDK_Handle aDevHandle);
      bool  dev_Get_Out_ChannelName     (TITSDK_Handle aDevHandle, int aChannelIndex, std::string *aChannelName);
      bool  dev_Get_Out_Channels        (TITSDK_Handle aDevHandle, int *aChannelCount, std::string *aChannelNames);

      int   dev_Get_Out_ChannelOptionCount(TITSDK_Handle aDevHandle, int aChannel);
      bool  dev_Get_Out_ChannelOptionName (TITSDK_Handle aDevHandle, int aChannel, int aOption, std::string *aOptionName);
      bool  dev_Get_Out_ChannelsOptions (TITSDK_Handle aDevHandle, int aChannel, int *aOptionCount, std::string *aOptions);
      int   dev_Get_Out_ChannelOption   (TITSDK_Handle aDevHandle, int aChannel);
      int   dev_Set_Out_ChannelOption   (TITSDK_Handle aDevHandle, int aChannel, int aOption);

      int   dev_Get_Trigger_DetectorSync_OptionCount(TITSDK_Handle aDevHandle);
      bool  dev_Get_Trigger_DetectorSync_OptionName (TITSDK_Handle aDevHandle, int aOption, std::string *aOptionName);
      int   dev_Get_Trigger_DetectorSync_Option (TITSDK_Handle aDevHandle);
      int   dev_Set_Trigger_DetectorSync_Option (TITSDK_Handle aDevHandle, int aOption);

      int   dev_Get_Trigger_FrameMark_OptionCount(TITSDK_Handle aDevHandle);
      bool  dev_Get_Trigger_FrameMark_OptionName (TITSDK_Handle aDevHandle,  int aOption, std::string *aOptionName);
      int   dev_Get_Trigger_FrameMark_Option (TITSDK_Handle aDevHandle);
      int   dev_Set_Trigger_FrameMark_Option (TITSDK_Handle aDevHandle, int aOption);

      int   dev_Get_Trigger_Gate_OptionCount(TITSDK_Handle aDevHandle);
      bool  dev_Get_Trigger_Gate_OptionName (TITSDK_Handle aDevHandle, int aOption, std::string *aOptionName);
      int   dev_Get_Trigger_Gate_Option (TITSDK_Handle aDevHandle);
      int   dev_Set_Trigger_Gate_Option (TITSDK_Handle aDevHandle, int aOption);

};

#endif // OITSDK_OBJECTHANDLER_IRBGRABDEV_H
