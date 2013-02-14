/*
 * 
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
/* This "requires" list describes what packages to import into this bundle */
requires ti.sdo.fc.global;
requires ti.sdo.fc.dskt2;
requires ti.sdo.fc.dman3;
requires ti.sdo.fc.acpy3;
requires ti.sdo.fc.ecpy;

requires ti.sdo.fc.utils;
requires ti.sdo.fc.utils.api;
requires ti.sdo.fc.utils.gtinfra;
requires ti.sdo.fc.utils.osal;
requires ti.sdo.fc.utils.osalsupport;
requires ti.sdo.fc.utils.osal.noOS;
requires ti.sdo.fc.memutils;

requires ti.sdo.fc.ires;
requires ti.sdo.fc.examples;
requires ti.sdo.fc.examples.buildutils;
requires ti.sdo.fc.examples.dmaXfer;
requires ti.sdo.fc.examples.dmaxferchecker;
requires ti.sdo.fc.ires.bufres;
requires ti.sdo.fc.ires.edma3chan;
requires ti.sdo.fc.ires.hdvicp;
requires ti.sdo.fc.ires.nullresource;
requires ti.sdo.fc.ires.sdma;
requires ti.sdo.fc.ires.shmbuf;
requires ti.sdo.fc.ires.tiledmemory;
requires ti.sdo.fc.ires.vicp;

requires ti.sdo.fc.rman;

requires ti.sdo.fc.edma3;
requires ti.sdo.fc.scpy;
requires ti.sdo.fc.hdintc;

requires khronos.opencl;

requires ti.sdo.opencl;
requires ti.sdo.opencl.platforms.c6472;
requires ti.sdo.opencl.examples;
requires ti.sdo.opencl.examples.autoviz;
requires ti.sdo.opencl.examples.hello;

requires ti.sdo.utils.trace;

requires ti.sdo.rcm;
requires ti.sdo.tiler;

/* Examples */
requires ti.sdo.fc.dskt2.examples;
requires ti.sdo.fc.rman.examples;
requires ti.sdo.fc.rman.examples.bufres;
requires ti.sdo.fc.rman.examples.bufres_yield;
requires ti.sdo.fc.rman.examples.dmaXferScratch;
requires ti.sdo.fc.rman.examples.dummyEdma3;
requires ti.sdo.fc.rman.examples.hdvicp;
requires ti.sdo.fc.rman.examples.nullresource.test;
requires ti.sdo.fc.rman.examples.plugin;
requires ti.sdo.fc.rman.examples.scratchEdma3;
requires ti.sdo.fc.rman.examples.sdma;
requires ti.sdo.fc.rman.examples.shmbuf;
requires ti.sdo.fc.rman.examples.vicp;
requires ti.sdo.fc.rman.examples.hdvicp.hdvicp2;

requires ti.sdo.fc.dman3.examples.fastcopy;
requires ti.sdo.fc.ires.examples.codecs.auddec1;
requires ti.sdo.fc.ires.examples.codecs.edmacodec1;
requires ti.sdo.fc.ires.examples.codecs.idma3codec1;
requires ti.sdo.fc.ires.examples.codecs.template;
requires ti.sdo.fc.ires.examples.codecs.universal_dma;

requires ti.sdo.rcm.examples.appcfg;
requires ti.sdo.rcm.examples.hello;
requires ti.sdo.rcm.examples.minidist.linux.osal;
requires ti.sdo.rcm.examples.minidist.linux.client;
requires ti.sdo.rcm.examples.minidist.linux.server;

requires ti.sdo.tiler.examples.remote;

/*!
 *  ======== framework_components ========
 *  The Framework Components product package.
 *
 *  This package is a "bundle" of several Framework Components packages.
 */
package framework_components_3_22_01_07 [1, 0, 0] {
}
/*
 *  @(#) framework_components_3_22_01_07; 1, 0, 0,1; 2-22-2012 18:25:04; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

