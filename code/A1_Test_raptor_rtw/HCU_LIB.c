/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HCU_LIB.c
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

#include "HCU_LIB.h"

/* Include model header file for global data */
#include "A1_Test.h"
#include "A1_Test_private.h"

/*
 * Output and update for atomic system:
 *    '<S4>/Limit'
 *    '<S6>/Limit1'
 *    '<S6>/Limit'
 *    '<S1>/Limit'
 *    '<S8>/Limit'
 *    '<S37>/Limit'
 *    '<S13>/Limit'
 *    '<S88>/Limit'
 *    '<S97>/Limit'
 *    '<S98>/Limit'
 *    ...
 */
void limit_lib(real_T rtu_input, real_T rtu_upper_limit, real_T rtu_lower_limit,
               rtB_limit_lib *localB)
{
  real_T y;

  /* MinMax: '<S18>/MinMax5' */
  if ((rtu_input <= rtu_upper_limit) || rtIsNaN(rtu_upper_limit)) {
    y = rtu_input;
  } else {
    y = rtu_upper_limit;
  }

  /* End of MinMax: '<S18>/MinMax5' */

  /* MinMax: '<S18>/MinMax10' */
  if ((y >= rtu_lower_limit) || rtIsNaN(rtu_lower_limit)) {
    /* MinMax: '<S18>/MinMax10' */
    localB->MinMax10 = y;
  } else {
    /* MinMax: '<S18>/MinMax10' */
    localB->MinMax10 = rtu_lower_limit;
  }

  /* End of MinMax: '<S18>/MinMax10' */
}

/*
 * Output and update for atomic system:
 *    '<S43>/SIN'
 *    '<S43>/SIN1'
 */
void sin_lib(real_T rtu_u_rad, rtB_sin_lib *localB)
{
  real_T u0;

  /* Gain: '<S76>/Gain' incorporates:
   *  Gain: '<S50>/Gain'
   *  Product: '<S50>/Product'
   *  Rounding: '<S50>/Rounding Function'
   *  Sum: '<S50>/Subtract'
   */
  u0 = (rtu_u_rad - floor(rtu_u_rad / 6.2831854820251465) * 6.2831853071795862) *
    57.295779513082323;

  /* Saturate: '<S50>/Saturation' */
  if (u0 > 360.0) {
    u0 = 360.0;
  } else if (u0 < 0.0) {
    u0 = 0.0;
  }

  /* End of Saturate: '<S50>/Saturation' */

  /* Lookup_n-D: '<S50>/SIN_Function' */
  localB->SIN_Function = look1_binlcapw(u0, A1_Test_ConstP.pooled19,
    A1_Test_ConstP.pooled18, 40U);
}

/*
 * Output and update for atomic system:
 *    '<S48>/deg2rad'
 *    '<S49>/deg2rad'
 *    '<S46>/deg2rad'
 *    '<S47>/deg2rad'
 *    '<S43>/deg2rad'
 *    '<S43>/deg2rad1'
 */
void deg2rad_lib(real_T rtu_u, rtB_deg2rad_lib *localB)
{
  /* Gain: '<S73>/Gain' */
  localB->y = 0.017453292519943295 * rtu_u;
}

/*
 * Output and update for atomic system:
 *    '<S43>/ATAN2'
 *    '<S43>/ATAN3'
 *    '<S43>/ATAN'
 *    '<S43>/ATAN1'
 */
void atan_lib(real_T rtu_u, rtB_atan_lib *localB)
{
  real_T rtb_Switch_m2;

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S72>/Constant'
   *  Lookup_n-D: '<S48>/ATAN_Function_NEG'
   *  Lookup_n-D: '<S48>/ATAN_Function_POS'
   *  RelationalOperator: '<S72>/Compare'
   *  Saturate: '<S48>/Saturation1'
   */
  if (rtu_u >= 0.0) {
    /* Saturate: '<S48>/Saturation' */
    if (rtu_u > 1000.0) {
      rtb_Switch_m2 = 1000.0;
    } else {
      rtb_Switch_m2 = rtu_u;
    }

    /* End of Saturate: '<S48>/Saturation' */
    rtb_Switch_m2 = look1_binlcapw(rtb_Switch_m2, A1_Test_ConstP.pooled21,
      A1_Test_ConstP.pooled20, 10U);
  } else {
    if (rtu_u < -1000.0) {
      /* Saturate: '<S48>/Saturation1' */
      rtb_Switch_m2 = -1000.0;
    } else {
      /* Saturate: '<S48>/Saturation1' */
      rtb_Switch_m2 = rtu_u;
    }

    rtb_Switch_m2 = look1_binlcapw(rtb_Switch_m2, A1_Test_ConstP.pooled24,
      A1_Test_ConstP.pooled23, 10U);
  }

  /* End of Switch: '<S48>/Switch' */

  /* Outputs for Atomic SubSystem: '<S48>/deg2rad' */
  deg2rad_lib(rtb_Switch_m2, &localB->deg2rad);

  /* End of Outputs for SubSystem: '<S48>/deg2rad' */
}

/*
 * Output and update for atomic system:
 *    '<S43>/rad2deg2'
 *    '<S43>/rad2deg3'
 *    '<S43>/rad2deg'
 *    '<S43>/rad2deg1'
 */
void rad2deg_lib(real_T rtu_u, rtB_rad2deg_lib *localB)
{
  /* Gain: '<S66>/Gain' */
  localB->y = 57.295779513082323 * rtu_u;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
