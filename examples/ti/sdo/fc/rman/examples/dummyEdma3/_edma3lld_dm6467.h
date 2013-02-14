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

/** Total number of DMA Channels supported by the EDMA3 Controller */
#define NUM_DMA_CHANNELS                        (64u)
/** Total number of QDMA Channels supported by the EDMA3 Controller */
#define NUM_QDMA_CHANNELS                       (8u)
/** Total number of TCCs supported by the EDMA3 Controller */
#define NUM_TCC                                 (64u)
/** Total number of PaRAM Sets supported by the EDMA3 Controller */
#define NUM_PARAM_SETS                          (512)
/** Total number of Event Queues in the EDMA3 Controller */
#define NUM_EVENT_QUEUE                         (4u)
/** Total number of Transfer Controllers (TCs) in the EDMA3 Controller */
#define NUM_TC                                  (4u)
/** Number of Regions on this EDMA3 controller */
#define NUM_REGION                              (8u)

/**
 * \brief Channel mapping existence
 * A value of 0 (No channel mapping) implies that there is fixed association
 * for a channel number to a parameter entry number or, in other words,
 * PaRAM entry n corresponds to channel n.
 */
#define CHANNEL_MAPPING_EXISTENCE               (1u)
/** Existence of memory protection feature */
#define MEM_PROTECTION_EXISTENCE                (0u)

/** Global Register Region of CC Registers */
#define CC_BASE_ADDRESS                         (0x01C00000u)
/** Transfer Controller 0 Registers */
#define TC0_BASE_ADDRESS                        (0x01C10000u)
/** Transfer Controller 1 Registers */
#define TC1_BASE_ADDRESS                        (0x01C10400u)
/** Transfer Controller 2 Registers */
#define TC2_BASE_ADDRESS                        (0x01C10800u)
/** Transfer Controller 3 Registers */
#define TC3_BASE_ADDRESS                        (0x01C10C00u)
/** Transfer Controller 4 Registers */
#define TC4_BASE_ADDRESS                        NULL
/** Transfer Controller 5 Registers */
#define TC5_BASE_ADDRESS                        NULL
/** Transfer Controller 6 Registers */
#define TC6_BASE_ADDRESS                        NULL
/** Transfer Controller 7 Registers */
#define TC7_BASE_ADDRESS                        NULL

/** Interrupt no. for Transfer Completion */
#define XFER_COMPLETION_INT                     (84u)
/** Interrupt no. for CC Error */
#define CC_ERROR_INT                            (85u)
/** Interrupt no. for TC 0 Error */
#define TC0_ERROR_INT                           (86u)
/** Interrupt no. for TC 1 Error */
#define TC1_ERROR_INT                           (87u)
/** Interrupt no. for TC 2 Error */
#define TC2_ERROR_INT                           (88u)
/** Interrupt no. for TC 3 Error */
#define TC3_ERROR_INT                           (89u)
/** Interrupt no. for TC 4 Error */
#define TC4_ERROR_INT                           (0u)
/** Interrupt no. for TC 5 Error */
#define TC5_ERROR_INT                           (0u)
/** Interrupt no. for TC 6 Error */
#define TC6_ERROR_INT                           (0u)
/** Interrupt no. for TC 7 Error */
#define TC7_ERROR_INT                           (0u)

/**
 * \brief Mapping of DMA channels 0-31 to Hardware Events from
 * various peripherals, which use EDMA for data transfer.
 * All channels need not be mapped, some can be free also.
 * 1: Mapped
 * 0: Not mapped
 *
 * This mapping will be used to allocate DMA channels when user passes
 * EDMA3_RM_DMA_CHANNEL_ANY as dma channel id (for eg to do memory-to-memory
 * copy). The same mapping is used to allocate the TCC when user passes
 * EDMA3_RM_TCC_ANY as tcc id (for eg to do memory-to-memory copy).
 *
 * To allocate more DMA channels or TCCs, one has to modify the event mapping.
 */
#define DMA_CHANNEL_TO_EVENT_MAPPING_0          (0x3DFF0FFCu)
/**
 * \brief Mapping of DMA channels 32-63 to Hardware Events from
 * various peripherals, which use EDMA for data transfer.
 * All channels need not be mapped, some can be free also.
 * 1: Mapped
 * 0: Not mapped
 *
 * This mapping will be used to allocate DMA channels when user passes
 * EDMA3_RM_DMA_CHANNEL_ANY as dma channel id (for eg to do memory-to-memory
 * copy). The same mapping is used to allocate the TCC when user passes
 * EDMA3_RM_TCC_ANY as tcc id (for eg to do memory-to-memory copy).
 *
 * To allocate more DMA channels or TCCs, one has to modify the event mapping.
 */
#define DMA_CHANNEL_TO_EVENT_MAPPING_1          (0x007F1FFFu)

/*
 *  @(#) ti.sdo.fc.rman.examples.dummyEdma3; 1, 0, 0,4; 2-22-2012 18:07:43; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

