#ifndef _ITSDK_OBJECTHANDLER_
#define _ITSDK_OBJECTHANDLER_

#include "hitsdkide.h"
#include "hitsdktypes.h"
#include <string>

#pragma once

namespace ITSDK_Lib {

}




class TITSDK_ObjectHandler
{
protected:
    PITSDK_LibHandle	FLibHandle;
    TITSDK_Ret          FLastError;


	TITSDK_FUNC_GETSET  _GetParam;
	TITSDK_FUNC_GETSET  _SetParam;
	TITSDK_FUNC_FREE	_ITObjectFree;

public:
    TITSDK_ObjectHandler();
    ~TITSDK_ObjectHandler();

    bool Init(PITSDK_LibHandle aLibHandle);
    void Deinit();
    bool LibHandle_IsValid(void);

    TITSDK_Ret LastError(void);

    bool Lib_GetFunc(TITSDK_LibHandle aHandle, TLibProcAddr *aFunc, const char *aName);


	TITSDK_Ret ITObject_Free(PITSDK_Handle aOjectHandle);

	//---------------------------------------------------------------
	// get param
	//---------------------------------------------------------------   
    TITSDK_Ret GetParam(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Pointer aDataPtr, TITSDK_UInt32 aDataType);

	TITSDK_Ret GetParam_Handle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Handle  aValue);
	TITSDK_Ret GetParam_Pointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Pointer aValue);
    TITSDK_Ret GetParam_Bool(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, bool *aValue);
	TITSDK_Ret GetParam_Int8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int8	 aValue);
	TITSDK_Ret GetParam_Int16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int16	 aValue);
	TITSDK_Ret GetParam_Int32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int32   aValue);
	TITSDK_Ret GetParam_Int64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int64   aValue);
	TITSDK_Ret GetParam_UInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt8   aValue);
	TITSDK_Ret GetParam_UInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt16  aValue);
	TITSDK_Ret GetParam_UInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt32  aValue);
	TITSDK_Ret GetParam_UInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt64  aValue);
	TITSDK_Ret GetParam_Single(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Single  aValue);
	TITSDK_Ret GetParam_Double(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Double  aValue);
    TITSDK_Ret GetParam_String(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, std::string *aValue);

    TITSDK_Ret GetParam_IdxHandle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Handle  aValue);
    TITSDK_Ret GetParam_IdxPointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Pointer aValue);
    TITSDK_Ret GetParam_IdxInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int8	 aValue);
    TITSDK_Ret GetParam_IdxInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int16	 aValue);
    TITSDK_Ret GetParam_IdxInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int32   aValue);
    TITSDK_Ret GetParam_IdxInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int64   aValue);
    TITSDK_Ret GetParam_IdxUInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt8   aValue);
    TITSDK_Ret GetParam_IdxUInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt16  aValue);
    TITSDK_Ret GetParam_IdxUInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt32  aValue);
    TITSDK_Ret GetParam_IdxUInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt64  aValue);
    TITSDK_Ret GetParam_IdxSingle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Single  aValue);
    TITSDK_Ret GetParam_IdxDouble(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Double  aValue);
    TITSDK_Ret GetParam_IdxString(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, std::string *aValue);

	//---------------------------------------------------------------
	// set param
	//--------------------------------------------------------------- 
	TITSDK_Ret SetParam(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Pointer aDataPtr, TITSDK_UInt32 aDataType);

	TITSDK_Ret SetParam_Handle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Handle  aValue);
	TITSDK_Ret SetParam_Pointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Pointer aValue);
    TITSDK_Ret SetParam_Bool(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, bool *aValue);
	TITSDK_Ret SetParam_Int8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int8	 aValue);
	TITSDK_Ret SetParam_Int16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int16	 aValue);
	TITSDK_Ret SetParam_Int32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int32   aValue);
	TITSDK_Ret SetParam_Int64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int64   aValue);
	TITSDK_Ret SetParam_UInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt8   aValue);
	TITSDK_Ret SetParam_UInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt16  aValue);
	TITSDK_Ret SetParam_UInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt32  aValue);
	TITSDK_Ret SetParam_UInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt64  aValue);
	TITSDK_Ret SetParam_Single(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Single  aValue);
	TITSDK_Ret SetParam_Double(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Double  aValue);
    TITSDK_Ret SetParam_String(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, std::string *aValue);

    TITSDK_Ret SetParam_IdxHandle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Handle  aValue);
    TITSDK_Ret SetParam_IdxPointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Pointer aValue);
    TITSDK_Ret SetParam_IdxInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int8	 aValue);
    TITSDK_Ret SetParam_IdxInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int16	 aValue);
    TITSDK_Ret SetParam_IdxInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int32   aValue);
    TITSDK_Ret SetParam_IdxInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int64   aValue);
    TITSDK_Ret SetParam_IdxUInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt8   aValue);
    TITSDK_Ret SetParam_IdxUInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt16  aValue);
    TITSDK_Ret SetParam_IdxUInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt32  aValue);
    TITSDK_Ret SetParam_IdxUInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt64  aValue);
    TITSDK_Ret SetParam_IdxSingle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Single  aValue);
    TITSDK_Ret SetParam_IdxDouble(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Double  aValue);
    TITSDK_Ret SetParam_IdxString(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, std::string *aValue);

    TITSDK_Ret SetParam_2Int32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aValue1, TITSDK_Int32   aValue2);
};




#endif /* _ITSDK_OBJECTHANDLER_ */
