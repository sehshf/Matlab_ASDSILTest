/*
 * ASDSIL.c
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

#include "ASDSIL_trc_ptr.h"
#include "ASDSIL.h"
#include "ASDSIL_private.h"

/* Block signals (auto storage) */
BlockIO_ASDSIL ASDSIL_B;

/* Block states (auto storage) */
D_Work_ASDSIL ASDSIL_DWork;

/* Real-time model */
RT_MODEL_ASDSIL ASDSIL_M_;
RT_MODEL_ASDSIL *ASDSIL_M = &ASDSIL_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(ASDSIL_M, 1);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 * This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchagne data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ASDSIL_M->Timing.TaskCounters.TID[1])++;
  if ((ASDSIL_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    ASDSIL_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
static void ASDSIL_output0(int_T tid)  /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* user code (Output function Trailer for TID0) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  if (rtmIsSampleHit(ASDSIL_M, 0, tid)) {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
    DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as argument.
   * As result, some Output functions may have unused tid
   */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
static void ASDSIL_update0(int_T tid)  /* Sample time: [0.001s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ASDSIL_M->Timing.clockTick0)) {
    ++ASDSIL_M->Timing.clockTickH0;
  }

  ASDSIL_M->Timing.t[0] = ASDSIL_M->Timing.clockTick0 *
    ASDSIL_M->Timing.stepSize0 + ASDSIL_M->Timing.clockTickH0 *
    ASDSIL_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model output function for TID1 */
static void ASDSIL_output1(int_T tid)  /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp;

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S1>/KeyOn'
   *  Constant: '<S1>/Power'
   */
  ASDSIL_B.LogicalOperator = (ASDSIL_P.KeyOn_Value && ASDSIL_P.Power_Value);

  /* RateTransition: '<S1>/Rate Transition2' */
  ASDSIL_B.RateTransition2 = ASDSIL_B.LogicalOperator;

  /* Outputs for enable SubSystem: '<S1>/CANBUS2' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (ASDSIL_B.RateTransition2) {
    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Constant: '<S6>/BaroP'
     */
    ASDSIL_B.DataTypeConversion_b = ASDSIL_P.BaroP_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
     *  Constant: '<S6>/AmbAirT'
     */
    ASDSIL_B.DataTypeConversion1_n = ASDSIL_P.AmbAirT_Value;

    /* S-Function (rti_commonblock): '<S7>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "AMB" Id:419362048 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF500]);
      ASDSIL_B.SFunction1_k = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF500]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_BarometricPressure" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion_b - ( 0 ) )
          / 0.5 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_AmbientAirTemp" (24|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion1_n -
          ( -273 ) ) / 0.03125 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte1;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF500], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
     *  Constant: '<S6>/BaroPSrc'
     */
    ASDSIL_B.DataTypeConversion2_i = ASDSIL_P.BaroPSrc_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
     *  Constant: '<S6>/AmbAirTSrc'
     */
    ASDSIL_B.DataTypeConversion3_p = ASDSIL_P.AmbAirTSrc_Value;

    /* S-Function (rti_commonblock): '<S8>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "AMB2" Id:419362087 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF527]);
      ASDSIL_B.SFunction1_kw = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF527]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_BarometricPressureSrc39" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion2_i - ( 0 )
          ) / 0.5 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_AmbientAirTempSrc39" (24|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion3_p -
          ( -273 ) ) / 0.03125 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte1;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF527], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion14' incorporates:
     *  Constant: '<S6>/FldTankLvl'
     */
    ASDSIL_B.DataTypeConversion14 = ASDSIL_P.FldTankLvl_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion15' incorporates:
     *  Constant: '<S6>/FldTankT'
     */
    ASDSIL_B.DataTypeConversion15 = ASDSIL_P.FldTankT_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion16' incorporates:
     *  Constant: '<S6>/FldTankLvl2'
     */
    ASDSIL_B.DataTypeConversion16 = ASDSIL_P.FldTankLvl2_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion17' incorporates:
     *  Constant: '<S6>/FldTankLvlPrelFMI'
     */
    ASDSIL_B.DataTypeConversion17 = ASDSIL_P.FldTankLvlPrelFMI_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion18' incorporates:
     *  Constant: '<S6>/CatRednOpertrInduc'
     */
    ASDSIL_B.DataTypeConversion18 = ASDSIL_P.CatRednOpertrInduc_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion19' incorporates:
     *  Constant: '<S6>/FldTank1TPrelFMI'
     */
    ASDSIL_B.DataTypeConversion19 = ASDSIL_P.FldTank1TPrelFMI_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion12' incorporates:
     *  Constant: '<S6>/OpertrInducSev'
     */
    ASDSIL_B.DataTypeConversion12 = ASDSIL_P.OpertrInducSev_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion13' incorporates:
     *  Constant: '<S6>/FldTankHeatr'
     */
    ASDSIL_B.DataTypeConversion13 = ASDSIL_P.FldTankHeatr_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion20' incorporates:
     *  Constant: '<S6>/FldTank1HeatrPrelFMI'
     */
    ASDSIL_B.DataTypeConversion20 = ASDSIL_P.FldTank1HeatrPrelFMI_Value;

    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "AT1T1I" Id:419321405 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FE563D]);
      ASDSIL_B.SFunction1_p = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FE563D]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_Fluid_Tank_Level" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion14 - ( 0 ) )
          / 0.4 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Fluid_Tank_Temperature" (8|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion15 - ( -40 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Fluid_Tank_Level_2" (16|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion16 - ( 0 ) )
          / 0.1 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "ecu_Fluid_Tank_Level_Preliminary_FMI" (32|5, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion17 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000001F;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Catalytic_Reduction_Operator_Inducement" (37|3, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion18 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000007;
        CAN_Sgn.UnsignedSgn <<= 5;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Fluid_Tank_1_Temperature_Preliminary_FMI" (40|5, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion19 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000001F;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Operator_Inducement_Severity" (45|3, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion12 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000007;
        CAN_Sgn.UnsignedSgn <<= 5;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Fluid_Tank_Heater" (48|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion13 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Fluid_Tank_1_Heater_Preliminary_FMI" (56|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion20 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FE563D], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion37' incorporates:
     *  Constant: '<S6>/EngIntkMnfldP'
     */
    ASDSIL_B.DataTypeConversion37 = ASDSIL_P.EngIntkMnfldP_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion38' incorporates:
     *  Constant: '<S6>/EngIntkManfldT'
     */
    ASDSIL_B.DataTypeConversion38 = ASDSIL_P.EngIntkManfldT_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion39' incorporates:
     *  Constant: '<S6>/AirIntkP'
     */
    ASDSIL_B.DataTypeConversion39 = ASDSIL_P.AirIntkP_Value;

    /* S-Function (rti_commonblock): '<S15>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "IC1" Id:419362304 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF600]);
      ASDSIL_B.SFunction1_j = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF600]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_EngineIntakeManifoldPressure" (8|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion37 - ( 0 ) )
          / 2 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineIntakeManifoldTemperature" (16|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion38 - ( -40 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_AirIntakePressure" (24|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion39 - ( 0 ) )
          / 2 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF600], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion24' incorporates:
     *  Constant: '<S6>/ProtnLamp'
     */
    ASDSIL_B.DataTypeConversion24 = ASDSIL_P.ProtnLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion31' incorporates:
     *  Constant: '<S6>/AmberWarnLamp'
     */
    ASDSIL_B.DataTypeConversion31 = ASDSIL_P.AmberWarnLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion22' incorporates:
     *  Constant: '<S6>/RedStopLamp'
     */
    ASDSIL_B.DataTypeConversion22 = ASDSIL_P.RedStopLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion23' incorporates:
     *  Constant: '<S6>/MalfcnIndcrLamp'
     */
    ASDSIL_B.DataTypeConversion23 = ASDSIL_P.MalfcnIndcrLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion25' incorporates:
     *  Constant: '<S6>/FlsProtnLamp'
     */
    ASDSIL_B.DataTypeConversion25 = ASDSIL_P.FlsProtnLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion26' incorporates:
     *  Constant: '<S6>/FlsAmberWarnLamp'
     */
    ASDSIL_B.DataTypeConversion26 = ASDSIL_P.FlsAmberWarnLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion27' incorporates:
     *  Constant: '<S6>/FlsRedStopLamp'
     */
    ASDSIL_B.DataTypeConversion27 = ASDSIL_P.FlsRedStopLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion28' incorporates:
     *  Constant: '<S6>/FlsMalfcnIndcrLamp'
     */
    ASDSIL_B.DataTypeConversion28 = ASDSIL_P.FlsMalfcnIndcrLamp_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion29' incorporates:
     *  Constant: '<S6>/SuspcPrmNo'
     */
    ASDSIL_B.DataTypeConversion29 = ASDSIL_P.SuspcPrmNo_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion30' incorporates:
     *  Constant: '<S6>/FaiModId'
     */
    ASDSIL_B.DataTypeConversion30 = ASDSIL_P.FaiModId_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion32' incorporates:
     *  Constant: '<S6>/OccCt'
     */
    ASDSIL_B.DataTypeConversion32 = ASDSIL_P.OccCt_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion33' incorporates:
     *  Constant: '<S6>/SPNCnvnMeth'
     */
    ASDSIL_B.DataTypeConversion33 = ASDSIL_P.SPNCnvnMeth_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion34' incorporates:
     *  Constant: '<S6>/Blank1'
     */
    ASDSIL_B.DataTypeConversion34 = ASDSIL_P.Blank1_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion35' incorporates:
     *  Constant: '<S6>/Blank2'
     */
    ASDSIL_B.DataTypeConversion35 = ASDSIL_P.Blank2_Value;

    /* S-Function (rti_commonblock): '<S12>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "DM01" Id:419351101 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FECA3D]);
      ASDSIL_B.SFunction1_a = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FECA3D]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_Protect_Lamp" (0|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion24 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Amber_Warning_Lamp" (2|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion31 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 2;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Red_Stop_Lamp" (4|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion22 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 4;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Malfunction_Indicator_Lamp" (6|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion23 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 6;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Flash_Protect_Lamp" (8|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion25 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Flash_Amber_Warning_Lamp" (10|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion26 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 2;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Flash_Red_Stop_Lamp" (12|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion27 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 4;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Flash_Malfunction_Indicator_Lamp" (14|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion28 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 6;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Suspect_Parameter_Number" (29|19, standard signal, unsigned int, motorola back.) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion29 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0007FFFF;
        CAN_Sgn.UnsignedSgn <<= 5;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte1;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;

        /* ...... "ecu_Failure_Mode_Identifier" (32|5, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion30 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000001F;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Occurrence_Count" (40|7, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion32 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000007F;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_SPN_Conversion_Method" (47|1, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion33 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000001;
        CAN_Sgn.UnsignedSgn <<= 7;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Blank1" (48|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion34 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_Blank2" (56|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion35 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FECA3D], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion55' incorporates:
     *  Constant: '<S6>/CtlByte'
     */
    ASDSIL_B.DataTypeConversion55 = ASDSIL_P.CtlByte_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion56' incorporates:
     *  Constant: '<S6>/TotMsgSize'
     */
    ASDSIL_B.DataTypeConversion56 = ASDSIL_P.TotMsgSize_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion57' incorporates:
     *  Constant: '<S6>/NoOfPckg'
     */
    ASDSIL_B.DataTypeConversion57 = ASDSIL_P.NoOfPckg_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion58' incorporates:
     *  Constant: '<S6>/Blank'
     */
    ASDSIL_B.DataTypeConversion58 = ASDSIL_P.Blank_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion59' incorporates:
     *  Constant: '<S6>/ReqPGN'
     */
    ASDSIL_B.DataTypeConversion59 = ASDSIL_P.ReqPGN_Value;

    /* S-Function (rti_commonblock): '<S20>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "TPCM" Id:485293885 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CECFF3D]);
      ASDSIL_B.SFunction1_o = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CECFF3D]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "eec_CtrlByte" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion55 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_TotalMsgSize" (8|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion56 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "eec_NumOfPackages" (24|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion57 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_blank" (32|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion58 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_ReqPGN" (40|24, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion59 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00FFFFFF;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte1;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte2;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CECFF3D], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion21' incorporates:
     *  Constant: '<S6>/WhlBasdVehSpd'
     */
    ASDSIL_B.DataTypeConversion21 = ASDSIL_P.WhlBasdVehSpd_Value;

    /* S-Function (rti_commonblock): '<S11>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "CCVS1" Id:419361024 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF100]);
      ASDSIL_B.SFunction1_d = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF100]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_WheelBasedVehicleSpeed" (8|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion21 - ( 0 ) )
          / 0.00390625 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte1;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF100], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion10' incorporates:
     *  Constant: '<S6>/EngStrtrMod'
     */
    ASDSIL_B.DataTypeConversion10 = ASDSIL_P.EngStrtrMod_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion11' incorporates:
     *  Constant: '<S6>/EngDmdTq'
     */
    ASDSIL_B.DataTypeConversion11 = ASDSIL_P.EngDmdTq_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion4' incorporates:
     *  Constant: '<S6>/EngTqMod'
     */
    ASDSIL_B.DataTypeConversion4_j = ASDSIL_P.EngTqMod_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion5' incorporates:
     *  Constant: '<S6>/EngTqHiRes'
     */
    ASDSIL_B.DataTypeConversion5_e = ASDSIL_P.EngTqHiRes_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion6' incorporates:
     *  Constant: '<S6>/DrvrDmdTq'
     */
    ASDSIL_B.DataTypeConversion6_p = ASDSIL_P.DrvrDmdTq_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion7' incorporates:
     *  Constant: '<S6>/EngTq'
     */
    ASDSIL_B.DataTypeConversion7_e = ASDSIL_P.EngTq_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion8' incorporates:
     *  Constant: '<S6>/EngSpd'
     */
    ASDSIL_B.DataTypeConversion8 = ASDSIL_P.EngSpd_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion9' incorporates:
     *  Constant: '<S6>/SrcAdrEEC'
     */
    ASDSIL_B.DataTypeConversion9 = ASDSIL_P.SrcAdrEEC_Value;

    /* S-Function (rti_commonblock): '<S13>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "EEC1" Id:217056256 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0XCF00400]);
      ASDSIL_B.SFunction1_o5 = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0XCF00400]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_EngineTorqueMode" (0|4, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion4_j ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000000F;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineTorqueHiRes" (4|4, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion5_e - ( 0 )
          ) / 0.125 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000000F;
        CAN_Sgn.UnsignedSgn <<= 4;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_DriversDemandTorque" (8|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion6_p - ( -125 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineTorque" (16|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion7_e - ( -125 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineSpeed" (24|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion8 - ( 0 ) )
          / 0.125 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "ecu_SourceAddressEEC" (40|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion9 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineStarterMode" (48|4, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion10 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000000F;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineDemandTorque" (56|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion11 - ( -125 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0XCF00400], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion36' incorporates:
     *  Constant: '<S6>/TCoolt'
     */
    ASDSIL_B.DataTypeConversion36 = ASDSIL_P.TCoolt_Value;

    /* S-Function (rti_commonblock): '<S14>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "ET1" Id:419360256 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEEE00]);
      ASDSIL_B.SFunction1_f = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEEE00]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_tCoolt" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion36 - ( -40 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEEE00], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion40' incorporates:
     *  Constant: '<S6>/EngFuRate'
     */
    ASDSIL_B.DataTypeConversion40 = ASDSIL_P.EngFuRate_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion41' incorporates:
     *  Constant: '<S6>/EngInstFuEco'
     */
    ASDSIL_B.DataTypeConversion41 = ASDSIL_P.EngInstFuEco_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion42' incorporates:
     *  Constant: '<S6>/EngAvrFuEco'
     */
    ASDSIL_B.DataTypeConversion42 = ASDSIL_P.EngAvrFuEco_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion43' incorporates:
     *  Constant: '<S6>/EngThrPosn'
     */
    ASDSIL_B.DataTypeConversion43 = ASDSIL_P.EngThrPosn_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion44' incorporates:
     *  Constant: '<S6>/EngThr2Posn'
     */
    ASDSIL_B.DataTypeConversion44 = ASDSIL_P.EngThr2Posn_Value;

    /* S-Function (rti_commonblock): '<S16>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "LFE" Id:419361280 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF200]);
      ASDSIL_B.SFunction1_os = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF200]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_EngineFuelRate" (0|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion40 - ( 0 ) )
          / 0.05 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "ecu_EngineInstFuelEconomy" (16|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion41 - ( 0 ) )
          / 0.00195313 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "ecu_EngineAvrFuelEconomy" (32|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion42 - ( 0 ) )
          / 0.00195312 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "ecu_EngineThrottlePosition" (48|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion43 - ( 0 ) )
          / 0.4 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_EngineThrottle2Position" (56|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion44 - ( 0 ) )
          / 0.4 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF200], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion45' incorporates:
     *  Constant: '<S6>/PGNReg'
     */
    ASDSIL_B.DataTypeConversion45 = ASDSIL_P.PGNReg_Value;

    /* S-Function (rti_commonblock): '<S17>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "RQST" Id:418053949 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF3D]);
      ASDSIL_B.SFunction1_e = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF3D]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "eec_PGNRequested" (0|24, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion45 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00FFFFFF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF3D], 3,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion46' incorporates:
     *  Constant: '<S6>/PGNReqEcu'
     */
    ASDSIL_B.DataTypeConversion46 = ASDSIL_P.PGNReqEcu_Value;

    /* S-Function (rti_commonblock): '<S18>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "RQST_ecu" Id:418053888 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF00]);
      ASDSIL_B.SFunction1_en = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF00]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_PGNRequested" (0|24, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion46 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00FFFFFF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF00], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion47' incorporates:
     *  Constant: '<S6>/TiMinOfs'
     */
    ASDSIL_B.DataTypeConversion47 = ASDSIL_P.TiMinOfs_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion48' incorporates:
     *  Constant: '<S6>/TiHrOfs'
     */
    ASDSIL_B.DataTypeConversion48 = ASDSIL_P.TiHrOfs_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion49' incorporates:
     *  Constant: '<S6>/TiSec'
     */
    ASDSIL_B.DataTypeConversion49 = ASDSIL_P.TiSec_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion50' incorporates:
     *  Constant: '<S6>/TiMin'
     */
    ASDSIL_B.DataTypeConversion50 = ASDSIL_P.TiMin_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion51' incorporates:
     *  Constant: '<S6>/TiHr'
     */
    ASDSIL_B.DataTypeConversion51 = ASDSIL_P.TiHr_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion52' incorporates:
     *  Constant: '<S6>/TiMonth'
     */
    ASDSIL_B.DataTypeConversion52 = ASDSIL_P.TiMonth_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion53' incorporates:
     *  Constant: '<S6>/TiDay'
     */
    ASDSIL_B.DataTypeConversion53 = ASDSIL_P.TiDay_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion54' incorporates:
     *  Constant: '<S6>/TiYear'
     */
    ASDSIL_B.DataTypeConversion54 = ASDSIL_P.TiYear_Value;

    /* S-Function (rti_commonblock): '<S19>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "TD" Id:419358446 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEE6EE]);
      ASDSIL_B.SFunction1_l = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEE6EE]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "ecu_tiSec" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion49 - ( 0 ) )
          / 0.25 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiMin" (8|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion50 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiHours" (16|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion51 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiMonth" (24|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion52 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiDay" (32|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion53 - ( 0 ) )
          / 0.25 + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiYear" (40|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion54 - ( 1985 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiMinOffs" (48|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion47 - ( -125 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "ecu_tiHoursOffs" (56|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (ASDSIL_B.DataTypeConversion48 - ( -125 )
          + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEE6EE], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion60' incorporates:
     *  Constant: '<S6>/SeqNo'
     */
    ASDSIL_B.DataTypeConversion60 = ASDSIL_P.SeqNo_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion61' incorporates:
     *  Constant: '<S6>/PcktDa1'
     */
    ASDSIL_B.DataTypeConversion61 = ASDSIL_P.PcktDa1_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion62' incorporates:
     *  Constant: '<S6>/PcktDa2'
     */
    ASDSIL_B.DataTypeConversion62 = ASDSIL_P.PcktDa2_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion63' incorporates:
     *  Constant: '<S6>/PcktDa3'
     */
    ASDSIL_B.DataTypeConversion63 = ASDSIL_P.PcktDa3_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion64' incorporates:
     *  Constant: '<S6>/PcktDa4'
     */
    ASDSIL_B.DataTypeConversion64 = ASDSIL_P.PcktDa4_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion65' incorporates:
     *  Constant: '<S6>/PcktDa5'
     */
    ASDSIL_B.DataTypeConversion65 = ASDSIL_P.PcktDa5_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion66' incorporates:
     *  Constant: '<S6>/PcktDa6'
     */
    ASDSIL_B.DataTypeConversion66 = ASDSIL_P.PcktDa6_Value;

    /* DataTypeConversion: '<S6>/Data Type Conversion67' incorporates:
     *  Constant: '<S6>/PcktDa7'
     */
    ASDSIL_B.DataTypeConversion67 = ASDSIL_P.PcktDa7_Value;

    /* S-Function (rti_commonblock): '<S21>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "TPDT" Id:485228349 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CEBFF3D]);
      ASDSIL_B.SFunction1_ec = (real_T)
        can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CEBFF3D]->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "eec_SeqNumber" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion60 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData1" (8|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion61 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData2" (16|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion62 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData3" (24|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion63 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData4" (32|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion64 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData5" (40|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion65 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData6" (48|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion66 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "eec_PacketData7" (56|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion67 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CEBFF3D], 8,
                       &(CAN_Msg[0]), delayTime);
    }

    /* S-Function (rti_commonblock): '<S10>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */
  }

  /* end of Outputs for SubSystem: '<S1>/CANBUS2' */

  /* Level2 S-Function Block: '<S3>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[1];
    sfcnOutputs(rts, 1);
  }

  /* S-Function (rti_commonblock): '<S3>/diocheck' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S3>/slvload' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Level2 S-Function Block: '<S4>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[2];
    sfcnOutputs(rts, 1);
  }

  /* S-Function (rti_commonblock): '<S4>/diocheck' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S4>/slvload' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* RateTransition: '<S1>/Rate Transition1' incorporates:
   *  Constant: '<S1>/Power'
   */
  ASDSIL_B.RateTransition1 = ASDSIL_P.Power_Value;

  /* Outputs for enable SubSystem: '<S1>/SENSORS' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (ASDSIL_B.RateTransition1) {
    /* Sum: '<S27>/Sum' incorporates:
     *  Constant: '<S27>/ZeroCelciusToKelvin'
     *  Constant: '<S5>/InletT'
     */
    ASDSIL_B.Sum = ASDSIL_P.InletT_Value - ASDSIL_P.ZeroCelciusToKelvin_Value;

    /* Product: '<S27>/Product1' */
    ASDSIL_B.Product1 = ASDSIL_B.Sum * ASDSIL_B.Sum;

    /* SignalConversion: '<S27>/TmpSignal ConversionAtProduct2Inport2' incorporates:
     *  Constant: '<S27>/Constant'
     */
    ASDSIL_B.TmpSignalConversionAtProduct2In[0] = ASDSIL_P.Constant_Value;
    ASDSIL_B.TmpSignalConversionAtProduct2In[1] = ASDSIL_B.Sum;
    ASDSIL_B.TmpSignalConversionAtProduct2In[2] = ASDSIL_B.Product1;

    /* Product: '<S27>/Product2' incorporates:
     *  Constant: '<S27>/TSnsrVect'
     */
    tmp = ASDSIL_P.TSnsrVect_Value[0] *
      ASDSIL_B.TmpSignalConversionAtProduct2In[0];
    tmp += ASDSIL_P.TSnsrVect_Value[1] *
      ASDSIL_B.TmpSignalConversionAtProduct2In[1];
    tmp += ASDSIL_P.TSnsrVect_Value[2] *
      ASDSIL_B.TmpSignalConversionAtProduct2In[2];
    ASDSIL_B.Product2 = tmp;

    /* Product: '<S27>/Product' incorporates:
     *  Constant: '<S27>/R0'
     */
    ASDSIL_B.Product = ASDSIL_P.R0_Value * ASDSIL_B.Product2;

    /* Sum: '<S28>/Sum' incorporates:
     *  Constant: '<S28>/PuUpR'
     */
    ASDSIL_B.Sum_p = ASDSIL_B.Product + ASDSIL_P.PuUpR_Value;

    /* Product: '<S28>/Divide' incorporates:
     *  Constant: '<S28>/PuUpU'
     */
    ASDSIL_B.Divide = ASDSIL_P.PuUpU_Value * ASDSIL_B.Product / ASDSIL_B.Sum_p;

    /* Gain: '<S23>/DAC_Gain' */
    ASDSIL_B.DAC_Gain = ASDSIL_P.DAC_Gain_Gain * ASDSIL_B.Divide;

    /* Sum: '<S23>/Sum' incorporates:
     *  Constant: '<S23>/CalBias'
     */
    ASDSIL_B.Sum_m = ASDSIL_B.DAC_Gain + ASDSIL_P.CalBias_Value;

    /* Level2 S-Function Block: '<S26>/DS1401DAC_T1_SFCN1' (ds1401dac_t1) */
    {
      SimStruct *rts = ASDSIL_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/NOxConcent'
     */
    ASDSIL_B.DataTypeConversion = ASDSIL_P.NOxConcent_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion1' incorporates:
     *  Constant: '<S5>/O2Concent'
     */
    ASDSIL_B.DataTypeConversion1 = ASDSIL_P.O2Concent_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion2' incorporates:
     *  Constant: '<S5>/NOxSenSt'
     */
    ASDSIL_B.DataTypeConversion2 = ASDSIL_P.NOxSenSt_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion3' incorporates:
     *  Constant: '<S5>/NOxHeatrErr'
     */
    ASDSIL_B.DataTypeConversion3 = ASDSIL_P.NOxHeatrErr_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion4' incorporates:
     *  Constant: '<S5>/NOxHeatrMode'
     */
    ASDSIL_B.DataTypeConversion4 = ASDSIL_P.NOxHeatrMode_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion5' incorporates:
     *  Constant: '<S5>/NOxErr'
     */
    ASDSIL_B.DataTypeConversion5 = ASDSIL_P.NOxErr_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion6' incorporates:
     *  Constant: '<S5>/NOxDiagFb'
     */
    ASDSIL_B.DataTypeConversion6 = ASDSIL_P.NOxDiagFb_Value;

    /* DataTypeConversion: '<S22>/Data Type Conversion7' incorporates:
     *  Constant: '<S5>/O2Err'
     */
    ASDSIL_B.DataTypeConversion7 = ASDSIL_P.O2Err_Value;

    /* S-Function (rti_commonblock): '<S25>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE RTICAN TX Message Block: "NOxSensorSignals" Id:82 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M2[CANTP1_M2_C1_TX_STD_0X52]);
      ASDSIL_B.SFunction1 = (real_T)can_type1_msg_M2[CANTP1_M2_C1_TX_STD_0X52]
        ->processed;

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "NOxConcent" (0|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "O2Concent" (16|16, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion1 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte1;

        /* ...... "Status" (32|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion2 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "HeaterErr" (40|5, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion3 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000001F;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "HeaterMode" (45|2, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion4 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000003;
        CAN_Sgn.UnsignedSgn <<= 5;
        CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "NOxErr" (48|5, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion5 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000001F;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "DiagFb" (53|3, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion6 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x00000007;
        CAN_Sgn.UnsignedSgn <<= 5;
        CAN_Msg[6] |= CAN_Sgn.SgnBytes.Byte0;

        /* ...... "O2Err" (56|5, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( ASDSIL_B.DataTypeConversion7 ) + 0.5);
        CAN_Sgn.UnsignedSgn &= 0x0000001F;
        CAN_Msg[7] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M2[CANTP1_M2_C1_TX_STD_0X52], 8, &(CAN_Msg
        [0]), delayTime);
    }

    /* S-Function (rti_commonblock): '<S24>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */
  }

  /* end of Outputs for SubSystem: '<S1>/SENSORS' */
  /* user code (Output function Trailer for TID1) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  if (rtmIsSampleHit(ASDSIL_M, 0, tid)) {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
    DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as argument.
   * As result, some Output functions may have unused tid
   */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID1 */
static void ASDSIL_update1(int_T tid)  /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ASDSIL_M->Timing.clockTick1)) {
    ++ASDSIL_M->Timing.clockTickH1;
  }

  ASDSIL_M->Timing.t[1] = ASDSIL_M->Timing.clockTick1 *
    ASDSIL_M->Timing.stepSize1 + ASDSIL_M->Timing.clockTickH1 *
    ASDSIL_M->Timing.stepSize1 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

static void ASDSIL_output(int_T tid)
{
  switch (tid) {
   case 0 :
    ASDSIL_output0(0);
    break;

   case 1 :
    ASDSIL_output1(1);
    break;

   default :
    break;
  }
}

static void ASDSIL_update(int_T tid)
{
  switch (tid) {
   case 0 :
    ASDSIL_update0(0);
    break;

   case 1 :
    ASDSIL_update1(1);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ASDSIL_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ASDSIL_M, 0,
                sizeof(RT_MODEL_ASDSIL));
  rtsiSetSolverName(&ASDSIL_M->solverInfo,"FixedStepDiscrete");
  ASDSIL_M->solverInfoPtr = (&ASDSIL_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ASDSIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ASDSIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ASDSIL_M->Timing.sampleTimes = (&ASDSIL_M->Timing.sampleTimesArray[0]);
    ASDSIL_M->Timing.offsetTimes = (&ASDSIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ASDSIL_M->Timing.sampleTimes[0] = (0.001);
    ASDSIL_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    ASDSIL_M->Timing.offsetTimes[0] = (0.0);
    ASDSIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ASDSIL_M, &ASDSIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ASDSIL_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = ASDSIL_M->Timing.perTaskSampleHitsArray;
    ASDSIL_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    ASDSIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ASDSIL_M, -1);
  ASDSIL_M->Timing.stepSize0 = 0.001;
  ASDSIL_M->Timing.stepSize1 = 0.1;
  ASDSIL_M->solverInfoPtr = (&ASDSIL_M->solverInfo);
  ASDSIL_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&ASDSIL_M->solverInfo, 0.001);
  rtsiSetSolverMode(&ASDSIL_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  ASDSIL_M->ModelData.blockIO = ((void *) &ASDSIL_B);
  (void) memset(((void *) &ASDSIL_B), 0,
                sizeof(BlockIO_ASDSIL));

  /* parameters */
  ASDSIL_M->ModelData.defaultParam = ((real_T *)&ASDSIL_P);

  /* states (dwork) */
  ASDSIL_M->Work.dwork = ((void *) &ASDSIL_DWork);
  (void) memset((void *)&ASDSIL_DWork, 0,
                sizeof(D_Work_ASDSIL));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &ASDSIL_M->NonInlinedSFcns.sfcnInfo;
    ASDSIL_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(ASDSIL_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &ASDSIL_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(ASDSIL_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ASDSIL_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(ASDSIL_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(ASDSIL_M));
    rtssSetStepSizePtr(sfcnInfo, &ASDSIL_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(ASDSIL_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ASDSIL_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &ASDSIL_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &ASDSIL_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &ASDSIL_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &ASDSIL_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ASDSIL_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &ASDSIL_M->solverInfoPtr);
  }

  ASDSIL_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&ASDSIL_M->NonInlinedSFcns.childSFunctions[0], 0,
                  3*sizeof(SimStruct));
    ASDSIL_M->childSfunctions = (&ASDSIL_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    ASDSIL_M->childSfunctions[0] = (&ASDSIL_M->NonInlinedSFcns.childSFunctions[0]);
    ASDSIL_M->childSfunctions[1] = (&ASDSIL_M->NonInlinedSFcns.childSFunctions[1]);
    ASDSIL_M->childSfunctions[2] = (&ASDSIL_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: ASDSIL/<S26>/DS1401DAC_T1_SFCN1 (ds1401dac_t1) */
    {
      SimStruct *rts = ASDSIL_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = ASDSIL_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = ASDSIL_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = ASDSIL_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ASDSIL_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, ASDSIL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ASDSIL_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ASDSIL_M->NonInlinedSFcns.methods3[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ASDSIL_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ASDSIL_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &ASDSIL_B.Sum_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DS1401DAC_T1_SFCN1");
      ssSetPath(rts,
                "ASDSIL/VEHICLE/SENSORS/TempSensor/DAC_TYPE1_M1_C1/DS1401DAC_T1_SFCN1");
      ssSetRTModel(rts,ASDSIL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ASDSIL_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ASDSIL_P.DS1401DAC_T1_SFCN1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ASDSIL_P.DS1401DAC_T1_SFCN1_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ASDSIL_P.DS1401DAC_T1_SFCN1_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ASDSIL_P.DS1401DAC_T1_SFCN1_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ASDSIL_P.DS1401DAC_T1_SFCN1_P5_Size[0]);
      }

      /* registration */
      ds1401dac_t1(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ASDSIL/<S3>/ds1401dio_t1_bit_out (ds1401dio_t1_bit_out) */
    {
      SimStruct *rts = ASDSIL_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = ASDSIL_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = ASDSIL_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = ASDSIL_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ASDSIL_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, ASDSIL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ASDSIL_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ASDSIL_M->NonInlinedSFcns.methods3[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ASDSIL_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          boolean_T const **sfcnUPtrs = (boolean_T const **)
            &ASDSIL_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &ASDSIL_P.Power_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "ds1401dio_t1_bit_out");
      ssSetPath(rts,
                "ASDSIL/VEHICLE/DIO_TYPE1_BIT_OUT_M1_G1_C1/ds1401dio_t1_bit_out");
      ssSetRTModel(rts,ASDSIL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ASDSIL_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P4_Size
                       [0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P5_Size
                       [0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P6_Size
                       [0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&ASDSIL_P.ds1401dio_t1_bit_out_P7_Size
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ASDSIL_DWork.ds1401dio_t1_bit_out_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ASDSIL_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ASDSIL_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ASDSIL_DWork.ds1401dio_t1_bit_out_IWORK);
      }

      /* registration */
      ds1401dio_t1_bit_out(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ASDSIL/<S4>/ds1401dio_t1_bit_out (ds1401dio_t1_bit_out) */
    {
      SimStruct *rts = ASDSIL_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = ASDSIL_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = ASDSIL_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = ASDSIL_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ASDSIL_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, ASDSIL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ASDSIL_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ASDSIL_M->NonInlinedSFcns.methods3[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ASDSIL_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          boolean_T const **sfcnUPtrs = (boolean_T const **)
            &ASDSIL_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &ASDSIL_P.KeyOn_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "ds1401dio_t1_bit_out");
      ssSetPath(rts,
                "ASDSIL/VEHICLE/DIO_TYPE1_BIT_OUT_M1_G1_C2/ds1401dio_t1_bit_out");
      ssSetRTModel(rts,ASDSIL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ASDSIL_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P1_Size_p[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P2_Size_m[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P3_Size_e[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P4_Size_a[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P5_Size_i[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P6_Size_l[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &ASDSIL_P.ds1401dio_t1_bit_out_P7_Size_h[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ASDSIL_DWork.ds1401dio_t1_bit_out_IWORK_k);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ASDSIL_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ASDSIL_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ASDSIL_DWork.ds1401dio_t1_bit_out_IWORK_k);
      }

      /* registration */
      ds1401dio_t1_bit_out(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void ASDSIL_terminate(void)
{
  /* Terminate for enable SubSystem: '<S1>/CANBUS2' */
  /* Terminate for S-Function (rti_commonblock): '<S7>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "AMB" Id:419362048 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF500])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S8>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "AMB2" Id:419362087 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][4] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF527])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S9>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "AT1T1I" Id:419321405 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FE563D])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S15>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "IC1" Id:419362304 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][4] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF600])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S12>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "DM01" Id:419351101 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FECA3D])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S20>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "TPCM" Id:485293885 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][5] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CECFF3D])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S11>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "CCVS1" Id:419361024 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF100])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S13>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "EEC1" Id:217056256 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0XCF00400])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S14>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "ET1" Id:419360256 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][2] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEEE00])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S16>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "LFE" Id:419361280 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEF200])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S17>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "RQST" Id:418053949 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF3D])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S18>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "RQST_ecu" Id:418053888 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18EAFF00])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S19>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "TD" Id:419358446 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][2] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X18FEE6EE])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S21>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "TPDT" Id:485228349 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][5] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_XTD_0X1CEBFF3D])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* end of Terminate for SubSystem: '<S1>/CANBUS2' */

  /* Level2 S-Function Block: '<S3>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for enable SubSystem: '<S1>/SENSORS' */
  /* Level2 S-Function Block: '<S26>/DS1401DAC_T1_SFCN1' (ds1401dac_t1) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (rti_commonblock): '<S25>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "NOxSensorSignals" Id:82 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[1][0] = can_tp1_msg_sleep
            (can_type1_msg_M2[CANTP1_M2_C1_TX_STD_0X52])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* end of Terminate for SubSystem: '<S1>/SENSORS' */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ASDSIL_output(tid);
}

void MdlUpdate(int_T tid)
{
  ASDSIL_update(tid);
}

void MdlInitializeSizes(void)
{
  ASDSIL_M->Sizes.numContStates = (0); /* Number of continuous states */
  ASDSIL_M->Sizes.numY = (0);          /* Number of model outputs */
  ASDSIL_M->Sizes.numU = (0);          /* Number of model inputs */
  ASDSIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ASDSIL_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  ASDSIL_M->Sizes.numBlocks = (218);   /* Number of blocks */
  ASDSIL_M->Sizes.numBlockIO = (103);  /* Number of block outputs */
  ASDSIL_M->Sizes.numBlockPrms = (146);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Level2 S-Function Block: '<S3>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S3>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/ds1401dio_t1_bit_out' (ds1401dio_t1_bit_out) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for enable SubSystem: '<S1>/SENSORS' */
  /* Level2 S-Function Block: '<S26>/DS1401DAC_T1_SFCN1' (ds1401dac_t1) */
  {
    SimStruct *rts = ASDSIL_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S1>/SENSORS' */
  MdlInitialize();
}

void MdlTerminate(void)
{
  ASDSIL_terminate();
}

RT_MODEL_ASDSIL *ASDSIL(void)
{
  ASDSIL_initialize(1);
  return ASDSIL_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
