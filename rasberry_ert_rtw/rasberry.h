/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rasberry.h
 *
 * Code generated for Simulink model 'rasberry'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Mar 15 09:36:53 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rasberry_h_
#define RTW_HEADER_rasberry_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef rasberry_COMMON_INCLUDES_
# define rasberry_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SDL_video_display.h"
#include "v4l2_capture.h"
#endif                                 /* rasberry_COMMON_INCLUDES_ */

#include "rasberry_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T V4L2VideoCapture_o1[19200];  /* '<Root>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o2[19200];  /* '<Root>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o3[19200];  /* '<Root>/V4L2 Video Capture' */
  uint8_T u0[19200];
  uint8_T u1[19200];
  uint8_T u2[19200];
} B_rasberry_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_SDLV_T obj; /* '<S2>/MATLAB System' */
  void *MATLABSystem_PWORK;            /* '<S2>/MATLAB System' */
} DW_rasberry_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: devName
   * Referenced by: '<Root>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP_rasberry_T;

/* Real-time Model Data Structure */
struct tag_RTM_rasberry_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B_rasberry_T rasberry_B;

/* Block states (auto storage) */
extern DW_rasberry_T rasberry_DW;

/* Constant parameters (auto storage) */
extern const ConstP_rasberry_T rasberry_ConstP;

/* Model entry point functions */
extern void rasberry_initialize(void);
extern void rasberry_step(void);
extern void rasberry_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rasberry_T *const rasberry_M;

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
 * '<Root>' : 'rasberry'
 * '<S1>'   : 'rasberry/Image processing'
 * '<S2>'   : 'rasberry/SDL Video Display'
 * '<S3>'   : 'rasberry/Image processing/Find  required angle'
 * '<S4>'   : 'rasberry/Image processing/Fint coordinate points'
 */
#endif                                 /* RTW_HEADER_rasberry_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
