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
 *  ======== Common.cfg.xs ========
 *
 */
var Program = xdc.useModule('xdc.cfg.Program');
var cfgArgs = Program.build.cfgArgs;


/*
 *  ======== IPC Configuration ========
 */
xdc.useModule('ti.sdo.ipc.heaps.HeapBufMP');

/* configure processor names */
var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
var procNameAry = MultiProc.getDeviceProcNames();
MultiProc.setConfig(cfgArgs.procName, procNameAry);

/* define host processor */
var Ipc = xdc.useModule('ti.sdo.ipc.Ipc');
Ipc.hostProcId = MultiProc.getIdMeta(cfgArgs.hostProcName);

/* plug the ipc attach and detach hook functions */
var userFxn = new Ipc.UserFxn;
userFxn.attach = '&SystemCfg_attachHook';
userFxn.detach = '&SystemCfg_detachHook';
Ipc.addUserFxn(userFxn, null);

/* shared region configuration */
var SharedRegion  = xdc.useModule('ti.sdo.ipc.SharedRegion');

/* configure the SharedRegion_0 (IPC) */
var sr0 = Program.cpu.memoryMap["SR0"];

SharedRegion.setEntryMeta(0,
    new SharedRegion.Entry({
        name:           "IPC_shared_memory",
        base:           sr0.base,
        len:            sr0.len,
        ownerProcId:    MultiProc.getIdMeta("DSP"),
        cacheEnable:    false,
        isValid:        true
        /* SR#0 always has a heap, no need to set it */
    })
);

/* configure SharedRegion_1 (data buffers) */
var sr1 = Program.cpu.memoryMap["SR1"];

SharedRegion.setEntryMeta(1,
    new SharedRegion.Entry({
        name:           "Shared_Data_Buffers",
        base:           sr1.base,
        len:            sr1.len,
        ownerProcId:    MultiProc.getIdMeta("DSP"),
        cacheEnable:    false,
        createHeap:     false,  /* don't want a heap here */
        isValid:        true,
    })
);

/* reduce data memory usage */
var GateMP = xdc.useModule('ti.sdo.ipc.GateMP');
GateMP.RemoteCustom1Proxy = xdc.useModule('ti.sdo.ipc.gates.GateMPSupportNull');

/* use new smaller notify circ driver */
var Notify = xdc.useModule('ti.sdo.ipc.Notify');
Notify.numEvents = 8;
Notify.SetupProxy = xdc.useModule('ti.sdo.ipc.family.arctic.NotifyCircSetup');

/* reduce circular buffer size to 16 (one cache line) to save space */
var NotifyDriverCirc =
    xdc.useModule('ti.sdo.ipc.notifyDrivers.NotifyDriverCirc');
NotifyDriverCirc.numMsgs = 16;

var MessageQ = xdc.useModule('ti.sdo.ipc.MessageQ');
MessageQ.SetupTransportProxy =
    xdc.useModule('ti.sdo.ipc.transports.TransportShmNotifySetup');
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

