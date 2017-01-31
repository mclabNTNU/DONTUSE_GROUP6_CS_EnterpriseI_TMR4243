/*
 * Group6Task6_2017_ssp.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Group6Task6_2017_ssp".
 *
 * Model version              : 1.161
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Jan 31 15:39:06 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Group6Task6_2017_ssp.h"
#include "Group6Task6_2017_ssp_private.h"

/* Block signals (auto storage) */
B_Group6Task6_2017_ssp_T Group6Task6_2017_ssp_B;

/* Block states (auto storage) */
DW_Group6Task6_2017_ssp_T Group6Task6_2017_ssp_DW;

/* Real-time model */
RT_MODEL_Group6Task6_2017_ssp_T Group6Task6_2017_ssp_M_;
RT_MODEL_Group6Task6_2017_ssp_T *const Group6Task6_2017_ssp_M =
  &Group6Task6_2017_ssp_M_;

/*
 * Output and update for atomic system:
 *    '<Root>/Sat_Chk_BT'
 *    '<Root>/Sat_Chk_VSP'
 */
void Group6Task6_2017_ssp_Sat_Chk_BT(real_T rtu_u_inn,
  B_Sat_Chk_BT_Group6Task6_2017_T *localB)
{
  /* MATLAB Function 'Sat_Chk_BT': '<S5>:1' */
  if ((rtu_u_inn > 1.0) || (rtu_u_inn < -1.0)) {
    /* '<S5>:1:3' */
    /* '<S5>:1:4' */
    localB->u_out = 0.0;

    /* '<S5>:1:5' */
    localB->error = true;
  } else {
    /* '<S5>:1:7' */
    localB->u_out = rtu_u_inn;

    /* '<S5>:1:8' */
    localB->error = false;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
static void Group6Task6_2017_ssp_output(void)
{
  /* local block i/o variables */
  real_T rtb_Output;
  real_T rtb_u_vsp;
  real_T rtb_u_bt;
  real_T rtb_DeadZone;
  real_T rtb_DeadZone1;

  /* MATLAB Function: '<Root>/Sel_Control_Mode' incorporates:
   *  Memory: '<Root>/Memory1'
   */
  /* MATLAB Function 'Sel_Control_Mode': '<S7>:1' */
  if (Group6Task6_2017_ssp_B.select == 1.0) {
    /* '<S7>:1:3' */
    if (Group6Task6_2017_ssp_DW.Memory1_PreviousInput == 2.0) {
      /* '<S7>:1:4' */
      /* '<S7>:1:5' */
      Group6Task6_2017_ssp_B.current_mode = 3.0;
    } else {
      /* '<S7>:1:7' */
      Group6Task6_2017_ssp_B.current_mode = 2.0;
    }
  } else {
    /* '<S7>:1:10' */
    Group6Task6_2017_ssp_B.current_mode =
      Group6Task6_2017_ssp_DW.Memory1_PreviousInput;
  }

  /* End of MATLAB Function: '<Root>/Sel_Control_Mode' */

  /* DeadZone: '<Root>/Dead Zone' */
  if (Group6Task6_2017_ssp_B.PosXLeft > Group6Task6_2017_ssp_P.DeadZone_End) {
    rtb_DeadZone = Group6Task6_2017_ssp_B.PosXLeft -
      Group6Task6_2017_ssp_P.DeadZone_End;
  } else if (Group6Task6_2017_ssp_B.PosXLeft >=
             Group6Task6_2017_ssp_P.DeadZone_Start) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = Group6Task6_2017_ssp_B.PosXLeft -
      Group6Task6_2017_ssp_P.DeadZone_Start;
  }

  /* End of DeadZone: '<Root>/Dead Zone' */

  /* DeadZone: '<Root>/Dead Zone1' */
  if (Group6Task6_2017_ssp_B.PosYLeft > Group6Task6_2017_ssp_P.DeadZone1_End) {
    rtb_DeadZone1 = Group6Task6_2017_ssp_B.PosYLeft -
      Group6Task6_2017_ssp_P.DeadZone1_End;
  } else if (Group6Task6_2017_ssp_B.PosYLeft >=
             Group6Task6_2017_ssp_P.DeadZone1_Start) {
    rtb_DeadZone1 = 0.0;
  } else {
    rtb_DeadZone1 = Group6Task6_2017_ssp_B.PosYLeft -
      Group6Task6_2017_ssp_P.DeadZone1_Start;
  }

  /* End of DeadZone: '<Root>/Dead Zone1' */

  /* MATLAB Function: '<Root>/Contoller_Map' incorporates:
   *  Constant: '<Root>/Max_Global_Forces'
   */
  /* MATLAB Function 'Contoller_Map': '<S1>:1' */
  if (Group6Task6_2017_ssp_B.current_mode == 2.0) {
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    Group6Task6_2017_ssp_B.tau_x = -rtb_DeadZone1 *
      Group6Task6_2017_ssp_P.Max_Global_Forces_Value[0];

    /* '<S1>:1:5' */
    Group6Task6_2017_ssp_B.tau_y = rtb_DeadZone *
      Group6Task6_2017_ssp_P.Max_Global_Forces_Value[3];

    /* '<S1>:1:6' */
    Group6Task6_2017_ssp_B.tau_yaw = 0.0;
  } else {
    /* '<S1>:1:8' */
    Group6Task6_2017_ssp_B.tau_x = -rtb_DeadZone1 *
      Group6Task6_2017_ssp_P.Max_Global_Forces_Value[0];

    /* '<S1>:1:9' */
    Group6Task6_2017_ssp_B.tau_y = rtb_DeadZone *
      Group6Task6_2017_ssp_P.Max_Global_Forces_Value[1];

    /* DeadZone: '<Root>/Dead Zone2' incorporates:
     *  Constant: '<Root>/Max_Global_Forces'
     */
    /* '<S1>:1:10' */
    if (Group6Task6_2017_ssp_B.R2_continuous >
        Group6Task6_2017_ssp_P.DeadZone2_End) {
      rtb_DeadZone = Group6Task6_2017_ssp_B.R2_continuous -
        Group6Task6_2017_ssp_P.DeadZone2_End;
    } else if (Group6Task6_2017_ssp_B.R2_continuous >=
               Group6Task6_2017_ssp_P.DeadZone2_Start) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = Group6Task6_2017_ssp_B.R2_continuous -
        Group6Task6_2017_ssp_P.DeadZone2_Start;
    }

    /* End of DeadZone: '<Root>/Dead Zone2' */
    Group6Task6_2017_ssp_B.tau_yaw = rtb_DeadZone *
      Group6Task6_2017_ssp_P.Max_Global_Forces_Value[2];
  }

  /* End of MATLAB Function: '<Root>/Contoller_Map' */

  /* MATLAB Function: '<Root>/Force Allocation' */
  /* MATLAB Function 'Force Allocation': '<S2>:1' */
  if (Group6Task6_2017_ssp_B.current_mode == 2.0) {
    /* '<S2>:1:5' */
    /* '<S2>:1:6' */
    Group6Task6_2017_ssp_B.f_vspx = Group6Task6_2017_ssp_B.tau_x;

    /* '<S2>:1:7' */
    Group6Task6_2017_ssp_B.f_vspy = 0.0;

    /* '<S2>:1:8' */
    Group6Task6_2017_ssp_B.f_bt = Group6Task6_2017_ssp_B.tau_y;
  } else {
    /* new equations from Silas 31/1/2017, based on Matlab inversion of B matrix */
    /* '<S2>:1:11' */
    Group6Task6_2017_ssp_B.f_vspx = Group6Task6_2017_ssp_B.tau_x;

    /* '<S2>:1:12' */
    Group6Task6_2017_ssp_B.f_vspy = 0.3875 * Group6Task6_2017_ssp_B.tau_y /
      0.845 - Group6Task6_2017_ssp_B.tau_yaw / 0.845;

    /* '<S2>:1:13' */
    Group6Task6_2017_ssp_B.f_bt = Group6Task6_2017_ssp_B.tau_yaw / 0.845 -
      -0.4575 * Group6Task6_2017_ssp_B.tau_y / 0.845;
  }

  /* End of MATLAB Function: '<Root>/Force Allocation' */

  /* MATLAB Function: '<Root>/Force2Control' incorporates:
   *  Constant: '<Root>/Sat_Forces'
   */
  /* original equations from 30/1/2017 */
  /*  f_vspx=tau_x; */
  /*  f_vspy=(tau_yaw-tau_y*l_bt)/(l_vsp-l_bt); */
  /*  f_bt=tau_y-f_vspy; */
  /* tau_yaw = f_vspy*l_vsp+f_bt*l_bt */
  /* tau_y=f_vspy+f_bt */
  /* solve for f_bt and f_vspy */
  /* MATLAB Function 'Force2Control': '<S3>:1' */
  /* '<S3>:1:3' */
  rtb_u_vsp = sqrt(Group6Task6_2017_ssp_B.f_vspx * Group6Task6_2017_ssp_B.f_vspx
                   + Group6Task6_2017_ssp_B.f_vspy *
                   Group6Task6_2017_ssp_B.f_vspy) /
    Group6Task6_2017_ssp_P.Sat_Forces_Value[0];

  /* '<S3>:1:4' */
  rtb_u_bt = Group6Task6_2017_ssp_B.f_bt /
    Group6Task6_2017_ssp_P.Sat_Forces_Value[1];

  /* '<S3>:1:5' */
  Group6Task6_2017_ssp_B.alpha = rt_atan2d_snf(Group6Task6_2017_ssp_B.f_vspy,
    Group6Task6_2017_ssp_B.f_vspx);

  /* MATLAB Function: '<Root>/Sat_Chk_BT' */
  Group6Task6_2017_ssp_Sat_Chk_BT(rtb_u_bt,
    &Group6Task6_2017_ssp_B.sf_Sat_Chk_BT);

  /* MATLAB Function: '<Root>/Sat_Chk_VSP' */
  Group6Task6_2017_ssp_Sat_Chk_BT(rtb_u_vsp,
    &Group6Task6_2017_ssp_B.sf_Sat_Chk_VSP);

  /* Clock: '<S4>/Clock' */
  rtb_Output = Group6Task6_2017_ssp_M->Timing.t[0];

  /* Step: '<S4>/Step' */
  if (Group6Task6_2017_ssp_M->Timing.t[0] < Group6Task6_2017_ssp_P.Ramp_start) {
    rtb_DeadZone = Group6Task6_2017_ssp_P.Step_Y0;
  } else {
    rtb_DeadZone = Group6Task6_2017_ssp_P.Ramp_slope;
  }

  /* End of Step: '<S4>/Step' */

  /* Sum: '<S4>/Output' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Product: '<S4>/Product'
   *  Sum: '<S4>/Sum'
   */
  rtb_Output = (rtb_Output - Group6Task6_2017_ssp_P.Ramp_start) * rtb_DeadZone +
    Group6Task6_2017_ssp_P.Ramp_X0;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Output > Group6Task6_2017_ssp_P.Saturation_UpperSat) {
    Group6Task6_2017_ssp_B.Saturation =
      Group6Task6_2017_ssp_P.Saturation_UpperSat;
  } else if (rtb_Output < Group6Task6_2017_ssp_P.Saturation_LowerSat) {
    Group6Task6_2017_ssp_B.Saturation =
      Group6Task6_2017_ssp_P.Saturation_LowerSat;
  } else {
    Group6Task6_2017_ssp_B.Saturation = rtb_Output;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Logic: '<Root>/Logical Operator' */
  Group6Task6_2017_ssp_B.LogicalOperator =
    (Group6Task6_2017_ssp_B.sf_Sat_Chk_VSP.error ||
     Group6Task6_2017_ssp_B.sf_Sat_Chk_BT.error);
}

/* Model update function */
static void Group6Task6_2017_ssp_update(void)
{
  /* Update for Memory: '<Root>/Memory1' */
  Group6Task6_2017_ssp_DW.Memory1_PreviousInput =
    Group6Task6_2017_ssp_B.current_mode;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Group6Task6_2017_ssp_M->Timing.clockTick0)) {
    ++Group6Task6_2017_ssp_M->Timing.clockTickH0;
  }

  Group6Task6_2017_ssp_M->Timing.t[0] =
    Group6Task6_2017_ssp_M->Timing.clockTick0 *
    Group6Task6_2017_ssp_M->Timing.stepSize0 +
    Group6Task6_2017_ssp_M->Timing.clockTickH0 *
    Group6Task6_2017_ssp_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Group6Task6_2017_ssp_M->Timing.clockTick1)) {
      ++Group6Task6_2017_ssp_M->Timing.clockTickH1;
    }

    Group6Task6_2017_ssp_M->Timing.t[1] =
      Group6Task6_2017_ssp_M->Timing.clockTick1 *
      Group6Task6_2017_ssp_M->Timing.stepSize1 +
      Group6Task6_2017_ssp_M->Timing.clockTickH1 *
      Group6Task6_2017_ssp_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void Group6Task6_2017_ssp_initialize(void)
{
  /* InitializeConditions for Memory: '<Root>/Memory1' */
  Group6Task6_2017_ssp_DW.Memory1_PreviousInput =
    Group6Task6_2017_ssp_P.Memory1_X0;
}

/* Model terminate function */
static void Group6Task6_2017_ssp_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Group6Task6_2017_ssp_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Group6Task6_2017_ssp_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Group6Task6_2017_ssp_initialize();
}

void MdlTerminate(void)
{
  Group6Task6_2017_ssp_terminate();
}

/* Registration function */
RT_MODEL_Group6Task6_2017_ssp_T *Group6Task6_2017_ssp(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Group6Task6_2017_ssp_M, 0,
                sizeof(RT_MODEL_Group6Task6_2017_ssp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Group6Task6_2017_ssp_M->solverInfo,
                          &Group6Task6_2017_ssp_M->Timing.simTimeStep);
    rtsiSetTPtr(&Group6Task6_2017_ssp_M->solverInfo, &rtmGetTPtr
                (Group6Task6_2017_ssp_M));
    rtsiSetStepSizePtr(&Group6Task6_2017_ssp_M->solverInfo,
                       &Group6Task6_2017_ssp_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Group6Task6_2017_ssp_M->solverInfo,
                          (&rtmGetErrorStatus(Group6Task6_2017_ssp_M)));
    rtsiSetRTModelPtr(&Group6Task6_2017_ssp_M->solverInfo,
                      Group6Task6_2017_ssp_M);
  }

  rtsiSetSimTimeStep(&Group6Task6_2017_ssp_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Group6Task6_2017_ssp_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Group6Task6_2017_ssp_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Group6Task6_2017_ssp_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Group6Task6_2017_ssp_M->Timing.sampleTimes =
      (&Group6Task6_2017_ssp_M->Timing.sampleTimesArray[0]);
    Group6Task6_2017_ssp_M->Timing.offsetTimes =
      (&Group6Task6_2017_ssp_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Group6Task6_2017_ssp_M->Timing.sampleTimes[0] = (0.0);
    Group6Task6_2017_ssp_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    Group6Task6_2017_ssp_M->Timing.offsetTimes[0] = (0.0);
    Group6Task6_2017_ssp_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Group6Task6_2017_ssp_M, &Group6Task6_2017_ssp_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Group6Task6_2017_ssp_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Group6Task6_2017_ssp_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Group6Task6_2017_ssp_M, -1);
  Group6Task6_2017_ssp_M->Timing.stepSize0 = 0.2;
  Group6Task6_2017_ssp_M->Timing.stepSize1 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Group6Task6_2017_ssp_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Group6Task6_2017_ssp_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Group6Task6_2017_ssp_M->rtwLogInfo, (NULL));
    rtliSetLogT(Group6Task6_2017_ssp_M->rtwLogInfo, "tout");
    rtliSetLogX(Group6Task6_2017_ssp_M->rtwLogInfo, "");
    rtliSetLogXFinal(Group6Task6_2017_ssp_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Group6Task6_2017_ssp_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Group6Task6_2017_ssp_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Group6Task6_2017_ssp_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Group6Task6_2017_ssp_M->rtwLogInfo, 1);
    rtliSetLogY(Group6Task6_2017_ssp_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Group6Task6_2017_ssp_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Group6Task6_2017_ssp_M->rtwLogInfo, (NULL));
  }

  Group6Task6_2017_ssp_M->solverInfoPtr = (&Group6Task6_2017_ssp_M->solverInfo);
  Group6Task6_2017_ssp_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Group6Task6_2017_ssp_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Group6Task6_2017_ssp_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Group6Task6_2017_ssp_M->ModelData.blockIO = ((void *) &Group6Task6_2017_ssp_B);
  (void) memset(((void *) &Group6Task6_2017_ssp_B), 0,
                sizeof(B_Group6Task6_2017_ssp_T));

  /* parameters */
  Group6Task6_2017_ssp_M->ModelData.defaultParam = ((real_T *)
    &Group6Task6_2017_ssp_P);

  /* states (dwork) */
  Group6Task6_2017_ssp_M->ModelData.dwork = ((void *) &Group6Task6_2017_ssp_DW);
  (void) memset((void *)&Group6Task6_2017_ssp_DW, 0,
                sizeof(DW_Group6Task6_2017_ssp_T));

  /* Initialize Sizes */
  Group6Task6_2017_ssp_M->Sizes.numContStates = (0);/* Number of continuous states */
  Group6Task6_2017_ssp_M->Sizes.numY = (0);/* Number of model outputs */
  Group6Task6_2017_ssp_M->Sizes.numU = (0);/* Number of model inputs */
  Group6Task6_2017_ssp_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Group6Task6_2017_ssp_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Group6Task6_2017_ssp_M->Sizes.numBlocks = (46);/* Number of blocks */
  Group6Task6_2017_ssp_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  Group6Task6_2017_ssp_M->Sizes.numBlockPrms = (134);/* Sum of parameter "widths" */
  return Group6Task6_2017_ssp_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_Group6Task6_2017_ssp
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern Group6Task6_2017_ssp_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_B.PosXLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // select
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_B.select, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_B.PosYLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // R2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_B.R2_continuous, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 4;
}

double ni_extout[15];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.sf_Sat_Chk_BT.u_out,0,0,0);
  } else {
    index += 1;
  }

  // u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.sf_Sat_Chk_VSP.u_out,0,0,0);
  } else {
    index += 1;
  }

  // u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.sf_Sat_Chk_VSP.u_out,0,0,0);
  } else {
    index += 1;
  }

  // alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.alpha,0,
      0,0);
  } else {
    index += 1;
  }

  // alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.alpha,0,
      0,0);
  } else {
    index += 1;
  }

  // omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.Saturation,0,0,0);
  } else {
    index += 1;
  }

  // omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.Saturation,0,0,0);
  } else {
    index += 1;
  }

  // Current Mode : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.current_mode,0,0,0);
  } else {
    index += 1;
  }

  // Error State Flag: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_B.LogicalOperator,0,8,0);
  } else {
    index += 1;
  }

  // f_vspx: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.f_vspx,
      0,0,0);
  } else {
    index += 1;
  }

  // f_vspy: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.f_vspy,
      0,0,0);
  } else {
    index += 1;
  }

  // f_bt: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.f_bt,0,
      0,0);
  } else {
    index += 1;
  }

  // tau_yaw: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.tau_yaw,
      0,0,0);
  } else {
    index += 1;
  }

  // tau_x: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.tau_x,0,
      0,0);
  } else {
    index += 1;
  }

  // tau_y: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.tau_y,0,
      0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 15;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.sf_Sat_Chk_BT.u_out,0,0,0);

  // u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.sf_Sat_Chk_VSP.u_out,0,0,0);

  // u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.sf_Sat_Chk_VSP.u_out,0,0,0);

  // alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.alpha,0,0,
    0);

  // alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.alpha,0,0,
    0);

  // omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.Saturation,0,0,0);

  // omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.Saturation,0,0,0);

  // Current Mode : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.current_mode,0,0,0);

  // Error State Flag: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Group6Task6_2017_ssp_B.LogicalOperator,0,8,0);

  // f_vspx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.f_vspx,0,
    0,0);

  // f_vspy: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.f_vspy,0,
    0,0);

  // f_bt: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.f_bt,0,0,
    0);

  // tau_yaw: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.tau_yaw,0,
    0,0);

  // tau_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.tau_x,0,0,
    0);

  // tau_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Group6Task6_2017_ssp_B.tau_y,0,0,
    0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "group6task6_2017_ssp/Ramp/Constant1/Value", offsetof
    (P_Group6Task6_2017_ssp_T, Ramp_X0), 29, 1, 2, 0, 0 },

  { 1, "group6task6_2017_ssp/Ramp/Step/After", offsetof(P_Group6Task6_2017_ssp_T,
    Ramp_slope), 29, 1, 2, 2, 0 },

  { 2, "group6task6_2017_ssp/Ramp/Constant/Value", offsetof
    (P_Group6Task6_2017_ssp_T, Ramp_start), 29, 1, 2, 4, 0 },

  { 3, "group6task6_2017_ssp/Ramp/Step/Time", offsetof(P_Group6Task6_2017_ssp_T,
    Ramp_start), 29, 1, 2, 6, 0 },

  { 4, "group6task6_2017_ssp/Memory1/X0", offsetof(P_Group6Task6_2017_ssp_T,
    Memory1_X0), 29, 1, 2, 8, 0 },

  { 5, "group6task6_2017_ssp/Dead Zone/LowerValue", offsetof
    (P_Group6Task6_2017_ssp_T, DeadZone_Start), 29, 1, 2, 10, 0 },

  { 6, "group6task6_2017_ssp/Dead Zone/UpperValue", offsetof
    (P_Group6Task6_2017_ssp_T, DeadZone_End), 29, 1, 2, 12, 0 },

  { 7, "group6task6_2017_ssp/Dead Zone1/LowerValue", offsetof
    (P_Group6Task6_2017_ssp_T, DeadZone1_Start), 29, 1, 2, 14, 0 },

  { 8, "group6task6_2017_ssp/Dead Zone1/UpperValue", offsetof
    (P_Group6Task6_2017_ssp_T, DeadZone1_End), 29, 1, 2, 16, 0 },

  { 9, "group6task6_2017_ssp/Dead Zone2/LowerValue", offsetof
    (P_Group6Task6_2017_ssp_T, DeadZone2_Start), 29, 1, 2, 18, 0 },

  { 10, "group6task6_2017_ssp/Dead Zone2/UpperValue", offsetof
    (P_Group6Task6_2017_ssp_T, DeadZone2_End), 29, 1, 2, 20, 0 },

  { 11, "group6task6_2017_ssp/Max_Global_Forces/Value", offsetof
    (P_Group6Task6_2017_ssp_T, Max_Global_Forces_Value), 23, 4, 2, 22, 0 },

  { 12, "group6task6_2017_ssp/Sat_Forces/Value", offsetof
    (P_Group6Task6_2017_ssp_T, Sat_Forces_Value), 24, 2, 2, 24, 0 },

  { 13, "group6task6_2017_ssp/Ramp/Step/Before", offsetof
    (P_Group6Task6_2017_ssp_T, Step_Y0), 29, 1, 2, 26, 0 },

  { 14, "group6task6_2017_ssp/Saturation/UpperLimit", offsetof
    (P_Group6Task6_2017_ssp_T, Saturation_UpperSat), 29, 1, 2, 28, 0 },

  { 15, "group6task6_2017_ssp/Saturation/LowerLimit", offsetof
    (P_Group6Task6_2017_ssp_T, Saturation_LowerSat), 29, 1, 2, 30, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 16;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 4,                                /* Parameter at index 11 */
  1, 2,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "group6task6_2017_ssp/PosXLeft", 0, "", offsetof(B_Group6Task6_2017_ssp_T,
    PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "group6task6_2017_ssp/select", 0, "", offsetof(B_Group6Task6_2017_ssp_T,
    select)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "group6task6_2017_ssp/PosYLeft", 0, "", offsetof(B_Group6Task6_2017_ssp_T,
    PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "group6task6_2017_ssp/R2_continuous", 0, "", offsetof
    (B_Group6Task6_2017_ssp_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 6, 0 },

  { 4, "group6task6_2017_ssp/Saturation", 0, "", offsetof
    (B_Group6Task6_2017_ssp_T, Saturation)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 8, 0 },

  { 5, "group6task6_2017_ssp/Sel_Control_Mode", 0, "current_mode", offsetof
    (B_Group6Task6_2017_ssp_T, current_mode)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 10, 0 },

  { 6, "group6task6_2017_ssp/Force2Control", 1, "alpha", offsetof
    (B_Group6Task6_2017_ssp_T, alpha)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12,
    0 },

  { 7, "group6task6_2017_ssp/Force Allocation", 0, "f_vspx", offsetof
    (B_Group6Task6_2017_ssp_T, f_vspx)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    14, 0 },

  { 8, "group6task6_2017_ssp/Force Allocation", 1, "f_vspy", offsetof
    (B_Group6Task6_2017_ssp_T, f_vspy)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    16, 0 },

  { 9, "group6task6_2017_ssp/Force Allocation", 2, "f_bt", offsetof
    (B_Group6Task6_2017_ssp_T, f_bt)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 18,
    0 },

  { 10, "group6task6_2017_ssp/Contoller_Map", 0, "tau_x", offsetof
    (B_Group6Task6_2017_ssp_T, tau_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 20,
    0 },

  { 11, "group6task6_2017_ssp/Contoller_Map", 1, "tau_y", offsetof
    (B_Group6Task6_2017_ssp_T, tau_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 22,
    0 },

  { 12, "group6task6_2017_ssp/Contoller_Map", 2, "tau_yaw", offsetof
    (B_Group6Task6_2017_ssp_T, tau_yaw)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    24, 0 },

  { 13, "group6task6_2017_ssp/Logical Operator", 0, "", offsetof
    (B_Group6Task6_2017_ssp_T, LogicalOperator)+0*sizeof(boolean_T), BLOCKIO_SIG,
    8, 1, 2, 26, 0 },

  { 14, "group6task6_2017_ssp/Sat_Chk_VSP", 0, "u_out", offsetof
    (B_Group6Task6_2017_ssp_T, sf_Sat_Chk_VSP.u_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "group6task6_2017_ssp/Sat_Chk_VSP", 1, "error", offsetof
    (B_Group6Task6_2017_ssp_T, sf_Sat_Chk_VSP.error)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 30, 0 },

  { 16, "group6task6_2017_ssp/Sat_Chk_BT", 0, "u_out", offsetof
    (B_Group6Task6_2017_ssp_T, sf_Sat_Chk_BT.u_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 32, 0 },

  { 17, "group6task6_2017_ssp/Sat_Chk_BT", 1, "error", offsetof
    (B_Group6Task6_2017_ssp_T, sf_Sat_Chk_BT.error)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 34, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 18;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 19;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 1, "select ", 1, EXT_IN, 1, 1, 1 },

  { 2, "PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 3, "R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 0, "u_BT", 1, EXT_OUT, 1, 1, 1 },

  { 1, "u_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 2, "u_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 3, "alpha_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 4, "alpha_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 5, "omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Current Mode ", 1, EXT_OUT, 1, 1, 1 },

  { 8, "Error State Flag", 1, EXT_OUT, 1, 1, 1 },

  { 9, "f_vspx", 1, EXT_OUT, 1, 1, 1 },

  { 10, "f_vspy", 1, EXT_OUT, 1, 1, 1 },

  { 11, "f_bt", 1, EXT_OUT, 1, 1, 1 },

  { 12, "tau_yaw", 1, EXT_OUT, 1, 1, 1 },

  { 13, "tau_x", 1, EXT_OUT, 1, 1, 1 },

  { 14, "tau_y", 1, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.2, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "group6task6_2017_ssp";
static char* NI_CompiledModelVersion = "1.161";
static char* NI_CompiledModelDateTime = "Tue Jan 31 15:39:05 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real Group6Task6_2017_ssp_P
   In the rest of the code Group6Task6_2017_ssp_P is redefine to be the read-side
   of rtParameter.
 */
#undef Group6Task6_2017_ssp_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &Group6Task6_2017_ssp_P, sizeof
         (P_Group6Task6_2017_ssp_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka Group6Task6_2017_ssp_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_Group6Task6_2017_ssp_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_Group6Task6_2017_ssp_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_Group6Task6_2017_ssp_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_Group6Task6_2017_ssp_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_Group6Task6_2017_ssp_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_Group6Task6_2017_ssp_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 0;
      *numDiscStates = 505;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.Memory1_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.select_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.select_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.u_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.u_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.u_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.CurrentMode_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.CurrentMode_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.ErrorStateFlag_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.ErrorStateFlag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.f_vspx_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.f_vspx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.f_vspy_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.f_vspy_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.f_bt_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.f_bt_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.tau_yaw_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.tau_yaw_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.tau_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.tau_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.tau_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.tau_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK2");
    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.PosXLeft_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.select_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.select_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.PosYLeft_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.R2_continuous_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.u_BT_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.u_VSP1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.u_VSP2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.alpha_VSP1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.alpha_VSP2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.omega_VSP1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.omega_VSP2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.CurrentMode_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.CurrentMode_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.ErrorStateFlag_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.ErrorStateFlag_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.f_vspx_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.f_vspx_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.f_vspy_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.f_vspy_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.f_bt_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.f_bt_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.tau_yaw_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.tau_yaw_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.tau_x_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.tau_x_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.tau_y_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.tau_y_DWORK2");
    }

    for (count = 0; count < 21; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK1, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 64; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK3, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK3");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.select_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.u_BT_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.CurrentMode_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.ErrorStateFlag_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.f_vspx_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.f_vspy_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.f_bt_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.tau_yaw_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.tau_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.tau_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK2, 0, discStates[idx
       ++], 6, 0);
    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.select_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.R2_continuous_DWORK2,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.u_BT_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.CurrentMode_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.ErrorStateFlag_DWORK2,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.f_vspx_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.f_vspy_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.f_bt_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.tau_yaw_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.tau_x_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType(&Group6Task6_2017_ssp_DW.tau_y_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 21; count++) {
      NIRT_SetValueByDataType
        (&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK1, count,
         discStates[idx++], 18, 0);
    }

    for (count = 0; count < 64; count++) {
      NIRT_SetValueByDataType
        (&Group6Task6_2017_ssp_DW.NIVeriStandSignalProbe_DWORK3, count,
         discStates[idx++], 20, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_Group6Task6_2017_ssp
