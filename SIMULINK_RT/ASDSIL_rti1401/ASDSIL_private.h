/*
 * ASDSIL_private.h
 *
 * Real-Time Workshop code generation for Simulink model "ASDSIL.mdl".
 *
 * Model version              : 1.10
 * Real-Time Workshop version : 7.6.1  (R2010bSP1)  28-Jan-2011
 * C source code generated on : Thu Jun 23 15:37:14 2016
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_ASDSIL_private_h_
#define RTW_HEADER_ASDSIL_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C2;

/* ... definition of message variable for the RTICAN blocks */
#define CANTP1_M1_NUMMSG               14

extern can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* ... variable for taskqueue error checking                  */
extern Int32 rtican_type1_tq_error[CAN_TYPE1_NUM_MODULES]
  [CAN_TYPE1_NUM_TASKQUEUES];

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M2_C1;

/* ... definition of message variable for the RTICAN blocks */
#define CANTP1_M2_NUMMSG               1

extern can_tp1_canMsg* can_type1_msg_M2[CANTP1_M2_NUMMSG];

/* ... variable for taskqueue error checking                  */
extern Int32 rtican_type1_tq_error[CAN_TYPE1_NUM_MODULES]
  [CAN_TYPE1_NUM_TASKQUEUES];

/* Declaration of user indices (CAN_Type1_M1) */
#define CANTP1_M1_C2_TX_XTD_0X18FEF500 0
#define TX_C2_XTD_0X18FEF500           0
#undef TX_C2_XTD_0X18FEF500
#define CANTP1_M1_C2_TX_XTD_0X18FEF527 1
#define TX_C2_XTD_0X18FEF527           1
#undef TX_C2_XTD_0X18FEF527
#define CANTP1_M1_C2_TX_XTD_0X18FE563D 2
#define TX_C2_XTD_0X18FE563D           2
#undef TX_C2_XTD_0X18FE563D
#define CANTP1_M1_C2_TX_XTD_0X18FEF600 3
#define TX_C2_XTD_0X18FEF600           3
#undef TX_C2_XTD_0X18FEF600
#define CANTP1_M1_C2_TX_XTD_0X18FECA3D 4
#define TX_C2_XTD_0X18FECA3D           4
#undef TX_C2_XTD_0X18FECA3D
#define CANTP1_M1_C2_TX_XTD_0X1CECFF3D 5
#define TX_C2_XTD_0X1CECFF3D           5
#undef TX_C2_XTD_0X1CECFF3D
#define CANTP1_M1_C2_TX_XTD_0X18FEF100 6
#define TX_C2_XTD_0X18FEF100           6
#undef TX_C2_XTD_0X18FEF100
#define CANTP1_M1_C2_TX_XTD_0XCF00400  7
#define TX_C2_XTD_0XCF00400            7
#undef TX_C2_XTD_0XCF00400
#define CANTP1_M1_C2_TX_XTD_0X18FEEE00 8
#define TX_C2_XTD_0X18FEEE00           8
#undef TX_C2_XTD_0X18FEEE00
#define CANTP1_M1_C2_TX_XTD_0X18FEF200 9
#define TX_C2_XTD_0X18FEF200           9
#undef TX_C2_XTD_0X18FEF200
#define CANTP1_M1_C2_TX_XTD_0X18EAFF3D 10
#define TX_C2_XTD_0X18EAFF3D           10
#undef TX_C2_XTD_0X18EAFF3D
#define CANTP1_M1_C2_TX_XTD_0X18EAFF00 11
#define TX_C2_XTD_0X18EAFF00           11
#undef TX_C2_XTD_0X18EAFF00
#define CANTP1_M1_C2_TX_XTD_0X18FEE6EE 12
#define TX_C2_XTD_0X18FEE6EE           12
#undef TX_C2_XTD_0X18FEE6EE
#define CANTP1_M1_C2_TX_XTD_0X1CEBFF3D 13
#define TX_C2_XTD_0X1CEBFF3D           13
#undef TX_C2_XTD_0X1CEBFF3D

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_XTD;

/* Declaration of user indices (CAN_Type1_M2) */
#define CANTP1_M2_C1_TX_STD_0X52       0
#define TX_C1_STD_0X52                 0
#undef TX_C1_STD_0X52

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M2_C1_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M2_C1_XTD;
extern void ds1401dac_t1(SimStruct *rts);
extern void ds1401dio_t1_bit_out(SimStruct *rts);

#endif                                 /* RTW_HEADER_ASDSIL_private_h_ */
