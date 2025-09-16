#ifndef HITSDKTYPES_H
#define HITSDKTYPES_H

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hitsdkide.h"


#ifdef ITSDK_OS_UNIX

#define __CALLCONV __cdecl

typedef void* TITSDK_LibHandle;
const TITSDK_LibHandle LibHandleInvalid = NULL;
typedef void* TLibProcAddr;
#define MAX_PATH 255

#else //ITSDK_OS_UNIX
#ifdef ITSDK_OS_WINDOWS

#include <Windows.h>

#define __CALLCONV __stdcall

typedef HMODULE TITSDK_LibHandle;
const TITSDK_LibHandle LibHandleInvalid = 0;
typedef FARPROC TLibProcAddr;

#else //ITSDK_OS_WINDOWS
undefined platform
#endif //not ITSDK_OS_WINDOWS
#endif //not ITSDK_OS_UNIX




typedef TITSDK_LibHandle* PITSDK_LibHandle;

typedef uint32_t	TITSDK_Ret;
typedef uint32_t	TITSDK_DataType;
typedef uint32_t	TITSDK_ParamID;
typedef int32_t     TITSDK_Index;


///////////////////////////////////////
///
/// base types
///
///////////////////////////////////////
//all structures must be packed for binary compatibility
#pragma pack(push, 1)

typedef intptr_t        TITSDK_Handle;
typedef TITSDK_Handle*  PITSDK_Handle;

typedef void*           TITSDK_Pointer;
typedef TITSDK_Pointer* PITSDK_Pointer;

typedef int8_t          TITSDK_Int8;
typedef TITSDK_Int8*    PITSDK_Int8;

typedef int16_t         TITSDK_Int16;
typedef TITSDK_Int16*   PITSDK_Int16;

typedef int32_t         TITSDK_Int32;
typedef TITSDK_Int32*   PITSDK_Int32;

typedef int64_t         TITSDK_Int64;
typedef TITSDK_Int64*   PITSDK_Int64;

typedef uint8_t         TITSDK_UInt8;
typedef TITSDK_UInt8*   PITSDK_UInt8;

typedef uint16_t        TITSDK_UInt16;
typedef TITSDK_UInt16*  PITSDK_UInt16;

typedef uint32_t        TITSDK_UInt32;
typedef TITSDK_UInt32*  PITSDK_UInt32;

typedef uint64_t        TITSDK_UInt64;
typedef TITSDK_UInt64*  PITSDK_UInt64;

typedef float           TITSDK_Single;
typedef TITSDK_Single*  PITSDK_Single;

typedef double          TITSDK_Double;
typedef TITSDK_Double*  PITSDK_Double;

typedef struct{
    char* Text;
    TITSDK_Int32	Len;
}TITSDK_Param;
typedef TITSDK_Param*   PITSDK_Param;

typedef struct{
	char* Text;
	TITSDK_Int32	Len;
}TITSDK_String;
typedef TITSDK_String*  PITSDK_String;

#pragma pack(pop)

///////////////////////////////////////
///
/// extended data type 'index'
///
///////////////////////////////////////

//all structures must be packed for binary compatibility
#pragma pack(push, 1)

typedef struct{
	TITSDK_Index	Index;
	TITSDK_Pointer	Value;
}TITSDK_IdxPointer;
typedef TITSDK_IdxPointer*  PITSDK_IdxPointer;

typedef struct{
	TITSDK_Index	Index;
	TITSDK_Handle	Value;
}TITSDK_IdxHandle;
typedef TITSDK_IdxHandle*   PITSDK_IdxHandle;

typedef struct{
    TITSDK_Index	Index;
    TITSDK_Int8     Value;
}TITSDK_IdxInt8;
typedef TITSDK_IdxInt8*    PITSDK_IdxInt8;

typedef struct{
    TITSDK_Index	Index;
    TITSDK_Int16	Value;
}TITSDK_IdxInt16;
typedef TITSDK_IdxInt16*    PITSDK_IdxInt16;

typedef struct{
	TITSDK_Index	Index;
	TITSDK_Int32	Value;
}TITSDK_IdxInt32;
typedef TITSDK_IdxInt32*    PITSDK_IdxInt32;

typedef struct{
	TITSDK_Index	Index;
	TITSDK_Int64	Value;
}TITSDK_IdxInt64;
typedef TITSDK_IdxInt64*    PITSDK_IdxInt64;

typedef struct{
    TITSDK_Index	Index;
    TITSDK_UInt8	Value;
}TITSDK_IdxUInt8;
typedef TITSDK_IdxUInt8*   PITSDK_IdxUInt8;

typedef struct{
    TITSDK_Index	Index;
    TITSDK_UInt16	Value;
}TITSDK_IdxUInt16;
typedef TITSDK_IdxUInt16*  PITSDK_IdxUInt16;

typedef struct{
    TITSDK_Index	Index;
    TITSDK_UInt32	Value;
}TITSDK_IdxUInt32;
typedef TITSDK_IdxUInt32*   PITSDK_IdxUInt32;

typedef struct{
    TITSDK_Index	Index;
    TITSDK_UInt64	Value;
}TITSDK_IdxUInt64;
typedef TITSDK_IdxUInt64*  PITSDK_IdxUInt64;

typedef struct{
	TITSDK_Index	Index;
	TITSDK_Single	Value;
}TITSDK_IdxSingle;
typedef TITSDK_IdxSingle*   PITSDK_IdxSingle;

typedef struct{
	TITSDK_Index	Index;
	TITSDK_Double	Value;
}TITSDK_IdxDouble;
typedef TITSDK_IdxDouble*   PITSDK_IdxDouble;

typedef struct{
	TITSDK_Index	Index;
	TITSDK_String	Value;
}TITSDK_IdxString;
typedef TITSDK_IdxString*   PITSDK_IdxString;


#pragma pack(pop)

///////////////////////////////////////
///
/// extended data type '2 values'
///
///////////////////////////////////////

//all structures must be packed for binary compatibility
#pragma pack(push, 1)

typedef struct{
    TITSDK_Pointer	FuncPtr;
    TITSDK_Pointer	Context;
}TITSDK_CallBack;
typedef TITSDK_CallBack*    PITSDK_CallBack;

typedef struct{
    TITSDK_Pointer	Value1;
    TITSDK_Pointer	Value2;
}TITSDK_2Pointer;
typedef TITSDK_IdxString*   PITSDK_2Pointer;

typedef struct{
    TITSDK_Int8     Value1;
    TITSDK_Int8     Value2;
}TITSDK_2Int8;
typedef TITSDK_2Int8*      PITSDK_2Int8;

typedef struct{
    TITSDK_Int16    Value1;
    TITSDK_Int16    Value2;
}TITSDK_2Int16;
typedef TITSDK_2Int16*      PITSDK_2Int16;

typedef struct{
    TITSDK_Int32    Value1;
    TITSDK_Int32    Value2;
}TITSDK_2Int32;
typedef TITSDK_2Int32*      PITSDK_2Int32;

typedef struct{
    TITSDK_Int64    Value1;
    TITSDK_Int64    Value2;
}TITSDK_2Int64;
typedef TITSDK_2Int64*      PITSDK_2Int64;

typedef struct{
    TITSDK_UInt8	Value1;
    TITSDK_UInt8	Value2;
}TITSDK_2UInt8;
typedef TITSDK_2UInt8*   PITSDK_2UInt8;

typedef struct{
    TITSDK_UInt16	Value1;
    TITSDK_UInt16	Value2;
}TITSDK_2UInt16;
typedef TITSDK_2UInt16*  PITSDK_2UInt16;

typedef struct{
    TITSDK_UInt32	Value1;
    TITSDK_UInt32	Value2;
}TITSDK_2UInt32;
typedef TITSDK_2UInt32*   PITSDK_2UInt32;

typedef struct{
    TITSDK_UInt64	Value1;
    TITSDK_UInt64	Value2;
}TITSDK_2UInt64;
typedef TITSDK_2UInt64*  PITSDK_2UInt64;

typedef struct{
    TITSDK_Single   Value1;
    TITSDK_Single   Value2;
}TITSDK_2Single;
typedef TITSDK_2Single*     PITSDK_2Single;

typedef struct{
    TITSDK_Double   Value1;
    TITSDK_Double   Value2;
}TITSDK_2Double;
typedef TITSDK_2Double*     PITSDK_2Double;

typedef struct{
    TITSDK_String	Value1;
    TITSDK_String	Value2;
}TITSDK_2String;
typedef TITSDK_2String*     PITSDK_2String;

typedef struct{
    TITSDK_Int32	X;
    TITSDK_Int32	Y;
}TITSDK_Pixel;
typedef TITSDK_Pixel*       PITSDK_Pixel;

#pragma pack(pop)


///////////////////////////////////////
///
/// structures/records
///
///////////////////////////////////////

#pragma pack(push, 1)

/**************************************
*** TITSDK_Frame_ContentInfo
***************************************/
typedef struct
{
    TITSDK_UInt16   MainType;
    TITSDK_UInt16   SubType;
    TITSDK_UInt16   StreamChannel;
}TITSDK_Frame_ContentInfo;
typedef TITSDK_Frame_ContentInfo*   PITSDK_Frame_ContentInfo;

/**************************************
*** TITSDK_Frame_IdxContentInfo
***************************************/
typedef struct
{
    TITSDK_Int32              Index;
    TITSDK_Frame_ContentInfo  FrameContent;
}TITSDK_Frame_IdxContentInfo;
typedef TITSDK_Frame_IdxContentInfo*    PITSDK_Frame_IdxContentInfo;

/**************************************
*** TITSDK_GetMemInfo
***************************************/
typedef struct
{
    TITSDK_Int32              StructSize;
    TITSDK_Frame_ContentInfo  FrameContent;
    TITSDK_UInt32             Flags;
}TITSDK_GetMemInfo;
typedef TITSDK_GetMemInfo*      PITSDK_GetMemInfo;

/**************************************
*** TITSDK_Frame_SaveInfo
***************************************/
typedef struct
{
    TITSDK_Int32              StructSize;
    TITSDK_Frame_ContentInfo  FrameContent;
}TITSDK_Frame_SaveInfo;
typedef TITSDK_Frame_SaveInfo*  PITSDK_Frame_SaveInfo;

/**************************************
*** TITSDK_DateTime
***************************************/
typedef struct
{
    TITSDK_UInt16   wYear;
    TITSDK_UInt16   wMonth;
    TITSDK_UInt16   wDay;
    TITSDK_UInt16   wDayOfWeek;
    TITSDK_UInt16   wHour;
    TITSDK_UInt16   wMinute;
    TITSDK_UInt16   wSecond;
    TITSDK_UInt16   wMilliSeconds;
}TITSDK_DateTime;
typedef TITSDK_DateTime*    PITSDK_DateTime;

/**************************************
*** TITSDK_PixelValue
***************************************/
typedef struct
{
    TITSDK_Int32    X;
    TITSDK_Int32    Y;
    TITSDK_Single   Value;
}TITSDK_PixelValue;
typedef TITSDK_PixelValue*  PITSDK_PixelValue;

/**************************************
*** TITSDK_MeasResult
***************************************/
typedef struct
{
    TITSDK_UInt32   ROI;
    TITSDK_Single   Min;
    TITSDK_Single   Max;
    TITSDK_Single   Avg;
    TITSDK_Single   StdDev;
    TITSDK_Single   Span;
}TITSDK_MeasResult;
typedef TITSDK_MeasResult*  PITSDK_MeasResult;


#pragma pack(pop)

//------------------------------------------------------------------
//- function definition
//------------------------------------------------------------------

#define __CALLCONV __stdcall
//typedef void (__CALLCONV *TIRBgrabOnNewFrame) (TITSDK_Handle aHandle, int aStreamIndex);
typedef TITSDK_Ret(__CALLCONV* TITSDK_FUNC_GETSET)(TITSDK_Handle aHandle, TITSDK_UInt32 aWhat, TITSDK_Pointer aDataPtr, TITSDK_UInt32 aDataType);
typedef TITSDK_Ret(__CALLCONV* TITSDK_FUNC_FREE)(PITSDK_Handle aHandle);

#define arraylength(variable) (sizeof(variable) / sizeof(variable[0]))



#endif //HITSDKTYPES_H

