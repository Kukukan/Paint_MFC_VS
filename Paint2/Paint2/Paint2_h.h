

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 10:14:07 2038
 */
/* Compiler settings for Paint2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0628 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __Paint2_h_h__
#define __Paint2_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IPaint2_FWD_DEFINED__
#define __IPaint2_FWD_DEFINED__
typedef interface IPaint2 IPaint2;

#endif 	/* __IPaint2_FWD_DEFINED__ */


#ifndef __Paint2_FWD_DEFINED__
#define __Paint2_FWD_DEFINED__

#ifdef __cplusplus
typedef class Paint2 Paint2;
#else
typedef struct Paint2 Paint2;
#endif /* __cplusplus */

#endif 	/* __Paint2_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __Paint2_LIBRARY_DEFINED__
#define __Paint2_LIBRARY_DEFINED__

/* library Paint2 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_Paint2;

#ifndef __IPaint2_DISPINTERFACE_DEFINED__
#define __IPaint2_DISPINTERFACE_DEFINED__

/* dispinterface IPaint2 */
/* [uuid] */ 


EXTERN_C const IID DIID_IPaint2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("442a4113-7cbf-4716-be3d-66fbe1205778")
    IPaint2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPaint2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPaint2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPaint2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPaint2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPaint2 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPaint2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPaint2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPaint2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IPaint2Vtbl;

    interface IPaint2
    {
        CONST_VTBL struct IPaint2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPaint2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPaint2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPaint2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPaint2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPaint2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPaint2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPaint2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPaint2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Paint2;

#ifdef __cplusplus

class DECLSPEC_UUID("2cfaa8b7-7152-435f-98e3-df1cf8117ddc")
Paint2;
#endif
#endif /* __Paint2_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


