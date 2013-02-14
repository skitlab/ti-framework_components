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
 *  ======== shmalg_ti_vtab.c ========
 *  Definition of SHMALG_TI_ISHMALG.
 *
 *  Since ISHMALG derives from IALG,we also define the sym
 *  SHMALG_TI_IALG, TI's implementation of the IALG interface.
 */

#include <xdc/std.h>
#include "ishmalg.h"
#include "shmalg_ti.h"
#include "shmalg_ti_priv.h"

#define IALGFXNS \
    &SHMALG_TI_IALG,        /* module ID */                     \
    SHMALG_TI_activate,     /* activate */                      \
    SHMALG_TI_alloc,        /* algAlloc */                      \
    SHMALG_TI_control,      /* control ops */                   \
    SHMALG_TI_deactivate,   /* deactivate */                    \
    SHMALG_TI_free,         /* free */                          \
    SHMALG_TI_initObj,      /* init */                          \
    NULL,                   /* moved (NULL => not suported) */  \
    SHMALG_TI_numAlloc      /* numAlloc (NULL => IALG_DEFMEMRECS) */\


/*
 *  ======== SHMALG_TI_ISHMALG ========
 *  This structure defines TI's implementation of the ISHMALG interface
 *  for the SHMALG_TI module.
 */
ISHMALG_Fxns SHMALG_TI_ISHMALG = {    /* module_vendor_interface */
    IALGFXNS,
    SHMALG_TI_useBufs,
    SHMALG_TI_checkBufs,
};

#ifdef __TI_COMPILER_VERSION__

/*
 *  ======== SHMALG_TI_IALG ========
 *  This structure defines TI's implementation of the IALG interface
 *  for the SHMALG_TI module.
 */
asm("_SHMALG_TI_IALG .set _SHMALG_TI_ISHMALG");
#else
/*
 *  We duplicate the structure here to allow this code to be compiled and
 *  run non-DSP platforms at the expense of unnecessary data space
 *  consumed by the definition below.
 */
IALG_Fxns SHMALG_TI_IALG = {
    IALGFXNS
};

#endif
/*
 *  @(#) ti.sdo.fc.rman.examples.shmbuf; 1, 0, 0,4; 2-22-2012 18:08:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

