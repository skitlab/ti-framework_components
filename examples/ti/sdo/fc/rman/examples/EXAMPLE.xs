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
 *  ======== EXAMPLE.xs ========
 */

var EXAMPLE = null;

function module$use()
{
    EXAMPLE = this;
    var os = Program.build.target.os;
    var fcSettings = xdc.useModule('ti.sdo.fc.global.Settings');


    //print(this.$name + ".module$use(): Hello!");

    /*
     *  Set the default EXAMPLE gate if undefined. If null, xdc will plug
     *  in a default gate instance (GateNull) later.
     */
    if (EXAMPLE.gate === undefined) {
        //print(this.$name + ".module$use(): Setting EXAMPLE.gate...");

        var Gate;

        if (fcSettings.multiProcess) {

            // Use MP Gate
            if (os == "Linux") {
                //print("EXAMPLE Gate undefined. Setting to " +
                //        "ti.sdo.xdcruntime.linux.GateProcessSupport");
                Gate =
                    xdc.useModule('ti.sdo.xdcruntime.linux.GateProcessSupport');
            }
            else if (os == undefined) {

                // Don't really need MP gates for BIOS.
                //print("EXAMPLE Gate undefined. Setting to " +
                //        "ti.sysbios.xdcruntime.GateGateProcessSupport");
                Gate =
                    xdc.useModule('ti.sysbios.xdcruntime.GateProcessSupport');
            }
            else {
                //print(this.$name + "close(): WARNING. Could not find "
                //        + "suitable module to configure gate to. No "
                //        + "default was known for the target OS");
            }
        }
        else {

            // Don't need MP support.
            if (os == "Linux") {
                //print("EXAMPLE Gate undefined. Setting to " +
                //        "ti.sdo.xdcruntime.linux.Gate");
                Gate = xdc.useModule('ti.sdo.xdcruntime.linux.GateThreadSupport');
            }
            else if (os == undefined) {
                //print("EXAMPLE Gate undefined. Setting to " +
                //        "ti.sdo.osal.bios6.Gate");
                Gate = xdc.useModule('ti.sysbios.xdcruntime.GateThreadSupport');
            }
            else {
                //print(this.$name + "close(): WARNING. EXAMPLE Gate was "
                //        + "not configured and no "
                //        + "default was known for the target OS");
            }
        }

        // Create the gate instance
        if (fcSettings.multiProcess) {

            //print("EXAMPLE.gate undefined. Creating an MP gate with a key");
            EXAMPLE.gate = Gate.create({key: 0x11111111});
        }
        else {

            //print("EXAMPLE.gate undefined. Creating a gate");
            EXAMPLE.gate = Gate.create();
        }

        //print("EXAMPLE.gate set to " + EXAMPLE.gate);
    }
    else {

        // Gate was already set up
        //print(this.$name +
        //        ".module$use(): Thanks for setting EXAMPLE.gate!");
    }
}
/*
 *  @(#) ti.sdo.fc.rman.examples; 1, 0, 0,4; 2-22-2012 18:07:12; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

