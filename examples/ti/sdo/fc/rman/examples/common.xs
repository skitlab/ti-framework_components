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
 *  ======== common.xs ========
 */

/* List of platforms we  build these examples for */
var DmaPlatformList674 = [
    "ti.platforms.evmDA830",
    "ti.platforms.evmTI816X"
];

var DmaPlatformListv5T = [
    "ti.platforms.evmDM355",
    "ti.platforms.evmDM365"
];

var DmaPlatformList64P = [
    "ti.platforms.evmDM6446",
    "ti.platforms.dsk6455",
    "ti.platforms.evmDM648",
    "ti.platforms.evmDM6467",
    "ti.platforms.evm3530",
    "ti.platforms.evm3430",
    "ti.platforms.sdp2430",
    //"ti.platforms.evmOMAPL137",
    //"ti.platforms.evmOMAPL138",
];

var DmaPlatformList64PMC = [
    "ti.platforms.evm6472",
    "ti.platforms.evm6474"
];

var DmaPlatformList66MC = [
    "ti.platforms.evm6678",
    "ti.platforms.evm6670"
];

/* We don't support DMA on these platforms */
var otherPlatforms = [
    "ti.platforms.sdp4430",
    "ti.platforms.evmTI813X"
];

var FullPlatformList = new Array();
FullPlatformList = FullPlatformList.concat(DmaPlatformList64P);
FullPlatformList = FullPlatformList.concat(DmaPlatformList64PMC);
FullPlatformList = FullPlatformList.concat(DmaPlatformList66MC);
FullPlatformList = FullPlatformList.concat(DmaPlatformList674);
FullPlatformList = FullPlatformList.concat(DmaPlatformListv5T);
FullPlatformList = FullPlatformList.concat(otherPlatforms);

function getDMAPlatforms(isa) {
    if (isa.match(/64P/)) {
        return DmaPlatformList64P;
    }
    if (isa.match(/674/)) {
        return DmaPlatformList674;
    }
    if (isa.match(/v5T/)) {
        return DmaPlatformListv5T;
    }
}


function getAllPlatforms() {
    return FullPlatformList;
}
/*
 *  @(#) ti.sdo.fc.rman.examples; 1, 0, 0,4; 2-22-2012 18:07:12; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

