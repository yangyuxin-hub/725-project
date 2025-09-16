//#include "pch.h"
#include "hitsdktypes.h"
#include "hitsdkconstants.h"
#include "oitsdk_objecthandler.h"
#include <string>



TITSDK_ObjectHandler::TITSDK_ObjectHandler()
{
  FLibHandle = nullptr;

  _GetParam = nullptr;
  _SetParam = nullptr;
  _ITObjectFree = nullptr;
}



TITSDK_ObjectHandler::~TITSDK_ObjectHandler()
{
	_GetParam = nullptr;
	_SetParam = nullptr;
	_ITObjectFree = nullptr;

}

bool TITSDK_ObjectHandler::Lib_GetFunc(TITSDK_LibHandle aHandle, TLibProcAddr *aFunc, const char *aName)
{
    #ifdef ITSDK_OS_UNIX
    TLibProcAddr Func = dlsym(aHandle, aName);
    #else

    #ifdef ITSDK_OS_WINDOWS
    TLibProcAddr Func = GetProcAddress(aHandle,aName);
    #endif
    #endif

    if (!Func) return false;
    if (aFunc == NULL) return false;
    *aFunc = Func;
    return true;
}

bool TITSDK_ObjectHandler::Init(PITSDK_LibHandle aLibHandle)
{
  FLibHandle = aLibHandle;
  return true;
}

void TITSDK_ObjectHandler::Deinit()
{
    _GetParam = nullptr;
    _SetParam = nullptr;
    _ITObjectFree = nullptr;

    FLibHandle = nullptr;
}

bool TITSDK_ObjectHandler::LibHandle_IsValid()
{
    if (FLibHandle == nullptr) {return false;}
    if (*FLibHandle == 0) {return false;}
    return true;
}

TITSDK_Ret TITSDK_ObjectHandler::LastError(void)
{
    return FLastError;
}

TITSDK_Ret TITSDK_ObjectHandler::ITObject_Free(PITSDK_Handle aOjectHandle)
{
	TITSDK_Ret retval = 0;
	if (_ITObjectFree != NULL)
	{
		retval = _ITObjectFree(aOjectHandle);
	}
	return retval;
}

//---------------------------------------------------------------
// get param
//---------------------------------------------------------------   


TITSDK_Ret TITSDK_ObjectHandler::GetParam(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Pointer aDataPtr, TITSDK_UInt32 aDataType)
{
	TITSDK_Ret retval = 0;
	if (_GetParam != NULL)
	{
		retval = _GetParam(aOjectHandle, aWhat, aDataPtr, aDataType);
	}
    FLastError = retval;
	return retval;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Handle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Handle  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_HANDLE);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Pointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Pointer aValue)
{
    return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_HANDLE);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Bool(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, bool *aValue)
{
    if (aValue == nullptr)  {return 0;}
    TITSDK_Int32 i32;
    if (!*aValue) {i32 = 0;}
    else {i32 = 1;}
    TITSDK_Ret ret = GetParam_Int32(aOjectHandle, aWhat, &i32);
    return (ret == ITSDK_RET_SUCCESS);
    *aValue = (i32 != 0);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Int8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int8	  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT8);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Int16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int16	  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT16);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Int32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int32   aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT32);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Int64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int64   aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT64);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_UInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt8   aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT8);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_UInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt16  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT16);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_UInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt32  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT32);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_UInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt64  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT64);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Single(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Single  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_SINGLE);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_Double(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Double  aValue)
{
	return GetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_DOUBLE);
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_String(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, std::string *aValue)
{
    TITSDK_String itstr;
    itstr.Text = aValue->data();
    itstr.Len = aValue->length();
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &itstr, ITSDK_DATATYPE_STRING);
    if (iret == ITSDK_RET_SUCCESS)
        {aValue->resize(itstr.Len);}
    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxHandle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Handle aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxHandle idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXHANDLE);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxPointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Pointer aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxPointer idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXPOINTER);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int8 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt8 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT8);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int16 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt16 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT16);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int32 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt32 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT32);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int64 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt64 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT64);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxUInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt8 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt8 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT8);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxUInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt16 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt16 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT16);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxUInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt32 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt32 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT32);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxUInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt64 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt64 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT64);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxSingle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Single aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxSingle idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXSingle);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxDouble(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Double aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxDouble idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXDouble);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::GetParam_IdxString(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, std::string *aValue)
{
	TITSDK_IdxString itidxstr;
	itidxstr.Index = aIndex;
    itidxstr.Value.Text = aValue->data();
    itidxstr.Value.Len = aValue->capacity();
    TITSDK_Ret iret = GetParam(aOjectHandle, aWhat, &itidxstr, ITSDK_DATATYPE_IDXString);
    if (iret == ITSDK_RET_SUCCESS)
        {aValue->resize(itidxstr.Value.Len);}
    return iret;
}


//---------------------------------------------------------------
// set param
//--------------------------------------------------------------- 

TITSDK_Ret TITSDK_ObjectHandler::SetParam(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Pointer aDataPtr, TITSDK_UInt32 aDataType)
{
	TITSDK_Ret retval = 0;
	if (_SetParam != NULL)
	{
		retval = _SetParam(aOjectHandle, aWhat, aDataPtr, aDataType);
	}
    FLastError = retval;
	return retval;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Handle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Handle  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_HANDLE);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Pointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Pointer aValue)
{
    return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_HANDLE);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Bool(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, bool *aValue)
{
    if (aValue == nullptr)  {return 0;}
    TITSDK_Int32 i32;
    if (!*aValue) {i32 = 0;}
    else {i32 = 1;}
    TITSDK_Ret ret = SetParam_Int32(aOjectHandle, aWhat, &i32);
    return (ret == ITSDK_RET_SUCCESS);
    *aValue = (i32 != 0);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Int8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int8	  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT8);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Int16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int16	  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT16);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Int32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int32   aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT32);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Int64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Int64   aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_INT64);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_UInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt8   aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT8);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_UInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt16  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT16);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_UInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt32  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT32);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_UInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_UInt64  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_UINT64);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Single(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Single  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_SINGLE);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_Double(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, PITSDK_Double  aValue)
{
	return SetParam(aOjectHandle, aWhat, aValue, ITSDK_DATATYPE_DOUBLE);
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_String(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, std::string *aValue)
{
	TITSDK_String itstr;
    itstr.Text = aValue->data();
    itstr.Len = aValue->length();
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &itstr, ITSDK_DATATYPE_STRING);
    if (iret == ITSDK_RET_SUCCESS)
        {aValue->resize(itstr.Len);}
    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxHandle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Handle aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxHandle idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXHANDLE);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxPointer(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Pointer aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxPointer idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXPOINTER);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int8 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt8 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT8);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int16 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt16 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT16);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int32 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt32 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT32);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Int64 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxInt64 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXINT64);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxUInt8(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt8 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt8 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT8);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxUInt16(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt16 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt16 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT16);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxUInt32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt32 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt32 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT32);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxUInt64(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_UInt64 aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxUInt64 idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXUINT64);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxSingle(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Single aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxSingle idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXSingle);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxDouble(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, PITSDK_Double aValue)
{
    if (aValue == nullptr) {return 0;}

    TITSDK_IdxDouble idxval;
    idxval.Index = aIndex;
    idxval.Value = *aValue;
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &idxval, ITSDK_DATATYPE_IDXDouble);
    if (iret == ITSDK_RET_SUCCESS) {*aValue = idxval.Value;}

    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_IdxString(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aIndex, std::string *aValue)
{
	TITSDK_IdxString itidxstr;
	itidxstr.Index = aIndex;
    itidxstr.Value.Text = aValue->data();
    itidxstr.Value.Len = aValue->length();
    TITSDK_Ret iret = SetParam(aOjectHandle, aWhat, &itidxstr, ITSDK_DATATYPE_IDXString);
    if (iret == ITSDK_RET_SUCCESS)
        {aValue->resize(itidxstr.Value.Len);}
    return iret;
}

TITSDK_Ret TITSDK_ObjectHandler::SetParam_2Int32(TITSDK_Handle aOjectHandle, TITSDK_UInt32 aWhat, TITSDK_Int32 aValue1, TITSDK_Int32 aValue2)
{
    TITSDK_2Int32 i2val;
    i2val.Value1 = aValue1;
    i2val.Value2 = aValue2;
    return SetParam(aOjectHandle, aWhat, &i2val, ITSDK_DATATYPE_2INT32);
}
