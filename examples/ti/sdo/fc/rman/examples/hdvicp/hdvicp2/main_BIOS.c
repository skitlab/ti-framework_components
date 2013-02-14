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
 *  ======== main_BIOS.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <ti/sysbios/BIOS.h>

#include <ti/xdais/ires.h>

#include <ti/sdo/fc/rman/rman.h>
//#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/global/FCSettings.h>

/* IRES resources */
#include <ti/sdo/fc/ires/hdvicp/iresman_hdvicp.h>


/* #define MOD_NAME "ti.sdo.fc.rman"*/
#define MODNAME "*"


/*
 *  ======== main ========
 */
/* ARGSUSED */
int main(Int argc, Char * argv[])
{
    IRES_Status status;
    Int         size = 0;

    FCSettings_init();
    Diags_setMask(FCSETTINGS_MODNAME"+EX1234567");
    Diags_setMask("xdc.runtime.Main+EX1234567");
    Diags_setMask("ti.sdo.fc.%+EX1234567");

    Log_print0(Diags_ENTRY, "[+E] _main> Enter");

    status = RMAN_init();
    if (IRES_OK != status) {
        Log_print1(Diags_USER7, "[+7] main> RMAN_init() failed [%d]",
                (IArg)status);
        System_abort("RMAN_init() failed, aborting...\n");
    }

    Log_print0(Diags_EXIT, "[+X] main> Exit");

    BIOS_start();

    return(0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.hdvicp.hdvicp2; 1, 0, 0,4; 2-22-2012 18:07:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

