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
 *  ======== OsalFactory.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Error.h>

#include <xdc/runtime/knl/SemThread.h>
#include <xdc/runtime/knl/SemProcess.h>
#include <xdc/runtime/knl/ISemaphore.h>

#include "package/internal/OsalFactory.xdc.h"

#define CREATE_FAILURE 1

extern Bool ti_sdo_fc_multiProcess;

/*
 *  ======== OsalFactory_createSem ========
 */
ISemaphore_Handle OsalFactory_createSem(Int count, Int key, Error_Block *eb)
{
    SemThread_Handle    sem;
    SemProcess_Handle   semMP;
    SemThread_Params    semParams;
    SemProcess_Params   semMPParams;
    ISemaphore_Handle   h = NULL;

    if (ti_sdo_fc_multiProcess) {
        SemProcess_Params_init(&semMPParams);
        semMP = SemProcess_create(count, key, &semMPParams, eb);

        if (!Error_check(eb)) {
            h = SemProcess_Handle_upCast(semMP);
        }
        else {
            Error_print(eb);
        }
    }
    else {
        SemThread_Params_init(&semParams);
        sem = SemThread_create(count, &semParams, eb);

        if (!Error_check(eb)) {
            h = SemThread_Handle_upCast(sem);
        }
        else {
            Error_print(eb);
        }
    }

    return (h);
}

/*
 *  ======== OsalFactory_deleteSem ========
 */
Void OsalFactory_deleteSem(ISemaphore_Handle h)
{
    SemThread_Handle  sem;
    SemProcess_Handle semMP;

    if (ti_sdo_fc_multiProcess) {
        semMP = SemProcess_Handle_downCast(h);
        SemProcess_delete(&semMP);
    }
    else {
        sem = SemThread_Handle_downCast(h);
        SemThread_delete(&sem);
    }
}
/*
 *  @(#) ti.sdo.fc.utils.osal; 1, 0, 0,4; 2-22-2012 18:08:51; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

