/////////////////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////////////////
/// \file _T_DIASDAQDLL.h	MBCS/UNICODE fitting include file for DIASDAQDLL
////////////////////////////////////////////////////////////////////////////

#include "DIASDAQDLL.h"

////////////////////////////////////////////////////////////////////////////
// Global Functions DDAQ_SET_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_SET_LOCALE	DDAQ_SET_LOCALE_UC
#else
#define _T_DDAQ_SET_LOCALE	DDAQ_SET_LOCALE
#endif

////////////////////////////////////////////////////////////////////////////
// Global Functions DDAQ_GET_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_GET_TEMPSTRING	DDAQ_GET_TEMPSTRING_UC
#else
#define _T_DDAQ_GET_TEMPSTRING	DDAQ_GET_TEMPSTRING
#endif

#ifdef _UNICODE
#define _T_DDAQ_GET_TEMPPRECSTRING	DDAQ_GET_TEMPPRECSTRING_UC
#else
#define _T_DDAQ_GET_TEMPPRECSTRING	DDAQ_GET_TEMPPRECSTRING
#endif

#ifdef _UNICODE
#define _T_DDAQ_GET_TEMPUNITSTRING	DDAQ_GET_TEMPUNITSTRING_UC
#else
#define _T_DDAQ_GET_TEMPUNITSTRING	DDAQ_GET_TEMPUNITSTRING
#endif

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_SER_DEVICE_IP_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_SET_DEVICE_IP_AUTO	DDAQ_SET_DEVICE_IP_AUTO_UC
#else
#define _T_DDAQ_SET_DEVICE_IP_AUTO	DDAQ_SET_DEVICE_IP_AUTO
#endif

#ifdef _UNICODE
#define _T_DDAQ_SET_DEVICE_IP_STATIC	DDAQ_SET_DEVICE_IP_STATIC_UC
#else
#define _T_DDAQ_SET_DEVICE_IP_STATIC	DDAQ_SET_DEVICE_IP_STATIC
#endif

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_DEVICE_DO_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_LIST	DDAQ_DEVICE_DO_LIST_UC
#else
#define _T_DDAQ_DEVICE_DO_LIST	DDAQ_DEVICE_DO_LIST
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_OPEN	DDAQ_DEVICE_DO_OPEN_UC
#else
#define _T_DDAQ_DEVICE_DO_OPEN	DDAQ_DEVICE_DO_OPEN
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_OPEN_INTERFACE	DDAQ_DEVICE_DO_OPEN_INTERFACE_UC
#else
#define _T_DDAQ_DEVICE_DO_OPEN_INTERFACE	DDAQ_DEVICE_DO_OPEN_INTERFACE
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_CHANGE_TEMPLATE	DDAQ_DEVICE_DO_CHANGE_TEMPLATE_UC
#else
#define _T_DDAQ_DEVICE_DO_CHANGE_TEMPLATE	DDAQ_DEVICE_DO_CHANGE_TEMPLATE
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_OPENSIMULATION	DDAQ_DEVICE_DO_OPENSIMULATION_UC
#else
#define _T_DDAQ_DEVICE_DO_OPENSIMULATION	DDAQ_DEVICE_DO_OPENSIMULATION
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_DOWNLOADIMAGE	DDAQ_DEVICE_DO_DOWNLOADIMAGE_UC
#else
#define _T_DDAQ_DEVICE_DO_DOWNLOADIMAGE	DDAQ_DEVICE_DO_DOWNLOADIMAGE
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_DO_DOWNLOADALLIMAGES	DDAQ_DEVICE_DO_DOWNLOADALLIMAGES_UC
#else
#define _T_DDAQ_DEVICE_DO_DOWNLOADALLIMAGES	DDAQ_DEVICE_DO_DOWNLOADALLIMAGES
#endif

////////////////////////////////////////////////////////////////////////////
// Functions DDAQ_DEVICE_GET_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_GET_IDSTRING	DDAQ_DEVICE_GET_IDSTRING_UC
#else
#define _T_DDAQ_DEVICE_GET_IDSTRING	DDAQ_DEVICE_GET_IDSTRING
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_GET_IDSTRING_EX	DDAQ_DEVICE_GET_IDSTRING_EX_UC
#else
#define _T_DDAQ_DEVICE_GET_IDSTRING_EX	DDAQ_DEVICE_GET_IDSTRING_EX
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_GET_INTERFACESTRING	DDAQ_DEVICE_GET_INTERFACESTRING_UC
#else
#define _T_DDAQ_DEVICE_GET_INTERFACESTRING	DDAQ_DEVICE_GET_INTERFACESTRING
#endif

#ifdef _UNICODE
#define _T_DDAQ_DEVICE_GET_MRANGESTRING	DDAQ_DEVICE_GET_MRANGESTRING_UC
#else
#define _T_DDAQ_DEVICE_GET_MRANGESTRING	DDAQ_DEVICE_GET_MRANGESTRING
#endif

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_FILE_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_DELETE	DDAQ_IRDX_FILE_DELETE_UC
#else
#define _T_DDAQ_IRDX_FILE_DELETE	DDAQ_IRDX_FILE_DELETE
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_GETSIZE	DDAQ_IRDX_FILE_GETSIZE_UC
#else
#define _T_DDAQ_IRDX_FILE_GETSIZE	DDAQ_IRDX_FILE_GETSIZE
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_RENAME	DDAQ_IRDX_FILE_RENAME_UC
#else
#define _T_DDAQ_IRDX_FILE_RENAME	DDAQ_IRDX_FILE_RENAME
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_OPEN_READ	DDAQ_IRDX_FILE_OPEN_READ_UC
#else
#define _T_DDAQ_IRDX_FILE_OPEN_READ	DDAQ_IRDX_FILE_OPEN_READ
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_OPEN_WRITE	DDAQ_IRDX_FILE_OPEN_WRITE_UC
#else
#define _T_DDAQ_IRDX_FILE_OPEN_WRITE	DDAQ_IRDX_FILE_OPEN_WRITE
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_OPEN_READWRITE	DDAQ_IRDX_FILE_OPEN_READWRITE_UC
#else
#define _T_DDAQ_IRDX_FILE_OPEN_READWRITE	DDAQ_IRDX_FILE_OPEN_READWRITE
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_FILE_SAVE	DDAQ_IRDX_FILE_SAVE_UC
#else
#define _T_DDAQ_IRDX_FILE_SAVE	DDAQ_IRDX_FILE_SAVE
#endif

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_DEVICE_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_IRDX_DEVICE_GET_IDSTRING	DDAQ_IRDX_DEVICE_GET_IDSTRING_UC
#else
#define _T_DDAQ_IRDX_DEVICE_GET_IDSTRING	DDAQ_IRDX_DEVICE_GET_IDSTRING
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_DEVICE_GET_IDSTRING_EX	DDAQ_IRDX_DEVICE_GET_IDSTRING_EX_UC
#else
#define _T_DDAQ_IRDX_DEVICE_GET_IDSTRING_EX	DDAQ_IRDX_DEVICE_GET_IDSTRING_EX
#endif

////////////////////////////////////////////////////////////////////////////
// DDAQ_IRDX_ACQUISITION_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_IRDX_ACQUISITION_GET_MRANGESTRING	DDAQ_IRDX_ACQUISITION_GET_MRANGESTRING_UC
#else
#define _T_DDAQ_IRDX_ACQUISITION_GET_MRANGESTRING	DDAQ_IRDX_ACQUISITION_GET_MRANGESTRING
#endif

////////////////////////////////////////////////////////////////////////////
// IRDX_USERDATA_xxxx
////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define _T_DDAQ_IRDX_USERDATA_GET_PRODUCTNAME	DDAQ_IRDX_USERDATA_GET_PRODUCTNAME_UC
#else
#define _T_DDAQ_IRDX_USERDATA_GET_PRODUCTNAME	DDAQ_IRDX_USERDATA_GET_PRODUCTNAME
#endif

#ifdef _UNICODE
#define _T_DDAQ_IRDX_USERDATA_SET_PRODUCTNAME	DDAQ_IRDX_USERDATA_SET_PRODUCTNAME_UC
#else
#define _T_DDAQ_IRDX_USERDATA_SET_PRODUCTNAME	DDAQ_IRDX_USERDATA_SET_PRODUCTNAME
#endif

////////////////////////////////////////////////////////////////////////////
