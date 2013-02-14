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
 *  @file       ti/sdo/fc/ecpy/ecpy_util.h
 *
 *  @brief      DSP-side ECPY Library utility definitions.
 */

/**
 *  @defgroup   ti_sdo_fc_ecpy_ECPY_UTIL ECPY Utility Module
 *
 *              Utility data structures and functions for the ECPY library.
 */

#ifndef ti_sdo_fc_ecpy_ECPY_UTIL_
#define ti_sdo_fc_ecpy_ECPY_UTIL_

/** @ingroup    ti_sdo_fc_ecpy_ECPY_UTIL */
/*@{*/

/* Definitions are mostly for internal use, but are accessible if needed. */



/*
 * This is used to ensure that routines that were previously compiled
 * with inline ECPY functions are compatible with the current version
 * of ECPY.
 * Therefore, whenever the ECPY code is modified such that it is no
 * longer compatible with the previous inline versions, the final
 * two digits of __ECPY_inlineCompatibilityKey_NN should be incremented.
 * In that way, if in fact the code and version name does change, then
 * code with inline ECPY functions that was previously compiled will
 * show an unresolved reference when linking.  This will indicate
 * an incompatibility.
 */
#define ECPY_INLINE_COMPATIBILITY_KEY_NAME ECPY_inlineCompatibilityKey_01
#define ECPY_VERSION_MACRO    asm (" .ref _ECPY_inlineCompatibilityKey_01"); \
                               ECPY_DIRTY_BITS_VERSION_MACRO

/*
 *  Bits to set in PaRam Register Opts field.
 */
#define ECPY_PARAMOPTS_ABSYNC    (0x1 << 2)  
#define ECPY_PARAMOPTS_TCC_INTEN (0x1 << 20)  
#define ECPY_PARAMOPTS_TCCHEN    (0x1 << 22)
#define ECPY_PARAMOPTS_ITCCHEN   (0x1 << 23)
#define ECPY_PARAMOPTS_STATIC    (0x1 << 3) 
#define ECPY_PARAMOPTS_TCCMODE   (0x1 << 11) 

/* TCC bits in Opts field of PaRam */
#define ECPY_PARAMOPTS_TCCMASK    0x3f000
#define ECPY_PARAMOPTS_TCCSHIFT   12       /* TCC starts at bit 12 of opts */
#define ECPY_PARAMOPTS_TCCBITS(tcc) (tcc << 12)



/**
 *  @brief  ECPY_ScratchObj defines the structure of the dma channel handle 
 *          that is used to manage state about the EDMA3 channel.
 */
typedef struct ECPY_ScratchObj {

    IRES_EDMA3CHAN2_Obj *iresHandle;

#ifdef _CACHE_IRES
    short assignedEdmaChannelIndex;
    short assignedNumPaRams;
    unsigned int * assignedPaRamAddresses;
    unsigned int * queueMap;
#endif /* _CACHE_IRES  */

    unsigned int optLinked;       /* PaRAM's OPT for intermediate transfers */
    unsigned int optFinalStaticOff;   /* PaRAM's OPT for the FINAL transfer */
    unsigned int iprRegisterAddr; /* Interrupt pending register */
    unsigned int iprBitMask;      /* Bit mask contining '1' corr to TCC */
    unsigned int esrRegisterAddr; /* Event Set Register Addr corr to channel */
    unsigned int esrBitMask;      /* Bit mask contining '1' corr to channel */
    short transferPending;        
    short finalTransferNo;        /* TransferNo of the last transfer in a */
                                  /* linked transfer */
    IRES_EDMA3CHAN_PaRamStruct *firstPARAMShadow;

} ECPY_ScratchObj;

/**
 *  @brief  ECPY_Obj defines the structure of the persistent dma channel handle
 *           that is used to manage state about the EDMA3 channel.
 */
typedef struct ECPY_Obj {

    IRES_EDMA3CHAN2_Obj *iresHandle;
    ECPY_ScratchObj     *scratchPtr;
    short scratchId;
} ECPY_Obj;

typedef union {
    struct {
        short    lo16; 
        short    hi16;
    } field;
    unsigned int val32;
} ECPY_Packed32;

/* EDMA3 PaRAM register structure redefined with 32-bit register fields
* for acnt_bcnt, elementIndexes, and frameIndexes.
*/
typedef struct _PaRamStruct {
    unsigned int   opt;
    unsigned int   src;
    ECPY_Packed32  acnt_bcnt;
    unsigned int   dst;
    ECPY_Packed32  elementIndexes;
    unsigned short link;
    unsigned short bCntrld;
    ECPY_Packed32  frameIndexes;
    unsigned short ccnt;
    unsigned short rsvd;
} *PaRamStructPtr;

/*@}*/

#endif  /* ti_sdo_fc_ecpy_ECPY_UTIL_ */
/*
 *  @(#) ti.sdo.fc.ecpy; 1, 0, 1,4; 2-22-2012 18:04:13; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

