/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HCU_LIB.h
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

#ifndef RTW_HEADER_HCU_LIB_h_
#define RTW_HEADER_HCU_LIB_h_
#include <math.h>
#ifndef A1_Test_COMMON_INCLUDES_
#define A1_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "data.h"
#include "sdk_interface.h"
#include "sdk_io_dictionary.h"
#include "time_api.h"
#include "xcp_protocol.h"
#include "sdk_can.h"
#include "can_4423__0004.h"
#include "stdio.h"
#include "string.h"
#include "can_4424__0004.h"
#endif                                 /* A1_Test_COMMON_INCLUDES_ */

#include "A1_Test_types.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S4>/Limit' */
typedef struct {
  real_T MinMax10;                     /* '<S18>/MinMax10' */
} rtB_limit_lib;

/* Block signals for system '<S43>/SIN' */
typedef struct {
  real_T SIN_Function;                 /* '<S50>/SIN_Function' */
} rtB_sin_lib;

/* Block signals for system '<S48>/deg2rad' */
typedef struct {
  real_T y;                            /* '<S73>/Gain' */
} rtB_deg2rad_lib;

/* Block signals for system '<S43>/ATAN2' */
typedef struct {
  rtB_deg2rad_lib deg2rad;             /* '<S48>/deg2rad' */
} rtB_atan_lib;

/* Block signals for system '<S43>/rad2deg2' */
typedef struct {
  real_T y;                            /* '<S66>/Gain' */
} rtB_rad2deg_lib;

extern void limit_lib(real_T rtu_input, real_T rtu_upper_limit, real_T
                      rtu_lower_limit, rtB_limit_lib *localB);
extern void sin_lib(real_T rtu_u_rad, rtB_sin_lib *localB);
extern void deg2rad_lib(real_T rtu_u, rtB_deg2rad_lib *localB);
extern void atan_lib(real_T rtu_u, rtB_atan_lib *localB);
extern void rad2deg_lib(real_T rtu_u, rtB_rad2deg_lib *localB);

#endif                                 /* RTW_HEADER_HCU_LIB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
