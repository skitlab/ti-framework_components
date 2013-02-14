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
 *  @file       ti/sdo/fc/ires/sdma/iresman_protocol_sdma.h
 *
 *  @brief      IRESMAN PROTOCOL SDMA Interface Definitions -
 *              Interface exposed to the device specific IRESMAN layer used to
 *              construct and destruct handles representing the resource
 */

#ifndef ti_sdo_fc_ires_sdma_iresman_protocol_sdma_
#define ti_sdo_fc_ires_sdma_iresman_protocol_sdma_


#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup    DSPIRESMANPROTSDMA */
/*@{*/


#include <ti/sdo/fc/ires/iresman_protocol.h>

/*
 * @brief           Arguments that are passed from the IRES Resource manager
 *                  to intialize the handle
 */
typedef struct IRES_SDMA_ConstructHandleArgs {

    IRESMAN_ConstructArgs args;

    Int32 persistent;

} IRES_SDMA_ConstructHandleArgs;


/*
 * Interface to expose to the resource manager to be able to construct handles
 */
extern IRESMAN_ConstructFxns IRESMAN_SDMA_CONSTRUCTFXNS;

/*@}*/ /** @ingroup    DSPIRESPROTSDMA */


#ifdef __cplusplus
}
#endif


#endif
/*
 *  @(#) ti.sdo.fc.ires.sdma; 1, 0, 0,4; 2-22-2012 18:06:31; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

