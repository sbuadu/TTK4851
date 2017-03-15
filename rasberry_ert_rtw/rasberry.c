/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rasberry.c
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

#include "rasberry.h"
#include "rasberry_private.h"
#include "rasberry_dt.h"

/* Block signals (auto storage) */
B_rasberry_T rasberry_B;

/* Block states (auto storage) */
DW_rasberry_T rasberry_DW;

/* Real-time model */
RT_MODEL_rasberry_T rasberry_M_;
RT_MODEL_rasberry_T *const rasberry_M = &rasberry_M_;

/* Model step function */
void rasberry_step(void)
{
  /* S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureOutput(rasberry_ConstP.V4L2VideoCapture_p1,
                        rasberry_B.V4L2VideoCapture_o1,
                        rasberry_B.V4L2VideoCapture_o2,
                        rasberry_B.V4L2VideoCapture_o3);

  /* MATLABSystem: '<S2>/MATLAB System' */
  memcpy(&rasberry_B.u0[0], &rasberry_B.V4L2VideoCapture_o1[0], 19200U * sizeof
         (uint8_T));
  memcpy(&rasberry_B.u1[0], &rasberry_B.V4L2VideoCapture_o2[0], 19200U * sizeof
         (uint8_T));
  memcpy(&rasberry_B.u2[0], &rasberry_B.V4L2VideoCapture_o3[0], 19200U * sizeof
         (uint8_T));

  /* Start for MATLABSystem: '<S2>/MATLAB System' incorporates:
   *  MATLABSystem: '<S2>/MATLAB System'
   */
  MW_SDL_videoDisplayOutput(rasberry_B.u0, rasberry_B.u1, rasberry_B.u2);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, rasberry_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(rasberry_M)!=-1) &&
        !((rtmGetTFinal(rasberry_M)-rasberry_M->Timing.taskTime0) >
          rasberry_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(rasberry_M, "Simulation finished");
    }

    if (rtmGetStopRequested(rasberry_M)) {
      rtmSetErrorStatus(rasberry_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rasberry_M->Timing.taskTime0 =
    (++rasberry_M->Timing.clockTick0) * rasberry_M->Timing.stepSize0;
}

/* Model initialize function */
void rasberry_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)rasberry_M, 0,
                sizeof(RT_MODEL_rasberry_T));
  rtmSetTFinal(rasberry_M, 10.0);
  rasberry_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  rasberry_M->Sizes.checksums[0] = (4252710013U);
  rasberry_M->Sizes.checksums[1] = (2132277219U);
  rasberry_M->Sizes.checksums[2] = (2038999838U);
  rasberry_M->Sizes.checksums[3] = (3051241465U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    rasberry_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rasberry_M->extModeInfo,
      &rasberry_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rasberry_M->extModeInfo, rasberry_M->Sizes.checksums);
    rteiSetTPtr(rasberry_M->extModeInfo, rtmGetTPtr(rasberry_M));
  }

  /* block I/O */
  (void) memset(((void *) &rasberry_B), 0,
                sizeof(B_rasberry_T));

  /* states (dwork) */
  (void) memset((void *)&rasberry_DW, 0,
                sizeof(DW_rasberry_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rasberry_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureInit(rasberry_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 160U,
                      120U, 2U, 2U, 1U, 0.1);

  /* Start for MATLABSystem: '<S2>/MATLAB System' */
  rasberry_DW.obj.isInitialized = 0;
  rasberry_DW.obj.isInitialized = 1;
  rasberry_DW.obj.PixelFormatEnum = 1;
  MW_SDL_videoDisplayInit(rasberry_DW.obj.PixelFormatEnum, 1, 1, 160.0, 120.0);

  /* End of Start for SubSystem: '<Root>/SDL Video Display' */
}

/* Model terminate function */
void rasberry_terminate(void)
{
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(rasberry_ConstP.V4L2VideoCapture_p1);

  /* Start for MATLABSystem: '<S2>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<S2>/MATLAB System'
   */
  if (rasberry_DW.obj.isInitialized == 1) {
    rasberry_DW.obj.isInitialized = 2;
    MW_SDL_videoDisplayTerminate(0, 0);
  }

  /* End of Start for MATLABSystem: '<S2>/MATLAB System' */
  /* End of Terminate for SubSystem: '<Root>/SDL Video Display' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
