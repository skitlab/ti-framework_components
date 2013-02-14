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
 *  ======== usescratch_ti_vtab.c ========
 *  Definition of USESCRATCH_TI_IUSESCRATCH.  
 *
 *  Since IUSESCRATCH derives from IALG,we also define the sym
 *  USESCRATCH_TI_IALG, TI's implementation of the IALG interface.
 */

#include <xdc/std.h>
#include "iusescratch.h"
#include "usescratch_ti.h"
#include "usescratch_ti_priv.h"

#define IALGFXNS \
    &USESCRATCH_TI_IALG,        /* module ID */                     \
    USESCRATCH_TI_activate,     /* activate */                      \
    USESCRATCH_TI_alloc,        /* algAlloc */                      \
    USESCRATCH_TI_control,      /* control ops */                   \
    USESCRATCH_TI_deactivate,   /* deactivate */                    \
    USESCRATCH_TI_free,         /* free */                          \
    USESCRATCH_TI_initObj,      /* init */                          \
    NULL,                       /* moved (NULL => not suported) */  \
    USESCRATCH_TI_numAlloc      /* numAlloc (NULL => IALG_DEFMEMRECS) */\


/*
 *  ======== USESCRATCH_TI_IUSESCRATCH ========
 *  This structure defines TI's implementation of the IUSESCRATCH interface
 *  for the USESCRATCH_TI module.
 */
IUSESCRATCH_Fxns USESCRATCH_TI_IUSESCRATCH = {    /* module_vendor_interface */
    IALGFXNS,
    USESCRATCH_TI_useScratch,
    USESCRATCH_TI_getBufs,
};

/*
 *  ======== USESCRATCH_TI_IALG ========
 *  This structure defines TI's implementation of the IALG interface
 *  for the USESCRATCH_TI module.
 */
/*
#ifdef __TI_COMPILER_VERSION__
asm("_USESCRATCH_TI_IALG .set _USESCRATCH_TI_IUSESCRATCH");
#else
*/

/*
 *  We duplicate the structure here to allow this code to be compiled and
 *  run non-DSP platforms at the expense of unnecessary data space
 *  consumed by the definition below.
 */
IALG_Fxns USESCRATCH_TI_IALG = {      /* module_vendor_interface */
    IALGFXNS
};

/* #endif */
/*
 *  @(#) ti.sdo.fc.dskt2.examples; 1, 0, 0,4; 2-22-2012 18:03:54; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

