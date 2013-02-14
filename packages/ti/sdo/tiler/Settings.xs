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
 *  ======== Settings.xs ========
 *
 */


/*
 *  ======== module$use ========
 */
function module$use()
{
    if (this.tilerLib == this.TilerLib_Stub) {
        xdc.useModule('ti.sdo.rcm.RcmClient');
        xdc.useModule('ti.sdo.rcm.Settings');
    }

    if (this.tilerLib == this.TilerLib_Skel) {
        xdc.useModule('ti.sdo.rcm.RcmServer');
        xdc.useModule('ti.sdo.rcm.Settings');
    }

    /* set heapId when running locally */
    if (this.tilerLib != this.TilerLib_Stub) {
        this.heapId = 0xFFFF;
    }
}


/*
 *  ======== module$validate ========
 *  Validate the module's state
 */
function module$validate()
{

    /* tilerLib must be set */
    if (this.tilerLib == undefined) {
        throw new Error("Settings.tilerLib is undefined."
        + " You must specify this config param.");
    }

    /* validate tiler stub config params */
    if (this.tilerLib == this.TilerLib_Stub) {
        if (this.tilerDaemonName == null) {
            throw new Error("Settings.tilerDaemonName is undefined."
            + " You must specify the remote tiler manager name when"
            + " using Settings.tilerLib = TilerLib_Stub.");
        }
        if (this.tilerManagerOS != undefined) {
            throw new Error("Cannot specify Settings.tilerManagerOS"
            + " when using Settings.tilerLib = TilerLib_Stub. Please"
            + " leave Settings.tilerManagerOS undefined.");
        }
        if (this.heapId == undefined) {
            throw new Error("Settings.heapId is undefined. You must"
            + " specify a heapId when using a remote tiler manager.");
        }
    }

    /* validate tiler skel config params */
    if (this.tilerLib == this.TilerLib_Skel) {
        if (this.tilerManagerOS == undefined) {
            throw new Error("Settings.tilerManagerOS is undefined."
            + " You must specify the operating system type when using"
            + " Settings.tilerLib = TilerLib_Skel. Please assign"
            + " Settings.tilerManagerOS a value.");
        }
    }

    /* validate tiler direct config params */
    if (this.tilerLib == this.TilerLib_Direct) {
        if (this.tilerManagerOS == undefined) {
            throw new Error("Settings.tilerManagerOS is undefined."
            + " You must specify the operating system type when using"
            + " Settings.tilerLib = TilerLib_Direct. Please assign"
            + " Settings.tilerManagerOS a value.");
        }
    }
}
/*
 *  @(#) ti.sdo.tiler; 1, 0, 0,4; 2-22-2012 18:10:47; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

