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
 *  ======== dman3_initImpl.c ========
 *  Initialize the DMAN3 module
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_dman3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/knl/GateProcess.h>
#include <xdc/runtime/Registry.h>

#include <string.h> /* For memset() */

#include <ti/sdo/fc/utils/osalsupport/OsalSupport.h>
#include <ti/sdo/fc/global/FCSettings.h>

#include "rmm.h"
#include "_rmm.h"
#include "dman3.h"
#include "dman3_impl.h"


#ifdef xdc_target__os_Linux
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>

#define SHMSIZE 0x4000      /* Size of shared memory chunk to allocate */

#endif

#ifdef __TI_COMPILER_VERSION__
#pragma CODE_SECTION(_DMAN3_initImpl, ".text:DMAN3_init");
#endif


/*
 *  QCHMAP: Queue to channel map register which specifies which parameter
 *  entry in bits 13-5 and the trigger word (which is word 7 in ACPY3
 *  implementation), in bits 4-2.
 */
//#define QCHMAP ((volatile Uns *)(0x01c00200))

// TODO: These 2 defines will go away with EDMA3 regs structures
#define QCHMAPOFFSET 0x200
#define PARAMOFFSET 0x4000
#define PARAMENTRYSIZE 8  /* Number of words in PaRam entry */

/* Byte offsets of QDMA registers */
#define QDMAQNUMOFFSET  0x0260
#define QUETCMAPOFFSET  0x0280
#define QUEPRIOFFSET    0x0284
#define QRAE0OFFSET     0x0380
#define QEESROFFSET     0x108C

/* Sizes of EDMA3 register and PaRam regions to map */
#define EDMA3REGSIZE 0x2000
#define PARAMREGSIZE 0x800

/* Align on 4-byte boundary */
#define ALIGN32(x) ((((UInt32)(x) + 3) / 4) * 4)

/* For putting offsets into shared data area rather than addresses */
#define OFFSET(base, address) ((UInt32)address - (UInt32)base)

/* Status of _DMAN3_initImpl */
Int _DMAN3_initStatus = DMAN3_EFAIL;

static int      refCount = 0;   /* Process reference count */
_DMAN3_Data *_DMAN3_data;
UInt32 _DMAN3_qdmaBase[DMAN3_MAXGROUPS + 1];


#ifdef xdc_target__os_Linux

static Void freeDman3Obj();
static Bool getDman3Obj();
static Void unMapShm();

#ifndef _DMAN3_CPUCOPY_
static int      memfd;          /* File discriptor for "/dev/mem" */
#endif

static Int      shmId;          /* Shared memory id */
#endif /* xdc_target__os_Linux */

static Void    *shmBase = NULL; /* Base address of shared memory chunk */
static Void    *shmFreeBase;    /* Next available location in shared memory */
static UInt32   shmSize;

static xdc_runtime_IHeap_Handle heapInt;
static xdc_runtime_IHeap_Handle heapExt;

UInt32          *_DMAN3_paRamAddr = NULL;
UInt32          *_DMAN3_edma3Addr = NULL;
UInt32          _DMAN3_nullPaRam = 0x0;
UInt32          _DMAN3_maxAssignedTcc = -1;

IGateProvider_Handle DMAN3_gate = NULL;

/*
 *  Functions for allocating and freeing from the shared memory block.
 */
static Void *shmAlloc(UArg segid, UInt32 size, UInt32 align);
static Bool shmFree(UArg segid, Void *addr, UInt32 size);

static Int getNumAssignedTccs(UInt32 mask32b, UInt32 * maxTcNumber);
static Void updateTccAllocationTable(UInt32 mask32b, Int base);
static Void initQdmaConfiguration();
static Bool checkDMAN3SocConfiguration();

static Int regInit = 0;  /* Registry_addModule() called */

Registry_Desc ti_sdo_fc_dman3_desc;

/*
 *  ======== _DMAN3_initImpl ========
 *  Initialize the DMAN module
 */
Void _DMAN3_initImpl(Void)
{
    RMM_Attrs       rmmAttrs;
    Int             i;
#ifndef _DMAN3_CPUCOPY_
    volatile Uns   *qchmap;
    Uns            *paRam;
#endif
    Int             rmmSize;
    Int             numTccs;
//    IArg            key;
    UInt32          maxId = 0x0;
    UInt32          tempNum = 0x0;
#ifndef _DMAN3_CPUCOPY_
    UInt32          chipTccs = 0x0;
    UInt32          cccfg = 0x0;
#endif
    UInt32          totalQdmas = 0;
    Registry_Result regResult;

    /* Protect DMAN3 data */
//    key = Gate_enterModule();
//    key = IGateProvider_enter(DMAN3_gate);

    /*
     *  Register the module name for logging only once. Do this before any
     *  Log functions are called.
     */
    if (regInit == 0) {
        regResult = Registry_addModule(&ti_sdo_fc_dman3_desc, DMAN3_MODNAME);

        Assert_isTrue(regResult == Registry_SUCCESS, (Assert_Id)NULL);

        /* Set diags mask to FC default */
        FCSettings_init();
        FCSettings_setDiags(DMAN3_MODNAME);
        regInit = 1;
    }

    Log_print0(Diags_ENTRY, "[+E] _DMAN3_initImpl> Enter");

    if (refCount++ == 0) {
        Log_print0(Diags_ENTRY, "[+2] _DMAN3_initImpl> Entering DMAN3 first "
                "time in this proces, creating gate\n");
        DMAN3_gate = OsalSupport_createGate(_DMAN3_GATEID);
        if (DMAN3_gate == NULL) {
            Log_print0(Diags_USER7, "[+7] _DMAN3_initImpl> Failed to create "
                       "gate");
            _DMAN3_initStatus = DMAN3_EOUTOFMEMORY;
            return;
        }

        heapInt = DMAN3_PARAMS.heapInternal;
        heapExt = DMAN3_PARAMS.heapExternal;

        heapInt = (heapInt == NULL) ? heapExt : heapInt;
        heapExt = (heapExt == NULL) ? heapInt : heapExt;

        Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> heapInt set to %d\n",
                (Int)heapInt);

#ifndef xdc_target__os_Linux
        /* This is a fatal configuration error for non-Linux os. */
        Assert_isTrue(heapInt != NULL, (Assert_Id)NULL);
#endif
        /*
         *  First, need to know how many TCCs are used.
         */
        numTccs = getNumAssignedTccs(DMAN3_PARAMS.tccAllocationMaskH,
                &tempNum);

        /*
         * Calculate the maximum Id of the tcc allocated. What is returned is
         * the highest (Tcc number +1) that was configured for DMAN3
         */
        if (tempNum > 0) {
            /* Adjust this number by 32 since this is the "H" mask */
            maxId = (tempNum - 1) + 32;
        }
        numTccs += getNumAssignedTccs(DMAN3_PARAMS.tccAllocationMaskL,
                &tempNum);

        /*
         * If the H mask was zero (and hence maxId was 0), then use this
         * returned number to figure out maxId
         */
        if (maxId == 0) {
            maxId = tempNum - 1;
        }

        _DMAN3_maxAssignedTcc = maxId;

        /*
         *  We need to compute the size of the memory chunk that will hold
         *  _DMAN3_data and RMM objects. To compute the amount of memory
         *  needed by RMM, we can do 'dummy' creates of the RMM objects that
         *  will manage the TCCs and PaRams.
         */
        rmmSize = 2 * sizeof(RMM_Obj) + sizeof(RMM_Header) *
            ((DMAN3_PARAMS.numPaRamEntries + 1) / 2 + (numTccs + 1) / 2);

#ifdef xdc_target__os_Linux
        /* Allocate the _DMAN3_data object for Linux */
        if (!getDman3Obj()) {
            _DMAN3_initStatus = DMAN3_EOUTOFMEMORY;
            return;
        }

#ifndef _DMAN3_CPUCOPY_
        /* Map the DMA registers */
        memfd = open("/dev/mem", O_RDWR | O_SYNC);
        if (memfd == NULL) {
            Log_print0(Diags_USER7, "[+7] _DMAN3_initImpl> "
                    "open(\"/dev/mem\" failed!");
            _DMAN3_initStatus = DMAN3_EFAIL;
            return;
        }

        _DMAN3_paRamAddr = mmap(0, PARAMREGSIZE, PROT_READ | PROT_WRITE,
                MAP_SHARED, memfd, (off_t)DMAN3_PARAMS.qdmaPaRamBase);

        _DMAN3_edma3Addr = mmap(0, EDMA3REGSIZE,
                PROT_READ | PROT_WRITE, MAP_SHARED, memfd,
                (off_t)((UInt32)DMAN3_PARAMS.qdmaPaRamBase - PARAMOFFSET));
#endif

#else
#ifdef _YOUR_TARGET_
        /*
         *  TODO: Allocate a block of memory for the _DMAN3_data object and
         *  other data that will be placed after the _DMAN3_data object. The
         *  size should be at least:
         *      sizeof(_DMAN3_Data) + rmmSize.
         *
         *  TODO: Set shmSize to the size of the allocated block.
         *  TODO: Set shmBase to the base address of the allocated block.
         *
         *  TODO: Set _DMAN3_data to the beginning of the allocated block,
         *        but make sure it is aligned on a 32 bit boundary.
         *
         *  TODO: Set shmFreeBase to the address of the first word after
         *        _DMAN3_data (see code below for an example).
         */

        /*
         *  TODO: Initialize _DMAN3_paRamAddr to the virtual or physical
         *  address of DMAN3_PARAMS.qdmaPaRamBase.
         */

        /*
         *  TODO: Initialize _DMAN3_edma3Addr to the virtual or physical
         *  address of (UInt32)DMAN3_PARAMS.qdmaPaRamBase - PARAMOFFSET.
         */
#else
        /*
         *  Allocate a block of memory for the _DMAN3_data object and
         *  other data that will be placed after the _DMAN3_data object. The
         *  size should be at least:
         *      sizeof(_DMAN3_Data) + rmmSize
         *  but we will add a little extra to be safe.
         */
        shmSize = sizeof(_DMAN3_Data) + rmmSize + 32;
        _DMAN3_data = (_DMAN3_Data *)Memory_calloc(DMAN3_PARAMS.heapExternal,
                shmSize, 0, NULL);
        if (_DMAN3_data == NULL) {
            Log_print0(Diags_USER7, "[+7] _DMAN3_initImpl> Memory allocation "
                    "of _DMAN3_data failed!");
            _DMAN3_initStatus = DMAN3_EOUTOFMEMORY;
            return;
        }

        /* Set shmBase to the base address of the allocated block. */
        shmBase = (Void *)_DMAN3_data;

        /* Make sure the shared memory base is aligned */
        shmFreeBase = (Void *)((UInt32)shmBase + ALIGN32(sizeof(_DMAN3_Data)));

        /* Start address of PaRams */
        _DMAN3_paRamAddr = DMAN3_PARAMS.qdmaPaRamBase;

        /* Start address of EDMA3 registers */
        _DMAN3_edma3Addr = (UInt32 *)((UInt32)DMAN3_PARAMS.qdmaPaRamBase -
                PARAMOFFSET);

#endif
#endif /* #ifdef xdc_target__os_Linux */

#ifndef _DMAN3_CPUCOPY_
        cccfg =  *(((volatile Uns *)_DMAN3_edma3Addr)+1);
        chipTccs = ( (( ((cccfg)>>8)&0x7)==0) ? 0 :
                        (0x4 << (((cccfg)>>8) & 0x7)) );
        if (maxId >= chipTccs) {

                Log_print2(Diags_USER6, "[+6] "
                        "_DMAN3_initImpl> DMAN3 tccAllocationMaskH configures tcc "
                        "%d, that is more than available on hardware %d\n",
                        maxId , numTccs);

                _DMAN3_initStatus = DMAN3_EFAIL;
                /* Error condition */
                return;
                }
#endif
    }

    Log_print0(Diags_ENTRY, "[+2] _DMAN3_initImpl> Entering DMAN3. Reference "
            "count non-zero\n");

    if (_DMAN3_refCount++ == 0) {
        /* Initialize to _DMAN3_data object */

#if !defined(xdc_target__isaCompatible_64P)
        /*
         *  Scratch env not supported for non-64P compatible targets
         *  (eg, v5T, 64T)
         */
        _DMAN3_allocScratch = NULL;
        _DMAN3_freeScratch = NULL;
#else
        /* 64P compatible target (eg, 64P, 674) */
        /*
         *  Configured function for allocating IDMA3 object's env from
         *  shared scratch memory.
         */
        _DMAN3_allocScratch = DMAN3_PARAMS.scratchAllocFxn;

        /*
         *  Configured function for allocating IDMA3 object's env from
         *  shared scratch memory.
         */
        _DMAN3_freeScratch = DMAN3_PARAMS.scratchFreeFxn;

        /*
         *  If one of _DMAN3_allocScratch or _DMAN3_freeScratch is NULL,
         *  then the other must be NULL.
         */
        Log_print2(Diags_USER2, "[+2] _DMAN3_initImpl> Checkng validity of "
                " _DMAN3_allocScratch %d and _DMAN3_freeScratch %d\n",
                (Int)_DMAN3_allocScratch,(Int)_DMAN3_freeScratch);

        Assert_isTrue((_DMAN3_allocScratch != NULL) ||
                (_DMAN3_freeScratch == NULL), (Assert_Id)NULL);
        Assert_isTrue((_DMAN3_freeScratch != NULL) ||
                (_DMAN3_allocScratch == NULL), (Assert_Id)NULL);
#endif

        /*
         * Initialize the tccAllocationTable with the provided TCCs.
         * Use the TCCs assigned in the High range (32-63) first, then
         * Low (0-31) when initializing the _DMAN3_tccAllocationTable.
         * Update the total number of assigned TCC count
         * (_DMAN3_numAssignedTccs)
         */
        _DMAN3_numAssignedTccs = 0;
        updateTccAllocationTable(DMAN3_PARAMS.tccAllocationMaskH, 32);
        updateTccAllocationTable(DMAN3_PARAMS.tccAllocationMaskL, 0);

        /*
         *  Initialize _DMAN3_heapInt and _DMAN3_heapExt with provided
         *  heaps. Use internal heap for _DMAN3_heapInt when provided.
         *  (Actually this is a fatal error if ACPY3 uses internal DMA
         *  (IDMA) to write to PARAMs.
         */
        _DMAN3_heapInt = heapInt;
        _DMAN3_heapExt = heapExt;
        _DMAN3_heapIdma3 = (DMAN3_PARAMS.idma3Internal) ?
            _DMAN3_heapInt : _DMAN3_heapExt;


        for (i = 0; i < DMAN3_MAXGROUPS; i++) {
            _DMAN3_numTccGroup[i] = DMAN3_PARAMS.numTccGroup[i];
            _DMAN3_numPaRamGroup[i] = DMAN3_PARAMS.numPaRamGroup[i];
        }

        /* Initialize _DMAN3_data->context[] to offsets in shared memory */
        for (i = 0; i < DMAN3_MAXGROUPS; i++) {
            _DMAN3_data->context[i] = OFFSET(_DMAN3_data,
                    &(_DMAN3_data->contextObjs[i]));
        }

        /*
         *  Attributes of TCC array that will be managed by RMM for
         *  allocation:
         *    segid - Use the external memory for the RMM object.
         *    base = 0 - We allocate indices of the array, starting with 0
         *    length = _DMAN3_numAssignedTccs - the number of TCCs in the array
         *    maxFreeListBlocks - Set to maximum number of free (unallocated)
         *        blocks that the array can fragment into. This happens when
         *        every other index is free.
         */
        rmmAttrs.segid = (UArg)NULL;
        rmmAttrs.base = 0;
        rmmAttrs.length = _DMAN3_numAssignedTccs;
        rmmAttrs.maxFreeListBlocks = (_DMAN3_numAssignedTccs + 1) / 2;
        rmmAttrs.allocFxn = shmAlloc;
        rmmAttrs.freeFxn = shmFree;

        /*
         *  Can't put a pointer in shared memory area if it's shared by
         *  different processes. Therefore, we store the offset from the
         *  _DMAN3_data.
         */
        _DMAN3_data->rmmTccs = OFFSET(_DMAN3_data, RMM_create(&rmmAttrs));

        Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> _DMAN3_data->rmmTccs = "
                "%d\n", _DMAN3_data->rmmTccs);

        Assert_isTrue(_DMAN3_rmmTccs != NULL, (Assert_Id)NULL);

        /*
         *  Attributes of PaRam entry numbers that will be managed by RMM for
         *  allocation:
         *    segid - Use the external memory for the RMM object.
         *    base - The first PaRam index for DMAN3.
         *    length - Number of PaRam entries for DMAN3.
         *    maxFreeListBlocks - Set to maximum number of free (unallocated)
         *        blocks that can PaRam indices can fragment into. This
         *        happens when every other index is free.
         */
        rmmAttrs.base = DMAN3_PARAMS.paRamBaseIndex;
        rmmAttrs.length = DMAN3_PARAMS.numPaRamEntries;
        rmmAttrs.maxFreeListBlocks = (DMAN3_PARAMS.numPaRamEntries + 1) / 2;

        _DMAN3_data->rmmPaRams = OFFSET(_DMAN3_data, RMM_create(&rmmAttrs));

        Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> _DMAN3_data->rmmPaRams ="
                " %d\n", _DMAN3_data->rmmPaRams);

        Assert_isTrue(_DMAN3_rmmPaRams != NULL, (Assert_Id)NULL);

                //TODO: Distribute channels among scratch groups
        totalQdmas = 0;

        if (ti_sdo_fc_dman3_DMAN3_useCustomDma) {

                for (i =0; i < DMAN3_MAXGROUPS; i++) {

            //_DMAN3_data->qdmaGroupNum[i] =
            //        ti_sdo_fc_dman3_DMAN3_numQdmaGroup[i];

                if (_DMAN3_numQdmaGroup(i) > 0 ) {
                        Assert_isTrue(totalQdmas < DMAN3_PARAMS.numQdmaChannels,
                                                        (Assert_Id)NULL);

                                        /* Set the allocation base for each scratch group */
                        _DMAN3_qdmaBase[i] = totalQdmas;

                                //_DMAN3_data->qdmaGroupBase[i] = totalQdmas;
                //_DMAN3_data->qdmaGroupCounter[i] =
                 //       _DMAN3_data->qdmaGroupBase[i];
                }
                else {
                        //TODO: Should this be set to "0" ?
                        _DMAN3_qdmaBase[i] = -1;
                                        //_DMAN3_data->qdmaGroupBase[i] = -1;
                        //_DMAN3_data->qdmaGroupCounter[i] = -1;
                }
                totalQdmas += _DMAN3_numQdmaGroup(i);
                }

                /* Leave the rest of the QDMA channels (if any) to scratch group -1 */
                _DMAN3_data->qdmaPersistentNum =
                        DMAN3_PARAMS.numQdmaChannels - totalQdmas;
                        _DMAN3_data->qdmaPersistentBase = totalQdmas;

                //_DMAN3_data->qdmaGroupBase[DMAN3_MAXGROUPS] = totalQdmas;
        }
        else {
                for (i =0; i < DMAN3_MAXGROUPS; i++) {
                _DMAN3_qdmaBase[i] = 0;
                ti_sdo_fc_dman3_DMAN3_numQdmaGroup[i] =
                            DMAN3_PARAMS.numQdmaChannels;
                        //_DMAN3_data->qdmaGroupBase[i] = 0;
            //_DMAN3_data->qdmaGroupNum[i] = DMAN3_PARAMS.numQdmaChannels;
            //_DMAN3_data->qdmaGroupCounter[i] = i;
                }
                _DMAN3_data->qdmaPersistentNum = DMAN3_PARAMS.numQdmaChannels;
                        _DMAN3_data->qdmaPersistentBase = 0;

                }
         _DMAN3_nullPaRam = DMAN3_PARAMS.nullPaRamIndex;

         Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> Null PaRam is %d",
                 (IArg)_DMAN3_nullPaRam);

#ifndef _DMAN3_CPUCOPY_
        /* Set qchmap to address of first QCHMAP register */
        qchmap = (volatile Uns *)((Uns)_DMAN3_edma3Addr + QCHMAPOFFSET);

        /*
         *  Set the trigger word of each QDMA channel to 7, so that when we
         *  set the static bit (of opts field of PaRam which is word 0) of the
         *  null PaRam, we don't start a transfer, in case the QCHMAP register
         *  happened to have the null PaRam with trigger word 0.
         *
         *  Note:-
         *  Even though all channels might not be owned by DMAN3, we are
         *  setting the static bit of ALL QDMA channels that are mapped to
         *  paRam 0. This is because QDMA channels on bring up point to paRam 0
         *  by default. Even if they aren't owned by DMAN3, not changing their
         *  trigger words, might cause extraneous transfers when setting the
         *  static bit of the OPT field of paRam 0.
         *  Since paRam 0 is owned by DMAN3, ideally no QDMA channels belonging
         *  to other frameworks should point to PaRam 0
         */
        for (i = 0; i < DMAN3_PARAMS.maxQdmaChannels; i++) {
            if (_DMAN3_nullPaRam == ((*qchmap >> 5 ) & 0x1FF)) {
                Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> "
                        "Qdma channel %d is pointing to the nullPaRam. Change "
                        "its trigger word bit to 0x7 so it doesn't get "
                        "triggered when we modify the null PaRam", (IArg)i);
                *qchmap = *qchmap | (0x7 << 2);
            }
            qchmap++;
        }

        /*
         *  Set the static bit of opts field of the null PaRam, since
         *  QCHMAP may get set to this PaRam when the channel is
         *  activated/deactivated. (The opts field is the first word of the
         *  PaRam entry).
         */
        paRam = (Uns *)((Uns)_DMAN3_paRamAddr +
                (_DMAN3_nullPaRam * PARAMENTRYSIZE * sizeof(UInt32)));

        Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> "
                "Setting static bit of null paRam (address = 0x%x)",
                (IArg)paRam);
        *paRam |= 0x8;
#endif

        Log_print0(Diags_USER2, "[+2] _DMAN3_initImpl> Now checking DMAN3 "
                "SOC configuration\n");
        if (FALSE == checkDMAN3SocConfiguration()) {
           Log_print0(Diags_USER6, "[+6] _DMAN3_initImpl> "
                   "DMAN3 SOC-specific configuration different from hardware, "
                   "continuing with configured values");
        }

        Log_print0(Diags_USER2, "[+2] _DMAN3_initImpl> Now initializing DMAN3 "
                "QDMA configuration\n");
        initQdmaConfiguration();

        /* Initialization successful */
        _DMAN3_initStatus = DMAN3_SOK;
    }

//    Gate_leaveModule(key);
    //IGateProvider_leave(DMAN3_gate, key);

    Log_print1(Diags_EXIT, "[+X] _DMAN3_initImpl> Exiting, _DMAN3_data = 0x%x",
            (IArg)_DMAN3_data);

    Log_print0(Diags_EXIT, "[+X] _DMAN3_initImpl> Exit");
}

/*
 *  ======== DMAN3_exit ========
 *  Finalization method of the DMAN3 module
 */
Void DMAN3_exit(Void)
{
    IArg     key;

    Log_print0(Diags_ENTRY, "[+E] DMAN3_exit> Enter");

    --refCount;

    if (_DMAN3_initStatus != DMAN3_SOK) {
        /* Clean up what there is */
        if (DMAN3_gate) {
            OsalSupport_deleteGate(DMAN3_gate);
            DMAN3_gate = NULL;
        }

        return;
    }

    key = IGateProvider_enter(DMAN3_gate);

    if (--_DMAN3_refCount == 0) {
        /*
         *  The global DMAN3 reference count is 0, ie, no other processes
         *  are using DMAN3.
         */
        /* No need to free RMM handles, since they are just offsets */

#ifdef xdc_target__os_Linux
        freeDman3Obj();
#else
#ifdef _YOUR_TARGET_
        /*
         *  TODO: Free the block allocated in DMAN3_initImpl() for
         *  _DMAN3_data
         */
#else
        /* Free _DMAN3_data */
        Memory_free(_DMAN3_heapExt, _DMAN3_data, shmSize);
#endif
#endif
        shmFreeBase = shmBase = NULL;
    }
    else {
        if (refCount == 0) {
            /* Only this process's refCount has gone to 0. */
#ifdef xdc_target__os_Linux
            /* Detach from the shared memory, unmap DMA registers */
            unMapShm();
#endif
#ifdef _YOUR_TARGET_
            /* TODO: Any cleanup that may be needed at this point */
#endif
            shmFreeBase = shmBase = NULL;
        }
    }

//    Gate_leaveModule(key);
    IGateProvider_leave(DMAN3_gate, key);

    Log_print0(Diags_EXIT, "[+X] DMAN3_exit> Exit");
}

/*
 *  ======== getNumAssignedTccs ========
 */
static Int getNumAssignedTccs(UInt32 mask32b, UInt32 * maxTcc)
{
    Int numTccs = 0;
    Int i;

    *maxTcc = 0x0;

    Log_print0(Diags_ENTRY, "[+E] getNumAssignedTccs> Enter");

    for (i = 0; i < 32; i++) {
        if (mask32b & (0x1 << i)) {
            numTccs++;
            *maxTcc = i+1;
        }
    }

    Log_print1(Diags_USER4, "[+4] getNumAssignedTccs> Max TCC is 0x%x",
            (IArg)(*maxTcc));

    Log_print0(Diags_EXIT, "[+X] getNumAssignedTccs> Exit");

    return (numTccs);
}


/* Functions for RMM to alloc and free its objects from shared memory */

/*
 *  ======== shmAlloc ========
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
static Void *shmAlloc(UArg segid, UInt32 size, UInt32 align)
{
    UInt32  nFreeBytes;
    Void   *base;
    UInt32  alnSize;

    Log_print3(Diags_ENTRY,
            "[+E] DMAN3 shmAlloc> segid = 0x%x, size = 0x%x, align = 0x%x",
            (IArg)segid, (IArg)size, (IArg)align);

    /*
     *  Don't need to handle align parameter (yet). Just align size on
     *  4-byte boundary.
     */
    alnSize = ALIGN32(size);

    /* Number of bytes remaining in the shared memory chunk */
    nFreeBytes = shmSize + (UInt32)shmBase -(UInt32)shmFreeBase;

    Log_print1(Diags_USER2,
            "[+2] DMAN3 shmAlloc> bytes remaining before allocation: 0x%x",
            (IArg)nFreeBytes);

    if (alnSize > nFreeBytes) {
        Log_print2(Diags_USER7,
                "[+7] DMAN3 shmAlloc> Shared memory allocation of [0x%x] bytes "
                "failed. Remaining free bytes: [0x%x]",
                (IArg)alnSize, (IArg)nFreeBytes);
        return (NULL);
    }

    base = shmFreeBase;
    shmFreeBase = (Void *)((UInt32)shmFreeBase + alnSize);

    Log_print1(Diags_USER2,
            "[+2] DMAN3 shmAlloc> bytes remaining after allocation: 0x%x",
            (IArg)(shmSize + (UInt32)shmBase - (UInt32)shmFreeBase));

    memset((void *)base, 0, size);

    Log_print1(Diags_EXIT, "[+X] DMAN3 shmAlloc> returning base address: 0x%x",
            (IArg)base);

    return (base);
}

/*
 *  ======== shmFree ========
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
static Bool shmFree(UArg segid, Void *addr, UInt32 size)
{
    return (TRUE);
}

/*
 *  ======== updateTccAllocationTable ========
 */
static Void updateTccAllocationTable(UInt32 mask32b, Int base)
{
    Int i;

    Log_print0(Diags_ENTRY, "[+E] updateTccAllocationTable> Enter");

    for (i = 0; i < 32; i++) {

        if (mask32b & (0x1 << i)) {
            _DMAN3_tccAllocationTable[_DMAN3_numAssignedTccs++] = base + i;
        }
    }

    Log_print0(Diags_EXIT, "[+X] updateTccAllocationTable> Exit");
}

/*
 * ======== checkDMAN3SocConfiguration ========
 */
/* ARGSUSED */
static Bool checkDMAN3SocConfiguration()
{
    Bool status = TRUE;
#ifndef _DMAN3_CPUCOPY_
    Uns cccfg = 0x0;
    short numQdma = 0;
    short numParam = 0;
    short numTC = 0;
    volatile Uns * edma3Base = (Uns *)_DMAN3_edma3Addr;

    Log_print0(Diags_ENTRY, "[+E] checkDMAN3SocConfiguration> Enter");

    cccfg = edma3Base[1];
    cccfg = (edma3Base[1] >> 4);

    numQdma = (cccfg & 0x7) << 0x1;

    if  (DMAN3_PARAMS.maxQdmaChannels != numQdma) {
        Log_print2(Diags_USER6,
                "[+6] checkDMAN3SocConfiguration> DMAN3 max QDMA channels configured "
                "to be %d, hardware reads %d",
                (IArg)(DMAN3_PARAMS.maxQdmaChannels), (IArg)numQdma);

        status = FALSE;
    }

    cccfg = (cccfg >> 8);
    numParam = (((cccfg & 0x7) == 0) ? 0x0 : (0x10 << (cccfg & 0x7)));

    if  (DMAN3_PARAMS.maxPaRamEntries != numParam) {
        Log_print2(Diags_USER6,
                "[+6] checkDMAN3SocConfiguration> DMAN3 max PaRam entries configured "
                "to be %d, hardware reads %d",
                (IArg)(DMAN3_PARAMS.maxPaRamEntries), (IArg)numParam);

        status = FALSE;
    }

    cccfg = (cccfg>>4);
    numTC = (cccfg &0x7) + 1;

    if  (DMAN3_PARAMS.maxTCs != numTC) {
        Log_print2(Diags_USER6,
                "[+6] checkDMAN3SocConfiguration> DMAN3 max TCs configured to be %d, "
                "hardware reads %d", (IArg)(DMAN3_PARAMS.maxTCs), (IArg)numTC);

        status = FALSE;
    }
#endif

    Log_print1(Diags_EXIT, "[+X] checkDMAN3SocConfiguration> Exit (status=%d)",
            (IArg)status);

    return (status);
}

/*
 *  ======== initQdmaConfiguration ========
 */
static Void initQdmaConfiguration()
{
#ifndef _DMAN3_CPUCOPY_
    Int i,chan;
    UInt32 * addr;
    Uns queueNum;
    Uns qeesr;
    UInt32 mask;

    Log_print0(Diags_ENTRY, "[+E] _initQdmaConfiguration> Enter");

    /* Event queue to TC channel mapping */
    addr = (UInt32 *)((UInt32)_DMAN3_edma3Addr + QUETCMAPOFFSET);
    for (i = 0 ; i < DMAN3_PARAMS.maxTCs; i++) {
        (*addr) |= (DMAN3_PARAMS.queueTCMap[i] << (i *4));
    }

    /* Set Priority for each of the event queues. */
    addr = (UInt32 *)((UInt32)_DMAN3_edma3Addr + QUEPRIOFFSET);
    for (i = 0; i < DMAN3_PARAMS.maxTCs; i++) {
        if (DMAN3_PARAMS.queuePri[i] == -1)  continue;
        mask = ~(0xF << (i * 4));
        *addr = ((*addr) & mask) | (DMAN3_PARAMS.queuePri[i] << (i * 4));
        //(*addr) |= ( DMAN3_PARAMS.queuePri[i] << (i * 4));
    }

    /* QDMA region access enable register 0 */
    addr = (UInt32 *)((UInt32)_DMAN3_edma3Addr + QRAE0OFFSET);
    (*addr) = 0xFF;

    /* Set QDMA to queue mapping */
    addr = (UInt32 *)((UInt32)_DMAN3_edma3Addr + QDMAQNUMOFFSET);
    for (i = 0; i < DMAN3_PARAMS.numQdmaChannels; i++) {
        chan = DMAN3_PARAMS.qdmaChannels[i];
        queueNum = DMAN3_PARAMS.qdmaQueueMap[i];
        (*addr) |= (queueNum << (4 * chan));
    }

    /* Queue Event Enable Set register */
    qeesr = 0x0;
    for (i = 0; i < DMAN3_PARAMS.numQdmaChannels; i++) {
        qeesr |= (0x1 << DMAN3_PARAMS.qdmaChannels[i]);
    }
    addr = (UInt32 *)((UInt32)_DMAN3_edma3Addr + QEESROFFSET);
    (*addr) = qeesr;

    Log_print0(Diags_EXIT, "[+X] _initQdmaConfiguration> Exit");

#endif /* DMAN3_CPUCOPY */
}

#ifdef xdc_target__os_Linux

/*
 *  ======== freeDman3Obj ========
 */
static Void freeDman3Obj()
{
#ifndef _DMAN3_CPUCOPY_
    /* close memfd, unmap */
    if (munmap(_DMAN3_edma3Addr, EDMA3REGSIZE) == -1) {
        Log_print1(Diags_USER7, "[+7] Failed to unmap _DMAN3_edma3Addr [0x%x]",
                (IArg)_DMAN3_edma3Addr);
    }

    if (munmap(_DMAN3_paRamAddr, PARAMREGSIZE) == -1) {
        Log_print1(Diags_USER7, "[+7] Failed to unmap _DMAN3_paRamAddr [0x%x]",
                (IArg)_DMAN3_paRamAddr);
    }

    close(memfd);
#endif
    /* Detach the shared memory */
    if (shmdt(shmBase) == -1) {
        /* error */
        Log_print2(Diags_USER7,
                "[+7] Failed to detach shared memory [0x%x], key = 0x%x",
                (IArg)shmBase, (IArg)_DMAN3_SHMID);
    }

    /* Free the shared memory */
    if (shmctl(shmId, IPC_RMID, 0) == -1) {
        /* error */
        Log_print2(Diags_USER7,
                "[+7] Failed to free shared memory [0x%x], key = 0x%x",
                (IArg)shmBase, (IArg)_DMAN3_SHMID);
    }
}

/*
 *  ======== getDman3Obj ========
 */
static Bool getDman3Obj()
{
    Bool               shmExists = TRUE;
    Int                lockRefCount;
    GateProcess_Handle gateMP;
    Error_Block        eb;

    /*
     *  TODO: Non-multiprocess apps do not need to use a shared memory
     *  object for the DMAN3 data.
     */

    /*
     *  Allocate or locate the chunk of shared memory where internal
     *  DMAN3 objects will be placed. This is to ensure that multiple
     *  processes will see the same DMAN3 objects.
     *  First attempt to get the shared memory without the IPC_CREAT
     *  flag, to see if it's already been created.
     */
    shmSize = SHMSIZE;
    shmId = shmget((key_t)(_DMAN3_SHMID), SHMSIZE, 0666);
    if (shmId == -1) {
        /*
         *  Failed to get the shared memory, so it probably hasn't been
         *  created yet.
         */
        shmId = shmget((key_t)(_DMAN3_SHMID), SHMSIZE, 0666 | IPC_CREAT);
        if (shmId == -1) {
            /* Couldn't create the shared memory */
            Log_print1(Diags_USER7,
                    "[+7] _DMAN3_initImpl> Failed to create shared memory "
                    "region, key = 0x%x", (IArg)_DMAN3_SHMID);

            /* Abort*/
            Assert_isTrue(shmId != -1, (Assert_Id)NULL);
            return (FALSE);
        }
        else {
            /* The segment had not been created before */
            Log_print1(Diags_USER2,
                    "[+2] _DMAN3_initImpl> Created shared memory, key = 0x%x",
                    (IArg)_DMAN3_SHMID);
            shmExists = FALSE;
        }
    }
    else {
        Log_print1(Diags_USER2,
                "[+2] _DMAN3_initImpl> Shared memory, key = 0x%x already exists",
                (IArg)_DMAN3_SHMID);
    }

    /* Get the address of the shared memory region with shmat() */
    shmBase = shmat(shmId, NULL, 0);
    if (shmBase == (Void *)-1) {
        Log_print1(Diags_USER7,
                "[+7] _DMAN3_initImpl> Failed to get shared memory address, "
                "key = 0x%x", (IArg)_DMAN3_SHMID);
        shmBase = NULL;

        /* Abort */
        Assert_isTrue(shmBase != NULL, (Assert_Id)NULL);
        return (FALSE);
    }

    /* Make sure the shared memory base is aligned */
    shmFreeBase = (Void *)ALIGN32(shmBase);

    _DMAN3_data = shmFreeBase;

    /* Make sure the shared memory base is aligned */
    shmFreeBase = (Void *)((UInt32)shmBase + ALIGN32(sizeof(_DMAN3_Data)));

    if (shmExists) {
        /*
         *  Shared memory segment already exists. Check the DMAN3 gate
         *  reference count. Since the gate is created only once per
         *  process, if the gate reference count is 1, the calling process
         *  is the only one using DMAN3 global data. In that case, a
         *  process must have died (or did not call DMAN3_exit()), so we
         *  will re-initialize the DMAN3 global data.
         */
        /*
         *  We can only get the reference of MP gates.
         *  GateProcess_Handle_downCast() will return a GateProcess handle if
         *  DMAN3_gate is a GateProcess gate, otherwise,
         *  GateProcess_Handle_downCast() will return NULL.
         */
        gateMP = GateProcess_Handle_downCast(DMAN3_gate);
        Log_print1(Diags_USER3,
                "[+3] GateProcess_Handle_downCast(DMAN3_gate) 0x%x",
                (IArg)gateMP);

        if (gateMP != NULL) {
            Error_init(&eb);
            lockRefCount = GateProcess_getReferenceCount(gateMP, &eb);

            if (Error_check(&eb)) {
                /* Error occurred, but there's not much we can do about it */
                Log_print0(Diags_USER7, "[+7] GateProcess_getReferenceCount:"
                        " error occurred");
            }
            Log_print1(Diags_USER3, "[+3] GateProcess_getRefCount(): %d",
                    (IArg)lockRefCount);
        }
        else {
            /*
             *  If this not an MP gate, we will re-initialize the
             *  shared memory. Failure by another app to cleanup would
             *  result in garbage data for this app.
             */
            lockRefCount = 1;
            Log_print0(Diags_USER5, "[+5] _DMAN3_initImpl> Warning: "
                    "This app has not configured DMAN3 for multi process, "
                    "and the DMAN3 shared object has been detected in "
                    "memory. The DMAN3 shared object will be re-initialized.");
        }

        Log_print2(Diags_USER2, "[+2] _DMAN3_initImpl> "
                "DMAN3 shared memory reference count = %d\n"
                "DMAN3 lock reference count = %d",
                (IArg)_DMAN3_refCount, (IArg)lockRefCount);

        if (lockRefCount == 1) {
            Log_print1(Diags_USER5, "[+5] _DMAN3_initImpl> Warning: "
                    "Inconsistent reference\ncount between DMAN3 shared memory"
                    " [%d] and lock", (IArg)_DMAN3_refCount);
            Log_print0(Diags_USER5, "[+5] _DMAN3_initImpl> Warning: DMAN3 "
                    "lock reference count indicates no other processes are \n"
                    "currently using DMAN3 shared memory.\n"
                    "Re-initializing DMAN3 shared memory");

            /* This will cause the DMAN3 data to be re-initialized */
            shmExists = FALSE;
        }
    }

    if (!shmExists) {
        /* Initialize the reference count in the shared data area */
        Log_print0(Diags_USER2, "[+2] Initializing DMAN3 shared data");
        _DMAN3_refCount = 0;

        /* Initialize the _DMAN3_data object to 0's */
        memset((Void *)_DMAN3_data, 0, sizeof(_DMAN3_Data));
    }

    return (TRUE);
}

/*
 *  ======== unMapShm ========
 */
static Void unMapShm()
{
#ifndef _DMAN3_CPUCOPY_
    /* close memfd, unmap */
    if (munmap(_DMAN3_edma3Addr, EDMA3REGSIZE) == -1) {
        Log_print1(Diags_USER7, "[+7] Failed to unmap _DMAN3_edma3Addr [0x%x]",
                (IArg)_DMAN3_edma3Addr);
    }

    if (munmap(_DMAN3_paRamAddr, PARAMREGSIZE) == -1) {
        Log_print1(Diags_USER7, "[+7] Failed to unmap _DMAN3_paRamAddr [0x%x]",
                (IArg)_DMAN3_paRamAddr);
    }

    close(memfd);
#endif
    /*
     *  Don't move this block of code. Cannot detach shmBase until
     *  _DMAN3_refCount is checked.
     */
    /* Detach the shared memory, but don't free it. */
    if (shmdt(shmBase) == -1) {
        /* error */
        Log_print2(Diags_USER7,
                "[+7] Failed to detach shared memory [0x%x], key = 0x%x",
                (IArg)shmBase, (IArg)_DMAN3_SHMID);
    }
}

#endif
/*
 *  @(#) ti.sdo.fc.dman3; 1, 0, 4,4; 2-22-2012 18:03:20; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

