/***************************************************************************

   Source file ASDSIL_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 6.6 (29-Nov-2010)
   Thu Jun 23 15:37:14 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "ASDSIL_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_ASDSIL_B_real_T_0 = 0;
volatile boolean_T *p_ASDSIL_B_boolean_T_1 = 0;
volatile real_T *p_ASDSIL_P_real_T_0 = 0;
volatile boolean_T *p_ASDSIL_P_boolean_T_1 = 0;
volatile int_T *p_ASDSIL_DWork_int_T_0 = 0;
