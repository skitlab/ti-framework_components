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
#include <ti/sdo/fc/edma3/edma3_config.h>

#define DMA_CHANNEL_TO_EVENT_MAPPING_0          (0x0)
#define DMA_CHANNEL_TO_EVENT_MAPPING_1          (0x0)


/* An example configuration that makes all possible EDMA3 resources available 
   for configuration. This is not the typical case. */
EDMA3_InstanceInitConfig ALL_config = {
            /* Resources owned by Region 1 */
            /* ownPaRAMSets */
            {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
            0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
            0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
            0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu},

            /* ownDmaChannels */
            {0xFFFFFFFFu, 0xFFFFFFFF},

            /* ownQdmaChannels */
            {0x000000FFu},

            /* ownTccs */
            {0xFFFFFFFFu, 0xFFFFFFFF},

            /* Resources reserved by Region 1 */
            /* resvdPaRAMSets */
            {0x0u, 0x0u, 0x0u, 0x0u,
            0x0u, 0x0u, 0x0u, 0x0u,
            0x0u, 0x0u, 0x0u, 0x0u,
            0x0u, 0x0u, 0x0u, 0x0u},

            /* resvdDmaChannels */
            {0x0, 0x0},

            /* resvdQdmaChannels */
            {0x0u},

            /* resvdTccs */
            {0x0, 0x0},
};


EDMA3_InstanceInitConfig C6472_config[8] =  {

          {
                /* Resources owned by Region 0 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0xFFFF0000u, 0x00FFFFFFu, 0xFFFFFFFFu, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0x00FF0000u, 0x00000000u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000001u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0x00FF0000u, 0x00000000u},

                /* Resources reserved by Region 0 */
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
        /* 31     0    63     32 */
        {0x0000FFFFu, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
        /* 31     0    63     32 */
        {0x0000FFFFu, 0x00000000u},
          },

          {
                /* Resources owned by Region 1 */
                /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0xFF000000u, 0x0, 0xFFFFFFFFu,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* ownDmaChannels */
                /* 31     0     63    32 */
                {0xFF000000u, 0x00000000u},

                /* ownQdmaChannels */
                /* 31     0 */
                {0x00000002u},

                /* ownTccs */
                /* 31     0     63    32 */
                {0xFF000000u, 0x00000000u},

                /* Resources reserved by Region 1 */
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
        /* 31     0    63     32 */
        {0x0000FFFFu, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
        /* 31     0    63     32 */
        {0x0000FFFFu, 0x00000000u},
          },

          {
                /* Resources owned by Region 2 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x0,
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
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
        /* 31     0    63     32 */
        {0x0000FFFFu, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
        /* 31     0    63     32 */
        {0x0000FFFFu, 0x00000000u},
          },

          {
                /* Resources owned by Region 3 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x0, 0x0000FFFFu, 0x00000000u, 0x00000000u,
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
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
                /* 31     0     63    32 */
                {0x0000FFFFu, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
                /* 31     0     63    32 */
                {0x0000FFFFu, 0x00000000u},
          },

          {
                /* Resources owned by Region 4 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0xFFFF0000u, 0x00FFFFFFu, 0x00000000u,
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
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
                /* 31     0     63    32 */
                {0x0000FFFFu, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
                /* 31     0     63    32 */
                {0x0000FFFFu, 0x00000000u},
          },

          {
                /* Resources owned by Region 5 */
                 /* ownPaRAMSets */
                /* 31     0     63    32     95    64     127   96 */
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0xFF000000u, 0xFFFFFFFFu,
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
                {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 159  128     191  160     223  192     255  224 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 287  256     319  288     351  320     383  352 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                /* 415  384     447  416     479  448     511  480 */
                 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,},

                /* resvdDmaChannels */
                /* 31     0     63    32 */
                {0x0000FFFFu, 0x00000000u},

                /* resvdQdmaChannels */
                /* 31     0 */
                {0x00000000u},

                /* resvdTccs */
                /* 31     0     63    32 */
                {0x0000FFFFu, 0x00000000u},
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
};
/*
 *  @(#) ti.sdo.fc.rman.examples.dmaXferScratch; 1, 0, 0,4; 2-22-2012 18:07:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

