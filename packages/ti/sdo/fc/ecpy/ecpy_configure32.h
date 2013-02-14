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
 *  ======== ecpy_configure32b.h ========
 */

#ifdef ti_sdo_fc_ecpy_ECPY_

#ifndef ti_sdo_fc_ecpy_ECPY_CONFIGURE32_
#define ti_sdo_fc_ecpy_ECPY_CONFIGURE32_

#include <xdc/std.h>

#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h>
#include <ti/sdo/fc/ecpy/ecpy_util.h>

#ifdef __TI_COMPILER_VERSION__
#if defined(ECPY_CONFIGURE32_INLINE) || defined(ECPY_INLINE_ALL)
ECPY_VERSION_MACRO
static __inline
#endif
#if defined(ECPY_CONFIGURE32_INLINE) || defined(ECPY_INLINE_ALL) || \
    defined(ECPY_CONFIGURE32_IMPLEMENTATION)

/*
 *  ======== ECPY_configure32b ========
 */
Void ECPY_configure32(ECPY_Handle restrict pHandle,
    ECPY_ParamField32b fieldId, unsigned int value, short transferNo)
{
    IRES_EDMA3CHAN_PaRamStruct * restrict paRam;
    ECPY_ScratchObj *handle = pHandle->scratchPtr;
#ifndef _CACHE_IRES
    IRES_EDMA3CHAN2_Handle restrict iresHandle = (IRES_EDMA3CHAN2_Handle)
            (handle->iresHandle);
#else
    ECPY_ScratchObj * restrict iresHandle = handle;
#endif


#if defined(ECPY_CONFIGURE32_IMPLEMENTATION)
    Log_print4(Diags_ENTRY,
            "[+E] ECPY_configure32b> Enter (handle=0x%x, fieldId=0x%x, "
            "value=0x%x, transferNo=%d)",
            (IArg)handle, (IArg)fieldId, (IArg)value, (IArg)transferNo);

#ifdef _DEBUG_
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(transferNo > 0, (Assert_Id)NULL);
    Assert_isTrue(transferNo <= handle->iresHandle->assignedNumPaRams, 
                  (Assert_Id)NULL);
    
#endif /* _DEBUG_ for debug profile */
#endif /* if defined(ECPY_CONFIGURE32_IMPLEMENTATION) */

    /* For transfer #1 always modify the Shadow PaRAM */
    if (transferNo == 1) {
        paRam = (IRES_EDMA3CHAN_PaRamStruct *)handle->firstPARAMShadow;

    } else {
        paRam = (IRES_EDMA3CHAN_PaRamStruct *)
                iresHandle->assignedPaRamAddresses[transferNo-1];
    }

    *((unsigned int *)((unsigned int)paRam + fieldId)) = value;

#if defined(ECPY_CONFIGURE32_IMPLEMENTATION)
    Log_print0(Diags_EXIT, "[+X] ECPY_configure32b> Exit");
#endif

}
#endif /* if defined(ECPY_CONFIGURE32_INLINE) ||
       **    defined(ECPY_INLINE_ALL) ||
       **    defined(ECPY_CONFIGURE32_IMPLEMENTATION)
       */
#endif /* ti_sdo_fc_ecpy_ECPY_CONFIGURE32_ */
#else
#error "ti/sdo/fc/ecpy/ecpy.h must be included first"
#endif
#endif /* __TI_COMPILER_VERSION__ */
/*
 *  @(#) ti.sdo.fc.ecpy; 1, 0, 1,4; 2-22-2012 18:04:12; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

