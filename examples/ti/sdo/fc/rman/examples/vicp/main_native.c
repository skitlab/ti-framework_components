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


extern Int smain(UArg arg0, UArg arg1);


/*
 *  ======== main ========
 */
/* ARGSUSED */
int main(Int argc, Char * argv[])
//int main(UArg argc, UArg argv)
{
    IRES_Status status;
    Int         size = 0;

#if 0
        // TODO: Convert to Diags_setMask()
        GT_set(MODNAME "=01234567");
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

    Log_print0(Diags_EXIT, "[+X] main> Exit");

    smain(argc, argv);

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.vicp; 1, 0, 0,4; 2-22-2012 18:08:22; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

