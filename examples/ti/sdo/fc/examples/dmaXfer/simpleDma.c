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


#include <ti/sdo/fc/memutils/memutils.h>

extern unsigned int ti_sdo_fc_examples_dmaXfer_EDMAADDR;

#define EDMAADDR ti_sdo_fc_examples_dmaXfer_EDMAADDR 

/* Uses Event#/DMA Ch #N, assumes CH#1 mapped to Param #N */
void do1DDma(unsigned int src, unsigned int dst, unsigned int bytes, 
        unsigned int chanNum)
{
    unsigned int * pEdma;
    unsigned int * pParam;
    volatile unsigned int * ipr;

    int i = 0;
    unsigned *src_addr = (unsigned int *)src;
    unsigned *dest_addr = (unsigned int *)dst;
    unsigned int tccNum = (unsigned int)-1;

#ifdef xdc_target__os_Linux 
    static int memfd = -1;           //File descriptor for "/dev/mem"

    memfd = open("/dev/mem", O_RDWR | O_SYNC);
    /* Obtain mmapped base address */ 
    pEdma = (unsigned int* )mmap(0, 0x8000,  PROT_READ | PROT_WRITE, MAP_SHARED,
            memfd, (off_t)EDMAADDR);
#else
    pEdma = (unsigned int* )EDMAADDR;
#endif

    /* 4. DMA from src to dst */
    /* Set param 1 */

    pParam = (unsigned int *)((unsigned int) pEdma + 0x4000 + 
            (0x20 * chanNum)); //param # chanNum 

    tccNum = (chanNum << 12); 

    /* Set QUEPRI to something */
    *((unsigned int *)((unsigned int) pEdma + 0x284)) = 0x3 << (0x4 * chanNum); 
    printf("QUEPRI Set to 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 
            0x284))); 

#ifndef EDMA

    /* Set QCHMAP -> trigger word set to 0x7 */
    *((unsigned int *)((unsigned int) pEdma + 0x200 + (0x4 * chanNum))) = 
            (0x7 << 2 | chanNum << 5); 
#endif

    //pParam[0] = (0x00100008 | tccNum); //OPT TCC == edmachan + STATIC
    pParam[0] = (0x00100000 | tccNum); //OPT TCC == edmachan + NORMAL (?!)
#ifdef xdc_target__os_Linux 
    pParam[1] = (unsigned int)MEMUTILS_getPhysicalAddr(src_addr);
#else
    pParam[1] = (unsigned int)src_addr;
#endif
    pParam[2] = 0x00010000 + bytes; //Bcnt, Acnt
#ifdef xdc_target__os_Linux 
    pParam[3] = (unsigned int)MEMUTILS_getPhysicalAddr(dest_addr);
#else
    pParam[3] = (unsigned int)dest_addr;
#endif
    pParam[4] = 0x0;
    pParam[5] = 0xFFFF;
    pParam[6] = 0x0;
#ifdef EDMA
    pParam[7] = 0x1;
#endif

    printf("Param # %d\n", chanNum);

    for (i = 0; i < 8; i++) {
       printf("0x%x\t",pParam[i]);
    }
    printf("\n");


    /* ICR */
    *((unsigned int *)((unsigned int) pEdma + 0x1070)) = (0x01 << chanNum); 
    
    ipr = (unsigned int *)((unsigned int)pEdma+ 0x1068);  
    printf("IPR Before 0x%x\n", *ipr);

#ifdef EDMA

    /* SECR = 0xFFFFFFFF */
    *((unsigned int *)((unsigned int) pEdma + 0x1040)) = 0xFFFFFFF; 
    printf("SER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1038))); 

    /* EESR  = 0x2 
    *((unsigned int *)((unsigned int) pEdma + 0x1030)) = (0x01 << chanNum); 
    printf("EER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1020))); 
    */

    /* IESR = 0x02 */
    /*
    *((unsigned int *)((unsigned int) pEdma + 0x1060)) = 0xFFFFFFF; 
    printf("IER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1050))); 
    */

   /* DCHMAP */
    *((unsigned int *)((unsigned int) pEdma + 0x100 + (0x4 * chanNum))) = 
            (chanNum << 4) ; 
    
    /* ESR = 0x02 */ 
    *((unsigned int *)((unsigned int) pEdma + 0x1010)) = (0x01 << chanNum); 


#else /* QDMA mode */

    /* Clear QEMR */
    *((unsigned int *)((unsigned int) pEdma + 0x0314)) = 0xFFFFFFF; 
    printf("QEMR 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x0310))); 

    /* QSECR = 0xFFFFFFFF */
    *((unsigned int *)((unsigned int) pEdma + 0x1094)) = 0xFFFFFFF; 
    printf("QSER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1090))); 

    /* QEESR  */
    *((unsigned int *)((unsigned int) pEdma + 0x108C)) = (0x01 << chanNum); 
    printf("QEER 0x%x\n", *((unsigned int *)((unsigned int) pEdma + 0x1084))); 

   pParam[7] = 0x1;

#endif

    /* Check for completion */
    while (((*ipr) & (0x1 << chanNum))  != (0x01 << chanNum));
    printf("IPR After 0x%x\n", *ipr);
 

#ifdef xdc_target__os_Linux 
    close(memfd);
#endif
}
/*
 *  @(#) ti.sdo.fc.examples.dmaXfer; 1, 0, 0,4; 2-22-2012 18:04:54; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

