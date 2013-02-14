/* 
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/*
 *  ======== dman3_externalRM_initImpl.c ========
 *  Initialize the DMAN3 module
 */

/* This difine must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_dman3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/knl/GateProcess.h>
#include <xdc/runtime/Registry.h>

#include <ti/sdo/fc/utils/osalsupport/OsalSupport.h>
#include <ti/sdo/fc/global/FCSettings.h>

#include "rmm.h"
#include "dman3.h"
#include "dman3_externalRM_impl.h"
#include <ti/sdo/fc/edma3/edma3_config.h>


#pragma CODE_SECTION(_DMAN3_initImpl, ".text:DMAN3_init");

__FAR__ xdc_runtime_IHeap_Handle _DMAN3_heapInt;
__FAR__ xdc_runtime_IHeap_Handle _DMAN3_heapExt;
__FAR__ xdc_runtime_IHeap_Handle _DMAN3_heapIdma3;

__FAR__ DMAN3_ScratchAllocFxn _DMAN3_allocScratch = NULL;
__FAR__ DMAN3_ScratchFreeFxn _DMAN3_freeScratch = NULL;

__FAR__ Uns _DMAN3_qdmaIndex = 0;

__FAR__ DMAN3_QdmaObj * DMAN3_QDMA;

UInt32          *_DMAN3_paRamAddr = NULL;
UInt32          *_DMAN3_edma3Addr = NULL;
UInt32          _DMAN3_nullPaRam = 0x0;
IGateProvider_Handle DMAN3_gate = NULL;

UInt32 _DMAN3_qdmaBase[DMAN3_MAXGROUPS + 1]; 
UInt32 _DMAN3_qdmaCounter[DMAN3_MAXGROUPS + 1]; 

static Int _DMAN3_refCount = 0;

static Int regInit = 0;  /* Registry_addModule() called */

Registry_Desc ti_sdo_fc_dman3_desc;

/*
 *  ======== _DMAN3_initImpl ========
 *  Initialize the DMAN module
 */
Void _DMAN3_initImpl(Void)
{
    Int totalQdmas = -1;
    Int i = 0;
    Registry_Result regResult;

    /*
     *  Register the module name for logging only once. Do this before any
     *  Log functions are called.
     */
    if (regInit == 0) {
        regResult = Registry_addModule(&ti_sdo_fc_dman3_desc, DMAN3_MODNAME);

        Assert_isTrue(regResult == Registry_SUCCESS, (Assert_Id)NULL);

        /* Set diags mask to FC default */
        FCSettings_init();
        FCSettings_setDiags(DMAN3_MODNAME);
        regInit = 1;
    }

    Log_print0(Diags_ENTRY, "[+E] _DMAN3_initImpl> Enter");

    if (_DMAN3_refCount++ == 0) {
        DMAN3_gate = OsalSupport_createGate(_DMAN3_GATEID);
        Assert_isTrue(DMAN3_gate != NULL, (Assert_Id)NULL);

        /*
         *  Initialize _DMAN3_heapInt and _DMAN3_heapExt with provided
         *  heaps. Use internal heap for _DMAN3_heapInt when provided.
         *  (Actually this is a fatal error if ACPY3 uses internal DMA
         *  (IDMA) to write to PARAMs.
         */
        _DMAN3_heapInt = DMAN3_PARAMS.heapInternal;
        _DMAN3_heapExt = DMAN3_PARAMS.heapExternal;

        _DMAN3_heapInt = (_DMAN3_heapInt == NULL) ?
            _DMAN3_heapExt : _DMAN3_heapInt;
        _DMAN3_heapExt = (_DMAN3_heapExt == NULL) ?
            _DMAN3_heapInt : _DMAN3_heapExt;
        _DMAN3_heapIdma3 = (DMAN3_PARAMS.idma3Internal) ?
            _DMAN3_heapInt : _DMAN3_heapExt;

        /* This is a fatal configuration error. */
        Assert_isTrue(_DMAN3_heapInt != NULL, (Assert_Id)NULL);

        /*
         *  Configured function for allocating IDMA3 object's env from
         *  shared scratch memory.
         */
        _DMAN3_allocScratch = DMAN3_PARAMS.scratchAllocFxn;

        /*
         *  Configured function for allocating IDMA3 object's env from
         *  shared scratch memory.
         */
        _DMAN3_freeScratch = DMAN3_PARAMS.scratchFreeFxn;

        /*
         *  If one of _DMAN3_allocScratch or _DMAN3_freeScratch is NULL,
         *  then the other must be NULL.
         */
        Assert_isTrue((_DMAN3_allocScratch != NULL) ||
                (_DMAN3_freeScratch == NULL), (Assert_Id)NULL);
        Assert_isTrue((_DMAN3_freeScratch != NULL) ||
                (_DMAN3_allocScratch == NULL), (Assert_Id)NULL);

        if (ti_sdo_fc_dman3_DMAN3_useCustomDma) {
    
            /* Distribute channels among scratch groups */
            totalQdmas = 0;
    
            for (i =0; i < DMAN3_MAXGROUPS; i++) {
                if (_DMAN3_numQdmaGroup(i) >0) {
                    Assert_isTrue(totalQdmas < DMAN3_PARAMS.numQdmaChannels,
                            (Assert_Id)NULL);  
                    /* Set the allocation base for each scratch group */ 
                    _DMAN3_qdmaBase[i] = totalQdmas;
                    _DMAN3_qdmaCounter[i] = totalQdmas;
                }
                else {
                    //TODO: Should this be set to "0" ?
                    _DMAN3_qdmaBase[i] = -1;
                    _DMAN3_qdmaCounter[i] = -1;
                }
                totalQdmas += _DMAN3_numQdmaGroup(i);
            } 
    
          /* Leave the rest of the QDMA channels (if any) to scratch group -1 */ 
            ti_sdo_fc_dman3_DMAN3_numQdmaGroup[DMAN3_MAXGROUPS] = 
                    DMAN3_PARAMS.numQdmaChannels - totalQdmas;
            _DMAN3_qdmaBase[DMAN3_MAXGROUPS] = totalQdmas;
            _DMAN3_qdmaCounter[i] = totalQdmas;
        }
        else {
                        /* Not using custom library */
            for (i =0; i < DMAN3_MAXGROUPS + 1; i++) {
                
                                /* Set base to the first qdma channel */
                                _DMAN3_qdmaBase[i] = 0;
                _DMAN3_qdmaCounter[i] = 0;
                /* Set num to total Qdma channels available */
                                ti_sdo_fc_dman3_DMAN3_numQdmaGroup[i] = 
                        DMAN3_PARAMS.numQdmaChannels;
            }
        }
    }

    Log_print0(Diags_EXIT, "[+X] _DMAN3_initImpl> Exit");
}

/*
 *  ======== DMAN3_exit ========
 *  Finalization method of the DMAN3 module
 */
Void DMAN3_exit(Void)
{
    Log_print0(Diags_ENTRY, "[+E] DMAN3_exit> Enter");

    if (_DMAN3_refCount == 0) {
        Log_print0(Diags_USER7, "[+7] DMAN3_exit> Reference "
                "count already zero, mismatch between DMAN3_init and DMAN3_exit"                "calls\n");
    }
    else {
        --_DMAN3_refCount;
    }

    Log_print0(Diags_EXIT, "[+X] DMAN3_exit> Exit");
}
/*
 *  @(#) ti.sdo.fc.dman3; 1, 0, 4,4; 2-22-2012 18:03:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

