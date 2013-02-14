/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */

#include <xdc/std.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef xdc_target__os_Linux 
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#include "_dmaRegs.h"

#include <ti/sdo/fc/memutils/memutils.h>

extern unsigned int ti_sdo_fc_examples_dmaXferChecker_EDMAADDR;


__FAR__ volatile DmaRegSpace * EDMA3BASE; 

static void checkParam(unsigned int *paramaddr);

/* Uses Event#/DMA Ch #N, assumes CH#1 mapped to Param #N */
Bool checkEdmaXfer(unsigned int edmaChan)
{
    unsigned int * pEdma;
    unsigned int * pParam;
    volatile unsigned int * ipr;
    unsigned int mappedParam = -1;

    int i = 0;
 

#ifdef xdc_target__os_Linux 
    static int memfd = -1;           //File descriptor for "/dev/mem"

    memfd = open("/dev/mem", O_RDWR | O_SYNC);

    /* Obtain mmapped base address */ 
    EDMA3BASE = (DmaRegSpace * )mmap(0, 0x8000,  PROT_READ | PROT_WRITE, 
            MAP_SHARED, memfd, 
            (off_t)ti_sdo_fc_examples_dmaXferChecker_EDMAADDR);
#else
    EDMA3BASE = (DmaRegSpace * )ti_sdo_fc_examples_dmaXferChecker_EDMAADDR;
#endif

    printf("dmaxferchecker: Checking Edma channel %d", edmaChan);

    /* Obtain param mapped to this channel. read dchmap */
    mappedParam = DCHMAP[edmaChan]; 
    mappedParam >>= 5; //Shift to bit 4
    mappedParam &= 0x01FF;   //Look at only bits 5 to 13 

    printf("dmaxferchecker: Mapped Param # = %d\n", mappedParam); 
    printf("dmaxferchecker: Address of Param 0x%x\n", &PARAM_BASE[mappedParam]);

    pParam = (unsigned int *) &PARAM_BASE[mappedParam];

    checkParam(pParam);

    /* Check tcc and ints enabled to decide whether to check IPR */ 

    /* Check linked params to see how many transfers left etc */ 

    /* If ints enabled, check if other registers are set for ISR calling */

    /* Check Queue mapping priority etc */

    /* Extra credit: Check status of Queue and Tcc */

#if 0
    /* EESR  = 0x2 
    *((unsigned int *)((unsigned int) pEdma + 0x1030)) = (0x01 << edmaChan); 
    printf("EER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1020))); 
    */

    /* IESR = 0x02 */
    /*
    *((unsigned int *)((unsigned int) pEdma + 0x1060)) = 0xFFFFFFF; 
    printf("IER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1050))); 
    */

    /* ICR */
    *((unsigned int *)((unsigned int) pEdma + 0x1070)) = (0x01 << edmaChan); 

    /* DCHMAP */
    *((unsigned int *)((unsigned int) pEdma + 0x100 + (0x4 * edmaChan))) = 
            (edmaChan << 4) ; 
    
    
    ipr = (unsigned int *)((unsigned int)pEdma+ 0x1068);  
    printf("IPR Before 0x%x\n", *ipr);

    /* ESR = 0x02 */ 
    *((unsigned int *)((unsigned int) pEdma + 0x1010)) = (0x01 << edmaChan); 

    printf("EER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1020))); 

    /* Check for completion */
    while (((*ipr) & (0x1 << edmaChan))  != (0x01 << edmaChan));
    printf("IPR After 0x%x\n", *ipr);

#endif
 

#ifdef xdc_target__os_Linux 
    close(memfd);
#endif

    return (TRUE);
}

Bool checkQdmaXfer(unsigned int qdmaChan)
{
    unsigned int * pEdma;
    unsigned int * pParam;
    volatile unsigned int * ipr;
    unsigned int mappedParam = -1;

    int i = 0;
 

#ifdef xdc_target__os_Linux 
    static int memfd = -1;           //File descriptor for "/dev/mem"

    memfd = open("/dev/mem", O_RDWR | O_SYNC);

    /* Obtain mmapped base address */ 
    EDMA3BASE = (DmaRegSpace * )mmap(0, 0x8000,  PROT_READ | PROT_WRITE, 
            MAP_SHARED, memfd, 
            (off_t)ti_sdo_fc_examples_dmaXferChecker_EDMAADDR);
#else
    EDMA3BASE = (DmaRegSpace * )ti_sdo_fc_examples_dmaXferChecker_EDMAADDR;
#endif

    printf("dmaxferchecker: Checking Qdma channel %d", qdmaChan);

    /* Obtain param mapped to this channel. read dchmap */
    mappedParam = QCHMAP[qdmaChan]; 
    mappedParam >>= 5; //Shift to bit 4
    mappedParam &= 0x01FF;   //Look at only bits 5 to 13 

    /* TODO: Also figure out trigger word */

    printf("dmaxferchecker: Mapped Param # = %d\n", mappedParam); 
    printf("dmaxferchecker: Address of Param 0x%x\n", &PARAM_BASE[mappedParam]);

    pParam = (unsigned int *) &PARAM_BASE[mappedParam];

    checkParam(pParam);

    /* Check tcc and ints enabled to decide whether to check IPR */ 

    /* Check linked params to see how many transfers left etc */ 

    /* If ints enabled, check if other registers are set for ISR calling */

    /* Check Queue mapping priority etc */

    /* Extra credit: Check status of Queue and Tcc */

#if 0
    /* EESR  = 0x2 
    *((unsigned int *)((unsigned int) pEdma + 0x1030)) = (0x01 << edmaChan); 
    printf("EER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1020))); 
    */

    /* IESR = 0x02 */
    /*
    *((unsigned int *)((unsigned int) pEdma + 0x1060)) = 0xFFFFFFF; 
    printf("IER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1050))); 
    */

    /* ICR */
    *((unsigned int *)((unsigned int) pEdma + 0x1070)) = (0x01 << edmaChan); 

    /* DCHMAP */
    *((unsigned int *)((unsigned int) pEdma + 0x100 + (0x4 * edmaChan))) = 
            (edmaChan << 4) ; 
    
    
    ipr = (unsigned int *)((unsigned int)pEdma+ 0x1068);  
    printf("IPR Before 0x%x\n", *ipr);

    /* ESR = 0x02 */ 
    *((unsigned int *)((unsigned int) pEdma + 0x1010)) = (0x01 << edmaChan); 

    printf("EER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1020))); 

    /* Check for completion */
    while (((*ipr) & (0x1 << edmaChan))  != (0x01 << edmaChan));
    printf("IPR After 0x%x\n", *ipr);

#endif
 

#ifdef xdc_target__os_Linux 
    close(memfd);
#endif

    return (TRUE);
}


static void checkParam(unsigned int * pParam)
{       
    unsigned *src_addr;
        unsigned *dest_addr;
    unsigned int acnt, bcnt, ccnt;
    unsigned int dstbidx, srcbidx;
    unsigned int bcntrld, link;
    unsigned int dstcidx, srccidx; 
    unsigned int opt;
    unsigned int tcc;
    unsigned int sam, dam;
    unsigned int sync;
    unsigned int entryUpdate;
    unsigned int fwid;
    unsigned int tccmode;
    unsigned int tcinten;
    unsigned int itcinten;
    unsigned int tcchen;
    unsigned int itcchen;
    unsigned int linkedParam;
    
    /* Parse opt */
    opt = pParam[0];
    printf("dmaxferchecker: opt 0x%x\n",opt);  
    sam = opt & 0x1;
    opt >>= 1;
    dam = opt & 0x1;
    opt >>= 1; 
    printf("dmaxferchecker: sam 0x%x dam 0x%x (0 Incremental, 1 Fifo)\n", sam, dam);  
    
    sync = opt & 0x1;
    opt >>= 1;

    printf("dmaxferchecker: syncdim 0x%x (0 A-sync, 1 B-sync)\n", sync);  

    entryUpdate = opt & 0x1;
    opt >>= 1;
    opt >>= 4;  //rsv

    printf("dmaxferchecker: static 0x%x (0 Normal, 1 Static)\n", entryUpdate);  

    fwid = opt & 0x7;
    opt >>= 3;

    if (sam || dam) {
        printf("dmaxferchecker: fifo width 0x%x\n", (0x4 << (fwid + 1)));  
    }

    tccmode = opt & 0x1;
    opt >>= 1;

    printf("dmaxferchecker: tcc mode 0x%x (0 Normal, 1 Early)\n", tccmode);  

    tcc = opt & 0x3F;
    opt >>= 6;
    opt >>= 2; //rsv

    printf("dmaxferchecker: tcc 0x%x\n", tcc);  

    tcinten = opt & 0x1;
    opt >>= 1;

    printf("dmaxferchecker: transfer completion interrupt 0x%x "
            "(0 dis, 1 enable)\n", tcinten);  

    itcinten = opt & 0x1;
    opt >>= 1; 

    printf("dmaxferchecker: intermediate transfer completion interrupt 0x%x "
            "(0 dis, 1 enable)\n", itcinten);  

    tcchen = opt & 0x1;
    opt >>= 1;

    printf("dmaxferchecker: transfer completion chaining 0x%x "
            "(0 dis, 1 enable)\n", tcchen);  

    itcchen = opt & 0x1;

    
    printf("dmaxferchecker: intermediate transfer completion chaining 0x%x "
            "(0 dis, 1 enable)\n", itcchen);  

    
    /* Obtain the following info from the param:- 
        src, dst, acnt, bcnt, completion, ints enabled, tcc, linked
     */   
    src_addr = (unsigned int *)pParam[1];
    acnt = pParam[2] & 0xFFFF;
    bcnt = (pParam[2] >> 16) & 0xFFFF;
    printf("dmaxferchecker: Acnt %d, Bcnt %d\n", acnt, bcnt);

    if ((acnt == 0) || (bcnt == 0)) {
        printf("dmaxferchecker: Dummy transfer !!\n"); 
    }

    dest_addr = (unsigned int *)pParam[3];

    printf("dmaxferchecker: Copy src 0x%x to dst 0x%x\n", src_addr, dest_addr);

    if (bcnt > 1) {
        srcbidx = pParam[4] & 0xFFFF;
        dstbidx = (pParam[4] >> 16) & 0xFFFF;
        printf("dmaxferchecker: srcbidx 0x%x dstbidx 0x%x\n", srcbidx, dstbidx);
    }
    link = pParam[5] & 0xFFFF;
    ccnt = pParam[7] & 0xFFFF;

    if (ccnt == 0) {
        printf("dmaxferchecker: Dummy transfer !!\n"); 
    }


    if (ccnt > 1)  {
        bcntrld = (pParam[5] >> 16) & 0xFFFF;

        if (sync == 0) {
            /* a-synced transfer */
            printf("dmaxferchecker: bcntrld 0x%x\n", bcntrld); 
        }
        srccidx = pParam[6] & 0xFFFF; 
        dstcidx = (pParam[6] >> 16) & 0xFFFF; 
        printf("dmaxferchecker: srccidx 0x%x dstcidx\n", srccidx, dstcidx); 
    }
    
    if (!(entryUpdate) && (link != 0xFFFF)) {
        linkedParam = (link & 0x3FE0) / 0x20;
        printf("dmaxferchecker: linked param 0x%x\n", linkedParam); 
        checkParam((unsigned int *)&PARAM_BASE[linkedParam]);
    } 

}
/*
 *  @(#) ti.sdo.fc.examples.dmaxferchecker; 1, 0, 0,4; 2-22-2012 18:04:56; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

