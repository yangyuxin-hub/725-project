
#include "oitsdk_objecthandler_irbgrabmem.h"
#include "hitsdkconstants.h"




TITSDK_ObjectHandler_IRBGrabMem::TITSDK_ObjectHandler_IRBGrabMem()
{


}

TITSDK_ObjectHandler_IRBGrabMem::~TITSDK_ObjectHandler_IRBGrabMem()
{

}

bool TITSDK_ObjectHandler_IRBGrabMem::Init(PITSDK_LibHandle aLibHandle)
{
    TITSDK_ObjectHandler_Mem::Init(aLibHandle);
    if (!LibHandle_IsValid()) {return false;}

    //
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getdimension), "irbgrab_mem_getdimension")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getdataptr), "irbgrab_mem_getdataptr")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getheaderptr), "irbgrab_mem_getheaderptr")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getirvalues), "irbgrab_mem_getirvalues")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getdigitalvalues), "irbgrab_mem_getdigitalvalues")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_gettimestamp), "irbgrab_mem_gettimestamp")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getinfo), "irbgrab_mem_getinfo")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_getheaderinfo), "irbgrab_mem_getheaderInfo")) return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&FProc_mem_savetofile), "irbgrab_mem_savetofile")) return false;

    ////set function pointer of parent object
    //if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_itmemget),    "itmem_get"))      return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_ITObjectFree),"irbgrab_mem_free"))     return false;
    if (!Lib_GetFunc(*FLibHandle, (TLibProcAddr*)(&_GetParam),    "irbgrab_mem_getparam")) return false;
    return true;

}

void TITSDK_ObjectHandler_IRBGrabMem::Deinit()
{


    FProc_mem_getdimension = NULL;
    FProc_mem_getdataptr = NULL;
    FProc_mem_getheaderptr = NULL;
    FProc_mem_getirvalues = NULL;
    FProc_mem_getdigitalvalues = NULL;
    FProc_mem_gettimestamp = NULL;
    FProc_mem_getinfo = NULL;
    FProc_mem_getheaderinfo = NULL;

    TITSDK_ObjectHandler_Mem::Deinit();
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetDimension(TITSDK_Handle aMemHandle, TITSDK_UInt32 *aWidth, TITSDK_UInt32 *aHeight, TITSDK_UInt32 *aPixelDataType)
{
    if (!FProc_mem_getdimension) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getdimension(aMemHandle, aWidth, aHeight, aPixelDataType);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetDataPtr(TITSDK_Handle aMemHandle, TITSDK_Pointer *aDataPtr, TITSDK_Int32 *aDataByteSize)
{
    if (!FProc_mem_getdataptr) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getdataptr(aMemHandle, aDataPtr, aDataByteSize);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetHeaderPtr(TITSDK_Handle aMemHandle, void **aHeaderPtr, int *aHeaderByteSize)
{
    if (!FProc_mem_getheaderptr) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getheaderptr(aMemHandle, aHeaderPtr, aHeaderByteSize);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetIRValues(TITSDK_Handle aMemHandle, float *aTempMin, float *aTempMax, float *aTempAvg, float *aStdDev)
{
    if (!FProc_mem_getirvalues) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getirvalues(aMemHandle, aTempMin, aTempMax, aTempAvg, aStdDev);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetDigitalValues(TITSDK_Handle aMemHandle, uint16_t *aDigValMin, uint16_t *aDigValMax)
{
    if (!FProc_mem_getdigitalvalues) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getdigitalvalues(aMemHandle, aDigValMin, aDigValMax);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetTimestamp(TITSDK_Handle aMemHandle, double *aTimeStamp)
{
    if (!FProc_mem_gettimestamp) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_gettimestamp(aMemHandle, aTimeStamp);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetInfo(TITSDK_Handle aMemHandle, struct TIRBG_MemInfo *aMemInfo)
{
    if (!FProc_mem_getinfo) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getinfo(aMemHandle, aMemInfo);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_GetHeaderInfo(TITSDK_Handle aMemHandle, struct TIRBG_HeaderInfo *aHeaderInfo)
{
    if (!FProc_mem_getheaderinfo) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_getheaderinfo(aMemHandle, aHeaderInfo);
}

TITSDK_Ret TITSDK_ObjectHandler_IRBGrabMem::mem_SaveToFile(TITSDK_Handle aMemHandle, struct TIRBG_SaveStruct *aSaveStruct)
{
    if (!FProc_mem_savetofile) return ITSDK_RET_ERR_GENERIC;
    return FProc_mem_savetofile(aMemHandle, aSaveStruct);
}

