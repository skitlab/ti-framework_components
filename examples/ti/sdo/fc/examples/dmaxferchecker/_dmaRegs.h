/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */


extern unsigned int ti_sdo_fc_examples_dmaXferChecker_EDMAADDR; 

/* Offsets of EDMA/QDMA peripheral registers from their base address */
#define DCHMAP_OFFSET          0x0100
#define QCHMAP_OFFSET          0x0200
#define QDMAQNUM_OFFSET        0x0260
#define QUETCMAP_OFFSET        0x0280
#define QUEPRI_OFFSET          0x0284
#define EMR_OFFSET             0x0300
#define EMRH_OFFSET            0x0304
#define EMCR_OFFSET            0x0308
#define EMCRH_OFFSET           0x030C
#define QEMR_OFFSET            0x0310
#define QEMCR_OFFSET           0x0314
#define QRAE0_OFFSET           0x0380
#define IPR_OFFSET        0x1068
#define IPRH_OFFSET       0x106C
#define ICR_OFFSET        0x1070
#define ICRH_OFFSET       0x1074
#define QER_OFFSET             0x1080
#define QEER_OFFSET            0x1084
#define QEECR_OFFSET           0x1088
#define QEESR_OFFSET           0x108C
#define QSER_OFFSET            0x1090
#define QSECR_OFFSET           0x1094
#define PARAM_OFFSET      0x4000

#define  MAX_QDMA_CHANNELS   8    
#define  MAX_EDMA_CHANNELS   64    

typedef struct PaRamSpace {
    Uns params[8];
} PaRamSpace;

typedef struct DmaRegSpace {
  Uns filler1[DCHMAP_OFFSET/sizeof(int)];
  Uns dchMap[MAX_EDMA_CHANNELS];    /* DCHMAP */
  Uns qchMap[MAX_QDMA_CHANNELS];    /* QCHMAP */
  Uns filler2[(QDMAQNUM_OFFSET -
              (QCHMAP_OFFSET + (MAX_QDMA_CHANNELS * sizeof(int))))
              / sizeof(int)];
  Uns qdmaQNum;                           /* QNUM */
  Uns filler3[(QUETCMAP_OFFSET -
              (QDMAQNUM_OFFSET + sizeof(int))) / sizeof(int)];
  Uns queTcMap;                           /* QUETCMAP */
  Uns quePri;                             /* QUEPRI */
  Uns filler4[(EMR_OFFSET -
              (QUEPRI_OFFSET + sizeof(int))) / sizeof(int)];
  Uns emr;                                /* EMR */
  Uns emrH;                               /* EMRH */
  Uns emcr;                               /* EMCR */
  Uns emcrH;                              /* EMCRH */
  Uns qemr;                               /* QEMR */
  Uns qemcr;                              /* QEMCR */
  Uns filler5[(QRAE0_OFFSET -
              (QEMCR_OFFSET + sizeof(int))) / sizeof(int)];
  Uns qrae0;                              /* QRAE0 */
  Uns filler6[(IPR_OFFSET -
              (QRAE0_OFFSET + sizeof(int))) / sizeof(int)];
  Uns ipr;                                /* _IPR */
  Uns iprH;                               /* _IPRH */
  Uns icr;                                /* _ICR */
  Uns icrH;                               /* _ICRH */
  Uns filler7[(QER_OFFSET -
              (ICRH_OFFSET + sizeof(int))) / sizeof(int)];
  Uns qer;                                /* QER */
  Uns qeer;                               /* QEER */
  Uns qeecr;                              /* QEECR */
  Uns qeesr;                              /* QEESR */
  Uns qser;                               /* QSER */
  Uns qsecr;                              /* QSECR */
  Uns filler8[(PARAM_OFFSET -
              (QSECR_OFFSET + sizeof(int))) / sizeof(int)];
  PaRamSpace paRamBase;                       /* PARAM_OFFSET */
} DmaRegSpace;


extern __FAR__ volatile DmaRegSpace * EDMA3BASE; 

/*
 *  DCHMAP: Channel to param map register which specifies which parameter
 *  entry in bits 13-5
 */
#define DCHMAP (EDMA3BASE->dchMap)


/*
 *  QCHMAP: Channel to param map register which specifies which parameter
 *  entry in bits 13-5 and the trigger word (which is word 7 in ACPY3
 *  implementation), in bits 4-2.
 */
#define QCHMAP (EDMA3BASE->qchMap)

/*
 *  QDMAQNUM: The QDMA queue number specifies which queue needs to be used
 *  for each of the individual QDMA channels, 4 in the case of Davinci. This
 *  register is defined in Figure 10 of the 3PCC spec.
 */
#define QDMAQNUM (&EDMA3BASE->qdmaQNum)

/*
 *  QUETCMAP: This register is specified in Figure 11 of the 3PCC  spec. In the
 *  case of Davinci there are 2 event queues and 2 TC channels. The default
 *  mapping is TC channel0 to Event Queue 0, etc.
 */
#define QUETCMAP (&EDMA3BASE->queTcMap)

/*
 *  QUEPRI: This register defines the priority for event queue. There are two
 *  event queues for Davinci, and hence two priorities need to be programmed.
 *  A "higher" value for the priority represents a lower priority.
 */
#define QUEPRI (&EDMA3BASE->quePri)

/* Event Missed Register */
#define EMR (&EDMA3BASE->emr)
/* Event Missed Register High */
#define EMRH (&EDMA3BASE->emrH)
/* Event Missed Clear Register */
#define EMCR (&EDMA3BASE->emcr)
/* Event Missed Clear Register High */
#define EMCRH (&EDMA3BASE->emcrH)
/* QDMA Event Missed Register */
#define QEMR (&EDMA3BASE->qemr)
/* QDMA Event Missed Clear Register */
#define QEMCR (&EDMA3BASE->qemcr)

/*
 *  QRAE0: This register represents the QDMA access enable register. This
 *  register needs to be set if the interrupts for specific TCC's is going
 *  to be used. This library uses polling of the interrupt pending register
 *  and hence does not need to set QRAE0.
 */
#define QRAE0 (&EDMA3BASE->qrae0)

/*
 *  QDMA_IPR : This represents the location where upon completion the DMA
 *  hardware posts completion, if the TCC used is one of the lower 32.
 */
#define IPR (&ACPY3_EDMA3BASE->ipr)

/*
 *  QDMA_IPRH : This represents the location where upon completion the DMA
 *  hardware posts completion, if the TCC used is one of the upper 32.
 */
#define IPRH (&ACPY3_EDMA3BASE->iprH)

/*
 *  QDMA_ICR: This represents the interrupt clear reg. Writing to this
 *  register should clear any corresp. bit in QDMA_IPR.
 */
#define ICR (&EDMA3BASE->icr)

/*
 *  QDMA_ICRH: This represents the interrupt clear reg. Writing to this
 *  register should clear any corresp. bit in QDMA_IPRH.
 */
#define ICRH (&EDMA3BASE->icrH)

/*
 *  QER: Queue Event register
 */
#define QER (&EDMA3BASE->qer)

/*
 *  QEER: Queue Event Enable register
 */
#define QEER (&EDMA3BASE->qeer)

/*
 *  QEECR: Queue Event Enable Set register is used to enable all the QDMA
 *  channels. To avoid the problem of read modify write seperate set and
 *  clear registers are provided for enabling the QDMA channels.
 */
#define QEECR (&EDMA3BASE->qeecr)

/* QEESR: register enables the individual QDMA channels to be enabled. */
#define QEESR (&EDMA3BASE->qeesr)

/* QDMA Secondary Event Register */
#define QSER (&EDMA3BASE->qser)
/* QDMA Secondary Event Clear Register */
#define QSECR (&EDMA3BASE->qsecr)
/* PaRam Base address */
#define PARAM_BASE ((PaRamSpace *)(&EDMA3BASE->paRamBase))
/*
 *  @(#) ti.sdo.fc.examples.dmaxferchecker; 1, 0, 0,4; 2-22-2012 18:04:56; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

