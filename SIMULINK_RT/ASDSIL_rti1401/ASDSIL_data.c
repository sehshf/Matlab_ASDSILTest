/*
 * ASDSIL_data.c
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

#include "ASDSIL.h"
#include "ASDSIL_private.h"

/* Block parameters (auto storage) */
Parameters_ASDSIL ASDSIL_P = {
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S6>/BaroP'
                                        */
  -272.2813,                           /* Expression: -272.2813
                                        * Referenced by: '<S6>/AmbAirT'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S6>/BaroPSrc'
                                        */
  -272.2813,                           /* Expression: -272.2813
                                        * Referenced by: '<S6>/AmbAirTSrc'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTankLvl'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTankT'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTankLvl2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTankLvlPrelFMI'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/CatRednOpertrInduc'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTank1TPrelFMI'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/OpertrInducSev'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTankHeatr'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FldTank1HeatrPrelFMI'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/AirIntkP'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngIntkMnfldP'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngIntkManfldT'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/AmberWarnLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Blank1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Blank2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/ProtnLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/RedStopLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/MalfcnIndcrLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FlsProtnLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FlsAmberWarnLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FlsRedStopLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FlsMalfcnIndcrLamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/SuspcPrmNo'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/FaiModId'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/OccCt'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/SPNCnvnMeth'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Blank'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/CtlByte'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TotMsgSize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/NoOfPckg'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/ReqPGN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/WhlBasdVehSpd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngStrtrMod'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngDmdTq'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngTqMod'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngTqHiRes'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/DrvrDmdTq'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngTq'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngSpd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/SrcAdrEEC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TCoolt'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngFuRate'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngInstFuEco'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngAvrFuEco'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngThrPosn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/EngThr2Posn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PGNReg'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PGNReqEcu'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiMinOfs'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiHrOfs'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiSec'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiMin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiHr'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiMonth'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiDay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/TiYear'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/SeqNo'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa7'
                                        */
  5.0,                                 /* Expression: PuUpU
                                        * Referenced by: '<S28>/PuUpU'
                                        */
  200.0,                               /* Expression: R0
                                        * Referenced by: '<S27>/R0'
                                        */

  /*  Expression: TSnsrVect
   * Referenced by: '<S27>/TSnsrVect'
   */
  { 1.0, 0.0038285, -5.85E-7 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  31.0,                                /* Expression: 31
                                        * Referenced by: '<S5>/InletT'
                                        */
  273.15,                              /* Expression: 273.15
                                        * Referenced by: '<S27>/ZeroCelciusToKelvin'
                                        */
  1000.0,                              /* Expression: PuUpR
                                        * Referenced by: '<S28>/PuUpR'
                                        */
  0.2222,                              /* Expression: 0.2222
                                        * Referenced by: '<S23>/DAC_Gain'
                                        */
  -0.006,                              /* Expression: CalBias
                                        * Referenced by: '<S23>/CalBias'
                                        */

  /*  Computed Parameter: DS1401DAC_T1_SFCN1_P1_Size
   * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).ModuleNo
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */

  /*  Computed Parameter: DS1401DAC_T1_SFCN1_P2_Size
   * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: sfp(1).ChannelNo
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */

  /*  Computed Parameter: DS1401DAC_T1_SFCN1_P3_Size
   * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).VoltageInitValue
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */

  /*  Computed Parameter: DS1401DAC_T1_SFCN1_P4_Size
   * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).VoltageTermMode
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */

  /*  Computed Parameter: DS1401DAC_T1_SFCN1_P5_Size
   * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).VoltageTermValue
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  65535.0,                             /* Expression: 65535
                                        * Referenced by: '<S5>/NOxConcent'
                                        */
  65535.0,                             /* Expression: 65535
                                        * Referenced by: '<S5>/O2Concent'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S5>/NOxSenSt'
                                        */
  31.0,                                /* Expression: 31
                                        * Referenced by: '<S5>/NOxHeatrErr'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S5>/NOxHeatrMode'
                                        */
  31.0,                                /* Expression: 31
                                        * Referenced by: '<S5>/NOxErr'
                                        */
  7.0,                                 /* Expression: 7
                                        * Referenced by: '<S5>/NOxDiagFb'
                                        */
  31.0,                                /* Expression: 31
                                        * Referenced by: '<S5>/O2Err'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P1_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).ModuleNo
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P2_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: sfp(1).BootMode
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P3_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: sfp(1).GroupNo
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P4_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).ChannelNo
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P5_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).StateInitValue
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P6_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).StateTermMode
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P7_Size
   * Referenced by: '<S3>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).StateTermValue
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P1_Size_p
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).ModuleNo
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P2_Size_m
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: sfp(1).BootMode
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P3_Size_e
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: sfp(1).GroupNo
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P4_Size_a
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: sfp(1).ChannelNo
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P5_Size_i
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).StateInitValue
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P6_Size_l
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).StateTermMode
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */

  /*  Computed Parameter: ds1401dio_t1_bit_out_P7_Size_h
   * Referenced by: '<S4>/ds1401dio_t1_bit_out'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: sfp(1).StateTermValue
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  0,                                   /* Computed Parameter: KeyOn_Value
                                        * Referenced by: '<S1>/KeyOn'
                                        */
  0                                    /* Computed Parameter: Power_Value
                                        * Referenced by: '<S1>/Power'
                                        */
};
