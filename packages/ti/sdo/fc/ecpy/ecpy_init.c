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
 *  ======== ecpy_init.c ========
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_ecpy_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>

#include <xdc/runtime/Registry.h>

#include <ti/sdo/fc/global/FCSettings.h>

#include "ecpy.h"

#ifdef xdc_target__isaCompatible_64P
#pragma CODE_SECTION(ECPY_init, ".text:ECPY_init")
#pragma CODE_SECTION(ECPY_exit, ".text:ECPY_exit")
#endif

Registry_Desc ti_sdo_fc_ecpy_desc;

static __FAR__ Int _ECPY_refCount  = 0;


/*
 *  ======== ECPY_exit ========
 *  Finalize the ECPY module
 */
Void ECPY_exit(Void)
{
    Log_print0(Diags_ENTRY, "[+E] ECPY_exit> Enter");

    _ECPY_refCount--;

    if (_ECPY_refCount == 0) {
    }

    Log_print0(Diags_EXIT, "[+X] ECPY_exit> Exit");
}

/*
 *  ======== ECPY_init ========
 *  Initialize the ECPY module. Don't do anything interesting here, since
 *  we cannot get logging.
 */
void ECPY_init(Void)
{
    Registry_Result   result;

    if (_ECPY_refCount++ == 0) {
        /* Register this module for logging */
        result = Registry_addModule(&ti_sdo_fc_ecpy_desc, ECPY_MODNAME);
        Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

        if (result == Registry_SUCCESS) {
            /* Set the diags mask to the FC default */
            FCSettings_init();
            FCSettings_setDiags(ECPY_MODNAME);
        }
    }

    Log_print0(Diags_ENTRY, "[+E] ECPY_init> Enter");

    Assert_isTrue((NULL != ECPY_CFG_PARAMS.allocFxn) && 
           (NULL != ECPY_CFG_PARAMS.freeFxn), (Assert_Id)NULL);

    Log_print0(Diags_EXIT, "[+X] ECPY_init> Exit");
}
/*
 *  @(#) ti.sdo.fc.ecpy; 1, 0, 1,4; 2-22-2012 18:04:13; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

