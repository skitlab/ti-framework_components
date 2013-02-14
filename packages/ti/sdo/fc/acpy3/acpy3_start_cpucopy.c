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
 *  ======== acpy3_start_cpuCopy.c ========
 *  No DMA (just CPU copy) C model of the acpy3_start() implementation.
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include "acpy3.h"
#include <ti/xdais/idma3.h>
#include "acpy3_util.h"


#ifdef _ACPY3_CPUCOPY_

#ifdef xdc_target__isaCompatible_64P
#pragma CODE_SECTION(ACPY3_start, ".text:ACPY3_start")
#endif

extern Registry_Desc ti_sdo_fc_acpy3_desc;

/*
 *  ======= ACPY3_start ========
 *  Submit a single or linked transfer using the most recently.
 *  configured transfer parameter settings.
 */
void ACPY3_start(IDMA3_Handle handle)
{
    Log_print1(Diags_ENTRY, "[+E] ACPY3_start> Enter (handle=0x%x)",
            (IArg)handle);

    if (handle->transferPending) {

        /* Wait for previously started transfer (if any) to complete */

        Log_print0(Diags_USER4, "[+4] ACPY3_start> Waiting for"
                " previously started transfer");

        ACPY3_wait(handle);
    }

    /*
     * As soon as channel is clear mark the channel state to indicate a
     * new transfer is being issued and 'transfer is pending'.
     * Only a subsequent 'ACPY3_wait' will clear the pending state.
     */
    handle->transferPending = TRUE;

    Log_print0(Diags_EXIT, "[+X] ACPY3_start> Exit");

}


#endif

/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

