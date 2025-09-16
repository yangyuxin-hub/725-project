#include "oitsdk_objecthandler_mem.h"
#include "hitsdkconstants.h"

TITSDK_ObjectHandler_Mem::TITSDK_ObjectHandler_Mem()
{
  _itmemget = nullptr;

  _ITObjectFree = nullptr;
  _GetParam = nullptr;
  _SetParam = nullptr;
}



TITSDK_ObjectHandler_Mem::~TITSDK_ObjectHandler_Mem()
{
    _itmemget = nullptr;

    _ITObjectFree = nullptr;
    _GetParam = nullptr;
    _SetParam = nullptr;
}


bool TITSDK_ObjectHandler_Mem::Init(PITSDK_LibHandle aLibHandle)
{
  TITSDK_ObjectHandler::Init(aLibHandle);
  if (!LibHandle_IsValid()) {return false;}
  //
  ////set function pointer of parent object
  if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_itmemget),    "itmem_get"))      return false;
  if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_ITObjectFree),"itmem_free"))     return false;
  if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_GetParam),    "itmem_getparam")) return false;
  if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_SetParam),    "itmem_setparam")) return false;
  return true;
}



bool TITSDK_ObjectHandler_Mem::Mem_GetData(TITSDK_Handle aFileObject, PITSDK_Handle aMemObject, PITSDK_GetMemInfo aGetMemInfo)
{
    if (!aMemObject) {return false;}
    if (*aMemObject != 0){
        Mem_Free(aMemObject);
    }
    if (_itmemget == NULL) {return false;}
    TITSDK_Ret res = _itmemget(aFileObject, aMemObject, aGetMemInfo);
    FLastError = res;
    if (res != ITSDK_RET_SUCCESS) {return false;}
    if (*aMemObject == 0){return false;}
    return true;
}

TITSDK_Ret TITSDK_ObjectHandler_Mem::Mem_Free(PITSDK_Handle aMemObject)
{
    return ITObject_Free(aMemObject);
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Image_MainType(TITSDK_Handle aMemObject, PITSDK_Int32 aMainType)
{
    *aMainType = 0;
    TITSDK_Ret retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_Image_MainType, aMainType);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Image_DataType(TITSDK_Handle aMemObject, PITSDK_Int32 aImageDataType)
{
    *aImageDataType = 0;
    TITSDK_Ret retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_Image_DataType, aImageDataType);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Image_Compression(TITSDK_Handle aMemObject, PITSDK_Int32 aCompression)
{
    *aCompression = 0;
    TITSDK_Ret retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_Compression, aCompression);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Image_Dimension(TITSDK_Handle aMemObject, PITSDK_Int32 aFrameWidth, PITSDK_Int32 aFrameHeight)
{
    *aFrameWidth = 0;
    *aFrameHeight = 0;
    TITSDK_Ret retval = 0;
    retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_FrameWidth, aFrameWidth);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_FrameHeight, aFrameHeight);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Image_Content(TITSDK_Handle aMemObject, PITSDK_Pointer aContent)
{
    TITSDK_Ret retval = GetParam_Pointer(aMemObject, ITSDK_ParamMem_Image_Content, aContent);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Time_TimeStamp(TITSDK_Handle aMemObject, PITSDK_DateTime aTimeStamp)
{
    TITSDK_Ret retval = GetParam(aMemObject, ITSDK_ParamMem_TimeStamp, aTimeStamp, ITSDK_DATATYPE_DateTime);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Time_TimeStampMS(TITSDK_Handle aMemObject, PITSDK_Double aTimeStamp)
{
    *aTimeStamp = 0;
    TITSDK_Ret retval = GetParam_Double(aMemObject, ITSDK_ParamMem_TimeStampMS, aTimeStamp);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Time_Triggered(TITSDK_Handle aMemObject, bool *aTriggered, PITSDK_Double aTimeStampMS)
{
    *aTriggered = false;
    *aTimeStampMS = -1;
    TITSDK_Int32 ii = 0;
    TITSDK_Ret retval = 0;
    retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_Triggered, &ii);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    *aTriggered = (ii != 0);
    if (!*aTriggered) {return true;}
    retval = GetParam_Double(aMemObject, ITSDK_ParamMem_Trigger_TimeStampMS, aTimeStampMS);
    if (retval != ITSDK_RET_SUCCESS) {*aTimeStampMS = -1;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Calib_Name(TITSDK_Handle aMemObject, std::string* aCalibName)
{

    TITSDK_Ret retval = 0;
    aCalibName->resize(128);
    *aCalibName = "";
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Calib_Name, aCalibName);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Calib_Date(TITSDK_Handle aMemObject, std::string* aCalibDate)
{

    TITSDK_Ret retval = 0;
    aCalibDate->resize(128);
    *aCalibDate = "";
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Calib_Date, aCalibDate);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Calib_Range(TITSDK_Handle aMemObject, PITSDK_Single aCalibMinK, PITSDK_Single aCalibMaxK)
{
    *aCalibMinK = 0;
    *aCalibMaxK = 0;
    TITSDK_Ret retval = 0;
    retval = GetParam_Single(aMemObject, ITSDK_ParamMem_Calib_MinK, aCalibMinK);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    retval = GetParam_Single(aMemObject, ITSDK_ParamMem_Calib_MaxK, aCalibMaxK);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Calib_IntegTimeMS(TITSDK_Handle aMemObject, PITSDK_Single aIntegTimeMS)
{
    *aIntegTimeMS = 0;
    TITSDK_Ret retval = 0;
    retval = GetParam_Single(aMemObject, ITSDK_ParamMem_IntegTimeMS, aIntegTimeMS);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Camera_Name        (TITSDK_Handle aMemObject, std::string* aCamName)
{
    aCamName->resize(128);
    *aCamName = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Camera_Name, aCamName);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Camera_Spec        (TITSDK_Handle aMemObject, std::string* aCamSpec)
{
    aCamSpec->resize(128);
    *aCamSpec = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Camera_Spec, aCamSpec);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Camera_SerialNo    (TITSDK_Handle aMemObject, std::string* aCamSN)
{
    aCamSN->resize(128);
    *aCamSN = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Camera_SerialNo, aCamSN);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}


bool TITSDK_ObjectHandler_Mem::Mem_Get_Lens_Name        (TITSDK_Handle aMemObject, std::string* aLensName)
{
    aLensName->resize(128);
    *aLensName = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Name, aLensName);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Lens_Spec        (TITSDK_Handle aMemObject, std::string* aLensSpec)
{
    aLensSpec->resize(128);
    *aLensSpec = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Spec, aLensSpec);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Lens_SerialNo    (TITSDK_Handle aMemObject, std::string* aLensSN)
{
    aLensSN->resize(128);
    *aLensSN = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_SerialNo, aLensSN);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Aperture_Name        (TITSDK_Handle aMemObject, std::string* aApertureName)
{
    aApertureName->resize(128);
    *aApertureName = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Name, aApertureName);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Aperture_Spec        (TITSDK_Handle aMemObject, std::string* aApertureSpec)
{
    aApertureSpec->resize(128);
    *aApertureSpec = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Spec, aApertureSpec);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Aperture_SerialNo    (TITSDK_Handle aMemObject, std::string* aApertureSN)
{
    aApertureSN->resize(128);
    *aApertureSN = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_SerialNo, aApertureSN);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Filter_Name        (TITSDK_Handle aMemObject, std::string* aFilterName)
{
    aFilterName->resize(128);
    *aFilterName = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Name, aFilterName);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Filter_Spec        (TITSDK_Handle aMemObject, std::string* aFilterSpec)
{
    aFilterSpec->resize(128);
    *aFilterSpec = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Spec, aFilterSpec);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Filter_SerialNo    (TITSDK_Handle aMemObject, std::string* aFilterSN)
{
    aFilterSN->resize(128);
    *aFilterSN = "";
    TITSDK_Ret retval = 0;
    retval = GetParam_String(aMemObject, ITSDK_ParamMem_Module_Lens_Spec, aFilterSN);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Zoom_FocalLength(TITSDK_Handle aMemObject, PITSDK_Single aFocalLength)
{
    *aFocalLength = 0;
    TITSDK_Ret retval = 0;
    retval = GetParam_Single(aMemObject, ITSDK_ParamMem_ZoomFocalLength, aFocalLength);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Representation_Range(TITSDK_Handle aMemObject, PITSDK_Single aMinK, PITSDK_Single aMaxK)
{
    *aMinK = 0;
    *aMaxK = 0;
    TITSDK_Ret retval = 0;
    retval = GetParam_Single(aMemObject, ITSDK_ParamMem_Representation_From, aMinK);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    retval = GetParam_Single(aMemObject, ITSDK_ParamMem_Representation_Till, aMaxK);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_Stream_Index  (TITSDK_Handle aMemObject, PITSDK_Int32 aStreamIndex)
{
    *aStreamIndex = 0;
    TITSDK_Ret retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_Stream_Index, aStreamIndex);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_SubStream_Count  (TITSDK_Handle aMemObject, PITSDK_Int32 aSubStreamCount)
{
    *aSubStreamCount = 0;
    TITSDK_Ret retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_SubStream_Count, aSubStreamCount);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}

bool TITSDK_ObjectHandler_Mem::Mem_Get_SubStream_Index  (TITSDK_Handle aMemObject, PITSDK_Int32 aSubStreamIndex)
{
    *aSubStreamIndex = 0;
    TITSDK_Ret retval = GetParam_Int32(aMemObject, ITSDK_ParamMem_SubStream_Index, aSubStreamIndex);
    if (retval != ITSDK_RET_SUCCESS) {return false;}
    return true;
}



