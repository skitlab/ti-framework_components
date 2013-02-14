/* 
 * Copyright (c) 2011, Texas Instruments Incorporated
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
 *
 */
#ifndef SystemCfg__include
#define SystemCfg__include


#if defined (__cplusplus)
extern "C" {
#endif

/*
 *  ======== Application Configuration ========
 */

/* NB: string max length = 16, (ti.ipc.NameServer_Params_MAXNAMELEN) */
#define SystemCfg_RcmMsgHeapName_CompDev        "MsgHeapCompDev"
#define SystemCfg_RcmMsgHeapId_CompDev          0
#define SystemCfg_OpenCLHeapName_CompDev        "OCLHeapCompDev"
#define SystemCfg_RcmServer_CompDev             "RcmSrvCompDev"

/* device specific configuration */
#define SystemCfg_Host_ProcName                 "DSP"
#define SystemCfg_ComputeDevice_ProcName        "EVE"

/*
 *  Runtime config settings for OpenCL
 *  rcmServerHeapId = SystemCfg_RcmMsgHeapId_CompDev
 *  rcmMsgDataSize = heap.blockSize - (MessageQ_Header + RcmClient_Header)
 */
#define SystemCfg_PROG_CONFIG \
    "rcmServerName="SystemCfg_RcmServer_CompDev";" \
    "rcmServerHeapId=0;" \
    "rcmMsgDataSize=76"


/*
 *  ======== SystemCfg ========
 */

/* constants and types */
#define SystemCfg_S_SUCCESS             (0)
#define SystemCfg_E_FAIL                (-1)
#define SystemCfg_E_NOMEMORY            (-2)

/* SystemCfg configuration */
#define SystemCfg_HostDspEvtNum         7
#define SystemCfg_NotifyLineId          0

/* event payload */
#define SystemCfg_EvtCreateDone         0x00000001
#define SystemCfg_EvtReady              0x00000002
#define SystemCfg_EvtCloseDone          0x00000004
#define SystemCfg_EvtShutdown           0x00000008
#define SystemCfg_EvtDone               0x00000010
#define SystemCfg_EvtStartup            0x00000020

typedef Int (*SystemCfgFxn)(Ptr);

typedef struct {
    String      remoteProcName;
} SystemCfg_Params;

typedef struct SystemCfg_Object_tag *SystemCfg_Handle;


/* module-wide functions */
Void SystemCfg_init(Void);
Void SystemCfg_exit(Void);
Void SystemCfg_Params_init(SystemCfg_Params *params);

/* per-instance functions */
Int SystemCfg_create(const SystemCfg_Params *p, SystemCfg_Handle *hp);
Int SystemCfg_delete(SystemCfg_Handle *hp);

Int SystemCfg_start(SystemCfg_Handle handle, String filePath);
Int SystemCfg_startAck(SystemCfg_Handle handle);
Void SystemCfg_stop(SystemCfg_Handle handle);

Int SystemCfg_attach(SystemCfg_Handle handle);
Int SystemCfg_detach(SystemCfg_Handle handle);

Int SystemCfg_createResources(SystemCfg_Handle handle);
Int SystemCfg_deleteResources(SystemCfg_Handle handle);
Int SystemCfg_openResources(SystemCfg_Handle handle);
Int SystemCfg_closeResources(SystemCfg_Handle handle);

Int SystemCfg_handshakeEvent(SystemCfg_Handle handle, UInt32 event);
Int SystemCfg_sendEvent(SystemCfg_Handle handle, UInt32 event);
Void SystemCfg_waitForEvent(SystemCfg_Handle handle, UInt32 event);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* SystemCfg__include */
/*
 *  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,1; 1-26-2011 22:23:33; /db/atree/library/trees/fc/fc.git/src/ fc-o11
 */

