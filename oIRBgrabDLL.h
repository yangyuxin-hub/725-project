#ifndef OIRBGRABDLL_H
#define OIRBGRABDLL_H

#pragma once

#include "hitsdkide.h"
#include "hitsdkconstants.h"
#include "hitsdktypes.h"
#include "oitsdk_objecthandler_irbgrabdev.h"
#include "oitsdk_objecthandler_irbgrabmem.h"

#ifdef ITSDK_OS_WINDOS
//#include <stdlib.h>
//#include <stdio.h>
//#include "Windows.h"
#endif

#ifdef ITSDK_OS_UNIX
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#endif






#define IRBG_WINDOW_CLOSE  -1
#define IRBG_WINDOW_TOGGLE  0
#define IRBG_WINDOW_SHOW  1
#define IRBG_WINDOW_MINIMIZE  2
#define IRBG_WINDOW_RESTORE  3

#define IRBG_MEMOBJ_NONE  0
#define IRBG_MEMOBJ_BITMAP32  1 // Bitmap mit 32Bit pro Pixel (A,R,G,B)
#define IRBG_MEMOBJ_IR_DIGITFRAME  2 // IRBild mit RAW 16Bit pro Pixel
#define IRBG_MEMOBJ_TEMPERATURES  3 // IRBild mit Kelvin(Single) pro Pixel
#define IRBG_MEMOBJ_8BITDATA  4 // 8Bit-Daten (0 = minTemp ; 255 = maxTemp)

#define WRITEMODE_ADD		0;
#define WRITEMODE_OVERWRITE 1;
#define WRITEMODE_SEQUENCE	2;

#pragma pack (push)

struct TIRBG_SendCommand
{
    char* Command;
    char* Answer;
    int AnswerSize;
    int TimeoutMS;
};


struct TIRBG_WindowMode
{
    int Index;
    int CamIndex;
    int Offx;
    int Offy;
    int Width;
    int Height;
    char Name[32];
};

struct TIRBG_MemInfo
{
    int    StructSize;
    int    Trigged;    // <> 0 --> trigged
    double TimeStamp;  // relative milliseconds
    int64_t  ImageNum;
    int    MissedPackets;
    int    What;
    double TrigTimeDiffMS;
    TITSDK_Handle DeviceHandle;
    uint8_t  StreamIndex;
};

struct TIRBG_HeaderInfo
{
    int           StructSize;
    float         AI[8];
    unsigned char DI[8];
};

struct TIRBG_SaveStruct
{
    uint32_t	StructLength;
    char	FileName[256];
    uint32_t	WriteMode;
    int64_t	MaxFileSizeMB;
    int32_t	MaxFrames;
    int64_t	MinDriveSizeMB;
};



#pragma pack(pop)


#define IRBG_DATATYPE_WINDOWMODE (ITSDK_BASETYPE_RECORD | sizeof(TIRBG_WindowMode))
#define IRBG_DATATYPE_SENDCMD (ITSDK_BASETYPE_RECORD | sizeof(TIRBG_SendCommand))

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/// constants for the functions irbgrab_dev_getparam and irbgrab_dev_setparam
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


#define IRBG_PARAM_SDK_ProcessIRBBypass     183 // ITSDK_DATATYPE_INT32 as Boolean; bypass the temperature calculation of IR-images to reduce the system power. Images can only grabbed as IRBG_MEMOBJ_IR_DIGITFRAME!

/// Acquisition - Acquisition Modulo
#define IRBG_PARAM_Acq_FrameCount           380 // IRBG_DATATYPE_INT32  <0 AcqModulo ausgeschaltet  MaxFrameCount  abs(Value)
#define IRBG_PARAM_Acq_Trigger              381 // IRBG_DATATYPE_INT32 as Boolean
#define IRBG_PARAM_Acq_LineCount            382 // IRBG_DATATYPE_INT32
#define IRBG_PARAM_Acq_LineIndex            383 // IRBG_DATATYPE_INT32
#define IRBG_PARAM_Acq_Waterfall            384 // IRBG_DATATYPE_INT32  Waterfall  Value <> 0
#define IRBG_PARAM_Acq_useFrameCount        385 // IRBG_DATATYPE_INT32
#define IRBG_PARAM_Acq_useLineCount         386 // IRBG_DATATYPE_INT32
#define IRBG_PARAM_Acq_useLineIndex         387 // IRBG_DATATYPE_INT32

/// Presentation/Display
#define IRBG_PARAM_ScaleForm_TempUnit       600 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_ScaleForm_TempRangeMode  601 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_ScaleForm_TempRangeTill	602 // R/W ITSDK_DATATYPE_DOUBLE; upper temperature of palette; unit: [K] if TempUnit <> DigitalValue
#define IRBG_PARAM_ScaleForm_TempRangeFrom	603	// R/W ITSDK_DATATYPE_DOUBLE; lower temperature of palette; unit: [K] if TempUnit <> DigitalValue
#define IRBG_PARAM_ScaleForm_PaletteCount	604	// R ITSDK_DATATYPE_INT32; count of available palettes
#define IRBG_PARAM_ScaleForm_PaletteName	605 // R ITSDK_DATATYPE_IDXString; palette name by Index
#define IRBG_PARAM_ScaleForm_PaletteIdx	    606 // R/W ITSDK_DATATYPE_INT32; current palette index

#define IRBG_PARAM_Image_Filter             620 // R/W ITSDK_DATATYPE_INT32; set the image filter of the camera

/// Radiometric Correction
#define IRBG_PARAM_IRBcorr_ObjEps           700 //	R/W	ITSDK_DATATYPE_IDXSingle; idxLoWord = 0 -> Global Corr
#define IRBG_PARAM_IRBcorr_ObjTau           701 // R/W ITSDK_DATATYPE_IDXSingle; idxLoWord = 0 -> Global Corr
#define IRBG_PARAM_IRBcorr_ObjRho           702 // R/W	ITSDK_DATATYPE_IDXSingle; idxLoWord = 0 -> Global Corr
#define IRBG_PARAM_IRBcorr_ObjTempEnv       703 // R/W	ITSDK_DATATYPE_IDXSingle; idxLoWord = 0 -> Global Corr
#define IRBG_PARAM_IRBcorr_ObjTempBackGrd   704 // R/W	ITSDK_DATATYPE_IDXSingle; idxLoWord = 0 -> Global Corr
#define IRBG_PARAM_IRBCorr_PathCount        705 // R/W	ITSDK_DATATYPE_IDXINT32; idx = 0 -> Global Corr else CorrShape
#define IRBG_PARAM_IRBcorr_SimpleEps        706 // R/W	ITSDK_DATATYPE_IDXSingle; idx = 0 -> Global Corr else CorrShape
#define IRBG_PARAM_IRBcorr_SimpleTau        707 // R/W	ITSDK_DATATYPE_IDXSingle; idx = 0 -> Global Corr else CorrShape
#define IRBG_PARAM_IRBcorr_SimpleEnvTemp	708 // R/W	ITSDK_DATATYPE_IDXSingle; idx = 0 -> Global Corr else CorrShape
#define IRBG_PARAM_IRBcorr_SimplePathTemp	709 // R/W	ITSDK_DATATYPE_IDXSingle; idx = 0 -> Global Corr else CorrShape; The “simple”-version sets PathCount to 1, ObjTau to 0, PathRho[0] to 0 and checked that the result of the sum calculation is everytime 1.

/// Camera – Measurement Control - Window Mode (full frame (FF) / half frame (HF) / quart frame (QF) / line scan (LS) / random frame (RF))
#define IRBG_PARAM_Sensor_Width             280 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Sensor_Height            281 // R ITSDK_DATATYPE_INT32

#define IRBG_PARAM_Frame_Width              294 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Frame_Height             295 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Frame_Offsetx            292 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Frame_Offsety            293 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Frame_FlipH              290 // R/W ITSDK_DATATYPE_INT32 as Boolean
#define IRBG_PARAM_Frame_FlipV              291 // R/W ITSDK_DATATYPE_INT32 as Boolean

#define IBRG_PARAM_Frame_BinningX           297 // R ITSDK_DATATYPE_INT32 binning factor X
#define IBRG_PARAM_Frame_BinningY           298 // R ITSDK_DATATYPE_INT32 binning factor Y
#define IRBG_PARAM_Frame_FirstValid         299 // R ITSDK_DATATYPE_IdxDoule; .Index: StreamIndex; .Value: timestamp of the first valid frame after calib changed. Compare it with result of irbgrab_mem_gettimestamp (see 4.5.6).
#define IRBG_PARAM_WindowMode_Prop          310 // R ITSDK_DATATYPE_WINDOWMODE
#define IRBG_PARAM_WindowMode_Idx           311 // R/W ITSDK_DATATYPE_INT32; results -1 if random frame is active
#define IRBG_PARAM_WindowMode_Count         312 // R ITSDK_DATATYPE_INT32

/// Camera – Measurement Control - Filter
#define IRBG_PARAM_Filter_Count             320 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Filter_PosIdx            321 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Filter_PosIdxLive        322 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Filter_Mode              323 // R ITSDK_DATATYPE_INT32 (see 5.4.10)

/// Camera – Measurement Control - Aperture
#define IRBG_PARAM_Aperture_Count           330 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Aperture_PosIdx          331 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Aperture_PosIdxLive      332 // R ITSDK_DATATYPE_INT32

/// Camera – Measurement Control - Integration time (so on multi integration time (MIT))
#define IRBG_PARAM_IntegTime                262 // R/W ITSDK_DATATYPE_IDXINT32 [µs]

/// Camera – Measurement Control - Framerate
#define IRBG_PARAM_Framerate_Hz             240 // R/W ITSDK_DATATYPE_SINGLE [Hz] or ITSDK_DATATYPE_IDXSINGLE with  Index=StreamIndex
#define IRBG_PARAM_Framerate_Max            241 // R ITSDK_DATATYPE_SINGLE [Hz]

/// Camera - Hardware Control
/// Camera - Hardware Control - Focus (motorized lenses only)
#define IRBG_PARAM_Focus_DeviceCount        460 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Focus_DeviceIndex        461 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_Focus_Init               462 // R ITSDK_DATATYPE_INT32; = DeviceIndex
#define IRBG_PARAM_Focus_DistRange          463 // R ITSDK_DATATYPE_SINGLE
#define IRBG_PARAM_Focus_PosRel             464 // R/W ITSDK_DATATYPE_SINGLE [0..100%]
#define IRBG_PARAM_Focus_PosRelSpeed        465 // R/W ITSDK_DATATYPE_SINGLE [0..100%]
#define IRBG_PARAM_Focus_PosDistWant        466 // W ITSDK_DATATYPE_SINGLE [m]; set distance
#define IRBG_PARAM_Focus_PosDistLive        467 // R ITSDK_DATATYPE_SINGLE [m]; get distance
#define IRBG_PARAM_Focus_MoveRel            468 // W ITSDK_DATATYPE_SINGLE [-1..0=Stopp..1]; set speed and direction
#define IRBG_PARAM_Focus_Auto               469 // W no parameter

/// Camera - Hardware Control - Zoom (hardware dependent)
#define IRBG_PARAM_Zoom_MoveRel             480 // W ITSDK_DATATYPE_SINGLE [ 100..0=Stopp..100]; set speed and direction; Notice: some devices supports several steps of speed only.
#define IRBG_PARAM_Zoom_FocalLen            481 // R/W ITSDK_DATATYPE_SINGLE; set the focal length [mm]
#define IRBG_PARAM_Zoom_FocalLenLive        482 // R ITSDK_DATATYPE_SINGLE; current position of the lens [mm]
#define IRBG_PARAM_Zoom_PosRel              484 // R/W ITSDK_DATATYPE_SINGLE [0..100%]

/// Camera - Hardware Control - Process-I/O (hardware dependent)
#define IRBG_PARAM_ProcIO_AnalogInCount         490 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_ProcIO_AnalogInActive        491 // R/W ITSDK_DATATYPE_IDXINT32 as Boolean
#define IRBG_PARAM_ProcIO_AnalogOutCount        492 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_ProcIO_AnalogOutChModeCnt	493 // R ITSDK_DATATYPE_IDXINT32
#define IRBG_PARAM_ProcIO_AnalogOutChModeName	494 // R ITSDK_DATATYPE_IdxString; .Index: AnalogOutChannel; .Value: Initialize with the index of the mode. If succeeded it results the name on this index.
#define IRBG_PARAM_ProcIO_AnalogOutChModeIdx	495 // R/W ITSDK_DATATYPE_IDXINT32
#define IRBG_PARAM_ProcIO_AnalogOutChFreq       496 // R/W ITSDK_DATATYPE_IDXSingle
#define IRBG_PARAM_ProcIO_AnalogOutChVolt       497 // R/W ITSDK_DATATYPE_IDXSingle



#define IRBG_PARAM_Trigger_Divider          372 // R/W ITSDK_DATATYPE_INT32

/// Camera - Hardware Control - Internal Trigger (Alarm Output)
#define IRBG_PARAM_TriggerImg_ValueItemCnt      357 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_ValueItem         358 // R ITSDK_DATATYPE_IDXString; index must be set
#define IRBG_PARAM_TriggerImg_ValueIdx          359 // R/W ITSDK_DATATYPE_INT32; = Index
#define IRBG_PARAM_TriggerImg_OperationItemCnt  360 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_OperationItem     361 // R ITSDK_DATATYPE_IDXString
#define IRBG_PARAM_TriggerImg_OperationIndex	362 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_Threshold         363 // R/W ITSDK_DATATYPE_SINGLE [K]
#define IRBG_PARAM_TriggerImg_LivePixelCount	364 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_LivePixelFast     365 // R/W ITSDK_DATATYPE_INT32 as Boolean
#define IRBG_PARAM_TriggerImg_SyncModeItemCnt	366 // R ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_SyncModeItem      367 // R ITSDK_DATATYPE_IDXString
#define IRBG_PARAM_TriggerImg_SyncModeIndex     368 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_Invert            369 // R/W ITSDK_DATATYPE_INT32 as Boolean
#define IRBG_PARAM_TriggerImg_DelayLow          370 // R/W ITSDK_DATATYPE_INT32
#define IRBG_PARAM_TriggerImg_DelayHigh         371 // R/W ITSDK_DATATYPE_INT32

/// Others
#define IRBG_PARAM_RemoteWindow             111 // W ITSDK_DATATYPE_INT32; (see 5.4.3 Library Window Constants)
#define IRBG_PARAM_SDK_RingBufSizeMax       182 // R/W ITSDK_DATATYPE_INT32; size of the internal buffer in the range of 10..4096 MB
#define IRBG_PARAM_DateTime                 400 // R ITSDK_DATATYPE_DOUBLE
#define IRBG_PARAM_DateTime_IRIG            401 // R ITSDK_DATATYPE_DOUBLE
#define IRBG_PARAM_SendCommand              231 // W ITSDK_DATATYPE_SENDCMD




class TIRBgrabLib 
{

private:

    typedef TITSDK_Ret(__CALLCONV *TProc_dll_version)(char *aDLLversion, int aMaxLen);
    typedef TITSDK_Ret(__CALLCONV *TProc_dll_init)();
    typedef TITSDK_Ret(__CALLCONV *TProc_dll_uninit)();
    typedef TITSDK_Ret(__CALLCONV *TProc_dll_isinit)(int *aInitCount);
    typedef TITSDK_Ret(__CALLCONV *TProc_dll_devicetypenames)(const char *aDeviceTypeNames,int aParamSize);

    TProc_dll_version		    FProc_dll_version;
    TProc_dll_init			    FProc_dll_init;
    TProc_dll_uninit	     	FProc_dll_uninit;
    TProc_dll_isinit		    FProc_dll_isinit;
    TProc_dll_devicetypenames   FProc_dll_devicetypenames;

    TITSDK_LibHandle FLibHandle;
    int	 	 FLibCounter;
    char     *FDeviceTypes[16];
    void NilProcs();

protected:
public:
    TIRBgrabLib();
    ~TIRBgrabLib();

    int DeviceCount();
    char* DeviceName(int aIndex);
    bool LibLoaded();

    TITSDK_ObjectHandler_IRBGrabMem FObjectHandler_Mem;
    TITSDK_ObjectHandler_IRBGrabDev FObjectHandler_Dev;

    bool LoadLib(const char *aLibFileName=NULL);
    bool UnloadLib();

    TIRBG_SaveStruct SaveStruct;
};

#endif // OIRBGRABDLL_H
