#ifndef OITSDK_OBJECTHANDLER_IRBGRABMEM_H
#define OITSDK_OBJECTHANDLER_IRBGRABMEM_H

#include "oitsdk_objecthandler_mem.h"

#pragma once

class TITSDK_ObjectHandler_IRBGrabMem : public TITSDK_ObjectHandler_Mem
{
    private:
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getdimension)(TITSDK_Handle aMemHandle, uint32_t *aWidth, uint32_t *aHeight, uint32_t *aPixelDataType);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getdataptr)(TITSDK_Handle aMemHandle, void **aDataPtr, int *aDataByteSize);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getheaderptr)(TITSDK_Handle aMemHandle, void **aHeaderPtr, int *aHeaderByteSize);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getirvalues)(TITSDK_Handle aMemHandle, float *aTempMin, float *aTempMax, float *aTempAvg, float *aStdDev);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getdigitalvalues)(TITSDK_Handle aMemHandle, uint16_t *aDigValMin, uint16_t *aDigValMax);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_gettimestamp)(TITSDK_Handle aMemHandle, double *aTimeStamp);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getinfo)(TITSDK_Handle aMemHandle, struct TIRBG_MemInfo *aMemInfo);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_getheaderinfo)(TITSDK_Handle aMemHandle, struct TIRBG_HeaderInfo *aMemInfo);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_savetofile)(TITSDK_Handle aMemHandle, struct TIRBG_SaveStruct *aSaveStruct);
        typedef TITSDK_Ret(__CALLCONV *TProc_mem_free)(TITSDK_Handle *aMemHandle);

        TProc_mem_getdimension	    FProc_mem_getdimension;
        TProc_mem_getdataptr	    FProc_mem_getdataptr;
        TProc_mem_getheaderptr  	FProc_mem_getheaderptr;
        TProc_mem_getirvalues  	    FProc_mem_getirvalues;
        TProc_mem_getdigitalvalues	FProc_mem_getdigitalvalues;
        TProc_mem_gettimestamp	    FProc_mem_gettimestamp;
        TProc_mem_getinfo		    FProc_mem_getinfo;
        TProc_mem_getheaderinfo	    FProc_mem_getheaderinfo;
        TProc_mem_savetofile	    FProc_mem_savetofile;

    protected:
    public:
        TITSDK_ObjectHandler_IRBGrabMem();
        ~TITSDK_ObjectHandler_IRBGrabMem();
        bool Init(PITSDK_LibHandle aLibHandle);
        void Deinit();

        TITSDK_Ret mem_GetDimension(TITSDK_Handle aMemHandle, TITSDK_UInt32* aWidth, TITSDK_UInt32* aHeight, TITSDK_UInt32* aPixelDataType);
        TITSDK_Ret mem_GetDataPtr(TITSDK_Handle aMemHandle, TITSDK_Pointer* aDataPtr, TITSDK_Int32* aDataByteSize);
        TITSDK_Ret mem_GetHeaderPtr(TITSDK_Handle aMemHandle, void **aHeaderPtr, int *aHeaderByteSize);
        TITSDK_Ret mem_GetIRValues(TITSDK_Handle aMemHandle, float *aTempMin, float *aTempMax, float *aTempAvg, float *aStdDev);
        TITSDK_Ret mem_GetDigitalValues(TITSDK_Handle aMemHandle, uint16_t *aDigValMin, uint16_t *aDigValMax);
        TITSDK_Ret mem_GetTimestamp(TITSDK_Handle aMemHandle, double *aTimeStamp);
        TITSDK_Ret mem_GetInfo(TITSDK_Handle aMemHandle, TIRBG_MemInfo *aMemInfo);
        TITSDK_Ret mem_GetHeaderInfo(TITSDK_Handle aMemHandle, TIRBG_HeaderInfo *aHeaderInfo);
        TITSDK_Ret mem_SaveToFile(TITSDK_Handle aMemHandle, TIRBG_SaveStruct *aSaveStruct);
};

#endif // OITSDK_OBJECTHANDLER_IRBGRABMEM_H
