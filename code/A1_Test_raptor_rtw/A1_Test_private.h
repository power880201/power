/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: A1_Test_private.h
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

#ifndef RTW_HEADER_A1_Test_private_h_
#define RTW_HEADER_A1_Test_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "A1_Test.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void Timer_ooqlV(void);
extern void Timer_BGND_G6Wyo(void);
extern void Timed_Trigger_XCP(void);
extern void RxTrig_XCP_BC_CAN1(void);
extern void RxTrig_XCP_CMD_CAN1(void);
extern void CAN1_XCP_CAN_PreStart(uint32_T, uint32_T, uint32_T);
extern real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void A1_Test_MATLABFunction11(real_T rtu_tau, real_T rtu_u, real_T
  rtu_old_u, rtB_MATLABFunction11_A1_Test *localB);
extern void A1_Test_Background_Init(void);
extern void A1_Test_Background_Reset(void);
extern void A1_Test_Background(void);
extern void A1_Test_Foreground_Init(void);
extern void A1_Test_Foreground_Reset(void);
extern void A1_Test_Foreground_Enable(void);
extern void A1_Test_Foreground_Disable(void);
extern void A1_Test_Foreground(void);

#endif                                 /* RTW_HEADER_A1_Test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
