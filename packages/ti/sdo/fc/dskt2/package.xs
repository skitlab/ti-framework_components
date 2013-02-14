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

function su(segName) { /* "strip underscore" */
        return (segName.charAt(0) == "_") ? segName.substr( 1 ) : segName;
}


/*
 *  ======== getLibs ========
 */
function getLibs(prog)
{
    var suffix = Program.build.target.findSuffix(this);

    if (null == suffix) {
        return (null);
    }

    if (this.DSKT2.disableLazyDeactivate) {
        var libs = "dskt2_lazydDisable";
    }
    else {
        var libs = "dskt2";
    }


    libs += ".a" + suffix;

    var dir = "lib/" + this.profile;

    if (!java.io.File(this.packageBase + dir + "/" + libs ).exists()) {
        print(this.$name + ": Requested profile '" + this.profile + "' does "
                + "not exist.\n\tDefaulting to the 'release' profile");

       dir = "lib/release";

    }

    return (dir + "/" + libs);
}


/*
 *  ======== getSects ========
 */
function getSects() {
   return (null);
}


/*
 * ======== close ========
 */
function close()
{
    var DSKT2 = this.DSKT2;
    var os = Program.build.target.os;

    //print(this.$name + ".close(): DSKT2 gate: " +DSKT2CFG.common$.gate);

    Program.exportModule('xdc.runtime.Log');
    Program.exportModule('xdc.runtime.Assert');
    Program.exportModule('xdc.runtime.Diags');
    var Diags = xdc.useModule('xdc.runtime.Diags');
    Program.exportModule('xdc.runtime.Registry');

    // This will be used to create semaphores (either MP or non-MP)
    // By going through this interface, we don't have to have separate calls
    // in code for MP semaphores and non-MP semaphores.
    xdc.loadPackage('ti.sdo.fc.utils.osalsupport');
    //xdc.useModule('ti.sdo.fc.utils.osal.OsalFactory');

    Program.exportModule('xdc.runtime.Error');
    //Program.exportModule('ti.sdo.fc.utils.osal.OsalFactory');

    // If using DSKT2_cacheWBInv, we need to use the BIOS 6 Cache module
    // so that the function that Cache_wbInv gets #define'd to will be
    // linked in.
    if (os == undefined) {

        /* Assume BIOS */
        if (DSKT2.cacheWritebackInvalidateFxn == "DSKT2_cacheWBInv") {
            //print(this.$name + ".close(): Using BIOS 6 Cache module *****");

            /* Use the Cache module */
            Program.exportModule('ti.sysbios.hal.Cache');
        }
    }
    else {
        /* If it isn't BIOS, don't use the DSKT2_cacheWBInv function */
        if (DSKT2.cacheWritebackInvalidateFxn == "DSKT2_cacheWBInv") {
            DSKT2.cacheWritebackInvalidateFxn == null;
        }
    }

    xdc.loadPackage("ti.xdais");

    var fcSettings = xdc.useModule('ti.sdo.fc.global.Settings');

    if (this.profile == undefined) {
        this.profile = fcSettings.profile;
    }

    if (DSKT2.disableLazyDeactivate == undefined) {
        DSKT2.disableLazyDeactivate = false;
    }
}
/*
 *  @(#) ti.sdo.fc.dskt2; 1, 0, 4,4; 2-22-2012 18:03:58; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

