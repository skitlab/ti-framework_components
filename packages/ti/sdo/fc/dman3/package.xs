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

var UTILS = xdc.loadCapsule('ti/sdo/fc/utils/utils.xs');
/*
 *  ======== validate ========
 */
function validate()
{
    var suffix = Program.build.target.findSuffix(this);
    var DMAN3 = this.DMAN3;

    if (suffix == null) {
        /* unsupported target - nothing to validate */
        return;
    }

    if (!(suffix.match(/64P/)) && (!(suffix.match(/674/))) &&
            (DMAN3.useExternalRM == true)) {
       throw("\n\n  DMAN3 Error: Configured DMAN3.useExternalRM = true for " +
             "non-C64P device. This mode supported only for C64P devices.");
    }

    if (DMAN3.useExternalRM == false) {
        if ((DMAN3.paRamBaseIndex + DMAN3.numPaRamEntries) >
                DMAN3.maxPaRamEntries ) {
            throw("\n\n  DMAN3 Error: configured DMAN3.numPaRamEntries (base " +
                "index:  " + DMAN3.paRamBaseIndex + ", number of " +
                "entries: " + DMAN3.numPaRamEntries + ") exceeds the " +
                "maximum number of PaRam entries on this Chip (" +
                DMAN3.maxPaRamEntries + "). Reduce DMAN3.numPaRamEntries" +
                " and/or adjust DMAN3.paRamBaseIndex so that it is within a " +
                "valid range.");
        }

        if ( DMAN3.nullPaRamIndex  >= DMAN3.maxPaRamEntries ) {
            throw("\n\n  DMAN3 Error: configured DMAN3.nullPaRamIndex (" +
                DMAN3.nullPaRamIndex + ") assigned to a value greater " +
                "than DMAN3.maxPaRamEntries (" + DMAN3.maxPaRamEntries +
                ").");
        }

        if ((DMAN3.nullPaRamIndex >= DMAN3.paRamBaseIndex) &&
                (DMAN3.nullPaRamIndex <
                (DMAN3.paRamBaseIndex + DMAN3.numPaRamEntries))) {
            throw("\n\n  DMAN3 Error: configured DMAN3.nullPaRamIndex (" +
                DMAN3.nullPaRamIndex + ") already assigned " +
                "to DMAN3 as free PaRam.  Select a different " +
                "DMAN3.nullPaRamIndex value outside of assigned DMAN3 range (" +
                "currently (" + DMAN3.paRamBaseIndex + " - " +
                (DMAN3.paRamBaseIndex + DMAN3.numPaRamEntries) +").");
        }

        if ((DMAN3.maxTCs > 8) || (DMAN3.maxTCs <= 0)) {
            throw("\n\n DMAN3 Error: config DMAN3.maxTCs should be > 0 and " +
            "<= 8. " + "Bad value " + DMAN3.maxTCs + "; please " +
            "reconfigure.");

        }

        for (var i = 0; i < DMAN3.numQdmaChannels; i++) {
            if ((DMAN3.qdmaQueueMap[i] >= DMAN3.maxTCs) ||
                    (DMAN3.qdmaQueueMap[0] < 0)) {
                throw("\n\n DMAN3 Error: config DMAN3.qdmaQueueMap[", + i +"]" +
                " should be > 0 and < DMAN3.maxTCs. Bad value " +
                DMAN3.qdmaQueueMap[i] + ". Please reconfigure");
            }
        }

        for (var j = 0; i < DMAN3.numQdmaChannels; j++) {
            if ((DMAN3.queueTCMap[i] >= DMAN3.maxTCs) ||
                    (DMAN3.queueTCMap[0] < 0)) {
                throw("\n\n DMAN3 Error: config DMAN3.queueTCMap[" + j + "]" +
                    " should be > 0 and < DMAN3.maxTCs. Bad value " +
                    DMAN3.queueTCMap[j] + ". Please reconfigure");
            }
        }
    }
}

/*
 *  ======== getLibs ========
 */
function getLibs(prog)
{
    var suffix;
    var libName;
    var profile;
    var isa = prog.build.target.isa;
    var DMAN3 = this.DMAN3;

    if ("findSuffix" in prog.build.target) {
        suffix = prog.build.target.findSuffix(this);
    }
    else {
        suffix = prog.build.target.suffix;
    }

    if (suffix == null) {
        print(this.$name + ".getLibs(): Can't find suffix for " +
              prog.build.target.name + " target.");
        return ("");
    }

    if (DMAN3.useExternalRM) {
        var libName = "dman3RMCfg.a"
    }
    else {
        var libName = "dman3Cfg.a"
    }

    // PC can only use CPU copy library
    if (isa.match(/i686/) != null) {
        libName = "dman3cpuCfg.a";
    }
    else {

        /* For all other targets, check the configuration */
        if (DMAN3.cpu) {
            libName = "dman3cpuCfg.a";
        }
    }

    var dir = "lib/" + this.profile;

    libs = libName + suffix;

    if (!java.io.File(this.packageBase + dir + "/" + libs).exists()) {
        print(this.$name + ": Requested profile '" + this.profile + "' does "
                + "not exist.\n\tDefaulting to the 'release' profile");

       dir = "lib/release";
    }

    return (dir + "/" + libs);

}


/*
 * ======== close ========
 */
function close()
{
    var DMAN3 = this.DMAN3;

    if (this.profile == undefined) {
        this.profile = xdc.useModule('ti.sdo.fc.global.Settings').profile;
    }

    var defaultQdmaPaRamBase = 0x1C04000;
    var defaultMaxPaRamEntries = 128;
    var defaultMaxQdmaChannels = 8;
    var defaultPaRamBaseIndex = 96;
    var defaultNumPaRamEntries = 32;
    var defaultNullPaRamIndex = 0;
    var defaultNumQdmaChannels = 4;

    var defaultQdmaChannels = [0,1,2,3];;
    var defaultTccAllocationMaskH = 0xffffffff;
    var defaultTccAllocationMaskL = 0x00000000;
    var defaultQdmaQueueMap =[1,1,1,1,1,1,1,1];;
    var defaultQueueTCMap =[0,1,2,3,4,5,6,7];;
    var defaultQueuePri = [3,7,0,0,0,0,0,0];

    var defaultNumTccGroup = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
    var defaultNumPaRamGroup = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];


    if (DMAN3.useExternalRM == true) {

        if (DMAN3.qdmaPaRamBase != defaultQdmaPaRamBase) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"qdmaPaRamBase\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (DMAN3.maxPaRamEntries != defaultMaxPaRamEntries) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"maxPaRamEntries\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (DMAN3.maxQdmaChannels != defaultMaxQdmaChannels) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"maxQdmaChannels\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (DMAN3.paRamBaseIndex != defaultPaRamBaseIndex) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"paRamBaseIndex\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (DMAN3.nullPaRamIndex != defaultNullPaRamIndex) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"nullPaRamIndex\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (!UTILS.compareArray(DMAN3.qdmaChannels, defaultQdmaChannels)){
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"qdmaChannels\" will be ignored. Configure" +
                " ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (DMAN3.tccAllocationMaskH != defaultTccAllocationMaskH) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"tccAllocationMaskH\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (DMAN3.tccAllocationMaskL != defaultTccAllocationMaskL) {
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"tccAllocationMaskL\" will be ignored. Configure " +
                "ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (!UTILS.compareArray(DMAN3.qdmaQueueMap, defaultQdmaQueueMap)){
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"qdmaQueueMap\" will be ignored. Configure" +
                " ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (!UTILS.compareArray(DMAN3.queueTCMap, defaultQueueTCMap)){
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"queueTCMap\" will be ignored. Configure" +
                " ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (!UTILS.compareArray(DMAN3.queuePri, defaultQueuePri)){
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"queuePri\" will be ignored. Configure" +
                " ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (!UTILS.compareArray(DMAN3.numTccGroup, defaultNumTccGroup)){
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"numTccGroup\" will be ignored. Configure" +
                " ti.sdo.fc.edma3.Settings module with appropriate values.");
        }
        if (!UTILS.compareArray(DMAN3.numPaRamGroup,defaultNumPaRamGroup)){
            print("Warning DMAN3.useExternalRM set to true, so configuration " +
                "parameter \"numPaRamGroup\" will be ignored. Configure" +
                " ti.sdo.fc.edma3.Settings module with appropriate values.");
        }

        /* If external RM is used, include low level Resource Manager module */
        xdc.useModule("ti.sdo.edma3.rm.RM");

        /* Needed to configure the low level resource manager module */
        xdc.useModule("ti.sdo.fc.edma3.Settings");
    }

    // First determine is bios is used before loading this package. If
    // bios is used, we need to load the package here so that the bios
    // library will get linked in after the dman3 library. The dman3 library
    // has MEM functions that must either come from bios, or another
    // library.
    /*
    if ('ti.bios' in xdc.om) {
        print("Found ti.bios");
        xdc.loadPackage('ti.bios');
    }
    */

    // This package depends on osal
    if ('ti.sdo.osal.linux' in xdc.om) {
        print("Found ti.sdo.osal.linux");
        xdc.loadPackage('ti.sdo.osal.linux');
    }

    xdc.loadPackage("ti.sdo.fc.utils");

    xdc.loadPackage("ti.xdais");

    Program.exportModule("xdc.runtime.Error");
}

/*
 *  @(#) ti.sdo.fc.dman3; 1, 0, 4,4; 2-22-2012 18:03:20; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

