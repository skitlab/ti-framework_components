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
 *  ======== main_native.c ========
 */


#include <xdc/std.h>
#include <xdc/runtime/Diags.h>

#include <ti/sdo/fc/rman/rman.h>

#include <ti/sdo/fc/global/FCSettings.h>

extern Void smain(Int argc, Char * argv[]);

/*
 *  ======== main ========
 */
/* ARGSUSED */
int main(Int argc, Char * argv[])
{

//    Diags_setMask("ti.sdo.fc.%+EX1234567");
//    Diags_setMask(RMAN_MODNAME"+EX1234567");
//    Diags_setMask("ti.sdo.fc.ires.%+EX1234567");

    FCSettings_init();
    Diags_setMask("ti.sdo.fc.global.FCSettings+EX1234567");

    _DSKT2_init();
    RMAN_init();

    /*
     *  Turn on logging for EDMA3. This call must be placed after EDMA3 is,
     *  initialized, which is done in RMAN_init().
     */
    //Diags_setMask("ti.sdo.fc.edma3+EX1234567");

    smain(argc, argv);

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.scratchEdma3; 1, 0, 0,4; 2-22-2012 18:08:03; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

