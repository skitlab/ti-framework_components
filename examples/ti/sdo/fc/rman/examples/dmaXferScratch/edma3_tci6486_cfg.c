/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */

/*
 * edma3_tci6486_cfg.c
 *
 * EDMA3 Resource Manager Adaptation Configuration File (SoC Specific).
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include <ti/sdo/edma3/rm/edma3_rm.h>

#define NUM_EDMA3_INSTANCES                     1u

/* Driver Object Initialization Configuration */
EDMA3_RM_GblConfigParams myGlobalConfig [NUM_EDMA3_INSTANCES] =
        {
                {
                /** Total number of DMA Channels supported by the EDMA3 Controller */
                64u,
                /** Total number of QDMA Channels supported by the EDMA3 Controller */
                4u,
                /** Total number of TCCs supported by the EDMA3 Controller */
                64u,
                /** Total number of PaRAM Sets supported by the EDMA3 Controller */
                256u,
                /** Total number of Event Queues in the EDMA3 Controller */
                4u,
                /** Total number of Transfer Controllers (TCs) in the EDMA3 Controller */
                4u,
                /** Number of Regions on this EDMA3 controller */
                8u,

                /**
                 * \brief Channel mapping existence
                 * A value of 0 (No channel mapping) implies that there is fixed association
                 * for a channel number to a parameter entry number or, in other words,
                 * PaRAM entry n corresponds to channel n.
                 */
                1u,

                /** Existence of memory protection feature */
                1u,

                /** Global Register Region of CC Registers */
                (void *)0x02A00000u,
                /** Transfer Controller (TC) Registers */
                {
                (void *)0x02A20000u,
                (void *)0x02A28000u,
                (void *)0x02A30000u,
                (void *)0x02A38000u,
                (void *)NULL,
                (void *)NULL,
                (void *)NULL,
                (void *)NULL
                },
                /** Interrupt no. for Transfer Completion */
                15u,
                /** Interrupt no. for CC Error */
                57u,
                /** Interrupt no. for TCs Error */
                {
                59u,
                60u,
                61u,
                62u,
                0u,
                0u,
                0u,
                0u,
                },

                /**
                 * \brief EDMA3 TC priority setting
                 *
                 * User can program the priority of the Event Queues
                 * at a system-wide level.  This means that the user can set the
                 * priority of an IO initiated by either of the TCs (Transfer Controllers)
                 * relative to IO initiated by the other bus masters on the
                 * device (ARM, DSP, USB, etc)
                 */
                {
                0u,
                1u,
                2u,
                3u,
                0u,
                0u,
                0u,
                0u
                },
                /**
                 * \brief To Configure the Threshold level of number of events
                 * that can be queued up in the Event queues. EDMA3CC error register
                 * (CCERR) will indicate whether or not at any instant of time the
                 * number of events queued up in any of the event queues exceeds
                 * or equals the threshold/watermark value that is set
                 * in the queue watermark threshold register (QWMTHRA).
                 */
                {
                16u,
                16u,
                16u,
                16u,
                0u,
                0u,
                0u,
                0u
                },

                /**
                 * \brief To Configure the Default Burst Size (DBS) of TCs.
                 * An optimally-sized command is defined by the transfer controller
                 * default burst size (DBS). Different TCs can have different
                 * DBS values. It is defined in Bytes.
                 */
                {
                64u,
                64u,
                64u,
                64u,
                0u,
                0u,
                0u,
                0u
                },

                /**
                 * \brief Mapping from each DMA channel to a Parameter RAM set,
                 * if it exists, otherwise of no use.
                 */
                {
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP,
        EDMA3_RM_CH_NO_PARAM_MAP, EDMA3_RM_CH_NO_PARAM_MAP
                },

                 /**
                  * \brief Mapping from each DMA channel to a TCC. This specific
                  * TCC code will be returned when the transfer is completed
                  * on the mapped channel.
                  */
                {
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        16u, 17u, 18u, 19u,
        20u, 21u, 22u, 23u,
        24u, 25u, 26u, 27u,
        28u, 29u, 30u, 31u,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP,
        EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP, EDMA3_RM_CH_NO_TCC_MAP
                },

                /**
                 * \brief Mapping of DMA channels to Hardware Events from
                 * various peripherals, which use EDMA for data transfer.
                 * All channels need not be mapped, some can be free also.
                 */
                {
                0xFFFF0000u,
                0x00000000u
                }
                }
        };

EDMA3_RM_InstanceInitConfig overridingConfig [NUM_EDMA3_INSTANCES][EDMA3_MAX_REGIONS] =
{
        {
          {
                /* Resources owned by Region 0 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0xFFFFFFFFu, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x000000FFu, 0x00000000u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000001u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x000000FFu, 0x00000000u},

                /* Resources reserved by Region 0 */
                /* resvdPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFFFFFFu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
        /* 31     0    63     32 */
        {0xFFFF0000u, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
        /* 31     0    63     32 */
        {0xFFFF0000u, 0x00000000u},
          },

          {
                /* Resources owned by Region 1 */
                /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0xFFFFFFFFu,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x0000FF00u, 0x00000000u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000002u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x0000FF00u, 0x00000000u},

                /* Resources reserved by Region 1 */
                /* resvdPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFFFFFFu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
        /* 31     0    63     32 */
        {0xFFFF0000u, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
        /* 31     0    63     32 */
        {0xFFFF0000u, 0x00000000u},
          },

          {
                /* Resources owned by Region 2 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0xFFFFFFFFu, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x00000000u, 0x000000FFu},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000004u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x00000000u, 0x000000FFu},

                /* Resources reserved by Region 2 */
                /* resvdPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFFFFFFu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
        /* 31     0    63     32 */
        {0xFFFF0000u, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
        /* 31     0    63     32 */
        {0xFFFF0000u, 0x00000000u},
          },

          {
                /* Resources owned by Region 3 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x00000000u, 0x0000FF00u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000008u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x00000000u, 0x0000FF00u},

                /* Resources reserved by Region 3 */
                /* resvdPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFFFFFFu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
                /* 31     0     63    32 */
                {0xFFFF0000u, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
                /* 31     0     63    32 */
                {0xFFFF0000u, 0x00000000u},
          },

          {
                /* Resources owned by Region 4 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0xFFFFFFFFu, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x00000000u, 0x00FF0000u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000008u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x00000000u, 0x00FF0000u},

                /* Resources reserved by Region 4 */
                /* resvdPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFFFFFFu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
                /* 31     0     63    32 */
                {0xFFFF0000u, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
                /* 31     0     63    32 */
                {0xFFFF0000u, 0x00000000u},
          },

          {
                /* Resources owned by Region 5 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0xFFFFFFFFu,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x00000000u, 0xFF000000u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000008u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x00000000u, 0xFF000000u},

                /* Resources reserved by Region 5 */
                /* resvdPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFFFFFFu, 0xFFFFFFFFu, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
                /* 31     0     63    32 */
                {0xFFFF0000u, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
                /* 31     0     63    32 */
                {0xFFFF0000u, 0x00000000u},
          },

      {
        /* Resources owned by Region 6 */
         /* ownPaRAMSets */
        /* 31     0     63    32     95    64     127   96 */
        {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 159  128     191  160     223  192     255  224 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 287  256     319  288     351  320     383  352 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 415  384     447  416     479  448     511  480 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

        /* ownDmaChannels */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},

        /* ownQdmaChannels */
        /* 31     0 */
        {0x00000000u},

        /* ownTccs */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},

        /* Resources reserved by Region 6 */
        /* resvdPaRAMSets */
        /* 31     0     63    32     95    64     127   96 */
        {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 159  128     191  160     223  192     255  224 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 287  256     319  288     351  320     383  352 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 415  384     447  416     479  448     511  480 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

        /* resvdDmaChannels */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},

        /* resvdQdmaChannels */
        /* 31     0 */
        {0x00000000u},

        /* resvdTccs */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},
      },

      {
        /* Resources owned by Region 7 */
         /* ownPaRAMSets */
        /* 31     0     63    32     95    64     127   96 */
        {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 159  128     191  160     223  192     255  224 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 287  256     319  288     351  320     383  352 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 415  384     447  416     479  448     511  480 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

        /* ownDmaChannels */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},

        /* ownQdmaChannels */
        /* 31     0 */
        {0x00000000u},

        /* ownTccs */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},

        /* Resources reserved by Region 7 */
        /* resvdPaRAMSets */
        /* 31     0     63    32     95    64     127   96 */
        {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 159  128     191  160     223  192     255  224 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 287  256     319  288     351  320     383  352 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        /* 415  384     447  416     479  448     511  480 */
         0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

        /* resvdDmaChannels */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},

        /* resvdQdmaChannels */
        /* 31     0 */
        {0x00000000u},

        /* resvdTccs */
        /* 31     0     63    32 */
        {0x00000000u, 0x00000000u},
      }
        }
};

/* End of File */
/*
 *  @(#) ti.sdo.fc.rman.examples.dmaXferScratch; 1, 0, 0,4; 2-22-2012 18:07:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

