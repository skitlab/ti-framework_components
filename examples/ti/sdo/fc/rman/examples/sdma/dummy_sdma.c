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
#include <xdc/std.h>
#include <ti/sdo/linuxutils/sdma/include/sdma.h>

#define SDMA_MAX_LOGICAL_CHANNELS       32   /* Number available on hardware */
#define SDMA_AVAILABLE_LOGICAL_CHANNELS 10   /* Number available to algorithms*/

Int SDMA_logicalChannels[SDMA_MAX_LOGICAL_CHANNELS] = {1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

Int SDMA_initRefCount = 0;

Int SDMA_init()
{
    Int i;
    if (0 == SDMA_initRefCount) {

        /* Mark last SDMA_AVAILABLE_LOGICAL_CHANNELS available */
        for (i = 1; i <= SDMA_AVAILABLE_LOGICAL_CHANNELS; i++) {
            SDMA_logicalChannels[SDMA_MAX_LOGICAL_CHANNELS-i] = 0;
        }
    }
    SDMA_initRefCount++;
    return (0);
}

Int SDMA_exit()
{
    if (SDMA_initRefCount > 0) {
        SDMA_initRefCount--;
    }
    else {
        //Error
        return (-1);
    }
    return (0);
}

/* SDMA_Status SDMA_getChannels(Int numChannels, Int chanArray[])*/
SDMA_Status SDMA_getChannels(Int numChannels,
        SDMA_ChannelDescriptor chanArray[])
{
    int i;
    int count = 0;
    for (i = SDMA_MAX_LOGICAL_CHANNELS-1; i >= 0; i--) {
        if (SDMA_logicalChannels[i] == 0) {
            chanArray[count].chanNum = i; /* Enter channel number in chanArray*/
            chanArray[count].addr = 0x0;
            chanArray[count].transferState.checkPending = 0x0;
            chanArray[count].transferState.transferCompleted = 0x0;
            SDMA_logicalChannels[i] = 1; /* Mark channel is busy */
            count++;
        }
        if (count == numChannels) {
            break;
        }
    }
    if (count < numChannels) {
        SDMA_freeChannels(count, chanArray);
        return (SDMA_ENOCHANNEL);
    }
    return (SDMA_OK);
}

/* SDMA_Status SDMA_freeChannels(Int numChannels, Int chanArray[])*/
SDMA_Status SDMA_freeChannels(Int numChannels,
        SDMA_ChannelDescriptor chanArray[])
{
    int i;
    SDMA_Status status = SDMA_OK;

    for (i = 0; i < numChannels; i++) {
        if (SDMA_logicalChannels[chanArray[i].chanNum] == 1) {
            SDMA_logicalChannels[chanArray[i].chanNum] = 0;
        }
        else {
            /* Trying to free already freed channels */
            status = SDMA_EFAIL;
        }
    }
    return (status);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.sdma; 1, 0, 0,4; 2-22-2012 18:08:08; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

