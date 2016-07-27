/*
 * ASDSIL.h
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
#ifndef RTW_HEADER_ASDSIL_h_
#define RTW_HEADER_ASDSIL_h_
#ifndef ASDSIL_COMMON_INCLUDES_
# define ASDSIL_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti1401dio.h>
#include <rtican_ds1401.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#endif                                 /* ASDSIL_COMMON_INCLUDES_ */

#include "ASDSIL_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ASDSIL_rtModel                 RT_MODEL_ASDSIL

/* Block signals (auto storage) */
typedef struct {
  real_T Sum;                          /* '<S27>/Sum' */
  real_T Product1;                     /* '<S27>/Product1' */
  real_T TmpSignalConversionAtProduct2In[3];/* '<S27>/Mux' */
  real_T Product2;                     /* '<S27>/Product2' */
  real_T Product;                      /* '<S27>/Product' */
  real_T Sum_p;                        /* '<S28>/Sum' */
  real_T Divide;                       /* '<S28>/Divide' */
  real_T DAC_Gain;                     /* '<S23>/DAC_Gain' */
  real_T Sum_m;                        /* '<S23>/Sum' */
  real_T DataTypeConversion;           /* '<S22>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S22>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S22>/Data Type Conversion2' */
  real_T DataTypeConversion3;          /* '<S22>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<S22>/Data Type Conversion4' */
  real_T DataTypeConversion5;          /* '<S22>/Data Type Conversion5' */
  real_T DataTypeConversion6;          /* '<S22>/Data Type Conversion6' */
  real_T DataTypeConversion7;          /* '<S22>/Data Type Conversion7' */
  real_T SFunction1;                   /* '<S25>/S-Function1' */
  real_T DataTypeConversion_b;         /* '<S6>/Data Type Conversion' */
  real_T DataTypeConversion1_n;        /* '<S6>/Data Type Conversion1' */
  real_T SFunction1_k;                 /* '<S7>/S-Function1' */
  real_T DataTypeConversion2_i;        /* '<S6>/Data Type Conversion2' */
  real_T DataTypeConversion3_p;        /* '<S6>/Data Type Conversion3' */
  real_T SFunction1_kw;                /* '<S8>/S-Function1' */
  real_T DataTypeConversion14;         /* '<S6>/Data Type Conversion14' */
  real_T DataTypeConversion15;         /* '<S6>/Data Type Conversion15' */
  real_T DataTypeConversion16;         /* '<S6>/Data Type Conversion16' */
  real_T DataTypeConversion17;         /* '<S6>/Data Type Conversion17' */
  real_T DataTypeConversion18;         /* '<S6>/Data Type Conversion18' */
  real_T DataTypeConversion19;         /* '<S6>/Data Type Conversion19' */
  real_T DataTypeConversion12;         /* '<S6>/Data Type Conversion12' */
  real_T DataTypeConversion13;         /* '<S6>/Data Type Conversion13' */
  real_T DataTypeConversion20;         /* '<S6>/Data Type Conversion20' */
  real_T SFunction1_p;                 /* '<S9>/S-Function1' */
  real_T DataTypeConversion37;         /* '<S6>/Data Type Conversion37' */
  real_T DataTypeConversion38;         /* '<S6>/Data Type Conversion38' */
  real_T DataTypeConversion39;         /* '<S6>/Data Type Conversion39' */
  real_T SFunction1_j;                 /* '<S15>/S-Function1' */
  real_T DataTypeConversion24;         /* '<S6>/Data Type Conversion24' */
  real_T DataTypeConversion31;         /* '<S6>/Data Type Conversion31' */
  real_T DataTypeConversion22;         /* '<S6>/Data Type Conversion22' */
  real_T DataTypeConversion23;         /* '<S6>/Data Type Conversion23' */
  real_T DataTypeConversion25;         /* '<S6>/Data Type Conversion25' */
  real_T DataTypeConversion26;         /* '<S6>/Data Type Conversion26' */
  real_T DataTypeConversion27;         /* '<S6>/Data Type Conversion27' */
  real_T DataTypeConversion28;         /* '<S6>/Data Type Conversion28' */
  real_T DataTypeConversion29;         /* '<S6>/Data Type Conversion29' */
  real_T DataTypeConversion30;         /* '<S6>/Data Type Conversion30' */
  real_T DataTypeConversion32;         /* '<S6>/Data Type Conversion32' */
  real_T DataTypeConversion33;         /* '<S6>/Data Type Conversion33' */
  real_T DataTypeConversion34;         /* '<S6>/Data Type Conversion34' */
  real_T DataTypeConversion35;         /* '<S6>/Data Type Conversion35' */
  real_T SFunction1_a;                 /* '<S12>/S-Function1' */
  real_T DataTypeConversion55;         /* '<S6>/Data Type Conversion55' */
  real_T DataTypeConversion56;         /* '<S6>/Data Type Conversion56' */
  real_T DataTypeConversion57;         /* '<S6>/Data Type Conversion57' */
  real_T DataTypeConversion58;         /* '<S6>/Data Type Conversion58' */
  real_T DataTypeConversion59;         /* '<S6>/Data Type Conversion59' */
  real_T SFunction1_o;                 /* '<S20>/S-Function1' */
  real_T DataTypeConversion21;         /* '<S6>/Data Type Conversion21' */
  real_T SFunction1_d;                 /* '<S11>/S-Function1' */
  real_T DataTypeConversion10;         /* '<S6>/Data Type Conversion10' */
  real_T DataTypeConversion11;         /* '<S6>/Data Type Conversion11' */
  real_T DataTypeConversion4_j;        /* '<S6>/Data Type Conversion4' */
  real_T DataTypeConversion5_e;        /* '<S6>/Data Type Conversion5' */
  real_T DataTypeConversion6_p;        /* '<S6>/Data Type Conversion6' */
  real_T DataTypeConversion7_e;        /* '<S6>/Data Type Conversion7' */
  real_T DataTypeConversion8;          /* '<S6>/Data Type Conversion8' */
  real_T DataTypeConversion9;          /* '<S6>/Data Type Conversion9' */
  real_T SFunction1_o5;                /* '<S13>/S-Function1' */
  real_T DataTypeConversion36;         /* '<S6>/Data Type Conversion36' */
  real_T SFunction1_f;                 /* '<S14>/S-Function1' */
  real_T DataTypeConversion40;         /* '<S6>/Data Type Conversion40' */
  real_T DataTypeConversion41;         /* '<S6>/Data Type Conversion41' */
  real_T DataTypeConversion42;         /* '<S6>/Data Type Conversion42' */
  real_T DataTypeConversion43;         /* '<S6>/Data Type Conversion43' */
  real_T DataTypeConversion44;         /* '<S6>/Data Type Conversion44' */
  real_T SFunction1_os;                /* '<S16>/S-Function1' */
  real_T DataTypeConversion45;         /* '<S6>/Data Type Conversion45' */
  real_T SFunction1_e;                 /* '<S17>/S-Function1' */
  real_T DataTypeConversion46;         /* '<S6>/Data Type Conversion46' */
  real_T SFunction1_en;                /* '<S18>/S-Function1' */
  real_T DataTypeConversion47;         /* '<S6>/Data Type Conversion47' */
  real_T DataTypeConversion48;         /* '<S6>/Data Type Conversion48' */
  real_T DataTypeConversion49;         /* '<S6>/Data Type Conversion49' */
  real_T DataTypeConversion50;         /* '<S6>/Data Type Conversion50' */
  real_T DataTypeConversion51;         /* '<S6>/Data Type Conversion51' */
  real_T DataTypeConversion52;         /* '<S6>/Data Type Conversion52' */
  real_T DataTypeConversion53;         /* '<S6>/Data Type Conversion53' */
  real_T DataTypeConversion54;         /* '<S6>/Data Type Conversion54' */
  real_T SFunction1_l;                 /* '<S19>/S-Function1' */
  real_T DataTypeConversion60;         /* '<S6>/Data Type Conversion60' */
  real_T DataTypeConversion61;         /* '<S6>/Data Type Conversion61' */
  real_T DataTypeConversion62;         /* '<S6>/Data Type Conversion62' */
  real_T DataTypeConversion63;         /* '<S6>/Data Type Conversion63' */
  real_T DataTypeConversion64;         /* '<S6>/Data Type Conversion64' */
  real_T DataTypeConversion65;         /* '<S6>/Data Type Conversion65' */
  real_T DataTypeConversion66;         /* '<S6>/Data Type Conversion66' */
  real_T DataTypeConversion67;         /* '<S6>/Data Type Conversion67' */
  real_T SFunction1_ec;                /* '<S21>/S-Function1' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T RateTransition2;           /* '<S1>/Rate Transition2' */
  boolean_T RateTransition1;           /* '<S1>/Rate Transition1' */
} BlockIO_ASDSIL;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int_T ds1401dio_t1_bit_out_IWORK;    /* '<S3>/ds1401dio_t1_bit_out' */
  int_T ds1401dio_t1_bit_out_IWORK_k;  /* '<S4>/ds1401dio_t1_bit_out' */
  int_T SFunction1_IWORK[2];           /* '<S24>/S-Function1' */
  int_T SFunction1_IWORK_e[2];         /* '<S10>/S-Function1' */
} D_Work_ASDSIL;

/* Backward compatible GRT Identifiers */
#define rtB                            ASDSIL_B
#define BlockIO                        BlockIO_ASDSIL
#define rtXdot                         ASDSIL_Xdot
#define StateDerivatives               StateDerivatives_ASDSIL
#define tXdis                          ASDSIL_Xdis
#define StateDisabled                  StateDisabled_ASDSIL
#define rtP                            ASDSIL_P
#define Parameters                     Parameters_ASDSIL
#define rtDWork                        ASDSIL_DWork
#define D_Work                         D_Work_ASDSIL

/* Parameters (auto storage) */
struct Parameters_ASDSIL_ {
  real_T BaroP_Value;                  /* Expression: 50
                                        * Referenced by: '<S6>/BaroP'
                                        */
  real_T AmbAirT_Value;                /* Expression: -272.2813
                                        * Referenced by: '<S6>/AmbAirT'
                                        */
  real_T BaroPSrc_Value;               /* Expression: 50
                                        * Referenced by: '<S6>/BaroPSrc'
                                        */
  real_T AmbAirTSrc_Value;             /* Expression: -272.2813
                                        * Referenced by: '<S6>/AmbAirTSrc'
                                        */
  real_T FldTankLvl_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/FldTankLvl'
                                        */
  real_T FldTankT_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/FldTankT'
                                        */
  real_T FldTankLvl2_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/FldTankLvl2'
                                        */
  real_T FldTankLvlPrelFMI_Value;      /* Expression: 0
                                        * Referenced by: '<S6>/FldTankLvlPrelFMI'
                                        */
  real_T CatRednOpertrInduc_Value;     /* Expression: 0
                                        * Referenced by: '<S6>/CatRednOpertrInduc'
                                        */
  real_T FldTank1TPrelFMI_Value;       /* Expression: 0
                                        * Referenced by: '<S6>/FldTank1TPrelFMI'
                                        */
  real_T OpertrInducSev_Value;         /* Expression: 0
                                        * Referenced by: '<S6>/OpertrInducSev'
                                        */
  real_T FldTankHeatr_Value;           /* Expression: 0
                                        * Referenced by: '<S6>/FldTankHeatr'
                                        */
  real_T FldTank1HeatrPrelFMI_Value;   /* Expression: 0
                                        * Referenced by: '<S6>/FldTank1HeatrPrelFMI'
                                        */
  real_T AirIntkP_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/AirIntkP'
                                        */
  real_T EngIntkMnfldP_Value;          /* Expression: 0
                                        * Referenced by: '<S6>/EngIntkMnfldP'
                                        */
  real_T EngIntkManfldT_Value;         /* Expression: 0
                                        * Referenced by: '<S6>/EngIntkManfldT'
                                        */
  real_T AmberWarnLamp_Value;          /* Expression: 0
                                        * Referenced by: '<S6>/AmberWarnLamp'
                                        */
  real_T Blank1_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/Blank1'
                                        */
  real_T Blank2_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/Blank2'
                                        */
  real_T ProtnLamp_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/ProtnLamp'
                                        */
  real_T RedStopLamp_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/RedStopLamp'
                                        */
  real_T MalfcnIndcrLamp_Value;        /* Expression: 0
                                        * Referenced by: '<S6>/MalfcnIndcrLamp'
                                        */
  real_T FlsProtnLamp_Value;           /* Expression: 0
                                        * Referenced by: '<S6>/FlsProtnLamp'
                                        */
  real_T FlsAmberWarnLamp_Value;       /* Expression: 0
                                        * Referenced by: '<S6>/FlsAmberWarnLamp'
                                        */
  real_T FlsRedStopLamp_Value;         /* Expression: 0
                                        * Referenced by: '<S6>/FlsRedStopLamp'
                                        */
  real_T FlsMalfcnIndcrLamp_Value;     /* Expression: 0
                                        * Referenced by: '<S6>/FlsMalfcnIndcrLamp'
                                        */
  real_T SuspcPrmNo_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/SuspcPrmNo'
                                        */
  real_T FaiModId_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/FaiModId'
                                        */
  real_T OccCt_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/OccCt'
                                        */
  real_T SPNCnvnMeth_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/SPNCnvnMeth'
                                        */
  real_T Blank_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/Blank'
                                        */
  real_T CtlByte_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/CtlByte'
                                        */
  real_T TotMsgSize_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/TotMsgSize'
                                        */
  real_T NoOfPckg_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/NoOfPckg'
                                        */
  real_T ReqPGN_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/ReqPGN'
                                        */
  real_T WhlBasdVehSpd_Value;          /* Expression: 0
                                        * Referenced by: '<S6>/WhlBasdVehSpd'
                                        */
  real_T EngStrtrMod_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/EngStrtrMod'
                                        */
  real_T EngDmdTq_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/EngDmdTq'
                                        */
  real_T EngTqMod_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/EngTqMod'
                                        */
  real_T EngTqHiRes_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/EngTqHiRes'
                                        */
  real_T DrvrDmdTq_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/DrvrDmdTq'
                                        */
  real_T EngTq_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/EngTq'
                                        */
  real_T EngSpd_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/EngSpd'
                                        */
  real_T SrcAdrEEC_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/SrcAdrEEC'
                                        */
  real_T TCoolt_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/TCoolt'
                                        */
  real_T EngFuRate_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/EngFuRate'
                                        */
  real_T EngInstFuEco_Value;           /* Expression: 0
                                        * Referenced by: '<S6>/EngInstFuEco'
                                        */
  real_T EngAvrFuEco_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/EngAvrFuEco'
                                        */
  real_T EngThrPosn_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/EngThrPosn'
                                        */
  real_T EngThr2Posn_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/EngThr2Posn'
                                        */
  real_T PGNReg_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/PGNReg'
                                        */
  real_T PGNReqEcu_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/PGNReqEcu'
                                        */
  real_T TiMinOfs_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/TiMinOfs'
                                        */
  real_T TiHrOfs_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/TiHrOfs'
                                        */
  real_T TiSec_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/TiSec'
                                        */
  real_T TiMin_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/TiMin'
                                        */
  real_T TiHr_Value;                   /* Expression: 0
                                        * Referenced by: '<S6>/TiHr'
                                        */
  real_T TiMonth_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/TiMonth'
                                        */
  real_T TiDay_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/TiDay'
                                        */
  real_T TiYear_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/TiYear'
                                        */
  real_T SeqNo_Value;                  /* Expression: 0
                                        * Referenced by: '<S6>/SeqNo'
                                        */
  real_T PcktDa1_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa1'
                                        */
  real_T PcktDa2_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa2'
                                        */
  real_T PcktDa3_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa3'
                                        */
  real_T PcktDa4_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa4'
                                        */
  real_T PcktDa5_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa5'
                                        */
  real_T PcktDa6_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa6'
                                        */
  real_T PcktDa7_Value;                /* Expression: 0
                                        * Referenced by: '<S6>/PcktDa7'
                                        */
  real_T PuUpU_Value;                  /* Expression: PuUpU
                                        * Referenced by: '<S28>/PuUpU'
                                        */
  real_T R0_Value;                     /* Expression: R0
                                        * Referenced by: '<S27>/R0'
                                        */
  real_T TSnsrVect_Value[3];           /* Expression: TSnsrVect
                                        * Referenced by: '<S27>/TSnsrVect'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T InletT_Value;                 /* Expression: 31
                                        * Referenced by: '<S5>/InletT'
                                        */
  real_T ZeroCelciusToKelvin_Value;    /* Expression: 273.15
                                        * Referenced by: '<S27>/ZeroCelciusToKelvin'
                                        */
  real_T PuUpR_Value;                  /* Expression: PuUpR
                                        * Referenced by: '<S28>/PuUpR'
                                        */
  real_T DAC_Gain_Gain;                /* Expression: 0.2222
                                        * Referenced by: '<S23>/DAC_Gain'
                                        */
  real_T CalBias_Value;                /* Expression: CalBias
                                        * Referenced by: '<S23>/CalBias'
                                        */
  real_T DS1401DAC_T1_SFCN1_P1_Size[2];/* Computed Parameter: DS1401DAC_T1_SFCN1_P1_Size
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P1;        /* Expression: sfp(1).ModuleNo
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P2_Size[2];/* Computed Parameter: DS1401DAC_T1_SFCN1_P2_Size
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P2;        /* Expression: sfp(1).ChannelNo
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P3_Size[2];/* Computed Parameter: DS1401DAC_T1_SFCN1_P3_Size
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P3;        /* Expression: sfp(1).VoltageInitValue
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P4_Size[2];/* Computed Parameter: DS1401DAC_T1_SFCN1_P4_Size
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P4;        /* Expression: sfp(1).VoltageTermMode
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P5_Size[2];/* Computed Parameter: DS1401DAC_T1_SFCN1_P5_Size
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T DS1401DAC_T1_SFCN1_P5;        /* Expression: sfp(1).VoltageTermValue
                                        * Referenced by: '<S26>/DS1401DAC_T1_SFCN1'
                                        */
  real_T NOxConcent_Value;             /* Expression: 65535
                                        * Referenced by: '<S5>/NOxConcent'
                                        */
  real_T O2Concent_Value;              /* Expression: 65535
                                        * Referenced by: '<S5>/O2Concent'
                                        */
  real_T NOxSenSt_Value;               /* Expression: 255
                                        * Referenced by: '<S5>/NOxSenSt'
                                        */
  real_T NOxHeatrErr_Value;            /* Expression: 31
                                        * Referenced by: '<S5>/NOxHeatrErr'
                                        */
  real_T NOxHeatrMode_Value;           /* Expression: 3
                                        * Referenced by: '<S5>/NOxHeatrMode'
                                        */
  real_T NOxErr_Value;                 /* Expression: 31
                                        * Referenced by: '<S5>/NOxErr'
                                        */
  real_T NOxDiagFb_Value;              /* Expression: 7
                                        * Referenced by: '<S5>/NOxDiagFb'
                                        */
  real_T O2Err_Value;                  /* Expression: 31
                                        * Referenced by: '<S5>/O2Err'
                                        */
  real_T ds1401dio_t1_bit_out_P1_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P1_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P1;      /* Expression: sfp(1).ModuleNo
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P2_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P2_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P2;      /* Expression: sfp(1).BootMode
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P3_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P3_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P3;      /* Expression: sfp(1).GroupNo
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P4_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P4_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P4;      /* Expression: sfp(1).ChannelNo
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P5_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P5_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P5;      /* Expression: sfp(1).StateInitValue
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P6_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P6_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P6;      /* Expression: sfp(1).StateTermMode
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P7_Size[2];/* Computed Parameter: ds1401dio_t1_bit_out_P7_Size
                                          * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                          */
  real_T ds1401dio_t1_bit_out_P7;      /* Expression: sfp(1).StateTermValue
                                        * Referenced by: '<S3>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P1_Size_p[2];/* Computed Parameter: ds1401dio_t1_bit_out_P1_Size_p
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P1_m;    /* Expression: sfp(1).ModuleNo
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P2_Size_m[2];/* Computed Parameter: ds1401dio_t1_bit_out_P2_Size_m
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P2_o;    /* Expression: sfp(1).BootMode
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P3_Size_e[2];/* Computed Parameter: ds1401dio_t1_bit_out_P3_Size_e
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P3_o;    /* Expression: sfp(1).GroupNo
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P4_Size_a[2];/* Computed Parameter: ds1401dio_t1_bit_out_P4_Size_a
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P4_h;    /* Expression: sfp(1).ChannelNo
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P5_Size_i[2];/* Computed Parameter: ds1401dio_t1_bit_out_P5_Size_i
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P5_f;    /* Expression: sfp(1).StateInitValue
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P6_Size_l[2];/* Computed Parameter: ds1401dio_t1_bit_out_P6_Size_l
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P6_f;    /* Expression: sfp(1).StateTermMode
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  real_T ds1401dio_t1_bit_out_P7_Size_h[2];/* Computed Parameter: ds1401dio_t1_bit_out_P7_Size_h
                                            * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                            */
  real_T ds1401dio_t1_bit_out_P7_f;    /* Expression: sfp(1).StateTermValue
                                        * Referenced by: '<S4>/ds1401dio_t1_bit_out'
                                        */
  boolean_T KeyOn_Value;               /* Computed Parameter: KeyOn_Value
                                        * Referenced by: '<S1>/KeyOn'
                                        */
  boolean_T Power_Value;               /* Computed Parameter: Power_Value
                                        * Referenced by: '<S1>/Power'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_ASDSIL {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    SimStruct childSFunctions[3];
    SimStruct *childSFunctionPtrs[3];
    struct _ssBlkInfo2 blkInfo2[3];
    struct _ssSFcnModelMethods2 methods2[3];
    struct _ssSFcnModelMethods3 methods3[3];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[5];
      mxArray *params[5];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_ASDSIL ASDSIL_P;

/* Block signals (auto storage) */
extern BlockIO_ASDSIL ASDSIL_B;

/* Block states (auto storage) */
extern D_Work_ASDSIL ASDSIL_DWork;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Real-time Model object */
extern struct RT_MODEL_ASDSIL *ASDSIL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ASDSIL
 * '<S1>'   : ASDSIL/VEHICLE
 * '<S2>'   : ASDSIL/VEHICLE/CANBUS2
 * '<S3>'   : ASDSIL/VEHICLE/DIO_TYPE1_BIT_OUT_M1_G1_C1
 * '<S4>'   : ASDSIL/VEHICLE/DIO_TYPE1_BIT_OUT_M1_G1_C2
 * '<S5>'   : ASDSIL/VEHICLE/SENSORS
 * '<S6>'   : ASDSIL/VEHICLE/CANBUS2/SAEJ1939
 * '<S7>'   : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/AMB
 * '<S8>'   : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/AMB2
 * '<S9>'   : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/AT1T1I
 * '<S10>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/CAN_TYPE1_SETUP_M1_C2
 * '<S11>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/CCVS1
 * '<S12>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/DM01
 * '<S13>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/EEC1
 * '<S14>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/ET1
 * '<S15>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/IC1
 * '<S16>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/LFE
 * '<S17>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/RQST
 * '<S18>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/RQST_ecu
 * '<S19>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/TD
 * '<S20>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/TPCM
 * '<S21>'  : ASDSIL/VEHICLE/CANBUS2/SAEJ1939/TPDT
 * '<S22>'  : ASDSIL/VEHICLE/SENSORS/NOxSensor
 * '<S23>'  : ASDSIL/VEHICLE/SENSORS/TempSensor
 * '<S24>'  : ASDSIL/VEHICLE/SENSORS/NOxSensor/CAN_TYPE1_SETUP_M2_C1
 * '<S25>'  : ASDSIL/VEHICLE/SENSORS/NOxSensor/NOxSensorSignals
 * '<S26>'  : ASDSIL/VEHICLE/SENSORS/TempSensor/DAC_TYPE1_M1_C1
 * '<S27>'  : ASDSIL/VEHICLE/SENSORS/TempSensor/Pt 200
 * '<S28>'  : ASDSIL/VEHICLE/SENSORS/TempSensor/Pull Up
 */
#endif                                 /* RTW_HEADER_ASDSIL_h_ */
