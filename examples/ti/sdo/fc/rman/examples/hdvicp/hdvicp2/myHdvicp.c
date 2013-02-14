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
#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

//If this implementation were part of IRES HDVICP2, we'd know this file
#include <ti/sdo/fc/ires/hdvicp/_hdvicp2.h> 


Void _configure(IALG_Handle algHandle, IRES_HDVICP2_Obj * hdvicpHandle,
        IRES_HDVICP2_CallbackFxn cbFunctionPtr, Void * cbArgs)
/* ARGSUSED */
{
}


Void _wait(IALG_Handle algHandle, IRES_HDVICP2_Obj * hdvicpHandle,
        IRES_YieldContext * yieldContext)
/* ARGSUSED */
{
    IRES_HDVICP2_IntObj * intObj = (IRES_HDVICP2_IntObj *)hdvicpHandle;
    IRES_YieldArgs yieldArgs;

    yieldArgs = DSKT2_getYieldArgs(intObj->scratchGroup);

    DSKT2_yield(IRES_ALL, yieldContext, (IRES_YieldArgs )yieldArgs);
}


Void _done(IALG_Handle algHandle, IRES_HDVICP2_Obj * hdvicpHandle)
/* ARGSUSED */
{
}
/*
 *  @(#) ti.sdo.fc.rman.examples.hdvicp.hdvicp2; 1, 0, 0,4; 2-22-2012 18:07:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

