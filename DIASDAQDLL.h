#include <minwindef.h>
#include <winnt.h>
#include <windef.h>
#include <wingdi.h>

/////////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////
/** @file DIASDAQDLL.h Interface for DIAS IR cameras and IRDX data format

	Definition of DDAQ data types starts here #DDAQ_V

	Available camera functions (access by DEVICE NUMBER) start here #DDAQ_DEVICE_DO_DETECTION
		
	Available IRDX functions (access by IRDX handle) start here #DDAQ_IRDX_FILE_DELETE

    DDAQ defines start here #DDAQ_MAX_DEVICES

	DDAQ error codes start here #DDAQ_NO_ERROR
*/
////////////////////////////////////////////////////////////////////////////
// DDAQ data types
////////////////////////////////////////////////////////////////////////////

typedef void				DDAQ_V;			///< void 
typedef CHAR				DDAQ_CHAR8;		///< 8 bit NULL-terminated character buffer (MBCS)
typedef WCHAR				DDAQ_CHAR16;	///< 16 bit NULL-terminated wide character buffer (Unicode UTF-16, 2 bytes per wide character)
typedef short				DDAQ_I16;		///< 16 bit signed
typedef unsigned short		DDAQ_U16;		///< 16 bit unsigned	
typedef long				DDAQ_I32;		///< 32 bit signed
typedef unsigned long		DDAQ_U32;		///< 32 bit unsigned
typedef bool				DDAQ_BOOL;		///< boolean
typedef float				DDAQ_F32;		///< 32 bit real
typedef double				DDAQ_F64;		///< 64 bit real

typedef void*				DDAQ_P_V;		///< void pointer
typedef DDAQ_CHAR8*			DDAQ_P_CHAR8;	///< pointer to 8 bit NULL-terminated character buffer (MBCS)
typedef CONST DDAQ_CHAR8*	DDAQ_PC_CHAR8;	///< const pointer to 8 bit NULL-terminated character buffer (MBCS)
typedef DDAQ_CHAR16*		DDAQ_P_CHAR16;	///< pointer to 16 bit NULL-terminated wide character buffer (Unicode UTF-16, 2 bytes per wide character)
typedef CONST DDAQ_CHAR16*	DDAQ_PC_CHAR16;	///< const pointer to 16 bit NULL-terminated wide character buffer (Unicode UTF-16, 2 bytes per wide character)
typedef DDAQ_I16*			DDAQ_P_I16;		///< pointer to 16 bit signed
typedef DDAQ_U16*			DDAQ_P_U16;		///< pointer to 16 bit unsigned
typedef DDAQ_U16**			DDAQ_PP_U16;	///< pointer to pointer to 16 bit unsigned
typedef DDAQ_I32*			DDAQ_P_I32;		///< pointer to 32 bit signed
typedef DDAQ_U32*			DDAQ_P_U32;		///< pointer to 32 bit unsigned
typedef DDAQ_BOOL*			DDAQ_P_BOOL;	///< pointer to boolean
typedef DDAQ_F32*			DDAQ_P_F32;		///< pointer to 32 bit real
typedef DDAQ_F64*			DDAQ_P_F64;		///< pointer to 64 bit real

typedef HANDLE				DDAQ_HANDLE;	///< access handle 
typedef DDAQ_HANDLE*		DDAQ_P_HANDLE;	///< pointer to access handle 

typedef HBITMAP				DDAQ_HBITMAP;		///< bitmap handle
typedef DDAQ_HBITMAP*		DDAQ_P_HBITMAP;		///< pointer to bitmap handle

typedef void*				DDAQ_P_BITMAPBITS;	///< pointer to BITMAPBITS 
typedef BITMAPINFO*			DDAQ_P_BITMAPINFO;	///< pointer to BITMAPINFO

typedef DDAQ_P_BITMAPBITS*	DDAQ_PP_BITMAPBITS;	///< pointer to pointer to BITMAPBITS 
typedef DDAQ_P_BITMAPINFO*	DDAQ_PP_BITMAPINFO;	///< pointer to pointer to BITMAPINFO

////////////////////////////////////////////////////////////////////////////
// Global Functions DDAQ_SET_xxxx
////////////////////////////////////////////////////////////////////////////

/** MBCS: Set general locale settings for the DAQ DLL (default is "english").
@param		sz8Locale			MBCS locale specifier (e.g. "german")
*/
DDAQ_V	__stdcall DDAQ_SET_LOCALE(DDAQ_PC_CHAR8 sz8Locale);

/** Unicode UTF-16: Set general locale settings for the DAQ DLL (default is "english").
@param		sz16Locale			Unicode locale specifier (e.g. "german")
*/

DDAQ_V	__stdcall DDAQ_SET_LOCALE_UC(DDAQ_PC_CHAR16 sz16Locale);

/** Set general precision for text output of temperatures (default is 1)
	@param		u16Precision		precision of text output (0, 1 or 2 decimals)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32 __stdcall DDAQ_SET_TEMPPRECISION(DDAQ_U16 u16Precision);

////////////////////////////////////////////////////////////////////////////

/** Set general temperature unit for all temperature inputs and outputs (default is #DDAQ_TEMPUNIT_C)
	This function has to be called before any IRDX file or device is opened
	@param		u16TempUnit		temperature unit (refer to #DDAQ_TEMPUNIT_C)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32 __stdcall DDAQ_SET_TEMPUNIT(DDAQ_U16 u16TempUnit);

////////////////////////////////////////////////////////////////////////////
// Global Functions DDAQ_GET_xxxx
////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the character string from a temperature value with global unit (#DDAQ_SET_TEMPUNIT) and global precision (#DDAQ_SET_TEMPPRECISION)
	@param		f32Temp			temperature value corresponding to #DDAQ_SET_TEMPUNIT	
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_GET_TEMPSTRING(DDAQ_F32 f32Temp, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the character string from a temperature value with global unit (#DDAQ_SET_TEMPUNIT) and global precision (#DDAQ_SET_TEMPPRECISION)
	@param		f32Temp			temperature value corresponding to #DDAQ_SET_TEMPUNIT
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_GET_TEMPSTRING_UC(DDAQ_F32 f32Temp, DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the character string from a temperature value with global unit (#DDAQ_SET_TEMPUNIT) and user precision
	@param		f32Temp			temperature value corresponding to #DDAQ_SET_TEMPUNIT	
	@param		u16Precision	precision of text output (0, 1 or 2 decimals)
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_GET_TEMPPRECSTRING(DDAQ_F32 f32Temp, DDAQ_U16 u16Precision, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the character string from a temperature value with global unit (#DDAQ_SET_TEMPUNIT) and user precision
	@param		f32Temp			temperature value corresponding to #DDAQ_SET_TEMPUNIT
	@param		u16Precision	precision of text output (0, 1 or 2 decimals)
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_GET_TEMPPRECSTRING_UC(DDAQ_F32 f32Temp, DDAQ_U16 u16Precision, DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the temperature unit string using the global unit (#DDAQ_SET_TEMPUNIT)
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_GET_TEMPUNITSTRING(DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the temperature unit string using the global unit (#DDAQ_SET_TEMPUNIT)
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_GET_TEMPUNITSTRING_UC(DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////
// Global temperature conversion functions
////////////////////////////////////////////////////////////////////////////

/** Get a temperature in degree Celsius from a temperature corresponding to #DDAQ_SET_TEMPUNIT (not for #DDAQ_TEMPUNIT_R).
@param		f64Temp			temperature corresponding to #DDAQ_SET_TEMPUNIT.
@return		temperature in degree Celsius
*/
DDAQ_F64	__stdcall DDAQ_TEMP_2_TEMPC(DDAQ_F64 f64Temp);

////////////////////////////////////////////////////////////////////////////

/** Get a temperature corresponding to #DDAQ_SET_TEMPUNIT from a temperature in degree Celsius (not for #DDAQ_TEMPUNIT_R).
@param		f64TempC		temperature in degree Celsius.
@return		temperature corresponding to #DDAQ_SET_TEMPUNIT
*/
DDAQ_F64	__stdcall DDAQ_TEMPC_2_TEMP(DDAQ_F64 f64TempC);

////////////////////////////////////////////////////////////////////////////

/** Get a temperature difference in Kelvin from a temperature corresponding to #DDAQ_SET_TEMPUNIT (not for #DDAQ_TEMPUNIT_R).
@param		f64TempDiff		temperature difference corresponding to #DDAQ_SET_TEMPUNIT.
@return		temperature difference in Kelvin
*/
DDAQ_F64	__stdcall DDAQ_TEMPDIFF_2_TEMPDIFFK(DDAQ_F64 f64TempDiff);

////////////////////////////////////////////////////////////////////////////

/** Get a temperature difference corresponding to #DDAQ_SET_TEMPUNIT from a temperarure difference in Kelvin (degree Celsius) (not for #DDAQ_TEMPUNIT_R).
@param		f64TempDiffK	temperature in Kelvin (degree Celsius).
@return		temperature difference corresponding to #DDAQ_SET_TEMPUNIT
*/
DDAQ_F64	__stdcall DDAQ_TEMPDIFFK_2_TEMPDIFF(DDAQ_F64 f64TempDiffK);

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_SET_DEVICE_IP_xxxx
////////////////////////////////////////////////////////////////////////////

/** MBCS: Set camera IP to static IP. This can take up to 60 seconds. 
@param		sz8CameraID			pointer to a NULL-terminated MBCS string of the camera ID (e.g. "C1234567")
@param		sz8IPAddress		pointer to a NULL-terminated MBCS string for theIP address(e.g. "192.168.2.220")
@param		sz8SubnetMask		pointer to a NULL-terminated MBCS string for the subnet mask (e.g. "255.255.255.0")
@param		sz8Gateway			pointer to a NULL-terminated MBCS string for the gateway (e.g. "0.0.0.0") (for none)
@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32 __stdcall DDAQ_SET_DEVICE_IP_STATIC(DDAQ_PC_CHAR8 sz8CameraID, DDAQ_PC_CHAR8 sz8IPAddress, DDAQ_PC_CHAR8 sz8SubnetMask, DDAQ_PC_CHAR8 sz8Gateway);

/** Unicode UTF-16: Set camera IP to static IP. This can take up to 60 seconds.
@param		sz16CameraID		pointer to a NULL-terminated Unicode string of the camera ID (e.g. "C1234567")
@param		sz16IPAddress		pointer to a NULL-terminated Unicode string for theIP address (e.g. "192.168.2.220")
@param		sz16SubnetMask		pointer to a NULL-terminated Unicode string for the subnet mask (e.g. "255.255.255.0")
@param		sz16Gateway			pointer to a NULL-terminated Unicode string for the gateway (e.g. "0.0.0.0") (for none)
@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32 __stdcall DDAQ_SET_DEVICE_IP_STATIC_UC(DDAQ_PC_CHAR16 sz16CameraID, DDAQ_PC_CHAR16 sz16IPAddress, DDAQ_PC_CHAR16 sz16SubnetMask, DDAQ_PC_CHAR16 sz16Gateway);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Set camera IP to DHCP/AutoIP. This can take up to 120 seconds.
@param		sz8CameraID			pointer to a NULL-terminated MBCS string of the camera ID (e.g. "C1234567")
@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32 __stdcall DDAQ_SET_DEVICE_IP_AUTO(DDAQ_PC_CHAR8 sz8CameraID);

/** Unicode UTF-16: Set camera IP to DHCP/Auto IP. This can take up to 120 seconds.
@param		sz16CameraID		pointer to a NULL-terminated Unicode string of the camera ID (e.g. "C1234567")
@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32 __stdcall DDAQ_SET_DEVICE_IP_AUTO_UC(DDAQ_PC_CHAR16 sz16CameraID);

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_DEVICE_DO_xxxx
////////////////////////////////////////////////////////////////////////////

/** Search for connected cameras, any open camera connections will be closed (refer also to \ref sec3_1)
	@return		number of devices (0 if no camera was found)
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_DETECTION();

////////////////////////////////////////////////////////////////////////////
/** MBCS: Get a device list of used cameras, with the possibility to search via UDP Broadcast for free cameras.
	@param		bSearch			true, if a new search for connected cameras should be executed  	
	@param		bCheckConnect	true, if the connection to the camera should be tested
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_LIST(DDAQ_BOOL bSearch, DDAQ_BOOL bCheckConnect, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get a device list of used cameras, with the possibility to search via UDP Broadcast for free cameras.
	@param		bSearch			true, if a new search for connected cameras should be executed
	@param		bCheckConnect	true, if the connection to the camera should be tested
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_LIST_UC(DDAQ_BOOL bSearch, DDAQ_BOOL bCheckConnect, DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////
/** Unicode UTF-8: Get a device list of used cameras, with the possibility to search via UDP Broadcast for free cameras.
	@param		bSearch			true, if a new search for connected cameras should be executed  	
	@param		bCheckConnect	true, if the connection to the camera should be tested
	@param		sz8Buf			pointer to a Null-terminated UTF-8 destination string (xml)
	@param		u32MaxNumChar	maximum number of characters (1 byte per char, recommended 10 kByte for each camera)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_LIST_XML(DDAQ_BOOL bSearch, DDAQ_BOOL bCheckConnect, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

////////////////////////////////////////////////////////////////////////////

/** Get the next free device number
	@param		pu32DeviceNo	pointer to next free device number (1 for the first, 0 if no device number is free)	
	@param		bSimu			true, if for simulation
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_FIND_FREE_DEVICENO(DDAQ_BOOL bSimu, DDAQ_P_U32 pu32DeviceNo);

////////////////////////////////////////////////////////////////////////////
/** MBCS: Open a camera connection for online data acquisition
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8FileName		pointer to a Null-terminated MBCS string (filename for template IRDX file)
								If sz8FileName is NULL, default settings are used
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_OPEN(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Open a camera connection for online data acquisition
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16FileName	pointer to a NULL-terminated Unicode string (filename for template IRDX file)
								If sz16FileName is NULL, default settings are used
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_OPEN_UC(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Open a camera connection (selected by the interface) for online data acquisition
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8Interface	pointer to a Null-terminated MBCS string of the interface (e.g. "192.168.2.200"))
	@param		sz8FileName		pointer to a Null-terminated MBCS string of the filename of a template IRDX file
								If sz8FileName is NULL, default settings are used
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_OPEN_INTERFACE(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR8 sz8Interface, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Open a camera connection (selected by the interface) for online data acquisition.
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16Interface	pointer to a Null-terminated Unicode string of the interface (e.g. "192.168.2.200"))
	@param		sz16FileName	pointer to a Null-terminated Unicode string of the filename of a template IRDX file
								If sz16FileName is NULL, default settings are used
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_OPEN_INTERFACE_UC(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR16 sz16Interface, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Change the template for an open camera
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8FileName		pointer to a Null-terminated MBCS string of the filename for a template IRDX file
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_CHANGE_TEMPLATE(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Change the template for an open camera
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16FileName	pointer to a Null-terminated Unicode string of the filename for a template IRDX file
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_CHANGE_TEMPLATE_UC(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Open a camera for simulation of data acquisition
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8FileName		pointer to a Null-terminated MBCS string of the filename for the simulation IRD file
								Use the included software tool "IRDX2IRD.exe" to convert an IRDX file to an IRD file
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_OPENSIMULATION(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Open a camera for simulation of data acquisition
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16FileName	pointer to a Null-terminated Unicode string of the filename for the simulation IRD file
								Use the included software tool "IRDX2IRD.exe" to convert an IRDX file to an IRD file
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_OPENSIMULATION_UC(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** Close a camera connection
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_CLOSE(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** Start continous data acquisition from a camera
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_START(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** Start one single shot data acquisition from a camera
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_STARTSINGLESHOT(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** Start one single shot data acquisition from a camera and wait for the data to be ready
	@param		u32DeviceNo		device number (1 for the first)	
	@param		u32Waitms			maximum waiting time (milliseconds)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_STARTSINGLESHOT_WAIT(DDAQ_U32 u32DeviceNo, DDAQ_U32 u32Waitms);

////////////////////////////////////////////////////////////////////////////

/** Stop data acquisition from a camera
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_STOP(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** Set trigger bit for software single trigger
	@param		u32DeviceNo		device number (1 for the first)	
	@param		bTrig			trigger command (1 set, 0 reset)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_SINGLETRIG(DDAQ_U32 u32DeviceNo, DDAQ_BOOL bTrig);

////////////////////////////////////////////////////////////////////////////

/** Set trigger bit for software sequence trigger
	@param		u32DeviceNo		device number (1 for the first)
	@param		bTrig			trigger command (1 set, 0 reset)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_SEQUENCETRIG(DDAQ_U32 u32DeviceNo, DDAQ_BOOL bTrig);

////////////////////////////////////////////////////////////////////////////

/** Execute a shutter procedure for the camera (cameras with shutter only, independend of shutter disable)
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_SHUTTERPROC(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** Operate motor focus (only for cameras with motor focus)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		u16Cmd			command for motor focus (refer to #DDAQ_MOTORFOCUS_CMD_STOP)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_MOTORFOCUS(DDAQ_U32 u32DeviceNo, DDAQ_U16 u16Cmd);

////////////////////////////////////////////////////////////////////////////

/** Update new data from the device to the connected internal IRDX memory file
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_UPDATEDATA(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** Enable sending the next data ready message (if messaging is active)
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_ENABLE_NEXTMSG(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Download an internal image from a portable camera (MIDAS) to an IRDX file (overwrites an existing file!)
	Only in compatibility mode of the DIASCam.dll, please see tool SetDetect.exe
	@param		u32DeviceNo		device number (1 for the first)
	@param		u16ImageIdx		image index (0 for the first)	
	@param		sz8FileName		pointer to a Null-terminated MBCS string (filename of IRDX file)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_DOWNLOADIMAGE(DDAQ_U32 u32DeviceNo, DDAQ_U16 u16ImageIdx, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Download an internal image from a portable camera (MIDAS) to an IRDX file (overwrites an existing file!)
	Only in compatibility mode of the DIASCam.dll, please see tool SetDetect.exe
	@param		u32DeviceNo		device number (1 for the first)
	@param		u16ImageIdx		image index (0 for the first)
	@param		sz16FileName	pointer to a Null-terminated Unicode string (filename of IRDX file)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_DOWNLOADIMAGE_UC(DDAQ_U32 u32DeviceNo, DDAQ_U16 u16ImageIdx, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Download all internal images from a portable camera (M8, TP8) to JPG files (overwrites existing files!)
	Only in compatibility mode of the DIASCam.dll, please see tool SetDetect.exe
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz8FileName		pointer to a Null-terminated MBCS string with placeholder for index (e.g. "C:\Data_%.4i.jpg")
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_DOWNLOADALLIMAGES(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Download all internal images from a portable camera (M8, TP8) to JPG files (overwrites existing files!)
	Only in compatibility mode of the DIASCam.dll, please see tool SetDetect.exe
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16FileName	pointer to a Null-terminated Unicode string with placeholder for index (e.g. "C:\Data_%.4i.jpg")
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_DOWNLOADALLIMAGES_UC(DDAQ_U32 u32DeviceNo, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** Delete all internal images from a portable camera (MIDAS, M8, TP8)
	@param		u32DeviceNo		device number (1 for the first)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_DO_DELETEIMAGES(DDAQ_U32 u32DeviceNo);

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_DEVICE_GET_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get the device identification (number and type) from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu32ID			pointer to ID number.
	@param		pu32Type		pointer to ID type (refer to #DDAQ_DEVICE_TYPE_INVALID)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_ID(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32ID, DDAQ_P_U32 pu32Type);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the device identification string from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8ID			pointer to character buffer for a NULL-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_IDSTRING(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR8 sz8ID, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the device identification string from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16ID			pointer to character buffer for a NULL-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_IDSTRING_UC(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR16 sz16ID, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the extended device identification string from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8IDName		pointer to character buffer for a NULL-terminated MBCS destination string (ID Name e.g. "PYROVIEW 380")
	@param		u32MaxNumCharN	maximum number of characters (1 byte per char) (ID Name)
	@param		sz8IDSN			pointer to character buffer for a NULL-terminated MBCS destination string (ID SN e.g. "C11234567")
	@param		u32MaxNumCharSN	maximum number of characters (1 byte per char) (ID SN)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_IDSTRING_EX(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR8 sz8IDName, DDAQ_U32 u32MaxNumCharN, DDAQ_P_CHAR8 sz8IDSN, DDAQ_U32 u32MaxNumCharSN);

/** Unicode UTF-16: Get the extended device identification string from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16IDName		pointer to character buffer for a NULL-terminated Unicode destination string (ID Name e.g. "PYROVIEW 380")
	@param		u32MaxNumWCharN	maximum number of wide characters (2 bytes per wchar) (ID Name)
	@param		sz16IDSN		pointer to character buffer for a NULL-terminated Unicode destination string (ID SN e.g. "C1234567")
	@param		u32MaxNumWCharSN	maximum number of wide characters (2 bytes per wchar) (ID SN)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_IDSTRING_EX_UC(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR16 sz16IDName, DDAQ_U32 u32MaxNumWCharN, DDAQ_P_CHAR16 sz16IDSN, DDAQ_U32 u32MaxNumWCharSN);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the camera interface string (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_INTERFACESTRING(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the camera interface string (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_INTERFACESTRING_UC(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** Unicode UTF-8: Get the device information string from the camera
	@param		u32DeviceNo		device number (1 for the first)	
	@param		sz8Buf			pointer to a Null-terminated UTF-8 destination string (xml)
	@param		u32MaxNumChar	maximum number of characters (1 byte per char, recommended 10 kByte)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_INFORMATIONSTRING(DDAQ_U32 u32DeviceNo, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

////////////////////////////////////////////////////////////////////////////

/** Get the number of available measurement ranges (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pNum			pointer to number of available measurement ranges
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_NUMMRANGES(DDAQ_U32 u32DeviceNo, DDAQ_P_U16 pNum);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the measurement range information string from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		u16Range		measurement range (1 for the first)
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_MRANGESTRING(DDAQ_U32 u32DeviceNo, DDAQ_U16 u16Range, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the measurement range information string from the camera (works after device detection, even if device is not open)
	@param		u32DeviceNo		device number (1 for the first)
	@param		u16Range		measurement range (1 for the first)
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_MRANGESTRING_UC(DDAQ_U32 u32DeviceNo, DDAQ_U16 u16Range, DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** Get the connected internal IRDX memory handle from a device
	@param		u32DeviceNo		device number (1 for the first)	
	@param		phIRDX			pointer to the connected IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_IRDX(DDAQ_U32 u32DeviceNo, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** Get the new data ready state
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pbReady			pointer to new data ready	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_NEWDATAREADY(DDAQ_U32 u32DeviceNo, DDAQ_P_BOOL pbReady);

////////////////////////////////////////////////////////////////////////////

/** Get the actual data update frequency
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pf32Frequ			pointer to data update frequency (Hz)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_UPDATEFREQUENCY(DDAQ_U32 u32DeviceNo, DDAQ_P_F32 pf32Frequ);

////////////////////////////////////////////////////////////////////////////

/** Get the current device errors and lost data information from the camera
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu32Info		pointer to information buffer: 
				pu32Info[0]		current error state: 0: no error, >0: error, refer to #DDAQ_DEVICE_ERROR_BITMASK_ERROR_ANY 
				pu32Info[1]		number of internal reconnections
				pu32Info[2]		lost data level 2 (DIASCam OUT)
				pu32Info[3]		lost data level 1 (DIASCam IN)
				pu32Info[4]		for u32BufSizelost 5*sizeof(DDAQ_U32): data level 0 (HIWORD: Ethernet frames, LOWORD: Ethernet packets)
				pu32Info[4]		for u32BufSizelost 6*sizeof(DDAQ_U32): data level 0 (Ethernet frames)
				pu32Info[5]		for u32BufSizelost 6*sizeof(DDAQ_U32): data level 0 (Ethernet packets)
	@param		u32BufSize		buffer size (bytes)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_ERRORS(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32Info, DDAQ_U32 u32BufSize);

////////////////////////////////////////////////////////////////////////////

/** Get the current state of the camera digital inputs and ouputs
	In stop mode the values of the inputs and outputs are updated every second  
	In running mode the values of the inputs are updated with every image from the camera  
	In running mode the values of the outputs are not updated  
	@param		u32DeviceNo		device number (1 for the first)
	@param		pu32DIN			current state of the digital intputs: 
	@param		pu32DIN			Bit 0: IN0 
	@param		pu32DIN			Bit 1: IN1
	@param		pu32DIN			Bit 2: IN2 (same like IN0)
	@param		pu32DIN			Bit 3: IN3 (same like IN1)
	@param		pu32DIN			if the Bit is "0", the input channel is closed (trigger active)
	@param		pu32DIN			if the Bit is "1", the input channel is open (trigger inactive)
	@param		pu32DIN			Bit 16: OUT0 (if usable)
	@param		pu32DIN			Bit 17: OUT1 (if usable)
	@param		pu32DIN			if the Bit is "1", the output channel  is closed (no alarm)
	@param		pu32DIN			if the Bit is "0", the output channel  is open (alarm)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_DINOUT(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32DIN);

////////////////////////////////////////////////////////////////////////////

/** Get the current state of the camera digital inputs and ouputs
	Same as #DDAQ_DEVICE_GET_DINOUT but sent directly to the camera
	The values of the inputs and outputs are updated by directly sending a command to the camera  
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_DINOUT_DIRECT(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32DIN);

////////////////////////////////////////////////////////////////////////////

/** Get the camera mode
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pbOK			pointer to camera mode OK ([true/false] is [OK/Error])
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_CAMERAMODEOK(DDAQ_U32 u32DeviceNo, DDAQ_P_BOOL pbOK);

////////////////////////////////////////////////////////////////////////////

/** Get the detector temperature
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pf32Temp		pointer to detector temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pbOK			pointer to detector temperature OK ([true/false] temperature [OK/Error])
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_DETECTORTEMP(DDAQ_U32 u32DeviceNo, DDAQ_P_F32 pf32Temp, DDAQ_P_BOOL pbOK);

////////////////////////////////////////////////////////////////////////////

/** Get the camera housing temperature
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pf32Temp		pointer to camera temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pbOK			pointer to camera temperature OK ([true/false] temperature [OK/Error])
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_CAMERATEMP(DDAQ_U32 u32DeviceNo, DDAQ_P_F32 pf32Temp, DDAQ_P_BOOL pbOK);

////////////////////////////////////////////////////////////////////////////

/** Get the current device state
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu32State		pointer to state buffer: 
				pu32State[0]	current acquisition state: 0 - stopped, 1 - running 
				pu32State[1]	current shutter state: 0 - open, 1 - closed 
	@param		u32BufSize		buffer size (bytes)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_STATE(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32State, DDAQ_U32 u32BufSize);

////////////////////////////////////////////////////////////////////////////

/** Get the number of internal images saved on a portable camera
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu16NumImages	pointer to number of images	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_NUMIMAGES(DDAQ_U32 u32DeviceNo, DDAQ_P_U16 pu16NumImages);

////////////////////////////////////////////////////////////////////////////

/** Get the internal image number (consecutive, reset at start of data acquisition)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu32ImageNo		pointer to image number	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_ACQUIMAGENO(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32ImageNo);

///////////////////////////////////////////////////////////////////////////

/** Get the usage of digital IN and OUT at the camera
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu32UsageIN		pointer to usage IN buffer: 
				pu32UsageIN[0]	usage of IN0 (refer to #DDAQ_UsageIN0_NA)
				pu32UsageIN[1]	usage of IN1 (refer to #DDAQ_UsageIN1_NA) 
	@param		pu32UsageOUT	pointer to usage OUT buffer: 
				pu32UsageOUT[0]	usage of OUT0 (refer to #DDAQ_UsageOUT0_NA)
				pu32UsageOUT[1]	usage of OUT1 (refer to #DDAQ_UsageOUT1_NA) 
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_USAGE_DINDOUT(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32UsageIN, DDAQ_P_U32 pu32UsageOUT);

///////////////////////////////////////////////////////////////////////////

/** Set the usage of digital IN and OUT at the camera
	@param		u32DeviceNo		device number (1 for the first)
	@param		pu32UsageIN		pointer to usage IN buffer:
				pu32UsageIN[0]	usage of IN0 (refer to #DDAQ_UsageIN0_NA)
				pu32UsageIN[1]	usage of IN1 (refer to #DDAQ_UsageIN1_NA)
	@param		pu32UsageOUT	pointer to usage OUT buffer:
				pu32UsageOUT[0]	usage of OUT0 (refer to #DDAQ_UsageOUT0_NA)
				pu32UsageOUT[1]	usage of OUT1 (refer to #DDAQ_UsageOUT1_NA)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_SET_USAGE_DINDOUT(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32UsageIN, DDAQ_P_U32 pu32UsageOUT);

///////////////////////////////////////////////////////////////////////////

/** Get the motor focus version
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu32Version		pointer to version (refer to #DDAQ_MOTORFOCUS_VERS_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_MOTOR_FOCUS_VERSION(DDAQ_U32 u32DeviceNo, DDAQ_P_U32 pu32Version);

///////////////////////////////////////////////////////////////////////////

/** Get the motor focus user position (if available)
	@param		u32DeviceNo		device number (1 for the first)	
	@param		pu16UserPos		user position
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_GET_MOTOR_FOCUS_USERPOS(DDAQ_U32 u32DeviceNo, DDAQ_P_U16 pu16UserPos);

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_DEVICE_SET_xxxx
////////////////////////////////////////////////////////////////////////////

/** Set the current state of the camera digital outputs
	@param		u32DeviceNo		device number (1 for the first)
	@param		u32DOUT			new state of the digital output: 
	@param		u32DOUT			Bit  0: OUT 0 (if usable)
	@param		u32DOUT			Bit  1: OUT 1 (if usable)
	@param		u32DOUT			if the Bit 0/1 is "0", the output channel goes to closed state (no alarm)
	@param		u32DOUT			if the Bit 0/1 is "1", the output channel goes to open state (alarm)
	@param		u32DOUT			Bit 16: mask for OUT 0 (if usable)
	@param		u32DOUT			Bit 17: mask for OUT 1 (if usable)
	@param		u32DOUT			only if the Bit 16/17 is "1", the corresonding output channel is effected
	@param		u32DOUT			if the mask is set to 0 completely, the values are used without mask
	@param		u32DOUT			e.g. Set OUT0 to open:		0x00010001
	@param		u32DOUT			e.g. Set OUT0 to closed:    0x00010000
	@param		u32DOUT			e.g. Set OUT1 to open:		0x00020002
	@param		u32DOUT			e.g. Set OUT1 to closed:    0x00020000	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_SET_DOUT(DDAQ_U32 u32DeviceNo, DDAQ_U32 u32DOUT);

////////////////////////////////////////////////////////////////////////////

/** Set a window handle for the data message 
	A windows message (#DDAQ_WM_DATAMSG, device number in WPARAM) is sent after new data are ready
	#DDAQ_DEVICE_DO_UPDATEDATA can be used to read the data
	Only after #DDAQ_DEVICE_DO_ENABLE_NEXTMSG was called a new message is sent
    @param		u32DeviceNo		device number (1 for the first)	
	@param		hWnd			HANDLE of the window, which will receive the messages (0 to disable)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_SET_MSGHWND(DDAQ_U32 u32DeviceNo, DDAQ_HANDLE hWnd);

////////////////////////////////////////////////////////////////////////////

/** Set a thread ID for the data message 
	A thread message (#DDAQ_WM_DATAMSG, device number in WPARAM) is sent when new data are ready
	#DDAQ_DEVICE_DO_UPDATEDATA can be used to read the data
	Only after #DDAQ_DEVICE_DO_ENABLE_NEXTMSG was called a new message is sent
    @param		u32DeviceNo		device number (1 for the first)	
	@param		u32ThreadID		ID of the thread, which will receive the messages (0 to disable)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_SET_MSGTHREAD(DDAQ_U32 u32DeviceNo, DDAQ_U32 u32ThreadID);

////////////////////////////////////////////////////////////////////////////

/** Set an event handle for the data event 
	An event is signaled when new data are ready
	#DDAQ_DEVICE_DO_UPDATEDATA can be used to read the data
    @param		u32DeviceNo		device number (1 for the first)	
	@param		hEvent			HANDLE of the event, which will receive the messages (-1 to disable)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_DEVICE_SET_MSGHEVENT(DDAQ_U32 u32DeviceNo, DDAQ_HANDLE hEvent);

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_FILE_xxxx
////////////////////////////////////////////////////////////////////////////

/** MBCS: Delete an IRDX file on disk
	@param		sz8FileName		pointer to a Null-terminated MBCS string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_DELETE(DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Delete an IRDX file on disk
	@param		sz16FileName	pointer to a Null-terminated Unicode string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_DELETE_UC(DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the IRDX file size on disk
	@param		sz8FileName		pointer to a Null-terminated MBCS string
	@param		pf64FileSizeMB	pointer to file size (MB)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_GETSIZE(DDAQ_PC_CHAR8 sz8FileName, DDAQ_P_F64 pf64FileSizeMB);

/** Unicode UTF-16: Get the IRDX file size on disk
	@param		sz16FileName	pointer to a Null-terminated Unicode string
	@param		pf64FileSizeMB	pointer to file size (MB)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_GETSIZE_UC(DDAQ_PC_CHAR16 sz16FileName, DDAQ_P_F64 pf64FileSizeMB);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Rename an IRDX file on disk
	@param		sz8FileNameOld	pointer to a Null-terminated MBCS string
	@param		sz8FileNameNew	pointer to a Null-terminated MBCS string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_RENAME(DDAQ_PC_CHAR8 sz8FileNameOld, DDAQ_PC_CHAR8 sz8FileNameNew);

/** Unicode UTF-16: Rename an IRDX file on disk
	@param		sz16FileNameOld	pointer to a Null-terminated Unicode string
	@param		sz16FileNameNew	pointer to a Null-terminated Unicode string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_RENAME_UC(DDAQ_PC_CHAR16 sz16FileNameOld, DDAQ_PC_CHAR16 sz16FileNameNew);

////////////////////////////////////////////////////////////////////////////

/** Open an empty IRDX memory file
	@param		phIRDX			pointer to created IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_MEM(DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** Open an empty extended (user defined) IRDX memory file
	@param		hIRDXFrom		IRDX handle	
	@param		u16SizeX		Size X of the IRDX file
	@param		u16SizeY		Size Y of the IRDX file
	@param		bClearData		clear output data
	@param		phIRDX			pointer to created IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_MEM_EX(DDAQ_HANDLE hIRDXFrom, DDAQ_U16 u16SizeX, DDAQ_U16 u16SizeY, DDAQ_BOOL bClearData, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** Clone an IRDX memory file
	@param		pIRDXSource		source IRDX memory handle
	@param		phIRDX			pointer to created IRDX memory handle
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_CLONE_MEM(DDAQ_HANDLE pIRDXSource, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Open an IRDX from a file for readingg
	@param		sz8FileName		pointer to a Null-terminated MBCS string
	@param		bAll			[true/false] is [all/only the first data set]
	@param		phIRDX			pointer to created IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_READ(DDAQ_PC_CHAR8 sz8FileName, DDAQ_BOOL bAll, DDAQ_P_HANDLE phIRDX);

/** Unicode UTF-16: Open an IRDX from a file for reading
	@param		sz16FileName	pointer to a Null-terminated Unicode string
	@param		bAll			[true/false] is [all/only the first data set]
	@param		phIRDX			pointer to created IRDX memory handle
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_READ_UC(DDAQ_PC_CHAR16 sz16FileName, DDAQ_BOOL bAll, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Open an IRDX file for writing
	@param		sz8FileName		pointer to a Null-terminated MBCS string
	@param		bAppend			[true/false] [append/delete] an existing file
	@param		phIRDX			pointer to created IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_WRITE(DDAQ_PC_CHAR8 sz8FileName, DDAQ_BOOL bAppend, DDAQ_P_HANDLE phIRDX);

/** Unicode UTF-16: Open an IRDX file for writing
	@param		sz16FileName	pointer to a Null-terminated Unicode string
	@param		bAppend			[true/false] [append/delete] an existing file
	@param		phIRDX			pointer to created IRDX memory handle
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_WRITE_UC(DDAQ_PC_CHAR16 sz16FileName, DDAQ_BOOL bAppend, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Open an IRDX file for reading and writing
	@param		sz8FileName		pointer to a Null-terminated MBCS string
	@param		bAppend			[true/false] [append/delete] an existing file
	@param		phIRDX			pointer to IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_READWRITE(DDAQ_PC_CHAR8 sz8FileName, DDAQ_BOOL bAppend, DDAQ_P_HANDLE phIRDX);

/** Unicode UTF-16: Open an IRDX file for reading and writing
	@param		sz16FileName	pointer to a Null-terminated Unicode string
	@param		bAppend			[true/false] [append/delete] an existing file
	@param		phIRDX			pointer to IRDX memory handle
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_OPEN_READWRITE_UC(DDAQ_PC_CHAR16 sz16FileName, DDAQ_BOOL bAppend, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** Close an open IRDX file
	@param		hIRDX			IRDX handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_CLOSE(DDAQ_HANDLE hIRDX);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Save an IRDX file to disk (overwrite an existing file!)
	@param		hIRDX			IRDX handle (type MEM, READ, or READWRITE)	
	@param		sz8FileName		pointer to a Null-terminated MBCS string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_SAVE(DDAQ_HANDLE hIRDX, DDAQ_PC_CHAR8 sz8FileName);

/** Unicode UTF-16: Save an IRDX file to disk (overwrite an existing file!)
	@param		hIRDX			IRDX handle (type MEM, READ, or READWRITE)
	@param		sz16FileName	pointer to a Null-terminated Unicode string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_SAVE_UC(DDAQ_HANDLE hIRDX, DDAQ_PC_CHAR16 sz16FileName);

////////////////////////////////////////////////////////////////////////////

/** Add all data sets from one IRDX file to another IRDX file
	@param		hIRDX			IRDX handle (type MEM, WRITE, or READWRITE)	
	@param		hIRDXAdd		IRDX handle (will be added to hIRDX)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_ADD_IRDX(DDAQ_HANDLE hIRDX, DDAQ_HANDLE hIRDXAdd);

////////////////////////////////////////////////////////////////////////////

/** Add the current data set from one IRDX file to another IRDX file
	@param		hIRDX			IRDX handle (type MEM, WRITE, or READWRITE)	
	@param		hIRDXAdd		IRDX handle (will be added to hIRDX)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_ADD_IRDX_CURDATASET(DDAQ_HANDLE hIRDX, DDAQ_HANDLE hIRDXAdd);

////////////////////////////////////////////////////////////////////////////

/** Get the number of data sets from an IRDX file
	@param		hIRDX			IRDX handle	
	@param		pu32NumDS		pointer to number of data sets
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_GET_NUMDATASETS(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32NumDS);

////////////////////////////////////////////////////////////////////////////

/** Get the current selected data set from an IRDX file
	@param		hIRDX			IRDX handle	
	@param		pu32DSIdx			pointer to the data set index (0...)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_GET_CURDATASET(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32DSIdx);

////////////////////////////////////////////////////////////////////////////

/** Select a data set from an IRDX file
	@param		hIRDX			IRDX handle	
	@param		u32DSIdx		data set index (0...)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_SET_CURDATASET(DDAQ_HANDLE hIRDX, DDAQ_U32 u32DSIdx);

////////////////////////////////////////////////////////////////////////////

/** Remove a data set from an IRDX file
	@param		hIRDX			IRDX handle	
	@param		u32DSIdx		data set index (0...) to be removed
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_REMOVE_DATASET(DDAQ_HANDLE hIRDX, DDAQ_U32 u32DSIdx);

////////////////////////////////////////////////////////////////////////////

/** Get the modified state of an IRDX file
	@param		hIRDX			IRDX handle	
	@param		pbModified		pointer to modified
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_GET_MODIFIED(DDAQ_HANDLE hIRDX, DDAQ_P_BOOL pbModified);

////////////////////////////////////////////////////////////////////////////
/** Lock the access to an IRDX handle
	@param		hIRDX			IRDX handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_LOCK(DDAQ_HANDLE hIRDX);				

////////////////////////////////////////////////////////////////////////////
/** Unlock the access to an IRDX handle
	@param		hIRDX			IRDX handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_FILE_UNLOCK(DDAQ_HANDLE hIRDX);				

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_DEVICE_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get the device identification (number and type)
	@param		hIRDX			IRDX handle	
	@param		pu32ID			pointer to ID number
	@param		pu32Type		pointer to ID type (refer to #DDAQ_DEVICE_TYPE_INVALID)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_ID(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32ID, DDAQ_P_U32 pu32Type);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the internal device identification string
	@param		hIRDX			IRDX handle	
	@param		sz8ID			pointer to character buffer for a NULL-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_IDSTRING(DDAQ_HANDLE hIRDX, DDAQ_P_CHAR8 sz8ID, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the internal device identification string
	@param		hIRDX			IRDX handle
	@param		sz16ID			pointer to character buffer for a NULL-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_IDSTRING_UC(DDAQ_HANDLE hIRDX, DDAQ_P_CHAR16 sz16ID, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the extended device identification string
	@param		hIRDX			IRDX handle	
	@param		sz8IDName		pointer to character buffer for a NULL-terminated MBCS destination string (ID Name e.g. "PYROVIEW 380")
	@param		u32MaxNumCharN	maximum number of characters (1 byte per char) (ID Name)
	@param		sz8IDSN			pointer to character buffer for a NULL-terminated MBCS destination string (ID SN e.g. "C1234567")
	@param		u32MaxNumCharSN	maximum number of characters (1 byte per char) (ID SN)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_IDSTRING_EX(DDAQ_HANDLE hIRDX, DDAQ_P_CHAR8 sz8IDName, DDAQ_U32 u32MaxNumCharN, DDAQ_P_CHAR8 sz8IDSN, DDAQ_U32 u32MaxNumCharSN);

/** Unicode UTF-16: Get the extended device identification string
	@param		hIRDX			IRDX handle
	@param		sz16IDName		pointer to character buffer for a NULL-terminated Unicode destination string (ID Name e.g. "PYROVIEW 380")
	@param		u32MaxNumWCharN	maximum number of wide characters (2 bytes per wchar) (ID Name)
	@param		sz16IDSN		pointer to character buffer for a NULL-terminated Unicode destination string (ID SN e.g. "C1234567")
	@param		u32MaxNumWCharSN	maximum number of wide characters (2 bytes per wchar) (ID SN)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_IDSTRING_EX_UC(DDAQ_HANDLE hIRDX, DDAQ_P_CHAR16 sz16IDName, DDAQ_U32 u32MaxNumWCharN, DDAQ_P_CHAR16 sz16IDSN, DDAQ_U32 u32MaxNumWCharSN);

////////////////////////////////////////////////////////////////////////////

/** Get measurement temperature range min and max
	@param		hIRDX			IRDX handle	
	@param		pf32Min			pointer to measurement minimum value (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pf32Max			pointer to measurement maximum value (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_MRANGEMINMAX(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Min, DDAQ_P_F32 pf32Max);

////////////////////////////////////////////////////////////////////////////

/** Get the internal frame rate of the camera without averaging and frame rate divider
	@param		hIRDX			IRDX handle	
	@param		pf32FR			pointer to the cameras internal frame rate (frames per second: Hz)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_INTERNALFPS(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32FR);

////////////////////////////////////////////////////////////////////////////

/** Get the camera mode
	@param		hIRDX			IRDX handle	
	@param		pbOK			pointer to camera mode OK ([true/false] is [OK/Error])
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_CAMERAMODEOK(DDAQ_HANDLE hIRDX, DDAQ_P_BOOL pbOK);

////////////////////////////////////////////////////////////////////////////

/** Get the detector temperature
	@param		hIRDX			IRDX handle	
	@param		pf32Temp		pointer to detector temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pbOK			pointer to detector temperature OK ([true/false] temperature [OK/Error])
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_DETECTORTEMP(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Temp, DDAQ_P_BOOL pbOK);

////////////////////////////////////////////////////////////////////////////

/** Get the camera housing temperature
	@param		hIRDX			IRDX handle	
	@param		pf32Temp		pointer to camera temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pbOK			pointer to camera temperature OK ([true/false] temperature [OK/Error])
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_CAMERATEMP(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Temp, DDAQ_P_BOOL pbOK);

////////////////////////////////////////////////////////////////////////////

/** Update status information (camera temperature, detector temperature, camera mode) from one IRDX to another
	@param		hIRDXFrom		source IRDX handle	
	@param		hIRDXTo			destination IRDX handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_DO_UPDATE_STATE(DDAQ_HANDLE hIRDXFrom, DDAQ_HANDLE hIRDXTo);

////////////////////////////////////////////////////////////////////////////

/** Get the internal image number
	@param		hIRDX			IRDX handle	
	@param		pu32ImageNo		pointer to image number	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_DEVICE_GET_ACQUIMAGENO(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32ImageNo);

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_OBJECT_xxxx 
////////////////////////////////////////////////////////////////////////////

/** Get relative emissivity of measurement object for the current data set
	@param		hIRDX			IRDX handle	
	@param		pf32Emiss		pointer to emissivity (0.1 - 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_GET_EMISSIVITY(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Emiss);

////////////////////////////////////////////////////////////////////////////

/** Set relative fix emissivity of measurement object for the current data set
	@param		hIRDX			IRDX handle	
	@param		f32Emiss		new emissivity (0.1 - 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_EMISSIVITY(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Emiss);

////////////////////////////////////////////////////////////////////////////

/** Set relative fix emissivity of measurement object for all data sets of a sequence
	@param		hIRDX			IRDX handle
	@param		f32Emiss		new emissivity (0.1 - 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_EMISSIVITY_ALLDATASETS(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Emiss);

////////////////////////////////////////////////////////////////////////////

/** Get transmission of measurement distance for the current data set
	@param		hIRDX			IRDX handle	
	@param		pf32Trans		pointer to transmission (0.1 - 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_GET_TRANSMISSION(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Trans);

////////////////////////////////////////////////////////////////////////////

/** Set fix transmission of measurement distance for the current data set
	@param		hIRDX			IRDX handle	
	@param		f32Trans		new transmission (0.1 - 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_TRANSMISSION(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Trans);

////////////////////////////////////////////////////////////////////////////

/** Set fix transmission of measurement distance for all data sets of a sequence
	@param		hIRDX			IRDX handle
	@param		f32Trans		new transmission (0.1 - 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_TRANSMISSION_ALLDATASETS(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Trans);

////////////////////////////////////////////////////////////////////////////

/** Get ambient temperature of measurement object for the current data set
	@param		hIRDX			IRDX handle	
	@param		pf32AmbTemp		pointer to ambient temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_GET_AMBIENTTEMP(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32AmbTemp);

////////////////////////////////////////////////////////////////////////////

/** Set fix ambient temperature of measurement object for the current data set
	@param		hIRDX			IRDX handle	
	@param		f32AmbTemp		new ambient temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_AMBIENTTEMP(DDAQ_HANDLE hIRDX, DDAQ_F32 f32AmbTemp);

////////////////////////////////////////////////////////////////////////////

/** Set fix ambient temperature of measurement object for all data sets of a sequence
	@param		hIRDX			IRDX handle
	@param		f32AmbTemp		new ambient temperature (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_AMBIENTTEMP_ALLDATASETS(DDAQ_HANDLE hIRDX, DDAQ_F32 f32AmbTemp);

////////////////////////////////////////////////////////////////////////////

/** Get partial temperature validity
	@param		hIRDX			IRDX handle	
	@param		pbEnable		pointer to bool for enable validity range ([true/false] is [partial temperature range/whole measurement range]
	@param		pf32TempMin		pointer to minimum temperature limit (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pf32TempMax		pointer to maximum temperature limit (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_GET_TEMPVALIDITY(DDAQ_HANDLE hIRDX, DDAQ_P_BOOL pbEnable, DDAQ_P_F32 pf32TempMin, DDAQ_P_F32 pf32TempMax);

////////////////////////////////////////////////////////////////////////////

/** Set partial temperature validity
	@param		hIRDX			IRDX handle	
	@param		bEnable			enable validity range ([true/false] is [partial temperature range/whole measurement range]
	@param		f32TempMin		minimum temperature limit (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		f32TempMax		maximum temperature limit (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_TEMPVALIDITY(DDAQ_HANDLE hIRDX, DDAQ_BOOL bEnable, DDAQ_F32 f32TempMin, DDAQ_F32 f32TempMax);

////////////////////////////////////////////////////////////////////////////

/** Calculate emissivity based on a given pixel temperature
	@param		hIRDX			IRDX handle	
	@param		u16x			x co-ordinate of point (1 ... sizex)
	@param		u16y			y co-ordinate of point (1 ... sizey)
	@param		f32DestTemp		destination temperature (corresponding to #DDAQ_SET_TEMPUNIT) of pixel
	@param		pf32CalcEmiss	pointer to calculated emissivity
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_GET_PIXEL_EMISSIVITY(DDAQ_HANDLE hIRDX, DDAQ_U16 u16x, DDAQ_U16 u16y, DDAQ_F32 f32DestTemp, DDAQ_P_F32 pf32CalcEmiss);

////////////////////////////////////////////////////////////////////////////

/** Get offset correction value for the current data set
	@param		hIRDX			IRDX handle	
	@param		pf32OfsTemp		pointer to current offset correction temperature (corresponding to #DDAQ_SET_TEMPUNIT)
*/
DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_GET_OFFSET(HANDLE hIRDX, DDAQ_P_F32 pf32OfsTemp);

////////////////////////////////////////////////////////////////////////////

/** Set fix offset correction value for the current data set 
	@param		hIRDX			IRDX handle
	@param		f32OfsTemp		current offset correction temperature (corresponding to #DDAQ_SET_TEMPUNIT, not for DDAQ_TEMPUNIT_R)
*/

DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_OFFSET(HANDLE hIRDX, DDAQ_F32 f32OfsTemp);

////////////////////////////////////////////////////////////////////////////

/** Set fix offset correction value for all data sets of a sequence
	@param		hIRDX			IRDX handle
	@param		f32OfsTemp		current offset correction temperature (corresponding to #DDAQ_SET_TEMPUNIT, not for DDAQ_TEMPUNIT_R)
*/

DDAQ_U32	__stdcall DDAQ_IRDX_OBJECT_SET_OFFSET_ALLDATASETS(HANDLE hIRDX, DDAQ_F32 f32OfsTemp);

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_ACQUISITION_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get the time stamp of the current acquisition
	@param		hIRDX			IRDX handle	
	@param		pi32Year		pointer to time stamp year
	@param		pi32Month		pointer to time stamp month
	@param		pi32Day			pointer to time stamp day
	@param		pi32Hour		pointer to time stamp hour
	@param		pi32Min			pointer to time stamp minute
	@param		pi32Sec			pointer to time stamp second
	@param		pi32MSec		pointer to time stamp millisecond
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_TIMESTAMP(DDAQ_HANDLE hIRDX, 
				   DDAQ_P_I32 pi32Year, DDAQ_P_I32 pi32Month, DDAQ_P_I32 pi32Day,
				   DDAQ_P_I32 pi32Hour, DDAQ_P_I32 pi32Min, DDAQ_P_I32 pi32Sec, DDAQ_P_I32 pi32MSec);

////////////////////////////////////////////////////////////////////////////

/** Get parameter fix averaging
	@param		hIRDX			IRDX handle	
	@param		pu16Av			pointer to averaging (1,2,4,8,...,8192(0x2000))
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_AVERAGING(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Av);

////////////////////////////////////////////////////////////////////////////

/** Set parameter fix averaging
	@param		hIRDX			IRDX handle	
	@param		u16Av			new averaging (1,2,4,8,...,8192(0x2000))
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_AVERAGING(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Av);

////////////////////////////////////////////////////////////////////////////

/** Get parameter frame rate divider
	@param		hIRDX			IRDX handle	
	@param		pu16FRD			pointer to divider (0: not available, 1,2,3,...,255)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_FRDIVIDER(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16FRD);

////////////////////////////////////////////////////////////////////////////

/** Set parameter frame rate divider
	@param		hIRDX			IRDX handle	
	@param		u16FRD			new divider (1,2,3,...,255)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_FRDIVIDER(DDAQ_HANDLE hIRDX, DDAQ_U16 u16FRD);

////////////////////////////////////////////////////////////////////////////

/** Get parameter fps (for devices with fps parameter)
	@param		hIRDX			IRDX handle
	@param		pf32FPS			pointer to fps
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_FPS(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32FPS);

////////////////////////////////////////////////////////////////////////////

/** Set parameter fps (for devices with fps parameter)
	@param		hIRDX			IRDX handle
	@param		f32FPS			fps
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_FPS(DDAQ_HANDLE hIRDX, DDAQ_F32 f32FPS);

////////////////////////////////////////////////////////////////////////////

/** Get parameter weighted averaging
	@param		hIRDX			IRDX handle	
	@param		pf32Weight		pointer to weighting factor of new value (>0.0 ... 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_AVERAGING_MOV(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Weight);

////////////////////////////////////////////////////////////////////////////

/** Set parameter weighted averaging
	@param		hIRDX			IRDX handle	
	@param		f32Weight		Weighting factor of new value (>0.0 ... 1.0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_AVERAGING_MOV(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Weight);

////////////////////////////////////////////////////////////////////////////

/** Get measurement range
	@param		hIRDX			IRDX handle	
	@param		pu16MR			pointer to measurement range (1,2,3 ...)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_MRANGE(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16MR);

////////////////////////////////////////////////////////////////////////////

/** Set measurement range
	@param		hIRDX			IRDX handle	
	@param		u16MR			new measurement range (1,2,3, ...)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_MRANGE(DDAQ_HANDLE hIRDX, DDAQ_U16 u16MR);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the measurement range information string from the IRDX
	@param		hIRDX			IRDX handle	
	@param		sz8Buf			pointer to a Null-terminated MBCS destination string
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_MRANGESTRING(DDAQ_HANDLE hIRDX, DDAQ_P_CHAR8 sz8Buf, DDAQ_U32 u32MaxNumChar);

/** Unicode UTF-16: Get the measurement range information string from the IRDX
	@param		hIRDX			IRDX handle
	@param		sz16Buf			pointer to a Null-terminated Unicode destination string
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_MRANGESTRING_UC(DDAQ_HANDLE hIRDX, DDAQ_P_CHAR16 sz16Buf, DDAQ_U32 u32MaxNumWChar);

////////////////////////////////////////////////////////////////////////////

/** Get number of frames (for line cameras)
	@param		hIRDX			IRDX handle	
	@param		pu16NumFrames	pointer to number of frames
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_NUMFRAMES(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16NumFrames);

////////////////////////////////////////////////////////////////////////////

/** Set number of frames (for line cameras)
	@param		hIRDX			IRDX handle	
	@param		u16NumFrames	number of frames
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_NUMFRAMES(DDAQ_HANDLE hIRDX, DDAQ_U16 u16NumFrames);

////////////////////////////////////////////////////////////////////////////

/** Get number of valid frames (for line cameras, can be less than the number of frames if re-triggered)
	@param		hIRDX			IRDX handle	
	@param		pu16ValidFrames	pointer to number valid of frames
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_VALIDFRAMES(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16ValidFrames);

////////////////////////////////////////////////////////////////////////////

/** Get parameter single trigger
	@param		hIRDX			IRDX handle	
	@param		pu16Trig		pointer to single trigger mode (refer to #DDAQ_SINGLETRIGGER_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_SINGLETRIGGER(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Trig);

////////////////////////////////////////////////////////////////////////////

/** Set parameter single trigger
	@param		hIRDX			IRDX handle	
	@param		u16Trig			new single trigger mode (refer to #DDAQ_SINGLETRIGGER_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_SINGLETRIGGER(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Trig);

////////////////////////////////////////////////////////////////////////////

/** Get parameter sequence trigger
	@param		hIRDX			IRDX handle	
	@param		pu16Trig		pointer to sequence trigger mode (refer to #DDAQ_SEQUENCETRIGGER_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_SEQUENCETRIGGER(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Trig);

////////////////////////////////////////////////////////////////////////////

/** Set parameter sequence trigger
	@param		hIRDX			IRDX handle	
	@param		u16Trig			new sequence trigger mode (refer to #DDAQ_SEQUENCETRIGGER_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_SEQUENCETRIGGER(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Trig);

////////////////////////////////////////////////////////////////////////////

/** Get parameter shutter trigger (only for cameras with shutter)
	@param		hIRDX			IRDX handle	
	@param		pu16Trig		pointer to shutter trigger mode (refer to #DDAQ_SHUTTERTRIGGER_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_SHUTTERTRIGGER(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Trig);

////////////////////////////////////////////////////////////////////////////

/** Set parameter shutter trigger (only for cameras with shutter)
	@param		hIRDX			IRDX handle	
	@param		u16Trig			new shutter trigger mode (refer to #DDAQ_SHUTTERTRIGGER_NO)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_SHUTTERTRIGGER(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Trig);

////////////////////////////////////////////////////////////////////////////

/** Get parameters for temperature sequence trigger
	@param		hIRDX			IRDX handle	
	@param		pf32Threshold	pointer to threshold for temperature sequence trigger (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pu16Mode		pointer to temperature sequence trigger mode (refer to #DDAQ_TEMPSEQUENCETRIGGER_MAX_G_TH)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_TEMPSEQUENCETRIGGER(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Threshold, DDAQ_P_U16 pu16Mode);

////////////////////////////////////////////////////////////////////////////

/** Set parameters for temperature sequence trigger
	@param		hIRDX			IRDX handle	
	@param		f32Threshold	new threshold for temperature sequence trigger (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		u16Mode			new temperature sequence trigger mode (refer to #DDAQ_TEMPSEQUENCETRIGGER_MAX_G_TH)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_TEMPSEQUENCETRIGGER(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Threshold, DDAQ_U16 u16Mode);

////////////////////////////////////////////////////////////////////////////

/** Get number of pre-trigger frames
	@param		hIRDX			IRDX handle	
	@param		pu16PTFNum			pointer to number of pre-trigger frames
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_NUMPRETRIGGERFRAMES(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16PTFNum);

////////////////////////////////////////////////////////////////////////////

/** Set number of pre-trigger frames
	@param		hIRDX			IRDX handle	
	@param		u16PTFNum		number of pre-trigger frames
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_NUMPRETRIGGERFRAMES(DDAQ_HANDLE hIRDX, DDAQ_U16 u16PTFNum);

////////////////////////////////////////////////////////////////////////////

/** Get the position of the motor focus
	@param		hIRDX			IRDX handle	
	@param		pu16Pos			pointer to position (0x0FFFF if not available)
	@param		pu16State		pointer to state (0 if no error and focus is not moving)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_GET_MOTOR_FOCUS_POSITION(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Pos, DDAQ_P_U16 pu16State);

////////////////////////////////////////////////////////////////////////////

/** Set the position of the motor focus
	@param		hIRDX			IRDX handle	
	@param		u16Pos			position
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_ACQUISITION_SET_MOTOR_FOCUS_POSITION(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Pos);

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_SCALE_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get current scale minimum and maximum
	@param		hIRDX			IRDX handle	
	@param		pf32Min			pointer to scale minimum value (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pf32Max			pointer to scale maximum value (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_GET_MINMAX(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Min, DDAQ_P_F32 pf32Max);

////////////////////////////////////////////////////////////////////////////

/** Set scale minimum and maximum (not for auto dynamic scaling)
	@param		hIRDX			IRDX handle	
	@param		f32Min			new scale minimum value (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		f32Max			new scale maximum value (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_SET_MINMAX(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Min, DDAQ_F32 f32Max);

////////////////////////////////////////////////////////////////////////////

/** Get auto scaling mode
	@param		hIRDX			IRDX handle	
	@param		pu16Mode		pointer to auto scaling mode (refer to #DDAQ_AUTOSCALE_NO)
	@param		pf32AVPlus		pointer to AvPlus value (only for mode #DDAQ_AUTOSCALE_AVERAGE and #DDAQ_AUTOSCALE_STDDEV)
								For #DDAQ_AUTOSCALE_AVERAGE scaling maximum is the value of Average + AvPlus
								For #DDAQ_AUTOSCALE_STDDEV scaling maximum is the value of Average + AvPlus*Standard Deviation
	@param		pf32AVMinus		pointer to AvMinus value (only for mode #DDAQ_AUTOSCALE_AVERAGE and #DDAQ_AUTOSCALE_STDDEV)
								For #DDAQ_AUTOSCALE_AVERAGE scaling minimum is the value of Average - AvMinus
								For #DDAQ_AUTOSCALE_STDDEV scaling minimum is the value of Average - AvMinus*Standard Deviation
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_GET_AUTOMODE(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Mode, DDAQ_P_F32 pf32AVPlus, DDAQ_P_F32 pf32AVMinus);

////////////////////////////////////////////////////////////////////////////

/** Get extended auto scaling mode
	@param		hIRDX				IRDX handle	
	@param		pu16Mode			pointer to auto scaling mode (refer to #DDAQ_AUTOSCALE_NO)
	@param		pf32AVPlusFix		pointer to AvPlusFix value (only for mode #DDAQ_AUTOSCALE_AVERAGE)
									For #DDAQ_AUTOSCALE_AVERAGE scaling maximum is the value of Average + AvPlusFix
	@param		pf32AVMinusFix		pointer to AvMinusFix value (only for mode #DDAQ_AUTOSCALE_AVERAGE)
									For #DDAQ_AUTOSCALE_AVERAGE scaling mainimum is the value of Average - AvMinusFix
	@param		pf32AVPlusDynFac	pointer to AvPlusDynFac value (only for mode #DDAQ_AUTOSCALE_STDDEV)
									For #DDAQ_AUTOSCALE_STDDEV scaling maximum is the value of Average + AVPlusDynFac*Standard Deviation
	@param		pf32AVMinusDynFac	pointer to AvMinusDynFac value (only for mode #DDAQ_AUTOSCALE_STDDEV)
									For #DDAQ_AUTOSCALE_STDDEV scaling minimum is the value of Average - AVMinusDynFac*Standard Deviation
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_GET_AUTOMODE_EX(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Mode, DDAQ_P_F32 pf32AVPlusFix, DDAQ_P_F32 pf32AVMinusFix, DDAQ_P_F32 pf32AVPlusDynFac, DDAQ_P_F32 pf32AVMinusDynFac);

////////////////////////////////////////////////////////////////////////////

/** Set auto scaling mode
	@param		hIRDX			IRDX handle	
	@param		u16Mode			auto scaling mode (refer to #DDAQ_AUTOSCALE_NO)
	@param		f32AVPlus		AvPlus value (corresponding to #DDAQ_SET_TEMPUNIT, only for mode #DDAQ_AUTOSCALE_AVERAGE and #DDAQ_AUTOSCALE_STDDEV)
								For #DDAQ_AUTOSCALE_AVERAGE scaling maximum is the value of Average + AvPlus
								For #DDAQ_AUTOSCALE_STDDEV scaling maximum is the value of Average + AvPlus*Standard Deviation
	@param		f32AVMinus		AvMinus value (corresponding to #DDAQ_SET_TEMPUNIT, only for mode #DDAQ_AUTOSCALE_AVERAGE and #DDAQ_AUTOSCALE_STDDEV)
								For #DDAQ_AUTOSCALE_AVERAGE scaling minimum is the value of Average - AvMinus
								For #DDAQ_AUTOSCALE_STDDEV scaling minimum is the value of Average - AvMinus*Standard Deviation
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_SET_AUTOMODE(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Mode, DDAQ_F32 f32AVPlus, DDAQ_F32 f32AVMinus);

////////////////////////////////////////////////////////////////////////////

/** Get scale step from IRDX
	@param		hIRDX			IRDX handle	
	@param		pf32Step		pointer to scale step value (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_GET_STEP(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Step);

////////////////////////////////////////////////////////////////////////////

/** Set scale step to IRDX
	@param		hIRDX			IRDX handle	
	@param		f32Step			new scale step value (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_SCALE_SET_STEP(DDAQ_HANDLE hIRDX, DDAQ_F32 f32Step);

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_PALLET_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get color bar type (palette) and number of colors
	@param		hIRDX			IRDX handle	
	@param		pu16Bar			pointer to color bar type (refer to #DDAQ_PALLET_SYMIICON)
	@param		pu16NumCol		pointer to number of colors (3 - 256)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BAR(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Bar, DDAQ_P_U16 pu16NumCol);

////////////////////////////////////////////////////////////////////////////

/** Set color bar type (palette) and number of colors
	@param		hIRDX			IRDX handle	
	@param		u16Bar			new color bar type(refer to #DDAQ_PALLET_SYMIICON)
	@param		u16NumCol		new number of colors (3 - 256)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_SET_BAR(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Bar, DDAQ_U16 u16NumCol);

////////////////////////////////////////////////////////////////////////////

/** Get the color bar background color
	@param		hIRDX			IRDX handle	
	@param		pu32BkCol		pointer to background color (COLORREF)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BACKGROUNDCOL(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32BkCol);

////////////////////////////////////////////////////////////////////////////

/** Set the color bar background color
	@param		hIRDX			IRDX handle	
	@param		u32BkCol		new background color (COLORREF)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_SET_BACKGROUNDCOL(DDAQ_HANDLE hIRDX, DDAQ_U32 u32BkCol);

////////////////////////////////////////////////////////////////////////////

/** Get the color bar text color
	@param		hIRDX			IRDX handle	
	@param		pu32TxtCol		pointer to text color (COLORREF)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_TEXTCOL(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32TxtCol);

////////////////////////////////////////////////////////////////////////////

/** Set the color bar text color
	@param		hIRDX			IRDX handle	
	@param		u32TxtCol		new text color (COLORREF)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_SET_TEXTCOL(DDAQ_HANDLE hIRDX, DDAQ_U32 u32TxtCol);

////////////////////////////////////////////////////////////////////////////

/** Get the number of isotherms
	@param		hIRDX			IRDX handle	
	@param		pu16NumIsoth	pointer to number of isotherms
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_NUMISOTHERMS(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16NumIsoth);

////////////////////////////////////////////////////////////////////////////

/** Set the number of isotherms
	@param		hIRDX			IRDX handle	
	@param		u16NumIsoth		number of isotherms
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_SET_NUMISOTHERMS(DDAQ_HANDLE hIRDX, DDAQ_U16 u16NumIsoth);

////////////////////////////////////////////////////////////////////////////

/** Get the settings for an isotherm
	@param		hIRDX			IRDX handle	
	@param		u16No			number of isotherm (1 - #DDAQ_ISOTHERM_MAX)
	@param		pf32Min			pointer to minimum of isotherm range
	@param		pf32Max			pointer to maximum of isotherm range
	@param		pu32Col			pointer to color of isotherm (COLORREF) 
	@param		pu16Sat			pointer to saturation (%) (0 - 100)
	@param		pbTransp		pointer to transparent mode [true/false]
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_ISOTHERM(DDAQ_HANDLE hIRDX, DDAQ_U16 u16No, DDAQ_P_F32 pf32Min, DDAQ_P_F32 pf32Max, DDAQ_P_U32 pu32Col, DDAQ_P_U16 pu16Sat, DDAQ_P_BOOL pbTransp);

////////////////////////////////////////////////////////////////////////////

/** Set the settings for an isotherm
	@param		hIRDX			IRDX handle	
	@param		u16No			number of isotherm (1 - #DDAQ_ISOTHERM_MAX)
	@param		f32Min			minimum of isotherm range
	@param		f32Max			maximum of isotherm range
	@param		u32Col			color of isotherm (COLORREF)
	@param		u16Sat			saturation (%) (0 - 100)
	@param		bTransp			transparent mode [true/false]
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_SET_ISOTHERM(DDAQ_HANDLE hIRDX, DDAQ_U16 u16No, DDAQ_F32 f32Min, DDAQ_F32 f32Max, DDAQ_U32 u32Col, DDAQ_U16 u16Sat, DDAQ_BOOL bTransp);

////////////////////////////////////////////////////////////////////////////

/** Get the current color bar as bitmap
	@param		hIRDX			IRDX handle	
	@param		u16Width		width of the bitmap
	@param		u16Height		height of the bitmap
	@param		ppBits			pointer to pointer of bitmap bits
	@param		ppBitmapInfo	pointer to pointer of bitmap info header
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BITMAP(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Width, DDAQ_U16 u16Height, DDAQ_PP_BITMAPBITS ppBits, DDAQ_PP_BITMAPINFO ppBitmapInfo);

////////////////////////////////////////////////////////////////////////////

/** Get the current color bar with scale text as bitmap
	@param		hIRDX			IRDX handle	
	@param		u16Width		width of the bitmap
	@param		u16Height		height of the bitmap
	@param		ppBits			pointer to pointer of bitmap bits
	@param		ppBitmapInfo	pointer to pointer of bitmap info header
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BITMAPSCALE(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Width, DDAQ_U16 u16Height, DDAQ_PP_BITMAPBITS ppBits, DDAQ_PP_BITMAPINFO ppBitmapInfo);

////////////////////////////////////////////////////////////////////////////

/** Get the current color bar with scale text as bitmap with extended settings
	@param		hIRDX			IRDX handle	
	@param		u16Width		width of the bitmap
	@param		u16Height		height of the bitmap
	@param		ppBits			pointer to pointer of bitmap bits
	@param		ppBitmapInfo	pointer to pointer of bitmap info header
	@param		pi32Param		pointer to additional parameters
				pi32Param[0]	font size for text 
								- negative values: font size in pixel
								- positive values: relative width of color bar: 0..100
	@param		u32Size			size of additional parameters (bytes)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BITMAPSCALEEX(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Width, DDAQ_U16 u16Height, DDAQ_PP_BITMAPBITS ppBits, DDAQ_PP_BITMAPINFO ppBitmapInfo, DDAQ_P_I32 pi32Param, DDAQ_U32 u32Size);

////////////////////////////////////////////////////////////////////////////

/** Get a specific color of the color bar palette
	@param		hIRDX			IRDX handle	
	@param		u16Idx			index of color in color bar (0 - number of colors-1)
	@param		pu32Col			pointer to color (COLORREF) 
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BARCOL(DDAQ_HANDLE hIRDX, DDAQ_U16 u16Idx, DDAQ_P_U32 pu32Col);

////////////////////////////////////////////////////////////////////////////

/** Get all colors of the color bar palette with isotherms
	@param		hIRDX			IRDX handle	
	@param		u16NumCol		number of colors
	@param		pu32Col			pointer to color buffer (must have NumCol*4 bytes) 
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PALLET_GET_BARCOLORS(DDAQ_HANDLE hIRDX, DDAQ_U16 u16NumCol, DDAQ_P_U32 pu32Col);

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_IMAGE_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get image size for bitmap image of measurement data
	@param		hIRDX			IRDX handle	
	@param		pu16Width		pointer to width of image
	@param		pu16Height		pointer to height of image
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_GET_SIZE(HANDLE hIRDX, DDAQ_P_U16 pu16Width, DDAQ_P_U16 pu16Height);

////////////////////////////////////////////////////////////////////////////

/** Get image zoom mode and image zoom factor for bitmap image of measurement data
	@param		hIRDX			IRDX handle	
	@param		pu16ZMode		pointer of zoom mode (refer to #DDAQ_ZMODE_DIRECT)
	@param		pf32Zoom		pointer to zoom factor (not used for ZMode #DDAQ_ZMODE_DIRECT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_GET_ZOOM(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16ZMode, DDAQ_P_F32 pf32Zoom);

////////////////////////////////////////////////////////////////////////////

/** Set image zoom mode and zoom factor for bitmap image of measurement data
	@param		hIRDX			IRDX handle	
	@param		u16ZMode		new zoom mode (refer to #DDAQ_ZMODE_DIRECT)
	@param		f32Zoom			new zoom factor (not used for ZMode #DDAQ_ZMODE_DIRECT)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_SET_ZOOM(DDAQ_HANDLE hIRDX, DDAQ_U16 u16ZMode, DDAQ_F32 f32Zoom);

////////////////////////////////////////////////////////////////////////////

/** Get image bitmap draw mode
	@param		hIRDX			IRDX handle	
	@param		pu16DrawMode	pointer of draw mode (refer to #DDAQ_DRAWMODE_R0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_GET_DRAWMODE(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16DrawMode);

////////////////////////////////////////////////////////////////////////////

/** Set image bitmap draw mode
	@param		hIRDX			IRDX handle	
	@param		u16DrawMode		new draw mode (refer to #DDAQ_DRAWMODE_R0)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_SET_DRAWMODE(DDAQ_HANDLE hIRDX, DDAQ_U16 u16DrawMode);

////////////////////////////////////////////////////////////////////////////

/** Get the 2D image of measurement data as bitmap
	@param		hIRDX			IRDX handle	
	@param		pu16Width		pointer to width of the bitmap
	@param		pu16Height		pointer to height of the bitmap
	@param		ppBits			pointer to pointer of bitmap bits
	@param		ppBitmapInfo	pointer to pointer of bitmap info header
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_GET_BITMAP(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Width, DDAQ_P_U16 pu16Height, DDAQ_PP_BITMAPBITS ppBits, DDAQ_PP_BITMAPINFO ppBitmapInfo);

////////////////////////////////////////////////////////////////////////////

/** Get the 1D image of measurement data as bitmap
	@param		hIRDX			IRDX handle	
	@param		pu16Width		pointer to width of the bitmap
	@param		u16Height		height of the bitmap
	@param		ppBits			pointer to pointer of bitmap bits
	@param		ppBitmapInfo	pointer to pointer of bitmap info header
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_IMAGE_GET_BITMAP_PROFILE(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Width, DDAQ_U16 u16Height, DDAQ_PP_BITMAPBITS ppBits, DDAQ_PP_BITMAPINFO ppBitmapInfo);

////////////////////////////////////////////////////////////////////////////
// IRDX_PIXEL_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get the pixel data size
	@param		hIRDX			IRDX handle	
	@param		pu16Width		pointer to width of the pixel field
	@param		pu16Height		pointer to height of the pixel field
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_SIZE(DDAQ_HANDLE hIRDX, DDAQ_P_U16 pu16Width, DDAQ_P_U16 pu16Height);

////////////////////////////////////////////////////////////////////////////

/** Get the values of minimum and maximum of all pixels
	@param		hIRDX			IRDX handle	
	@param		pf32Min			pointer to minimum (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pf32Max			pointer to maximum (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
	Invalid temperatures are marked as -FLT_MAX (-3.402823466e+38)
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_MINMAX(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Min, DDAQ_P_F32 pf32Max);

////////////////////////////////////////////////////////////////////////////

/** Get the average value of all pixels
	@param		hIRDX			IRDX handle	
	@param		pf32AV			pointer to average (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
	Invalid temperatures are marked as -FLT_MAX (-3.402823466e+38)
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_AVERAGE(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32AV);

////////////////////////////////////////////////////////////////////////////

/** Get the average value and standard deviation value of all pixels
	@param		hIRDX			IRDX handle	
	@param		pf32AV			pointer to average (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pf32StdDev		pointer to standard deviation (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
	Invalid temperatures are marked as -FLT_MAX (-3.402823466e+38)
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_AVSTDDEV(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32AV, DDAQ_P_F32 pf32StdDev);

////////////////////////////////////////////////////////////////////////////

/** Get the temperature data of all pixels
	@param		hIRDX			IRDX handle	
	@param		pf32Data		pointer to data buffer for temperatures (corresponding to #DDAQ_SET_TEMPUNIT) 
	@param		u32BufSize		buffer size (bytes, e.g. for a 640x480 camera: 640x480x4=1228800 bytes)
	@return		error code, #DDAQ_NO_ERROR for success
	invalid temperatures are marked as -FLT_MAX (-3.402823466e+38)
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_DATA(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Data, DDAQ_U32 u32BufSize);

////////////////////////////////////////////////////////////////////////////

/** Set the temperature data for all pixels
	@param		hIRDX			IRDX handle	
	@param		pf32Data		pointer to data buffer for temperatures (corresponding to #DDAQ_SET_TEMPUNIT) 
	@param		u32NumPix		number of pixels
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_SET_DATA(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Data, DDAQ_U32 u32NumPix);

////////////////////////////////////////////////////////////////////////////

/** Get the temperature data of one pixel
	@param		hIRDX			IRDX handle	
	@param		u16x			x co-ordinate of pixel(1 ... sizex)
	@param		u16y			y co-ordinate of pixel (1 ... sizey)
	@param		pf32Data		pointer to the data buffer for temperature value (corresponding to #DDAQ_SET_TEMPUNIT)
	@return		error code, #DDAQ_NO_ERROR for success
	invalid temperatures are marked as -FLT_MAX (-3.402823466e+38)
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_DATA_POINT(HANDLE hIRDX, DDAQ_U16 u16x, DDAQ_U16 u16y, DDAQ_P_F32 pf32Data);

////////////////////////////////////////////////////////////////////////////

/** Get the value of maximum and the corresponding co-ordinate
	@param		hIRDX			IRDX handle	
	@param		pf32Max			pointer to maximum (corresponding to #DDAQ_SET_TEMPUNIT)
	@param		pu16x			pointer to x co-ordinate of point (1 ... sizex)
	@param		pu16y			pointer to y co-ordinate of point (1 ... sizey)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_PIXEL_GET_MAXCOORD(DDAQ_HANDLE hIRDX, DDAQ_P_F32 pf32Max, DDAQ_P_U16 pu16x, DDAQ_P_U16 pu16y);

////////////////////////////////////////////////////////////////////////////
// IRDX_USERDATA_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get the size of a user data range
	@param		hIRDX			IRDX handle
	@param		u16No			number of user data range (1 - 32)
	@param		pu32Size		pointer to get data size  
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_GET_SIZE(DDAQ_HANDLE hIRDX, DDAQ_U16 u16No, DDAQ_P_U32 pu32Size);

////////////////////////////////////////////////////////////////////////////

/** Get the data of a user data range
	@param		hIRDX			IRDX handle
	@param		u16No			number of user data range (1 - 32)
	@param		u32Size			buffer size (bytes)
	@param		pData			pointer to buffer
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_GET_DATA(DDAQ_HANDLE hIRDX, DDAQ_U16 u16No, DDAQ_U32 u32Size, DDAQ_P_V pData);

////////////////////////////////////////////////////////////////////////////

/** Set the data of a user data range
	@param		hIRDX			IRDX handle
	@param		u16No			number of user data range (1 - 32)
	@param		u32Size			buffer size (bytes)
	@param		pData			pointer to buffer
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_SET_DATA(DDAQ_HANDLE hIRDX, DDAQ_U16 u16No, DDAQ_U32 u32Size, DDAQ_P_V pData);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Get the product name
	@param		hIRDX			IRDX handle
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@param		sz8ProductName	pointer to character buffer for a NULL-terminated MBCS destination string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_GET_PRODUCTNAME(DDAQ_HANDLE hIRDX, DDAQ_U32 u32MaxNumChar, DDAQ_P_CHAR8 sz8ProductName);

/** Unicode UTF-16: Get the product name
	@param		hIRDX			IRDX handle
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@param		sz16ProductName	pointer to character buffer for a NULL-terminated Unicode destination string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_GET_PRODUCTNAME_UC(DDAQ_HANDLE hIRDX, DDAQ_U32 u32MaxNumWChar, DDAQ_P_CHAR16 sz16ProductName);

////////////////////////////////////////////////////////////////////////////

/** MBCS: Set the product name
	@param		hIRDX			IRDX handle
	@param		u32MaxNumChar	maximum number of characters (1 byte per char)
	@param		sz8ProductName	pointer to a Null-terminated MBCS string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_SET_PRODUCTNAME(DDAQ_HANDLE hIRDX, DDAQ_U32 u32MaxNumChar, DDAQ_PC_CHAR8 sz8ProductName);

/** Unicode UTF-16: Set the product name
	@param		hIRDX			IRDX handle
	@param		u32MaxNumWChar	maximum number of wide characters (2 bytes per wchar)
	@param		sz16ProductName	pointer to a Null-terminated Unicode string
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall DDAQ_IRDX_USERDATA_SET_PRODUCTNAME_UC(DDAQ_HANDLE hIRDX, DDAQ_U32 u32MaxNumWChar, DDAQ_PC_CHAR16 sz16ProductName);

////////////////////////////////////////////////////////////////////////////
// IRDX_BUFFER_xxxx
////////////////////////////////////////////////////////////////////////////

/** Get the buffer size of an IRDX (only valid for an IRDX with 1 data set)
	@param		hIRDX		HANDLE of IRDX file	
	@param		pu32BufSize	pointer to buffer size (bytes)	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall 	DDAQ_IRDX_BUFFER_GET_SIZE(DDAQ_HANDLE hIRDX, DDAQ_P_U32 pu32BufSize);	

////////////////////////////////////////////////////////////////////////////

/** Write an IRDX to a buffer (only available for an IRDX with 1 data set)
	@param		hIRDX		HANDLE of IRDX file	
	@param		pBuf		pointer to buffer	
	@param		u32BufSize		buffer size (bytes)	
	@param		pu32UsedBufSize	pointer to number of used buffer size (bytes)
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall 	DDAQ_IRDX_BUFFER_WRITE_TO(DDAQ_HANDLE hIRDX, DDAQ_P_V pBuf, DDAQ_U32 u32BufSize, DDAQ_P_U32 pu32UsedBufSize);

////////////////////////////////////////////////////////////////////////////

/** Write an IRDX to a buffer (only available for an IRDX with 1 data set)
	@param		hIRDX		HANDLE of IRDX file	
	@param		pBuf		pointer to buffer	
	@param		u32BufSize		buffer size (bytes)	
	@param		pu32UsedBufSize	pointer to number of used buffer size (bytes)
	@param		pu32RawDataOfs	pointer to raw data offset 
	@param		pu32RawDataSize	pointer to raw data size
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall 	DDAQ_IRDX_BUFFER_WRITE_TO_EX(DDAQ_HANDLE hIRDX, DDAQ_P_V pBuf, DDAQ_U32 u32BufSize, DDAQ_P_U32 pu32UsedBufSize, DDAQ_P_U32 pu32RawDataOfs, DDAQ_P_U32 pu32RawDataSize);

////////////////////////////////////////////////////////////////////////////

/** Open an IRDX memory object from a buffer (only 1 data set is read from the buffer)
	@param		pBuf		pointer to buffer	
	@param		u32BufSize	buffer size (bytes)	
	@param		phIRDX		pointer to IRDX memory handle	
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall 	DDAQ_IRDX_BUFFER_OPEN_FROM(DDAQ_P_V pBuf, DDAQ_U32 u32BufSize, DDAQ_P_HANDLE phIRDX);

////////////////////////////////////////////////////////////////////////////

/** Open an IRDX memory object from a buffer (only 1 data set is read from the buffer)
	@param		pBuf		pointer to buffer	
	@param		u32BufSize	buffer size (bytes)	
	@param		phIRDX		pointer to IRDX memory handle	
	@param		pu32RawDataOfs		pointer to raw data offset 
	@param		pu32RawDataSize		pointer to raw data size
	@return		error code, #DDAQ_NO_ERROR for success
*/
DDAQ_U32	__stdcall 	DDAQ_IRDX_BUFFER_OPEN_FROM_EX(DDAQ_P_V pBuf, DDAQ_U32 u32BufSize, DDAQ_P_HANDLE phIRDX, DDAQ_P_U32 pu32RawDataOfs, DDAQ_P_U32 pu32RawDataSize);

////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
// DDAQ defines
////////////////////////////////////////////////////////////////////////////

#define	DDAQ_MAX_DEVICES	32	///< Maximum number of devices

////////////////////////////////////////////////////////////////////////////
// DDAQ temperatur units

#define	DDAQ_TEMPUNIT_C			0	///< temperature unit degree Celsius
#define	DDAQ_TEMPUNIT_F			1	///< temperature unit degree Fahrenheit
#define	DDAQ_TEMPUNIT_K			2	///< temperature unit Kelvin
#define	DDAQ_TEMPUNIT_R			3	///< temperature unit relative units RU (raw data)

////////////////////////////////////////////////////////////////////////////
// DDAQ device types

#define	DDAQ_DEVICE_TYPE_INVALID		0	///< invalid
#define	DDAQ_DEVICE_TYPE_VIEW_100		1	///< VIEW 100
#define	DDAQ_DEVICE_TYPE_VIEW_256		2	///< VIEW 256
#define	DDAQ_DEVICE_TYPE_VIEW_320		3	///< VIEW 320
#define	DDAQ_DEVICE_TYPE_MIDAS			4	///< MIDAS 320
#define	DDAQ_DEVICE_TYPE_VIEW_380		5	///< VIEW 380
#define	DDAQ_DEVICE_TYPE_VIEW_640N		6	///< VIEW 640N

#define	DDAQ_DEVICE_TYPE_VIEW_640		8	///< VIEW 640

#define	DDAQ_DEVICE_TYPE_MODULE_128		10	///< MODULE 128
#define	DDAQ_DEVICE_TYPE_LINE_128		11	///< LINE 128
#define	DDAQ_DEVICE_TYPE_LINE_256		12	///< LINE 256
#define	DDAQ_DEVICE_TYPE_HZK_160		13	///< HZK 160
#define	DDAQ_DEVICE_TYPE_HZK_256		14	///< HZK 256
#define	DDAQ_DEVICE_TYPE_LINE_256HS		15	///< LINE 256 HS
#define	DDAQ_DEVICE_TYPE_LINE_512		16	///< LINE 512
#define	DDAQ_DEVICE_TYPE_LINE_640		17	///< LINE 640
#define	DDAQ_DEVICE_TYPE_LINE_1024		18	///< LINE 1024
#define	DDAQ_DEVICE_TYPE_LINE_320		19	///< LINE 320

#define	DDAQ_DEVICE_TYPE_M8				30	///< M8
#define	DDAQ_DEVICE_TYPE_TP8			31	///< TP8
#define	DDAQ_DEVICE_TYPE_PVP_480		32	///< PVP 480
#define	DDAQ_DEVICE_TYPE_M380L			33	///< M380L

#define	DDAQ_DEVICE_TYPE_FIELD_8		40	///< FIELD 8
#define	DDAQ_DEVICE_TYPE_FIELD_16		41	///< FIELD 16
#define	DDAQ_DEVICE_TYPE_FIELD_32		42	///< FIELD 32

#define	DDAQ_DEVICE_TYPE_FIELD_160		45	///< FIELD 160

#define	DDAQ_DEVICE_TYPE_VIEW_320IN		50	///< VIEW 320 IN
#define	DDAQ_DEVICE_TYPE_VIEW_160		51	///< VIEW 160
#define	DDAQ_DEVICE_TYPE_VIEW_512		52	///< VIEW 512 N
#define	DDAQ_DEVICE_TYPE_VIEW_512H		53	///< VIEW 512 Half
#define	DDAQ_DEVICE_TYPE_VIEW_768		54	///< VIEW 768
#define	DDAQ_DEVICE_TYPE_VIEW_1024		55	///< VIEW 1024
#define	DDAQ_DEVICE_TYPE_VIEW_320N		56	///< VIEW 320 N
#define	DDAQ_DEVICE_TYPE_VIEW_900		57	///< VIEW 900

#define	DDAQ_DEVICE_TYPE_VIEW_1920		60	///< VIEW 1920
#define	DDAQ_DEVICE_TYPE_VIEW_1600		61	///< VIEW 1600
#define	DDAQ_DEVICE_TYPE_VIEW_640N2		62	///< VIEW 640N x 512
#define	DDAQ_DEVICE_TYPE_VIEW_1280		63	///< VIEW 1280N x 960
#define	DDAQ_DEVICE_TYPE_VIEW_640_512	64	///< VIEW 640 x 512 (Dali VLD)


////////////////////////////////////////////////////////////////////////////
// DDAQ device error bit masks
#define DDAQ_DEVICE_ERROR_BITMASK_ERROR_ANY		0x00000000	///< error: any error
#define DDAQ_DEVICE_ERROR_BITMASK_ERROR_CONNECT	0x80000000	///< error: lost connection, trying re-connect is automatically in progress 
#define DDAQ_DEVICE_ERROR_BITMASK_ERROR_TIMEOUT	0x40000000	///< error: data timeout, trying re-init is automatically in progress 
#define DDAQ_DEVICE_ERROR_BITMASK_ERROR_CAMMODE	0x00000001	///< error: invalid camera operation mode
#define DDAQ_DEVICE_ERROR_BITMASK_ERROR_CAMTEMP	0x00000002	///< error: invalid camera temperature
#define DDAQ_DEVICE_ERROR_BITMASK_ERROR_DETTEMP	0x00000004	///< error: invalid detector temperature

////////////////////////////////////////////////////////////////////////////
// DDAQ single trigger modes

#define	DDAQ_SINGLETRIGGER_NO			0	///< no single trigger 
#define DDAQ_SINGLETRIGGER_LEVEL_IN0	1	///< hardware single trigger with level on camera input IN0
#define DDAQ_SINGLETRIGGER_EDGE_IN0		2	///< hardware single trigger with edge on camera input IN0
#define DDAQ_SINGLETRIGGER_LEVEL_IN2	1	///< hardware single trigger with level on former camera input IN2 (new: IN0)
#define DDAQ_SINGLETRIGGER_EDGE_IN2		2	///< hardware single trigger with edge on former camera input IN2 (new: IN0)
#define DDAQ_SINGLETRIGGER_LEVEL_SW		3	///< software single trigger with level
#define DDAQ_SINGLETRIGGER_EDGE_SW		4	///< software single trigger with edge

////////////////////////////////////////////////////////////////////////////
// DDAQ sequence trigger modes

#define	DDAQ_SEQUENCETRIGGER_NO			0	///< no sequence trigger 
#define DDAQ_SEQUENCETRIGGER_LEVEL_IN1	1	///< hardware sequence trigger with level on camera input IN1
#define DDAQ_SEQUENCETRIGGER_EDGE_IN1	2	///< hardware sequence trigger with edge on camera input IN1
#define DDAQ_SEQUENCETRIGGER_LEVEL_IN3	1	///< hardware sequence trigger with level on former camera input IN3 (new: IN1)
#define DDAQ_SEQUENCETRIGGER_EDGE_IN3	2	///< hardware sequence trigger with edge on former camera input IN3 (new: IN1)
#define DDAQ_SEQUENCETRIGGER_LEVEL_TEMP	3	///< temperature sequence trigger with level and re-trigger
#define DDAQ_SEQUENCETRIGGER_EDGE_TEMP	4	///< temperature sequence trigger with edge and re-trigger
#define DDAQ_SEQUENCETRIGGER_EDGE1_TEMP	5	///< temperature sequence trigger with edge without re-trigger
#define DDAQ_SEQUENCETRIGGER_LEVEL_SW	6	///< software sequence trigger with level
#define DDAQ_SEQUENCETRIGGER_EDGE_SW	7	///< software sequence trigger with edge

////////////////////////////////////////////////////////////////////////////
// DDAQ temperature sequence trigger modes

#define	DDAQ_TEMPSEQUENCETRIGGER_MAX_G_TH	1	///< maximum greater then threshold
#define	DDAQ_TEMPSEQUENCETRIGGER_AVE_G_TH	2	///< average greater then threshold
#define	DDAQ_TEMPSEQUENCETRIGGER_MIN_G_TH	3	///< minimum greater then threshold
#define	DDAQ_TEMPSEQUENCETRIGGER_MAX_L_TH	4	///< maximum less then threshold
#define	DDAQ_TEMPSEQUENCETRIGGER_AVE_L_TH	5	///< average less then threshold
#define	DDAQ_TEMPSEQUENCETRIGGER_MIN_L_TH	6	///< minimum less then threshold

////////////////////////////////////////////////////////////////////////////
// DDAQ shutter trigger modes

#define	DDAQ_SHUTTERTRIGGER_NO			0	///< no shutter trigger (internal auto mode)
#define DDAQ_SHUTTERTRIGGER_IN0			1	///< hardware shutter trigger: disable auto shuttering with camera hardware input IN0, must be configured for the camera with tool CamConfig
#define DDAQ_SHUTTERTRIGGER_IN1			2	///< hardware shutter trigger: disable auto shuttering with camera hardware input IN1, must be configured for the camera with tool CamConfig
#define DDAQ_SHUTTERTRIGGER_IN2			1	///< hardware shutter trigger: disable auto shuttering with former camera hardware input IN2 (new: IN0), must be configured for the camera with tool CamConfig
#define DDAQ_SHUTTERTRIGGER_IN3			2	///< hardware shutter trigger: disable auto shuttering with former camera hardware input IN3 (new: IN1), must be configured for the camera with tool CamConfig
#define DDAQ_SHUTTERTRIGGER_SW			3	///< software shutter trigger: disable auto shuttering like hardware

////////////////////////////////////////////////////////////////////////////
// DDAQ Usage of camera inputs and outputs

#define DDAQ_UsageIN0_NA				0	///< not available
#define DDAQ_UsageIN0_DisableShutter	1	///< disable shutter
#define DDAQ_UsageIN0_SingleTrigger		2	///< single trigger 

#define DDAQ_UsageIN1_NA				0	///< not available
#define DDAQ_UsageIN1_DisableShutter	1	///< disable shutter
#define DDAQ_UsageIN1_SequenceTrigger	2	///< seuqence trigger 

#define DDAQ_UsageOUT0_NA					0	///< not available
#define DDAQ_UsageOUT0_ErrorChannel			1	///< error channel
#define DDAQ_UsageOUT0_ShutterState			2	///< shutter state
#define DDAQ_UsageOUT0_SoftwareDef0			3	///< software, default closed
#define DDAQ_UsageOUT0_SoftwareDef1			4	///< software, default open
#define DDAQ_UsageOUT0_EchoIN0				5	///< echo from IN0
#define DDAQ_UsageOUT0_SoftwareIntZoneDef0	6	///< internal zone software, default closed	
#define DDAQ_UsageOUT0_SoftwareIntZoneDef1	7	///< internal zone software, default open	

#define DDAQ_UsageOUT1_NA					0	///< not available
#define DDAQ_UsageOUT1_SyncSignal			1	///< image synchronous signal
#define DDAQ_UsageOUT1_ShutterState			2	///< shutter state
#define DDAQ_UsageOUT1_SoftwareDef0			3	///< software, default closed
#define DDAQ_UsageOUT1_SoftwareDef1			4	///< software, default open
#define DDAQ_UsageOUT1_EchoIN1				5	///< echo from IN1
#define DDAQ_UsageOUT1_SoftwareIntZoneDef0	6	///< internal zone software, default closed	
#define DDAQ_UsageOUT1_SoftwareIntZoneDef1	7	///< internal zone software, default open

////////////////////////////////////////////////////////////////////////////
// DDAQ pallet types for bitmap display 
	
#define	DDAQ_PALLET_SYMIICON		0	///< SYMIICON
#define	DDAQ_PALLET_MULTICOLOR		1	///< MULTICOLOR
#define	DDAQ_PALLET_SPECTRUM		2	///< SPECTRUM
#define	DDAQ_PALLET_THERMO			3	///< THERMO
#define	DDAQ_PALLET_GRAY			4	///< GRAY
#define	DDAQ_PALLET_GRAYPLUS		5	///< GRAYPLUS
#define	DDAQ_PALLET_HOTMETAL		6	///< HOTMETAL
#define	DDAQ_PALLET_IRON			7	///< IRON
#define	DDAQ_PALLET_LIGHT			8	///< LIGHT
#define	DDAQ_PALLET_SYMIICON_INV	9	///< SYMIICON inverse
#define	DDAQ_PALLET_MULTICOLOR_INV	10	///< MULTICOLOR inverse
#define	DDAQ_PALLET_SPECTRUM_INV	11	///< SPECTRUM inverse
#define	DDAQ_PALLET_THERMO_INV		12	///< THERMO inverse
#define	DDAQ_PALLET_GRAY_INV		13	///< GRAY inverse
#define	DDAQ_PALLET_GRAYPLUS_INV	14	///< GRAYPLUS inverse
#define	DDAQ_PALLET_HOTMETAL_INV	15	///< HOTMETAL inverse
#define	DDAQ_PALLET_IRON_INV		16	///< IRON inverse
#define	DDAQ_PALLET_LIGHT_INV		17	///< LIGHT inverse
#define	DDAQ_PALLET_GRAYLIGHT			18	///< GRAYLIGHT
#define	DDAQ_PALLET_GRAYPLUSLIGHT		19	///< GRAYPLUSLIGHT
#define	DDAQ_PALLET_GRAYLIGHT_INV		20	///< GRAYLIGHT inverse
#define	DDAQ_PALLET_GRAYPLUSLIGHT_INV	21	///< GRAYPLUSLIGHT inverse
#define	DDAQ_PALLET_MAX	DDAQ_PALLET_GRAYPLUSLIGHT_INV	///< last entry

////////////////////////////////////////////////////////////////////////////
/// DDAQ auto dynmic modes for scaling 

#define	DDAQ_AUTOSCALE_NO		0	///< no auto scaling (fix min and max)
#define	DDAQ_AUTOSCALE_MINMAX	1	///< auto scaling for min and max
#define	DDAQ_AUTOSCALE_MAX		2	///< auto scaling for max (fix min)
#define	DDAQ_AUTOSCALE_MIN		3	///< auto scaling for min (fix max)
#define	DDAQ_AUTOSCALE_AVERAGE	4	///< auto scaling for min and max with average +/- range
#define	DDAQ_AUTOSCALE_STDDEV	5	///< auto scaling for min and max with average +/- standard deviation

////////////////////////////////////////////////////////////////////////////
/// DDAQ data read mode

#define	DDAQ_DATAREADMODE_DETECTOR		0	///< 1:1 from detector
#define	DDAQ_DATAREADMODE_LENS			1	///< like lens

////////////////////////////////////////////////////////////////////////////
/// DDAQ zoom modes for bitmap display 

#define	DDAQ_ZMODE_DIRECT		0	///< 1:1 from source
#define	DDAQ_ZMODE_INTEGER		1	///< integer zoom without interpolation
#define	DDAQ_ZMODE_REAL			2	///< real zoom with interpolation

/////////////////////////////////////////////////////////////////////////////

#define DDAQ_DRAWMODE_R0		0	///< without rotation
#define DDAQ_DRAWMODE_R90		1	///<  90 degrees rotated 
#define DDAQ_DRAWMODE_R180		2	///< 180 degrees rotated 
#define DDAQ_DRAWMODE_R270		3	///< 270 degrees rotated 
#define DDAQ_DRAWMODE_R0_IH		4	///< without rotation, horizontally inverted 
#define DDAQ_DRAWMODE_R90_IH	5	///<  90 degrees rotated, horizontally inverted 
#define DDAQ_DRAWMODE_R180_IH	6	///< 180 degrees rotated, horizontally inverted 
#define DDAQ_DRAWMODE_R270_IH	7	///< 270 degrees rotated, horizontally inverted
#define DDAQ_DRAWMODE_R0_IV		8	///< without rotation, vertically inverted 
#define DDAQ_DRAWMODE_R90_IV	9	///<  90 degrees rotated, vertically inverted 
#define DDAQ_DRAWMODE_R180_IV	10	///< 180 degrees rotated, vertically inverted 
#define DDAQ_DRAWMODE_R270_IV	11	///< 270 degrees rotated, vertically inverted
#define DDAQ_DRAWMODE_R0_IHV	12	///< without rotation, horizontally and vertically inverted 
#define DDAQ_DRAWMODE_R90_IHV	13	///<  90 degrees rotated, horizontally and vertically inverted 
#define DDAQ_DRAWMODE_R180_IHV	14	///< 180 degrees rotated, horizontally and vertically inverted 
#define DDAQ_DRAWMODE_R270_IHV	15	///< 270 degrees rotated, horizontally and vertically inverted
 
#define DDAQ_WM_DATAMSG			WM_USER + 420	///< message id for window or thread message

/////////////////////////////////////////////////////////////////////////////
/// DDAQ maximum user data number 

#define	DDAQ_USERDAT_MAX	32		///< Maximum number of user data ranges

/////////////////////////////////////////////////////////////////////////////
/// DDAQ maximum isotherm number 

#define DDAQ_ISOTHERM_MAX	5		///< Maximum number of isotherms

////////////////////////////////////////////////////////////////////////////
/// DDAQ motor focus version

#define DDAQ_MOTORFOCUS_VERS_NO				0	///< motor focus not available
#define DDAQ_MOTORFOCUS_VERS_MOVE			1	///< motor focus movement without absolute positioning
#define DDAQ_MOTORFOCUS_VERS_POS_READ		2	///< motor focus movement and read absolute positioning
#define DDAQ_MOTORFOCUS_VERS_POS_READWRITE	3	///< motor focus movement and read/write absolute positioning

////////////////////////////////////////////////////////////////////////////
/// DDAQ motor focus commands

#define DDAQ_MOTORFOCUS_CMD_EXIST		0	///< check if available
#define DDAQ_MOTORFOCUS_CMD_STOP		1	///< stop any motion
#define DDAQ_MOTORFOCUS_CMD_NEAR		2	///< move focus to near range (active until stop command)
#define DDAQ_MOTORFOCUS_CMD_FAR			3	///< move focus to far range (active until stop command)
#define DDAQ_MOTORFOCUS_CMD_NEAR_STEP	4	///< move focus one step to near range
#define DDAQ_MOTORFOCUS_CMD_FAR_STEP	5	///< move focus one step to far range
#define DDAQ_MOTORFOCUS_CMD_NEAR_STEP_BIG	6	///< move focus one big step to near range
#define DDAQ_MOTORFOCUS_CMD_FAR_STEP_BIG	7	///< move focus one big step to far range

////////////////////////////////////////////////////////////////////////////
// DDAQ error codes
////////////////////////////////////////////////////////////////////////////

#define DDAQ_NO_ERROR						0

#define DDAQ_ERROR_INVALID_LICENSE			1
#define DDAQ_ERROR_INVALID_DEVNO			2
#define DDAQ_ERROR_INVALID_HIRDX			3

#define DDAQ_ERROR_OPEN_IRDX				4
#define DDAQ_ERROR_ADD_MAP					5
#define DDAQ_ERROR_REMOVE_MAP				6
#define DDAQ_ERROR_READMEM					7
#define DDAQ_ERROR_DRAWPALLET				8
#define DDAQ_ERROR_BUFFERSIZE				9

#define DDAQ_ERROR_INVALID_USERDATANO		10
#define DDAQ_ERROR_INVALID_ISOTHERMNO		11
#define DDAQ_ERROR_INVALID_AMBIENTCORRMODE	12
#define DDAQ_ERROR_INVALID_AMBIENTCORROFFS	13
#define DDAQ_ERROR_AMBIENTCORR_ON			14
#define DDAQ_ERROR_TRANSMCORR_ON			15
#define DDAQ_ERROR_TRANSMCORR_OFF			16
#define DDAQ_ERROR_INVALID_TRANSMCORRMODE	17
#define DDAQ_ERROR_INVALID_TRANSMCORRREFTEMP	18
#define DDAQ_ERROR_INVALID_TRANSMCORRREFEPS	19
#define DDAQ_ERROR_INVALID_TRANSMCORRWEIGHT	20
#define DDAQ_ERROR_INVALID_TRANSMCORRMINVAL	21
#define DDAQ_ERROR_INVALID_XYCOORD			22
#define DDAQ_ERROR_INVALID_SCALE_MIN		23
#define DDAQ_ERROR_INVALID_SCALE_MAX		24
#define DDAQ_ERROR_INVALID_SCALE_STEP		25
#define DDAQ_ERROR_INVALID_AUTODYN			26
#define DDAQ_ERROR_INVALID_AUTODYN_PM		27
#define DDAQ_ERROR_INVALID_BAR				28
#define DDAQ_ERROR_INVALID_NUMCOL			29
#define DDAQ_ERROR_INVALID_ISOTHERMMIN		30
#define DDAQ_ERROR_INVALID_ISOTHERMMAX		31
#define DDAQ_ERROR_INVALID_ISOTHERMSAT		32
#define DDAQ_ERROR_INVALID_ZOOMMODE			33
#define DDAQ_ERROR_INVALID_ZOOM				34
#define DDAQ_ERROR_INVALID_READMODE			35
#define DDAQ_ERROR_INVALID_COLORINDEX		36
#define DDAQ_ERROR_INVALID_DRAWMODE			37
#define DDAQ_ERROR_INVALID_TEMPPRECISION	38
#define DDAQ_ERROR_INVALID_TEMPUNIT			39
#define DDAQ_ERROR_TIMEOUT_SINGLESHOT		40
#define DDAQ_ERROR_INVALID_IMAGE			41 
#define DDAQ_ERROR_INVALID_BUFFER			42 
#define DDAQ_ERROR_INVALID_POINTER			43
#define DDAQ_ERROR_EMISSCORR_ON				44
#define DDAQ_ERROR_EMISSCORR_OFF			45
//#define DDAQ_ERROR_INVALID_EMISSCORRWEIGHT	46
#define DDAQ_ERROR_INVALID_EMISSCORRMINVAL	47
#define DDAQ_ERROR_OFFSETCORR_ON			48
#define DDAQ_ERROR_OFFSETCORR_OFF			49
//#define DDAQ_ERROR_INVALID_OFFSETCORRWEIGHT	50
#define DDAQ_ERROR_INVALID_OFFSETCORRMINVAL	51

#define DDAQ_ERROR_OPEN_JPG					52
#define DDAQ_ERROR_OPEN_IRV					53
#define DDAQ_ERROR_OPEN_RTT					54
#define DDAQ_ERROR_SAVE_IRDX_EXT			55
#define DDAQ_ERROR_DEVICE_INUSE				57
#define DDAQ_ERROR_OPEN_INTERFACE_EMPTY		58

#define DDAQ_ERROR_OPEN_FIELD_TXT			59
#define DDAQ_ERROR_OPEN_INVALID_JPG			60
#define DDAQ_ERROR_OPEN_INVALID_IRV			61

#define DDAQ_ERROR_INVALID_POINT_EPS		62
#define DDAQ_ERROR_INVALID_ROI_REPLMODE		63
#define DDAQ_ERROR_OPEN_DPE					64

#define DDAQ_ERROR_OPEN_DAT					65

#define DDAQ_ERROR_INVALID_OFFSET			66

#define DDAQ_ERROR_SETIP_ID_INVALID			70	// invalid camera ID
#define DDAQ_ERROR_SETIP_ID_USED			71	// camera ID used
#define DDAQ_ERROR_SETIP_ID_NOTFOUND		72	// camera not found
#define DDAQ_ERROR_SETIP_IP_INVALID			73  // invalid IP address
#define DDAQ_ERROR_SETIP_SN_INVALID			74	// invalid subnet Mask
#define DDAQ_ERROR_SETIP_IPSN_INVALID		75	// invalid combination IP address/subnet mask
#define DDAQ_ERROR_SETIP_STATIC				76  // error set static IP
#define DDAQ_ERROR_SETIP_AUTO				77  // error set auto IP
#define DDAQ_ERROR_SETIP_CONNECTION			78	// error check connection after set
#define DDAQ_ERROR_SETIP_STATIC_IP			79	// error verify IP address
#define DDAQ_ERROR_SETIP_STATIC_SN			80	// error verify subnet mask
#define DDAQ_ERROR_SETIP_STATIC_GW			81	// error verify gateway

////////////////////////////////////////////////////////////////////////////
// from DIASCAM.dll

#define	DDAQ_ERROR_OFFSET_DIASCAMDLL		1000
#define DDAQ_ERROR_INVALID_DEVICENO			1001
#define DDAQ_ERROR_INVALID_ITEM				1002		
#define DDAQ_ERROR_INVALID_BUFSIZE			1003	
#define DDAQ_ERROR_NO_COMPMODE				1004	
#define DDAQ_ERROR_INVALID_PARAMETER		1005

#define DDAQ_ERROR_NO_DEVICE_DETECT			1010
#define DDAQ_ERROR_COM_NOT_FREE				1011	
#define DDAQ_ERROR_CREATE_OBJECT			1012
#define DDAQ_ERROR_CREATE_THREAD			1013
#define DDAQ_ERROR_ALLOC_BUFFER				1014
#define DDAQ_ERROR_LOAD_DRIVER				1015
#define DDAQ_ERROR_FUNCTION_NOT_POSSIBLE	1016
#define DDAQ_ERROR_CREATE_ETHERNET			1017
#define DDAQ_ERROR_CREATE_M8TP8				1018
#define DDAQ_ERROR_CLOSE_THREAD				1019

#define DDAQ_ERROR_INVALID_CFGFILE			1020
#define DDAQ_ERROR_INVALID_DEVICE_TYPE		1021	
#define DDAQ_ERROR_INVALID_DEVICE_ID		1022		
#define DDAQ_ERROR_INIT_CORRDATA			1023
#define DDAQ_ERROR_TKLFILE_NOT_EXIST		1024
#define DDAQ_ERROR_INVALID_TKL_INDEX		1025
#define DDAQ_ERROR_LOAD_TKL					1026
#define DDAQ_ERROR_UPDATE_CFG				1027		
#define DDAQ_ERROR_UPDATE_TKL				1028		
#define DDAQ_ERROR_UPDATE_TPX				1029	

#define DDAQ_ERROR_IRDFILE_NOT_EXIST		1030
#define DDAQ_ERROR_INVALID_HDRFILE			1031
#define DDAQ_ERROR_PVP_NUMIMAGES			1032
#define DDAQ_ERROR_PVP_OPERATION			1033
#define DDAQ_ERROR_POST_THREAD_MESSAGE		1034
#define DDAQ_ERROR_TIMEOUT_THREAD_MESSAGE	1035
#define DDAQ_ERROR_MR_NOTEXIST				1036
#define DDAQ_ERROR_FTP_LOGIN				1037

#define DDAQ_ERROR_DEVICE_NOT_OPEN			1100
#define DDAQ_ERROR_DEVICE_ALREDAY_OPEN		1101
#define DDAQ_ERROR_NOT_STOP_MODE			1102		
#define DDAQ_ERROR_ALREADY_STOP_MODE		1103
#define DDAQ_ERROR_SEND_COMMAND				1104	
#define DDAQ_ERROR_START_RECORDING			1105
#define DDAQ_ERROR_STOP_RECORDING			1106
#define DDAQ_ERROR_INVALID_SOURCE_BUFFER	1107
#define DDAQ_ERROR_INVALID_DEST_BUFFER		1108

#define DDAQ_ERROR_INVALID_AVERAGING		1200		
#define DDAQ_ERROR_INVALID_NUMFRAMES		1201
#define DDAQ_ERROR_INVALID_MEASUREMENTRANGE	1202
#define DDAQ_ERROR_INVALID_TRIGGERMODE		1203
#define DDAQ_ERROR_INVALID_DATAUNIT			1204
#define DDAQ_ERROR_INVALID_EMISSIVITY		1205
#define DDAQ_ERROR_INVALID_TRANSMISSION		1206
#define DDAQ_ERROR_INVALID_AMBIENTTEMP		1207
#define DDAQ_ERROR_INVALID_THRESHOLD		1208
#define DDAQ_ERROR_INVALID_DATAREADMODE		1209
#define DDAQ_ERROR_INVALID_DISABLESHUTTERMODE	1210
#define DDAQ_ERROR_IN0_ALREADY_USED			1211
#define DDAQ_ERROR_IN1_ALREADY_USED			1212
#define DDAQ_ERROR_INVALID_VALIDITYTEMP		1213
#define DDAQ_ERROR_NO_MOTORFOCUS			1214
#define DDAQ_ERROR_INVALID_2DLINECOORD		1215
#define DDAQ_ERROR_WAIT_MOTOR_FOCUS_SET_POS	1216
#define DDAQ_ERROR_CORR						1217
#define DDAQ_ERROR_INVALID_FRATEDIVIDER		1218
#define DDAQ_ERROR_NO_MOTORFOCUS_POS		1219

#define DDAQ_ERROR_INVALID_IMAGE_NO			1250
#define DDAQ_ERROR_WRITE_IMAGE				1251
#define DDAQ_ERROR_PCAM_SAVEALLIMAGES		1252
#define DDAQ_ERROR_PCAM_DELETEALLIMAGES		1253

#define DDAQ_ERROR_SEND_HTTP				1255

#define DDAQ_ERROR_CHECKKALIFILE			1260
#define DDAQ_ERROR_CHECKKALIFILE_CFG		1261
#define DDAQ_ERROR_CHECKKALIFILE_DPE		1262
#define DDAQ_DDAQ_ERROR_KALIDATE			1263
#define DDAQ_ERROR_CHECKKALIFILE_TK1		1264
#define DDAQ_ERROR_CHECKKALIFILE_TK2		1265
#define DDAQ_ERROR_CHECKKALIFILE_TK3		1266
#define DDAQ_ERROR_CHECKKALIFILE_TK4		1267
#define DDAQ_ERROR_CHECKKALIFILE_TK5		1268
#define DDAQ_ERROR_CHECKKALIFILE_TK6		1269
#define DDAQ_ERROR_CHECKKALIFILE_TK7		1270
#define DDAQ_ERROR_CHECKKALIFILE_TK8		1271
#define DDAQ_ERROR_CHECKKALIFILE_TK9		1272
#define DDAQ_ERROR_CHECKKALIFILE_END		1272


////////////////////////////////////////////////////////////////////////////
// from DIASIRDX.dll

#define	DDAQ_ERROR_OFFSET_DIASIRDXDLL		2000

#define DDAQ_ERROR_INVALID_IRDX_HANDLE		2001
#define DDAQ_ERROR_FILE_NOT_EXIST			2002	
#define DDAQ_ERROR_NOT_ENAUGH_MEMORY		2003
#define DDAQ_ERROR_WRITE_BUFFER				2004
#define DDAQ_ERROR_WRITE_DISK				2005
#define DDAQ_ERROR_CLOSE_FILE				2006
#define DDAQ_ERROR_INVALID_IRDX_TYPE		2007
#define DDAQ_ERROR_DIALOG_CANCEL			2008
#define DDAQ_ERROR_ABORT_LOADING			2009

#define DDAQ_ERROR_OPEN_FILE				2010
#define DDAQ_ERROR_INVALID_FILE_SIZE		2011
#define DDAQ_ERROR_READ_FROM_FILE			2012
#define DDAQ_ERROR_INVALID_BUFFER_SIZE		2013
#define DDAQ_ERROR_DELETE_FILE				2014
#define DDAQ_ERROR_RENAME_FILE				2015
#define DDAQ_ERROR_GETFILESIZE				2016

#define DDAQ_ERROR_CREATE_SECTION			2020
#define DDAQ_ERROR_INVALID_SECTION_ID		2021
#define DDAQ_ERROR_INVALID_SECTION_INDEX	2022
#define DDAQ_ERROR_INVALID_SECTION_SIZE		2023

#define DDAQ_ERROR_CREATE_ENTRY				2030
#define DDAQ_ERROR_INVALID_ENTRY_INDEX		2031
#define DDAQ_ERROR_INVALID_ENTRY_SIZE		2032
#define DDAQ_ERROR_ENTRY_NOT_FOUND			2033
#define DDAQ_ERROR_INVALID_ENTRY_BUFFER		2034

#define DDAQ_ERROR_LOAD_HDR					2040
#define DDAQ_ERROR_LOAD_PXT					2041
#define DDAQ_ERROR_LOAD_IRD					2042
#define DDAQ_ERROR_NO_IRDX_FILE				2043

#define DDAQ_ERROR_INVALID_DATASETINDEX		2050
#define DDAQ_ERROR_INVALID_DATASETNUM		2051

#define DDAQ_ERROR_ADD_IRDX_ID				2060
#define DDAQ_ERROR_ADD_IRDX_MR				2061
#define DDAQ_ERROR_ADD_IRDX_SIZE			2062
#define DDAQ_ERROR_ADD_IRDX_UNIT			2063
#define DDAQ_ERROR_ADD_IRDX_TCAL			2064

////////////////////////////////////////////////////////////////////////////
// from DIASTCALC.dll

#define	DDAQ_ERROR_OFFSET_DIASTCALCDLL		3000

#define DDAQ_ERROR_INVALID_TCALC_HANDLE		3001
#define DDAQ_ERROR_OPEN_FROM_IRDX_HANDLE	3002
#define DDAQ_ERROR_OPEN_FROM_CAMERA_DEVNO	3003
#define DDAQ_ERROR_SAVE_TO_IRDX_HANDLE		3004
#define DDAQ_ERROR_INVALID_TCALC_TABLEID	3005
#define DDAQ_ERROR_OPEN_FROM_ABCH			3006
#define DDAQ_ERROR_INVALID_TCALC_TYPE		3007

////////////////////////////////////////////////////////////////////////////
// from DRAWDATA.dll 

#define DDAQ_ERROR_DRAWDATA					4000

////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
