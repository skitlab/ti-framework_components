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
 *  ======== acpy3_complete.c ========
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include <ti/sdo/fc/utils/dbc.h>
#include <ti/xdais/idma3.h>

#include "acpy3.h"
#include "acpy3_util.h"


extern Registry_Desc ti_sdo_fc_acpy3_desc;

#ifdef __TI_COMPILER_VERSION__
#pragma CODE_SECTION(ACPY3_complete, ".text:ACPY3_complete")
#endif

#ifndef _ACPY3_CPUCOPY_

#define ACPY3_COMPLETE_IMPLEMENTATION
#include "acpy3_complete.h"

#else


/*
 *  ======== ACPY3_complete ========
 *  Check to see if all dma transfers on logical channel are finished.
 *  This is a non-blocking call.
 */
Bool ACPY3_complete(IDMA3_Handle handle)
{
    Log_print1(Diags_ENTRY, "[+E] ACPY3_complete> Enter (handle=0x%x)",
            (IArg)handle);

    ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->extendedHooks, 
            handle, ACPY3_INSTR_COMPLETE_ENTER);

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

    if (handle->transferPending) {

        Log_print0(Diags_USER2, "[+2] ACPY3_complete> Transfer Pending");

        ACPY3_wait(handle);
    }

    Log_print0(Diags_USER2, "[+2] ACPY3_complete> No Transfers Pending");

    /* No transfers pending. */
    ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->extendedHooks, 
            handle, ACPY3_INSTR_COMPLETE_EXIT);

    Log_print0(Diags_EXIT, "[+X] ACPY3_complete> Exit (status=TRUE)");

    return (TRUE);
}
#endif
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

