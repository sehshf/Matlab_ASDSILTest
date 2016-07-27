  /*********************** dSPACE target specific file *************************

   Header file ASDSIL_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 6.6 (29-Nov-2010)
   Thu Jun 23 15:37:14 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_ASDSIL_trc_ptr_h_
  #define RTI_HEADER_ASDSIL_trc_ptr_h_
  /* Include the model header file. */
  #include "ASDSIL.h"
  #include "ASDSIL_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_ASDSIL_B_real_T_0;
              EXTERN_C volatile  boolean_T *p_ASDSIL_B_boolean_T_1;
              EXTERN_C volatile  real_T *p_ASDSIL_P_real_T_0;
              EXTERN_C volatile  boolean_T *p_ASDSIL_P_boolean_T_1;
              EXTERN_C volatile  int_T *p_ASDSIL_DWork_int_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_ASDSIL_B_real_T_0 = &ASDSIL_B.Sum;\
              p_ASDSIL_B_boolean_T_1 = &ASDSIL_B.LogicalOperator;\
              p_ASDSIL_P_real_T_0 = &ASDSIL_P.BaroP_Value;\
              p_ASDSIL_P_boolean_T_1 = &ASDSIL_P.KeyOn_Value;\
              p_ASDSIL_DWork_int_T_0 = &ASDSIL_DWork.ds1401dio_t1_bit_out_IWORK;\

   #endif                       /* RTI_HEADER_ASDSIL_trc_ptr_h_ */
