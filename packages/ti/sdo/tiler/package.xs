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
 *  ======== package.xs ========
 *
 */


/*
 *  ======== getLibs ========
 */
function getLibs(prog)
{
    var suffix;
    var file;
    var libNameAry = [];
    var libPathAry = [];
    var profile = this.profile;
    var Settings = this.Settings;


    /* XDCtools 3.10 has new findSuffix() function */
    if ("findSuffix" in prog.build.target) {
        suffix = prog.build.target.findSuffix(this);
        if (suffix == null) {
            return "";  // nothing to contribute
        }
    }
    else {
        suffix = prog.build.target.suffix;
    }

    /* specify which tiler implementation to use */
    if (Settings.tilerLib == Settings.TilerLib_Stub) {
        libNameAry.push("tiler_stub");
    }
    else if (Settings.tilerLib == Settings.TilerLib_Skel) {
        libNameAry.push("tiler_skel");
    }
    else if (Settings.tilerLib != Settings.TilerLib_Direct) {
        throw new Error("Unsupported remote implementation");
    }

    /* specify which operating system to target */
    if (Settings.tilerManagerOS == Settings.OperSys_Linux) {
        libNameAry.push("tiler_linux");
    }
    else if (Settings.tilerManagerOS == Settings.OperSys_WinCE) {
        libNameAry.push("tiler_wince");
        throw new Error("Unsupported tiler implementation: OperSys_WinCE");
    }
    else if (Settings.tilerManagerOS == Settings.OperSys_RTOS) {
        libNameAry.push("tiler_rtos");
//      throw new Error("Unsupported tiler implementation: Opersys_RTOS");
    }
    else if (Settings.tilerManagerOS != undefined) {
        throw new Error("Unsupported operating system");
    }

    /* make sure the library exists, else fallback to a built library */
    for (var i = 0; i < libNameAry.length; i++) {
        file = "lib/" + profile + "/" + libNameAry[i] + ".a" + suffix;
        if (java.io.File(this.packageBase + file).exists()) {
            libPathAry.push(file);
        }
        else {
            file = "lib/release/" + libNameAry[i] + ".a" + suffix;
            if (java.io.File(this.packageBase + file).exists()) {
                libPathAry.push(file);
            }
            else {
                /* fallback to a compatible library built by this package */
                for (var p in this.build.libDesc) {
                    if (p.match(libNameAry[i] + ".a" + suffix)) {
                        libPathAry.push(p);
                        break;
                    }
                }
            }
        }
    }

    return libPathAry.join(";");
}
/*
 *  @(#) ti.sdo.tiler; 1, 0, 0,4; 2-22-2012 18:10:47; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

