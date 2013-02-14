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

#include <xdc/std.h>
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp2.h>
#include <ti/sysbios/knl/Task.h>

#define SLEEPTIME 2

/* Everything below is a poor attempt at implementing the "wait" function */ 
#include <ti/sdo/fc/ires/hdvicp/_hdvicp2.h>


/* Cal to obtain yield arguments for a particular scratch group */
extern IRES_YieldArgs (* ti_sdo_fc_ires_hdvicp_HDVICP2_getYieldArgs)
        (Int scratchId);

/* Call to release group lock/context etc */ 
extern Void (* ti_sdo_fc_ires_hdvicp_HDVICP2_yieldRelease)
        (IRES_YieldResourceType resource, IRES_YieldContextHandle ctxt, 
        IRES_YieldArgs args); 

/* Call to re-acquire group lock/context etc */ 
extern Void (* ti_sdo_fc_ires_hdvicp_HDVICP2_yieldAcquire)
        (IRES_YieldResourceType resource, IRES_YieldContextHandle ctxt, 
        IRES_YieldArgs args); 


Void _configure(IALG_Handle algHandle, IRES_HDVICP2_Obj * hdvicpHandle,
        IRES_HDVICP2_CallbackFxn cbFunctionPtr, Void * cbArgs)
{
}


Void _wait(IALG_Handle algHandle, IRES_HDVICP2_Obj * hdvicpHandle, 
        IRES_YieldContext * yieldCtxt)
{

    IRES_YieldArgs yieldArgs;
    yieldArgs = ti_sdo_fc_ires_hdvicp_HDVICP2_getYieldArgs(
            ((IRES_HDVICP2_IntObj *)hdvicpHandle)->scratchGroup);
    ti_sdo_fc_ires_hdvicp_HDVICP2_yieldRelease(IRES_ALL, yieldCtxt, yieldArgs);
    
    /* Should yield scratch group lock !!*/
     Task_sleep(SLEEPTIME);

    ti_sdo_fc_ires_hdvicp_HDVICP2_yieldAcquire(IRES_ALL, yieldCtxt, yieldArgs);
}


Void _done(IALG_Handle algHandle, IRES_HDVICP2_Obj * hdvicpHandle)
{
}
/*
 *  @(#) ti.sdo.fc.rman.examples.plugin; 1, 0, 0,4; 2-22-2012 18:08:06; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

