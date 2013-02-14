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
 *  This define is for Logging and must precede the inclusion of any xdc
 *  header files
 */
#define Registry_CURDESC ti_sdo_fc_utils_shm_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/knl/GateProcess.h>

#include <ti/sdo/fc/global/FCSettings.h>

#include <string.h>
#include <stdlib.h>

#include "shm.h"


Registry_Desc ti_sdo_fc_utils_shm_desc;

static Int refCount  = 0;


/*
 *  ======== SHM_exit ========
 */
Void SHM_exit(Void)
{
    if (--refCount == 0) {
    }
}

/*
 *  ======== Shm_freeObj ========
 */
Bool SHM_freeObj(Void * shmBase, Int shmId)
{
    free((void *)shmId);

    return (TRUE);
}

/*
 *  ======== SHM_getObj ========
 */
Void * SHM_getObj(IGateProvider_Handle gate, unsigned int shmSize, 
        unsigned int keyt, SHM_InitFxn fxn, Int *shmId)
{
    Void  * shmBase = NULL;

    Log_print5(Diags_ENTRY, "[+E] SHM_getObj> Entered (0x%x, 0x%x, 0x%x, "
            "0x%x, 0x%x)", (IArg)gate, (IArg)shmSize, (IArg)keyt,
            (IArg)fxn, (IArg)shmId);

    /* Create the shared memory if it doesn't exist yet */
    shmBase = malloc(shmSize);

    if (NULL == shmBase) {
        *shmId = -1;
        return (NULL);
    }

    /* Initialize the _Shared Memory_data object to 0's */
    memset((Void *)shmBase, 0, shmSize);

    if (fxn) {
        fxn(shmBase);
    }

    *shmId = (Int)shmBase;

    Log_print1(Diags_EXIT, "[+X] SHM_getObj> Exit (shmbase = 0x%lx)",
            (IArg)shmBase);
    return (shmBase);
}

/*
 *  ======== SHM_init ========
 */
Void SHM_init(Void)
{
    Registry_Result result;

    if (refCount++ == 0) {
        FCSettings_init();

        result = Registry_addModule(&ti_sdo_fc_utils_shm_desc, SHM_MODNAME);
        Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

        if (result == Registry_SUCCESS) {
            /* Set the diags mask to the FC default */
            FCSettings_setDiags(SHM_MODNAME);
        }
    }
}
/*
 *  @(#) ti.sdo.fc.utils; 1, 0, 3,4; 2-22-2012 18:08:42; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

