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
 *  ======== GT_config_BIOS.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Swi.h>


#include "Trace.h"
#include <ti/sdo/utils/trace/CBuf.h>

Void   error(String msg, ...);
Void   printfCaller(String format, ...);
Ptr    myMalloc(Int size);
Void   myFree(Ptr addr, Int size);
Int    myGetTaskId(Void);
Void   myLock(Void);
Void   myUnlock(Void);
Void   myInit(Void);

/* trace buffer and its size, defined in Global.xdt */
extern Char Gtinfra_traceBuffer[];
extern Int  Gtinfra_traceBufferSize;

/* default memory segment for allocs, defined in Global.xdt */
//extern Int Memory_SEGID;

static Bool        initFlag = FALSE;
static SemThread_Handle  mutex    = NULL;
static CBuf_Handle traceBuf = NULL;

/*
 *  ======== myInit ========
 */
Void myInit(Void)
{
    SemThread_Params params;

    if (initFlag != TRUE) {

        initFlag = TRUE;

        Trace_init();
        traceBuf = CBuf_create( Gtinfra_traceBuffer,
                                Gtinfra_traceBufferSize, NULL );
        Trace_bind(traceBuf);

        SemThread_Params_init(&params);

        mutex = SemThread_create(1, &params, NULL);
        if (mutex == NULL) {
            /* clean up the lock, unlock entries in the vtable */
        }
    }
}


/*
 *  ======== printfCaller ========
 */
Void printfCaller(String format, ...)
{
    va_list va;

    va_start(va, format);

    System_vprintf(format, va);

    va_end(va);
}

/*
 *  ======== myGetTaskId ========
 */
Int myGetTaskId(Void)
{
    BIOS_ThreadType threadType;
    Int             id;

    threadType = BIOS_getThreadType();

    switch (threadType) {
        case BIOS_ThreadType_Task:
            id = (Int)Task_self();
            break;

        case BIOS_ThreadType_Swi:
            id = (Int)Swi_self();
            break;

        case BIOS_ThreadType_Hwi:
        case BIOS_ThreadType_Main:
        default:
            id = 0;
            break;
    }

    return (id);
}

/*
 * ======== error ========
 *  purpose:
 *      Prints error onto the standard output.
 */
void error(String fmt, ...)
{
    va_list va;

    System_printf("ASSERTION ERROR: ");

    va_start(va, fmt);

    System_vprintf(fmt, va);

    va_end(va);
}

/*
 *  ======== myMalloc ========
 */
Ptr myMalloc(Int size)
{
    return (Memory_calloc(Memory_defaultHeapInstance, size, 0, NULL));
}


/*
 *  ======== myFree ========
 */
Void myFree(Ptr addr, Int size)
{
    Memory_free(Memory_defaultHeapInstance, addr, size);
}

/*
 *  ======== myLock ========
 */
Void myLock(Void)
{
    SemThread_pend(mutex, SemThread_FOREVER, NULL);
}


/*
 *  ======== myUnlock ========
 */
Void myUnlock(Void)
{
    SemThread_post(mutex, NULL);
}
/*
 *  @(#) ti.sdo.fc.utils.gtinfra; 1, 0, 0,4; 2-22-2012 18:08:51; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

