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

var UTILS = xdc.loadCapsule("ti/sdo/fc/utils/utils.xs")

/*
 *  ======== getLibs ========
 */
function getLibs(prog)
{
    var suffix;
    var libName;
    var profile;
    var isa = prog.build.target.isa;
    var dir = "lib/" + this.profile;

    if ("findSuffix" in prog.build.target) {
        suffix = prog.build.target.findSuffix(this);
        if (suffix == null) {
            print(this.$name + ".getLibs(): Can't find suffix for " +
                  prog.build.target.name + " target.");
            return ("");
        }
//        print(this.$name + ".getLibs(): suffix for " + prog.build.target.name +
//              ": " + suffix);
    }
    else {
        suffix = prog.build.target.suffix;
    }


    libName = "acpy3.a";

    // PC can only use CPU copy library
    if (isa.match(/i686/) != null) {
        libName = "acpy3cpu.a";
    }
    else {
        /* For the rest of the targets check for instrumented/cpu specific
           config */
        if (this.ACPY3.cpu) {
            libName = "acpy3cpu.a";
        }
    }

    libs =  libName + suffix;

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
 *  ======== close ========
 */
function close() {

    if (xdc.om.$name != "cfg") {
        return;
    }

    if ((this.ACPY3.nullPaRam == undefined) ||
            (this.ACPY3.edma3BaseAddress == undefined)) {

        if (UTILS.usingPackage("ti.sdo.fc.dman3")) {
//            xdc.useModule("ti.sdo.fc.dman3.DMAN3");
        }
        else {
/*
            For this to work, CE/xDAIS have to be modified to do a usingPackage
            check instead of a useModule of ACPY3 in their builds. Till then
            keeping this commented.
            throw("\n\nACPY3 error: Have not configured ACPY3 module, "
            + "and also not using DMAN3 in the application. Need to either "
            + configure the ACPY3 modules "
            + \"nullPaRam\" and \"edma3BaseAddress\", or " +
            "use DMAN3 to obtain resources.");
*/
        }
        this.ACPY3.edma3BaseAddress = -1;
        this.ACPY3.paRamBaseAddress = -1;
        this.ACPY3.nullPaRam = -1;
    }

    if (this.profile == undefined) {
        this.profile = xdc.useModule('ti.sdo.fc.global.Settings').profile;
    }

    xdc.useModule("ti.sdo.fc.memutils.MEMUTILS");
    xdc.loadPackage("ti.sdo.fc.utils.osalsupport");
    xdc.loadPackage("ti.sdo.fc.utils");
    xdc.loadPackage("ti.xdais");
}

/* TODO: Check if DSKT2 is being used, and if so, check DMAN3's
         ALLOW_EXTERNAL_SCRATCH configuration, confirm it is set to false */
function validate() {
}
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

