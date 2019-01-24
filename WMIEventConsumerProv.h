

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Jan 23 15:05:39 2019
 */
/* Compiler settings for WMIEventConsumerProv.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __WMIEventConsumerProv_h__
#define __WMIEventConsumerProv_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __EventConsumer_FWD_DEFINED__
#define __EventConsumer_FWD_DEFINED__

#ifdef __cplusplus
typedef class EventConsumer EventConsumer;
#else
typedef struct EventConsumer EventConsumer;
#endif /* __cplusplus */

#endif 	/* __EventConsumer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "wbemprov.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __WMIEVENTCONSUMERPROVLib_LIBRARY_DEFINED__
#define __WMIEVENTCONSUMERPROVLib_LIBRARY_DEFINED__

/* library WMIEVENTCONSUMERPROVLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WMIEVENTCONSUMERPROVLib;

EXTERN_C const CLSID CLSID_EventConsumer;

#ifdef __cplusplus

class DECLSPEC_UUID("96BEA408-AFDD-41A6-B67B-8E9F5DB7BFD9")
EventConsumer;
#endif
#endif /* __WMIEVENTCONSUMERPROVLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


