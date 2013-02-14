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
 *  ======== shmbuf.c ========
 *  IRES implementation for the Linux shared memory resource.
 */

/* This difine must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_ires_shmbuf_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include <ti/sdo/fc/global/FCSettings.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <ti/sdo/fc/ires/iresman.h>


#include "shmbuf.h"


#define ti_sdo_fc_ires_NOPROTOCOLREV

#define MAXRECS 10
#define NUMRECS 1

/*
 *  ======== SHMBUF_ConstructArgs ========
 *  Arguments passed to the constructHandle() function.
 */
typedef struct SHMBUF_ConstructArgs {
    Int     size;    /* Size of this structure */

    /*
     *  Fields that will go into the SHMBUF_Obj (that are not already in
     *  SHMBUF_Args)
     */
    Void   *base;    /* Base address */
} SHMBUF_ConstructArgs;

Registry_Desc ti_sdo_fc_ires_shmbuf_desc;

/* Resource Manager Interface functions */
static String getProtocolName();
static IRES_ProtocolRevision * getRevision();
static IRES_Status initShm(IRESMAN_Params *args);
static IRES_Status exitShm();
static IRES_Handle getShm(IALG_Handle algHandle, IRES_ResourceDescriptor *desc,
        Int scratchId, IRES_Status *status);
static IRES_Status freeShm(IALG_Handle algHandle, IRES_Handle res,
        IRES_ResourceDescriptor *desc, Int scratchId);

/*
 *  ======== SHMBUF_MGRFXNS ========
 *  Implementation of IRESMAN_Fxns interface. These functions are called
 *  (by a resource manager, eg, RMAN) to:
 *      - initialize the resource with config params
 *      - allocate resource based on args
 *      - free resource (based on args)
 *      - exit the resource
 */
IRESMAN_Fxns SHMBUF_MGRFXNS = {
    getProtocolName,
    getRevision,
    initShm,          /* init */
    exitShm,          /* exit */
    getShm,           /* getHandle */
    freeShm,          /* freeHandle */
};

/* Resource Request Interface functions */
static IRES_Status getMemRecs(IRES_Handle ires, IRES_ProtocolArgs *args,
        IALG_MemRec *memRecs);
static Int getNumRecs(IRES_ProtocolArgs *args);
static IRES_Handle constructHandle(IRES_ProtocolArgs *args,
        IALG_MemRec *memRecs, IRESMAN_ConstructArgs *cArgs,
        IRES_Status *status);
static IRES_Status destructHandle(IRES_Handle ires);

/*
 *  ======== SHMBUF_REQFXNS ========
 *  Implementation of IRESMAN_ConstructFxns. These functions get called by the
 *  resource's IRESMAN_Fxns when allocating a resource, to
 *      - determine how much memory is needed
 *      - initialize the allocated memory
 */
IRESMAN_ConstructFxns SHMBUF_REQFXNS = {
    getProtocolName,
    getRevision,
    getMemRecs,          /* getResourceMemRecs */
    getNumRecs,          /* getNumMemRecs */
    constructHandle,     /* constructHandle */
    destructHandle,      /* destructHandle */
};

/* Resource Protocol Interface functions */
Void getStaticProps(IRES_Handle res, IRES_Properties *props);

/*
 *  Internal types and objects for this resource manager.
 */

/*
 *  ======== ShmBufInfo ========
 *  Properties and state of the shared memory buffer that will be stored
 *  at the beginning of the buffer, so that it can be accessed by multiple
 *  processes.
 *
 *  TODO: Is refCount necessary, or can we use shmctl(shmId, IPC_STAT, &desc)
 *  to get the reference count?
 */
typedef struct ShmBufInfo {
    UInt32   length;        /* Length (bytes) of useable part of buffer */
    Int      refCount;      /* Number of algorithms using this buffer */
    UInt32   isScratch;
//  Int         scratchId;  /* Scratch group Id of algs using the buffer */

    /*
     *  Set to 0, if the buffer is not scratch and being used, non-zero
     *  if it's available. This should always be non-zero if isScratch is
     *  TRUE.
     */
    UInt32   isFree;

    /* Make size a multiple of 32 bytes */
    UInt32   resvd1;
    UInt32   resvd2;
    UInt32   resvd3;
    UInt32   resvd4;
} ShmBufInfo;


static Void *bufAlloc(Int id, Int size, Int align);

#if 0 /* Don't need these for now */
static Bool myAlloc(IALG_MemRec *memTab, Int numRecs);
static Bool myFree(IALG_MemRec *memTab, Int numRecs);
#endif

static Int curInit = 0;     /* Refence count on initShm() */
static Int regInit = 0;     /* Registry_addModule() called */
static Int initialized = 0; /* Successful initialization */
/*
 *  The resource:
 *      bufferInfo: Points to data about the shared buffer. This will be set
 *                  to the start of the buffer returned by shmget().
 *      bufferBase: Start of buffer where we can alloc from. This will be set
 *                  to bufferInfo + sizeof(ShmBufInfo).
 *      bufferId:   Id returned by shmget().
 */
static ShmBufInfo *bufferInfo = NULL;
static Void       *bufferBase = NULL;
static Int         bufferId = 0;


/* ======== IMPLEMENTATION ======== */

/*
 *  ======== IRES RESOURCE MANAGER FUNCTIONS ========
 *  getProtocolName, getRevision, initBuf, exitBuf, getShm, freeShm
 */

/*
 *  ======== getProtocolName ========
 */
static String getProtocolName()
{
    return (SHMBUF_PROTOCOLNAME);
}

/*
 *  ======== getRevision ========
 */
static IRES_ProtocolRevision * getRevision()
{
    return (&SHMBUF_PROTOCOLVERSION);
}

/*
 *  ======== initShm ========
 *  Initialize the SHMBUF resource manager.
 */
static IRES_Status initShm(IRESMAN_Params *args)
{
    SHMBUF_Params    *params = (SHMBUF_Params *)args;
    Int               refCount;
    Int               shmId = -1;
    Int               bufSize;
    Bool              first = FALSE;
    Void             *shmMem = NULL;
    struct shmid_ds   desc;
    UInt32            length;
    IRES_Status       status = IRES_OK;
    Registry_Result   result;


    /*
     *  Register the module name for logging only once. Do this before any
     *  Log functions are called.
     */
    if (!regInit) {
        result = Registry_addModule(&ti_sdo_fc_ires_shmbuf_desc,
                SHMBUF_MODNAME);

        Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

        /* Set diags mask to FC default */
        FCSettings_init();
        FCSettings_setDiags(SHMBUF_MODNAME);
        regInit = 1;
    }

    Log_print1(Diags_ENTRY, "[+E] SHMBUF initShm> Enter (aArgs=0x%x)",
            (IArg)args);

    Assert_isTrue(args != NULL, (Assert_Id)NULL);

    if (curInit++) {
        /* Already initialized */
        Log_print0(Diags_ENTRY, "[+E] SHMBUF initShm> already initialized");
        return (IRES_EEXISTS);
    }

    Log_print3(Diags_ENTRY, "[+E] SHMBUF initShm> key [0x%x] length [0x%x] "
            "isScratch [%d]",
            (IArg)(params->key), (IArg)(params->bufsize),
            (IArg)(params->isScratch));

    /* We'll just use malloc() and free() instead of any functions in args */

    /* Initialize the Buffer Resource Manager based on config params */

    /*
     *  The actual length of the buffer allocated will be rounded up to a
     *  multiple of the page size, but we will just keep track of the length
     *  that was passed in. Round length up to a 4-byte boundary and add on
     *  the size of the ShmBufInfo structure that we will fill in at the
     *  beginning of the buffer.
     */
    length = ((params->bufsize + 3) / 4) * 4;
    bufSize = length + sizeof(ShmBufInfo);
    //buffer.key = params->key;

    /* Enter critical section */

    /* Create the shared memory if it doesn't exist yet */
    shmId = shmget((key_t)params->key, bufSize, 0666 | IPC_CREAT | IPC_EXCL);
    if (shmId == -1) {
        /*
         *  Maybe the shared memory is already created, and we just need
         *  to get its id.
         */
        shmId = shmget((key_t)params->key, bufSize, 0666 | IPC_CREAT);
        if (shmId == -1) {
            /* error */
            Log_print2(Diags_USER7, "[+7] SHMBUF initShm> "
                    "shmget(0x%x, 0x%x, 0666 | IPC_CREAT) failed",
                    (IArg)(params->key), (IArg)bufSize);
            status = IRES_EFAIL;
        }
    }
    else {
        /* We were the first to create the shared memory buffer */
        first = TRUE;
    }

    if (shmId != -1) {
        shmMem = shmat(shmId, NULL, 0);
        if (shmMem == (Void *)-1) {
            Log_print1(Diags_USER7, "[+7] SHMBUF initShm> "
                    "shmat(0x%x, 0x%x, NULL, 0) failed", (IArg)shmId);
            status = IRES_EFAIL;
        }
        else {
            bufferInfo = (ShmBufInfo *)shmMem;
            bufferBase = (Void *)((UInt32)shmMem + sizeof(ShmBufInfo));
            bufferId = shmId;

            Log_print3(Diags_ENTRY, "[+E] SHMBUF initShm> bufferInfo [0x%x], "
                    "bufferBase [0x%x], bufferId [0x%x]",
                    (IArg)bufferInfo, (IArg)bufferBase, (IArg)bufferId);

            if (first) {
                /*
                 *  Initialize shared memory region to 0's and mark the
                 *  buffer as available.
                 */
                Log_print0(Diags_ENTRY,
                        "[+E] SHMBUF initShm> Initialing shared memory buffer");
                memset(shmMem, 0, bufSize);
                bufferInfo->length = length;
                bufferInfo->refCount = 0;
                bufferInfo->isScratch = params->isScratch;
                bufferInfo->isFree = 1;
            }
            else {
                /*
                 *  If the buffer was already created as scratch, we should
                 *  not use it as persistent. Print out a warning.
                 */
                if (bufferInfo->isScratch && !params->isScratch) {
                    Log_print0(Diags_USER6, "[+6] SHMBUF initShm> WARNING: "
                            "params->isScratch is FALSE, although "
                            "this resource has already been initialized "
                            "as scratch. Any persistent requests of this "
                            "resource will fail");
                }

                Log_print4(Diags_ENTRY, "[+E] SHMBUF initShm> Buffer already "
                        "created by another processes. length [0x%x], "
                        "refCount [%d], isScratch [%d], isFree [%d]",
                        (IArg)(bufferInfo->length),
                        (IArg)(bufferInfo->refCount),
                        (IArg)(bufferInfo->isScratch),
                        (IArg)(bufferInfo->isFree));
            }

            bufferInfo->refCount++;
            shmctl(shmId, IPC_STAT, &desc);
            refCount = desc.shm_nattch;

            /*
             *  Compare the reference count returned by shmctl() with the one
             *  stored in the buffer.
             */
            Log_print2(Diags_ENTRY, "[+E] SHMBUF initShm> shm refCount from "
                    "shmctl() = %d, refCount in shm = %d",
                    (IArg)refCount, (IArg)(bufferInfo->refCount));
        }
    }

    if (status == IRES_OK) {
        initialized = 1;
    }

    /* Exit critical section */

    Log_print1(Diags_ENTRY, "[+E] SHMBUF init> returning 0x%x", (IArg)status);
    return (status);
}

/*
 *  ======== exitShm ========
 */
static IRES_Status exitShm()
{
    Int             refCount;
    struct shmid_ds desc;

    Log_print0(Diags_EXIT, "[+X] SHMBUF exit>");

    /* Enter critical section */

    if (--curInit == 0) {
        /* Process reference count is 0, clean up */

        /* Get the reference count of the shared memory region */
        shmctl(bufferId, IPC_STAT, &desc);
        refCount = desc.shm_nattch;

        Log_print2(Diags_EXIT, "[+X] SHMBUF exitShm> shm refCount from "
                "shmctl() = %d, refCount in shm = %d",
                (IArg)refCount, (IArg)(bufferInfo->refCount));

        /* Detach from the shared memory */
        if (shmdt(bufferInfo) == -1) {
            Log_print1(Diags_USER7, "[+7] SHMBUF exitShm> shmdt(%p) failed",
                    (IArg)bufferInfo);
        }

        /* If this is the last process using the shared memory, delete it. */
        if (refCount == 1) {
            Log_print0(Diags_EXIT, "[+X] SHMBUF exitShm> freeing shared memory");
            if (shmctl(bufferId, IPC_RMID, 0) == -1) {
                Log_print1(Diags_USER7, "[+7] SHMBUF exitShm> "
                        "shmctl(0x%lx, IPC_RMID) failed", (IArg)bufferId);
            }
        }
        bufferInfo = NULL;
        bufferBase = NULL;
        bufferId = 0;
    }

    /* Exit critical section */

    return (IRES_OK);
}

/*
 *  ======== getShm ========
 * This function allocates the buffer resource
 */
/* ARGSUSED */
static IRES_Handle getShm(IALG_Handle algHandle, 
        IRES_ResourceDescriptor *resDesc, Int scratchId, IRES_Status *pStatus)
{
    SHMBUF_Handle        res = NULL;
    Int                  length;
    Int                  align;
    Void                *base = NULL;
    IRES_RequestMode     mode;
    IRES_Status          status = IRES_OK;
    IRES_ProtocolArgs * args = resDesc->protocolArgs;   

    Assert_isTrue(pStatus != NULL, (Assert_Id)NULL);
    Assert_isTrue(args != NULL, (Assert_Id)NULL);

    length = ((SHMBUF_Args *)args)->length;
    align = ((SHMBUF_Args *)args)->align;
    mode = args->mode; /* IRES_SCRATCH or IRES_PERSISTENT */

    Log_print3(Diags_ENTRY, "[+E] SHMBUF getShm> Requesting buffer of "
            "length 0x%x, align 0x%x, mode %s", (IArg)length, (IArg)align,
            (IArg)((mode == IRES_PERSISTENT) ? "IRES_PERSISTENT" :
                    "IRES_SCRATCH"));

    if (initialized == 0) {
        *pStatus = IRES_ENOINIT;
        return (NULL);
    }

    /* TODO: acquire a lock */

    /*
     *  Don't give this buffer out if it was created as scratch, but requested
     *  as persistent, or if it was created as persistent but is being
     *  requested as scratch.
     */
    if (bufferInfo->isScratch && (mode == IRES_PERSISTENT)) {
        Log_print0(Diags_USER6, "[+6] SHMBUF getShm> Cannot assign "
                "shared scratch buffer if requested as persistent");
        status = IRES_ENORESOURCE;
    }
    else if (!bufferInfo->isScratch && (mode == IRES_SCRATCH)) {
        Log_print0(Diags_USER6, "[+6] SHMBUF getShm> Cannot assign "
                "persistent buffer if requested as scratch");
        status = IRES_ENORESOURCE;
    }
    else if (!bufferInfo->isScratch && !bufferInfo->isFree) {
        /* Can only allocate from a persistent buffer if it is available */
        Log_print0(Diags_USER6,
                "[+6] SHMBUF_getShm> Buffer is currently in use");
        status = IRES_ENORESOURCE;
    }
    else {
        /* Allocate from the shm buffer */
        if ((base = bufAlloc(0, length, align)) == NULL) {
            Log_print2(Diags_USER6, "[+6] SHMBUF getShm> "
                    "bufAlloc(0, 0x%x, 0x%x) failed",
                    (IArg)length, (IArg)align);
            status = IRES_ENORESOURCE;
        }
    }

    if (status == IRES_OK) {
        /*
         *  Found available resource, now allocate memory to construct
         *  a SHMBUF handle to pass back to the algorithm. Instead of filling
         *  in a memTab[] array and passing it to an alloc function, will
         *  just malloc() the object.
         */
        res = (SHMBUF_Handle)malloc(sizeof(SHMBUF_Obj));
        if (res == NULL) {
            Log_print1(Diags_USER7, "[+7] SHMBUF getShm> malloc(0x%x) failed",
                    (IArg)(sizeof(SHMBUF_Obj)));
            return (NULL);
        }
        memset(res, '\0', sizeof(SHMBUF_Obj));
    }

    if (status == IRES_OK) {
        /*
         *  Initialize the buffers.
         *  Normally, we could create an SHMBUF_ConstructArgs object, fill it
         *  in and pass it to constructHandle():
         *      res = (SHMBUF_Handle)constructHandle(args, memRecs,
         *              (IRESMAN_ConstructArgs *)&cArgs, &retVal);
         *
         *  but it is clearer if we just initialize here.
         */
        res->ires.getStaticProperties = getStaticProps;
        res->ires.persistent = (args->mode == IRES_PERSISTENT) ? 1 : 0;
        //res->ires.persistent = IRES_PERSISTENT;

        res->base = base;
        res->length = length;
    }

    if (status == IRES_OK) {
        /* Mark shm buffer unavailable if we've requested it persistently */
        if (res->ires.persistent) {
            bufferInfo->isFree = 0;
        }
    }

    /* TODO: release lock */
    resDesc->handle = (IRES_Handle)res;
    resDesc->revision->Major = 1;       
    resDesc->revision->Source = 0;      
    resDesc->revision->Radius = 0;      

    *pStatus = status;

    return ((IRES_Handle)res);
}

/*
 *  ======== freeShm ========
 */
/* ARGSUSED */
static IRES_Status freeShm(IALG_Handle algHandle, IRES_Handle res,
        IRES_ResourceDescriptor *resDesc, Int scratchId)
{
    IRES_Status status = IRES_OK;
    IRES_ProtocolArgs * args = resDesc->protocolArgs;

    Assert_isTrue(res != NULL, (Assert_Id)NULL);

    /*
     *  Normally, we would fill in memRecs[] with data needed to allocate the
     *  buffers that were allocated to create the SHMBUF_Obj, call the
     *  destructHandle() function, and then the free function. Since we only
     *  have one buffer allocated to create the SHMBUF_Obj, we'll just free
     *  it.
     */
    free((Void *)res);

    /* TODO: acquire lock */

    /*
     *  Mark the buffer as available. (If it is scratch, isFree should already
     *  be 1.)
     */
    bufferInfo->isFree = 1;

    /* release lock */

    return (status);
}

/*
 *  ======== IRES RESOURCE PROTOCOL INTERFACE FUNCTIONS ========
 *  getStaticProps
 */

/*
 *  ======== getStaticProps ========
 */
/* ARGSUSED */
Void getStaticProps(IRES_Handle res, IRES_Properties *props)
{
    Assert_isTrue(res != NULL, (Assert_Id)NULL);
    Assert_isTrue(props != NULL, (Assert_Id)NULL);

    ((SHMBUF_Props *)props)->base = bufferBase;
    ((SHMBUF_Props *)props)->length = bufferInfo->length;
}


/*
 *  ======== IRES RESOURCE REQUEST INTERFACE FUNCTIONS ========
 *  constructHandle, destructHandle, getMemRecs, getNumRecs
 */

/*
 *  ======== constructHandle ========
 */
/* ARGSUSED */
static IRES_Handle constructHandle(IRES_ProtocolArgs *args,
        IALG_MemRec *memRecs, IRESMAN_ConstructArgs *cArgs,
        IRES_Status *status)
{
    SHMBUF_Handle   res;

    Assert_isTrue(args != NULL, (Assert_Id)NULL);
    Assert_isTrue(cArgs != NULL, (Assert_Id)NULL);
    Assert_isTrue(memRecs != NULL, (Assert_Id)NULL);
    Assert_isTrue(status != NULL, (Assert_Id)NULL);

    /*
     *  Piece the allocated buffers together to form the SHMBUF_Obj.
     *  In this case, only one buffer has been allocated, so piecing
     *  together is unnecessary.
     */
    res = (SHMBUF_Handle)(memRecs->base);
    res->ires.getStaticProperties = getStaticProps;
//  res->ires.persistent = (args->mode == IRES_PERSISTENT) ? 1 : 0;
    res->ires.persistent = IRES_PERSISTENT;

    res->base = ((SHMBUF_ConstructArgs *)cArgs)->base;
    res->length = ((SHMBUF_Args *)args)->length;

    *status = IRES_OK;
    return ((IRES_Handle)res);
}

/*
 *  ======== destructHandle ========
 */
/* ARGSUSED */
static IRES_Status destructHandle(IRES_Handle res)
{
    /*
     *  Do any de-initialization necessary on the SHMBUF_Obj. In this case,
     *  nothing needs to be done.
     */
    return (IRES_OK);
}


/*
 *  ======== getMemRecs ========
 *  Fill in the memRecs table with the values needed to allocate a
 *  SHMBUF_Obj.
 */
/* ARGSUSED */
static IRES_Status getMemRecs(IRES_Handle ires, IRES_ProtocolArgs *args,
        IALG_MemRec *memRecs)
{
    IRES_Status     status = IRES_OK;

    if (ires == NULL) {
        /* Fill memRecs[] with data needed to allocate the object */
        memRecs[0].size = sizeof(SHMBUF_Obj);
        memRecs[0].alignment = 0;
        memRecs[0].attrs = IALG_PERSIST;
        memRecs[0].space = IALG_EXTERNAL;
    }
    else {
        /*
         *  Fill memRec[] with data on buffers allocated to create the
         *  object. (In this case, only one buffer was allocated).
         */
        memRecs[0].base = (Void *)ires;
        memRecs[0].size = sizeof(SHMBUF_Obj);
        memRecs[0].alignment = 0;
        memRecs[0].attrs = IALG_PERSIST;
        memRecs[0].space = IALG_EXTERNAL;
    }

    return (status);
}

/*
 *  ======== getNumRecs ========
 */
/* ARGSUSED */
static Int getNumRecs(IRES_ProtocolArgs *args)
{
    /* Only one buffer is needed to construct a SHMBUF_Obj */
    return (NUMRECS);
}

/*
 *  ======== Internal Functions ========
 */

/*
 *  ======== bufAlloc ========
 */
/* ARGSUSED */
static Void *bufAlloc(Int id, Int size, Int align)
{
    Uint32     alignSize;
    Uint32     alignBytes;
    Uint32     remainBytes;
    Uint32     base;

    /* 'align' must be 0 or a power of 2, 0 means no alignment */
    alignBytes = (align == 0) ? 1 : align;
    base = (Uint32)bufferBase;

    if (base & (alignBytes - 1)) {
        /* The base of the buffer is not aligned on 'alignBytes' boundary */
        remainBytes = alignBytes - (base & (alignBytes - 1));
        alignSize = size + remainBytes;
        base = base + remainBytes;
    }
    else {
        /* buffer is already aligned */
        alignSize = size;
    }

    if (alignSize <= bufferInfo->length) {
        return ((Void *)base);
    }
    else {
        return (NULL);
    }
}

#if 0 /* Don't really need these for now */
/*
 *  ======== myAlloc ========
 */
static Bool myAlloc(IALG_MemRec *memTab, Int numRecs)
{
    Int     i;

    Log_print2(Diags_ENTRY, "[+E] SHMBUF myAlloc(0x%lx, %d)",
            (IArg)memTab, (IArg)numRecs);

    for (i = 0; i < numRecs; i++) {
        memTab[i].base = malloc(memTab[i].size);

        if (memTab[i].base == NULL) {
            Log_print1(Diags_USER7, "[+7] SHMBUF myAlloc> malloc(0x%x) failed",
                    (IArg)(memTab[i].size));
            myFree(memTab, i - 1);
            return (FALSE);
        }

        memset(memTab[i].base, '\0', memTab[i].size);
    }
    return (TRUE);
}

/*
 *  ======== myFree ========
 */
static Bool myFree(IALG_MemRec *memTab, Int numRecs)
{
    Int     i;

    Log_print2(Diags_ENTRY, "[+E] SHMBUF myAlloc(0x%lx, %d)",
            (IArg)memTab, (IArg)numRecs);

    for (i = 0; i < numRecs; i++) {
        Assert_isTrue(memTab[i].base != NULL, (Assert_Id)NULL);
        free(memTab[i].base);
    }

    return (TRUE);
}
#endif
/*
 *  @(#) ti.sdo.fc.ires.shmbuf; 1, 0, 0,4; 2-22-2012 18:06:41; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

