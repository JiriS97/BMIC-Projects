/* Based on CPU DB MC9S08LH64_80, version 3.00.036 (RegistersPrg V2.32) */
/* DataSheet : MC9S08LH64RM Rev. 4 03/2009 */

#include <mc9s08lh64.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0x00000000 */
volatile PTADDSTR _PTADD;                                  /* Port A Data Direction Register; 0x00000001 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0x00000002 */
volatile PTBDDSTR _PTBDD;                                  /* Port B Data Direction Register; 0x00000003 */
volatile PTCDSTR _PTCD;                                    /* Port C Data Register; 0x00000004 */
volatile PTCDDSTR _PTCDD;                                  /* Port C Data Direction Register; 0x00000005 */
volatile PTDDSTR _PTDD;                                    /* Port D Data Register; 0x00000006 */
volatile PTDDDSTR _PTDDD;                                  /* Port D Data Direction Register; 0x00000007 */
volatile PTEDSTR _PTED;                                    /* Port E Data Register; 0x00000008 */
volatile PTEDDSTR _PTEDD;                                  /* Port E Data Direction Register; 0x00000009 */
volatile KBISCSTR _KBISC;                                  /* KBI Status and Control Register; 0x0000000C */
volatile KBIPESTR _KBIPE;                                  /* KBI Pin Enable Register; 0x0000000D */
volatile KBIESSTR _KBIES;                                  /* KBI Edge Select Register; 0x0000000E */
volatile IRQSCSTR _IRQSC;                                  /* Interrupt request status and control register; 0x0000000F */
volatile ADCSC1ASTR _ADCSC1A;                              /* Status and Control Register 1A; 0x00000010 */
volatile ADCSC1BSTR _ADCSC1B;                              /* Status and Control Register 1B; 0x00000011 */
volatile ADCCFG1STR _ADCCFG1;                              /* Configuration Register 1; 0x00000012 */
volatile ADCCFG2STR _ADCCFG2;                              /* Configuration Register 2; 0x00000013 */
volatile LCDC0STR _LCDC0;                                  /* LCD Control Register 0; 0x00000018 */
volatile LCDC1STR _LCDC1;                                  /* LCD Control Register 1; 0x00000019 */
volatile LCDSUPPLYSTR _LCDSUPPLY;                          /* LCD Voltage Supply Register; 0x0000001A */
volatile LCDRVCSTR _LCDRVC;                                /* LCD Regulated Voltage Control Register; 0x0000001B */
volatile LCDBCTLSTR _LCDBCTL;                              /* LCD Blink Control Register; 0x0000001C */
volatile LCDSSTR _LCDS;                                    /* LCD Status Register; 0x0000001D */
volatile ACMPSCSTR _ACMPSC;                                /* ACMP Status and Control Register; 0x0000001F */
volatile SCI1C1STR _SCI1C1;                                /* SCI1 Control Register 1; 0x00000022 */
volatile SCI1C2STR _SCI1C2;                                /* SCI1 Control Register 2; 0x00000023 */
volatile SCI1S1STR _SCI1S1;                                /* SCI1 Status Register 1; 0x00000024 */
volatile SCI1S2STR _SCI1S2;                                /* SCI1 Status Register 2; 0x00000025 */
volatile SCI1C3STR _SCI1C3;                                /* SCI1 Control Register 3; 0x00000026 */
volatile SCI1DSTR _SCI1D;                                  /* SCI1 Data Register; 0x00000027 */
volatile SPIC1STR _SPIC1;                                  /* SPI Control Register 1; 0x00000028 */
volatile SPIC2STR _SPIC2;                                  /* SPI Control Register 2; 0x00000029 */
volatile SPIBRSTR _SPIBR;                                  /* SPI Baud Rate Register; 0x0000002A */
volatile SPISSTR _SPIS;                                    /* SPI Status Register; 0x0000002B */
volatile SPIDSTR _SPID;                                    /* SPI Data Register; 0x0000002D */
volatile PPAGESTR _PPAGE;                                  /* Program Page Register; 0x00000030 */
volatile LAP2STR _LAP2;                                    /* Linear Address Pointer Register 2; 0x00000031 */
volatile LAP1STR _LAP1;                                    /* Linear Address Pointer Register 1; 0x00000032 */
volatile LAP0STR _LAP0;                                    /* Linear Address Pointer Register 0; 0x00000033 */
volatile LWPSTR _LWP;                                      /* Linear Word Post Increment Register; 0x00000034 */
volatile LBPSTR _LBP;                                      /* Linear Byte Post Increment Register; 0x00000035 */
volatile LBSTR _LB;                                        /* Linear Byte Register; 0x00000036 */
volatile LAPABSTR _LAPAB;                                  /* Linear Address Pointer Add Byte Register; 0x00000037 */
volatile ICSC1STR _ICSC1;                                  /* ICS Control Register 1; 0x00000038 */
volatile ICSC2STR _ICSC2;                                  /* ICS Control Register 2; 0x00000039 */
volatile ICSTRMSTR _ICSTRM;                                /* ICS Trim Register; 0x0000003A */
volatile ICSSCSTR _ICSSC;                                  /* ICS Status and Control Register; 0x0000003B */
volatile TPM1SCSTR _TPM1SC;                                /* TPM1 Status and Control Register; 0x00000040 */
volatile TPM1C0SCSTR _TPM1C0SC;                            /* TPM1 Timer Channel 0 Status and Control Register; 0x00000045 */
volatile TPM1C1SCSTR _TPM1C1SC;                            /* TPM1 Timer Channel 1 Status and Control Register; 0x00000048 */
volatile TPM2SCSTR _TPM2SC;                                /* TPM2 Status and Control Register; 0x00000050 */
volatile TPM2C0SCSTR _TPM2C0SC;                            /* TPM2 Timer Channel 0 Status and Control Register; 0x00000055 */
volatile TPM2C1SCSTR _TPM2C1SC;                            /* TPM2 Timer Channel 1 Status and Control Register; 0x00000058 */
volatile VREF1TRMSTR _VREF1TRM;                            /* VREF Trim Register; 0x0000005C */
volatile VREF1SCSTR _VREF1SC;                              /* VREF Control Register; 0x0000005D */
volatile VREF2TRMSTR _VREF2TRM;                            /* VREF Trim Register; 0x0000005E */
volatile VREF2SCSTR _VREF2SC;                              /* VREF Control Register; 0x0000005F */
volatile LCDPEN0STR _LCDPEN0;                              /* LCD Pin Enable Register 0; 0x00001000 */
volatile LCDPEN1STR _LCDPEN1;                              /* LCD Pin Enable Register 1; 0x00001001 */
volatile LCDPEN2STR _LCDPEN2;                              /* LCD Pin Enable Register 2; 0x00001002 */
volatile LCDPEN3STR _LCDPEN3;                              /* LCD Pin Enable Register 3; 0x00001003 */
volatile LCDPEN4STR _LCDPEN4;                              /* LCD Pin Enable Register 4; 0x00001004 */
volatile LCDPEN5STR _LCDPEN5;                              /* LCD Pin Enable Register 5; 0x00001005 */
volatile LCDBPEN0STR _LCDBPEN0;                            /* LCD Backplane Enable Register 0; 0x00001008 */
volatile LCDBPEN1STR _LCDBPEN1;                            /* LCD Backplane Enable Register 1; 0x00001009 */
volatile LCDBPEN2STR _LCDBPEN2;                            /* LCD Backplane Enable Register 2; 0x0000100A */
volatile LCDBPEN3STR _LCDBPEN3;                            /* LCD Backplane Enable Register 3; 0x0000100B */
volatile LCDBPEN4STR _LCDBPEN4;                            /* LCD Backplane Enable Register 4; 0x0000100C */
volatile LCDBPEN5STR _LCDBPEN5;                            /* LCD Backplane Enable Register 5; 0x0000100D */
volatile LCDWF0STR _LCDWF0;                                /* LCD Waveform Register 0; 0x00001010 */
volatile LCDWF1STR _LCDWF1;                                /* LCD Waveform Register 1; 0x00001011 */
volatile LCDWF2STR _LCDWF2;                                /* LCD Waveform Register 2; 0x00001012 */
volatile LCDWF3STR _LCDWF3;                                /* LCD Waveform Register 3; 0x00001013 */
volatile LCDWF4STR _LCDWF4;                                /* LCD Waveform Register 4; 0x00001014 */
volatile LCDWF5STR _LCDWF5;                                /* LCD Waveform Register 5; 0x00001015 */
volatile LCDWF6STR _LCDWF6;                                /* LCD Waveform Register 6; 0x00001016 */
volatile LCDWF7STR _LCDWF7;                                /* LCD Waveform Register 7; 0x00001017 */
volatile LCDWF8STR _LCDWF8;                                /* LCD Waveform Register 8; 0x00001018 */
volatile LCDWF9STR _LCDWF9;                                /* LCD Waveform Register 9; 0x00001019 */
volatile LCDWF10STR _LCDWF10;                              /* LCD Waveform Register 10; 0x0000101A */
volatile LCDWF11STR _LCDWF11;                              /* LCD Waveform Register 11; 0x0000101B */
volatile LCDWF12STR _LCDWF12;                              /* LCD Waveform Register 12; 0x0000101C */
volatile LCDWF13STR _LCDWF13;                              /* LCD Waveform Register 13; 0x0000101D */
volatile LCDWF14STR _LCDWF14;                              /* LCD Waveform Register 14; 0x0000101E */
volatile LCDWF15STR _LCDWF15;                              /* LCD Waveform Register 15; 0x0000101F */
volatile LCDWF16STR _LCDWF16;                              /* LCD Waveform Register 16; 0x00001020 */
volatile LCDWF17STR _LCDWF17;                              /* LCD Waveform Register 17; 0x00001021 */
volatile LCDWF18STR _LCDWF18;                              /* LCD Waveform Register 18; 0x00001022 */
volatile LCDWF19STR _LCDWF19;                              /* LCD Waveform Register 19; 0x00001023 */
volatile LCDWF20STR _LCDWF20;                              /* LCD Waveform Register 20; 0x00001024 */
volatile LCDWF21STR _LCDWF21;                              /* LCD Waveform Register 21; 0x00001025 */
volatile LCDWF22STR _LCDWF22;                              /* LCD Waveform Register 22; 0x00001026 */
volatile LCDWF23STR _LCDWF23;                              /* LCD Waveform Register 23; 0x00001027 */
volatile LCDWF24STR _LCDWF24;                              /* LCD Waveform Register 24; 0x00001028 */
volatile LCDWF25STR _LCDWF25;                              /* LCD Waveform Register 25; 0x00001029 */
volatile LCDWF26STR _LCDWF26;                              /* LCD Waveform Register 26; 0x0000102A */
volatile LCDWF27STR _LCDWF27;                              /* LCD Waveform Register 27; 0x0000102B */
volatile LCDWF28STR _LCDWF28;                              /* LCD Waveform Register 28; 0x0000102C */
volatile LCDWF29STR _LCDWF29;                              /* LCD Waveform Register 29; 0x0000102D */
volatile LCDWF30STR _LCDWF30;                              /* LCD Waveform Register 30; 0x0000102E */
volatile LCDWF31STR _LCDWF31;                              /* LCD Waveform Register 31; 0x0000102F */
volatile LCDWF32STR _LCDWF32;                              /* LCD Waveform Register 32; 0x00001030 */
volatile LCDWF33STR _LCDWF33;                              /* LCD Waveform Register 33; 0x00001031 */
volatile LCDWF34STR _LCDWF34;                              /* LCD Waveform Register 34; 0x00001032 */
volatile LCDWF35STR _LCDWF35;                              /* LCD Waveform Register 35; 0x00001033 */
volatile LCDWF36STR _LCDWF36;                              /* LCD Waveform Register 36; 0x00001034 */
volatile LCDWF37STR _LCDWF37;                              /* LCD Waveform Register 37; 0x00001035 */
volatile LCDWF38STR _LCDWF38;                              /* LCD Waveform Register 38; 0x00001036 */
volatile LCDWF39STR _LCDWF39;                              /* LCD Waveform Register 39; 0x00001037 */
volatile LCDWF40STR _LCDWF40;                              /* LCD Waveform Register 40; 0x00001038 */
volatile LCDWF41STR _LCDWF41;                              /* LCD Waveform Register 41; 0x00001039 */
volatile LCDWF42STR _LCDWF42;                              /* LCD Waveform Register 42; 0x0000103A */
volatile LCDWF43STR _LCDWF43;                              /* LCD Waveform Register 43; 0x0000103B */
volatile SRSSTR _SRS;                                      /* System Reset Status Register; 0x00001800 */
volatile SBDFRSTR _SBDFR;                                  /* System Background Debug Force Reset Register; 0x00001801 */
volatile SOPT1STR _SOPT1;                                  /* System Options Register 1; 0x00001802 */
volatile SOPT2STR _SOPT2;                                  /* System Options Register 2; 0x00001803 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0x00001808 */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0x00001809 */
volatile SPMSC3STR _SPMSC3;                                /* System Power Management Status and Control 3 Register; 0x0000180B */
volatile SCGC1STR _SCGC1;                                  /* System Clock Gating Control 1 Register; 0x0000180E */
volatile SCGC2STR _SCGC2;                                  /* System Clock Gating Control 2 Register; 0x0000180F */
volatile DBGCAXSTR _DBGCAX;                                /* Debug Comparator A Extension Register; 0x00001818 */
volatile DBGCBXSTR _DBGCBX;                                /* Debug Comparator B Extension Register; 0x00001819 */
volatile DBGCCXSTR _DBGCCX;                                /* Debug Comparator C Extension Register; 0x0000181A */
volatile DBGFXSTR _DBGFX;                                  /* Debug FIFO Extended Information Register; 0x0000181B */
volatile DBGCSTR _DBGC;                                    /* Debug Control Register; 0x0000181C */
volatile DBGTSTR _DBGT;                                    /* Debug Trigger Register; 0x0000181D */
volatile DBGSSTR _DBGS;                                    /* Debug Status Register; 0x0000181E */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Status Register; 0x0000181F */
volatile FCDIVSTR _FCDIV;                                  /* FLASH Clock Divider Register; 0x00001820 */
volatile FOPTSTR _FOPT;                                    /* Flash Options Register; 0x00001821 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00001823 */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register; 0x00001824 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00001825 */
volatile FCMDSTR _FCMD;                                    /* Flash Command Register; 0x00001826 */
volatile TODCSTR _TODC;                                    /* TOD Control Register; 0x00001830 */
volatile TODSCSTR _TODSC;                                  /* TOD Status and Control Register; 0x00001831 */
volatile TODMSTR _TODM;                                    /* TOD Match Register; 0x00001832 */
volatile TODCNTSTR _TODCNT;                                /* TOD Counter Register; 0x00001833 */
volatile PTAPESTR _PTAPE;                                  /* Port A Pull Enable Register; 0x00001840 */
volatile PTASESTR _PTASE;                                  /* Port A Slew Rate Enable Register; 0x00001841 */
volatile PTADSSTR _PTADS;                                  /* Port A Drive Strength Selection Register; 0x00001842 */
volatile PTBPESTR _PTBPE;                                  /* Port B Pull Enable Register; 0x00001844 */
volatile PTBSESTR _PTBSE;                                  /* Port B Slew Rate Enable Register; 0x00001845 */
volatile PTBDSSTR _PTBDS;                                  /* Port B Drive Strength Selection Register; 0x00001846 */
volatile PTCPESTR _PTCPE;                                  /* Port C Pull Enable Register; 0x00001848 */
volatile PTCSESTR _PTCSE;                                  /* Port C Slew Rate Enable Register; 0x00001849 */
volatile PTCDSSTR _PTCDS;                                  /* Port C Drive Strength Selection Register; 0x0000184A */
volatile PTDPESTR _PTDPE;                                  /* Port D Pull Enable Register; 0x0000184C */
volatile PTDSESTR _PTDSE;                                  /* Port D Slew Rate Enable Register; 0x0000184D */
volatile PTDDSSTR _PTDDS;                                  /* Port D Drive Strength Selection Register; 0x0000184E */
volatile PTEPESTR _PTEPE;                                  /* Port E Pull Enable Register; 0x00001850 */
volatile PTESESTR _PTESE;                                  /* Port E Slew Rate Enable Register; 0x00001851 */
volatile PTEDSSTR _PTEDS;                                  /* Port E Drive Strength Selection Register; 0x00001852 */
volatile SCI2C1STR _SCI2C1;                                /* SCI2 Control Register 1; 0x0000185A */
volatile SCI2C2STR _SCI2C2;                                /* SCI2 Control Register 2; 0x0000185B */
volatile SCI2S1STR _SCI2S1;                                /* SCI2 Status Register 1; 0x0000185C */
volatile SCI2S2STR _SCI2S2;                                /* SCI2 Status Register 2; 0x0000185D */
volatile SCI2C3STR _SCI2C3;                                /* SCI2 Control Register 3; 0x0000185E */
volatile SCI2DSTR _SCI2D;                                  /* SCI2 Data Register; 0x0000185F */
volatile IICASTR _IICA;                                    /* IIC Address Register; 0x00001860 */
volatile IICFSTR _IICF;                                    /* IIC Frequency Divider Register; 0x00001861 */
volatile IICC1STR _IICC1;                                  /* IIC Control Register 1; 0x00001862 */
volatile IICSSTR _IICS;                                    /* IIC Status Register; 0x00001863 */
volatile IICDSTR _IICD;                                    /* IIC Data I/O Register; 0x00001864 */
volatile IICC2STR _IICC2;                                  /* IIC Control Register 2; 0x00001865 */
volatile ADCSC2STR _ADCSC2;                                /* Status and Control Register 2; 0x00001884 */
volatile ADCSC3STR _ADCSC3;                                /* Status and Control Register 3; 0x00001885 */
volatile ADCCLPDSTR _ADCCLPD;                              /* Plus-Side General Calibration Value D Register; 0x0000188C */
volatile ADCCLPSSTR _ADCCLPS;                              /* Plus-Side General Calibration Value S Register; 0x0000188D */
volatile ADCCLP2STR _ADCCLP2;                              /* Plus-Side General Calibration Value 2 Register; 0x00001892 */
volatile ADCCLP1STR _ADCCLP1;                              /* Plus-Side General Calibration Value 1 Register; 0x00001893 */
volatile ADCCLP0STR _ADCCLP0;                              /* Plus-Side General Calibration Value 0 Register; 0x00001894 */
volatile ADCCLMDSTR _ADCCLMD;                              /* Minus-Side General Calibration Value D Register; 0x00001896 */
volatile ADCCLMSSTR _ADCCLMS;                              /* Minus-Side General Calibration Value S Register; 0x00001897 */
volatile ADCCLM2STR _ADCCLM2;                              /* Minus-Side General Calibration Value 2 Register; 0x0000189C */
volatile ADCCLM1STR _ADCCLM1;                              /* Minus-Side General Calibration Value 1 Register; 0x0000189D */
volatile ADCCLM0STR _ADCCLM0;                              /* Minus-Side General Calibration Value 0 Register; 0x0000189E */
volatile APCTL1STR _APCTL1;                                /* Pin Control 1 Register; 0x0000189F */
volatile APCTL2STR _APCTL2;                                /* Pin Control 2 Register; 0x000018A0 */
/* NVVREF1TRM - macro for reading non volatile register    Non-volatile VREF Trim Register; 0x0000FFAC */
/* Tip for register initialization in the user code:  const byte NVVREF1TRM_INIT @0x0000FFAC = <NVVREF1TRM_INITVAL>; */
/* NVVREF2TRM - macro for reading non volatile register    Non-volatile VREF Trim Register; 0x0000FFAD */
/* Tip for register initialization in the user code:  const byte NVVREF2TRM_INIT @0x0000FFAD = <NVVREF2TRM_INITVAL>; */
/* NVFTRIM - macro for reading non volatile register       Nonvolatile ICS Fine Trim; 0x0000FFAE */
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x0000FFAE = <NVFTRIM_INITVAL>; */
/* NVICSTRM - macro for reading non volatile register      Nonvolatile ICS Trim Register; 0x0000FFAF */
/* Tip for register initialization in the user code:  const byte NVICSTRM_INIT @0x0000FFAF = <NVICSTRM_INITVAL>; */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x0000FFB0 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x0000FFB1 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x0000FFB2 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x0000FFB3 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x0000FFB4 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x0000FFB5 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x0000FFB6 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x0000FFB7 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile Flash Protection Register; 0x0000FFBD */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
/* NVOPT - macro for reading non volatile register         Nonvolatile Flash Options Register; 0x0000FFBF */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ADCRASTR _ADCRA;                                  /* Data Result Register A; 0x00000014 */
volatile ADCRBSTR _ADCRB;                                  /* Data Result Register B; 0x00000016 */
volatile SCI1BDSTR _SCI1BD;                                /* SCI1 Baud Rate Register; 0x00000020 */
volatile TPM1CNTSTR _TPM1CNT;                              /* TPM1 Timer Counter Register; 0x00000041 */
volatile TPM1MODSTR _TPM1MOD;                              /* TPM1 Timer Counter Modulo Register; 0x00000043 */
volatile TPM1C0VSTR _TPM1C0V;                              /* TPM1 Timer Channel 0 Value Register; 0x00000046 */
volatile TPM1C1VSTR _TPM1C1V;                              /* TPM1 Timer Channel 1 Value Register; 0x00000049 */
volatile TPM2CNTSTR _TPM2CNT;                              /* TPM2 Timer Counter Register; 0x00000051 */
volatile TPM2MODSTR _TPM2MOD;                              /* TPM2 Timer Counter Modulo Register; 0x00000053 */
volatile TPM2C0VSTR _TPM2C0V;                              /* TPM2 Timer Channel 0 Value Register; 0x00000056 */
volatile TPM2C1VSTR _TPM2C1V;                              /* TPM2 Timer Channel 1 Value Register; 0x00000059 */
volatile SDIDSTR _SDID;                                    /* System Device Identification Register; 0x00001806 */
volatile DBGCASTR _DBGCA;                                  /* Debug Comparator A Register; 0x00001810 */
volatile DBGCBSTR _DBGCB;                                  /* Debug Comparator B Register; 0x00001812 */
volatile DBGCCSTR _DBGCC;                                  /* Debug Comparator C Register; 0x00001814 */
volatile DBGFSTR _DBGF;                                    /* Debug FIFO Register; 0x00001816 */
volatile SCI2BDSTR _SCI2BD;                                /* SCI2 Baud Rate Register; 0x00001858 */
volatile ADCCV1STR _ADCCV1;                                /* Compare Value 1 Register; 0x00001880 */
volatile ADCCV2STR _ADCCV2;                                /* Compare Value 2 Register; 0x00001882 */
volatile ADCOFSSTR _ADCOFS;                                /* Offset Correction Register; 0x00001886 */
volatile ADCPGSTR _ADCPG;                                  /* Plus-Side Gain Register; 0x00001888 */
volatile ADCMGSTR _ADCMG;                                  /* Minus-Side Gain Register; 0x0000188A */
volatile ADCCLP4STR _ADCCLP4;                              /* Plus-Side General Calibration Value 4 Register; 0x0000188E */
volatile ADCCLP3STR _ADCCLP3;                              /* Plus-Side General Calibration Value 3 Register; 0x00001890 */
volatile ADCCLM4STR _ADCCLM4;                              /* Minus-Side General Calibration Value 4 Register; 0x00001898 */
volatile ADCCLM3STR _ADCCLM3;                              /* Minus-Side General Calibration Value 3 Register; 0x0000189A */

/*lint -restore */

/* EOF */
