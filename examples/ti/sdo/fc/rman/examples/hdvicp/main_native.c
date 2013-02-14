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
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>


#include <ti/xdais/ires.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/ires/hdvicp/iresman_hdvicp.h>
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp.h>



extern Int rmanTask(Int argc, Char * argv[]);

IRESMAN_HdVicpParams configParams = {
    {0,      /* Size of this structure */
            /*
             * RMAN_PERSISTENTALLOCFXN,
             * RMAN_PERSISTENTFREEFXN,
             */
    NULL,
    NULL},
    2,      /* Number of resources to manage */
    NULL,   /* Rsvd for future use */
};


/*
 *  ======== main ========
 */
/* ARGSUSED */
int main(Int argc, Char * argv[])
{
    IRES_Status status;
    Int         size = 0;

#if 0
    // TODO: Convert to Diags_setMask()
        GT_set("ti.sdo.fc.rman" "=4567");
        GT_set("ti.sdo.fc.dskt2" "=67");
        GT_set("ti.sdo.fc.ires.hdvicp" "=01234567");
/*      GT_set("ti.sdo.fc.dskt2" "=01234567");*/
#endif
    Log_print0(Diags_ENTRY, "[+E] _main> Enter ");

    status = RMAN_init();
    if (IRES_OK != status) {
        Log_print1(Diags_USER7, "[+7] main> RMAN_init() failed [%d]",
                (IArg)status);
        return (-1);
    }

    /*
     * Supply initialization information for the RESMAN while registering
     */
    size = sizeof(IRESMAN_HdVicpParams);

    configParams.baseConfig.allocFxn = RMAN_PARAMS.allocFxn;
    configParams.baseConfig.freeFxn = RMAN_PARAMS.freeFxn;
    configParams.baseConfig.size = size;

    /* Register the HDVICP protocol/resource manager with the
     * generic resource manager */

    status = RMAN_register(&IRESMAN_HDVICP, (IRESMAN_Params *)&configParams);

    if (IRES_OK != status) {
        Log_print1(Diags_USER7, "[+7] main> RMAN_register() failed [%d]",
                (IArg)status);
        return (-1);
    }

    Log_print0(Diags_EXIT, "[+X] main> Exit");

    return (rmanTask(argc, argv));
}
/*
 *  @(#) ti.sdo.fc.rman.examples.hdvicp; 1, 0, 0,4; 2-22-2012 18:07:40; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

