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
 *  ======== SystemCfg.h ========
 *
 */
#ifndef SystemCfg__include
#define SystemCfg__include

#include <xdc/std.h>


#if defined (__cplusplus)
extern "C" {
#endif


/* application configuration */
#define Global_TilerDaemonName          "TilerMgr:HOST"
#define Global_TilerHeapId              0

/* notify configuration */
#define Global_HostDspEvtNum            15
#define Global_TimestampEvtNum          16
#define Global_NotifyLineId             0

/* event payload */
#define Global_EvtMask                  0xFF
#define Global_EvtCreateDone            0x61
#define Global_EvtReady                 0x62
#define Global_EvtCloseDone             0x63
#define Global_EvtShutdown              0x64
#define Global_EvtDone                  0x65
#define Global_EvtAlmostDone            0x66
#define Global_EvtTimestamp             0x67

#define Global_EvtAppReady              0x41
#define Global_EvtAppShutdown           0x42


typedef Int (*SystemCfg_AppFxn)(Ptr arg);


/* function prototypes */
Void SystemCfg_init(Void);
Void SystemCfg_exit(Void);

Int SystemCfg_start(String procName, String filePath);
Int SystemCfg_startAck(Void);
Int SystemCfg_stop(Void);

Int SystemCfg_createLocalResources(Void);
Int SystemCfg_deleteLocalResources(Void);

Int SystemCfg_openSharedResources(SystemCfg_AppFxn fxn, Ptr arg);
Int SystemCfg_closeSharedResources(SystemCfg_AppFxn fxn, Ptr arg);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* SystemCfg__include */
/*
 *  @(#) ti.sdo.tiler.examples.remote; 1, 0, 0,4; 2-22-2012 18:10:55; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

