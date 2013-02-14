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
 *  ======== edma3Chan2Lite.c ========
 *  Implementation of the IRESMAN interface to acquire EDMA3CHAN resource 
 *  handles. 
 */


#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include "ires_edma3Chan.h"
#include "edma3Chan2Lite.h"
#include "_edma3Chan.h" 

#define CHANMAX ti_sdo_fc_ires_edma3chan_EDMA3CHANLITE_numChans
#define CHANS(i) ti_sdo_fc_ires_edma3chan_EDMA3CHANLITE_chanArray[(i)]
#define BASEADDR ti_sdo_fc_ires_edma3chan_EDMA3CHANLITE_baseAddr
#define PARAMBASEOFFSET  0x4000

void IRES_EDMA3CHAN_getStaticProperties(IRES_Handle resourceHandle,
        IRES_Properties * resourceProperties);

IRES_EDMA3CHAN2_Handle EDMA3CHAN2_createHandle (IALG_Handle alg, 
        IRES_EDMA3CHAN_ProtocolArgs * args, Int scratchId)
{
    IRES_EDMA3CHAN2_Handle res = NULL;
    Int size = 0x0;
    IALG_MemRec memRec;
    Int numP = 0;
    Int numT = 0;
    Int i = 0;
    Int index = -1;
    Bool found = FALSE;

    IRES_EDMA3CHAN_PaRamStruct * shadowPaRamsPtr = 0x0;
    unsigned int * paRamAddressPtr = 0x0;
    short * paRamIndexPtr = 0x0;
    short * tccIndexPtr = 0x0;
    Int grpToMatch = -2; 

    UInt paRamBase = BASEADDR + PARAMBASEOFFSET; 

    numP = args->numPaRams;
    numT = args->numTccs;

    if ((args->mode == IRES_PERSISTENT) || (scratchId == -1)) {
        grpToMatch = -2;    //Only resources with grp of -2 are unused
        scratchId = -1;
    }
    else {
        grpToMatch = scratchId;
    }

    /* 0. Pick out of configured resources to return the right resources */ 
    /*    Need to do some sort of scratch sharing of resources */  
    for (i = 0; i < CHANMAX; i++) {
        /* Your resource is either unused, or if scratch shared, then owned by
           same scratch grp */  
        if ( ((grpToMatch == CHANS(i).scratchGrp) || 
                (CHANS(i).scratchGrp == -2)) && (numP <= CHANS(i).numParams) && 
                (numT <= CHANS(i).numTccs)) {
            found = TRUE;
            index = i;
            break;
        }
    }

    if (!(found)) return (NULL);

    /* 1. Calculate size based on arguments requested, num params, num tccs, 
          shadow params etc */ 
    if (args->shadowPaRamsAllocation) {
        size = numP * (sizeof(short) + sizeof(IRES_EDMA3CHAN_PaRamStruct)
                + sizeof(unsigned int));
    } 
    else {
        size = numP * ( sizeof(short) + sizeof(unsigned int));
    }
    size += numT * ( sizeof(short));
    size += sizeof(IRES_EDMA3CHAN2_Obj);

    /* 2. Allocate memory for the handle */
    memRec.size = size;
    memRec.alignment = 4;
    memRec.space = IALG_EXTERNAL;
    memRec.attrs = IALG_PERSIST;

    memRec.base = Memory_calloc(NULL, memRec.size, memRec.alignment, NULL);

    if (memRec.base == NULL) {
        return (NULL);
    }

    res = memRec.base;

    shadowPaRamsPtr = (IRES_EDMA3CHAN_PaRamStruct *)((UInt8 *)res +
            sizeof(IRES_EDMA3CHAN2_Obj));

    if (args->shadowPaRamsAllocation) {
        paRamAddressPtr = (unsigned int *)((UInt8 *)shadowPaRamsPtr +
                (numP * sizeof(IRES_EDMA3CHAN_PaRamStruct)));
    }
    else {
        paRamAddressPtr =  (unsigned int *)shadowPaRamsPtr;
        shadowPaRamsPtr = NULL;
    }

    paRamIndexPtr = (short *)((UInt8 *)paRamAddressPtr + (numP *
            sizeof(unsigned int)));

    tccIndexPtr = (short *)((UInt8 *)paRamIndexPtr + (numP *
            sizeof(unsigned short)));

    res->assignedPaRamIndices = paRamIndexPtr;
    res->shadowPaRams = shadowPaRamsPtr;
    res->assignedPaRamAddresses = paRamAddressPtr;
    res->assignedTccIndices = tccIndexPtr;

    res->assignedNumPaRams = numP; 
    res->assignedNumTccs = numT; 
    res->assignedEdmaChannelIndex = CHANS(index).chanNo;
    res->assignedQdmaChannelIndex = IRES_EDMA3CHAN_CHAN_NONE; 

    (res->ires).getStaticProperties = IRES_EDMA3CHAN_getStaticProperties;

    CHANS(index).scratchGrp = scratchId;
    CHANS(index).numUsers += 1;

    /* 3. Populate the handle */
    /*    Add resources */
    /*    Point to the getStaticProperties function */
    for (i = 0; i < numP; i++) {
        paRamIndexPtr[i] = CHANS(index).paramArr[i]; 
        paRamAddressPtr[i] = paRamBase + ((unsigned int)paRamIndexPtr[i] *
                sizeof(IRES_EDMA3CHAN_PaRamStruct));
    }

    for (i = 0; i < numT; i++) {
        tccIndexPtr[i] = CHANS(index).tccArr[i]; 
    }
 
    /* 4. */
    return (res);
} 

IRES_Status EDMA3CHAN2_freeHandle (IALG_Handle alg, IRES_EDMA3CHAN2_Handle h,
        IRES_EDMA3CHAN_ProtocolArgs * args, Int scratchId)
{
    Int size = 0x0;
    Int numP = 0;
    Int numT = 0;
    Int chanNo = -1; 
    Int i = 0;
    Int index = -1;
    Bool found = FALSE;

    numP = args->numPaRams;
    numT = args->numTccs;
    chanNo = h->assignedEdmaChannelIndex;
    //CHANS(index).chanNo;

    for (i = 0; i < CHANMAX; i++) {
        if (CHANS(i).chanNo == chanNo) {
            //Assuming scratch group ids match !
            index = i;
            found = TRUE;
            break;
        }
    }

    if (!(found)) { return (IRES_ENORESOURCE); }

    CHANS(index).numUsers -= 1;
    if (CHANS(index).numUsers == 0) {
        CHANS(index).scratchGrp = -2; //Reset, mark as unused
    }

    if (args->shadowPaRamsAllocation) {
        size = numP * (sizeof(short) + sizeof(IRES_EDMA3CHAN_PaRamStruct)
                + sizeof(unsigned int));
    } 
    else {
        size = numP * ( sizeof(short) + sizeof(unsigned int));
    }
    size += numT * ( sizeof(short));
    size += sizeof(IRES_EDMA3CHAN2_Obj);

    /* 1. Mark returned resources as available */ 

    /* 2. Free the handle */
    Memory_free (NULL,  h, size);
    
    return (IRES_OK);
}

/**
 *  ======= IRES_EDMA3CHAN_getStaticProperties =======
 *  Returns the static properties of the particular resource
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
void IRES_EDMA3CHAN_getStaticProperties(IRES_Handle resourceHandle,
        IRES_Properties * resourceProperties)
{
    IRES_EDMA3CHAN_Properties * properties =
            (IRES_EDMA3CHAN_Properties *)resourceProperties;

    unsigned int * addr = (unsigned int *) BASEADDR;

    unsigned int cccfg = addr[1];

    properties->numDmaChannels =
            IRES_EDMA3CHAN_EDMA3REGISTERLAYER_NUMDMACH(cccfg);
    properties->numEvtQueue =
            IRES_EDMA3CHAN_EDMA3REGISTERLAYER_NUMEVTQUE(cccfg);
    properties->numPaRAMSets =
            IRES_EDMA3CHAN_EDMA3REGISTERLAYER_NUMPAENTRY(cccfg);
    properties->numQdmaChannels =
            IRES_EDMA3CHAN_EDMA3REGISTERLAYER_NUMQDMACH(cccfg);
    properties->numRegions = IRES_EDMA3CHAN_EDMA3REGISTERLAYER_NUMREGN(cccfg);
    properties->numTccs = IRES_EDMA3CHAN_EDMA3REGISTERLAYER_NUMINTCH(cccfg);
    properties->numTcs = properties->numEvtQueue;
    properties->dmaChPaRAMMapExists    =
            IRES_EDMA3CHAN_EDMA3REGISTERLAYER_CHMAPEXIST(cccfg);
    properties->memProtectionExists    =
            IRES_EDMA3CHAN_EDMA3REGISTERLAYER_MPEXIST(cccfg);
    properties->globalRegs = (IRES_EDMA3CHAN_EDMA3RegisterLayer *)BASEADDR; 
}
/*
 *  @(#) ti.sdo.fc.ires.edma3chan; 1, 0, 0,4; 2-22-2012 18:05:31; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

