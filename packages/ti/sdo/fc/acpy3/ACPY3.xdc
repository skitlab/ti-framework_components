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

import xdc.runtime.IHeap;

/*!
 *  ======== ACPY3 ========
 *  EDMA3 "Algorithm Copy" library.
 */
@Template("./ACPY3.xdt")

metaonly module ACPY3 {

    /*!
     *  ======= edma3BaseAddress =======
     *  EDMA3 Base Address for the device
     *  Not required to be set if this library
     *  is used alongwith DMAN3.
     */
    config UInt edma3BaseAddress;

    /*!
     *  ======= paRamBaseAddress =======
     *  PaRam Base Address for the device
     *  Not required to be set if this library
     *  is used alongwith DMAN3 or for built for TI targets.
     */
    config UInt paRamBaseAddress;

    /*!
     *  ======= nullPaRam =======
     *  Index of the paRam to be used as Null paRam
     *  Not required to be set if this library
     *  is used alongwith DMAN3.
     */
    config UInt nullPaRam;

    /*!
     *  ======= cpu ========
     *  Builds a non-EDMA, CPU only version of the library
     */
     config Bool cpu = false;

    /*!
     *  ======== ipcKeyBase ========
     *  Linux only. Base value of keys of Linux IPC objects used by
     *  ACPY3CFG. The IPC objects created by ACPY3 will use keys starting at
     *  this value, and incrementing with each new object. There are currently
     *  three IPC objects, so keys in the range of ipcKeyBase to ipcKeyBase + 2
     *  will be reserved for ACPY3CFG. The default value of ipcKeyBase is
     *  ascii code for "YPCA".
     *
     *  WARNING: This value should only be changed if it conflicts with
     *  another IPC key in the system that cannot be changed. If this value
     *  is changed, all programs using ACPY3CFG that will be run simultaneously
     *  must have the ipcKeyBase configured to the new value.
     *  @_nodoc
     */
    config UInt ipcKeyBase = 0x33504341;
    
    config Bool enableLog;
}

/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

