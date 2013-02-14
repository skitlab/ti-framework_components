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
 *  ======== Global.h ========
 *
 */
#ifndef Global__include
#define Global__include

#if defined (__cplusplus)
extern "C" {
#endif

/* shared configuration */
#define Global_RcmServerName            "Slave:RcmServer"
#define Global_RcmClientHeapId          0
#define Global_RcmClientHeapName        "RcmClientHeap"

/* SystemCfg configuration */
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

/* device specific configuration */
#if defined (__OMAP3530__)
#define Global_HostProcName             "HOST"

#elif defined (__TMS320TI816X__)
#define Global_HostProcName             "HOST"

#elif defined (__TMS320C6472__)
#define Global_HostProcName             "CORE0"
#endif


#if defined (__cplusplus)
}

#endif /* defined (__cplusplus) */
#endif /* Global__include */
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.server; 1,0,0,4; 2-22-2012 18:10:25; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

