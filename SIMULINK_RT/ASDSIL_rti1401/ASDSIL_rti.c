/*********************** dSPACE target specific file *************************

   Include file ASDSIL_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1401 6.6 (29-Nov-2010)
   Thu Jun 23 15:37:14 2016

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "ASDSIL.h"
#include "ASDSIL_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             ASDSIL_B
#define RTP_STRUCTURE_NAME             ASDSIL_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti1401dio.h>
#include <rtican_ds1401.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* Timer Task 2. (Sample rate). */
static void rti_TIMERA2(rtk_p_task_control_block task)
{
  /* Task code. */
  sampleRateService(task);
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE I/O Board DS1_RTICAN #1 */

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M1_C2;

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_XTD;

/* ... definition of message variable for the RTICAN blocks */
can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* dSPACE I/O Board DS1_RTICAN #2 */

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M2_C1;

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M2_C1_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M2_C1_XTD;

/* ... definition of message variable for the RTICAN blocks */
can_tp1_canMsg* can_type1_msg_M2[CANTP1_M2_NUMMSG];

/* dSPACE I/O Board RTICAN_GLOBAL #0 */

/* This is the global time_sync_flag */
UInt32 rtican_time_sync_flag = 0;

/* dSPACE Test-Automation Stimulus Engine */
#define TA_STIMULUS_ENGINE_ENABLE      0

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  {
    ts_timestamp_type ts = { 0, 0 };

    host_service(1, &ts);
    DsDaq_Init(0, 32, 1);
  }
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1401, (void *) 0,
                        VCM_TXT_RTI1401, 6, 6, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 7, 11, 1,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 7, 6, 1,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 7, 6, 1,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }

    vcm_module_register(VCM_MID_RTICAN, (void *) 0,
                        VCM_TXT_RTICAN, 2, 7, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
  }

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Initialization of DS1501 board */
  can_tp1_communication_init(can_tp1_address_table[0].module_addr,
    CAN_TP1_INT_ENABLE);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 250 kbit/s */
  can_type1_channel_M1_C2 = can_tp1_channel_init(can_tp1_address_table[0].
    module_addr, 1, 250000, CAN_TP1_STD, CAN_TP1_NO_SUBINT);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M1_C2_STD = can_tp1_msg_tx_register(can_type1_channel_M1_C2, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M1_C2_XTD = can_tp1_msg_tx_register(can_type1_channel_M1_C2, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "AMB" Id:419362048 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF500] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 3, 419362048, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "AMB2" Id:419362087 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF527] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 4, 419362087, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "AT1T1I" Id:419321405 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FE563D] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 1, 419321405, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "IC1" Id:419362304 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF600] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 4, 419362304, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "DM01" Id:419351101 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FECA3D] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 1, 419351101, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "TPCM" Id:485293885 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CECFF3D] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 5, 485293885, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "CCVS1" Id:419361024 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF100] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 3, 419361024, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "EEC1" Id:217056256 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0XCF00400] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 0, 217056256, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "ET1" Id:419360256 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEEE00] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 2, 419360256, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "LFE" Id:419361280 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF200] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 3, 419361280, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "RQST" Id:418053949 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF3D] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 0, 418053949, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "RQST_ecu" Id:418053888 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF00] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 0, 418053888, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "TD" Id:419358446 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEE6EE] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 2, 419358446, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "TPDT" Id:485228349 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CEBFF3D] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 5, 485228349, CAN_TP1_EXT, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "AMB" Id:419362048 */
  ASDSIL_B.SFunction1_k = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "AMB2" Id:419362087 */
  ASDSIL_B.SFunction1_kw = 0;          /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "AT1T1I" Id:419321405 */
  ASDSIL_B.SFunction1_p = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "IC1" Id:419362304 */
  ASDSIL_B.SFunction1_j = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "DM01" Id:419351101 */
  ASDSIL_B.SFunction1_a = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "TPCM" Id:485293885 */
  ASDSIL_B.SFunction1_o = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "CCVS1" Id:419361024 */
  ASDSIL_B.SFunction1_d = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "EEC1" Id:217056256 */
  ASDSIL_B.SFunction1_o5 = 0;          /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "ET1" Id:419360256 */
  ASDSIL_B.SFunction1_f = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "LFE" Id:419361280 */
  ASDSIL_B.SFunction1_os = 0;          /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "RQST" Id:418053949 */
  ASDSIL_B.SFunction1_e = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "RQST_ecu" Id:418053888 */
  ASDSIL_B.SFunction1_en = 0;          /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "TD" Id:419358446 */
  ASDSIL_B.SFunction1_l = 0;           /* processed - flag */

  /* dSPACE RTICAN TX Message Block: "TPDT" Id:485228349 */
  ASDSIL_B.SFunction1_ec = 0;          /* processed - flag */

  /* dSPACE I/O Board DS1_RTICAN #2 */
  /* Initialization of DS1501 board */
  can_tp1_communication_init(can_tp1_address_table[1].module_addr,
    CAN_TP1_INT_ENABLE);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 250 kbit/s */
  can_type1_channel_M2_C1 = can_tp1_channel_init(can_tp1_address_table[1].
    module_addr, 0, 250000, CAN_TP1_STD, CAN_TP1_NO_SUBINT);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M2_C1_STD = can_tp1_msg_tx_register(can_type1_channel_M2_C1, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M2_C1_XTD = can_tp1_msg_tx_register(can_type1_channel_M2_C1, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "NOxSensorSignals" Id:82 */
  /* ... Register message */
  can_type1_msg_M2[CANTP1_M2_C1_TX_STD_0X52] = can_tp1_msg_tx_register
    (can_type1_channel_M2_C1, 0, 82, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "NOxSensorSignals" Id:82 */
  ASDSIL_B.SFunction1 = 0;             /* processed - flag */

  /* dSPACE I/O Board RTICAN_GLOBAL #0 */
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1401 #1 Unit:DS1401SLV */
  ds1401_slv_boot_finished();

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M1_C2, CAN_TP1_INT_DISABLE);

  /* Set the type1CAN error level */
  rtican_type1_error_level = 0;

  /* ... Reset all taskqueue-specific error variables */
  rtican_type1_tq_err_all_reset(0);

  /* ... Clear all message data buffers */
  can_tp1_all_data_clear(can_tp1_address_table[0].module_addr);

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF500])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][4] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF527])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FE563D])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][4] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF600])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FECA3D])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][5] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CECFF3D])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF100])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0XCF00400])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][2] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEEE00])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF200])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF3D])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF00])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][2] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEE6EE])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][5] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CEBFF3D])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  /* dSPACE I/O Board DS1_RTICAN #2 */
  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M2_C1, CAN_TP1_INT_DISABLE);

  /* Set the type1CAN error level */
  rtican_type1_error_level = 0;

  /* ... Reset all taskqueue-specific error variables */
  rtican_type1_tq_err_all_reset(1);

  /* ... Clear all message data buffers */
  can_tp1_all_data_clear(can_tp1_address_table[1].module_addr);

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[1][0] = can_tp1_msg_wakeup
              (can_type1_msg_M2[CANTP1_M2_C1_TX_STD_0X52])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

static void rti_mdl_timesync_simstate(void)
{
  /* ...... initiate single synchronisation after SIMSTATE changing */
  rtican_time_sync_flag = 0;
}

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);

  /* dSPACE I/O Board DIO_TYPE1 #1 */
  /* Check master - dio communication */
  {
    UInt32 dioErrorCode = 0;
    Int16 i;
    for (i = 0; i < RTI_DIO_TASKQUEUES_NUM_OF; i++) {
      dio_tp1_error_read(dio_tp1_address_table[0].module_addr, i, &dioErrorCode);
      rti1401dio_taskqueue_error_msg_typstr("1", "unknown", 1, i, dioErrorCode,
        RTI_DIO_ERROR_WARN);
    }
  }

  /* dSPACE I/O Board DS1_RTICAN #1 */
  {
    real_T bg_code_exec_time;
    static real_T bg_code_last_exec_time = 0.0;
    bg_code_exec_time = RTLIB_TIC_READ();
    if ((bg_code_exec_time - bg_code_last_exec_time) > 0.25 ||
        (bg_code_exec_time - bg_code_last_exec_time) < 0) {
      /* ... Check taskqueue-specific error variables */
      rtican_type1_tq_err_all_chk(can_tp1_address_table[0].module_addr, 0);
      bg_code_last_exec_time = bg_code_exec_time;
    }
  }

  /* copy DPMEM - buffers in background */
  {
    /* call update function for CAN Tp1 CAN interface (module number: 1) */
    can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
  }

  /* dSPACE I/O Board DS1_RTICAN #2 */
  {
    real_T bg_code_exec_time;
    static real_T bg_code_last_exec_time = 0.0;
    bg_code_exec_time = RTLIB_TIC_READ();
    if ((bg_code_exec_time - bg_code_last_exec_time) > 0.25 ||
        (bg_code_exec_time - bg_code_last_exec_time) < 0) {
      /* ... Check taskqueue-specific error variables */
      rtican_type1_tq_err_all_chk(can_tp1_address_table[1].module_addr, 1);
      bg_code_last_exec_time = bg_code_exec_time;
    }
  }

  /* copy DPMEM - buffers in background */
  {
    /* call update function for CAN Tp1 CAN interface (module number: 2) */
    can_tp1_msg_copy_all_to_mem(can_tp1_address_table[1].module_addr);
  }
}

/* Function rti_mdl_sample_input() is empty */
#define rti_mdl_sample_input()
#undef __INLINE

/****** [EOF] ****************************************************************/
