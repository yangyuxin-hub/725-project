#ifndef HITSDKCONSTANTS_H
#define HITSDKCONSTANTS_H

#include "hitsdktypes.h"

#include <sstream>
#include <string>

///////////////////////////////////////
///
/// return values of the library functions
///
///////////////////////////////////////

//structural integration
#define ITSDK_RET_TYPE_MASK		TITSDK_Ret(0xF0000000)


//bits to distinguish return type
#define ITSDK_RET_TYPE_OK		TITSDK_Ret(0x10000000)
#define ITSDK_RET_TYPE_STATUS	TITSDK_Ret(0x20000000)
#define ITSDK_RET_TYPE_RESERVED	TITSDK_Ret(0x40000000)
#define ITSDK_RET_TYPE_ERR		TITSDK_Ret(0x80000000)

//no valid return value (should never be passed as argument | return value)
#define ITSDK_RET_UNDEF			TITSDK_Ret(0)

/**************************************
*** return value 'ok'
***************************************/
//ITSDK_RET_TYPE_OK
#define ITSDK_RET_SUCCESS                 TITSDK_Ret( ITSDK_RET_TYPE_OK     | 0x01)
#define ITSDK_RET_OK                      TITSDK_Ret( ITSDK_RET_SUCCESS )

/**************************************
*** return value 'ok'
***************************************/
//ITSDK_RET_TYPE_STATUS
#define ITSDK_RET_STATUS_OK               TITSDK_Ret( ITSDK_RET_TYPE_STATUS | 0x01 ) //generic ok status
#define ITSDK_RET_STATUS_CONNECTING       TITSDK_Ret( ITSDK_RET_TYPE_STATUS | 0x02 ) //in the process of establishing a connection
#define ITSDK_RET_STATUS_CONNECTED        TITSDK_Ret( ITSDK_RET_TYPE_STATUS | 0x03 ) //connection is established, but no data has been exchanged yet
#define ITSDK_RET_STATUS_COMM_ERROR       TITSDK_Ret( ITSDK_RET_TYPE_STATUS | 0x05 ) //device has been connected and communicating before, but lost its connection (e.g. cable has fallen off, peer is down,...)
#define ITSDK_RET_STATUS_DISCONNECTED     TITSDK_Ret( ITSDK_RET_TYPE_STATUS | 0x06 ) //has been connected before and is gracefully disconnected
#define ITSDK_RET_STATUS_RUNNING          TITSDK_Ret( ITSDK_RET_TYPE_STATUS | 0x07 ) //communication is up and running

/**************************************
*** return value 'ok'
***************************************/
//ITSDK_RET_TYPE_ERR
#define ITSDK_RET_ERR_GENERIC             TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x01 ) //generic unspecified error
#define ITSDK_RET_ERR_NOT_SUPPORTED       TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x02 ) //feature is not supported
#define ITSDK_RET_ERR_NOT_FOUND           TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x03 ) //generic "something" could not be found (maybe add some more specific errors later)
#define ITSDK_RET_ERR_OUT_OF_RANGE        TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x04 ) //argument is out of range
#define ITSDK_RET_ERR_TIMEOUT             TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x05 ) //timeout elapsed
#define ITSDK_RET_ERR_BLOCKED             TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x06 ) //failed to enter some critical section
#define ITSDK_RET_ERR_UNASSIGNED          TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x07 ) //something is unset/nil
#define ITSDK_RET_ERR_INCOMPATIBLE        TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x08 ) //binary incompatibilities detected (e.g. struct sizes differ)
#define ITSDK_RET_ERR_BUFSIZE             TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x09 ) //buffer is too small (is not neccessarily an error)
#define ITSDK_RET_ERR_CONFIG              TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x0A )
#define ITSDK_RET_ERR_CONNECTION          TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x0B ) //no connection could be established - device has never been connected
#define ITSDK_RET_ERR_INVALID_HANDLE      TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x0C ) //invalid Handle
#define ITSDK_RET_ERR_INVALID_DATASIZE    TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x0D ) //invalid DataSize
#define ITSDK_RET_ERR_INVALID_DATAPOINTER TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x0E ) //invalid DataPointer
#define ITSDK_RET_ERR_INVALID_PARAMETER   TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x0F ) //invalid Parameter
#define ITSDK_RET_ERR_TERMINATED          TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x10 ) //Object is Terminated
#define ITSDK_RET_ERR_NOT_PERMITTED       TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x11 ) //Operation is not permitted (e.g. ReadOnly)
#define ITSDK_RET_ERR_DRIVE               TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x12 ) //Drive is full or invalid drive
#define ITSDK_RET_ERR_RAM                 TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x13 ) //RAM is full
#define ITSDK_RET_ERR_FILESIZE            TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x14 ) //file has reached max. size
#define ITSDK_RET_ERR_SKIP                TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x15 ) //operation failed/skipped
#define ITSDK_RET_ERR_NOT_READY           TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x16 ) //operation is not ready
#define ITSDK_RET_ERR_INVALID_LICENSE     TITSDK_Ret( ITSDK_RET_TYPE_ERR    | 0x17 ) //invalid license or license is out of date


///////////////////////////////////////
///
/// data type description
///
///////////////////////////////////////

/**************************************
*** data type identification
***************************************/

// base types
#define ITSDK_BASETYPE_RAW		TITSDK_DataType(0x00000000)
#define ITSDK_BASETYPE_POINTER	TITSDK_DataType(0x10000000)

#define ITSDK_BASETYPE_INT8		TITSDK_DataType(0x20000000)
#define ITSDK_BASETYPE_INT16	TITSDK_DataType(0x30000000)
#define ITSDK_BASETYPE_INT32	TITSDK_DataType(0x40000000)
#define ITSDK_BASETYPE_INT64	TITSDK_DataType(0x50000000)

#define ITSDK_BASETYPE_UINT8	TITSDK_DataType(0x60000000)
#define ITSDK_BASETYPE_UINT16	TITSDK_DataType(0x70000000)
#define ITSDK_BASETYPE_UINT32	TITSDK_DataType(0x80000000)
#define ITSDK_BASETYPE_UINT64	TITSDK_DataType(0x90000000)

#define ITSDK_BASETYPE_SINGLE	TITSDK_DataType(0xA0000000)
#define ITSDK_BASETYPE_DOUBLE	TITSDK_DataType(0xB0000000)

#define ITSDK_BASETYPE_RECORD	TITSDK_DataType(0xE0000000)
#define ITSDK_BASETYPE_STRING	TITSDK_DataType(0xF0000000) // String wird immer als PAnsiChar  + Len(integer) übergeben

// extended types
#define ITSDK_EXTTYP_MASK		TITSDK_DataType(0x0F000000)
#define ITSDK_EXTYPE_NONE		TITSDK_DataType(0x00000000)
#define ITSDK_EXTYPE_INDEX		TITSDK_DataType(0x01000000) // besteht immer aus einen Index (Int32) + Wert
#define ITSDK_EXTYPE_ARRAY		TITSDK_DataType(0x02000000) // Array of DataType
#define ITSDK_EXTYPE_IDXARRAY	TITSDK_DataType(ITSDK_EXTYPE_INDEX | ITSDK_EXTYPE_ARRAY) // Array of (Index(Int32) + Wert)
#define ITSDK_EXTYPE_ARRAY2		TITSDK_DataType(ITSDK_EXTYPE_ARRAY | 0x00020000) // Array[0..1] of DataType


/**************************************
*** full description of data types
***************************************/
#define ITSDK_DATATYPE_RAW          TITSDK_DataType(ITSDK_BASETYPE_RAW)
// base types
#define ITSDK_DATATYPE_POINTER      TITSDK_DataType( ITSDK_BASETYPE_POINTER	| sizeof(TITSDK_Pointer) )
#define ITSDK_DATATYPE_HANDLE       TITSDK_DataType( ITSDK_BASETYPE_POINTER	| sizeof(TITSDK_Handle)  )
#define ITSDK_DATATYPE_INT8         TITSDK_DataType( ITSDK_BASETYPE_INT8	| sizeof(TITSDK_Int8)    )
#define ITSDK_DATATYPE_INT16        TITSDK_DataType( ITSDK_BASETYPE_INT16	| sizeof(TITSDK_Int16)   )
#define ITSDK_DATATYPE_INT32        TITSDK_DataType( ITSDK_BASETYPE_INT32	| sizeof(TITSDK_Int32)   )
#define ITSDK_DATATYPE_INT64        TITSDK_DataType( ITSDK_BASETYPE_INT64	| sizeof(TITSDK_Int64)   )
#define ITSDK_DATATYPE_UINT8        TITSDK_DataType( ITSDK_BASETYPE_UINT8	| sizeof(TITSDK_UInt8)   )
#define ITSDK_DATATYPE_UINT16       TITSDK_DataType( ITSDK_BASETYPE_UINT16	| sizeof(TITSDK_UInt16)  )
#define ITSDK_DATATYPE_UINT32       TITSDK_DataType( ITSDK_BASETYPE_UINT32	| sizeof(TITSDK_UInt32)  )
#define ITSDK_DATATYPE_UINT64       TITSDK_DataType( ITSDK_BASETYPE_UINT64	| sizeof(TITSDK_UInt64)  )
#define ITSDK_DATATYPE_SINGLE       TITSDK_DataType( ITSDK_BASETYPE_SINGLE	| sizeof(TITSDK_Single)  )
#define ITSDK_DATATYPE_DOUBLE       TITSDK_DataType( ITSDK_BASETYPE_DOUBLE	| sizeof(TITSDK_Double)  )
#define ITSDK_DATATYPE_STRING       TITSDK_DataType( ITSDK_BASETYPE_STRING	| sizeof(TITSDK_String)  )

// extended type 'index'
#define ITSDK_DATATYPE_IDXPOINTER	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_POINTER | sizeof(TITSDK_IdxPointer) )
#define ITSDK_DATATYPE_IDXHANDLE    TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_POINTER | sizeof(TITSDK_IdxHandle)  )
#define ITSDK_DATATYPE_IDXINT8		TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_INT8    | sizeof(TITSDK_IdxInt8)    )

#define ITSDK_DATATYPE_IDXINT16		TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_INT16   | sizeof(TITSDK_IdxInt16)   )
#define ITSDK_DATATYPE_IDXINT32		TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_INT32   | sizeof(TITSDK_IdxInt32)   )
#define ITSDK_DATATYPE_IDXINT64		TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_INT64   | sizeof(TITSDK_IdxInt64)   )
#define ITSDK_DATATYPE_IDXUINT8 	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_UINT8   | sizeof(TITSDK_IdxUInt16)  )
#define ITSDK_DATATYPE_IDXUINT16	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_UINT16  | sizeof(TITSDK_IdxUInt16)  )
#define ITSDK_DATATYPE_IDXUINT32	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_UINT32  | sizeof(TITSDK_IdxUInt32)  )
#define ITSDK_DATATYPE_IDXUINT64	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_UINT64  | sizeof(TITSDK_IdxUInt64)  )
#define ITSDK_DATATYPE_IDXSingle	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_SINGLE  | sizeof(TITSDK_IdxSingle)  )
#define ITSDK_DATATYPE_IDXDouble	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_DOUBLE  | sizeof(TITSDK_IdxDouble)  )
#define ITSDK_DATATYPE_IDXString	TITSDK_DataType( ITSDK_EXTYPE_INDEX | ITSDK_BASETYPE_STRING  | sizeof(TITSDK_IdxString)  )

// extended type '2 values'
#define ITSDK_DATATYPE_2POINTER		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_POINTER | sizeof(TITSDK_2Pointer) )
#define ITSDK_DATATYPE_2INT8		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_INT8	  | sizeof(TITSDK_2Int8)    )
#define ITSDK_DATATYPE_2INT16		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_INT16	  | sizeof(TITSDK_2Int16)   )
#define ITSDK_DATATYPE_2INT32		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_INT32	  | sizeof(TITSDK_2Int32)   )
#define ITSDK_DATATYPE_2INT64		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_INT64	  | sizeof(TITSDK_2Int64)   )
#define ITSDK_DATATYPE_2UINT8		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_UINT8   | sizeof(TITSDK_2UInt8)   )
#define ITSDK_DATATYPE_2UINT16		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_UINT16  | sizeof(TITSDK_2UInt16)  )
#define ITSDK_DATATYPE_2UINT32		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_UINT32  | sizeof(TITSDK_2UInt32)  )
#define ITSDK_DATATYPE_2UINT64		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_UINT64  | sizeof(TITSDK_2UInt64)  )
#define ITSDK_DATATYPE_2Single		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_SINGLE  | sizeof(TITSDK_2Single)  )
#define ITSDK_DATATYPE_2Double		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_DOUBLE  | sizeof(TITSDK_2Double)  )
#define ITSDK_DATATYPE_2String		TITSDK_DataType( ITSDK_EXTYPE_ARRAY2 | ITSDK_BASETYPE_STRING  | sizeof(TITSDK_2String)  )

#define ITSDK_DATATYPE_CALLBACK		TITSDK_DataType( ITSDK_DATATYPE_2POINTER )
#define ITSDK_DATATYPE_PIXEL        TITSDK_DataType( ITSDK_DATATYPE_2INT32   )

/**************************************
*** description of special structures
***************************************/
#define ITSDK_DATATYPE_Frame_ContentInfo    TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_Frame_ContentInfo))
#define ITSDK_DATATYPE_Frame_IdxContentInfo TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_Frame_IdxContentInfo))
#define ITSDK_DATATYPE_GetMemInfo           TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_GetMemInfo))
#define ITSDK_DATATYPE_Frame_SaveInfo       TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_Frame_SaveInfo))
#define ITSDK_DATATYPE_DateTime             TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_DateTime))
#define ITSDK_DATATYPE_PixelValue           TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_PixelValue))
#define ITSDK_DATATYPE_MeasResult           TITSDK_DataType(ITSDK_BASETYPE_RECORD | sizeof(TITSDK_MeasResult))

///////////////////////////////////////
///
/// other constants
///
///////////////////////////////////////

/**************************************
*** full description of data types
***************************************/
#define ITSDK_MEMTYPE_DEFAULT        0
#define ITSDK_MEMTYPE_BITMAP32       1
#define ITSDK_MEMTYPE_IR_DIGIT       2
#define ITSDK_MEMTYPE_IR_TEMP        3
#define ITSDK_MEMTYPE_IR_LUT         4
#define ITSDK_MEMTYPE_JPG            6
#define ITSDK_MEMTYPE_PNG            7

/**************************************
*** main type of a frame
***************************************/
#define ITSDK_FRAME_MAINTYPE_IR      8
#define ITSDK_FRAME_MAINTYPE_INI    34
#define ITSDK_FRAME_MAINTYPE_IMAGE  57
#define ITSDK_FRAME_MAINTYPE_AUDIO  58

/**************************************
*** sub type of a frame
***************************************/
#define ITSDK_FRAME_SUBTYPE_DEFAULT  0

/**************************************
*** temperature units
***************************************/
#define ITSDK_TEMPUNIT_Undef             0
#define ITSDK_TEMPUNIT_Kelvin            1
#define ITSDK_TEMPUNIT_Celsius           2
#define ITSDK_TEMPUNIT_Fahrenheit        3
#define ITSDK_TEMPUNIT_Rankine           4
#define ITSDK_TEMPUNIT_SpecRad          12
#define ITSDK_TEMPUNIT_SpecRadExitance   5
#define ITSDK_TEMPUNIT_DigitalValue      9
#define ITSDK_TEMPUNIT_Millikelvin      10

/**************************************
*** temperature range mode
***************************************/
#define ITSDK_TEMPRANGEMODE_User         0
#define ITSDK_TEMPRANGEMODE_Auto         1
#define ITSDK_TEMPRANGEMODE_ObjTemp      2
#define ITSDK_TEMPRANGEMODE_RangeShot    3
#define ITSDK_TEMPRANGEMODE_Calibration  4

/**************************************
*** save mode
***************************************/
#define ITSDK_SAVEMODE_ADD               0
#define ITSDK_SAVEMODE_OVERWRITE         1
#define ITSDK_SAVEMODE_SEQUENCE          2

/**************************************
*** GetMem flags
***************************************/
#define ITSDK_GETMEMFLAG_Compressed TITSDK_UInt32(0x00000001)


///////////////////////////////////////
///
/// help functions
///
///////////////////////////////////////

inline const std::string ITSDK_ReturnString(TITSDK_Ret aRetVal)
{
    switch(aRetVal){
        //ITSDK_RET_TYPE_OK
        //case ITSDK_RET_SUCCESS:                 return "Success";
        //ITSDK_RET_TYPE_STATUS
        case ITSDK_RET_STATUS_OK:               return "StatusOk";
        case ITSDK_RET_STATUS_CONNECTING:       return "Connecting";
        case ITSDK_RET_STATUS_CONNECTED:        return "Connected";
        case ITSDK_RET_STATUS_RUNNING:          return "Running";
        case ITSDK_RET_STATUS_COMM_ERROR:       return "CommunicationError";
        case ITSDK_RET_STATUS_DISCONNECTED:     return "Disconnected";
        //ITSDK_RET_TYPE_ERROR
        case ITSDK_RET_ERR_GENERIC:             return "Error";
        case ITSDK_RET_ERR_NOT_SUPPORTED:       return "NotSupported";
        case ITSDK_RET_ERR_NOT_FOUND:           return "NotFound";
        case ITSDK_RET_ERR_OUT_OF_RANGE:        return "OutOfRange";
        case ITSDK_RET_ERR_TIMEOUT:             return "Timeout";
        case ITSDK_RET_ERR_BLOCKED:             return "Blocked";
        case ITSDK_RET_ERR_UNASSIGNED:          return "Unassigned";
        case ITSDK_RET_ERR_INCOMPATIBLE:        return "Incompatible";
        case ITSDK_RET_ERR_BUFSIZE:             return "BufferTooSmall";
        case ITSDK_RET_ERR_CONFIG:              return "ConfigError";
        case ITSDK_RET_ERR_CONNECTION:          return "ConnectionError";
        case ITSDK_RET_ERR_INVALID_HANDLE:      return "InvalidHandle";
        case ITSDK_RET_ERR_INVALID_DATASIZE:    return "InvalidDataSize";
        case ITSDK_RET_ERR_INVALID_DATAPOINTER: return "InvalidDataPointer";
        case ITSDK_RET_ERR_INVALID_PARAMETER:   return "InvalidParameter";
        case ITSDK_RET_ERR_TERMINATED:          return "Terminated";
        case ITSDK_RET_ERR_NOT_PERMITTED:       return "NotPermitted";
        case ITSDK_RET_ERR_DRIVE:               return "HarddriveError";
        case ITSDK_RET_ERR_RAM:                 return "RamError";
        case ITSDK_RET_ERR_FILESIZE:            return "FileSize";
        case ITSDK_RET_ERR_SKIP:                return "Skipped";
        case ITSDK_RET_ERR_NOT_READY:           return "ITSDK_RET_ERR_NOT_READY";
        case ITSDK_RET_ERR_INVALID_LICENSE:     return "Invalid Licence";

    default:
        std::ostringstream  oss;
        if (oss<<"0x"<<std::hex<<aRetVal) {return oss.str();}
        else                        {return "ErrConvertingToHex";}
    };
}


#endif // HITSDKCONSTANTS_H
