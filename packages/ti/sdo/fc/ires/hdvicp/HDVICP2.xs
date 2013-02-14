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
 *  ======== HDVICP2CFG.xs ========
 */

var HDVICP2 = null;

function module$use()
{

    HDVICP2 = this;
    var os = Program.build.target.os;
    var fcSettings = xdc.useModule('ti.sdo.fc.global.Settings');

    //print(this.$name + ".module$use(): Hello!");
    xdc.useModule('xdc.runtime.Log');
    xdc.useModule('xdc.runtime.Assert');
    var Diags = xdc.useModule('xdc.runtime.Diags');

    var Sem = xdc.useModule("xdc.runtime.knl.Semaphore");
    //xdc.useModule("xdc.runtime.knl.ISemaphore");

    if (os == undefined) {

        //print(this.$name + ".module$use(): os undefined");
        /* Assume bios (6) */
        /* Create the HWI function, SWI function and Semaphores */ 
        
        var device = Program.cpu.deviceName;
        var Hwi = xdc.useModule('ti.sysbios.hal.Hwi');
        var hwiParams = new Hwi.Params;
        var Swi = xdc.useModule('ti.sysbios.knl.Swi');
        var swiParams = new Swi.Params; 

        var Semthread = xdc.useModule("xdc.runtime.knl.SemThread");
        var Sembios6 = xdc.useModule("ti.sysbios.xdcruntime.SemThreadSupport"); 
        
        Sem.Proxy = Semthread; 
        Semthread.Proxy = Sembios6; 

        var semParams = new Sembios6.Params; 

        var ivahdPeriph = xdc.useModule("ti.catalog.peripherals.hdvicp2.HDVICP2");
        var ivahds = ivahdPeriph.getAll(); 
        var numHdvicp = ivahds.length;
        var intArray = new Array();

        if (numHdvicp == 0) {
            throw("Platform " + Program.platformName + " device " + device + 
                    " doesn't have recognized support for HDVICP2."); 
        }

        for (var i = 0; i < ivahds.length; i++) {
            intArray[i] = ivahds[i].$orig.intNum;
            hwiParams.arg = i;
            Program.global["ti_sdo_fc_ires_hdvicp_HDVICP2_hwi" + i] = 
                    Hwi.create(intArray[i], 
                    '&ti_sdo_fc_ires_hdvicp_HDVICP2_hwiFunc', hwiParams);
            swiParams.arg0 = i; 
            Program.global["ti_sdo_fc_ires_hdvicp_HDVICP2_swi" + i] = 
                    Swi.create('&ti_sdo_fc_ires_hdvicp_HDVICP2_swiFunc', 
                    swiParams);
            var sem = Semthread.create(0, semParams);
            Program.global["ti_sdo_fc_ires_hdvicp_HDVICP2_sem" + i] = sem;
        }
    
    }
    else {
        print(this.$name + ".module$use(): os is " + os + " doing nothing!!");
    }

}
/*
 *  @(#) ti.sdo.fc.ires.hdvicp; 1, 0, 1,4; 2-22-2012 18:06:22; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

