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
 *  ======== dskt2_lock.c ========
 *  Implements the locks and contexts save/restore functions for DSKT2
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_dskt2_desc

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Registry.h>

#include <xdc/runtime/knl/ISemaphore.h>
#include <ti/sdo/fc/utils/osalsupport/OsalSupport.h>

#include <ti/xdais/ires.h>

#include "_dskt2.h"
#include "dskt2_lock.h"


/*
 *  Create semaphores starting at ti_sdo_fc_dskt2_DSKT2_ipcKeyBase + 1, to
 *  allow DSKT2 lock to use ti_sdo_fc_dskt2_DSKT2_ipcKeyBase.
 */
static UInt32 keyBase;

/* Locks corresponding to each scratch group */
//static SemUtils_Handle _locks[DSKT2_NUM_SCRATCH_GROUPS];
static ISemaphore_Handle _locks[DSKT2_NUM_SCRATCH_GROUPS];

/*
 * Holds yielding contexts of all the scratch groups
 */
static IRES_YieldContextHandle
        _DSKT2_yieldingContext[DSKT2_NUM_SCRATCH_GROUPS];

extern Registry_Desc ti_sdo_fc_dskt2_desc;

/*
 *  ======== DSKT2_initLocks ========
 *  Implements yield function and initializes all the
 *  the lock semaphores, and yield contexts.
 */
Void DSKT2_initLocks()
{
    Int i;

    /*
     * Initialize the yielding context and lock create flags
     */
    for (i = 0; i < DSKT2_NUM_SCRATCH_GROUPS; i++) {
        _DSKT2_yieldingContext[i] = NULL;

        /*
         * Note, an optimization could be to allow this array to be
         * sparse, and only create enough semaphores for the groups that
         * will be used.  Might require some extra config on the user's part
         * but it would save on some resources in environments where sems,
         * and especially multi-process sems(!) are heavy.
         */
        keyBase = _DSKT2_ipcKeyBase + 1;

        _locks[i] = OsalSupport_createSem(1, (Int)keyBase + i);

        if (_locks[i] == NULL) {
            /* This is a fatal error */
            System_abort("DSKT2_initLocks(): Semaphore creation failed\n");
        }
    }
}

Void DSKT2_exitLocks()
{
    Int i;

    /*
     * Initialize the yielding context and lock create flags
     */
    for (i = 0; i < DSKT2_NUM_SCRATCH_GROUPS; i++) {
        _DSKT2_yieldingContext[i] = NULL;

        /*
         * Note, an optimization could be to allow this array to be
         * sparse, and only create enough semaphores for the groups that
         * will be used.  Might require some extra config on the user's part
         * but it would save on some resources in environments where sems,
         * and especially multi-process sems(!) are heavy.
         */
        OsalSupport_deleteSem(_locks[i]);

        _locks[i] = NULL;
    }
}
/*
 *  ======== DSKT2_acquireLock ========
 *  Acquires a semaphore lock for a particular scratch group
 */
Void DSKT2_acquireLock(Int scratchId)
{
    /*
     * Try and acquire it if it is a valid scratch Id
     */
    if ((scratchId >= 0) && (scratchId < DSKT2_NUM_SCRATCH_GROUPS)) {
        ISemaphore_pend(_locks[scratchId], /* ISemaphore_FOREVER */(UInt32)-1,
                NULL);
    }
}

/*
 *  ======== DSKT2_releaseLock ========
 *  Releases the semaphore lock on a particular scratch group.
 */
Void DSKT2_releaseLock(Int scratchId)
{
    /*
     * Release the lock
     */
    if ((scratchId >= 0) && (scratchId < DSKT2_NUM_SCRATCH_GROUPS)) {
        ISemaphore_post(_locks[scratchId], NULL);
    }
}

/*
 *  ======== DSKT2_getContext ========
 *  Obtains the (previously saved) context for a particular scratch group.
 */
IRES_YieldContextHandle DSKT2_getContext(Int scratchId)
{
    if ((scratchId >= 0) && (scratchId < DSKT2_NUM_SCRATCH_GROUPS)) {
        return (_DSKT2_yieldingContext[scratchId]);
    }
    else {
        return (NULL);
    }
}

/*
 *  ======== DSKT2_setContext ========
 *  Sets/saves the context for a particular scratch group.
 */
Void DSKT2_setContext(Int scratchId, IRES_YieldContextHandle context)
{
    if ((scratchId >= 0) && (scratchId < DSKT2_NUM_SCRATCH_GROUPS)) {
        _DSKT2_yieldingContext[scratchId] = context;
    }
}
/*
 *  @(#) ti.sdo.fc.dskt2; 1, 0, 4,4; 2-22-2012 18:03:55; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

