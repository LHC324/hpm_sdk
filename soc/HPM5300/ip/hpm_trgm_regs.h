/*
 * Copyright (c) 2021-2025 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef HPM_TRGM_H
#define HPM_TRGM_H

typedef struct {
    __RW uint32_t FILTCFG[28];                 /* 0x0 - 0x6C: Filter configure register */
    __R  uint8_t  RESERVED0[144];              /* 0x70 - 0xFF: Reserved */
    __RW uint32_t TRGOCFG[137];                /* 0x100 - 0x320: Trigger manager output configure register */
    __R  uint8_t  RESERVED1[220];              /* 0x324 - 0x3FF: Reserved */
    __RW uint32_t DMACFG[8];                   /* 0x400 - 0x41C: DMA request configure register */
    __R  uint8_t  RESERVED2[224];              /* 0x420 - 0x4FF: Reserved */
    __RW uint32_t GCR;                         /* 0x500: General Control Register */
    __R  uint8_t  RESERVED3[12];               /* 0x504 - 0x50F: Reserved */
    __RW uint32_t ADC_MATRIX_SEL;              /* 0x510: adc matrix select register */
    __RW uint32_t DAC_MATRIX_SEL;              /* 0x514: dac matrix select register */
    __RW uint32_t POS_MATRIX_SEL0;             /* 0x518: position matrix select register0 */
    __RW uint32_t POS_MATRIX_SEL1;             /* 0x51C: position matrix select register1 */
    __R  uint8_t  RESERVED4[224];              /* 0x520 - 0x5FF: Reserved */
    __R  uint32_t TRGM_IN[4];                  /* 0x600 - 0x60C: trigmux input read register0 */
    __R  uint8_t  RESERVED5[16];               /* 0x610 - 0x61F: Reserved */
    __R  uint32_t TRGM_OUT[5];                 /* 0x620 - 0x630: trigmux output read register0 */
} TRGM_Type;


/* Bitfield definition for register array: FILTCFG */
/*
 * OUTINV (RW)
 *
 * 1- Filter will invert the output
 * 0- Filter will not invert the output
 */
#define TRGM_FILTCFG_OUTINV_MASK (0x10000UL)
#define TRGM_FILTCFG_OUTINV_SHIFT (16U)
#define TRGM_FILTCFG_OUTINV_SET(x) (((uint32_t)(x) << TRGM_FILTCFG_OUTINV_SHIFT) & TRGM_FILTCFG_OUTINV_MASK)
#define TRGM_FILTCFG_OUTINV_GET(x) (((uint32_t)(x) & TRGM_FILTCFG_OUTINV_MASK) >> TRGM_FILTCFG_OUTINV_SHIFT)

/*
 * MODE (RW)
 *
 * This bitfields defines the filter mode
 * 000-bypass;
 * 100-rapid change mode;
 * 101-delay filter mode;
 * 110-stalbe low mode;
 * 111-stable high mode
 */
#define TRGM_FILTCFG_MODE_MASK (0xE000U)
#define TRGM_FILTCFG_MODE_SHIFT (13U)
#define TRGM_FILTCFG_MODE_SET(x) (((uint32_t)(x) << TRGM_FILTCFG_MODE_SHIFT) & TRGM_FILTCFG_MODE_MASK)
#define TRGM_FILTCFG_MODE_GET(x) (((uint32_t)(x) & TRGM_FILTCFG_MODE_MASK) >> TRGM_FILTCFG_MODE_SHIFT)

/*
 * SYNCEN (RW)
 *
 * set to enable sychronization input signal with TRGM clock
 */
#define TRGM_FILTCFG_SYNCEN_MASK (0x1000U)
#define TRGM_FILTCFG_SYNCEN_SHIFT (12U)
#define TRGM_FILTCFG_SYNCEN_SET(x) (((uint32_t)(x) << TRGM_FILTCFG_SYNCEN_SHIFT) & TRGM_FILTCFG_SYNCEN_MASK)
#define TRGM_FILTCFG_SYNCEN_GET(x) (((uint32_t)(x) & TRGM_FILTCFG_SYNCEN_MASK) >> TRGM_FILTCFG_SYNCEN_SHIFT)

/*
 * FILTLEN_SHIFT (RW)
 *
 */
#define TRGM_FILTCFG_FILTLEN_SHIFT_MASK (0xE00U)
#define TRGM_FILTCFG_FILTLEN_SHIFT_SHIFT (9U)
#define TRGM_FILTCFG_FILTLEN_SHIFT_SET(x) (((uint32_t)(x) << TRGM_FILTCFG_FILTLEN_SHIFT_SHIFT) & TRGM_FILTCFG_FILTLEN_SHIFT_MASK)
#define TRGM_FILTCFG_FILTLEN_SHIFT_GET(x) (((uint32_t)(x) & TRGM_FILTCFG_FILTLEN_SHIFT_MASK) >> TRGM_FILTCFG_FILTLEN_SHIFT_SHIFT)

/*
 * FILTLEN_BASE (RW)
 *
 * This bitfields defines the filter counter length.
 */
#define TRGM_FILTCFG_FILTLEN_BASE_MASK (0x1FFU)
#define TRGM_FILTCFG_FILTLEN_BASE_SHIFT (0U)
#define TRGM_FILTCFG_FILTLEN_BASE_SET(x) (((uint32_t)(x) << TRGM_FILTCFG_FILTLEN_BASE_SHIFT) & TRGM_FILTCFG_FILTLEN_BASE_MASK)
#define TRGM_FILTCFG_FILTLEN_BASE_GET(x) (((uint32_t)(x) & TRGM_FILTCFG_FILTLEN_BASE_MASK) >> TRGM_FILTCFG_FILTLEN_BASE_SHIFT)

/* Bitfield definition for register array: TRGOCFG */
/*
 * OUTINV (RW)
 *
 * 1- Invert the output
 */
#define TRGM_TRGOCFG_OUTINV_MASK (0x800U)
#define TRGM_TRGOCFG_OUTINV_SHIFT (11U)
#define TRGM_TRGOCFG_OUTINV_SET(x) (((uint32_t)(x) << TRGM_TRGOCFG_OUTINV_SHIFT) & TRGM_TRGOCFG_OUTINV_MASK)
#define TRGM_TRGOCFG_OUTINV_GET(x) (((uint32_t)(x) & TRGM_TRGOCFG_OUTINV_MASK) >> TRGM_TRGOCFG_OUTINV_SHIFT)

/*
 * FEDG2PEN (RW)
 *
 * 1- The selected input signal falling edge will be convert to an pulse on output. The output pulse can be stably used within the motor control system. When connecting the signal outside the motor system, due to the asynchronization of the clock systems, the clock frequency and signal active length need to be considered.
 */
#define TRGM_TRGOCFG_FEDG2PEN_MASK (0x400U)
#define TRGM_TRGOCFG_FEDG2PEN_SHIFT (10U)
#define TRGM_TRGOCFG_FEDG2PEN_SET(x) (((uint32_t)(x) << TRGM_TRGOCFG_FEDG2PEN_SHIFT) & TRGM_TRGOCFG_FEDG2PEN_MASK)
#define TRGM_TRGOCFG_FEDG2PEN_GET(x) (((uint32_t)(x) & TRGM_TRGOCFG_FEDG2PEN_MASK) >> TRGM_TRGOCFG_FEDG2PEN_SHIFT)

/*
 * REDG2PEN (RW)
 *
 * 1- The selected input signal rising edge will be convert to an pulse on output. The output pulse can be stably used within the motor control system. When connecting the signal outside the motor system, due to the asynchronization of the clock systems, the clock frequency and signal active length need to be considered.
 */
#define TRGM_TRGOCFG_REDG2PEN_MASK (0x200U)
#define TRGM_TRGOCFG_REDG2PEN_SHIFT (9U)
#define TRGM_TRGOCFG_REDG2PEN_SET(x) (((uint32_t)(x) << TRGM_TRGOCFG_REDG2PEN_SHIFT) & TRGM_TRGOCFG_REDG2PEN_MASK)
#define TRGM_TRGOCFG_REDG2PEN_GET(x) (((uint32_t)(x) & TRGM_TRGOCFG_REDG2PEN_MASK) >> TRGM_TRGOCFG_REDG2PEN_SHIFT)

/*
 * TRIGOSEL (RW)
 *
 * This bitfield selects one of the TRGM inputs as output.
 */
#define TRGM_TRGOCFG_TRIGOSEL_MASK (0x7FU)
#define TRGM_TRGOCFG_TRIGOSEL_SHIFT (0U)
#define TRGM_TRGOCFG_TRIGOSEL_SET(x) (((uint32_t)(x) << TRGM_TRGOCFG_TRIGOSEL_SHIFT) & TRGM_TRGOCFG_TRIGOSEL_MASK)
#define TRGM_TRGOCFG_TRIGOSEL_GET(x) (((uint32_t)(x) & TRGM_TRGOCFG_TRIGOSEL_MASK) >> TRGM_TRGOCFG_TRIGOSEL_SHIFT)

/* Bitfield definition for register array: DMACFG */
/*
 * DMAMUX_EN (RW)
 *
 */
#define TRGM_DMACFG_DMAMUX_EN_MASK (0x80000000UL)
#define TRGM_DMACFG_DMAMUX_EN_SHIFT (31U)
#define TRGM_DMACFG_DMAMUX_EN_SET(x) (((uint32_t)(x) << TRGM_DMACFG_DMAMUX_EN_SHIFT) & TRGM_DMACFG_DMAMUX_EN_MASK)
#define TRGM_DMACFG_DMAMUX_EN_GET(x) (((uint32_t)(x) & TRGM_DMACFG_DMAMUX_EN_MASK) >> TRGM_DMACFG_DMAMUX_EN_SHIFT)

/*
 * DMASRCSEL (RW)
 *
 * This field selects one of the DMA requests as the DMA request output.
 */
#define TRGM_DMACFG_DMASRCSEL_MASK (0x3FU)
#define TRGM_DMACFG_DMASRCSEL_SHIFT (0U)
#define TRGM_DMACFG_DMASRCSEL_SET(x) (((uint32_t)(x) << TRGM_DMACFG_DMASRCSEL_SHIFT) & TRGM_DMACFG_DMASRCSEL_MASK)
#define TRGM_DMACFG_DMASRCSEL_GET(x) (((uint32_t)(x) & TRGM_DMACFG_DMASRCSEL_MASK) >> TRGM_DMACFG_DMASRCSEL_SHIFT)

/* Bitfield definition for register: GCR */
/*
 * TRGOPEN (RW)
 *
 * The bitfield enable the TRGM outputs.
 */
#define TRGM_GCR_TRGOPEN_MASK (0xFFU)
#define TRGM_GCR_TRGOPEN_SHIFT (0U)
#define TRGM_GCR_TRGOPEN_SET(x) (((uint32_t)(x) << TRGM_GCR_TRGOPEN_SHIFT) & TRGM_GCR_TRGOPEN_MASK)
#define TRGM_GCR_TRGOPEN_GET(x) (((uint32_t)(x) & TRGM_GCR_TRGOPEN_MASK) >> TRGM_GCR_TRGOPEN_SHIFT)

/* Bitfield definition for register: ADC_MATRIX_SEL */
/*
 * QEI1_ADC1_SEL (RW)
 *
 * 0-adc0;  1-adc1;  2-rdc_adc0; 3-rdc_adc1;
 * bit7 is used to invert adc_value;
 * others reserved
 */
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_MASK (0xFF000000UL)
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_SHIFT (24U)
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_SET(x) (((uint32_t)(x) << TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_SHIFT) & TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_MASK)
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_GET(x) (((uint32_t)(x) & TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_MASK) >> TRGM_ADC_MATRIX_SEL_QEI1_ADC1_SEL_SHIFT)

/*
 * QEI1_ADC0_SEL (RW)
 *
 */
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_MASK (0xFF0000UL)
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_SHIFT (16U)
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_SET(x) (((uint32_t)(x) << TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_SHIFT) & TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_MASK)
#define TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_GET(x) (((uint32_t)(x) & TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_MASK) >> TRGM_ADC_MATRIX_SEL_QEI1_ADC0_SEL_SHIFT)

/*
 * QEI0_ADC1_SEL (RW)
 *
 */
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_MASK (0xFF00U)
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_SHIFT (8U)
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_SET(x) (((uint32_t)(x) << TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_SHIFT) & TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_MASK)
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_GET(x) (((uint32_t)(x) & TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_MASK) >> TRGM_ADC_MATRIX_SEL_QEI0_ADC1_SEL_SHIFT)

/*
 * QEI0_ADC0_SEL (RW)
 *
 */
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_MASK (0xFFU)
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_SHIFT (0U)
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_SET(x) (((uint32_t)(x) << TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_SHIFT) & TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_MASK)
#define TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_GET(x) (((uint32_t)(x) & TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_MASK) >> TRGM_ADC_MATRIX_SEL_QEI0_ADC0_SEL_SHIFT)

/* Bitfield definition for register: DAC_MATRIX_SEL */
/*
 * DAC1_DAC_SEL (RW)
 *
 * 0-qeo0_dac0;   1-qeo0_dac1;  2-qeo0_dac2;
 * 3-qeo1_dac0;   4-qeo1_dac1;  5-qeo1_dac2;
 * 6-rdc_dac0;      7-rdc_dac1;
 * bit7 is used to invert dac_value;
 * others reserved
 */
#define TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_MASK (0xFF000000UL)
#define TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_SHIFT (24U)
#define TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_SET(x) (((uint32_t)(x) << TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_SHIFT) & TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_MASK)
#define TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_GET(x) (((uint32_t)(x) & TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_MASK) >> TRGM_DAC_MATRIX_SEL_DAC1_DAC_SEL_SHIFT)

/*
 * DAC0_DAC_SEL (RW)
 *
 */
#define TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_MASK (0xFF0000UL)
#define TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_SHIFT (16U)
#define TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_SET(x) (((uint32_t)(x) << TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_SHIFT) & TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_MASK)
#define TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_GET(x) (((uint32_t)(x) & TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_MASK) >> TRGM_DAC_MATRIX_SEL_DAC0_DAC_SEL_SHIFT)

/*
 * ACMP1_DAC_SEL (RW)
 *
 */
#define TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_MASK (0xFF00U)
#define TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_SHIFT (8U)
#define TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_SET(x) (((uint32_t)(x) << TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_SHIFT) & TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_MASK)
#define TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_GET(x) (((uint32_t)(x) & TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_MASK) >> TRGM_DAC_MATRIX_SEL_ACMP1_DAC_SEL_SHIFT)

/*
 * ACMP0_DAC_SEL (RW)
 *
 */
#define TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_MASK (0xFFU)
#define TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_SHIFT (0U)
#define TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_SET(x) (((uint32_t)(x) << TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_SHIFT) & TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_MASK)
#define TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_GET(x) (((uint32_t)(x) & TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_MASK) >> TRGM_DAC_MATRIX_SEL_ACMP0_DAC_SEL_SHIFT)

/* Bitfield definition for register: POS_MATRIX_SEL0 */
/*
 * MMC1_POSIN_SEL (RW)
 *
 * 0-sei_pos_out0;       1-sei_pos_out1;
 * 2-qei0_pos;             3-qei1_pos;
 * 4-mmc0_pos_out0;  5-mmc0_pos_out1;
 * 6-mmc1_pos_out0;  7-mmc1_pos_out1;
 * bit7 is used to invert position value;
 *  others reserved
 */
#define TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_MASK (0xFF000000UL)
#define TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_SHIFT (24U)
#define TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_SET(x) (((uint32_t)(x) << TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_SHIFT) & TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_MASK)
#define TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_GET(x) (((uint32_t)(x) & TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_MASK) >> TRGM_POS_MATRIX_SEL0_MMC1_POSIN_SEL_SHIFT)

/*
 * MMC0_POSIN_SEL (RW)
 *
 */
#define TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_MASK (0xFF0000UL)
#define TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_SHIFT (16U)
#define TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_SET(x) (((uint32_t)(x) << TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_SHIFT) & TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_MASK)
#define TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_GET(x) (((uint32_t)(x) & TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_MASK) >> TRGM_POS_MATRIX_SEL0_MMC0_POSIN_SEL_SHIFT)

/*
 * SEI_POSIN1_SEL (RW)
 *
 */
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_MASK (0xFF00U)
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_SHIFT (8U)
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_SET(x) (((uint32_t)(x) << TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_SHIFT) & TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_MASK)
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_GET(x) (((uint32_t)(x) & TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_MASK) >> TRGM_POS_MATRIX_SEL0_SEI_POSIN1_SEL_SHIFT)

/*
 * SEI_POSIN0_SEL (RW)
 *
 */
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_MASK (0xFFU)
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_SHIFT (0U)
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_SET(x) (((uint32_t)(x) << TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_SHIFT) & TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_MASK)
#define TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_GET(x) (((uint32_t)(x) & TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_MASK) >> TRGM_POS_MATRIX_SEL0_SEI_POSIN0_SEL_SHIFT)

/* Bitfield definition for register: POS_MATRIX_SEL1 */
/*
 * QEO1_POS_SEL (RW)
 *
 */
#define TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_MASK (0xFF00U)
#define TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_SHIFT (8U)
#define TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_SET(x) (((uint32_t)(x) << TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_SHIFT) & TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_MASK)
#define TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_GET(x) (((uint32_t)(x) & TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_MASK) >> TRGM_POS_MATRIX_SEL1_QEO1_POS_SEL_SHIFT)

/*
 * QEO0_POS_SEL (RW)
 *
 */
#define TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_MASK (0xFFU)
#define TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_SHIFT (0U)
#define TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_SET(x) (((uint32_t)(x) << TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_SHIFT) & TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_MASK)
#define TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_GET(x) (((uint32_t)(x) & TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_MASK) >> TRGM_POS_MATRIX_SEL1_QEO0_POS_SEL_SHIFT)

/* Bitfield definition for register array: TRGM_IN */
/*
 * TRGM_IN (RO)
 *
 * mmc1_trig_out[1:0], mmc0_trig_out[1:0],sync_pulse[3:0],moto_gpio_in_sync[7:0],//31:16
 *  gtmr3_to_motor_sync[1:0],gtmr2_to_motor_sync[1:0],gtmr1_to_motor_sync[1:0],gtmr0_to_motor_sync[1:0],  //15:8
 *  acmp_out_sync[1:0],can2mot_event_sync[1:0],usb0_sof_tog_sync,pwm_debug,1'b1,1'b0       //7:0
 */
#define TRGM_TRGM_IN_TRGM_IN_MASK (0xFFFFFFFFUL)
#define TRGM_TRGM_IN_TRGM_IN_SHIFT (0U)
#define TRGM_TRGM_IN_TRGM_IN_GET(x) (((uint32_t)(x) & TRGM_TRGM_IN_TRGM_IN_MASK) >> TRGM_TRGM_IN_TRGM_IN_SHIFT)

/* Bitfield definition for register array: TRGM_OUT */
/*
 * TRGM_OUT (RO)
 *
 * motor_to_opamp0[7:0]     = trig_mux_out[7:0];
 * motor_to_opamp1[7:0]     = trig_mux_out[15:8];
 * motor_to_gtmr0_capt[1:0] = trig_mux_out[17:16];
 * motor_to_gtmr0_sync      = trig_mux_out[18];
 * motor_to_gtmr1_capt[1:0] = trig_mux_out[20:19];
 * motor_to_gtmr1_sync      = trig_mux_out[21];
 * motor_to_gtmr2_capt[1:0] = trig_mux_out[23:22];
 * motor_to_gtmr2_sync      = trig_mux_out[24];
 * motor_to_gtmr3_capt[1:0] = trig_mux_out[26:25];
 * motor_to_gtmr3_sync      = trig_mux_out[27];
 * acmp_window[1:0]         = trig_mux_out[29:28];
 * dac0_buf_trigger         = trig_mux_out[30];
 * dac1_buf_trigger         = trig_mux_out[31];
 * dac0_step_trigger[3:0]   = {trig_mux_out[24:22],trig_mux_out[30]};//use same buf_trig, and gtmr2
 * dac1_step_trigger[3:0]   = {trig_mux_out[27:25],trig_mux_out[31]}; //use same buf_trig, and gtmr3
 */
#define TRGM_TRGM_OUT_TRGM_OUT_MASK (0xFFFFFFFFUL)
#define TRGM_TRGM_OUT_TRGM_OUT_SHIFT (0U)
#define TRGM_TRGM_OUT_TRGM_OUT_GET(x) (((uint32_t)(x) & TRGM_TRGM_OUT_TRGM_OUT_MASK) >> TRGM_TRGM_OUT_TRGM_OUT_SHIFT)



/* FILTCFG register group index macro definition */
#define TRGM_FILTCFG_PWM0_IN0 (0UL)
#define TRGM_FILTCFG_PWM0_IN1 (1UL)
#define TRGM_FILTCFG_PWM0_IN2 (2UL)
#define TRGM_FILTCFG_PWM0_IN3 (3UL)
#define TRGM_FILTCFG_PWM0_IN4 (4UL)
#define TRGM_FILTCFG_PWM0_IN5 (5UL)
#define TRGM_FILTCFG_PWM0_IN6 (6UL)
#define TRGM_FILTCFG_PWM0_IN7 (7UL)
#define TRGM_FILTCFG_PWM1_IN0 (8UL)
#define TRGM_FILTCFG_PWM1_IN1 (9UL)
#define TRGM_FILTCFG_PWM1_IN2 (10UL)
#define TRGM_FILTCFG_PWM1_IN3 (11UL)
#define TRGM_FILTCFG_PWM1_IN4 (12UL)
#define TRGM_FILTCFG_PWM1_IN5 (13UL)
#define TRGM_FILTCFG_PWM1_IN6 (14UL)
#define TRGM_FILTCFG_PWM1_IN7 (15UL)
#define TRGM_FILTCFG_TRGM_P_00 (16UL)
#define TRGM_FILTCFG_TRGM_P_01 (17UL)
#define TRGM_FILTCFG_TRGM_P_02 (18UL)
#define TRGM_FILTCFG_TRGM_P_03 (19UL)
#define TRGM_FILTCFG_TRGM_P_04 (20UL)
#define TRGM_FILTCFG_TRGM_P_05 (21UL)
#define TRGM_FILTCFG_TRGM_P_06 (22UL)
#define TRGM_FILTCFG_TRGM_P_07 (23UL)
#define TRGM_FILTCFG_PWM0_FAULT0 (24UL)
#define TRGM_FILTCFG_PWM0_FAULT1 (25UL)
#define TRGM_FILTCFG_PWM1_FAULT0 (26UL)
#define TRGM_FILTCFG_PWM1_FAULT1 (27UL)

/* TRGOCFG register group index macro definition */
#define TRGM_TRGOCFG_MOT2OPAMP0_0 (0UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_1 (1UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_2 (2UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_3 (3UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_4 (4UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_5 (5UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_6 (6UL)
#define TRGM_TRGOCFG_MOT2OPAMP0_7 (7UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_0 (8UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_1 (9UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_2 (10UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_3 (11UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_4 (12UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_5 (13UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_6 (14UL)
#define TRGM_TRGOCFG_MOT2OPAMP1_7 (15UL)
#define TRGM_TRGOCFG_GPTMR0_IN2 (16UL)
#define TRGM_TRGOCFG_GPTMR0_IN3 (17UL)
#define TRGM_TRGOCFG_GPTMR0_SYNCI (18UL)
#define TRGM_TRGOCFG_GPTMR1_IN2 (19UL)
#define TRGM_TRGOCFG_GPTMR1_IN3 (20UL)
#define TRGM_TRGOCFG_GPTMR1_SYNCI (21UL)
#define TRGM_TRGOCFG_GPTMR2_IN2 (22UL)
#define TRGM_TRGOCFG_GPTMR2_IN3 (23UL)
#define TRGM_TRGOCFG_GPTMR2_SYNCI (24UL)
#define TRGM_TRGOCFG_GPTMR3_IN2 (25UL)
#define TRGM_TRGOCFG_GPTMR3_IN3 (26UL)
#define TRGM_TRGOCFG_GPTMR3_SYNCI (27UL)
#define TRGM_TRGOCFG_ACMP_CH0_WIN (28UL)
#define TRGM_TRGOCFG_ACMP_CH1_WIN (29UL)
#define TRGM_TRGOCFG_DAC0_BUFTRG (30UL)
#define TRGM_TRGOCFG_DAC1_BUFTRG (31UL)
#define TRGM_TRGOCFG_ADC0_STRGI (32UL)
#define TRGM_TRGOCFG_ADC1_STRGI (33UL)
#define TRGM_TRGOCFG_ADCX_PTRGI0A (34UL)
#define TRGM_TRGOCFG_ADCX_PTRGI0B (35UL)
#define TRGM_TRGOCFG_ADCX_PTRGI0C (36UL)
#define TRGM_TRGOCFG_ADCX_PTRGI1A (37UL)
#define TRGM_TRGOCFG_ADCX_PTRGI1B (38UL)
#define TRGM_TRGOCFG_ADCX_PTRGI1C (39UL)
#define TRGM_TRGOCFG_ADCX_PTRGI2A (40UL)
#define TRGM_TRGOCFG_ADCX_PTRGI2B (41UL)
#define TRGM_TRGOCFG_ADCX_PTRGI2C (42UL)
#define TRGM_TRGOCFG_ADCX_PTRGI3A (43UL)
#define TRGM_TRGOCFG_ADCX_PTRGI3B (44UL)
#define TRGM_TRGOCFG_ADCX_PTRGI3C (45UL)
#define TRGM_TRGOCFG_CAN_PTPC0_CAP (46UL)
#define TRGM_TRGOCFG_CAN_PTPC1_CAP (47UL)
#define TRGM_TRGOCFG_QEO0_TRIG_IN0 (48UL)
#define TRGM_TRGOCFG_QEO0_TRIG_IN1 (49UL)
#define TRGM_TRGOCFG_QEO1_TRIG_IN0 (50UL)
#define TRGM_TRGOCFG_QEO1_TRIG_IN1 (51UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN0 (52UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN1 (53UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN2 (54UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN3 (55UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN4 (56UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN5 (57UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN6 (58UL)
#define TRGM_TRGOCFG_SEI_TRIG_IN7 (59UL)
#define TRGM_TRGOCFG_MMC0_TRIG_IN0 (60UL)
#define TRGM_TRGOCFG_MMC0_TRIG_IN1 (61UL)
#define TRGM_TRGOCFG_MMC1_TRIG_IN0 (62UL)
#define TRGM_TRGOCFG_MMC1_TRIG_IN1 (63UL)
#define TRGM_TRGOCFG_PLB_IN_00 (64UL)
#define TRGM_TRGOCFG_PLB_IN_01 (65UL)
#define TRGM_TRGOCFG_PLB_IN_02 (66UL)
#define TRGM_TRGOCFG_PLB_IN_03 (67UL)
#define TRGM_TRGOCFG_PLB_IN_04 (68UL)
#define TRGM_TRGOCFG_PLB_IN_05 (69UL)
#define TRGM_TRGOCFG_PLB_IN_06 (70UL)
#define TRGM_TRGOCFG_PLB_IN_07 (71UL)
#define TRGM_TRGOCFG_PLB_IN_08 (72UL)
#define TRGM_TRGOCFG_PLB_IN_09 (73UL)
#define TRGM_TRGOCFG_PLB_IN_10 (74UL)
#define TRGM_TRGOCFG_PLB_IN_11 (75UL)
#define TRGM_TRGOCFG_PLB_IN_12 (76UL)
#define TRGM_TRGOCFG_PLB_IN_13 (77UL)
#define TRGM_TRGOCFG_PLB_IN_14 (78UL)
#define TRGM_TRGOCFG_PLB_IN_15 (79UL)
#define TRGM_TRGOCFG_PLB_IN_16 (80UL)
#define TRGM_TRGOCFG_PLB_IN_17 (81UL)
#define TRGM_TRGOCFG_PLB_IN_18 (82UL)
#define TRGM_TRGOCFG_PLB_IN_19 (83UL)
#define TRGM_TRGOCFG_PLB_IN_20 (84UL)
#define TRGM_TRGOCFG_PLB_IN_21 (85UL)
#define TRGM_TRGOCFG_PLB_IN_22 (86UL)
#define TRGM_TRGOCFG_PLB_IN_23 (87UL)
#define TRGM_TRGOCFG_PLB_IN_24 (88UL)
#define TRGM_TRGOCFG_PLB_IN_25 (89UL)
#define TRGM_TRGOCFG_PLB_IN_26 (90UL)
#define TRGM_TRGOCFG_PLB_IN_27 (91UL)
#define TRGM_TRGOCFG_PLB_IN_28 (92UL)
#define TRGM_TRGOCFG_PLB_IN_29 (93UL)
#define TRGM_TRGOCFG_PLB_IN_30 (94UL)
#define TRGM_TRGOCFG_PLB_IN_31 (95UL)
#define TRGM_TRGOCFG_TRGM_P_00 (96UL)
#define TRGM_TRGOCFG_TRGM_P_01 (97UL)
#define TRGM_TRGOCFG_TRGM_P_02 (98UL)
#define TRGM_TRGOCFG_TRGM_P_03 (99UL)
#define TRGM_TRGOCFG_TRGM_P_04 (100UL)
#define TRGM_TRGOCFG_TRGM_P_05 (101UL)
#define TRGM_TRGOCFG_TRGM_P_06 (102UL)
#define TRGM_TRGOCFG_TRGM_P_07 (103UL)
#define TRGM_TRGOCFG_PWM_IN8 (104UL)
#define TRGM_TRGOCFG_PWM_IN9 (105UL)
#define TRGM_TRGOCFG_PWM_IN10 (106UL)
#define TRGM_TRGOCFG_PWM_IN11 (107UL)
#define TRGM_TRGOCFG_PWM_IN12 (108UL)
#define TRGM_TRGOCFG_PWM_IN13 (109UL)
#define TRGM_TRGOCFG_PWM_IN14 (110UL)
#define TRGM_TRGOCFG_PWM_IN15 (111UL)
#define TRGM_TRGOCFG_PWM0_FRCI (112UL)
#define TRGM_TRGOCFG_PWM0_FRCSYNCI (113UL)
#define TRGM_TRGOCFG_PWM0_SYNCI (114UL)
#define TRGM_TRGOCFG_PWM0_SHRLDSYNCI (115UL)
#define TRGM_TRGOCFG_PWM0_FAULTI0 (116UL)
#define TRGM_TRGOCFG_PWM0_FAULTI1 (117UL)
#define TRGM_TRGOCFG_PWM1_FRCI (118UL)
#define TRGM_TRGOCFG_PWM1_FRCSYNCI (119UL)
#define TRGM_TRGOCFG_PWM1_SYNCI (120UL)
#define TRGM_TRGOCFG_PWM1_SHRLDSYNCI (121UL)
#define TRGM_TRGOCFG_PWM1_FAULTI0 (122UL)
#define TRGM_TRGOCFG_PWM1_FAULTI1 (123UL)
#define TRGM_TRGOCFG_RDC_TRIG_IN0 (124UL)
#define TRGM_TRGOCFG_RDC_TRIG_IN1 (125UL)
#define TRGM_TRGOCFG_SYNCTIMER_TRIG (126UL)
#define TRGM_TRGOCFG_QEI0_TRIG_IN (127UL)
#define TRGM_TRGOCFG_QEI1_TRIG_IN (128UL)
#define TRGM_TRGOCFG_QEI0_PAUSE (129UL)
#define TRGM_TRGOCFG_QEI1_PAUSE (130UL)
#define TRGM_TRGOCFG_UART_TRIG0 (131UL)
#define TRGM_TRGOCFG_UART_TRIG1 (132UL)
#define TRGM_TRGOCFG_TRGM_IRQ0 (133UL)
#define TRGM_TRGOCFG_TRGM_IRQ1 (134UL)
#define TRGM_TRGOCFG_TRGM_DMA0 (135UL)
#define TRGM_TRGOCFG_TRGM_DMA1 (136UL)

/* DMACFG register group index macro definition */
#define TRGM_DMACFG_0 (0UL)
#define TRGM_DMACFG_1 (1UL)
#define TRGM_DMACFG_2 (2UL)
#define TRGM_DMACFG_3 (3UL)
#define TRGM_DMACFG_4 (4UL)
#define TRGM_DMACFG_5 (5UL)
#define TRGM_DMACFG_6 (6UL)
#define TRGM_DMACFG_7 (7UL)

/* TRGM_IN register group index macro definition */
#define TRGM_TRGM_IN_0 (0UL)
#define TRGM_TRGM_IN_1 (1UL)
#define TRGM_TRGM_IN_2 (2UL)
#define TRGM_TRGM_IN_3 (3UL)

/* TRGM_OUT register group index macro definition */
#define TRGM_TRGM_OUT_0 (0UL)
#define TRGM_TRGM_OUT_1 (1UL)
#define TRGM_TRGM_OUT_2 (2UL)
#define TRGM_TRGM_OUT_3 (3UL)
#define TRGM_TRGM_OUT_4 (4UL)


#endif /* HPM_TRGM_H */
