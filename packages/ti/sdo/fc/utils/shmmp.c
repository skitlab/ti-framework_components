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
 *  ======== shmmp.c ========
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

#include <ti/sdo/fc/global/FCSettings.h>

#include <string.h>
#include <sys/shm.h>
#include <xdc/runtime/knl/GateProcess.h>

#include "shm.h"


/* Align on 4-byte boundary */
#define ALIGN32(x) (Void *)((((UInt32)(x) + 3) / 4) * 4)


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
    Int         refCount;
    struct shmid_ds    desc;
    Bool status = TRUE;
    //IArg key;

    Log_print2(Diags_ENTRY, "[+E] SHM_freeObj> Entered shmBase = 0x%x, "
            "shmId = 0x%x", (IArg)shmBase, (IArg)shmId);
    /*
     *  Don't move this block of code. Cannot detach shmBase until
     *  _Shared Memory_refCount is checked.
     */
    /* Detach the shared memory, but don't free it. */
    if (shmdt(shmBase) == -1) {
        /* error */
        Log_print2(Diags_USER7,
                "[+7] Failed to detach shared memory [0x%x], shmId = 0x%x",
                (IArg)shmBase, (IArg)shmId);
        status = FALSE;
    }

    shmctl(shmId, IPC_STAT, &desc);

    refCount = desc.shm_nattch;

    if (refCount == 0) {
        if (shmctl(shmId, IPC_RMID, 0) == -1) {
        /* error */
            Log_print2(Diags_USER7,
                    "[+7] Failed to free shared memory [0x%x], shmId = 0x%x",
                    (IArg)shmBase, (IArg)shmId);

            status = FALSE;
        }
    }

    Log_print1(Diags_EXIT, "[+X] SHM_freeObj> Leaving, status = %d",
            (IArg)status);

    return (status);
}

/*
 *  ======== SHM_getObj ========
 */
Void * SHM_getObj(IGateProvider_Handle gate, unsigned int shmSize, 
        unsigned int keyt, SHM_InitFxn fxn, Int *shmId)
{
    Bool            shmExists = TRUE;
    Int             gateRefCount;
    Void          * shmBase = NULL;
    Error_Block     eb;


    Log_print5(Diags_ENTRY, "[+E] SHM_getObj> Entered (0x%x, 0x%x, 0x%x, "
            "0x%x, 0x%x)", (IArg)gate, (IArg)shmSize, (IArg)keyt,
            (IArg)fxn, (IArg)shmId);

    /*
     *  Allocate or locate the chunk of shared memory where internal
     *  Shared Memory objects will be placed. This is to ensure that multiple
     *  processes will see the same Shared Memory objects.
     *  First attempt to get the shared memory without the IPC_CREAT
     *  flag, to see if it's already been created.
     */

    Assert_isTrue((GateProcess_Handle_downCast(gate) != NULL),(Assert_Id)NULL);

    /* Create the shared memory if it doesn't exist yet */
    *shmId = shmget((key_t)(keyt), shmSize, 0666);

    if (*shmId == -1) {
        /*
         *  Failed to get the shared memory, so it probably hasn't been
         *  created yet.
         */
        *shmId = shmget((key_t)keyt, shmSize, 0666 | IPC_CREAT);

        if (*shmId == -1) {
            /* Couldn't create the shared memory */
            Log_print1(Diags_USER7,
                    "[+7] SHM_getObj> Failed to create shared memory "
                    "region, key = 0x%x", (IArg)shmId);

            /* Abort*/
            Assert_isTrue(*shmId != -1, (Assert_Id)NULL);

            return (FALSE);
        }
        else {
            /* The segment had not been created before */
            Log_print1(Diags_ENTRY, "[+E] SHM_getObj> Created shared memory, "
                    "key = 0x%x", (IArg)(*shmId));

            shmExists = FALSE;
        }
    }
    else {
        Log_print1(Diags_ENTRY,
                "[+E] SHM_getObj> Shared memory, key = 0x%x already exists",
                (IArg)(*shmId));
    }

    /* Get the address of the shared memory region with shmat() */
    shmBase = shmat(*shmId, NULL, 0);

    if (shmBase == (void *)-1) {

        Log_print1(Diags_USER7, "[+7] SHM_getObj> Failed to get shared memory "
                "address, key = 0x%x", (IArg)(*shmId));
        shmBase = (unsigned int)NULL;

        /* Abort */
        Assert_isTrue(shmBase != NULL, (Assert_Id)NULL);

        return (NULL);
    }

    shmBase = ALIGN32(shmBase);

    if (shmExists) {
        /*
         *  Shared memory segment already exists. Check the Shared Memory lock
         *  reference count. Since the lock is created only once per
         *  process, if the lock reference count is 1, the calling process
         *  is the only one using Shared Memory global data. In that case, a
         *  process must have died, and we will re-initialize the Shared Memory
         *  global data.
         */
        Error_init(&eb);
        gateRefCount = GateProcess_getReferenceCount(
                GateProcess_Handle_downCast(gate), &eb);

        if (Error_check(&eb)) {

            Log_print0(Diags_USER7, "[+7] GateProcess_getReferenceCount: "
                    "an error occurred");

            SHM_freeObj(shmBase, *shmId);

            *shmId = -1;

            return (NULL); 
        }

        Log_print1(Diags_ENTRY,
                "[+E] SHM_getObj> "
                "Shared Memory lock reference count = %d", (IArg)gateRefCount);

        if (gateRefCount == 1) {
            Log_print0(Diags_USER5,
                    "[+5] SHM_getObj> Warning: Shared Memory lock "
                    "reference count indicates no other processes are \n"
                    "currently using Shared Memory shared memory.\n"
                    "Re-initializing Shared Memory shared memory");

            /* This will cause the Shared Memory data to be re-initialized */
            shmExists = FALSE;
        }
    }

    if (!shmExists) {

        /* Initialize the reference count in the shared data area */
        Log_print0(Diags_ENTRY, "[+E] Initializing Shared Memory region");

        /* Initialize the _Shared Memory_data object to 0's */
        memset((Void *)shmBase, 0, shmSize);

        if (fxn) {
            fxn(shmBase);
        }
    }

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

