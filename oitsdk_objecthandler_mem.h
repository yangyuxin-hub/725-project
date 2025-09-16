#ifndef OITSDK_OBJECTHANDLER_MEM_H
#define OITSDK_OBJECTHANDLER_MEM_H

#pragma once

#include "oitsdk_objecthandler.h"

//file properties
#define ITSDK_ParamMem_File_Name             42
#define ITSDK_ParamMem_Frame_Index           11
#define ITSDK_ParamMem_Frame_ID              12
#define ITSDK_ParamMem_ID_Entry              31

//properties of format and access
#define ITSDK_ParamMem_Image_DataPointer        20
#define ITSDK_ParamMem_Image_CharacterSize      22
#define ITSDK_ParamMem_Image_CharacterFormat    23
#define ITSDK_ParamMem_Image_DataSize           24
#define ITSDK_ParamMem_Image_MainType           25
#define ITSDK_ParamMem_Image_SubType            26
#define ITSDK_ParamMem_Image_DataType           27
#define ITSDK_ParamMem_Image_Content            28


//modules
#define ITSDK_ParamMem_Module_Camera_Name        50
#define ITSDK_ParamMem_Module_Camera_Spec        51
#define ITSDK_ParamMem_Module_Camera_SerialNo    52

#define ITSDK_ParamMem_Module_Lens_Name          60
#define ITSDK_ParamMem_Module_Lens_Spec          61
#define ITSDK_ParamMem_Module_Lens_SerialNo      62

#define ITSDK_ParamMem_Module_Filter_Name        70
#define ITSDK_ParamMem_Module_Filter_Spec        71
#define ITSDK_ParamMem_Module_Filter_SerialNo    72
#define ITSDK_ParamMem_Module_Filter_Position   322

#define ITSDK_ParamMem_Module_Aperture_Name      80
#define ITSDK_ParamMem_Module_Aperture_Spec      81
#define ITSDK_ParamMem_Module_Aperture_SerialNo  82

//calibration
#define ITSDK_ParamMem_Calib_Date        120
#define ITSDK_ParamMem_Calib_Name        121
#define ITSDK_ParamMem_Calib_MinK        124
#define ITSDK_ParamMem_Calib_MaxK        125

#define ITSDK_ParamMem_Calib_TempValCnt        150
#define ITSDK_ParamMem_Calib_TempValIdx        151


#define ITSDK_ParamMem_Temperature_Value  213
#define ITSDK_ParamMem_Temperature_Name   214
#define ITSDK_ParamMem_CameraTemp         218

#define ITSDK_ParamMem_Compression        230

#define ITSDK_ParamMem_IntegTimeMS        262

#define ITSDK_ParamMem_FrameWidth             294
#define ITSDK_ParamMem_FrameHeight            295

#define ITSDK_ParamMem_Triggered            373
#define ITSDK_ParamMem_Trigger_TimeStampMS  374

#define ITSDK_ParamMem_TimeStamp          400
#define ITSDK_ParamMem_TimeStampMS        402

#define ITSDK_ParamMem_ZoomFocalLength  482

#define ITSDK_ParamMem_ImageComment           530

#define ITSDK_ParamMem_Stream_Index     226
#define ITSDK_ParamMem_SubStream_Count  830
#define ITSDK_ParamMem_SubStream_Index  831

//radiometric correction
#define ITSDK_IRSource_Corr_SimpleEps         556
#define ITSDK_IRSource_Corr_SimpleTau         557
#define ITSDK_IRSource_Corr_SimpleEnvTemp     558
#define ITSDK_IRSource_Corr_SimplePathTemp    559
#define ITSDK_IRSource_Corr_Humidity          560
#define ITSDK_IRSource_Corr_Distance          561

#define ITSDK_ParamMem_Representation_Till          561
#define ITSDK_ParamMem_Representation_From          561






class TITSDK_ObjectHandler_Mem : public TITSDK_ObjectHandler
{
private:
    typedef TITSDK_Ret(__CALLCONV* TProc_itmemget)(TITSDK_Handle aFileObject, PITSDK_Handle aMemObject, PITSDK_GetMemInfo aGetDataInfo);

protected:
    TProc_itmemget      _itmemget = NULL;

//object function
public:
    ~TITSDK_ObjectHandler_Mem();
    TITSDK_ObjectHandler_Mem();

    bool Init(PITSDK_LibHandle aLibHandle);


//library functions
public:
    bool Mem_GetData(TITSDK_Handle aFileObject, PITSDK_Handle aMemObject, PITSDK_GetMemInfo aGetMemInfo);
    TITSDK_Ret Mem_Free(PITSDK_Handle aMemObject);

//abstracted GetParam functions with specified parameter
public:
    /*image information*/
    bool Mem_Get_Image_MainType     (TITSDK_Handle aMemObject, PITSDK_Int32 aMainType);
    bool Mem_Get_Image_DataType     (TITSDK_Handle aMemObject, PITSDK_Int32 aImageDataType);
    bool Mem_Get_Image_Compression  (TITSDK_Handle aMemObject, PITSDK_Int32 aCompression);
    bool Mem_Get_Image_Dimension    (TITSDK_Handle aMemObject, PITSDK_Int32 aFrameWidth, PITSDK_Int32 aFrameHeight);
    bool Mem_Get_Image_Content      (TITSDK_Handle aMemObject, PITSDK_Pointer aContent);

    /*time information*/
    bool Mem_Get_Time_TimeStamp     (TITSDK_Handle aMemObject, PITSDK_DateTime aTimeStamp);
    bool Mem_Get_Time_TimeStampMS   (TITSDK_Handle aMemObject, PITSDK_Double aTimeStamp);
    bool Mem_Get_Time_Triggered      (TITSDK_Handle aMemObject, bool *aTriggered, PITSDK_Double aTimeStampMS);

    /*calibration information*/
    bool Mem_Get_Calib_Name         (TITSDK_Handle aMemObject, std::string* aCalibName);
    bool Mem_Get_Calib_Date         (TITSDK_Handle aMemObject, std::string*  aCalibDate);
    bool Mem_Get_Calib_Range        (TITSDK_Handle aMemObject, PITSDK_Single aCalibMinK, PITSDK_Single aCalibMaxK);
    bool Mem_Get_Calib_IntegTimeMS  (TITSDK_Handle aMemObject, PITSDK_Single aIntegTimeMS);

    /*camera information*/
    bool Mem_Get_Camera_Name        (TITSDK_Handle aMemObject, std::string* aCamName);
    bool Mem_Get_Camera_Spec        (TITSDK_Handle aMemObject, std::string* aCamSpec);
    bool Mem_Get_Camera_SerialNo    (TITSDK_Handle aMemObject, std::string* aCamSN);

    /*lens information*/
    bool Mem_Get_Lens_Name        (TITSDK_Handle aMemObject, std::string* aLensName);
    bool Mem_Get_Lens_Spec        (TITSDK_Handle aMemObject, std::string* aLensSpec);
    bool Mem_Get_Lens_SerialNo    (TITSDK_Handle aMemObject, std::string* aLensSN);

    /*aperture information*/
    bool Mem_Get_Aperture_Name        (TITSDK_Handle aMemObject, std::string* aApertureName);
    bool Mem_Get_Aperture_Spec        (TITSDK_Handle aMemObject, std::string* aApertureSpec);
    bool Mem_Get_Aperture_SerialNo    (TITSDK_Handle aMemObject, std::string* aApertureSN);

    /*aperture information*/
    bool Mem_Get_Filter_Name        (TITSDK_Handle aMemObject, std::string* aFilterName);
    bool Mem_Get_Filter_Spec        (TITSDK_Handle aMemObject, std::string* aFilterSpec);
    bool Mem_Get_Filter_SerialNo    (TITSDK_Handle aMemObject, std::string* aFilterSN);

    bool Mem_Get_Zoom_FocalLength(TITSDK_Handle aMemObject, PITSDK_Single aFocalLength);

    bool Mem_Get_Representation_Range(TITSDK_Handle aMemObject, PITSDK_Single aMinK, PITSDK_Single aMaxK);

    bool Mem_Get_Stream_Index  (TITSDK_Handle aMemObject, PITSDK_Int32 aStreamIndex);
    bool Mem_Get_SubStream_Count  (TITSDK_Handle aMemObject, PITSDK_Int32 aSubStreamCount);
    bool Mem_Get_SubStream_Index  (TITSDK_Handle aMemObject, PITSDK_Int32 aSubStreamIndex);
};

#endif // OITSDK_OBJECTHANDLER_MEM_H
