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
/**
 *  @file       ti/sdo/fc/ecpy/ecpy_impl.c
 *
 *  @brief      ECPY Definitions (C64P) - EDMA functional library  
 *              Provides a comprehensive list of DMA operations an algorithm
 *              can perform on logical DMA channels it acquires through the
 *              IRES_EDMA3CHAN protocol.
 *
 *  WARNING:    THIS IS NOT THE FINAL REVISION OF ECPY INTERFACE. IT IS SUBJECT
 *              TO CHANGES PER REVIEW FEEDBACK. ADDITIONALLY, CURRENTLY IT IS 
 *              AN API DEFINITION ONLY, IMPLEMENTATION AND COLLATERAL SUPPORT
 *              WILL BE ADDED IN FUTURE FC RELEASES.
 */

/**
 *  @defgroup   ti_sdo_fc_ecpy_ECPY ECPY (C64P)
 *
 *              The ECPY module provides a comprehensive list of DMA
 *              operations an algorithm can perform on logical DMA channels
 *              it acquires through the IRES_EDMA3CHAN protocol. Example of ECPY
 *              operations include channel configuration, DMA transfer
 *              scheduling, and DMA transfer synchronization.
 *
 *  @remark     For additional information, please refer to the
 *              "Using DMA with Framework Components for 'C64x+" document.
 */

#ifdef __cplusplus
extern "C" {
#endif

#define Registry_CURDESC ti_sdo_fc_ecpy_desc

/** @ingroup    ti_sdo_fc_ecpy_ECPY */
/*@{*/
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include "ecpy.h"
#include "ecpy_util.h"

static Void *myAlloc(size_t size, size_t align);
static Void myFree(Ptr addr, size_t size);
extern Registry_Desc ti_sdo_fc_ecpy_desc;

/*
 *  ======== myAlloc ========
 *  Wrapper around ECPY_CFG_PARAMS.allocFxn.
 */
static Void *myAlloc(size_t size, size_t align)
{
    IALG_MemRec memTab;
    Void       *addr = NULL;

    if (NULL == ECPY_CFG_PARAMS.allocFxn) {
        return (NULL);
    } 

    memTab.size = size;
    memTab.alignment = align;
    memTab.space = IALG_DARAM0; /* this gets overridden in DSKT2_allocPersistent
                                 * to IALG_ESDATA.  */
    memTab.attrs = IALG_PERSIST;

    if (ECPY_CFG_PARAMS.allocFxn(&memTab, 1)) {
        addr = memTab.base;
    }

    return (addr);
}

/*
 *  ======== myFree ========
 *  Wrapper around ECPY_CFG_PARAMS.freeFxn.
 */
static Void myFree(Ptr addr, size_t size)
{
    IALG_MemRec memTab;

    memTab.base = addr;
    memTab.size = size;
    memTab.alignment = 0;         /* Alignment shouldn't be needed here */
    memTab.space = IALG_DARAM0;
    memTab.attrs = IALG_PERSIST;

    ECPY_CFG_PARAMS.freeFxn(&memTab, 1);
}

#ifndef _CACHE_IRES
/*
 *  ======== ECPY_getPaRamLinkIndex ============
 *  Returns the PARAM ID of the Physical PaRAM Regs associated with the
 *  logical channel handle's transfer for configuring the LINK field in linked
 *  transfers.
 */
static __inline
Uns ECPY_getPaRamLinkIndex(IRES_EDMA3CHAN2_Handle handle, short transferNo)
{
    return ((Uns)(handle->assignedPaRamAddresses[transferNo]) & 
            0xFFFF);                 
}
#endif

static IRES_EDMA3CHAN_EDMA3RegisterLayer *_EDMA3_globalRegs = NULL;

static IRES_EDMA3CHAN_Properties  _EDMA3CHAN_staticProperties;

static void _ECPY_initEDMA3CHANStaticProperties(IRES_EDMA3CHAN2_Handle handle)
{
    /* ensure that the toolchain uses same structure layout for PaRAM overlay */
    Assert_isTrue((sizeof(IRES_EDMA3CHAN_PaRamStruct)==32), (Assert_Id)NULL);
    
    if (_EDMA3_globalRegs == NULL) {

        handle->ires.getStaticProperties((struct IRES_Obj *)handle,  
                (IRES_Properties *)&_EDMA3CHAN_staticProperties);
        _EDMA3_globalRegs = _EDMA3CHAN_staticProperties.globalRegs;
    }
}
        

/* common PARAM update portion of _configure and _directConfigure functions */
static __inline Void
_updatePaRam(ECPY_ScratchObj *handle, IRES_EDMA3CHAN_PaRamStruct *paRam, 
        ECPY_Params * restrict params, short transferNo)
{
    ECPY_Packed32 _packed_acnt_bcnt;
    ECPY_Packed32 _packed_elementIndexes;
    ECPY_Packed32 _packed_frameIndexes;
    
#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj *iresHandle = handle;
#endif

    PaRamStructPtr paRamPtr = (PaRamStructPtr)paRam;

    /* Final transfer's OPT's STATIC bit will ON initially, and will be 
     * cleared/unset iff later we discover it is a 3D xfer */
    unsigned int staticBit = ECPY_PARAMOPTS_STATIC; 
    unsigned int itcchenBit = 0x0;
    
    /* #1 - Source address */
    paRamPtr->src = (unsigned int)params->srcAddr;

    /* #2 */
    _packed_acnt_bcnt.field.lo16 = params->elementSize; /* must always be set */

    /* #3 - Destination address */
    paRamPtr->dst = (unsigned int)params->dstAddr;

    if (params->transferType != ECPY_1D1D) {

        /* Field #2: update with 2nd dimension */
        _packed_acnt_bcnt.field.hi16 = params->numElements;

        /* Field #3: set Element Indexes for 2D */
        if (params->transferType == ECPY_1D2D) {
            Log_print0(Diags_USER4, "[+4] ECPY_configure> 1D2D transfer");
            _packed_elementIndexes.field.lo16 = params->elementSize;
            _packed_elementIndexes.field.hi16 = params->dstElementIndex;
        }
        else if (params->transferType == ECPY_2D1D) {
            Log_print0(Diags_USER4, "[+4] ECPY_configure> 2D1D transfer");
            _packed_elementIndexes.field.lo16 = params->srcElementIndex;
            _packed_elementIndexes.field.hi16 = params->elementSize;
        
        } else { /* 2D2D */
            _packed_elementIndexes.field.lo16 = params->srcElementIndex;
            _packed_elementIndexes.field.hi16 = params->dstElementIndex;
            Log_print0(Diags_USER4, "[+4] ECPY_configure> 2D2D transfer");
        }
        /* Element Indexes only get set for non 1D1D transfers */
        paRamPtr->elementIndexes.val32 = _packed_elementIndexes.val32;
        
    } else { /* 1D1D */
        _packed_acnt_bcnt.field.hi16 = 1;
        Log_print0(Diags_USER4, "[+4] ECPY_configure> 1D1D transfer");
    }

    paRamPtr->acnt_bcnt.val32 = _packed_acnt_bcnt.val32;

    if (params->numFrames <= 1) {
        paRamPtr->ccnt = 1;
    }
    else {
        /* 3D Transfer */
        paRamPtr->ccnt = params->numFrames;
        _packed_frameIndexes.field.lo16 = params->srcFrameIndex;
        _packed_frameIndexes.field.hi16 = params->dstFrameIndex;
        
        /* Frame Indexes only get set for 3D transfers :- numFrames/CCNT > 1 */
        paRamPtr->frameIndexes.val32 = _packed_frameIndexes.val32;

        /* reset staticBit (OPT's STATIC bit) and enable ITCCHEN since it is a 3D transter */
        staticBit = 0x0;
        itcchenBit = ECPY_PARAMOPTS_ITCCHEN; 
    }

    Log_print5(Diags_USER4, "[+4] ECPY_configure> src 0x%x, "
            "dst 0x%x, acnt 0x%x, bcnt 0x%x ccnt 0x%x",
            (IArg)(paRam->src), (IArg)(paRam->dst),
            (IArg)(paRam->acnt), (IArg)(paRam->bcnt),
            (IArg)(paRam->ccnt));

    Log_print3(Diags_USER4, "[+4] ECPY_configure> bcnt reload"
            " 0x%x, srcIndex 0x%x, dstIndex 0x%x",
            (IArg)(paRam->bCntrld), (IArg)(paRam->srcElementIndex),
            (IArg)(paRam->dstElementIndex));


    
    if ((transferNo != handle->finalTransferNo) && 
            (transferNo < iresHandle->assignedNumPaRams)) {
        /*  == INTERMEDIATE Transfer ==
         *  Setup this param's link field to point to the NEXT transfer when
         *  setting up linked transfers we assign PARAM addresses in
         *  descending order, so that the last entry is the first transfer,
         *  etc., handle's paRamAddr is pointing to the 'last' PARAM entry
         *  assigned to the channel handle (along with the preceding
         *  "numTransfer" PARAM entries.
         */
        /* #5 */
#ifndef _CACHE_IRES
        paRamPtr->link = (unsigned short)
                ECPY_getPaRamLinkIndex(iresHandle, transferNo);
#else
        paRamPtr->link = (unsigned short)
                ((handle->assignedPaRamAddresses[transferNo]) & 0xFFFF);
#endif

        /* initialize OPT from the create time configured value for linking */
        /* set ITCCHEN bit based on whether it is 3D transfer or not */
        paRamPtr->opt = handle->optLinked | itcchenBit;
                     
        Log_print2(Diags_USER4, "[+4] ECPY_configure> Link this"
                " transfer to 0x%x Opt is 0x%x",
                (IArg)(paRam->link), (IArg)(paRam->opt));
    }
    else {
        /* == Single transfer or the FINAL transfer of a linked set */
        /* #5 - Set no link for final PaRam */
        paRamPtr->link = 0xffff;

        /* #0 */
        /* initialize OPT from the create time configured value for FINAL */
        paRamPtr->opt = handle->optFinalStaticOff | staticBit | itcchenBit; 

        Log_print2(Diags_USER4, "[+4] ECPY_configure> Mark as Final "
                " transfer setting Link to 0x%x Opt is 0x%x",
                (IArg)(paRam->link), (IArg)(paRam->opt));
    }
}
/**
 *  @brief      Configure all DMA transfer settings for the logical channel.
 *
 *  @param[in]  handle      IRES_EDMA3CHAN channel handle.
 *  @param[in]  params      DMA transfer specific parameters used to
 *                          configure this logical DMA channel.
 *  @param[in]  transferNo  Indicates the individual transfer to be
 *                          configured using the passed 'params'
 *
 *  @pre        channel must be in active state
 *  @pre        valid  handle
 *  @pre        0 < transferNo <= originally requested number of transfers
 */
Void ECPY_configure(ECPY_Handle pHandle, ECPY_Params * restrict params,
    short transferNo)
{
    IRES_EDMA3CHAN_PaRamStruct * restrict paRam;
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj *iresHandle = handle;
#endif

    Log_print2(Diags_ENTRY, "[+E] ECPY_configure> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)transferNo);
    
#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

    if ((transferNo == 0) || (transferNo > iresHandle->assignedNumPaRams)) {

        Log_print2(Diags_USER4, "[+4] ECPY_configure> ERROR! (transferNo=%d) "
            " should be non-Zero and less than assignedNumPaRams:%d", 
            (IArg)transferNo, (IArg)iresHandle->assignedNumPaRams);
    }
    Assert_isTrue(transferNo <= iresHandle->assignedNumPaRams, (Assert_Id)NULL);
    Assert_isTrue((transferNo > 0), (Assert_Id)NULL);

#endif /* _DEBUG_ defined only for debug profile */
    
    /*
     * Always update shadow params of the 1st transfer.  
     * When using Linked or single 3D transfers the physical PaRam of the 
     * 1st trasfer gets overwritten , so it needs to be recorded in a shadow 
     * memory and written out to physical PaRAM before each 'start'.
     */
    if (transferNo == 1) {
        /* 1st transfer updates the shadow PaRAM */
        paRam = (IRES_EDMA3CHAN_PaRamStruct *)handle->firstPARAMShadow;

    } else {
        /* modify the assigned Physical PaRAM directly */
        paRam = (IRES_EDMA3CHAN_PaRamStruct *)
                iresHandle->assignedPaRamAddresses[transferNo-1];
    }

    _updatePaRam(handle, paRam, params, transferNo);

    Log_print2(Diags_EXIT, "[+E] ECPY_configure> Exit "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)transferNo);
}

/**
 *  @brief      Configure all DMA transfer settings for the logical channel.
 *
 *  @param[in]  handle      IRES_EDMA3CHAN channel handle.
 *  @param[in]  params      DMA transfer specific parameters used to
 *                          configure this logical DMA channel.
 *  @param[in]  transferNo  Indicates the individual transfer to be
 *                          configured using the passed 'params'
 *
 *  @pre        channel must be in active state
 *  @pre        valid  handle
 *  @pre        0 < transferNo <= originally requested number of transfers
 */
Void ECPY_directConfigure(ECPY_Handle pHandle, ECPY_Params * restrict params,
    short transferNo)
{
    IRES_EDMA3CHAN_PaRamStruct * restrict paRam;
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj * iresHandle = handle;
#endif

    Log_print2(Diags_ENTRY, "[+E] ECPY_directConfigure> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)transferNo);
    
#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

    if ((transferNo == 0) || (transferNo > iresHandle->assignedNumPaRams)) {

        Log_print2(Diags_USER4, "[+4] ECPY_configure> ERROR! (transferNo=%d) "
            " should be non-Zero and less than assignedNumPaRams:%d", 
            (IArg)transferNo, (IArg)iresHandle->assignedNumPaRams);
    }
    Assert_isTrue(transferNo <= iresHandle->assignedNumPaRams, (Assert_Id)NULL);
    Assert_isTrue(transferNo > 0, (Assert_Id)NULL);

#endif /* _DEBUG_ defined only for debug profile */


    /*
     * Fast version of configure, directly updating Physical EDMA3 PARAM space.
     * Does not update shadow params of the 1st transfer when using Linked
     * transfers. The physical PaRam of the 1st trasfer in a Linked xfer
     * gets overwritten copied  by the Linked transfers PaRAMs, so it needs
     * to be saved and refreshed before 'start'.
     * The physical PaRAM of a single transfer also gets overwritten if the
     * the transfer is 3D (numFrames (CCNT) > 1), and must be reconfigured
     * before next 'direcStart'.
     */

    /* Always modify the assigned Physical PaRAM directly */
    paRam = (IRES_EDMA3CHAN_PaRamStruct *)
            iresHandle->assignedPaRamAddresses[transferNo-1];

    _updatePaRam(handle, paRam, params, transferNo);

    Log_print2(Diags_EXIT, "[+E] ECPY_directConfigure> Exit "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)transferNo);
}

/*
 *  ======== ECPY_directConfigure16 ========
 */
Void ECPY_directConfigure16(ECPY_Handle restrict pHandle,
    ECPY_ParamField16b fieldId, unsigned short value, short transferNo)
{
    IRES_EDMA3CHAN_PaRamStruct * restrict paRam;
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj * iresHandle = handle;
#endif

    UInt registerValue32;
    UInt offsetAligned32;
    UInt *regPtr;

    Log_print4(Diags_ENTRY, "[+E] ECPY_directConfigure16b> Enter"
            " (handle=0x%x, fieldId=0x%x, value=0x%x, trasnferNo=%d",
            (IArg)handle, (IArg)fieldId, (IArg)value, (IArg)transferNo);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(transferNo > 0, (Assert_Id)NULL);
    Assert_isTrue(transferNo <= iresHandle->assignedNumPaRams, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    paRam = (IRES_EDMA3CHAN_PaRamStruct *)
            iresHandle->assignedPaRamAddresses[transferNo-1];

    /* to update a 16bit field in a 32bit register we first read the 32bit
     * register, update 
     */
    /* mask the rightmost 2 bits of fieldId to get a 32-bit aligned offset*/
    offsetAligned32 = fieldId & 0xFFFC;

    regPtr = (UInt *)((Char *)paRam + offsetAligned32);
    registerValue32 = *regPtr;
    registerValue32 &= ((UInt)0xFFFF0000 >> ((fieldId & 0x02) << 3));
    registerValue32 |= (value << ((fieldId & 0x02) << 3));
    *regPtr = registerValue32;

    if (fieldId == ECPY_PARAMFIELD_NUMFRAMES) {

        if  (value > 1) { /* 3D transfer */

            if (handle->finalTransferNo == transferNo) { 
                /* 3D Final transfer */
                /* set ITCCHEN to 1' and make sure the STATIC bit of OPT is 0 */
                paRam->opt = handle->optFinalStaticOff | ECPY_PARAMOPTS_ITCCHEN;
                
                Log_print0(Diags_USER4, "[+4] ECPY_directConfigure16b> "
                        "Resetting OPT.STATIC since this is a 3D, "
                        "Final transfer");
                
            } else { 
                /* intermediate 3D transfer => enable ITCCHEN */
                paRam->opt |= ECPY_PARAMOPTS_ITCCHEN;
            }
        } 
        else {
/* not a 3D transfer => ensure ITCCHEN is 0 to support dummy transfers */
            paRam->opt &= ~(ECPY_PARAMOPTS_ITCCHEN);
            
            if (handle->finalTransferNo == transferNo) { 
                /* final non-3D transfer, so additionally turn STATIC bit ON */
                paRam->opt |= (ECPY_PARAMOPTS_STATIC); 
                
                Log_print0(Diags_USER4, "[+4] ECPY_directConfigure16b> "
                        "Setting OPT.STATIC since this not a 3D Final transfer");
            }
        }
    }
        
    Log_print0(Diags_EXIT, "[+E] ECPY_directConfigure16> Exit");
}

/*
 *  ======== ECPY_directConfigure32 ========
 */
Void ECPY_directConfigure32(ECPY_Handle restrict pHandle,
    ECPY_ParamField32b fieldId, unsigned int value, short transferNo)
{
    IRES_EDMA3CHAN_PaRamStruct * restrict paRam;
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
        (handle->iresHandle);
#else
    ECPY_ScratchObj * iresHandle = handle;
#endif

    Log_print4(Diags_ENTRY, "[+E] ECPY_directConfigure32b> Enter"
            " (handle=0x%x, fieldId=0x%x, value=0x%x, trasnferNo=%d",
            (IArg)handle, (IArg)fieldId, (IArg)value, (IArg)transferNo);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(transferNo > 0, (Assert_Id)NULL);
    Assert_isTrue(transferNo <= iresHandle->assignedNumPaRams, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    paRam = (IRES_EDMA3CHAN_PaRamStruct *)iresHandle->
            assignedPaRamAddresses[transferNo-1];

    *((unsigned int *)((unsigned int)paRam + fieldId)) = value;

    Log_print0(Diags_EXIT, "[+E] ECPY_directConfigure32> Exit");
}

/**
 *  @brief      Indicate that a given transfer will be the last in a sequence
 *              of linked transfers.
 *
 *              This API can be used to dynamically change the number of
 *              transfers in a linked transfers. 
 *
 *  @param[in]  handle      ECPY channel handle.
 *  @param[in]  transferNo  Indicates which transfer that will be the last
 *                          in the set of linked transfers. (This is the same
 *                          value that was passed to ECPY_configure()).
 *
 *  @remarks    This API can be used if a channel was created to
 *              transfer numTransfers linked transfers, but at
 *              some point, it may be that fewer transfers than
 *              numTransfers should be started.
 *
 *  @remarks    This API configures both 'direct' params as well as shadow
 *              paRAMs.
 *
 *  @pre        Valid channel handle.
 *  @pre        Channel must be in 'active' state.
 *
 *  @post       ECPY Handle's state is updated with 'current' last transferNo.
 *  @post       If current 'final' is > previous 'final' transfer, fix the 
 *              link field of the previous 'final' transfer to link to the 
 *              next transfer!
 */
Void ECPY_setFinal(ECPY_Handle pHandle, short transferNo)
{
    IRES_EDMA3CHAN_PaRamStruct *paRamThis;
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj * iresHandle = handle;
#endif

    short numTotalPaRams = iresHandle->assignedNumPaRams; 
    short prevFinal = handle->finalTransferNo;

    Log_print2(Diags_ENTRY, "[+E] ECPY_setFinal> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)(transferNo ));

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(transferNo > 0, (Assert_Id)NULL);
    Assert_isTrue(transferNo <= iresHandle->assignedNumPaRams, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    if (numTotalPaRams == 1) {
        return;
    }

    handle->finalTransferNo = transferNo; /* this xfer becomes the final */

    /*
     *  Reset the link id of the previous transfer that was configured as
     *  final, unless it is the last PaRam allocated to the channel.
     */
    if ( (prevFinal < numTotalPaRams) && (prevFinal != transferNo)) {
     
        IRES_EDMA3CHAN_PaRamStruct *paRamPrevFinal;

        /* If prevFinal was 1st xfer, update the shadow PaRAMs . */
        if (prevFinal == 1) {
            paRamPrevFinal = handle->firstPARAMShadow;

        } else {
            /* modify the assigned Physical PaRAM directly */
            paRamPrevFinal = (IRES_EDMA3CHAN_PaRamStruct *)
                    iresHandle->assignedPaRamAddresses[prevFinal-1];
        }
                
#ifndef _CACHE_IRES
        paRamPrevFinal->link = (unsigned short)
                ECPY_getPaRamLinkIndex(iresHandle, prevFinal);
#else
        paRamPrevFinal->link = (unsigned short)
                ((Uns)(iresHandle->assignedPaRamAddresses[prevFinal]) & 0xFFFF);
#endif

        /* 
         * Make what used to be Final a Linked/Intermediate transfer:
         * Unset TCC_INTEN and STATIC, and Set TCCHEN & TCCMODE
         * NOTE: can't use optLinked directly like the uncommneted assignment
         *       because we don't know if ITCCHEN is 1 or 0 without checking CCNT
         *             paRamPrevFinal->opt = handle->optLinked;
         */
        if (paRamPrevFinal->ccnt > 1) {
            paRamPrevFinal->opt = handle->optLinked | ECPY_PARAMOPTS_ITCCHEN;
        
        } else {
            paRamPrevFinal->opt = handle->optLinked; 
        }
        /* 
         * This makes sure we use the TCCMODE info from the handle's optLinked, 
         * since this may have been modified via ECPY_setEarlyCompletion after the
         * the channel was created
         */
    }

    /* If setting 1st xfer as Final, update the shadow PaRAMs . */
    if (transferNo == 1) {
        paRamThis = handle->firstPARAMShadow;

    } else {
        /* modify the assigned Physical PaRAM directly */
        paRamThis = (IRES_EDMA3CHAN_PaRamStruct *)
                iresHandle->assignedPaRamAddresses[transferNo-1];
    }

    /* Set no link for final PaRam */
    paRamThis->link = 0xffff;

    // /* set the OPT for the final transfer (default=STATIC is OFF) */
    // paRamThis->opt = handle->optFinalStaticOff;
    
    /* 
     * Set this as a Final transfer:
     * Set TCC_INTEN, and UnSet TCCHEN & TCCMODE
     */
    paRamThis->opt |= (ECPY_PARAMOPTS_TCC_INTEN);
    paRamThis->opt &= ~(ECPY_PARAMOPTS_TCCMODE | ECPY_PARAMOPTS_TCCHEN);

    Log_print0(Diags_EXIT, "[+E] ECPY_setFinal> Exit");
}
/*
 * ======== ECPY_directSetFinal ====================
 */
Void ECPY_directSetFinal(ECPY_Handle pHandle, short transferNo)
{
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj * iresHandle = handle; 
#endif

    IRES_EDMA3CHAN_PaRamStruct *paRamThis = (IRES_EDMA3CHAN_PaRamStruct *)
                iresHandle->assignedPaRamAddresses[transferNo-1];
    short numTotalPaRams = iresHandle->assignedNumPaRams; 
    short prevFinal = handle->finalTransferNo;
    

    Log_print2(Diags_ENTRY, "[+E] ECPY_directSetFinal> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)(transferNo ));

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(transferNo > 0, (Assert_Id)NULL);
    Assert_isTrue(transferNo <= iresHandle->assignedNumPaRams, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    if (numTotalPaRams == 1) {
    
        Log_print0(Diags_EXIT, "[+E] ECPY_setFinal> Exit");
        return;
    }

    handle->finalTransferNo = transferNo; /* this xfer becomes the final */

    /*
     *  Reset the link id of the previous transfer that was configured as
     *  final, unless it is the last PaRam allocated to the channel.
     */
    if ( (prevFinal < numTotalPaRams) && (prevFinal != transferNo)) {
     
        IRES_EDMA3CHAN_PaRamStruct *paRamPrevFinal;

        /* modify the assigned Physical PaRAM directly */
        paRamPrevFinal = (IRES_EDMA3CHAN_PaRamStruct *)
                iresHandle->assignedPaRamAddresses[prevFinal-1];
                
#ifndef _CACHE_IRES
        paRamPrevFinal->link = (unsigned short)
                ECPY_getPaRamLinkIndex(iresHandle, prevFinal);
#else
        paRamPrevFinal->link = (unsigned short)
                (Uns)((iresHandle->assignedPaRamAddresses[prevFinal]) & 0xFFFF);
#endif

        /* 
         * Make what used to be Final a Linked/Intermediate transfer:
         * Unset TCC_INTEN and STATIC, and Set TCCHEN & TCCMODE
         * NOTE: can't use optLinked directly like the uncommneted assignment
         *       because we don't know if ITCCHEN is 1 or 0 without checking CCNT
         *       paRamPrevFinal->opt = handle->optLinked;
         */
        if (paRamPrevFinal->ccnt > 1) {
            paRamPrevFinal->opt = handle->optLinked | ECPY_PARAMOPTS_ITCCHEN;
        
        } else {
            paRamPrevFinal->opt = handle->optLinked; 
        }
    }

    /* Set no link for final PaRam */
    paRamThis->link = 0xffff;
 
    /* set the OPT for the final transfer */
    if (paRamThis->ccnt > 1) { 
        /* 3D transfer, so use default, where STATIC bit OFF */
        // paRamThis->opt = handle->optFinalStaticOff;
        /* 
         * Make this a Final transfer:
         * Set TCC_INTEN, and UnSet TCCHEN & TCCMODE
         */
        paRamThis->opt |= (ECPY_PARAMOPTS_TCC_INTEN);
        paRamThis->opt &= ~(ECPY_PARAMOPTS_TCCMODE | ECPY_PARAMOPTS_TCCHEN);

    } else {
        /* set STATIC bit ON, so that single transfers do not thrash 1st PaRAM*/
        /* 
         * Make this a Final transfer:
         * Set TCC_INTEN & STATIC, and UnSet TCCHEN & TCCMODE
         */
        paRamThis->opt |= (ECPY_PARAMOPTS_TCC_INTEN | ECPY_PARAMOPTS_STATIC);
        paRamThis->opt &= ~(ECPY_PARAMOPTS_TCCMODE | ECPY_PARAMOPTS_TCCHEN);
        //paRamThis->opt = handle->optFinalStaticOff | ECPY_PARAMOPTS_STATIC;
    }

    Log_print0(Diags_EXIT, "[+E] ECPY_directSetFinal> Exit");
}

/**
 *  @brief      Submit a single or linked transfer using the most recently
 *              configured transfer parameter settings.
 *
 *  @param[in]  handle   channel handle.
 *
 *  @pre        Valid channel handle.
 *  @pre        Channel must be in 'active' state.
 *  @pre        Channel must be in 'configured' state.
 *
 */
Void ECPY_start(ECPY_Handle pHandle)
{
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj * iresHandle = handle;
#endif

    IRES_EDMA3CHAN_PaRamStruct * restrict paRam;
    IRES_EDMA3CHAN_PaRamStruct * shadow_paRam;
    int i;

    Log_print1(Diags_ENTRY, "[+E] ECPY_start> Enter (handle=0x%x)",
            (IArg)handle);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->transferPending == FALSE, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    /* TODO: optimization. Add a 'useShadow' field in ECPY handle
     * and use shadow based on this flag instead of always! Taking into account
     * setFinal and 3D transfer settings.
     */
     
    /* Always update the 1st transfer's PaRAMs from its shadowParams */
    
    paRam =(IRES_EDMA3CHAN_PaRamStruct *)
            iresHandle->assignedPaRamAddresses[0];
    shadow_paRam = (IRES_EDMA3CHAN_PaRamStruct *)handle->firstPARAMShadow;

    /* Copy first transfer's shadow PaRAM to Phys PaRam registers */
    for (i = 0; i < 8; i++) {
        *((Uns *)paRam + i) = *((Uns *)shadow_paRam + i);
    }
    
    /* Set transferPending indicating a transfer has been submitted */
    handle->transferPending = 1;
    
    /* Manually trigger EDMA transfer by setting the ESR bit corresponding
     * to the EDMA channel 
     */
    *(volatile unsigned int *)handle->esrRegisterAddr = handle->esrBitMask;

    Log_print0(Diags_EXIT, "[+E] ECPY_start> Exit");
}

/**
 *  @brief      Submit a single or linked transfer using the most recently
 *              modified EDMA3 Physical PaRAM transfer parameter settings.
 *
 *  @param[in]  handle   channel handle.
 *
 *  @pre        Valid channel handle.
 *  @pre        Channel must be in 'active' state.
 *  @pre        Channel must be in 'configured' state.
 *
 */
Void ECPY_directStartEdma(ECPY_Handle pHandle)
{
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 


    Log_print1(Diags_ENTRY, "[+E] ECPY_directStartEdma> Enter (handle=0x%x)",
            (IArg)handle);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */
    
    /* 
     * Starts an EDMA manual triggered transfer using the most recent 
     * Physical EDMA PARAM values. If the previous transfer was a Linked
     * transfer, the 1st PARAM must be directConfigure()'ed before calling
     * this function. This functions does not use shadow PaRAMs to retain
     * logical channel PARAM settings.
     */ 

    /* Manually trigger EDMA transfer by setting the ESR bit corresponding
     * to the EDMA channel 
     */
    *(volatile unsigned int *)handle->esrRegisterAddr = handle->esrBitMask;

    Log_print0(Diags_EXIT, "[+E] ECPY_directStartEdma> Exit");
}

/*
 * ECPY_createHandle(IRES_EDMA3CHAN2_Handle handle)
 */
ECPY_Handle ECPY_createHandle(IRES_EDMA3CHAN2_Handle handle, IALG_Handle alg)
{
    ECPY_ScratchObj * scratchHandle = NULL;
    int allocSize = 0;
    int allocatedFromSharedScratch = 0;
    ECPY_Handle ecpyHandle = NULL;
    int scratchId;

    Log_print2(Diags_ENTRY, "[+E] ECPY_createHandle> Enter "
            "(handle=0x%x, ialgHandle=%d)", (IArg)handle, (IArg)(alg ));

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

#endif /* _DEBUG_ defined only for debug profile */
    
    /* First time this API is called we initialize the EDMA3 Static Properties*/
    if (_EDMA3_globalRegs == NULL) {
            _ECPY_initEDMA3CHANStaticProperties(handle);
    }

    /* First create the persistent ECPY_Handle */
    allocSize = sizeof(ECPY_Obj);

    /* Allocate memory for the ECPY handle object */
    if ((ecpyHandle = myAlloc(allocSize, 0)) == NULL) {

        Log_print1(Diags_USER7, "[+7] ECPY_createHandle> "
                   "Could not allocate memory size 0x%x in space "
                   "IALG_EXTERNAL of type IALG_PERSIST", (IArg)allocSize);

        Log_print0(Diags_EXIT, "[+X] ECPY_createHandle> "
                    "Exit (status=NULL)");

        return  (ECPY_Handle) NULL;
    }
    
    /* then create the scratch handle */
#ifndef _CACHE_IRES
    allocSize = sizeof(ECPY_ScratchObj) + sizeof(IRES_EDMA3CHAN_PaRamStruct);
#else
    allocSize = sizeof(ECPY_ScratchObj) + sizeof(IRES_EDMA3CHAN_PaRamStruct) 
                + handle->assignedNumPaRams * sizeof(unsigned int);
#endif

#define MULTI_CHANNEL_SCRATCH_SUPPORT
#ifdef  MULTI_CHANNEL_SCRATCH_SUPPORT

    //scratchId = handle->iprBitMaskH;
    //algHandle = handle->iprBitMaskL;
    if (ECPY_CFG_PARAMS.getScratchIdFxn != NULL) {
        scratchId = ECPY_CFG_PARAMS.getScratchIdFxn((IALG_Handle)alg);
    } 
    else {
        ecpyHandle->scratchId = -1;
        scratchId = -1;
    }
    
    /* if there is an assigned scratch group to alg, try to allocate the 
     * scratchHandle from the shared scratch buffer (past the alg's instance
     * memory). 
     */
    if (scratchId != -1) {
        IALG_MemRec memTab[1];
        
        memTab[0].size = allocSize;
        memTab[0].alignment = 0;
        memTab[0].space = IALG_DARAM0;
        memTab[0].attrs = IALG_SCRATCH;
        memTab[0].base = (void *) NULL;
        
        if (allocatedFromSharedScratch = ECPY_CFG_PARAMS.scratchAllocFxn(
                (IALG_Handle)alg, scratchId, memTab, 1)) {
     
            scratchHandle = memTab[0].base;
            ecpyHandle->scratchId = scratchId;
        }
        else {
            Log_print2(Diags_USER7, "[+7] ECPY_createHandle> "
                   "Could not allocate scratch handle memory size 0x%x in "
                   "shared scratch for scratchId:%d ", 
                   (IArg)allocSize, (IArg)scratchId);

            ecpyHandle->scratchId = -1;
        }
    } 
#endif
    /* 
     * if allocation from shared scratch was succesful, we are done, otherwise
     * allocate the scratchHandle persistently.
     */
    if (!allocatedFromSharedScratch &&
            (scratchHandle = myAlloc(allocSize, 0)) == NULL) {
            
        Log_print1(Diags_USER7, "[+7] ECPY_createHandle> "
                   "Could not allocate scratch handle memory size 0x%x in space"
                   "(IALG_EXTERNAL) ", (IArg)allocSize);

        Log_print0(Diags_EXIT, "[+X] ECPY_createHandle> "
                    "Exit (status=NULL)");

        /* Free memory for the ECPY handle object */
        myFree(ecpyHandle, sizeof(ECPY_Obj));

        return  (ECPY_Handle) NULL;
    } 

    ecpyHandle->iresHandle = handle;
    ecpyHandle->scratchPtr = scratchHandle;

    Log_print0(Diags_EXIT, "[+E] ECPY_createHandle> Exit");

    return ecpyHandle;
}


void _initializeScratchHandle(ECPY_Handle pHandle)
{
    unsigned int channel;
    unsigned int tcc;
    int i;
    ECPY_ScratchObj *ecpyHandle = pHandle->scratchPtr;
    IRES_EDMA3CHAN2_Handle handle = pHandle->iresHandle;
    
    ecpyHandle->iresHandle = pHandle->iresHandle;
    ecpyHandle->firstPARAMShadow =  (IRES_EDMA3CHAN_PaRamStruct *)
                ((unsigned int)ecpyHandle + sizeof(ECPY_ScratchObj));
    
    tcc     = handle->assignedTccIndices[0];
    channel = handle->assignedEdmaChannelIndex;

    /* 
     * For performance optimization: cache the IPR Register, channel-mask
     * and the ESR Register and channel bitmask in the handle.
     */
    if (tcc < 32) {
        ecpyHandle->iprRegisterAddr = (unsigned int)&_EDMA3_globalRegs->IPR;
        ecpyHandle->iprBitMask = (1UL << tcc);
        
    } else {
        ecpyHandle->iprRegisterAddr = (unsigned int)&_EDMA3_globalRegs->IPRH;
        ecpyHandle->iprBitMask = (1UL << (tcc - 32));
    }
     
    if (channel < 32) {
        ecpyHandle->esrRegisterAddr = (unsigned int)&_EDMA3_globalRegs->ESR;
        ecpyHandle->esrBitMask = (1UL << channel);

    } else {
        ecpyHandle->esrRegisterAddr = (unsigned int)&_EDMA3_globalRegs->ESRH;
        ecpyHandle->esrBitMask = (1UL << (channel - 32));
    } 

#ifdef _CACHE_IRES
    ecpyHandle->assignedEdmaChannelIndex = handle->assignedEdmaChannelIndex;
    ecpyHandle->queueMap = (unsigned int *) handle->queueMap;
    ecpyHandle->assignedNumPaRams = handle->assignedNumPaRams;
    ecpyHandle->assignedPaRamAddresses = (unsigned int *)(
            (unsigned int)ecpyHandle + sizeof(IRES_EDMA3CHAN_PaRamStruct) + 
            sizeof(ECPY_ScratchObj));
    for (i = 0; i < ecpyHandle->assignedNumPaRams; i++) {
        ecpyHandle->assignedPaRamAddresses[i] = 
                handle->assignedPaRamAddresses[i];
    }
#endif

    /* 
     * 3D transfers require that intermediate transfer chaining (ITCCHEN)
     * is enabled, but that will be done separately.
     * Linked transfer require  transfer chaining (TCCHEN) is enabled.
     * Set TCCMODE=1 => Early Completion mode, for faster linked transfers as default
     */
    ecpyHandle->optLinked = ECPY_PARAMOPTS_TCCBITS(tcc) |
                     ECPY_PARAMOPTS_TCCMODE | /* enable Early Completion */
                     // ECPY_PARAMOPTS_ITCCHEN | 
                     ECPY_PARAMOPTS_TCCHEN |
                     ECPY_PARAMOPTS_ABSYNC;

    /* 
     * For Final transfers program OPT with the TCC assigned to this channel,
     * enable TCC Interrupt 
     * Default is to keep the STATIC bit 0 to support 3D transfers, 
     * this will be set =1 when it is a non-3D single transfer so that 
     * ECPY_directXXX APIs can reuse the single transfer PaRAMs without having
     * to reconfigure after each directStart.
     * The intermediate TR chaining will be set when needed for 3D.
     */
    ecpyHandle->optFinalStaticOff = ECPY_PARAMOPTS_TCCBITS(tcc) |
                     // ECPY_PARAMOPTS_ITCCHEN      |
                     ECPY_PARAMOPTS_ABSYNC       |
                     ECPY_PARAMOPTS_TCC_INTEN    ;

}

/*
 * ECPY_deleteHandle(ECPY_Handle handle)
 */
Void ECPY_deleteHandle(ECPY_Handle ecpyHandle)
{
    int handleSize;

    IRES_EDMA3CHAN2_Handle iresHandle = NULL;

    Log_print1(Diags_ENTRY, "[+E] ECPY_deleteHandle> Enter "
            "(handle=0x%x)", (IArg)ecpyHandle);

// TODO: free scratch and persistent handles separately ....

#ifdef _DEBUG_
    Assert_isTrue(ecpyHandle != NULL, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    iresHandle = ecpyHandle->iresHandle;

    if ( (ecpyHandle != NULL) && 
         ((ECPY_Handle)iresHandle->shadowPaRams != ecpyHandle)) {

        /* 
         * Free ecpyHandle memory ONLY IF the channel (iresHandle) has NOT
         * been assigned shadow PARAM memory that is 
         * used by ECPY_createHandle to construct the ECPY handle and
         * nothing needs to be freed here.
         */
#ifndef _CACHE_IRES
        handleSize = sizeof(ECPY_ScratchObj) + 
                     sizeof(IRES_EDMA3CHAN_PaRamStruct);
#else
        handleSize = sizeof(ECPY_ScratchObj) + 
                     sizeof(IRES_EDMA3CHAN_PaRamStruct) +
                     iresHandle->assignedNumPaRams * sizeof(unsigned int);
#endif

        /* Free allocates memory for the Scratch ECPY handle object */
        if (ecpyHandle->scratchId == -1) {
            /* free persistently allocated handle */
            myFree(ecpyHandle->scratchPtr, handleSize);
        }
        else {
            /* free shared scratch allocated handle */
            ECPY_CFG_PARAMS.scratchFreeFxn(ecpyHandle->scratchId, 
                    ecpyHandle->scratchPtr, handleSize);
        }
        /* Finally free the persistent ECPY Handle */
        myFree(ecpyHandle, sizeof(ECPY_Obj));
    }

    Log_print0(Diags_EXIT, "[+E] ECPY_deleteHandle> Exit");
}

/*
 * ECPY_activate(ECPY_Handle handle)
 */
Void ECPY_activate(ECPY_Handle pHandle)
{
    unsigned int channel;
    ECPY_ScratchObj *handle = pHandle->scratchPtr;

#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle iresHandle = (IRES_EDMA3CHAN2_Handle)
            (pHandle->iresHandle); // get iresHandle from the persistent handle
#else
    ECPY_ScratchObj *iresHandle = handle;
#endif

    Log_print1(Diags_ENTRY, "[+E] ECPY_activate> Enter "
            "(handle=0x%x)", (IArg)handle);

#ifdef _DEBUG_
    Assert_isTrue(pHandle != NULL, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    /* Initialize scratch Handle using the persistent state + iresHandle */
    _initializeScratchHandle(pHandle);

    channel    = iresHandle->assignedEdmaChannelIndex;
    
    /* Map EDMA3 Channel to the PARAM associated with channel    */ 
    if (channel < 64) {
        _EDMA3_globalRegs->DCHMAP[channel] = 
                iresHandle->assignedPaRamAddresses[0];
    }
    
    /* Check and clear event missed register EMR entry for the channel */
    /* Also Ensure that  ER and SER bits are clear (via ECR and SECR writes. */ 
    if (channel < 32) {
    
        if (*(volatile Uns *)(&_EDMA3_globalRegs->EMR) & (1UL << channel)) {
            Log_print1(Diags_USER4, "[+4] ECPY_activate> WARNING! (EMR) EDMA "
                    "Event Miss detected for (DMA channel=0x%x)",(IArg)channel);
        
            *(volatile Uns *)(&_EDMA3_globalRegs->EMCR) = (1UL << channel); 
        }
        
        if (*(volatile Uns *)(&_EDMA3_globalRegs->ER) & (1UL << channel)) {
            Log_print1(Diags_USER4, "[+4] ECPY_activate> WARNING! (ER) EDMA "
                    "Event Register had to be cleared for (DMA channel=0x%x)", 
                   (IArg)channel);
        
            *(volatile Uns *)(&_EDMA3_globalRegs->ECR) = (1UL << channel); 
        }
        
        if (*(volatile Uns *)(&_EDMA3_globalRegs->SER) & (1UL << channel)) {
            Log_print1(Diags_USER4, "[+4] ECPY_activate> WARNING! (SER) EDMA "
                    "Secondary Event Register reset for (DMA channel=0x%x)", 
                    (IArg)channel);
        
            *(volatile Uns *)(&_EDMA3_globalRegs->SECR) = (1UL << channel); 
        }
        
    } else if (channel < 64) {
    
        if (*(volatile Uns *)(&_EDMA3_globalRegs->EMRH) & (1UL << (channel-32)))
        {
            Log_print1(Diags_USER4, "[+4] ECPY_activate> WARNING! (EMR) EDMA "
                    "Event Miss detected for (DMA channel=0x%x)",(IArg)channel);
        
            *(volatile Uns *)(&_EDMA3_globalRegs->EMCRH)= (1UL << (channel-32)); 
        }
        
        if (*(volatile Uns *)(&_EDMA3_globalRegs->ERH) & (1UL << (channel-32)))
        {
            Log_print1(Diags_USER4, "[+4] ECPY_activate> WARNING! (ER) EDMA "
                    "Event Register had to be cleared for (DMA channel=0x%x)", 
                   (IArg)channel);
        
            *(volatile Uns *)(&_EDMA3_globalRegs->ECRH)= (1UL << (channel-32)); 
        }
        
        if (*(volatile Uns *)(&_EDMA3_globalRegs->SERH) & (1UL << (channel-32)))
        {
            Log_print1(Diags_USER4, "[+4] ECPY_activate> WARNING! (SER) EDMA "
                    "Secondary Event Register reset for (DMA channel=0x%x)", 
                    (IArg)channel);
        
            *(volatile Uns *)(&_EDMA3_globalRegs->SECRH)= (1UL << (channel-32)); 
        }
    }

    /* Enable EDMA3 Channel */
    if (channel < 32) {
        *(volatile Uns *)(&_EDMA3_globalRegs->EESR) = (1UL << channel); 

    } else if (channel < 64) {
        *(volatile Uns *)(&_EDMA3_globalRegs->EESRH) = (1UL << (channel-32)); 
    } 

    Log_print0(Diags_EXIT, "[+E] ECPY_activate> Exit");
    
    /* Initialize transferPending  and finalTransferNo for the channel. */
    handle->transferPending = 0;
    handle->finalTransferNo = iresHandle->assignedNumPaRams;
    
    return;
}

/*
 * ECPY_deactivate(ECPY_Handle handle)
 * 
 * Current implementation does not disable the EDMA3 channels associated with 
 * the handle to avoid race conditions involving shared EDMA channels.
 */
Void ECPY_deactivate(ECPY_Handle handle)
{
    Log_print1(Diags_ENTRY, "[+E] ECPY_deactivate> Enter "
            "(handle=0x%x)", (IArg)handle);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    Log_print0(Diags_EXIT, "[+E] ECPY_deactivate> Exit");
}

/**
 *  @brief      Indicate the memory space that DMA transfers submitted to
 *              the channel associated with the handle will modify.
 *              This information can be used for channel to TC Queue mapping
 *              for avoiding known Silicon GEM lockup issues or for 
 *              performance improvements.
 *
 *  @param[in]  handle  ECPY channel handle.
 *  @param[in]  mode    DMA destination description of type 
 *                      IRES_EDMA3CHAN_DmaDestType.
 */
Void ECPY_setDestinationMemoryMode(ECPY_Handle pHandle, short mode)
{
    volatile unsigned int *dmaqnumRegister; 
    unsigned int *dmaqnum0RegisterAddr = 
           (unsigned int *)&_EDMA3_globalRegs->DMAQNUM[0];
    ECPY_ScratchObj *handle = pHandle->scratchPtr; 

#ifndef _CACHE_IRES
    unsigned int edmaChannelNo = handle->iresHandle->assignedEdmaChannelIndex;
#else
    unsigned int edmaChannelNo = handle->assignedEdmaChannelIndex;
#endif

    unsigned int queueNum = 0;
   
    Log_print2(Diags_ENTRY, "[+E] ECPY_setDestinationMemoryMode> Enter "
            "(handle=0x%x) (mode=%d)", (IArg)handle, (IArg)mode);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */

    /* map the channel to EDMA Queue */

    /*  select the DMAQNUM[i] register, each register mapping 8 channels */
    dmaqnumRegister = dmaqnum0RegisterAddr + (edmaChannelNo >> 3);

    /* get configuration supplied Queue Number using the IRES_EDMA3CHAN2 */
#ifndef _CACHE_IRES
    queueNum = handle->iresHandle->queueMap[mode];
#else
    queueNum = handle->queueMap[mode];
#endif

    /* clear and update the 3 bits corr to the Channel with the Queue number */
    (*dmaqnumRegister) &= ~( 0x0000000F  << (4 * (edmaChannelNo & 0x7))); 
    (*dmaqnumRegister) |= (queueNum << (4 * (edmaChannelNo & 0x7)));

    Log_print2(Diags_USER4, "[+4] ECPY_setDestinationMemoryMode> Map "
            " EDMA Channel: %d to TC Queue: 0x%x",
            (IArg)(edmaChannelNo), (IArg)(queueNum));

    Log_print0(Diags_EXIT, "[+E] ECPY_setDestinationMemoryMode> Exit");
}

/**
 *  @brief      Setting the TCCMODE (Early or Normal) affects only the 'intermediate
 *              transfers' of the linked transfers submitted using this channel.
 *              All subsequent direct and non-direct ECPY_configure* calls
 *              using this ecpyHandle will program the OPT's TCCMODE to select
 *              Early or Normal completion mode based on the 'enabled' argument.
 *
 *              Selecting the Early Completion mode may lead to performance
 *              improvements by increasing the EDMA throughput of linked 
 *              transfers
 *              by submitting each transfer request from the EDMA Channel 
 *              Controller
 *              to the Transfer Controller without waiting for the completion of
 *              the previous transfer from the Transfer Controller.
 *
 *  @param[in]  handle  ECPY channel handle.
 *  @param[in]  enabled 1/TRUE  to set TCCMODE to 1 (Early Completion)
 *                      0/FALSE to set TCCMODE to 1 (Normal Completion)
 *
 *  ======== ECPY_setEarlyCompletionMode ========
 */
Void ECPY_setEarlyCompletionMode(ECPY_Handle pEcpyHandle, short enabled)
{
    ECPY_ScratchObj *ecpyHandle = pEcpyHandle->scratchPtr; 

    Log_print2(Diags_ENTRY, "[+E] ECPY_setEarlyCompletionMode> Enter "
            "(ecpyHandle=0x%x) (enabled=%d)", (IArg)ecpyHandle, (IArg)enabled);
#ifdef _DEBUG_
    Assert_isTrue(ecpyHandle != NULL, (Assert_Id)NULL);
#endif /* _DEBUG_ defined only for debug profile */
            
    if (enabled) {
        ecpyHandle->optLinked |= ECPY_PARAMOPTS_TCCMODE;
    } else {
        ecpyHandle->optLinked &= ~(ECPY_PARAMOPTS_TCCMODE);
    }

    Log_print2(Diags_USER4, "[+4] ECPY_setEarlyCompletionMode> Set "
            "(ecpyHandle=0x%x) Early Completion mode to:%d", 
            (IArg)ecpyHandle,(IArg)enabled);

    Log_print0(Diags_EXIT, "[+E] ECPY_setEarlyCompletionMode> Exit ");
}

/**
 *  @brief              Initialize the ECPY module.  Called by framework.
 */
Void ECPY_init(Void);

/**
 *  @brief              Finalization of the ECPY module.
 */
Void ECPY_exit(Void);


/*@}*/

#ifdef __cplusplus
}
#endif /* extern "C" */

/*
 *  @(#) ti.sdo.fc.ecpy; 1, 0, 1,4; 2-22-2012 18:04:13; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

