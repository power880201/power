/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: A1_Test.c
 *
 * Code generated for Simulink model 'A1_Test'.
 *
 * Model version                  : 9.101
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Jan  1 18:42:51 2023
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Freescale-MPC55xx
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "A1_Test.h"
#include "A1_Test_private.h"

/* Block signals (default storage) */
BlockIO_A1_Test A1_Test_B;

/* Block states (default storage) */
D_Work_A1_Test A1_Test_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_A1_Test A1_Test_PrevZCSigState;

/* Forward declaration for local functions */
static real_T A1_Test_inv_p(real_T x);
static void A1_Test_inv_n(const real_T x[9], real_T y[9]);
static void A1_Test_interp1(const real_T varargin_1[3000], const real_T
  varargin_2[3000], const real_T varargin_3[24], real_T Vq[24]);
static void A1_Test_inv(const real_T x[16], real_T y[16]);
real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* System initialize for function-call system: '<S2>/Background' */
void A1_Test_Background_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_in): '<S112>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S112>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S113>/raptor_delta_time' */
  A1_Test_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S113>/Unit Delay2' */
  A1_Test_DWork.UnitDelay2_DSTATE = true;
}

/* System reset for function-call system: '<S2>/Background' */
void A1_Test_Background_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S113>/raptor_delta_time' */
  A1_Test_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S113>/Unit Delay2' */
  A1_Test_DWork.UnitDelay2_DSTATE = true;
}

/* Output and update for function-call system: '<S2>/Background' */
void A1_Test_Background(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_delta_time;
  boolean_T rtb_raptor_digital_in;
  boolean_T rtb_raptor_sfun_nv_status;
  real_T rtb_MultiportSwitch1;
  boolean_T rtb_Logic;
  boolean_T rtb_LogicalOperator1_h;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator2_c;

  /* S-Function (raptor_sfun_digital_in): '<S112>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    rtb_raptor_digital_in = (boolean_T) Digital_Input_Read_Chan(KEYSW_DG);
  }

  /* S-Function (raptor_sfun_delta_time): '<S113>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (GetDeltaTime_ms((uint32_t*)
      &A1_Test_DWork.raptor_delta_time_DWORK1) * 0.001);
  }

  /* MultiPortSwitch: '<S113>/Multiport Switch1' incorporates:
   *  Constant: '<S113>/Constant'
   *  RelationalOperator: '<S117>/FixPt Relational Operator'
   *  Sum: '<S113>/Add'
   *  UnitDelay: '<S113>/Unit Delay'
   *  UnitDelay: '<S117>/Delay Input1'
   */
  if (rtb_raptor_digital_in == A1_Test_DWork.DelayInput1_DSTATE_c) {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      A1_Test_DWork.UnitDelay_DSTATE_b3;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S113>/Multiport Switch1' */
  /* S-Function (raptor_sfun_nv_status): '<S112>/raptor_sfun_nv_status' incorporates:
   *  UnitDelay: '<S113>/Unit Delay2'
   */
  rtb_raptor_sfun_nv_status = A1_Test_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S113>/Logic' incorporates:
   *  Logic: '<S113>/Logical Operator1'
   *  Logic: '<S113>/Logical Operator2'
   *  Logic: '<S113>/Logical Operator3'
   *  RelationalOperator: '<S113>/Relational Operator'
   *  RelationalOperator: '<S113>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S113>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S113>/raptor_adjustment4'
   */
  rtb_Logic = A1_Test_ConstP.Logic_table[((((uint32_T)(rtb_raptor_digital_in &&
    (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data()))) << 1) +
    ((!rtb_raptor_digital_in) && (rtb_MultiportSwitch1 >= (KeySwLoTimeThr_Data()))))
    << 1) + rtb_raptor_sfun_nv_status];

  /* Logic: '<S112>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S112>/raptor_data_read1'
   */
  rtb_LogicalOperator1_h = (rtb_Logic || KeepModuleOn_Data());

  /* Outputs for Triggered SubSystem: '<S112>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S114>/Trigger'
   */
  if ((!rtb_LogicalOperator1_h) &&
      (A1_Test_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S114>/raptor_data_write' incorporates:
     *  Constant: '<S114>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S114>/Function-Call Generator' incorporates:
     *  SubSystem: '<S114>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S118>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S114>/Function-Call Generator' */
  }

  A1_Test_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S112>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S112>/Raise Startup Event' incorporates:
   *  EnablePort: '<S115>/Enable'
   *  TriggerPort: '<S115>/Trigger'
   */
  if (FgndTasksStopped_Data()) {
    if (rtb_LogicalOperator1_h &&
        (A1_Test_PrevZCSigState.RaiseStartupEvent_Trig_ZCE != POS_ZCSIG)) {
      /* S-Function (fcgen): '<S115>/Function-Call Generator' incorporates:
       *  SubSystem: '<S115>/raptor_startup'
       */
      /* S-Function (raptor_sfun_startup): '<S119>/raptor_data_write' */
      /* S-Function Block */
      {
        extern void App_Startup(void);
        App_Startup();
      }

      /* End of Outputs for S-Function (fcgen): '<S115>/Function-Call Generator' */
    }

    /* Outputs for Triggered SubSystem: '<S112>/Raise Shutdown Event' incorporates:
     *  TriggerPort: '<S114>/Trigger'
     */
    A1_Test_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = rtb_LogicalOperator1_h;

    /* End of Outputs for SubSystem: '<S112>/Raise Shutdown Event' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S112>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S112>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S114>/Trigger'
   */
  A1_Test_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S112>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S112>/Raise Startup Event' */

  /* UnitDelay: '<S112>/Unit Delay' */
  rtb_LogicalOperator2_c = A1_Test_DWork.UnitDelay_DSTATE_ez;

  /* Outputs for Triggered SubSystem: '<S112>/Store EEPROM' incorporates:
   *  TriggerPort: '<S116>/Trigger'
   */
  if ((!A1_Test_DWork.UnitDelay_DSTATE_ez) &&
      (A1_Test_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (fcgen): '<S116>/Function-Call Generator' incorporates:
     *  SubSystem: '<S116>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S120>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S116>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S112>/Unit Delay' */
  A1_Test_PrevZCSigState.StoreEEPROM_Trig_ZCE = rtb_LogicalOperator2_c;

  /* End of Outputs for SubSystem: '<S112>/Store EEPROM' */

  /* S-Function (raptor_sfun_data_write): '<S112>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S112>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_raptor_sfun_nv_status = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S112>/Logical Operator2' incorporates:
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  rtb_LogicalOperator2 = (rtb_raptor_sfun_nv_status || rtb_LogicalOperator1_h ||
    A1_Test_DWork.UnitDelay1_DSTATE);

  /* S-Function (raptor_sfun_digital_out): '<S112>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      static uint8_T rtb_LogicalOperator2_prev = 0U;
      if (rtb_LogicalOperator2 == 0U && rtb_LogicalOperator2_prev == 1U) {
        extern void Module_Shutdown(boolean_T shutdownPower);
        Module_Shutdown(1);
      }

      rtb_LogicalOperator2_prev = rtb_LogicalOperator2;
    }
  }

  /* Update for UnitDelay: '<S117>/Delay Input1' */
  A1_Test_DWork.DelayInput1_DSTATE_c = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S113>/Unit Delay' */
  A1_Test_DWork.UnitDelay_DSTATE_b3 = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S113>/Unit Delay2' */
  A1_Test_DWork.UnitDelay2_DSTATE = rtb_Logic;

  /* Update for UnitDelay: '<S112>/Unit Delay' */
  A1_Test_DWork.UnitDelay_DSTATE_ez = rtb_LogicalOperator1_h;

  /* Update for UnitDelay: '<S112>/Unit Delay1' */
  A1_Test_DWork.UnitDelay1_DSTATE = rtb_LogicalOperator2_c;
}

/*
 * Output and update for atomic system:
 *    '<S6>/MATLAB Function11'
 *    '<S35>/MATLAB Function'
 */
void A1_Test_MATLABFunction11(real_T rtu_tau, real_T rtu_u, real_T rtu_old_u,
  rtB_MATLABFunction11_A1_Test *localB)
{
  /* MATLAB Function 'Foreground/Cut-in strategy/MATLAB Function11': '<S27>:1' */
  /* '<S27>:1:3' */
  /* '<S27>:1:5' */
  localB->y = 0.1 / (rtu_tau + 0.1) * rtu_u + rtu_tau / (rtu_tau + 0.1) *
    rtu_old_u;
}

/* Function for MATLAB Function: '<S17>/time update' */
static real_T A1_Test_inv_p(real_T x)
{
  return 1.0 / x;
}

/* Function for MATLAB Function: '<S8>/MATLAB Function' */
static void A1_Test_inv_n(const real_T x[9], real_T y[9])
{
  real_T b_x[9];
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(x[0]);
  absx21 = fabs(x[1]);
  absx31 = fabs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
  } else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    b_x[0] = x[2];
    b_x[2] = x[0];
    b_x[3] = x[5];
    b_x[5] = x[3];
    b_x[6] = x[8];
    b_x[8] = x[6];
  }

  b_x[1] /= b_x[0];
  b_x[2] /= b_x[0];
  b_x[4] -= b_x[1] * b_x[3];
  b_x[5] -= b_x[2] * b_x[3];
  b_x[7] -= b_x[1] * b_x[6];
  b_x[8] -= b_x[2] * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = absx11;
    absx11 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx11;
    absx11 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx11;
  }

  b_x[5] /= b_x[4];
  b_x[8] -= b_x[5] * b_x[7];
  absx11 = (b_x[1] * b_x[5] - b_x[2]) / b_x[8];
  absx21 = -(b_x[7] * absx11 + b_x[1]) / b_x[4];
  y[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -b_x[5] / b_x[8];
  absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
  y[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / b_x[8];
  absx21 = -b_x[7] * absx11 / b_x[4];
  y[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

/* Function for MATLAB Function: '<S19>/Camera_NEW' */
static void A1_Test_interp1(const real_T varargin_1[3000], const real_T
  varargin_2[3000], const real_T varargin_3[24], real_T Vq[24])
{
  real_T tmp;
  real_T xtmp;
  int32_T exitg1;
  int32_T high_i;
  int32_T i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  memcpy(&A1_Test_B.y[0], &varargin_2[0], 3000U * sizeof(real_T));
  memcpy(&A1_Test_B.x[0], &varargin_1[0], 3000U * sizeof(real_T));
  for (i = 0; i < 24; i++) {
    Vq[i] = (rtNaN);
  }

  i = 0;
  do {
    exitg1 = 0;
    if (i < 3000) {
      if (rtIsNaN(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 1500; i++) {
          xtmp = A1_Test_B.x[i];
          A1_Test_B.x[i] = A1_Test_B.x[2999 - i];
          A1_Test_B.x[2999 - i] = xtmp;
        }

        for (i = 0; i < 1500; i++) {
          xtmp = A1_Test_B.y[i];
          A1_Test_B.y[i] = A1_Test_B.y[2999 - i];
          A1_Test_B.y[2999 - i] = xtmp;
        }
      }

      for (i = 0; i < 24; i++) {
        if (rtIsNaN(varargin_3[i])) {
          Vq[i] = (rtNaN);
        } else if ((!(varargin_3[i] > A1_Test_B.x[2999])) && (!(varargin_3[i] <
                     A1_Test_B.x[0]))) {
          high_i = 3000;
          low_i = 1;
          low_ip1 = 2;
          while (high_i > low_ip1) {
            mid_i = (low_i + high_i) >> 1;
            if (varargin_3[i] >= A1_Test_B.x[mid_i - 1]) {
              low_i = mid_i;
              low_ip1 = mid_i + 1;
            } else {
              high_i = mid_i;
            }
          }

          xtmp = A1_Test_B.x[low_i - 1];
          xtmp = (varargin_3[i] - xtmp) / (A1_Test_B.x[low_i] - xtmp);
          if (xtmp == 0.0) {
            Vq[i] = A1_Test_B.y[low_i - 1];
          } else if (xtmp == 1.0) {
            Vq[i] = A1_Test_B.y[low_i];
          } else {
            tmp = A1_Test_B.y[low_i - 1];
            if (tmp == A1_Test_B.y[low_i]) {
              Vq[i] = tmp;
            } else {
              Vq[i] = (1.0 - xtmp) * tmp + xtmp * A1_Test_B.y[low_i];
            }
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S19>/Camera_NEW' */
static void A1_Test_inv(const real_T x[16], real_T y[16])
{
  real_T A[16];
  real_T s;
  real_T smax;
  int32_T c_ix;
  int32_T c_j;
  int32_T d;
  int32_T d_k;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T jj;
  int8_T ipiv[4];
  int8_T p[4];
  for (c_j = 0; c_j < 16; c_j++) {
    A[c_j] = x[c_j];
    y[c_j] = 0.0;
  }

  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (c_j = 0; c_j < 3; c_j++) {
    jj = c_j * 5;
    iy = 0;
    ix = jj;
    smax = fabs(A[jj]);
    for (d_k = 2; d_k <= 4 - c_j; d_k++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        iy = d_k - 1;
        smax = s;
      }
    }

    if (A[jj + iy] != 0.0) {
      if (iy != 0) {
        iy += c_j;
        ipiv[c_j] = (int8_T)(iy + 1);
        smax = A[c_j];
        A[c_j] = A[iy];
        A[iy] = smax;
        smax = A[c_j + 4];
        A[c_j + 4] = A[iy + 4];
        A[iy + 4] = smax;
        smax = A[c_j + 8];
        A[c_j + 8] = A[iy + 8];
        A[iy + 8] = smax;
        smax = A[c_j + 12];
        A[c_j + 12] = A[iy + 12];
        A[iy + 12] = smax;
      }

      iy = (jj - c_j) + 4;
      for (ix = jj + 1; ix < iy; ix++) {
        A[ix] /= A[jj];
      }
    }

    iy = jj;
    ix = jj + 4;
    for (d_k = 0; d_k <= 2 - c_j; d_k++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = jj + 1;
        ijA = iy + 5;
        d = (iy - c_j) + 8;
        while (ijA + 1 <= d) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
          ijA++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;
  if (ipiv[0] > 1) {
    jj = p[ipiv[0] - 1];
    p[ipiv[0] - 1] = 1;
    p[0] = (int8_T)jj;
  }

  if (ipiv[1] > 2) {
    jj = p[ipiv[1] - 1];
    p[ipiv[1] - 1] = p[1];
    p[1] = (int8_T)jj;
  }

  if (ipiv[2] > 3) {
    jj = p[ipiv[2] - 1];
    p[ipiv[2] - 1] = p[2];
    p[2] = (int8_T)jj;
  }

  jj = p[0] - 1;
  y[(p[0] - 1) << 2] = 1.0;
  for (iy = 0; iy + 1 < 5; iy++) {
    c_j = jj << 2;
    d_k = c_j + iy;
    if (y[d_k] != 0.0) {
      for (ix = iy + 1; ix + 1 < 5; ix++) {
        c_ix = c_j + ix;
        y[c_ix] -= A[(iy << 2) + ix] * y[d_k];
      }
    }
  }

  jj = p[1] - 1;
  y[((p[1] - 1) << 2) + 1] = 1.0;
  for (iy = 1; iy + 1 < 5; iy++) {
    c_j = jj << 2;
    d_k = c_j + iy;
    if (y[d_k] != 0.0) {
      for (ix = iy + 1; ix + 1 < 5; ix++) {
        c_ix = c_j + ix;
        y[c_ix] -= A[(iy << 2) + ix] * y[d_k];
      }
    }
  }

  jj = p[2] - 1;
  y[((p[2] - 1) << 2) + 2] = 1.0;
  for (iy = 2; iy + 1 < 5; iy++) {
    c_j = jj << 2;
    d_k = c_j + iy;
    if (y[d_k] != 0.0) {
      for (ix = iy + 1; ix + 1 < 5; ix++) {
        c_ix = c_j + ix;
        y[c_ix] -= A[(iy << 2) + ix] * y[d_k];
      }
    }
  }

  jj = p[3] - 1;
  c_ix = (p[3] - 1) << 2;
  y[c_ix + 3] = 1.0;
  for (iy = 3; iy + 1 < 5; iy++) {
    if (y[c_ix + iy] != 0.0) {
      for (ix = iy + 1; ix + 1 < 5; ix++) {
        c_j = jj << 2;
        d_k = c_j + ix;
        y[d_k] -= A[(iy << 2) + ix] * y[c_j + iy];
      }
    }
  }

  for (c_j = 0; c_j < 4; c_j++) {
    jj = c_j << 2;
    smax = y[jj + 3];
    if (smax != 0.0) {
      y[jj + 3] = smax / A[15];
      for (d_k = 0; d_k < 3; d_k++) {
        c_ix = d_k + jj;
        y[c_ix] -= y[jj + 3] * A[d_k + 12];
      }
    }

    smax = y[jj + 2];
    if (smax != 0.0) {
      y[jj + 2] = smax / A[10];
      for (d_k = 0; d_k < 2; d_k++) {
        c_ix = d_k + jj;
        y[c_ix] -= y[jj + 2] * A[d_k + 8];
      }
    }

    smax = y[jj + 1];
    if (smax != 0.0) {
      y[jj + 1] = smax / A[5];
      y[jj] -= y[jj + 1] * A[4];
    }

    if (y[jj] != 0.0) {
      y[jj] /= A[0];
    }
  }
}

/* System initialize for function-call system: '<Root>/Foreground' */
void A1_Test_Foreground_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S93>/IC' */
  A1_Test_DWork.IC_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S14>/Delay2' */
  A1_Test_DWork.icLoad = true;

  /* InitializeConditions for Delay: '<S14>/Delay6' */
  A1_Test_DWork.icLoad_l = true;

  /* InitializeConditions for Delay: '<S6>/Delay10' */
  A1_Test_DWork.icLoad_m = true;

  /* InitializeConditions for Delay: '<S35>/Delay' */
  A1_Test_DWork.icLoad_d = true;

  /* SystemInitialize for Enabled SubSystem: '<S1>/V_rel Estimation' */
  /* InitializeConditions for Delay: '<S17>/Delay2' */
  A1_Test_DWork.icLoad_dw = true;

  /* InitializeConditions for Delay: '<S17>/Delay' */
  memcpy(&A1_Test_DWork.Delay_DSTATE_i[0],
         &A1_Test_ConstP.Delay_InitialCondition[0], 9U * sizeof(real_T));

  /* InitializeConditions for Delay: '<S17>/Delay1' */
  A1_Test_DWork.icLoad_l1 = true;

  /* End of SystemInitialize for SubSystem: '<S1>/V_rel Estimation' */
}

/* System reset for function-call system: '<Root>/Foreground' */
void A1_Test_Foreground_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S93>/IC' */
  A1_Test_DWork.IC_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S14>/Delay2' */
  A1_Test_DWork.icLoad = true;

  /* InitializeConditions for Delay: '<S14>/Delay6' */
  A1_Test_DWork.icLoad_l = true;

  /* InitializeConditions for Delay: '<S6>/Delay10' */
  A1_Test_DWork.icLoad_m = true;

  /* InitializeConditions for Delay: '<S35>/Delay' */
  A1_Test_DWork.icLoad_d = true;
}

/* Enable for function-call system: '<Root>/Foreground' */
void A1_Test_Foreground_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_3568__0001(0U);

  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg1' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg1' (raptor_sfun_can_txmsg) */
  can_set_period_3569__0001(0U);

  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg2' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg2' (raptor_sfun_can_txmsg) */
  can_set_period_3570__0001(0U);

  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg3' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg3' (raptor_sfun_can_txmsg) */
  can_set_period_3571__0001(0U);
}

/* Disable for function-call system: '<Root>/Foreground' */
void A1_Test_Foreground_Disable(void)
{
  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_3568__0001(0);

  /* Disable for Enabled SubSystem: '<S1>/V_rel Estimation' */
  A1_Test_DWork.V_relEstimation_MODE = false;

  /* End of Disable for SubSystem: '<S1>/V_rel Estimation' */

  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg1' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg1' (raptor_sfun_can_txmsg) */
  can_set_period_3569__0001(0);

  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg2' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg2' (raptor_sfun_can_txmsg) */
  can_set_period_3570__0001(0);

  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg3' */
  /* Level2 S-Function Block: '<S1>/raptor_can_txmsg3' (raptor_sfun_can_txmsg) */
  can_set_period_3571__0001(0);
}

/* Output and update for function-call system: '<Root>/Foreground' */
void A1_Test_Foreground(void)
{
  /* local block i/o variables */
  real_T rtb_VACCTargetVehAssigned_flg;
  real_T rtb_raptor_adjustment4_j;
  real_T rtb_raptor_adjustment1;
  real_T rtb_Global_X;
  real_T rtb_Global_Y;
  real_T rtb_Ax_PV;
  real_T rtb_Station;
  real_T rtb_raptor_adjustment7;
  real_T rtb_raptor_adjustment6;
  real_T rtb_raptor_adjustment7_b;
  real_T rtb_raptor_adjustment8;
  real_T rtb_raptor_adjustment_k;
  real_T rtb_raptor_adjustment1_c;
  real_T rtb_Yaw_HV_deg;
  real_T rtb_raptor_adjustment_g;
  real_T rtb_raptor_adjustment1_j;
  real_T rtb_raptor_adjustment4_i;
  real_T rtb_raptor_adjustment5;
  real_T rtb_raptor_adjustment3_j;
  real_T rtb_Roll_rate_L1;
  real_T rtb_Roll_rate_L2;
  real_T rtb_Roll_rate_R1;
  real_T rtb_Roll_rate_R2;
  real_T rtb_raptor_adjustment_f;
  real_T rtb_Ay;
  real_T rtb_y_error;
  real_T rtb_Vx_HV;
  real_T rtb_Sqrt1;
  real_T rtb_Product2_g;
  real_T rtb_Max;
  real_T rtb_Max3;
  real_T rtb_Gain_g;
  uint32_T rtb_raptor_can_rxraw8_o3;
  uint32_T rtb_raptor_can_rxraw4_o3;
  uint32_T rtb_raptor_can_rxraw_o3;
  uint32_T rtb_raptor_can_rxraw6_o3;
  uint32_T rtb_raptor_can_rxraw5_o3;
  uint32_T rtb_raptor_can_rxraw1_o3;
  uint32_T rtb_raptor_can_rxraw2_o3;
  uint32_T rtb_raptor_can_rxraw3_o3;
  uint16_T rtb_raptor_can_rxraw8_o1;
  uint16_T rtb_raptor_can_rxraw4_o1;
  uint16_T rtb_raptor_can_rxraw_o1;
  uint16_T rtb_raptor_can_rxraw6_o1;
  uint16_T rtb_raptor_can_rxraw5_o1;
  uint16_T rtb_raptor_can_rxraw1_o1;
  uint16_T rtb_raptor_can_rxraw2_o1;
  uint16_T rtb_raptor_can_rxraw3_o1;
  uint8_T rtb_raptor_can_rxraw3_o5[8];
  boolean_T rtb_raptor_can_rxraw8_o2;
  boolean_T rtb_raptor_can_rxraw4_o2;
  boolean_T rtb_raptor_can_rxraw_o2;
  boolean_T rtb_raptor_can_rxraw6_o2;
  boolean_T rtb_raptor_can_rxraw5_o2;
  boolean_T rtb_raptor_can_rxraw1_o2;
  boolean_T rtb_raptor_can_rxraw2_o2;
  boolean_T rtb_raptor_adjustment5_d;
  boolean_T rtb_raptor_can_rxraw3_o2;
  real_T Q_th[100];
  real_T Am_D[75];
  real_T Amm_D[75];
  real_T F[30];
  real_T h[30];
  real_T rtb_u_TH_tmp[30];
  real_T Am_K[27];
  real_T Amm_K[27];
  real_T Am_D_0[25];
  real_T s[24];
  real_T x_ref_12[24];
  real_T y_ref_12[24];
  real_T a[22];
  real_T x_tmp[22];
  real_T y[22];
  real_T F_acc[20];
  real_T h_acc[20];
  real_T tmp[16];
  real_T tmp_0[16];
  real_T F_D[15];
  real_T Yref_TH[10];
  real_T v[10];
  real_T K_K[9];
  real_T P[9];
  real_T Q_K[9];
  real_T b_a[9];
  real_T rtb_u_tmp[9];
  real_T rtb_u_tmp_0[9];
  real_T tmp_2[9];
  real_T tmp_1[5];
  real_T rtb_C[4];
  real_T F_0[3];
  real_T P_0[3];
  real_T rtb_X1[3];
  real_T d_y;
  real_T f_y;
  real_T rtb_Add1;
  real_T rtb_Add13;
  real_T rtb_Add14;
  real_T rtb_Add17;
  real_T rtb_Add8;
  real_T rtb_Add9;
  real_T rtb_Add_bp;
  real_T rtb_Gain15;
  real_T rtb_Gain29;
  real_T rtb_Gain46;
  real_T rtb_Gain7;
  real_T rtb_Sqrt;
  real_T rtb_Switch14;
  real_T rtb_Switch15;
  real_T rtb_Switch7;
  real_T rtb_UnitDelay_b;
  real_T rtb_UnitDelay_f;
  real_T rtb_UnitDelay_g;
  real_T rtb_UnitDelay_j;
  real_T sum_y;
  real_T x_tmp_tmp;
  int32_T Am_K_tmp;
  int32_T Amm_K_tmp;
  int32_T F_tmp;
  int32_T P_tmp;
  int32_T b_a_tmp;
  int32_T i;
  int8_T Q_K_tmp[9];
  int8_T b_tmp[3];
  int8_T b_tmp_0[3];
  int8_T b_tmp_1;
  boolean_T rtb_ACC_mode;
  boolean_T rtb_LogicalOperator4;
  boolean_T rtb_RelationalOperator_i;
  static const real_T a_0[9] = { 1.0, 0.0, 0.0, 0.1, 1.0, 0.0,
    0.005000000000000001, 0.1, 1.0 };

  static const real_T b_a_0[3] = { -0.00016666666666666669,
    -0.005000000000000001, -0.1 };

  static const int8_T c[3] = { 1, 0, 0 };

  static const real_T e[3] = { -0.00016666666666666672, -0.005000000000000001,
    -0.1 };

  static const real_T d[9] = { 1.0, 0.1, 0.005000000000000001, 0.0, 1.0, 0.1,
    0.0, 0.0, 1.0 };

  static const real_T c_b[9] = { 1.0, 0.0, 0.0, 0.1, 1.0, 0.0,
    0.005000000000000001, 0.1, 0.66666666666666663 };

  static const int8_T e_b[100] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1 };

  static const int8_T f_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T c_0[5] = { 0.0, 0.0, 1.0, 0.1, 0.0 };

  static const int8_T a_1[5] = { 1, 0, 0, 0, 0 };

  const real_T *rtb_MultiportSwitch1_g_0;
  boolean_T exitg1;

  /* UnitDelay: '<S42>/Unit Delay' */
  rtb_UnitDelay_g = A1_Test_DWork.UnitDelay_DSTATE;

  /* UnitDelay: '<S41>/Unit Delay' */
  rtb_UnitDelay_b = A1_Test_DWork.UnitDelay_DSTATE_j;

  /* UnitDelay: '<S36>/Unit Delay' */
  rtb_UnitDelay_j = A1_Test_DWork.UnitDelay_DSTATE_f;

  /* UnitDelay: '<S33>/Unit Delay' */
  rtb_UnitDelay_f = A1_Test_DWork.UnitDelay_DSTATE_b;

  /* S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg' */

  /* S-Function Block:<S1>/raptor_can_txmsg */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: Brake_Pressor   */
    /* Brake_Pressor   - StartBit: 36U, BitLength: 12U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_UnitDelay_g < -20.48)
        tempS = (int32_T)-2048.0;
      else if ((real_T)rtb_UnitDelay_g > 20.47)
        tempS = (int32_T)2046.9999999999998;
      else if ((real_T)rtb_UnitDelay_g < 0)
        tempS = (int32_T)(int32_T)((rtb_UnitDelay_g) * 100.0f);
      else
        tempS = (int32_T)((rtb_UnitDelay_g) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp << 4);
    temp_shift &= ((uint8_T)240U);
    data[4U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 4);
    data[3U] |= temp_shift;

    /* Signal: Brake_Pressor_F */
    /* Brake_Pressor_F - StartBit: 40U, BitLength: 12U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_UnitDelay_b < -20.48)
        tempS = (int32_T)-2048.0;
      else if ((real_T)rtb_UnitDelay_b > 20.47)
        tempS = (int32_T)2046.9999999999998;
      else if ((real_T)rtb_UnitDelay_b < 0)
        tempS = (int32_T)(int32_T)((rtb_UnitDelay_b) * 100.0f);
      else
        tempS = (int32_T)((rtb_UnitDelay_b) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[5U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    temp_shift &= ((uint8_T)15U);
    data[4U] |= temp_shift;

    /* Signal: Driving_Tq      */
    /* Driving_Tq      - StartBit: 56U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_UnitDelay_j < -3276.8)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_UnitDelay_j > 3276.7000000000003)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_UnitDelay_j < 0)
        tempS = (int32_T)(int32_T)((rtb_UnitDelay_j) * 10.0f);
      else
        tempS = (int32_T)((rtb_UnitDelay_j) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[7U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[6U] |= temp_shift;

    /* Signal: Steer_Ang       */
    /* Steer_Ang       - StartBit: 16U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_UnitDelay_f < -3276.8)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_UnitDelay_f > 3276.7000000000003)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_UnitDelay_f < 0)
        tempS = (int32_T)(int32_T)((rtb_UnitDelay_f) * 10.0f);
      else
        tempS = (int32_T)((rtb_UnitDelay_f) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[2U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[1U] |= temp_shift;
    can_set_period_3568__0001(0U);
    can_send_3568__0001(787U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw8' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw8 */
  can_get_3567__0001(&rtb_raptor_can_rxraw8_o1, &rtb_raptor_can_rxraw8_o3,
                     &rtb_raptor_can_rxraw8_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack8' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack8 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: Ay                          */

      /* Signal: Ay                        */
      temp = 0;
      temp |= (((uint32_T)data[5U]) & 255)
        ;
      temp |= (((uint32_T)data[4U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Ay = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: y_error                     */

      /* Signal: y_error                   */
      temp = 0;
      temp |= (((uint32_T)data[6U]) & 255)
        ;
      if (temp & 128)
        temp |= -256;
      rtb_y_error = (((real_T) ((int32_T) temp) / (real_T) 10.0) );
    }

    {
      uint32_T temp;

      /*    Signal: VACCTargetVehAssigned_flg   */

      /* Signal: VACCTargetVehAssigned_flg */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 3)
        ;
      if (temp & 2)
        temp |= -4;
      rtb_VACCTargetVehAssigned_flg = (((real_T) ((int32_T) temp) ) );
    }
  }

  /* Gain: '<S1>/Gain15' incorporates:
   *  S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment2'
   */
  rtb_Gain15 = 0.27777777777777779 * (ACCSetSpeed_kph_Data());

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment4' */
  rtb_raptor_adjustment4_j = (Est_switch_Data());

  /* Outputs for Atomic SubSystem: '<S1>/Limit' */
  /* Constant: '<S1>/Constant' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  limit_lib(rtb_raptor_adjustment4_j, 1.0, 0.0, &A1_Test_B.Limit_c);

  /* End of Outputs for SubSystem: '<S1>/Limit' */

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment1' */
  rtb_raptor_adjustment1 = (OnlyPY_signal_Data());

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw4' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw4 */
  can_get_3564__0001(&rtb_raptor_can_rxraw4_o1, &rtb_raptor_can_rxraw4_o3,
                     &rtb_raptor_can_rxraw4_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack4' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack4 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: X_PV   */

      /* Signal: X_PV */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      temp |= (((uint32_T)data[5U]) & 255)
        << 16;
      if (temp & 8388608)
        temp |= -16777216;
      rtb_Vx_HV = (((real_T) ((int32_T) temp) / (real_T) 1000.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Y_PV   */

      /* Signal: Y_PV */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      temp |= (((uint32_T)data[1U]) & 255)
        << 16;
      if (temp & 8388608)
        temp |= -16777216;
      rtb_Sqrt1 = (((real_T) ((int32_T) temp) / (real_T) 1000.0) );
    }
  }

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw */
  can_get_3560__0001(&rtb_raptor_can_rxraw_o1, &rtb_raptor_can_rxraw_o3,
                     &rtb_raptor_can_rxraw_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: Global_X   */

      /* Signal: Global_X */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      temp |= (((uint32_T)data[5U]) & 255)
        << 16;
      if (temp & 8388608)
        temp |= -16777216;
      rtb_Global_X = (((real_T) ((int32_T) temp) / (real_T) 1000.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Global_Y   */

      /* Signal: Global_Y */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      temp |= (((uint32_T)data[1U]) & 255)
        << 16;
      if (temp & 8388608)
        temp |= -16777216;
      rtb_Global_Y = (((real_T) ((int32_T) temp) / (real_T) 1000.0) );
    }
  }

  /* Sum: '<S43>/Add' */
  rtb_Add_bp = rtb_Vx_HV - rtb_Global_X;

  /* Sum: '<S43>/Add1' */
  rtb_Add1 = rtb_Sqrt1 - rtb_Global_Y;

  /* Sqrt: '<S43>/Sqrt1' incorporates:
   *  Math: '<S43>/Square'
   *  Math: '<S43>/Square1'
   *  Sum: '<S43>/Add4'
   */
  rtb_Sqrt1 = rtb_Add_bp * rtb_Add_bp + rtb_Add1 * rtb_Add1;

  /* Sqrt: '<S43>/Sqrt' */
  rtb_Sqrt = sqrt(rtb_Sqrt1);

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw6' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw6 */
  can_get_3566__0001(&rtb_raptor_can_rxraw6_o1, &rtb_raptor_can_rxraw6_o3,
                     &rtb_raptor_can_rxraw6_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack6' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack6 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: X_APV   */

      /* Signal: X_APV */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      temp |= (((uint32_T)data[5U]) & 255)
        << 16;
      if (temp & 8388608)
        temp |= -16777216;
      rtb_Sqrt1 = (((real_T) ((int32_T) temp) / (real_T) 1000.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Y_APV   */

      /* Signal: Y_APV */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      temp |= (((uint32_T)data[1U]) & 255)
        << 16;
      if (temp & 8388608)
        temp |= -16777216;
      rtb_Vx_HV = (((real_T) ((int32_T) temp) / (real_T) 1000.0) );
    }
  }

  /* Sum: '<S43>/Add8' */
  rtb_Add8 = rtb_Sqrt1 - rtb_Global_X;

  /* Sum: '<S43>/Add9' */
  rtb_Add9 = rtb_Vx_HV - rtb_Global_Y;

  /* Sqrt: '<S43>/Sqrt1' incorporates:
   *  Math: '<S43>/Square2'
   *  Math: '<S43>/Square3'
   *  Sum: '<S43>/Add10'
   */
  rtb_Sqrt1 = rtb_Add8 * rtb_Add8 + rtb_Add9 * rtb_Add9;
  rtb_Sqrt1 = sqrt(rtb_Sqrt1);

  /* Sum: '<S43>/Add13' incorporates:
   *  Constant: '<S43>/car_length2'
   */
  rtb_Add13 = rtb_Sqrt1 - 4.5;

  /* S-Function (raptor_sfun_adjustment): '<S45>/raptor_adjustment' */
  rtb_Switch15 = (Cut_in_Secenary_flg_Data());

  /* Switch: '<S45>/Switch7' incorporates:
   *  Constant: '<S43>/car_length'
   *  S-Function (raptor_sfun_adjustment): '<S45>/raptor_adjustment'
   *  Sum: '<S43>/Add7'
   */
  if (rtb_Switch15 != 0.0) {
    rtb_Switch7 = rtb_Sqrt - 4.5;
  } else {
    rtb_Switch7 = rtb_Add13;
  }

  /* End of Switch: '<S45>/Switch7' */

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw5' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw5 */
  can_get_3565__0001(&rtb_raptor_can_rxraw5_o1, &rtb_raptor_can_rxraw5_o3,
                     &rtb_raptor_can_rxraw5_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack5' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack5 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: Vx_PV    */

      /* Signal: Vx_PV  */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Vx_HV = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Ax_PV    */

      /* Signal: Ax_PV  */
      temp = 0;
      temp |= (((uint32_T)data[5U]) & 255)
        ;
      temp |= (((uint32_T)data[4U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Ax_PV = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Vx_APV   */

      /* Signal: Vx_APV */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Product2_g = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Ax_APV   */

      /* Signal: Ax_APV */
      temp = 0;
      temp |= (((uint32_T)data[1U]) & 255)
        ;
      temp |= (((uint32_T)data[0U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Max3 = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }
  }

  /* Gain: '<S1>/Gain46' */
  rtb_Gain46 = 0.27777777777777779 * rtb_Vx_HV;

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw1' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw1 */
  can_get_3561__0001(&rtb_raptor_can_rxraw1_o1, &rtb_raptor_can_rxraw1_o3,
                     &rtb_raptor_can_rxraw1_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack1' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack1 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: Vx_HV     */

      /* Signal: Vx_HV   */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Vx_HV = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Vy_HV     */

      /* Signal: Vy_HV   */
      temp = 0;
      temp |= (((uint32_T)data[5U]) & 255)
        ;
      temp |= (((uint32_T)data[4U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Max = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Ax_HV     */

      /* Signal: Ax_HV   */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Gain_g = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Station   */

      /* Signal: Station */
      temp = 0;
      temp |= (((uint32_T)data[1U]) & 255)
        ;
      temp |= (((uint32_T)data[0U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Station = (((real_T) ((int32_T) temp) / (real_T) 10.0) );
    }
  }

  /* Gain: '<S1>/Gain29' */
  rtb_Gain29 = 0.27777777777777779 * rtb_Vx_HV;

  /* Product: '<S21>/Product2' incorporates:
   *  Gain: '<S1>/Gain47'
   */
  rtb_Product2_g *= 0.27777777777777779;

  /* MinMax: '<S43>/Min4' incorporates:
   *  MATLAB Function: '<S15>/MPC_TH'
   */
  rtb_RelationalOperator_i = rtIsNaN(rtb_Gain15);
  if ((rtb_Product2_g <= rtb_Gain15) || rtb_RelationalOperator_i) {
    sum_y = rtb_Product2_g;
  } else {
    sum_y = rtb_Gain15;
  }

  /* End of MinMax: '<S43>/Min4' */

  /* Sum: '<S43>/Add14' */
  rtb_Add14 = sum_y - rtb_Gain29;

  /* Switch: '<S45>/Switch14' incorporates:
   *  Sum: '<S43>/Add2'
   */
  if (rtb_Switch15 != 0.0) {
    rtb_Switch14 = rtb_Gain46 - rtb_Gain29;
  } else {
    rtb_Switch14 = rtb_Add14;
  }

  /* End of Switch: '<S45>/Switch14' */

  /* Gain: '<S1>/Gain7' */
  rtb_Gain7 = 9.81 * rtb_Gain_g;

  /* MinMax: '<S102>/Max3' incorporates:
   *  Gain: '<S1>/Gain48'
   */
  rtb_Max3 *= 9.81;

  /* Gain: '<S37>/Gain' incorporates:
   *  Abs: '<S56>/Abs'
   */
  rtb_Gain_g = fabs(rtb_Max3);

  /* Switch: '<S56>/Switch' */
  if (!(rtb_Gain_g > 0.01)) {
    /* MinMax: '<S102>/Max3' incorporates:
     *  Constant: '<S56>/Constant1'
     */
    rtb_Max3 = 0.0;
  }

  /* End of Switch: '<S56>/Switch' */

  /* Sum: '<S43>/Add17' */
  rtb_Add17 = rtb_Max3 - rtb_Gain7;

  /* Switch: '<S45>/Switch15' incorporates:
   *  Sum: '<S43>/Add3'
   */
  if (rtb_Switch15 != 0.0) {
    /* Gain: '<S1>/Gain44' */
    rtb_Switch15 = 9.81 * rtb_Ax_PV;

    /* Switch: '<S57>/Switch' incorporates:
     *  Abs: '<S57>/Abs'
     *  Constant: '<S57>/Constant1'
     */
    if (!(fabs(rtb_Switch15) > 0.01)) {
      rtb_Switch15 = 0.0;
    }

    /* End of Switch: '<S57>/Switch' */
    rtb_Switch15 -= rtb_Gain7;
  } else {
    rtb_Switch15 = rtb_Add17;
  }

  /* End of Switch: '<S45>/Switch15' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S43>/Constant3'
   *  Sum: '<S43>/Add5'
   *  Switch: '<S53>/Switch'
   */
  if (rtb_Sqrt >= 0.0) {
    /* Switch: '<S52>/Switch' incorporates:
     *  Abs: '<S52>/Abs'
     *  Constant: '<S52>/Constant'
     */
    if (!(fabs(rtb_Add_bp) > 0.1)) {
      rtb_Add_bp = 0.1;
    }

    /* End of Switch: '<S52>/Switch' */

    /* Switch: '<S60>/Switch' incorporates:
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S78>/Lower Limit'
     *  Constant: '<S78>/Upper Limit'
     *  Logic: '<S60>/Logical Operator'
     *  Logic: '<S78>/AND'
     *  Product: '<S60>/Divide'
     *  RelationalOperator: '<S78>/Lower Test'
     *  RelationalOperator: '<S78>/Upper Test'
     */
    if ((!(-0.001 <= rtb_Add_bp)) || (!(rtb_Add_bp <= 0.001))) {
      rtb_Add1 /= rtb_Add_bp;
    } else {
      rtb_Add1 = 100.0;
    }

    /* End of Switch: '<S60>/Switch' */

    /* Outputs for Atomic SubSystem: '<S43>/ATAN' */
    atan_lib(rtb_Add1, &A1_Test_B.ATAN);

    /* End of Outputs for SubSystem: '<S43>/ATAN' */

    /* Outputs for Atomic SubSystem: '<S43>/rad2deg' */
    rad2deg_lib(A1_Test_B.ATAN.deg2rad.y, &A1_Test_B.rad2deg);

    /* End of Outputs for SubSystem: '<S43>/rad2deg' */
    rtb_Add1 = A1_Test_B.rad2deg.y;
  } else {
    if (!(fabs(rtb_Add_bp) > 0.1)) {
      /* Switch: '<S53>/Switch' incorporates:
       *  Constant: '<S53>/Constant'
       */
      rtb_Add_bp = 0.1;
    }

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S79>/Lower Limit'
     *  Constant: '<S79>/Upper Limit'
     *  Logic: '<S61>/Logical Operator'
     *  Logic: '<S79>/AND'
     *  Product: '<S61>/Divide'
     *  RelationalOperator: '<S79>/Lower Test'
     *  RelationalOperator: '<S79>/Upper Test'
     */
    if ((!(-0.001 <= rtb_Add_bp)) || (!(rtb_Add_bp <= 0.001))) {
      rtb_Add1 /= rtb_Add_bp;
    } else {
      rtb_Add1 = 100.0;
    }

    /* End of Switch: '<S61>/Switch' */

    /* Outputs for Atomic SubSystem: '<S43>/ATAN1' */
    atan_lib(rtb_Add1, &A1_Test_B.ATAN1);

    /* End of Outputs for SubSystem: '<S43>/ATAN1' */

    /* Outputs for Atomic SubSystem: '<S43>/rad2deg1' */
    rad2deg_lib(A1_Test_B.ATAN1.deg2rad.y, &A1_Test_B.rad2deg1);

    /* End of Outputs for SubSystem: '<S43>/rad2deg1' */
    rtb_Add1 = A1_Test_B.rad2deg1.y + 180.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S43>/Constant4'
   *  Sum: '<S43>/Add6'
   */
  if (!(rtb_Add1 >= -0.1)) {
    rtb_Add1 += 360.0;
  }

  /* End of Switch: '<S43>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S43>/deg2rad' */
  deg2rad_lib(rtb_Add1, &A1_Test_B.deg2rad);

  /* End of Outputs for SubSystem: '<S43>/deg2rad' */

  /* Outputs for Atomic SubSystem: '<S43>/SIN' */
  sin_lib(A1_Test_B.deg2rad.y, &A1_Test_B.SIN);

  /* End of Outputs for SubSystem: '<S43>/SIN' */

  /* Switch: '<S43>/Switch2' incorporates:
   *  Abs: '<S54>/Abs'
   *  Constant: '<S43>/Constant8'
   *  Sum: '<S43>/Add11'
   *  Switch: '<S54>/Switch'
   */
  if (rtb_Sqrt1 >= 0.0) {
    /* Switch: '<S55>/Switch' incorporates:
     *  Abs: '<S55>/Abs'
     *  Constant: '<S55>/Constant'
     */
    if (!(fabs(rtb_Add8) > 0.1)) {
      rtb_Add8 = 0.1;
    }

    /* End of Switch: '<S55>/Switch' */

    /* Switch: '<S62>/Switch' incorporates:
     *  Constant: '<S43>/Constant6'
     *  Constant: '<S80>/Lower Limit'
     *  Constant: '<S80>/Upper Limit'
     *  Logic: '<S62>/Logical Operator'
     *  Logic: '<S80>/AND'
     *  Product: '<S62>/Divide'
     *  RelationalOperator: '<S80>/Lower Test'
     *  RelationalOperator: '<S80>/Upper Test'
     */
    if ((!(-0.001 <= rtb_Add8)) || (!(rtb_Add8 <= 0.001))) {
      rtb_Add9 /= rtb_Add8;
    } else {
      rtb_Add9 = 100.0;
    }

    /* End of Switch: '<S62>/Switch' */

    /* Outputs for Atomic SubSystem: '<S43>/ATAN2' */
    atan_lib(rtb_Add9, &A1_Test_B.ATAN2);

    /* End of Outputs for SubSystem: '<S43>/ATAN2' */

    /* Outputs for Atomic SubSystem: '<S43>/rad2deg2' */
    rad2deg_lib(A1_Test_B.ATAN2.deg2rad.y, &A1_Test_B.rad2deg2);

    /* End of Outputs for SubSystem: '<S43>/rad2deg2' */
    rtb_Add9 = A1_Test_B.rad2deg2.y;
  } else {
    if (!(fabs(rtb_Add8) > 0.1)) {
      /* Switch: '<S54>/Switch' incorporates:
       *  Constant: '<S54>/Constant'
       */
      rtb_Add8 = 0.1;
    }

    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S43>/Constant7'
     *  Constant: '<S81>/Lower Limit'
     *  Constant: '<S81>/Upper Limit'
     *  Logic: '<S63>/Logical Operator'
     *  Logic: '<S81>/AND'
     *  Product: '<S63>/Divide'
     *  RelationalOperator: '<S81>/Lower Test'
     *  RelationalOperator: '<S81>/Upper Test'
     */
    if ((!(-0.001 <= rtb_Add8)) || (!(rtb_Add8 <= 0.001))) {
      rtb_Add9 /= rtb_Add8;
    } else {
      rtb_Add9 = 100.0;
    }

    /* End of Switch: '<S63>/Switch' */

    /* Outputs for Atomic SubSystem: '<S43>/ATAN3' */
    atan_lib(rtb_Add9, &A1_Test_B.ATAN3);

    /* End of Outputs for SubSystem: '<S43>/ATAN3' */

    /* Outputs for Atomic SubSystem: '<S43>/rad2deg3' */
    rad2deg_lib(A1_Test_B.ATAN3.deg2rad.y, &A1_Test_B.rad2deg3);

    /* End of Outputs for SubSystem: '<S43>/rad2deg3' */
    rtb_Add9 = A1_Test_B.rad2deg3.y + 180.0;
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Switch: '<S43>/Switch3' incorporates:
   *  Constant: '<S43>/Constant9'
   *  Sum: '<S43>/Add12'
   */
  if (!(rtb_Add9 >= -0.1)) {
    rtb_Add9 += 360.0;
  }

  /* End of Switch: '<S43>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S43>/deg2rad1' */
  deg2rad_lib(rtb_Add9, &A1_Test_B.deg2rad1);

  /* End of Outputs for SubSystem: '<S43>/deg2rad1' */

  /* Outputs for Atomic SubSystem: '<S43>/SIN1' */
  sin_lib(A1_Test_B.deg2rad1.y, &A1_Test_B.SIN1);

  /* End of Outputs for SubSystem: '<S43>/SIN1' */

  /* Outputs for Enabled SubSystem: '<S12>/Subsystem5' incorporates:
   *  EnablePort: '<S44>/Enable'
   */
  if (rtb_VACCTargetVehAssigned_flg > 0.0) {
    /* MATLAB Function: '<S44>/MATLAB Function7' incorporates:
     *  Abs: '<S44>/Abs2'
     *  Abs: '<S44>/Abs3'
     *  Product: '<S43>/Product'
     *  Product: '<S43>/Product1'
     */
    /* MATLAB Function 'Foreground/Subsystem11/Subsystem5/MATLAB Function7': '<S82>:1' */
    if (rtb_raptor_adjustment1 == 0.0) {
      /* '<S82>:1:2' */
      if ((rtb_Add13 < rtb_Switch7) && (rtb_Sqrt1 * A1_Test_B.SIN1.SIN_Function
           - rtb_Sqrt * A1_Test_B.SIN.SIN_Function <= 0.3) && (fabs(rtb_Add9) -
           fabs(rtb_Add1) <= 5.0)) {
        /* '<S82>:1:3' */
        /* '<S82>:1:5' */
        A1_Test_B.RR = rtb_Add13;

        /* '<S82>:1:6' */
        A1_Test_B.RV = rtb_Add14;

        /* '<S82>:1:7' */
        A1_Test_B.RA = rtb_Add17;

        /* '<S82>:1:8' */
        A1_Test_B.trig = 1.0;
      } else {
        /* '<S82>:1:11' */
        A1_Test_B.RR = rtb_Switch7;

        /* '<S82>:1:12' */
        A1_Test_B.RV = rtb_Switch14;

        /* '<S82>:1:13' */
        A1_Test_B.RA = rtb_Switch15;

        /* '<S82>:1:14' */
        A1_Test_B.trig = 0.0;
      }
    } else {
      /* '<S82>:1:17' */
      A1_Test_B.RR = rtb_Switch7;

      /* '<S82>:1:18' */
      A1_Test_B.RV = rtb_Switch14;

      /* '<S82>:1:19' */
      A1_Test_B.RA = rtb_Switch15;

      /* '<S82>:1:20' */
      A1_Test_B.trig = 0.0;
    }

    /* End of MATLAB Function: '<S44>/MATLAB Function7' */
  }

  /* End of Outputs for SubSystem: '<S12>/Subsystem5' */

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment7' */
  rtb_raptor_adjustment7 = (Kalman_trig_Data());

  /* Outputs for Enabled SubSystem: '<S1>/V_rel Estimation' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtb_raptor_adjustment7 > 0.0) {
    if (!A1_Test_DWork.V_relEstimation_MODE) {
      /* InitializeConditions for Delay: '<S17>/Delay2' */
      A1_Test_DWork.icLoad_dw = true;

      /* InitializeConditions for Delay: '<S17>/Delay' */
      memcpy(&A1_Test_DWork.Delay_DSTATE_i[0],
             &A1_Test_ConstP.Delay_InitialCondition[0], 9U * sizeof(real_T));

      /* InitializeConditions for Delay: '<S17>/Delay1' */
      A1_Test_DWork.icLoad_l1 = true;
      A1_Test_DWork.V_relEstimation_MODE = true;
    }

    /* Delay: '<S17>/Delay2' */
    if (A1_Test_DWork.icLoad_dw) {
      A1_Test_DWork.Delay2_DSTATE_o = rtb_Gain7;
    }

    /* Delay: '<S17>/Delay1' incorporates:
     *  SignalConversion generated from: '<S17>/Delay1'
     */
    if (rt_ZCFcn(RISING_ZERO_CROSSING,&A1_Test_PrevZCSigState.Delay1_Reset_ZCE,
                 (A1_Test_B.trig)) != NO_ZCEVENT) {
      A1_Test_DWork.icLoad_l1 = true;
    }

    if (A1_Test_DWork.icLoad_l1) {
      A1_Test_DWork.Delay1_DSTATE_k[0] = A1_Test_B.RR;
      A1_Test_DWork.Delay1_DSTATE_k[1] = A1_Test_B.RV;
      A1_Test_DWork.Delay1_DSTATE_k[2] = A1_Test_B.RA;
    }

    /* Gain: '<S17>/sample time' incorporates:
     *  Delay: '<S17>/Delay2'
     *  Sum: '<S17>/Add3'
     */
    rtb_Sqrt = (rtb_Gain7 - A1_Test_DWork.Delay2_DSTATE_o) * 10.0;

    /* MATLAB Function 'Foreground/V_rel Estimation/measurement update': '<S110>:1' */
    /* '<S110>:1:5' */
    /* MATLAB Function 'Foreground/V_rel Estimation/time update': '<S111>:1' */
    /* '<S111>:1:8' */
    /* '<S111>:1:7' */
    for (i = 0; i < 3; i++) {
      /* MATLAB Function: '<S17>/measurement update' incorporates:
       *  Delay: '<S17>/Delay1'
       */
      rtb_X1[i] = ((a_0[i + 3] * A1_Test_DWork.Delay1_DSTATE_k[1] + a_0[i] *
                    A1_Test_DWork.Delay1_DSTATE_k[0]) + a_0[i + 6] *
                   A1_Test_DWork.Delay1_DSTATE_k[2]) + b_a_0[i] * rtb_Sqrt;

      /* MATLAB Function: '<S17>/time update' */
      b_tmp[i] = c[i];
      b_tmp_0[i] = c[i];
    }

    /* MATLAB Function: '<S17>/time update' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Delay: '<S17>/Delay'
     */
    rtb_Sqrt = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Sqrt += ((A1_Test_DWork.Delay_DSTATE_i[3 * i + 1] * (real_T)b_tmp_0[1]
                    + A1_Test_DWork.Delay_DSTATE_i[3 * i] * (real_T)b_tmp_0[0])
                   + A1_Test_DWork.Delay_DSTATE_i[3 * i + 2] * (real_T)b_tmp_0[2])
        * (real_T)b_tmp[i];
      P_0[i] = (A1_Test_DWork.Delay_DSTATE_i[i + 3] * (real_T)b_tmp[1] +
                A1_Test_DWork.Delay_DSTATE_i[i] * (real_T)b_tmp[0]) +
        A1_Test_DWork.Delay_DSTATE_i[i + 6] * (real_T)b_tmp[2];
    }

    rtb_Add17 = A1_Test_inv_p(rtb_Sqrt + 0.01);
    rtb_Sqrt = P_0[0] * rtb_Add17;
    rtb_Add13 = P_0[1] * rtb_Add17;
    rtb_Switch7 = P_0[2] * rtb_Add17;
    for (i = 0; i < 3; i++) {
      b_tmp_1 = b_tmp_0[i];
      b_a[3 * i] = rtb_Sqrt * (real_T)b_tmp_1;
      b_a[3 * i + 1] = rtb_Add13 * (real_T)b_tmp_1;
      b_a[3 * i + 2] = rtb_Switch7 * (real_T)b_tmp_1;
    }

    /* '<S111>:1:8' */
    /* '<S111>:1:9' */
    rtb_Sqrt = A1_Test_inv_p(0.01);

    /* MATLAB Function: '<S17>/MATLAB Function2' */
    /* MATLAB Function 'Foreground/V_rel Estimation/MATLAB Function2': '<S109>:1' */
    /* '<S109>:1:3' */
    rtb_Add13 = 0.0;
    for (i = 0; i < 3; i++) {
      /* MATLAB Function: '<S17>/MATLAB Function2' */
      rtb_Add13 += (real_T)c[i] * rtb_X1[i];

      /* MATLAB Function: '<S17>/time update' incorporates:
       *  Delay: '<S17>/Delay'
       */
      P_0[i] = 0.0;
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        P_tmp = 3 * Amm_K_tmp + i;
        rtb_Switch7 = A1_Test_DWork.Delay_DSTATE_i[P_tmp] -
          ((A1_Test_DWork.Delay_DSTATE_i[3 * Amm_K_tmp + 1] * b_a[i + 3] +
            A1_Test_DWork.Delay_DSTATE_i[3 * Amm_K_tmp] * b_a[i]) +
           A1_Test_DWork.Delay_DSTATE_i[3 * Amm_K_tmp + 2] * b_a[i + 6]);
        P[P_tmp] = rtb_Switch7;
        P_0[i] += rtb_Switch7 * (real_T)b_tmp[Amm_K_tmp];
      }
    }

    /* MATLAB Function: '<S17>/MATLAB Function2' incorporates:
     *  MATLAB Function: '<S17>/time update'
     */
    rtb_Add17 = A1_Test_B.RR - rtb_Add13;
    A1_Test_B.X2[0] = P_0[0] * rtb_Sqrt * rtb_Add17 + rtb_X1[0];
    A1_Test_B.X2[1] = P_0[1] * rtb_Sqrt * rtb_Add17 + rtb_X1[1];
    A1_Test_B.X2[2] = P_0[2] * rtb_Sqrt * rtb_Add17 + rtb_X1[2];

    /* SignalConversion generated from: '<S17>/a_rel' */
    A1_Test_B.OutportBufferFora_rel = A1_Test_B.X2[2];

    /* SignalConversion generated from: '<S17>/v_rel' */
    A1_Test_B.OutportBufferForv_rel = A1_Test_B.X2[1];

    /* Update for Delay: '<S17>/Delay2' */
    A1_Test_DWork.icLoad_dw = false;
    A1_Test_DWork.Delay2_DSTATE_o = rtb_Gain7;

    /* MATLAB Function: '<S17>/time update' */
    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        K_K[b_a_tmp] = 0.0;
        K_K[b_a_tmp] += P[3 * Amm_K_tmp] * a_0[i];
        K_K[b_a_tmp] += P[3 * Amm_K_tmp + 1] * a_0[i + 3];
        K_K[b_a_tmp] += P[3 * Amm_K_tmp + 2] * a_0[i + 6];
      }

      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        b_a[b_a_tmp] = 0.0;
        b_a[b_a_tmp] += d[3 * Amm_K_tmp] * K_K[i];
        b_a[b_a_tmp] += d[3 * Amm_K_tmp + 1] * K_K[i + 3];
        b_a[b_a_tmp] += d[3 * Amm_K_tmp + 2] * K_K[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_Sqrt = e[i];
      P[3 * i] = -0.03333333333333334 * rtb_Sqrt;
      P[3 * i + 1] = -1.0000000000000002 * rtb_Sqrt;
      P[3 * i + 2] = -20.0 * rtb_Sqrt;
    }

    /* Update for Delay: '<S17>/Delay' incorporates:
     *  MATLAB Function: '<S17>/time update'
     */
    for (i = 0; i < 9; i++) {
      A1_Test_DWork.Delay_DSTATE_i[i] = b_a[i] + P[i];
    }

    /* End of Update for Delay: '<S17>/Delay' */

    /* Update for Delay: '<S17>/Delay1' */
    A1_Test_DWork.icLoad_l1 = false;
    A1_Test_DWork.Delay1_DSTATE_k[0] = A1_Test_B.X2[0];
    A1_Test_DWork.Delay1_DSTATE_k[1] = A1_Test_B.X2[1];
    A1_Test_DWork.Delay1_DSTATE_k[2] = A1_Test_B.X2[2];
  } else {
    A1_Test_DWork.V_relEstimation_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/V_rel Estimation' */

  /* MultiPortSwitch: '<S1>/Multiport Switch4' */
  if ((int32_T)A1_Test_B.Limit_c.MinMax10 == 0) {
    /* Gain: '<S37>/Gain' */
    rtb_Gain_g = A1_Test_B.RV;
  } else {
    /* Gain: '<S37>/Gain' */
    rtb_Gain_g = A1_Test_B.OutportBufferForv_rel;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch4' */

  /* Outputs for Atomic SubSystem: '<S4>/Limit' */
  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  limit_lib(rtb_Gain_g + rtb_Gain29, 100.0, 0.0, &A1_Test_B.Limit);

  /* End of Outputs for SubSystem: '<S4>/Limit' */

  /* MultiPortSwitch: '<S1>/Multiport Switch3' incorporates:
   *  MultiPortSwitch: '<S16>/Multiport Switch'
   */
  if ((int32_T)A1_Test_B.Limit_c.MinMax10 == 0) {
    /* Gain: '<S37>/Gain' */
    rtb_Gain_g = A1_Test_B.RR;
    rtb_Add14 = A1_Test_B.RR;
  } else {
    /* Gain: '<S37>/Gain' */
    rtb_Gain_g = A1_Test_B.X2[0];
    rtb_Add14 = A1_Test_B.X2[0];
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch3' */

  /* Gain: '<S37>/Gain' incorporates:
   *  Bias: '<S4>/dist_safe1'
   */
  rtb_Gain_g += -2.0;

  /* RelationalOperator: '<S4>/Relational Operator4' incorporates:
   *  Gain: '<S4>/TH_ref4'
   */
  rtb_ACC_mode = (1.5 * rtb_Gain15 < rtb_Gain_g);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Bias: '<S4>/Add Constant'
   *  Constant: '<S4>/Constant36'
   *  Gain: '<S4>/TH_ref'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  Sum: '<S4>/Add13'
   */
  rtb_ACC_mode = ((!(rtb_VACCTargetVehAssigned_flg != 0.0)) || ((rtb_Gain15 <
    A1_Test_B.Limit.MinMax10 + 1.0) && rtb_ACC_mode) || (rtb_ACC_mode && (1.5 *
    rtb_Gain29 - rtb_Gain_g < -0.5)));

  /* Switch: '<S106>/Switch' incorporates:
   *  Abs: '<S16>/Abs4'
   *  Bias: '<S16>/Add Constant5'
   *  Constant: '<S108>/Lower Limit'
   *  Constant: '<S108>/Upper Limit'
   *  Constant: '<S16>/Constant8'
   *  Logic: '<S106>/Logical Operator'
   *  Logic: '<S108>/AND'
   *  Product: '<S106>/Divide'
   *  RelationalOperator: '<S108>/Lower Test'
   *  RelationalOperator: '<S108>/Upper Test'
   */
  if ((!(-1.0 <= rtb_Gain29)) || (!(rtb_Gain29 <= 4.166666666666667))) {
    /* Saturate: '<S106>/Saturation' */
    if (rtb_Gain29 <= 0.1) {
      rtb_Add17 = 0.1;
    } else {
      rtb_Add17 = rtb_Gain29;
    }

    /* End of Saturate: '<S106>/Saturation' */
    rtb_Sqrt = fabs(rtb_Add14 + -2.0) / rtb_Add17;
  } else {
    rtb_Sqrt = 1.5;
  }

  /* End of Switch: '<S106>/Switch' */

  /* Outputs for Atomic SubSystem: '<S16>/Limit1' */
  /* Constant: '<S16>/Constant2' incorporates:
   *  Constant: '<S16>/Constant3'
   */
  limit_lib(rtb_Sqrt, 10.0, 0.0, &A1_Test_B.Limit1);

  /* End of Outputs for SubSystem: '<S16>/Limit1' */

  /* Sum: '<S13>/Add4' */
  rtb_Switch7 = rtb_Product2_g - rtb_Gain29;

  /* MATLAB Function: '<S13>/Estimation_TTCx_PV2' */
  rtb_Sqrt = A1_Test_B.RR;
  rtb_Add13 = rtb_Switch7;

  /* MATLAB Function 'Foreground/Subsystem2/Estimation_TTCx_PV2': '<S86>:1' */
  /* '<S86>:1:2' */
  if (A1_Test_B.RR < 0.0) {
    /* '<S86>:1:5' */
    /* '<S86>:1:6' */
    rtb_Sqrt = -A1_Test_B.RR;

    /* '<S86>:1:7' */
    rtb_Add13 = -rtb_Switch7;

    /* '<S86>:1:8' */
  }

  if (rtb_Sqrt < 0.1) {
    /* '<S86>:1:40' */
    /* '<S86>:1:41' */
    rtb_Sqrt = 0.0;
  } else {
    /* '<S86>:1:43' */
    rtb_Sqrt = -rtb_Sqrt / rtb_Add13;
  }

  if (rtb_Sqrt > 10.0) {
    /* '<S86>:1:45' */
    /* '<S86>:1:46' */
    rtb_Sqrt = 10.0;
  }

  if (rtb_Sqrt < 0.0) {
    /* '<S86>:1:48' */
    /* '<S86>:1:49' */
    rtb_Sqrt = 10.0;
  }

  /* Switch: '<S13>/Switch13' incorporates:
   *  Constant: '<S13>/Constant21'
   *  Constant: '<S83>/Constant'
   *  MATLAB Function: '<S13>/Estimation_TTCx_PV2'
   *  RelationalOperator: '<S83>/Compare'
   */
  if (A1_Test_B.RR == 0.0) {
    rtb_Add13 = 10.0;
  } else {
    rtb_Add13 = rtb_Sqrt;
  }

  /* End of Switch: '<S13>/Switch13' */

  /* S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg1' */

  /* S-Function Block:<S1>/raptor_can_txmsg1 */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: ACC_MODE                  */
    /* ACC_MODE                  - StartBit: 2U, BitLength: 2U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((boolean_T)rtb_ACC_mode < -2.0)
        tempS = (int32_T)-2.0;
      else if ((boolean_T)rtb_ACC_mode > 1.0)
        tempS = (int32_T)1.0;
      else
        tempS = (int32_T)((rtb_ACC_mode));
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp << 2);
    temp_shift &= ((uint8_T)12U);
    data[0U] |= temp_shift;

    /* Signal: TH                        */
    /* TH                        - StartBit: 48U, BitLength: 8U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)A1_Test_B.Limit1.MinMax10 < -12.8)
        tempS = (int32_T)-128.0;
      else if ((real_T)A1_Test_B.Limit1.MinMax10 > 12.700000000000001)
        tempS = (int32_T)127.0;
      else if ((real_T)A1_Test_B.Limit1.MinMax10 < 0)
        tempS = (int32_T)(int32_T)((A1_Test_B.Limit1.MinMax10) * 10.0f);
      else
        tempS = (int32_T)((A1_Test_B.Limit1.MinMax10) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[6U] |= temp_shift;

    /* Signal: TTC                       */
    /* TTC                       - StartBit: 56U, BitLength: 8U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Add13 < -12.8)
        tempS = (int32_T)-128.0;
      else if ((real_T)rtb_Add13 > 12.700000000000001)
        tempS = (int32_T)127.0;
      else if ((real_T)rtb_Add13 < 0)
        tempS = (int32_T)(int32_T)((rtb_Add13) * 10.0f);
      else
        tempS = (int32_T)((rtb_Add13) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[7U] |= temp_shift;

    /* Signal: VACCTargetVehAssigned_flg */
    /* VACCTargetVehAssigned_flg - StartBit: 0U, BitLength: 2U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_VACCTargetVehAssigned_flg < -2.0)
        tempS = (int32_T)-2.0;
      else if ((real_T)rtb_VACCTargetVehAssigned_flg > 1.0)
        tempS = (int32_T)1.0;
      else if ((real_T)rtb_VACCTargetVehAssigned_flg < 0)
        tempS = (int32_T)(int32_T)((rtb_VACCTargetVehAssigned_flg));
      else
        tempS = (int32_T)((rtb_VACCTargetVehAssigned_flg));
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)3U);
    data[0U] |= temp_shift;

    /* Signal: Vx_HV                     */
    /* Vx_HV                     - StartBit: 40U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Gain29 < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Gain29 > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Gain29 < 0)
        tempS = (int32_T)(int32_T)((rtb_Gain29) * 100.0f);
      else
        tempS = (int32_T)((rtb_Gain29) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[5U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[4U] |= temp_shift;

    /* Signal: Vx_PV                     */
    /* Vx_PV                     - StartBit: 24U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Gain46 < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Gain46 > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Gain46 < 0)
        tempS = (int32_T)(int32_T)((rtb_Gain46) * 100.0f);
      else
        tempS = (int32_T)((rtb_Gain46) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[3U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[2U] |= temp_shift;

    /* Signal: y_error                   */
    /* y_error                   - StartBit: 8U, BitLength: 8U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_y_error < -12.8)
        tempS = (int32_T)-128.0;
      else if ((real_T)rtb_y_error > 12.700000000000001)
        tempS = (int32_T)127.0;
      else if ((real_T)rtb_y_error < 0)
        tempS = (int32_T)(int32_T)((rtb_y_error) * 10.0f);
      else
        tempS = (int32_T)((rtb_y_error) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[1U] |= temp_shift;
    can_set_period_3569__0001(0U);
    can_send_3569__0001(769U & 0x7FF, 0, 8U, &data[0]);
  }

  /* Switch: '<S93>/Switch1' incorporates:
   *  Delay: '<S92>/Delay1'
   *  Sum: '<S93>/Sum2'
   *  UnitDelay: '<S93>/IC'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  if (A1_Test_DWork.IC_DSTATE >= 0.5) {
    rtb_Gain46 = A1_Test_DWork.UnitDelay_DSTATE_m;
  } else {
    /* Switch: '<S93>/Switch' incorporates:
     *  Constant: '<S92>/Constant48'
     *  Delay: '<S92>/Delay1'
     *  Product: '<S93>/Divide'
     *  Product: '<S93>/Product_tmp1'
     *  Sum: '<S93>/Sum'
     *  UnitDelay: '<S9>/Unit Delay'
     */
    rtb_Gain46 = (A1_Test_DWork.UnitDelay_DSTATE_m - A1_Test_DWork.Delay1_DSTATE)
      * 0.1 / 0.35;
    rtb_Gain46 += A1_Test_DWork.Delay1_DSTATE;
  }

  /* End of Switch: '<S93>/Switch1' */

  /* Delay: '<S14>/Delay2' */
  if (A1_Test_DWork.icLoad) {
    A1_Test_DWork.Delay2_DSTATE = rtb_Gain46;
  }

  /* Switch: '<S91>/Switch7' incorporates:
   *  RelationalOperator: '<S91>/Relational Operator'
   */
  if (rtb_Gain29 >= 0.5) {
    /* Gain: '<S37>/Gain' incorporates:
     *  Delay: '<S14>/Delay2'
     *  Gain: '<S14>/sample time1'
     *  Sum: '<S14>/Add10'
     */
    rtb_Gain_g = (rtb_Gain46 - A1_Test_DWork.Delay2_DSTATE) * 10.0;
  } else {
    /* Gain: '<S37>/Gain' incorporates:
     *  Constant: '<S91>/Constant1'
     */
    rtb_Gain_g = 0.0;
  }

  /* End of Switch: '<S91>/Switch7' */

  /* UnitDelay: '<S10>/Unit Delay' */
  rtb_Sqrt = A1_Test_DWork.UnitDelay_DSTATE_d;

  /* Delay: '<S14>/Delay6' incorporates:
   *  UnitDelay: '<S10>/Unit Delay'
   */
  if (A1_Test_DWork.icLoad_l) {
    A1_Test_DWork.Delay6_DSTATE = A1_Test_DWork.UnitDelay_DSTATE_d;
  }

  /* MinMax: '<S102>/Max3' incorporates:
   *  Delay: '<S14>/Delay6'
   *  Gain: '<S14>/sample time2'
   *  Sum: '<S14>/Add1'
   *  UnitDelay: '<S10>/Unit Delay'
   */
  rtb_Max3 = (A1_Test_DWork.UnitDelay_DSTATE_d - A1_Test_DWork.Delay6_DSTATE) *
    10.0;

  /* S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg2' */

  /* S-Function Block:<S1>/raptor_can_txmsg2 */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: Ax */
    /* Ax - StartBit: 56U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Gain7 < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Gain7 > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Gain7 < 0)
        tempS = (int32_T)(int32_T)((rtb_Gain7) * 100.0f);
      else
        tempS = (int32_T)((rtb_Gain7) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[7U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[6U] |= temp_shift;

    /* Signal: Ay */
    /* Ay - StartBit: 40U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Ay < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Ay > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Ay < 0)
        tempS = (int32_T)(int32_T)((rtb_Ay) * 100.0f);
      else
        tempS = (int32_T)((rtb_Ay) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[5U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[4U] |= temp_shift;

    /* Signal: Jx */
    /* Jx - StartBit: 24U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Gain_g < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Gain_g > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Gain_g < 0)
        tempS = (int32_T)(int32_T)((rtb_Gain_g) * 100.0f);
      else
        tempS = (int32_T)((rtb_Gain_g) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[3U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[2U] |= temp_shift;

    /* Signal: Jy */
    /* Jy - StartBit: 8U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Max3 < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Max3 > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Max3 < 0)
        tempS = (int32_T)(int32_T)((rtb_Max3) * 100.0f);
      else
        tempS = (int32_T)((rtb_Max3) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[1U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[0U] |= temp_shift;
    can_set_period_3570__0001(0U);
    can_send_3570__0001(770U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment6' */
  rtb_raptor_adjustment6 = (Long_trig_Data());

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S13>/Constant20'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S88>/Constant1'
   *  Constant: '<S89>/Lower Limit'
   *  Constant: '<S89>/Upper Limit'
   *  Logic: '<S88>/Logical Operator'
   *  Logic: '<S89>/AND'
   *  Product: '<S88>/Divide'
   *  RelationalOperator: '<S89>/Lower Test'
   *  RelationalOperator: '<S89>/Upper Test'
   */
  if ((!((rtMinusInf) <= rtb_Switch7)) || (!(rtb_Switch7 <= 0.1))) {
    /* Outputs for Atomic SubSystem: '<S88>/Limit' */
    limit_lib(rtb_Switch7, 100.0, 0.1, &A1_Test_B.Limit_f);

    /* End of Outputs for SubSystem: '<S88>/Limit' */
    rtb_Switch7 = A1_Test_B.RR / A1_Test_B.Limit_f.MinMax10;
  } else {
    rtb_Switch7 = 10.0;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Outputs for Atomic SubSystem: '<S13>/Limit' */
  /* Constant: '<S13>/Constant' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  limit_lib(rtb_Switch7, 100.0, -100.0, &A1_Test_B.Limit_m);

  /* End of Outputs for SubSystem: '<S13>/Limit' */

  /* Abs: '<S13>/Abs2' */
  rtb_Switch7 = fabs(A1_Test_B.Limit_m.MinMax10);

  /* Switch: '<S105>/Switch' incorporates:
   *  Abs: '<S16>/Abs'
   *  Bias: '<S16>/Add Constant'
   *  Constant: '<S107>/Lower Limit'
   *  Constant: '<S107>/Upper Limit'
   *  Constant: '<S16>/Constant29'
   *  Logic: '<S105>/Logical Operator'
   *  Logic: '<S107>/AND'
   *  Product: '<S105>/Divide'
   *  RelationalOperator: '<S107>/Lower Test'
   *  RelationalOperator: '<S107>/Upper Test'
   */
  if ((!(-1.0 <= rtb_Gain29)) || (!(rtb_Gain29 <= 1.3888888888888888))) {
    /* Saturate: '<S105>/Saturation' */
    if (rtb_Gain29 <= 0.1) {
      rtb_Add17 = 0.1;
    } else {
      rtb_Add17 = rtb_Gain29;
    }

    /* End of Saturate: '<S105>/Saturation' */
    rtb_Add14 = fabs(rtb_Add14 + -2.0) / rtb_Add17;
  } else {
    rtb_Add14 = 1.5;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Outputs for Atomic SubSystem: '<S16>/Limit' */
  /* Constant: '<S16>/Constant' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  limit_lib(rtb_Add14, 10.0, 0.0, &A1_Test_B.Limit_ns);

  /* End of Outputs for SubSystem: '<S16>/Limit' */

  /* Switch: '<S1>/Switch12' incorporates:
   *  Constant: '<S1>/Constant23'
   */
  if (rtb_VACCTargetVehAssigned_flg != 0.0) {
    rtb_Add14 = A1_Test_B.Limit_ns.MinMax10;
  } else {
    rtb_Add14 = 1.5;
  }

  /* End of Switch: '<S1>/Switch12' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S6>/TH_ref'
   *  Gain: '<S28>/Gain'
   *  RelationalOperator: '<S23>/Compare'
   *  Sum: '<S6>/Add18'
   */
  if (rtb_Add14 - 1.5 <= -0.1) {
    /* S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment' */
    rtb_raptor_adjustment_f = (UseTTC_switch_Data());

    /* Switch: '<S6>/Switch3' incorporates:
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S84>/Constant'
     *  Logic: '<S13>/Logical Operator3'
     *  Logic: '<S6>/Logical Operator'
     *  RelationalOperator: '<S84>/Compare'
     *  RelationalOperator: '<S85>/FixPt Relational Operator'
     *  UnitDelay: '<S85>/Delay Input1'
     */
    if ((rtb_raptor_adjustment_f != 0.0) && ((rtb_Switch7 >
          A1_Test_DWork.DelayInput1_DSTATE) && (rtb_Switch7 >= 2.0))) {
      rtb_Switch14 = 1000.0;
    } else {
      /* Outputs for Atomic SubSystem: '<S6>/Limit1' */
      limit_lib(rtb_raptor_adjustment_f, 1.0, 0.0, &A1_Test_B.Limit1_l);

      /* End of Outputs for SubSystem: '<S6>/Limit1' */

      /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
       *  Bias: '<S6>/Add Constant6'
       *  Constant: '<S6>/Constant'
       *  Constant: '<S6>/Constant1'
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant4'
       *  Constant: '<S6>/Constant5'
       */
      if ((int32_T)A1_Test_B.Limit1_l.MinMax10 == 0) {
        rtb_Switch14 = 0.0;
      } else {
        /* Outputs for Atomic SubSystem: '<S6>/Limit' */
        limit_lib(rtb_Add13 + -2.0, 10.0, 0.0, &A1_Test_B.Limit_l);

        /* End of Outputs for SubSystem: '<S6>/Limit' */
        rtb_Switch14 = A1_Test_B.Limit_l.MinMax10;
      }

      /* End of MultiPortSwitch: '<S6>/Multiport Switch' */
    }

    /* End of Switch: '<S6>/Switch3' */
    rtb_Switch14 *= 5.0;
  } else {
    rtb_Switch14 = 0.0;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Delay: '<S6>/Delay10' */
  if (A1_Test_DWork.icLoad_m) {
    A1_Test_DWork.Delay10_DSTATE = rtb_Add14;
  }

  /* MATLAB Function: '<S6>/MATLAB Function11' incorporates:
   *  Delay: '<S6>/Delay10'
   */
  A1_Test_MATLABFunction11(rtb_Switch14, rtb_Add14, A1_Test_DWork.Delay10_DSTATE,
    &A1_Test_B.sf_MATLABFunction11);

  /* Switch: '<S6>/Switch2' incorporates:
   *  Bias: '<S6>/Add Constant5'
   *  Constant: '<S24>/Constant'
   *  Product: '<S6>/Product2'
   *  RelationalOperator: '<S24>/Compare'
   */
  if (rtb_Gain29 <= 1.3888888888888888) {
    /* MultiPortSwitch: '<S1>/Multiport Switch1' */
    if ((int32_T)A1_Test_B.Limit_c.MinMax10 == 0) {
      rtb_Add17 = A1_Test_B.RR;
    } else {
      rtb_Add17 = A1_Test_B.X2[0];
    }

    /* End of MultiPortSwitch: '<S1>/Multiport Switch1' */
  } else {
    rtb_Add17 = rtb_Gain29 * A1_Test_B.sf_MATLABFunction11.y + 2.0;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* MultiPortSwitch: '<S15>/Multiport Switch2' */
  if ((int32_T)A1_Test_B.Limit_c.MinMax10 == 0) {
    rtb_X1[0] = rtb_Add17;
    rtb_X1[1] = A1_Test_B.RV;
    rtb_X1[2] = A1_Test_B.RA;
  } else {
    rtb_X1[0] = A1_Test_B.X2[0];
    rtb_X1[1] = A1_Test_B.OutportBufferForv_rel;
    rtb_X1[2] = A1_Test_B.OutportBufferFora_rel;
  }

  /* End of MultiPortSwitch: '<S15>/Multiport Switch2' */

  /* Product: '<S21>/Product2' incorporates:
   *  Abs: '<S96>/Abs'
   */
  rtb_Product2_g = fabs(rtb_X1[2]);

  /* Switch: '<S96>/Switch' incorporates:
   *  Constant: '<S96>/Constant'
   */
  if (rtb_Product2_g > 1.0) {
    rtb_Add14 = rtb_X1[2];
  } else {
    rtb_Add14 = 0.0;
  }

  /* End of Switch: '<S96>/Switch' */

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment7' */
  rtb_raptor_adjustment7_b = (Q_th_Data());

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment8' */
  rtb_raptor_adjustment8 = (R_th_Data());

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment' */
  rtb_raptor_adjustment_k = (Q_acc_Data());

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment1' */
  rtb_raptor_adjustment1_c = (R_acc_Data());

  /* MATLAB Function: '<S15>/MPC_TH' incorporates:
   *  SignalConversion generated from: '<S95>/ SFunction '
   */
  /* MATLAB Function 'Foreground/Subsystem8/MPC_TH': '<S95>:1' */
  /* '<S95>:1:29' */
  /* '<S95>:1:36' */
  /* '<S95>:1:38' */
  /* '<S95>:1:41' */
  /* '<S95>:1:57' */
  /* '<S95>:1:58' */
  /* '<S95>:1:81' */
  /* '<S95>:1:89' */
  /* '<S95>:1:91' */
  /* '<S95>:1:94' */
  /* '<S95>:1:10' */
  if ((rtb_Gain29 > rtb_Gain15) || (rtIsNaN(rtb_Gain29) &&
       (!rtb_RelationalOperator_i))) {
    rtb_Switch15 = rtb_Gain15;
  } else {
    rtb_Switch15 = rtb_Gain29;
  }

  /* '<S95>:1:9' */
  /* '<S95>:1:11' */
  for (b_a_tmp = 0; b_a_tmp < 10; b_a_tmp++) {
    /* '<S95>:1:11' */
    /* '<S95>:1:12' */
    Yref_TH[b_a_tmp] = (rtb_Gain7 * 0.1 * ((real_T)b_a_tmp + 1.0) + rtb_Switch15)
      * 1.5;
  }

  /* '<S95>:1:29' */
  if (rtb_raptor_adjustment6 == 1.0) {
    /* '<S95>:1:31' */
    /* '<S95>:1:33' */
    /* '<S95>:1:34' */
    for (i = 0; i < 30; i++) {
      h[i] = 0.0;
      F[i] = 0.0;
    }

    /* '<S95>:1:35' */
    /* '<S95>:1:36' */
    h[0] = 1.0;
    F[0] = 1.0;
    h[10] = 0.0;
    F[10] = 0.1;
    h[20] = 0.0;
    F[20] = 0.005000000000000001;

    /* '<S95>:1:37' */
    for (b_a_tmp = 0; b_a_tmp < 9; b_a_tmp++) {
      /* '<S95>:1:37' */
      /* '<S95>:1:38' */
      for (i = 0; i < 3; i++) {
        P_0[i] = (c_b[3 * i + 1] * h[b_a_tmp + 10] + c_b[3 * i] * h[b_a_tmp]) +
          c_b[3 * i + 2] * h[b_a_tmp + 20];
      }

      /* '<S95>:1:39' */
      for (i = 0; i < 3; i++) {
        h[(b_a_tmp + 10 * i) + 1] = P_0[i];
        F_0[i] = (c_b[3 * i + 1] * F[b_a_tmp + 10] + c_b[3 * i] * F[b_a_tmp]) +
          c_b[3 * i + 2] * F[b_a_tmp + 20];
      }

      F[b_a_tmp + 1] = F_0[0];
      F[b_a_tmp + 11] = F_0[1];
      F[b_a_tmp + 21] = F_0[2];
    }

    /* '<S95>:1:41' */
    for (i = 0; i < 10; i++) {
      v[i] = (h[i + 10] * 0.0 + h[i] * 0.0) + h[i + 20] * 0.33333333333333337;
    }

    /* '<S95>:1:42' */
    for (i = 0; i < 30; i++) {
      h[i] = 0.0;
    }

    /* '<S95>:1:43' */
    memcpy(&h[0], &v[0], 10U * sizeof(real_T));

    /* '<S95>:1:48' */
    rtb_Switch14 = 0.0;

    /* '<S95>:1:49' */
    /* '<S95>:1:50' */
    for (i = 0; i < 9; i++) {
      /* '<S95>:1:50' */
      /* '<S95>:1:51' */
      rtb_Switch14++;

      /* '<S95>:1:52' */
      h[i + 11] = v[(int32_T)rtb_Switch14 - 1];
    }

    /* '<S95>:1:54' */
    rtb_Switch14 = 0.0;

    /* '<S95>:1:49' */
    /* '<S95>:1:50' */
    for (i = 0; i < 8; i++) {
      /* '<S95>:1:50' */
      /* '<S95>:1:51' */
      rtb_Switch14++;

      /* '<S95>:1:52' */
      h[i + 22] = v[(int32_T)rtb_Switch14 - 1];
    }

    /* '<S95>:1:54' */
    /* '<S95>:1:57' */
    /* '<S95>:1:58' */
    /* '<S95>:1:60' */
    /* '<S95>:1:62' */
    /* '<S95>:1:63' */
    /* '<S95>:1:64' */
    /* '<S95>:1:65' */
    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 10; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        rtb_u_TH_tmp[b_a_tmp] = 0.0;
        for (P_tmp = 0; P_tmp < 10; P_tmp++) {
          rtb_u_TH_tmp[b_a_tmp] += (real_T)e_b[10 * Amm_K_tmp + P_tmp] *
            rtb_raptor_adjustment7_b * h[10 * i + P_tmp];
        }
      }

      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        sum_y = 0.0;
        for (P_tmp = 0; P_tmp < 10; P_tmp++) {
          sum_y += rtb_u_TH_tmp[3 * P_tmp + i] * h[10 * Amm_K_tmp + P_tmp];
        }

        b_a_tmp = 3 * Amm_K_tmp + i;
        P[b_a_tmp] = (real_T)f_b[b_a_tmp] * rtb_raptor_adjustment8 + sum_y;
      }
    }

    A1_Test_inv_n(P, b_a);
    rtb_Switch14 = rtb_X1[0] - 2.0;
    rtb_Add_bp = rtb_X1[1];
    for (i = 0; i < 10; i++) {
      v[i] = Yref_TH[i] - ((F[i + 10] * rtb_Add_bp + F[i] * rtb_Switch14) + F[i
                           + 20] * rtb_Add14);
    }

    for (i = 0; i < 3; i++) {
      rtb_X1[i] = 0.0;
      for (Amm_K_tmp = 0; Amm_K_tmp < 10; Amm_K_tmp++) {
        rtb_X1[i] += rtb_u_TH_tmp[3 * Amm_K_tmp + i] * v[Amm_K_tmp];
      }
    }

    for (i = 0; i < 3; i++) {
      P_0[i] = (b_a[i + 3] * rtb_X1[1] + b_a[i] * rtb_X1[0]) + b_a[i + 6] *
        rtb_X1[2];
    }

    rtb_Add14 = (rtb_Gain7 + rtb_Add14) - P_0[0];

    /* '<S95>:1:71' */
    rtb_Switch14 = Yref_TH[0] + 2.0;

    /* '<S95>:1:84' */
    /* '<S95>:1:86' */
    /* '<S95>:1:87' */
    for (i = 0; i < 20; i++) {
      h_acc[i] = 0.0;
      F_acc[i] = 0.0;
    }

    /* '<S95>:1:88' */
    /* '<S95>:1:89' */
    h_acc[0] = 1.0;
    F_acc[0] = 1.0;
    h_acc[10] = 0.0;
    F_acc[10] = 0.1;

    /* '<S95>:1:90' */
    for (b_a_tmp = 0; b_a_tmp < 9; b_a_tmp++) {
      /* '<S95>:1:90' */
      /* '<S95>:1:91' */
      rtb_Add_bp = h_acc[b_a_tmp + 10] * 0.66666666666666663 + h_acc[b_a_tmp] *
        0.1;

      /* '<S95>:1:92' */
      h_acc[b_a_tmp + 1] = h_acc[b_a_tmp];
      h_acc[b_a_tmp + 11] = rtb_Add_bp;
      rtb_Add_bp = F_acc[b_a_tmp + 10] * 0.66666666666666663 + F_acc[b_a_tmp] *
        0.1;
      F_acc[b_a_tmp + 1] = F_acc[b_a_tmp];
      F_acc[b_a_tmp + 11] = rtb_Add_bp;
    }

    /* '<S95>:1:94' */
    for (i = 0; i < 10; i++) {
      Yref_TH[i] = h_acc[i + 10] * 0.33333333333333337;
    }

    /* '<S95>:1:95' */
    for (i = 0; i < 30; i++) {
      h[i] = 0.0;
    }

    /* '<S95>:1:96' */
    memcpy(&h[0], &Yref_TH[0], 10U * sizeof(real_T));

    /* '<S95>:1:100' */
    rtb_Add9 = 0.0;

    /* '<S95>:1:101' */
    /* '<S95>:1:102' */
    for (i = 0; i < 9; i++) {
      /* '<S95>:1:102' */
      /* '<S95>:1:103' */
      rtb_Add9++;

      /* '<S95>:1:104' */
      h[i + 11] = Yref_TH[(int32_T)rtb_Add9 - 1];
    }

    /* '<S95>:1:106' */
    rtb_Add9 = 0.0;

    /* '<S95>:1:101' */
    /* '<S95>:1:102' */
    for (i = 0; i < 8; i++) {
      /* '<S95>:1:102' */
      /* '<S95>:1:103' */
      rtb_Add9++;

      /* '<S95>:1:104' */
      h[i + 22] = Yref_TH[(int32_T)rtb_Add9 - 1];
    }

    /* '<S95>:1:106' */
    /* '<S95>:1:108' */
    for (i = 0; i < 100; i++) {
      Q_th[i] = 0.0;
    }

    for (b_a_tmp = 0; b_a_tmp < 10; b_a_tmp++) {
      Q_th[b_a_tmp + 10 * b_a_tmp] = 1.0;
    }

    for (i = 0; i < 100; i++) {
      Q_th[i] *= rtb_raptor_adjustment_k;
    }

    /* '<S95>:1:109' */
    for (i = 0; i < 9; i++) {
      P[i] = 0.0;
    }

    /* '<S95>:1:111' */
    /* '<S95>:1:112' */
    /* '<S95>:1:114' */
    /* '<S95>:1:115' */
    /* '<S95>:1:116' */
    /* '<S95>:1:117' */
    for (b_a_tmp = 0; b_a_tmp < 3; b_a_tmp++) {
      P[b_a_tmp + 3 * b_a_tmp] = 1.0;
      for (i = 0; i < 10; i++) {
        F_tmp = 3 * i + b_a_tmp;
        F[F_tmp] = 0.0;
        for (Amm_K_tmp = 0; Amm_K_tmp < 10; Amm_K_tmp++) {
          F[F_tmp] += h[10 * b_a_tmp + Amm_K_tmp] * Q_th[10 * i + Amm_K_tmp];
        }
      }
    }

    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        sum_y = 0.0;
        for (P_tmp = 0; P_tmp < 10; P_tmp++) {
          sum_y += F[3 * P_tmp + i] * h[10 * Amm_K_tmp + P_tmp];
        }

        F_tmp = 3 * Amm_K_tmp + i;
        K_K[F_tmp] = P[F_tmp] * rtb_raptor_adjustment1_c + sum_y;
      }
    }

    A1_Test_inv_n(K_K, b_a);
    for (i = 0; i < 10; i++) {
      Yref_TH[i] = F_acc[i + 10] * rtb_Gain7 + F_acc[i] * rtb_Switch15;
    }

    v[0] = rtb_Gain15;
    v[1] = rtb_Gain15;
    v[2] = rtb_Gain15;
    v[3] = rtb_Gain15;
    v[4] = rtb_Gain15;
    v[5] = rtb_Gain15;
    v[6] = rtb_Gain15;
    v[7] = rtb_Gain15;
    v[8] = rtb_Gain15;
    v[9] = rtb_Gain15;
    for (i = 0; i < 10; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 10; Amm_K_tmp++) {
        Q_th[Amm_K_tmp + 10 * i] = v[i] - Yref_TH[Amm_K_tmp];
      }
    }

    for (i = 0; i < 10; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        F_tmp = 3 * i + Amm_K_tmp;
        h[F_tmp] = 0.0;
        for (P_tmp = 0; P_tmp < 10; P_tmp++) {
          h[F_tmp] += F[3 * P_tmp + Amm_K_tmp] * Q_th[10 * i + P_tmp];
        }
      }
    }

    for (i = 0; i < 10; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        P_tmp = 3 * i + Amm_K_tmp;
        F[P_tmp] = 0.0;
        F[P_tmp] += h[3 * i] * b_a[Amm_K_tmp];
        F[P_tmp] += h[3 * i + 1] * b_a[Amm_K_tmp + 3];
        F[P_tmp] += h[3 * i + 2] * b_a[Amm_K_tmp + 6];
      }
    }

    rtb_Gain15 = F[0];
  } else {
    /* '<S95>:1:73' */
    rtb_Add14 = 0.0;

    /* '<S95>:1:74' */
    rtb_Switch14 = 0.0;

    /* '<S95>:1:120' */
    rtb_Gain15 = 0.0;
  }

  /* Switch: '<S1>/Switch8' */
  /* '<S95>:1:81' */
  if (rtb_ACC_mode) {
    /* Product: '<S21>/Product2' */
    rtb_Product2_g = rtb_Switch14;
  } else {
    /* Product: '<S21>/Product2' */
    rtb_Product2_g = A1_Test_B.RR;
  }

  /* End of Switch: '<S1>/Switch8' */

  /* S-Function (raptor_sfun_can_txmsg): '<S1>/raptor_can_txmsg3' */

  /* S-Function Block:<S1>/raptor_can_txmsg3 */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: RR        */
    /* RR        - StartBit: 56U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Product2_g < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Product2_g > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Product2_g < 0)
        tempS = (int32_T)(int32_T)((rtb_Product2_g) * 100.0f);
      else
        tempS = (int32_T)((rtb_Product2_g) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[7U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[6U] |= temp_shift;

    /* Signal: RR_Desire */
    /* RR_Desire - StartBit: 40U, BitLength: 16U, Endian: 1U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_Switch14 < -327.68)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_Switch14 > 327.67)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_Switch14 < 0)
        tempS = (int32_T)(int32_T)((rtb_Switch14) * 100.0f);
      else
        tempS = (int32_T)((rtb_Switch14) * 100.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[5U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[4U] |= temp_shift;
    can_set_period_3571__0001(0U);
    can_send_3571__0001(784U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement' */
  TTC_Data() = rtb_Add13;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement1' */
  RR_new_Data() = rtb_Add17;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement10' */
  Jx_HV_mps3_Data() = rtb_Gain_g;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement11' */
  TH_Data() = A1_Test_B.Limit_ns.MinMax10;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement13' */
  Acc_Mode_Data() = rtb_ACC_mode;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement14' */
  Driving_Torque_Data() = rtb_UnitDelay_j;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement15' */
  Braking_Pressure_RR_Data() = rtb_UnitDelay_g;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement19' */
  VACCTargetVehAssigned_flg_Data() = rtb_VACCTargetVehAssigned_flg;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement2' */
  RR_est_Data() = A1_Test_B.X2[0];

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement3' */
  RV_est_Data() = A1_Test_B.OutportBufferForv_rel;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement4' */
  RA_est_Data() = A1_Test_B.OutportBufferFora_rel;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement5' */
  cut_in_flg_Data() = A1_Test_B.trig;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement6' */
  RAx_Data() = A1_Test_B.RA;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement7' */
  RVx_Data() = A1_Test_B.RV;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement8' */
  RR_Data() = A1_Test_B.RR;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement9' */
  Jy_HV_mps3_Data() = rtb_Max3;

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw2' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw2 */
  can_get_3562__0001(&rtb_raptor_can_rxraw2_o1, &rtb_raptor_can_rxraw2_o3,
                     &rtb_raptor_can_rxraw2_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack2' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack2 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: Steer_ang     */

      /* Signal: Steer_ang   */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Gain_g = (((real_T) ((int32_T) temp) / (real_T) 10.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Yaw_HV_deg    */

      /* Signal: Yaw_HV_deg  */
      temp = 0;
      temp |= (((uint32_T)data[5U]) & 255)
        ;
      temp |= (((uint32_T)data[4U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Yaw_HV_deg = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Yaw_rate_HV   */

      /* Signal: Yaw_rate_HV */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Max3 = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }
  }

  /* MultiPortSwitch: '<S22>/Multiport Switch6' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  S-Function (raptor_sfun_adjustment): '<S22>/raptor_adjustment'
   */
  switch ((int32_T)(Path_selector_Data())) {
   case 1:
    memcpy(&A1_Test_B.MultiportSwitch6[0], &A1_Test_ConstP.Constant_Value[0],
           3000U * sizeof(real_T));
    break;

   case 2:
    memcpy(&A1_Test_B.MultiportSwitch6[0], &A1_Test_ConstP.Constant1_Value[0],
           3000U * sizeof(real_T));
    break;

   default:
    memcpy(&A1_Test_B.MultiportSwitch6[0], &A1_Test_ConstP.Constant2_Value[0],
           3000U * sizeof(real_T));
    break;
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch6' */

  /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
   *  Constant: '<S22>/Constant3'
   *  Constant: '<S22>/Constant7'
   *  Constant: '<S22>/Constant8'
   *  S-Function (raptor_sfun_adjustment): '<S22>/raptor_adjustment'
   */
  switch ((int32_T)(Path_selector_Data())) {
   case 1:
    rtb_MultiportSwitch1_g_0 = &A1_Test_ConstP.Constant3_Value[0];
    break;

   case 2:
    rtb_MultiportSwitch1_g_0 = &A1_Test_ConstP.Constant7_Value[0];
    break;

   default:
    rtb_MultiportSwitch1_g_0 = &A1_Test_ConstP.Constant8_Value[0];
    break;
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch1' */

  /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
   *  Constant: '<S22>/Constant4'
   *  Constant: '<S22>/Constant5'
   *  Constant: '<S22>/Constant6'
   *  S-Function (raptor_sfun_adjustment): '<S22>/raptor_adjustment'
   */
  switch ((int32_T)(Path_selector_Data())) {
   case 1:
    memcpy(&A1_Test_B.MultiportSwitch2_j[0], &A1_Test_ConstP.Constant4_Value[0],
           3000U * sizeof(real_T));
    break;

   case 2:
    memcpy(&A1_Test_B.MultiportSwitch2_j[0], &A1_Test_ConstP.Constant5_Value[0],
           3000U * sizeof(real_T));
    break;

   default:
    memcpy(&A1_Test_B.MultiportSwitch2_j[0], &A1_Test_ConstP.Constant6_Value[0],
           3000U * sizeof(real_T));
    break;
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch2' */

  /* MATLAB Function: '<S19>/Camera_NEW' incorporates:
   *  Constant: '<S19>/Constant4'
   */
  /* MATLAB Function 'Foreground/Camera/Subsystem6/Camera_NEW': '<S20>:1' */
  /* '<S20>:1:21' */
  /* '<S20>:1:8' */
  rtb_Add17 = rtb_Yaw_HV_deg * 3.1415926535897931 / 180.0;

  /* '<S20>:1:13' */
  rtb_Switch15 = cos(rtb_Add17);
  rtb_Add9 = sin(rtb_Add17);
  for (i = 0; i < 3000; i++) {
    A1_Test_B.MultiportSwitch6[i] -= rtb_Global_X;
    A1_Test_B.MultiportSwitch2_j[i] -= rtb_Global_Y;
  }

  /* '<S20>:1:14' */
  /* '<S20>:1:20' */
  rtb_Add17 = 0.1 * rtb_Gain29;

  /* '<S20>:1:21' */
  for (i = 0; i < 24; i++) {
    s[i] = (real_T)i * rtb_Add17 + rtb_Station;
  }

  /* '<S20>:1:26' */
  for (i = 0; i < 3000; i++) {
    A1_Test_B.rtb_Switch15_m[i] = rtb_Switch15 * A1_Test_B.MultiportSwitch6[i] +
      rtb_Add9 * A1_Test_B.MultiportSwitch2_j[i];
  }

  A1_Test_interp1(rtb_MultiportSwitch1_g_0, A1_Test_B.rtb_Switch15_m, s,
                  x_ref_12);

  /* '<S20>:1:27' */
  for (i = 0; i < 3000; i++) {
    A1_Test_B.rtb_Switch15_m[i] = -rtb_Add9 * A1_Test_B.MultiportSwitch6[i] +
      rtb_Switch15 * A1_Test_B.MultiportSwitch2_j[i];
  }

  A1_Test_interp1(rtb_MultiportSwitch1_g_0, A1_Test_B.rtb_Switch15_m, s,
                  y_ref_12);

  /* '<S20>:1:28' */
  /* '<S20>:1:29' */
  /* '<S20>:1:34' */
  /* '<S20>:1:1' */
  /* '<S20>:1:35' */
  /* '<S20>:1:45' */
  rtb_RelationalOperator_i = true;
  b_a_tmp = 1;
  exitg1 = false;
  while ((!exitg1) && (b_a_tmp - 1 < 22)) {
    if (!(y_ref_12[b_a_tmp] >= 1.5)) {
      rtb_RelationalOperator_i = false;
      exitg1 = true;
    } else {
      b_a_tmp++;
    }
  }

  if (rtb_RelationalOperator_i) {
    /* '<S20>:1:56' */
    for (i = 0; i < 22; i++) {
      y[i] = y_ref_12[i + 1] - 3.66;
    }
  } else {
    rtb_RelationalOperator_i = true;
    b_a_tmp = 1;
    exitg1 = false;
    while ((!exitg1) && (b_a_tmp - 1 < 22)) {
      if (!(y_ref_12[b_a_tmp] <= -1.5)) {
        rtb_RelationalOperator_i = false;
        exitg1 = true;
      } else {
        b_a_tmp++;
      }
    }

    if (rtb_RelationalOperator_i) {
      /* '<S20>:1:58' */
      for (i = 0; i < 22; i++) {
        y[i] = y_ref_12[i + 1] + 3.66;
      }
    } else {
      /* '<S20>:1:60' */
      memcpy(&y[0], &y_ref_12[1], 22U * sizeof(real_T));
    }
  }

  /* '<S20>:1:64' */
  rtb_Add17 = x_ref_12[1];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    rtb_Add17 += x_ref_12[b_a_tmp + 2];
  }

  /* '<S20>:1:65' */
  for (b_a_tmp = 0; b_a_tmp < 22; b_a_tmp++) {
    rtb_Switch15 = x_ref_12[b_a_tmp + 1];
    a[b_a_tmp] = rtb_Switch15 * rtb_Switch15;
  }

  rtb_Switch15 = a[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    rtb_Switch15 += a[b_a_tmp + 1];
  }

  /* '<S20>:1:66' */
  for (b_a_tmp = 0; b_a_tmp < 22; b_a_tmp++) {
    a[b_a_tmp] = rt_powd_snf(x_ref_12[b_a_tmp + 1], 3.0);
  }

  rtb_Add9 = a[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    rtb_Add9 += a[b_a_tmp + 1];
  }

  /* '<S20>:1:67' */
  for (b_a_tmp = 0; b_a_tmp < 22; b_a_tmp++) {
    a[b_a_tmp] = rt_powd_snf(x_ref_12[b_a_tmp + 1], 4.0);
  }

  rtb_Add8 = a[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    rtb_Add8 += a[b_a_tmp + 1];
  }

  /* '<S20>:1:68' */
  for (b_a_tmp = 0; b_a_tmp < 22; b_a_tmp++) {
    a[b_a_tmp] = rt_powd_snf(x_ref_12[b_a_tmp + 1], 5.0);
  }

  rtb_Add1 = a[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    rtb_Add1 += a[b_a_tmp + 1];
  }

  /* '<S20>:1:69' */
  for (b_a_tmp = 0; b_a_tmp < 22; b_a_tmp++) {
    a[b_a_tmp] = rt_powd_snf(x_ref_12[b_a_tmp + 1], 6.0);
  }

  rtb_Add_bp = a[0];

  /* '<S20>:1:70' */
  sum_y = y[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    rtb_Add_bp += a[b_a_tmp + 1];
    sum_y += y[b_a_tmp + 1];
  }

  /* '<S20>:1:88' */
  /* '<S20>:1:93' */
  for (i = 0; i < 22; i++) {
    a[i] = x_ref_12[i + 1] * y[i];
  }

  d_y = a[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    d_y += a[b_a_tmp + 1];
  }

  for (i = 0; i < 22; i++) {
    x_tmp_tmp = x_ref_12[i + 1];
    x_tmp_tmp *= x_tmp_tmp;
    a[i] = x_tmp_tmp * y[i];
    x_tmp[i] = x_tmp_tmp;
  }

  x_tmp_tmp = a[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    x_tmp_tmp += a[b_a_tmp + 1];
  }

  for (i = 0; i < 22; i++) {
    x_tmp[i] = x_ref_12[i + 1] * x_tmp[i] * y[i];
  }

  f_y = x_tmp[0];
  for (b_a_tmp = 0; b_a_tmp < 21; b_a_tmp++) {
    f_y += x_tmp[b_a_tmp + 1];
  }

  if (rtb_Gain29 <= 0.1) {
    /* '<S20>:1:105' */
    /* '<S20>:1:106' */
    rtb_C[0] = 0.0;
    rtb_C[1] = 0.0;
    rtb_C[2] = 0.0;
    rtb_C[3] = 0.0;
  } else {
    /* '<S20>:1:108' */
    tmp[0] = 22.0;
    tmp[4] = rtb_Add17;
    tmp[8] = rtb_Switch15;
    tmp[12] = rtb_Add9;
    tmp[1] = rtb_Add17;
    tmp[5] = rtb_Switch15;
    tmp[9] = rtb_Add9;
    tmp[13] = rtb_Add8;
    tmp[2] = rtb_Switch15;
    tmp[6] = rtb_Add9;
    tmp[10] = rtb_Add8;
    tmp[14] = rtb_Add1;
    tmp[3] = rtb_Add9;
    tmp[7] = rtb_Add8;
    tmp[11] = rtb_Add1;
    tmp[15] = rtb_Add_bp;
    A1_Test_inv(tmp, tmp_0);
    for (i = 0; i < 4; i++) {
      rtb_C[i] = ((tmp_0[i + 4] * d_y + tmp_0[i] * sum_y) + tmp_0[i + 8] *
                  x_tmp_tmp) + tmp_0[i + 12] * f_y;
    }
  }

  /* End of MATLAB Function: '<S19>/Camera_NEW' */

  /* S-Function (raptor_sfun_measurement): '<S19>/raptor_measurement' */
  C0_Data() = rtb_C[0];

  /* Gain: '<S21>/Gain' */
  rtb_Add17 = 0.5 * rtb_Gain7;
  for (i = 0; i < 10; i++) {
    /* Product: '<S21>/Product11' incorporates:
     *  Constant: '<S21>/Constant10'
     *  Constant: '<S21>/Constant11'
     *  Math: '<S21>/Square1'
     *  Product: '<S21>/Product10'
     *  Product: '<S21>/Product12'
     *  Sum: '<S21>/Add5'
     */
    rtb_Switch15 = A1_Test_ConstP.Constant10_Value[i] * 0.1;
    Yref_TH[i] = rtb_Switch15 * rtb_Switch15 * rtb_Add17 + rtb_Gain29 *
      rtb_Switch15;
  }

  /* Product: '<S21>/Product2' incorporates:
   *  Fcn: '<S21>/Fcn'
   */
  rtb_Product2_g = rt_powd_snf(Yref_TH[0], 3.0);
  rtb_Product2_g *= rtb_C[3];

  /* Sum: '<S21>/Add30' */
  rtb_Add17 = rtb_C[0];

  /* Product: '<S21>/Product' */
  rtb_Add_bp = rtb_C[1];

  /* Product: '<S21>/Product1' */
  rtb_Add1 = rtb_C[2];

  /* Sum: '<S21>/Add30' incorporates:
   *  Math: '<S21>/Square'
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   */
  for (i = 0; i < 10; i++) {
    rtb_Switch15 = Yref_TH[i];
    Yref_TH[i] = ((rtb_Add_bp * rtb_Switch15 + rtb_Add17) + rtb_Switch15 *
                  rtb_Switch15 * rtb_Add1) + rtb_Product2_g;
  }

  /* Gain: '<S1>/Gain2' */
  rtb_Add9 = 0.27777777777777779 * rtb_Max;

  /* MinMax: '<S102>/Max' incorporates:
   *  Gain: '<S8>/Gain31'
   *  S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment6'
   */
  rtb_Max = 3.6 * (V_Data());

  /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
   *  Constant: '<S8>/Constant32'
   */
  rtb_RelationalOperator_i = (rtb_Max <= 30.0);

  /* Logic: '<S29>/Logical Operator4' */
  rtb_LogicalOperator4 = !rtb_RelationalOperator_i;

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S8>/Constant30'
   *  Delay: '<S29>/Delay'
   *  Logic: '<S29>/Logical Operator3'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Switch: '<S29>/Switch1'
   */
  if ((rtb_Max >= 35.0) && rtb_LogicalOperator4) {
    rtb_Add17 = 1.0;
  } else if (rtb_RelationalOperator_i) {
    /* Switch: '<S29>/Switch1' */
    rtb_Add17 = rtb_LogicalOperator4;
  } else {
    rtb_Add17 = A1_Test_DWork.Delay_DSTATE;
  }

  /* End of Switch: '<S29>/Switch' */

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment5' */
  rtb_raptor_adjustment5_d = (Lat_trig_Data());

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment' */
  rtb_raptor_adjustment_g = (Q_D_Data());

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment1' */
  rtb_raptor_adjustment1_j = (R_D_Data());

  /* Gain: '<S8>/Gain4' incorporates:
   *  Gain: '<S8>/Gain6'
   */
  rtb_Switch15 = 0.05 * rtb_Gain_g * 0.017453292519943295;

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment4' */
  rtb_raptor_adjustment4_i = (Q_K_Data());

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment5' */
  rtb_raptor_adjustment5 = (R_K_Data());

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant5'
   *  Gain: '<S1>/Gain16'
   */
  rtb_Add8 = rtb_Gain29;

  /* MATLAB Function 'Foreground/MPC_Dynematc1/MATLAB Function': '<S31>:1' */
  /* '<S31>:1:70' */
  /* '<S31>:1:75' */
  /* '<S31>:1:91' */
  /* '<S31>:1:106' */
  /* '<S31>:1:127' */
  /* '<S31>:1:132' */
  /* '<S31>:1:7' */
  /* '<S31>:1:8' */
  /* '<S31>:1:9' */
  /* '<S31>:1:10' */
  /* '<S31>:1:11' */
  /* '<S31>:1:12' */
  /* '<S31>:1:13' */
  if (rtb_raptor_adjustment5_d && (rtb_Add17 == 1.0)) {
    /* '<S31>:1:20' */
    /* '<S31>:1:23' */
    if (rtb_Gain29 < 10.0) {
      /* '<S31>:1:25' */
      /* '<S31>:1:26' */
      rtb_Add8 = 10.0;
    }

    /* '<S31>:1:46' */
    /* '<S31>:1:47' */
    for (b_a_tmp = 0; b_a_tmp < 3; b_a_tmp++) {
      /* '<S31>:1:47' */
      /* '<S31>:1:48' */
      Am_D[25 * b_a_tmp] = 1.0;
      Am_D[25 * b_a_tmp + 5] = 0.1;
      Am_D[25 * b_a_tmp + 10] = rtb_Add8 * 0.1;
      Am_D[25 * b_a_tmp + 15] = 0.0;
      Am_D[25 * b_a_tmp + 20] = 0.0;
      Am_D[25 * b_a_tmp + 1] = 0.0;
      Am_D[25 * b_a_tmp + 6] = -16052.0 / (1501.0 * rtb_Add8) + 1.0;
      Am_D[25 * b_a_tmp + 11] = 0.0;
      Am_D[25 * b_a_tmp + 16] = 7129.8099999999995 / (1501.0 * rtb_Add8) -
        rtb_Add8 * 0.1;
      Am_D[25 * b_a_tmp + 21] = 5.3317788141239175;
      for (i = 0; i < 5; i++) {
        Am_D[(5 * i + 25 * b_a_tmp) + 2] = c_0[i];
      }

      Am_D[25 * b_a_tmp + 3] = 0.0;
      Am_D[25 * b_a_tmp + 8] = 7129.8099999999995 / (1536.7 * rtb_Add8);
      Am_D[25 * b_a_tmp + 13] = 0.0;
      Am_D[25 * b_a_tmp + 18] = -37149.050899999995 / (1536.7 * rtb_Add8) + 1.0;
      Am_D[25 * b_a_tmp + 23] = 5.2860317563610328;
      Am_D[25 * b_a_tmp + 4] = 0.0;
      Am_D[25 * b_a_tmp + 9] = 0.0;
      Am_D[25 * b_a_tmp + 14] = 0.0;
      Am_D[25 * b_a_tmp + 19] = 0.0;
      Am_D[25 * b_a_tmp + 24] = 0.66666666666666663;
    }

    /* '<S31>:1:67' */
    for (i = 0; i < 75; i++) {
      Amm_D[i] = 0.0;
    }

    /* '<S31>:1:68' */
    for (i = 0; i < 5; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 5; Amm_K_tmp++) {
        Amm_D[Amm_K_tmp + 5 * i] = Am_D[5 * i + Amm_K_tmp];
      }
    }

    /* '<S31>:1:69' */
    for (b_a_tmp = 0; b_a_tmp < 2; b_a_tmp++) {
      /* '<S31>:1:69' */
      /* '<S31>:1:70' */
      for (i = 0; i < 5; i++) {
        for (Amm_K_tmp = 0; Amm_K_tmp < 5; Amm_K_tmp++) {
          F_tmp = 5 * Amm_K_tmp + i;
          Am_D_0[F_tmp] = 0.0;
          for (P_tmp = 0; P_tmp < 5; P_tmp++) {
            Am_D_0[F_tmp] += Am_D[(5 * P_tmp + i) + (b_a_tmp + 1) * 25] * Amm_D
              [(5 * Amm_K_tmp + P_tmp) + 25 * b_a_tmp];
          }
        }
      }

      for (i = 0; i < 5; i++) {
        for (Amm_K_tmp = 0; Amm_K_tmp < 5; Amm_K_tmp++) {
          P_tmp = 5 * i + Amm_K_tmp;
          Amm_D[P_tmp + 25 * (b_a_tmp + 1)] = Am_D_0[P_tmp];
        }
      }
    }

    /* '<S31>:1:73' */
    /* '<S31>:1:74' */
    for (b_a_tmp = 0; b_a_tmp < 3; b_a_tmp++) {
      /* '<S31>:1:74' */
      /* '<S31>:1:75' */
      for (i = 0; i < 5; i++) {
        P_tmp = 3 * i + b_a_tmp;
        F_D[P_tmp] = 0.0;
        for (Amm_K_tmp = 0; Amm_K_tmp < 5; Amm_K_tmp++) {
          F_D[P_tmp] += Amm_D[(5 * i + Amm_K_tmp) + 25 * b_a_tmp] * (real_T)
            a_1[Amm_K_tmp];
        }
      }
    }

    /* '<S31>:1:78' */
    for (i = 0; i < 9; i++) {
      P[i] = 0.0;
    }

    /* '<S31>:1:79' */
    tmp_1[0] = 0.0;
    tmp_1[1] = 0.0;
    tmp_1[2] = 0.0;
    tmp_1[3] = 0.0;
    tmp_1[4] = 0.33333333333333337;

    /* '<S31>:1:80' */
    for (i = 0; i < 3; i++) {
      rtb_X1[i] = 0.0;
      for (Amm_K_tmp = 0; Amm_K_tmp < 5; Amm_K_tmp++) {
        rtb_X1[i] += F_D[3 * Amm_K_tmp + i] * tmp_1[Amm_K_tmp];
      }

      P[i] = rtb_X1[i];
    }

    /* '<S31>:1:82' */
    rtb_Add8 = 0.0;

    /* '<S31>:1:83' */
    /* '<S31>:1:84' */
    for (i = 0; i < 2; i++) {
      /* '<S31>:1:84' */
      /* '<S31>:1:85' */
      rtb_Add8++;

      /* '<S31>:1:86' */
      P[i + 4] = rtb_X1[(int32_T)rtb_Add8 - 1];
    }

    /* '<S31>:1:88' */
    /* '<S31>:1:83' */
    /* '<S31>:1:84' */
    /* '<S31>:1:85' */
    /* '<S31>:1:86' */
    P[8] = rtb_X1[0];

    /* '<S31>:1:88' */
    /* '<S31>:1:91' */
    for (i = 0; i < 9; i++) {
      Amm_K_tmp = f_b[i];
      K_K[i] = rtb_raptor_adjustment_g * (real_T)Amm_K_tmp;
      Q_K_tmp[i] = (int8_T)Amm_K_tmp;
    }

    /* '<S31>:1:92' */
    /* '<S31>:1:95' */
    /* '<S31>:1:96' */
    for (i = 0; i < 3; i++) {
      rtb_u_tmp[3 * i] = P[i];
      rtb_u_tmp[3 * i + 1] = P[i + 3];
      rtb_u_tmp[3 * i + 2] = P[i + 6];
    }

    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        b_a[b_a_tmp] = 0.0;
        b_a[b_a_tmp] += K_K[3 * Amm_K_tmp] * rtb_u_tmp[i];
        b_a[b_a_tmp] += K_K[3 * Amm_K_tmp + 1] * rtb_u_tmp[i + 3];
        b_a[b_a_tmp] += K_K[3 * Amm_K_tmp + 2] * rtb_u_tmp[i + 6];
      }

      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        rtb_u_tmp_0[b_a_tmp] = ((P[3 * Amm_K_tmp + 1] * b_a[i + 3] + P[3 *
          Amm_K_tmp] * b_a[i]) + P[3 * Amm_K_tmp + 2] * b_a[i + 6]) + (real_T)
          Q_K_tmp[b_a_tmp] * rtb_raptor_adjustment1_j;
      }
    }

    A1_Test_inv_n(rtb_u_tmp_0, b_a);
    tmp_1[0] = 0.0;
    tmp_1[1] = rtb_Add9;
    tmp_1[2] = 0.0;
    tmp_1[3] = 0.017453292519943295 * rtb_Max3;
    tmp_1[4] = rtb_Switch15;
    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        P_tmp = 3 * Amm_K_tmp + i;
        rtb_u_tmp_0[P_tmp] = 0.0;
        rtb_u_tmp_0[P_tmp] += rtb_u_tmp[3 * Amm_K_tmp] * b_a[i];
        rtb_u_tmp_0[P_tmp] += rtb_u_tmp[3 * Amm_K_tmp + 1] * b_a[i + 3];
        rtb_u_tmp_0[P_tmp] += rtb_u_tmp[3 * Amm_K_tmp + 2] * b_a[i + 6];
      }

      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        P_tmp = 3 * Amm_K_tmp + i;
        tmp_2[P_tmp] = 0.0;
        tmp_2[P_tmp] += K_K[3 * Amm_K_tmp] * rtb_u_tmp_0[i];
        tmp_2[P_tmp] += K_K[3 * Amm_K_tmp + 1] * rtb_u_tmp_0[i + 3];
        tmp_2[P_tmp] += K_K[3 * Amm_K_tmp + 2] * rtb_u_tmp_0[i + 6];
      }

      sum_y = 0.0;
      for (Amm_K_tmp = 0; Amm_K_tmp < 5; Amm_K_tmp++) {
        sum_y += F_D[3 * Amm_K_tmp + i] * tmp_1[Amm_K_tmp];
      }

      rtb_X1[i] = Yref_TH[i] - sum_y;
    }

    for (i = 0; i < 3; i++) {
      P_0[i] = (tmp_2[i + 3] * rtb_X1[1] + tmp_2[i] * rtb_X1[0]) + tmp_2[i + 6] *
        rtb_X1[2];
    }

    rtb_Switch15 = P_0[0];
  } else if (rtb_raptor_adjustment5_d && (rtb_Add17 == 0.0)) {
    /* '<S31>:1:98' */
    /* '<S31>:1:101' */
    /* '<S31>:1:106' */
    /* '<S31>:1:117' */
    /* '<S31>:1:118' */
    /* '<S31>:1:119' */
    Am_K[0] = 1.0;
    Am_K[3] = rtb_Gain29 * 0.1;
    Am_K[6] = rtb_Gain29 * 0.1;
    Am_K[1] = 0.0;
    Am_K[4] = 1.0;
    rtb_Add_bp = rtb_Gain29 / 2.65 * 0.1;
    Am_K[7] = rtb_Add_bp;
    Am_K[2] = 0.0;
    Am_K[5] = 0.0;
    Am_K[8] = 0.66666666666666663;

    /* '<S31>:1:118' */
    /* '<S31>:1:119' */
    Am_K[9] = 1.0;
    Am_K[12] = rtb_Gain29 * 0.1;
    Am_K[15] = rtb_Gain29 * 0.1;
    Am_K[10] = 0.0;
    Am_K[13] = 1.0;
    Am_K[16] = rtb_Add_bp;
    Am_K[11] = 0.0;
    Am_K[14] = 0.0;
    Am_K[17] = 0.66666666666666663;

    /* '<S31>:1:118' */
    /* '<S31>:1:119' */
    Am_K[18] = 1.0;
    Am_K[21] = rtb_Gain29 * 0.1;
    Am_K[24] = rtb_Gain29 * 0.1;
    Am_K[19] = 0.0;
    Am_K[22] = 1.0;
    Am_K[25] = rtb_Add_bp;
    Am_K[20] = 0.0;
    Am_K[23] = 0.0;
    Am_K[26] = 0.66666666666666663;

    /* '<S31>:1:124' */
    for (i = 0; i < 27; i++) {
      Amm_K[i] = 0.0;
    }

    /* '<S31>:1:125' */
    for (i = 0; i < 3; i++) {
      Amm_K[3 * i] = Am_K[3 * i];
      Amm_K_tmp = 3 * i + 1;
      Amm_K[Amm_K_tmp] = Am_K[Amm_K_tmp];
      Amm_K_tmp = 3 * i + 2;
      Amm_K[Amm_K_tmp] = Am_K[Amm_K_tmp];
    }

    /* '<S31>:1:126' */
    for (b_a_tmp = 0; b_a_tmp < 2; b_a_tmp++) {
      /* '<S31>:1:126' */
      /* '<S31>:1:127' */
      for (i = 0; i < 3; i++) {
        for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
          P_tmp = 3 * Amm_K_tmp + i;
          P[P_tmp] = 0.0;
          F_tmp = (b_a_tmp + 1) * 9 + i;
          Am_K_tmp = 3 * Amm_K_tmp + 9 * b_a_tmp;
          P[P_tmp] += Am_K[F_tmp] * Amm_K[Am_K_tmp];
          P[P_tmp] += Am_K[F_tmp + 3] * Amm_K[Am_K_tmp + 1];
          P[P_tmp] += Am_K[F_tmp + 6] * Amm_K[Am_K_tmp + 2];
        }
      }

      for (i = 0; i < 3; i++) {
        Amm_K_tmp = (b_a_tmp + 1) * 9 + 3 * i;
        Amm_K[Amm_K_tmp] = P[3 * i];
        Amm_K[Amm_K_tmp + 1] = P[3 * i + 1];
        Amm_K[Amm_K_tmp + 2] = P[3 * i + 2];
      }
    }

    /* '<S31>:1:130' */
    /* '<S31>:1:131' */
    for (b_a_tmp = 0; b_a_tmp < 3; b_a_tmp++) {
      /* '<S31>:1:131' */
      /* '<S31>:1:132' */
      for (i = 0; i < 3; i++) {
        P_tmp = 3 * i + b_a_tmp;
        P[P_tmp] = 0.0;
        Amm_K_tmp = 3 * i + 9 * b_a_tmp;
        P[P_tmp] += Amm_K[Amm_K_tmp];
        P[P_tmp] += Amm_K[Amm_K_tmp + 1] * 0.0;
        P[P_tmp] += Amm_K[Amm_K_tmp + 2] * 0.0;
      }
    }

    /* '<S31>:1:135' */
    for (i = 0; i < 9; i++) {
      K_K[i] = 0.0;
    }

    /* '<S31>:1:136' */
    /* '<S31>:1:137' */
    for (i = 0; i < 3; i++) {
      rtb_Add_bp = (P[i + 3] * 0.0 + P[i] * 0.0) + P[i + 6] *
        0.33333333333333337;
      K_K[i] = rtb_Add_bp;
      rtb_X1[i] = rtb_Add_bp;
    }

    /* '<S31>:1:139' */
    rtb_Add9 = 0.0;

    /* '<S31>:1:140' */
    /* '<S31>:1:141' */
    for (i = 0; i < 2; i++) {
      /* '<S31>:1:141' */
      /* '<S31>:1:142' */
      rtb_Add9++;

      /* '<S31>:1:143' */
      K_K[i + 4] = rtb_X1[(int32_T)rtb_Add9 - 1];
    }

    /* '<S31>:1:145' */
    /* '<S31>:1:140' */
    /* '<S31>:1:141' */
    /* '<S31>:1:142' */
    /* '<S31>:1:143' */
    K_K[8] = rtb_X1[0];

    /* '<S31>:1:145' */
    /* '<S31>:1:148' */
    for (i = 0; i < 9; i++) {
      Amm_K_tmp = f_b[i];
      Q_K[i] = rtb_raptor_adjustment4_i * (real_T)Amm_K_tmp;
      Q_K_tmp[i] = (int8_T)Amm_K_tmp;
    }

    /* '<S31>:1:149' */
    /* '<S31>:1:152' */
    /* '<S31>:1:153' */
    for (i = 0; i < 3; i++) {
      rtb_u_tmp[3 * i] = K_K[i];
      rtb_u_tmp[3 * i + 1] = K_K[i + 3];
      rtb_u_tmp[3 * i + 2] = K_K[i + 6];
    }

    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        b_a[b_a_tmp] = 0.0;
        b_a[b_a_tmp] += Q_K[3 * Amm_K_tmp] * rtb_u_tmp[i];
        b_a[b_a_tmp] += Q_K[3 * Amm_K_tmp + 1] * rtb_u_tmp[i + 3];
        b_a[b_a_tmp] += Q_K[3 * Amm_K_tmp + 2] * rtb_u_tmp[i + 6];
      }

      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        b_a_tmp = 3 * Amm_K_tmp + i;
        rtb_u_tmp_0[b_a_tmp] = ((K_K[3 * Amm_K_tmp + 1] * b_a[i + 3] + K_K[3 *
          Amm_K_tmp] * b_a[i]) + K_K[3 * Amm_K_tmp + 2] * b_a[i + 6]) + (real_T)
          Q_K_tmp[b_a_tmp] * rtb_raptor_adjustment5;
      }
    }

    A1_Test_inv_n(rtb_u_tmp_0, b_a);
    P_0[0] = 0.0;
    P_0[1] = 0.0;
    P_0[2] = rtb_Switch15;
    for (i = 0; i < 3; i++) {
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        P_tmp = 3 * Amm_K_tmp + i;
        rtb_u_tmp_0[P_tmp] = 0.0;
        rtb_u_tmp_0[P_tmp] += rtb_u_tmp[3 * Amm_K_tmp] * b_a[i];
        rtb_u_tmp_0[P_tmp] += rtb_u_tmp[3 * Amm_K_tmp + 1] * b_a[i + 3];
        rtb_u_tmp_0[P_tmp] += rtb_u_tmp[3 * Amm_K_tmp + 2] * b_a[i + 6];
      }

      sum_y = 0.0;
      for (Amm_K_tmp = 0; Amm_K_tmp < 3; Amm_K_tmp++) {
        P_tmp = 3 * Amm_K_tmp + i;
        tmp_2[P_tmp] = 0.0;
        tmp_2[P_tmp] += Q_K[3 * Amm_K_tmp] * rtb_u_tmp_0[i];
        tmp_2[P_tmp] += Q_K[3 * Amm_K_tmp + 1] * rtb_u_tmp_0[i + 3];
        tmp_2[P_tmp] += Q_K[3 * Amm_K_tmp + 2] * rtb_u_tmp_0[i + 6];
        sum_y += P[P_tmp] * P_0[Amm_K_tmp];
      }

      rtb_X1[i] = Yref_TH[i] - sum_y;
    }

    for (i = 0; i < 3; i++) {
      P_0[i] = (tmp_2[i + 3] * rtb_X1[1] + tmp_2[i] * rtb_X1[0]) + tmp_2[i + 6] *
        rtb_X1[2];
    }

    rtb_Switch15 = P_0[0];
  } else {
    /* '<S31>:1:157' */
    rtb_Switch15 = 0.0;
  }

  /* End of MATLAB Function: '<S8>/MATLAB Function' */

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement1' */
  SW_Dynematic_Data() = rtb_Switch15;

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement2' */
  latched_Data() = rtb_Add17;

  /* Outputs for Atomic SubSystem: '<S8>/Limit' */
  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Gain: '<S32>/Gain'
   */
  limit_lib(20.0 * (57.295779513082323 * rtb_Switch15), 720.0, -720.0,
            &A1_Test_B.Limit_b);

  /* End of Outputs for SubSystem: '<S8>/Limit' */

  /* Gain: '<S37>/Gain' incorporates:
   *  Constant: '<S97>/Constant'
   *  Constant: '<S97>/Constant1'
   *  Product: '<S100>/Product1'
   */
  rtb_Gain_g = 0.25;

  /* MinMax: '<S100>/Max2' */
  if (!(rtb_Gain_g >= 0.0)) {
    /* Gain: '<S37>/Gain' */
    rtb_Gain_g = 0.0;
  }

  /* End of MinMax: '<S100>/Max2' */

  /* Outputs for Atomic SubSystem: '<S97>/Limit' */
  /* Constant: '<S97>/Constant3' incorporates:
   *  Constant: '<S97>/Constant4'
   */
  limit_lib(rtb_Gain15, 2.0, -2.0, &A1_Test_B.Limit_n);

  /* End of Outputs for SubSystem: '<S97>/Limit' */

  /* MinMax: '<S102>/Max' incorporates:
   *  Sum: '<S100>/Add'
   *  UnitDelay: '<S100>/Unit Delay'
   */
  rtb_Max = A1_Test_B.Limit_n.MinMax10 - A1_Test_DWork.UnitDelay_DSTATE_o;

  /* MinMax: '<S102>/Max3' incorporates:
   *  Constant: '<S97>/Constant'
   *  Constant: '<S97>/Constant2'
   *  Product: '<S100>/Product'
   */
  rtb_Max3 = -0.25;

  /* MinMax: '<S100>/Max3' */
  if ((0.0 <= rtb_Max3) || rtIsNaN(rtb_Max3)) {
    /* MinMax: '<S102>/Max3' */
    rtb_Max3 = 0.0;
  }

  /* End of MinMax: '<S100>/Max3' */

  /* MinMax: '<S100>/Max' */
  if ((!(rtb_Max >= rtb_Max3)) && (!rtIsNaN(rtb_Max3))) {
    /* MinMax: '<S102>/Max' */
    rtb_Max = rtb_Max3;
  }

  /* End of MinMax: '<S100>/Max' */

  /* MinMax: '<S100>/Max1' */
  if ((rtb_Gain_g <= rtb_Max) || rtIsNaN(rtb_Max)) {
    sum_y = rtb_Gain_g;
  } else {
    sum_y = rtb_Max;
  }

  /* End of MinMax: '<S100>/Max1' */

  /* Sum: '<S100>/Add1' incorporates:
   *  UnitDelay: '<S100>/Unit Delay'
   */
  rtb_Switch15 = sum_y + A1_Test_DWork.UnitDelay_DSTATE_o;

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Lookup_n-D: '<S39>/1-D Lookup Table'
   *  Switch: '<S13>/Switch13'
   */
  if (rtb_ACC_mode) {
    rtb_Add13 = 0.5;
  } else {
    rtb_Add13 = look1_binlxpw(rtb_Add13, A1_Test_ConstP.uDLookupTable_bp01Data,
      A1_Test_ConstP.uDLookupTable_tableData, 2U);
  }

  /* End of Switch: '<S39>/Switch' */

  /* Delay: '<S35>/Delay' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   */
  if (A1_Test_DWork.icLoad_d) {
    A1_Test_DWork.Delay_DSTATE_n = rtb_ACC_mode;
  }

  /* MATLAB Function: '<S35>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   *  Delay: '<S35>/Delay'
   */
  A1_Test_MATLABFunction11(rtb_Add13, (real_T)rtb_ACC_mode,
    A1_Test_DWork.Delay_DSTATE_n, &A1_Test_B.sf_MATLABFunction_i);

  /* Gain: '<S37>/Gain' incorporates:
   *  Constant: '<S98>/Constant'
   *  Constant: '<S98>/Constant1'
   *  Product: '<S102>/Product1'
   */
  rtb_Gain_g = 0.25;

  /* MinMax: '<S102>/Max2' */
  if (!(rtb_Gain_g >= 0.0)) {
    /* Gain: '<S37>/Gain' */
    rtb_Gain_g = 0.0;
  }

  /* End of MinMax: '<S102>/Max2' */

  /* Outputs for Atomic SubSystem: '<S98>/Limit' */
  /* Constant: '<S98>/Constant3' incorporates:
   *  Constant: '<S98>/Constant4'
   */
  limit_lib(rtb_Add14, 2.0, -2.0, &A1_Test_B.Limit_g);

  /* End of Outputs for SubSystem: '<S98>/Limit' */

  /* MinMax: '<S102>/Max' incorporates:
   *  Sum: '<S102>/Add'
   *  UnitDelay: '<S102>/Unit Delay'
   */
  rtb_Max = A1_Test_B.Limit_g.MinMax10 - A1_Test_DWork.UnitDelay_DSTATE_e;

  /* MinMax: '<S102>/Max3' incorporates:
   *  Constant: '<S98>/Constant'
   *  Constant: '<S98>/Constant2'
   *  Product: '<S102>/Product'
   */
  rtb_Max3 = -0.25;

  /* MinMax: '<S102>/Max3' */
  if ((0.0 <= rtb_Max3) || rtIsNaN(rtb_Max3)) {
    /* MinMax: '<S102>/Max3' */
    rtb_Max3 = 0.0;
  }

  /* End of MinMax: '<S102>/Max3' */

  /* MinMax: '<S102>/Max' */
  if ((!(rtb_Max >= rtb_Max3)) && (!rtIsNaN(rtb_Max3))) {
    /* MinMax: '<S102>/Max' */
    rtb_Max = rtb_Max3;
  }

  /* End of MinMax: '<S102>/Max' */

  /* MinMax: '<S102>/Max1' */
  if ((rtb_Gain_g <= rtb_Max) || rtIsNaN(rtb_Max)) {
    sum_y = rtb_Gain_g;
  } else {
    sum_y = rtb_Max;
  }

  /* End of MinMax: '<S102>/Max1' */

  /* Sum: '<S102>/Add1' incorporates:
   *  UnitDelay: '<S102>/Unit Delay'
   */
  rtb_Add13 = sum_y + A1_Test_DWork.UnitDelay_DSTATE_e;

  /* Sum: '<S35>/Add12' incorporates:
   *  Constant: '<S35>/Constant49'
   *  Product: '<S35>/Product1'
   *  Product: '<S35>/Product2'
   *  Sum: '<S35>/Add9'
   */
  rtb_Add9 = (1.0 - A1_Test_B.sf_MATLABFunction_i.y) * rtb_Add13 + rtb_Switch15 *
    A1_Test_B.sf_MATLABFunction_i.y;

  /* MATLAB Function: '<S11>/Acceleration controller2' incorporates:
   *  Constant: '<S11>/Constant14'
   */
  /* MATLAB Function 'Foreground/Subsystem10/Acceleration controller2': '<S34>:1' */
  /* '<S34>:1:4' */
  /* '<S34>:1:5' */
  /* '<S34>:1:7' */
  /* '<S34>:1:8' */
  /* '<S34>:1:9' */
  /* '<S34>:1:10' */
  /* '<S34>:1:19' */
  /* '<S34>:1:20' */
  /* '<S34>:1:21' */
  /* '<S34>:1:22' */
  /* '<S34>:1:36' */
  /* '<S34>:1:37' */
  if (rtb_Add9 >= 0.0) {
    /* '<S34>:1:39' */
    /* '<S34>:1:40' */
    rtb_Add8 = ((rtb_Gain29 * rtb_Gain29 * 0.39798 + 1501.0 * rtb_Add9) +
                55.954278) * 0.325;

    /* '<S34>:1:41' */
    rtb_Gain29 = 0.0;
  } else {
    /* '<S34>:1:43' */
    rtb_Add8 = 0.0;

    /* '<S34>:1:44' */
    rtb_Gain29 = ((1501.0 * rtb_Add9 - rtb_Gain29 * rtb_Gain29 * 0.39798) -
                  55.954278) * 0.325;
  }

  /* End of MATLAB Function: '<S11>/Acceleration controller2' */

  /* S-Function (raptor_sfun_measurement): '<S11>/raptor_measurement' */
  Driving_Torque_b_Data() = rtb_Add8;

  /* S-Function (raptor_sfun_measurement): '<S11>/raptor_measurement1' */
  axc_Data() = rtb_Add9;

  /* Outputs for Atomic SubSystem: '<S37>/Limit' */
  /* Constant: '<S37>/Constant' incorporates:
   *  Constant: '<S37>/Constant1'
   */
  limit_lib(rtb_Gain29, 0.0, -10000.0, &A1_Test_B.Limit_d);

  /* End of Outputs for SubSystem: '<S37>/Limit' */

  /* Gain: '<S37>/Gain' */
  rtb_Gain_g = -0.25 * A1_Test_B.Limit_d.MinMax10;

  /* S-Function (raptor_sfun_measurement): '<S15>/raptor_measurement' */
  TH_acc_Data() = rtb_Add14;

  /* S-Function (raptor_sfun_measurement): '<S15>/raptor_measurement1' */
  Desired_distance_Data() = rtb_Switch14;

  /* S-Function (raptor_sfun_measurement): '<S15>/raptor_measurement2' */
  Spd_acc_Data() = rtb_Gain15;

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment3' */
  rtb_raptor_adjustment3_j = (LaneAvail_flg_Data());

  /* S-Function (raptor_sfun_can_rxraw): '<S1>/raptor_can_rxraw3' */

  /* Set data to zero as this is a stack pointer */
  memset((void *) &rtb_raptor_can_rxraw3_o5[0], 0, 8);

  /* S-Function Block: <S1>/raptor_can_rxraw3 */
  can_get_3563__0001(&rtb_raptor_can_rxraw3_o1, &rtb_raptor_can_rxraw3_o3,
                     &rtb_raptor_can_rxraw3_o2, &rtb_raptor_can_rxraw3_o5[0], 8);

  /* S-Function (raptor_sfun_dbcparse_unpack): '<S1>/raptor_sfun_dbcparse_unpack3' */

  /* S-Function (raptor_sfun_dbcparse_unpack):<S1>/raptor_sfun_dbcparse_unpack3 */
  {
    uint8_T *data = (uint8_T*)&rtb_raptor_can_rxraw3_o5[0];

    {
      uint32_T temp;

      /*    Signal: Roll_rate_L1   */

      /* Signal: Roll_rate_L1 */
      temp = 0;
      temp |= (((uint32_T)data[7U]) & 255)
        ;
      temp |= (((uint32_T)data[6U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Roll_rate_L1 = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Roll_rate_L2   */

      /* Signal: Roll_rate_L2 */
      temp = 0;
      temp |= (((uint32_T)data[5U]) & 255)
        ;
      temp |= (((uint32_T)data[4U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Roll_rate_L2 = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Roll_rate_R1   */

      /* Signal: Roll_rate_R1 */
      temp = 0;
      temp |= (((uint32_T)data[3U]) & 255)
        ;
      temp |= (((uint32_T)data[2U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Roll_rate_R1 = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }

    {
      uint32_T temp;

      /*    Signal: Roll_rate_R2   */

      /* Signal: Roll_rate_R2 */
      temp = 0;
      temp |= (((uint32_T)data[1U]) & 255)
        ;
      temp |= (((uint32_T)data[0U]) & 255)
        << 8;
      if (temp & 32768)
        temp |= -65536;
      rtb_Roll_rate_R2 = (((real_T) ((int32_T) temp) / (real_T) 100.0) );
    }
  }

  /* Update for UnitDelay: '<S42>/Unit Delay' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Gain: '<S37>/Gain3'
   *  Product: '<S42>/Product'
   *  Product: '<S42>/Product1'
   *  Sum: '<S42>/Add'
   *  Sum: '<S42>/Add1'
   */
  A1_Test_DWork.UnitDelay_DSTATE = 0.0066666666666666671 * rtb_Gain_g *
    0.33333333333333337 + 0.66666666666666663 * rtb_UnitDelay_g;

  /* Update for UnitDelay: '<S41>/Unit Delay' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant1'
   *  Gain: '<S37>/Gain2'
   *  Product: '<S41>/Product'
   *  Product: '<S41>/Product1'
   *  Sum: '<S41>/Add'
   *  Sum: '<S41>/Add1'
   */
  A1_Test_DWork.UnitDelay_DSTATE_j = 0.004 * rtb_Gain_g * 0.33333333333333337 +
    0.66666666666666663 * rtb_UnitDelay_b;

  /* Update for UnitDelay: '<S36>/Unit Delay' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/Constant1'
   *  Product: '<S36>/Product'
   *  Product: '<S36>/Product1'
   *  Sum: '<S36>/Add'
   *  Sum: '<S36>/Add1'
   */
  A1_Test_DWork.UnitDelay_DSTATE_f = rtb_Add8 * 0.33333333333333337 +
    0.66666666666666663 * rtb_UnitDelay_j;

  /* Update for UnitDelay: '<S33>/Unit Delay' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant1'
   *  Product: '<S33>/Product'
   *  Product: '<S33>/Product1'
   *  Sum: '<S33>/Add'
   *  Sum: '<S33>/Add1'
   */
  A1_Test_DWork.UnitDelay_DSTATE_b = A1_Test_B.Limit_b.MinMax10 *
    0.33333333333333337 + 0.66666666666666663 * rtb_UnitDelay_f;

  /* Update for UnitDelay: '<S9>/Unit Delay' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Sum: '<S9>/Add'
   *  Sum: '<S9>/Add1'
   */
  A1_Test_DWork.UnitDelay_DSTATE_m = rtb_Gain7 * 0.33333333333333337 +
    0.66666666666666663 * A1_Test_DWork.UnitDelay_DSTATE_m;

  /* Update for UnitDelay: '<S93>/IC' incorporates:
   *  Constant: '<S93>/zero'
   */
  A1_Test_DWork.IC_DSTATE = 0.0;

  /* Update for Delay: '<S92>/Delay1' */
  A1_Test_DWork.Delay1_DSTATE = rtb_Gain46;

  /* Update for Delay: '<S14>/Delay2' */
  A1_Test_DWork.icLoad = false;
  A1_Test_DWork.Delay2_DSTATE = rtb_Gain46;

  /* Update for UnitDelay: '<S10>/Unit Delay' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Sum: '<S10>/Add'
   *  Sum: '<S10>/Add1'
   */
  A1_Test_DWork.UnitDelay_DSTATE_d = rtb_Ay * 0.33333333333333337 +
    0.66666666666666663 * A1_Test_DWork.UnitDelay_DSTATE_d;

  /* Update for Delay: '<S14>/Delay6' */
  A1_Test_DWork.icLoad_l = false;
  A1_Test_DWork.Delay6_DSTATE = rtb_Sqrt;

  /* Update for UnitDelay: '<S85>/Delay Input1' */
  A1_Test_DWork.DelayInput1_DSTATE = rtb_Switch7;

  /* Update for Delay: '<S6>/Delay10' */
  A1_Test_DWork.icLoad_m = false;
  A1_Test_DWork.Delay10_DSTATE = A1_Test_B.sf_MATLABFunction11.y;

  /* Update for Delay: '<S29>/Delay' */
  A1_Test_DWork.Delay_DSTATE = rtb_Add17;

  /* Update for UnitDelay: '<S100>/Unit Delay' */
  A1_Test_DWork.UnitDelay_DSTATE_o = rtb_Switch15;

  /* Update for Delay: '<S35>/Delay' */
  A1_Test_DWork.icLoad_d = false;
  A1_Test_DWork.Delay_DSTATE_n = A1_Test_B.sf_MATLABFunction_i.y;

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  A1_Test_DWork.UnitDelay_DSTATE_e = rtb_Add13;
}

/* Model step function */
void A1_Test_step(void)
{
  /* S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /*
   * New Eagle LLC 2011
   */
}

/* Model initialize function */
void A1_Test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    A1_Test_B.OutportBufferFora_rel = 0.0;
    A1_Test_B.OutportBufferForv_rel = 0.0;
    A1_Test_B.X2[0] = 0.0;
    A1_Test_B.X2[1] = 0.0;
    A1_Test_B.X2[2] = 0.0;
    A1_Test_B.RR = 0.0;
    A1_Test_B.RV = 0.0;
    A1_Test_B.RA = 0.0;
    A1_Test_B.trig = 0.0;
    A1_Test_B.Limit1.MinMax10 = 0.0;
    A1_Test_B.Limit_ns.MinMax10 = 0.0;
    A1_Test_B.Limit_g.MinMax10 = 0.0;
    A1_Test_B.Limit_n.MinMax10 = 0.0;
    A1_Test_B.Limit_f.MinMax10 = 0.0;
    A1_Test_B.Limit_m.MinMax10 = 0.0;
    A1_Test_B.deg2rad1.y = 0.0;
    A1_Test_B.deg2rad.y = 0.0;
    A1_Test_B.rad2deg1.y = 0.0;
    A1_Test_B.ATAN1.deg2rad.y = 0.0;
    A1_Test_B.rad2deg.y = 0.0;
    A1_Test_B.ATAN.deg2rad.y = 0.0;
    A1_Test_B.rad2deg3.y = 0.0;
    A1_Test_B.ATAN3.deg2rad.y = 0.0;
    A1_Test_B.rad2deg2.y = 0.0;
    A1_Test_B.ATAN2.deg2rad.y = 0.0;
    A1_Test_B.SIN1.SIN_Function = 0.0;
    A1_Test_B.SIN.SIN_Function = 0.0;
    A1_Test_B.Limit_d.MinMax10 = 0.0;
    A1_Test_B.sf_MATLABFunction_i.y = 0.0;
    A1_Test_B.Limit_b.MinMax10 = 0.0;
    A1_Test_B.Limit_c.MinMax10 = 0.0;
    A1_Test_B.Limit_l.MinMax10 = 0.0;
    A1_Test_B.Limit1_l.MinMax10 = 0.0;
    A1_Test_B.sf_MATLABFunction11.y = 0.0;
    A1_Test_B.Limit.MinMax10 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&A1_Test_DWork, 0,
                sizeof(D_Work_A1_Test));
  A1_Test_DWork.UnitDelay_DSTATE = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_j = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_f = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_b = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_m = 0.0;
  A1_Test_DWork.IC_DSTATE = 0.0;
  A1_Test_DWork.Delay1_DSTATE = 0.0;
  A1_Test_DWork.Delay2_DSTATE = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_d = 0.0;
  A1_Test_DWork.Delay6_DSTATE = 0.0;
  A1_Test_DWork.DelayInput1_DSTATE = 0.0;
  A1_Test_DWork.Delay10_DSTATE = 0.0;
  A1_Test_DWork.Delay_DSTATE = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_o = 0.0;
  A1_Test_DWork.Delay_DSTATE_n = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_e = 0.0;
  A1_Test_DWork.Delay2_DSTATE_o = 0.0;

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      A1_Test_DWork.Delay_DSTATE_i[i] = 0.0;
    }
  }

  A1_Test_DWork.Delay1_DSTATE_k[0] = 0.0;
  A1_Test_DWork.Delay1_DSTATE_k[1] = 0.0;
  A1_Test_DWork.Delay1_DSTATE_k[2] = 0.0;
  A1_Test_DWork.UnitDelay_DSTATE_b3 = 0.0;

  /* Start for S-Function (raptor_sfun_xcp): '<S3>/raptor_xcp_update' */

  /* S-Function Block - Start: <S3>/raptor_xcp_update */
  {
    CAN1_XCP_CAN_PreStart(CAN1__XCP_BC_ID_Data(), CAN1__XCP_RX_ID_Data(),
                          CAN1__XCP_TX_ID_Data());
  }

  /* Start for S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /* S-Function Block - Start: <Root>/raptor_target_def */
  {
    UDSClientAddr_RAM_Data() = 1616;
  }

  /* S-Function Block - Start: <Root>/raptor_target_def */
  {
    UDSServerAddr_RAM_Data() = 1536;
  }

  A1_Test_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = ZERO_ZCSIG;
  A1_Test_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = POS_ZCSIG;
  A1_Test_PrevZCSigState.StoreEEPROM_Trig_ZCE = ZERO_ZCSIG;
  A1_Test_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  A1_Test_Foreground_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<S2>/Background'
   */
  A1_Test_Background_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<Root>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */
  A1_Test_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  A1_Test_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<S2>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */
}

/* Model terminate function */
void A1_Test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
