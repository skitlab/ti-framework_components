/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y25
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     CREATE ARGS
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     FUNCTION SELECTORS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sdo_fc_utils_osal_noOS_SemThreadNull__include
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull__include

#ifndef __nested__
#define __nested__
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_fc_utils_osal_noOS_SemThreadNull___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sdo/fc/utils/osal/noOS/package/package.defs.h>

#include <xdc/runtime/knl/ISemThreadSupport.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* PendStatus */
typedef xdc_runtime_knl_ISemaphore_PendStatus ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus;

/* FOREVER */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_FOREVER (~(0))

/* Mode */
typedef xdc_runtime_knl_ISemaphore_Mode ti_sdo_fc_utils_osal_noOS_SemThreadNull_Mode;

/* PendStatus_ERROR */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus_ERROR xdc_runtime_knl_ISemaphore_PendStatus_ERROR

/* PendStatus_TIMEOUT */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus_TIMEOUT xdc_runtime_knl_ISemaphore_PendStatus_TIMEOUT

/* PendStatus_SUCCESS */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus_SUCCESS xdc_runtime_knl_ISemaphore_PendStatus_SUCCESS

/* Mode_COUNTING */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Mode_COUNTING xdc_runtime_knl_ISemaphore_Mode_COUNTING

/* Mode_BINARY */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Mode_BINARY xdc_runtime_knl_ISemaphore_Mode_BINARY


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_Args__create {
    xdc_Int count;
} ti_sdo_fc_utils_osal_noOS_SemThreadNull_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsEnabled ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsIncluded ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__gateObj ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__gatePrms ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__id;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__id ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerDefined ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerObj ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn0 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn1 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn2 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn4 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn8 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDoneFxn ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__count;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__count ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__heap;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__heap ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__sizeof ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__table;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__table ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    xdc_runtime_knl_ISemaphore_Mode mode;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct {
    const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Fxns__* __fxns;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Int (*pend)(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle, xdc_UInt, xdc_runtime_Error_Block*);
    xdc_Bool (*post)(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Fxns__ ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_startup( state ) -1

/* Instance_init__F */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init__F, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init")
__extern void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init__F( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object*, xdc_Int count, const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* );

/* Instance_init__R */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init__R, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init")
__extern void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init__R( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object*, xdc_Int count, const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* );

/* Handle__label__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle__label__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle__label")
__extern xdc_runtime_Types_Label* ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDone__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDone")
__extern xdc_Bool ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__create__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__create")
__extern xdc_Ptr ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__delete__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__delete")
__extern xdc_Void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__destruct__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__destruct")
__extern xdc_Void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__get__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__get")
__extern xdc_Ptr ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__first__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__first")
__extern xdc_Ptr ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__next__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__next")
__extern xdc_Ptr ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params__init__S, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params__init")
__extern xdc_Void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* pend__E */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__E
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__E, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend")
__extern xdc_Int ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__E( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle __inst, xdc_UInt timeout, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__F, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend")
__extern xdc_Int ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__F( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object* __inst, xdc_UInt timeout, xdc_runtime_Error_Block* eb );
__extern xdc_Int ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__R( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle __inst, xdc_UInt timeout, xdc_runtime_Error_Block* eb );

/* post__E */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_post ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__E
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__E, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_post")
__extern xdc_Bool ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__E( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle __inst, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__F, "ti_sdo_fc_utils_osal_noOS_SemThreadNull_post")
__extern xdc_Bool ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__F( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object* __inst, xdc_runtime_Error_Block* eb );
__extern xdc_Bool ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__R( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle __inst, xdc_runtime_Error_Block* eb );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* pend_{FxnT,fxnP} */
typedef xdc_Int (*ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend_FxnT)(void*, xdc_UInt, xdc_runtime_Error_Block*);
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend_FxnT ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend_fxnP( void )
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend_FxnT)ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend; 
}

/* post_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sdo_fc_utils_osal_noOS_SemThreadNull_post_FxnT)(void*, xdc_runtime_Error_Block*);
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_post_FxnT ti_sdo_fc_utils_osal_noOS_SemThreadNull_post_fxnP( void )
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_post_FxnT)ti_sdo_fc_utils_osal_noOS_SemThreadNull_post; 
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_knl_ISemThreadSupport_Module ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_upCast( void )
{
    return (xdc_runtime_knl_ISemThreadSupport_Module)&ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__FXNS__C;
}

/* Module_to_xdc_runtime_knl_ISemThreadSupport */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_to_xdc_runtime_knl_ISemThreadSupport ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_knl_ISemThreadSupport_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_upCast( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle i )
{
    return (xdc_runtime_knl_ISemThreadSupport_Handle)i;
}

/* Handle_to_xdc_runtime_knl_ISemThreadSupport */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_to_xdc_runtime_knl_ISemThreadSupport ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_upCast

/* Handle_downCast */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_downCast( xdc_runtime_knl_ISemThreadSupport_Handle i )
{
    xdc_runtime_knl_ISemThreadSupport_Handle i2 = (xdc_runtime_knl_ISemThreadSupport_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__FXNS__C ? (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)i : 0;
}

/* Handle_from_xdc_runtime_knl_ISemThreadSupport */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_from_xdc_runtime_knl_ISemThreadSupport ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_downCast

/* Module_upCast2 */
static inline xdc_runtime_knl_ISemaphore_Module ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_upCast2( void )
{
    return (xdc_runtime_knl_ISemaphore_Module)&ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__FXNS__C;
}

/* Module_to_xdc_runtime_knl_ISemaphore */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_to_xdc_runtime_knl_ISemaphore ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_upCast2

/* Handle_upCast2 */
static inline xdc_runtime_knl_ISemaphore_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_upCast2( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle i )
{
    return (xdc_runtime_knl_ISemaphore_Handle)i;
}

/* Handle_to_xdc_runtime_knl_ISemaphore */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_to_xdc_runtime_knl_ISemaphore ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_upCast2

/* Handle_downCast2 */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_downCast2( xdc_runtime_knl_ISemaphore_Handle i )
{
    xdc_runtime_knl_ISemaphore_Handle i2 = (xdc_runtime_knl_ISemaphore_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__FXNS__C ? (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)i : 0;
}

/* Handle_from_xdc_runtime_knl_ISemaphore */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_from_xdc_runtime_knl_ISemaphore ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_downCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_startupDone() ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_heap() ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__heap__C

/* Module_heap */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_heap() ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__id ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_id( void ) 
{
    return ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_hasMask( void ) 
{
    return ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_getMask( void ) 
{
    return ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask__C != NULL ? *ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask__C != NULL) *ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params_init( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* prms ) 
{
    if (prms) {
        ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params__init__S(prms, 0, sizeof(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params_copy( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* dst, const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* src ) 
{
    if (dst) {
        ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params__init__S(dst, (xdc_Ptr)src, sizeof(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_count() ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__count__C

/* Object_sizeof */
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_sizeof() ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__sizeof__C

/* Object_get */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_get( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_State* oarr, int i ) 
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_first( void )
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__first__S();
}

/* Object_next */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_next( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object* obj )
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_label( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle inst, xdc_runtime_Types_Label* lab )
{
    return ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_name( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_create( xdc_Int count, const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    ti_sdo_fc_utils_osal_noOS_SemThreadNull_Args__create __args;
    __args.count = count;
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__create__S(0, 0, &__args, (const xdc_UChar*)__prms, sizeof(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params), __eb);
}

/* construct */
static inline void ti_sdo_fc_utils_osal_noOS_SemThreadNull_construct( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct* __obj, xdc_Int count, const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params* __prms )
{
    ti_sdo_fc_utils_osal_noOS_SemThreadNull_Args__create __args;
    __args.count = count;
    ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__create__S(__obj, sizeof (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct), &__args, (const xdc_UChar*)__prms, sizeof(ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params), NULL);
}

/* delete */
static inline void ti_sdo_fc_utils_osal_noOS_SemThreadNull_delete( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle* instp )
{
    ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__delete__S(instp);
}

/* destruct */
static inline void ti_sdo_fc_utils_osal_noOS_SemThreadNull_destruct( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct* obj )
{
    ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__destruct__S(obj);
}

/* handle */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_handle( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct* str )
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle)str;
}

/* struct */
static inline ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct* ti_sdo_fc_utils_osal_noOS_SemThreadNull_struct( ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle inst )
{
    return (ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_fc_utils_osal_noOS_SemThreadNull__top__
#undef __nested__
#endif

#endif /* ti_sdo_fc_utils_osal_noOS_SemThreadNull__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_fc_utils_osal_noOS_SemThreadNull__internalaccess))

#ifndef ti_sdo_fc_utils_osal_noOS_SemThreadNull__include_state
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull__include_state

/* Object */
struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object {
    const ti_sdo_fc_utils_osal_noOS_SemThreadNull_Fxns__* __fxns;
};

#endif /* ti_sdo_fc_utils_osal_noOS_SemThreadNull__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_fc_utils_osal_noOS_SemThreadNull__nolocalnames)

#ifndef ti_sdo_fc_utils_osal_noOS_SemThreadNull__localnames__done
#define ti_sdo_fc_utils_osal_noOS_SemThreadNull__localnames__done

/* module prefix */
#define SemThreadNull_Instance ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance
#define SemThreadNull_Handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle
#define SemThreadNull_Module ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module
#define SemThreadNull_Object ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object
#define SemThreadNull_Struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_Struct
#define SemThreadNull_PendStatus ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus
#define SemThreadNull_FOREVER ti_sdo_fc_utils_osal_noOS_SemThreadNull_FOREVER
#define SemThreadNull_Mode ti_sdo_fc_utils_osal_noOS_SemThreadNull_Mode
#define SemThreadNull_Instance_State ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_State
#define SemThreadNull_PendStatus_ERROR ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus_ERROR
#define SemThreadNull_PendStatus_TIMEOUT ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus_TIMEOUT
#define SemThreadNull_PendStatus_SUCCESS ti_sdo_fc_utils_osal_noOS_SemThreadNull_PendStatus_SUCCESS
#define SemThreadNull_Mode_COUNTING ti_sdo_fc_utils_osal_noOS_SemThreadNull_Mode_COUNTING
#define SemThreadNull_Mode_BINARY ti_sdo_fc_utils_osal_noOS_SemThreadNull_Mode_BINARY
#define SemThreadNull_Params ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params
#define SemThreadNull_pend ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend
#define SemThreadNull_pend_fxnP ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend_fxnP
#define SemThreadNull_pend_FxnT ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend_FxnT
#define SemThreadNull_post ti_sdo_fc_utils_osal_noOS_SemThreadNull_post
#define SemThreadNull_post_fxnP ti_sdo_fc_utils_osal_noOS_SemThreadNull_post_fxnP
#define SemThreadNull_post_FxnT ti_sdo_fc_utils_osal_noOS_SemThreadNull_post_FxnT
#define SemThreadNull_Module_name ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_name
#define SemThreadNull_Module_id ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_id
#define SemThreadNull_Module_startup ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_startup
#define SemThreadNull_Module_startupDone ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_startupDone
#define SemThreadNull_Module_hasMask ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_hasMask
#define SemThreadNull_Module_getMask ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_getMask
#define SemThreadNull_Module_setMask ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_setMask
#define SemThreadNull_Object_heap ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_heap
#define SemThreadNull_Module_heap ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_heap
#define SemThreadNull_construct ti_sdo_fc_utils_osal_noOS_SemThreadNull_construct
#define SemThreadNull_create ti_sdo_fc_utils_osal_noOS_SemThreadNull_create
#define SemThreadNull_handle ti_sdo_fc_utils_osal_noOS_SemThreadNull_handle
#define SemThreadNull_struct ti_sdo_fc_utils_osal_noOS_SemThreadNull_struct
#define SemThreadNull_Handle_label ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_label
#define SemThreadNull_Handle_name ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_name
#define SemThreadNull_Instance_init ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_init
#define SemThreadNull_Object_count ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_count
#define SemThreadNull_Object_get ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_get
#define SemThreadNull_Object_first ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_first
#define SemThreadNull_Object_next ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_next
#define SemThreadNull_Object_sizeof ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object_sizeof
#define SemThreadNull_Params_copy ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params_copy
#define SemThreadNull_Params_init ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params_init
#define SemThreadNull_Instance_State ti_sdo_fc_utils_osal_noOS_SemThreadNull_Instance_State
#define SemThreadNull_delete ti_sdo_fc_utils_osal_noOS_SemThreadNull_delete
#define SemThreadNull_destruct ti_sdo_fc_utils_osal_noOS_SemThreadNull_destruct
#define SemThreadNull_Module_upCast ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_upCast
#define SemThreadNull_Module_to_xdc_runtime_knl_ISemThreadSupport ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_to_xdc_runtime_knl_ISemThreadSupport
#define SemThreadNull_Handle_upCast ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_upCast
#define SemThreadNull_Handle_to_xdc_runtime_knl_ISemThreadSupport ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_to_xdc_runtime_knl_ISemThreadSupport
#define SemThreadNull_Handle_downCast ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_downCast
#define SemThreadNull_Handle_from_xdc_runtime_knl_ISemThreadSupport ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_from_xdc_runtime_knl_ISemThreadSupport
#define SemThreadNull_Module_upCast2 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_upCast2
#define SemThreadNull_Module_to_xdc_runtime_knl_ISemaphore ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module_to_xdc_runtime_knl_ISemaphore
#define SemThreadNull_Handle_upCast2 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_upCast2
#define SemThreadNull_Handle_to_xdc_runtime_knl_ISemaphore ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_to_xdc_runtime_knl_ISemaphore
#define SemThreadNull_Handle_downCast2 ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_downCast2
#define SemThreadNull_Handle_from_xdc_runtime_knl_ISemaphore ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle_from_xdc_runtime_knl_ISemaphore

#endif /* ti_sdo_fc_utils_osal_noOS_SemThreadNull__localnames__done */
#endif
