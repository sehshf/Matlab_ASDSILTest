/************************ dSPACE target specific file *************************

   Include file .\asdsil_rti1401\ASDSIL_th.c :

   Task Configuration file for model : ASDSIL

   RTI1401 6.6 (29-Nov-2010)/2.3
   23-Jun-2016 15:37:14

   MATLAB 7.11.1.866 (R2010b) Service Pack 1

   Copyright (c) 1993-2002 dSPACE GmbH, GERMANY

 *****************************************************************************/

/* ===== List of model tasks and assigned interrupt sources ================

   Timer Task 1 [0.001 0] s       : Timer A interrupt
   Timer Task 2 [0.1 0] s         : Timer Task 1

  * ========================================================================= */

#ifndef  _RTI_TH_MODEL_C__
# define _RTI_TH_MODEL_C__

/* ===== File includes ===================================================== */

/* Auxiliary functions of TaskHandling*/

/* No sub-interrupts used by application: */
/* RTITH_USES_SUBINT not defined for rti_th_aux.c */
# include <rti_th_aux.c>

/* rtkernel.h already included in RTI Simulation Engine. */

/* ===== Macro definitions ================================================= */

/* Number of local tasks of the specific type */
# define  RTITH_TIMER_TASKS_LOCAL_NUM_OF      (2)
# define  RTITH_HWINT_TASKS_LOCAL_NUM_OF      (0)
# define  RTITH_SWINT_TASKS_LOCAL_NUM_OF      (0)
# define  RTITH_TMRINT_TASKS_LOCAL_NUM_OF     (0)

# define  RTITH_INT_TASKS_ALL_LOCAL_NUM_OF    (0)
# define  RTITH_TASKS_ALL_LOCAL_NUM_OF        (2)

/* Default scaling factor for timer tasks */
# ifndef  RTI_TIMER_TASK_TIME_SCALE
#   define RTI_TIMER_TASK_TIME_SCALE           (1.0)
# endif

/* Avoid compilation with invalid timer task mode */
# ifndef MULTITASKING
#   error Cannot compile in single timer task mode (.\asdsil_rti1401\ASDSIL_th.c is for MT).
# endif


/* ===== Type definitions ================================================ */

typedef struct tagRtiTimerTask1TriggerSource {
  int service;
  int subentry;
  int subsubentry;
} RtiTimerTask1TriggerSource;


/* ===== Global declarations =============================================== */

/* Pointers to task information variables */
  /* --- Task  1 : Timer Task 1 (TIMER TIMERA) */
double               *pRti_TIMERA_STime;
double               *pRti_TIMERA_TTime;
rtk_task_state_type  *pRti_TIMERA_TState;
rtk_ovc_check_type   *pRti_TIMERA_OType;
int                  *pRti_TIMERA_OMax;
int                  *pRti_TIMERA_ORpt;
int                  *pRti_TIMERA_OCnt;
double               *pRti_TIMERA_TCnt;
int                  *pRti_TIMERA_Prio;

  /* --- Task  2 : Timer Task 2 (TIMER TIMERA2) */
double               *pRti_TIMERA2_STime;
double               *pRti_TIMERA2_TTime;
rtk_task_state_type  *pRti_TIMERA2_TState;
rtk_ovc_check_type   *pRti_TIMERA2_OType;
int                  *pRti_TIMERA2_OMax;
int                  *pRti_TIMERA2_ORpt;
int                  *pRti_TIMERA2_OCnt;
double               *pRti_TIMERA2_TCnt;
int                  *pRti_TIMERA2_Prio;

/* Pointer to RTK task control block of 'Timer Task 1' */
static rtk_p_task_control_block    pRtiTimerTask1TCB = NULL;


/* ===== Function definitions ============================================== */

/* Interface function of Task Handling to create and bind all tasks */
static void rti_th_initialize(void)
{
  /* --- Local declarations ------------------------------------------------ */

  /* Pointers to task control blocks */
  rtk_p_task_control_block pTask1;  /*  Task (TCB pointer).              */
  rtk_p_task_control_block pTask2;  /*  Task (TCB pointer).              */

  int subentry;        /*  RTK subentry.                    */
  int service;         /*  RTK service.                     */

/* Initialize dynamically generated services */

  /* --- Initialization code -----------------------------------------------
   * Task  1 : Timer Task 1 (TIMER TIMERA)
   * Priority: 1, Source: 1, Target: 1
   * Source IntNo: 0, SubIntNo: RTK_NO_SINT, TaskId: 0
   * ----------------------------------------------------------------------- */
  service   = S_PERIODIC_A;                     /*  RTK service.                     */
  subentry = rtk_get_subentry( /* --- Get RTK subentry. ----------- */
      service,                 /*  RTK service.                     */
      0,                 /*  Board base address.              */
      0);                /*  Interrupt number.                */
  pTask1   = rtith_create_task( /* --- Create task. ---------------- */
      rti_TIMERA,                 /*  Task function pointer.           */
      1,                 /*  Task priority.                   */
      ovc_fcn,                 /*  RTK overrun check type.          */
      rti_default_overrun_fcn,                 /*  Overrun handler function.        */
      1,                 /*  Overrun count limit.             */
      0);                /*  Simulink TID.                    */
  rtk_task_name_set( /* --- Set task name. -------------- */
      pTask1,          /*  Task (TCB pointer).              */
      "Timer Task 1");       /*  Task name.                       */
  rtith_bind_interrupt( /* --- Bind interrupt to task. ----- */
      service, subentry,         /*  RTK service, RTK subentry.       */
      pTask1,             /*  Task (TCB pointer).              */
      (0.001 * RTI_TIMER_TASK_TIME_SCALE),             /*  Sample time or period.           */
      C_LOCAL,             /*  RTK channel.                     */
      -1,             /*  Logical interrupt number.        */
      NULL);            /*  Hook function.                   */
  rtith_set_task_type( /* --- Set RTK task type. ---------- */
      service, subentry,           /*  RTK service, RTK subentry.       */
      RTK_NO_SINT,               /*  Sub-interrupt number.            */
      rtk_tt_periodic,               /*  RTK task type.                   */
      NULL,               /*  Reference task (time stamping).  */
      0,            /*  Sample time offset.              */
      1);           /*  Step multiple.                   */

  /* ... Assign task information variables ................................. */
  pRti_TIMERA_STime       = &(pTask1->sample_time);
  pRti_TIMERA_TTime       = &(pTask1->turnaround_time);
  pRti_TIMERA_TState      = &(pTask1->state);
  pRti_TIMERA_OType       = &(pTask1->ovc_type);
  pRti_TIMERA_OMax        = &(pTask1->ovc_max);
  pRti_TIMERA_ORpt        = &(pTask1->ovc_repeat);
  pRti_TIMERA_OCnt        = &(pTask1->ovc_counter);
  pRti_TIMERA_TCnt        = &(pTask1->tm_task_calls);
  pRti_TIMERA_Prio        = &(pTask1->priority);

  /* ... Assign pointer to RTK task control block of of 'Timer Task 1' ..... */
  pRtiTimerTask1TCB = pTask1;         /*  Reference task (time stamping).  */

  /* ... Mark driving interrupt as unused in non-RT simulation mode ........ */
# ifdef SMODE
#   if SMODE == NRTSIM
  rtith_int_status_bit_clear( /* --------------------------------- */
    service, subentry,                 /*  RTK service, RTK subentry.       */
    RTK_NO_SINT,                     /*  Sub-interrupt number.            */
    RTK_STATUS_USED);       /*  RTK mask: Interrupt is bound.    */
#   endif
# endif

  /* --- Initialization code -----------------------------------------------
   * Task  2 : Timer Task 2 (TIMER TIMERA2)
   * Priority: 2, Source: 1, Target: 1
   * Source IntNo: 0, SubIntNo: RTK_NO_SINT, TaskId: 1
   * ----------------------------------------------------------------------- */
  service   = S_SAMPLERATE;                     /*  RTK service.                     */
  subentry = rtk_get_subentry( /* --- Get RTK subentry. ----------- */
      service,                 /*  RTK service.                     */
      0,                 /*  Board base address.              */
      0);                /*  Interrupt number.                */
  pTask2   = rtith_create_task( /* --- Create task. ---------------- */
      rti_TIMERA2,                 /*  Task function pointer.           */
      2,                 /*  Task priority.                   */
      ovc_fcn,                 /*  RTK overrun check type.          */
      rti_default_overrun_fcn,                 /*  Overrun handler function.        */
      1,                 /*  Overrun count limit.             */
      1);                /*  Simulink TID.                    */
  rtk_task_name_set( /* --- Set task name. -------------- */
      pTask2,          /*  Task (TCB pointer).              */
      "Timer Task 2");       /*  Task name.                       */
  rtith_bind_interrupt( /* --- Bind interrupt to task. ----- */
      service, subentry,         /*  RTK service, RTK subentry.       */
      pTask2,             /*  Task (TCB pointer).              */
      0.1,             /*  Sample time or period.           */
      C_LOCAL,             /*  RTK channel.                     */
      -1,             /*  Logical interrupt number.        */
      NULL);            /*  Hook function.                   */
  rtith_set_task_type( /* --- Set RTK task type. ---------- */
      service, subentry,           /*  RTK service, RTK subentry.       */
      RTK_NO_SINT,               /*  Sub-interrupt number.            */
      rtk_tt_periodic,               /*  RTK task type.                   */
      NULL,               /*  Reference task (time stamping).  */
      0,            /*  Sample time offset.              */
      1);           /*  Step multiple.                   */

  /* ... Assign task information variables ................................. */
  pRti_TIMERA2_STime      = &(pTask2->sample_time);
  pRti_TIMERA2_TTime      = &(pTask2->turnaround_time);
  pRti_TIMERA2_TState     = &(pTask2->state);
  pRti_TIMERA2_OType      = &(pTask2->ovc_type);
  pRti_TIMERA2_OMax       = &(pTask2->ovc_max);
  pRti_TIMERA2_ORpt       = &(pTask2->ovc_repeat);
  pRti_TIMERA2_OCnt       = &(pTask2->ovc_counter);
  pRti_TIMERA2_TCnt       = &(pTask2->tm_task_calls);
  pRti_TIMERA2_Prio       = &(pTask2->priority);

  return;
}

void rti_th_timertask1_trigger_source(RtiTimerTask1TriggerSource* triggerSource)
{
  triggerSource->service = S_PERIODIC_A;
  triggerSource->subentry = rtk_get_subentry(
    S_PERIODIC_A,
    0,
    0);
  triggerSource->subsubentry = RTK_NO_SINT;
}

#endif /* _RTI_TH_MODEL_C__ */

/****** [EOF] ****************************************************************/
