/*
 * File: Adaptive_Cruise_Control_Logic.c
 *
 * Code generated for Simulink model 'Adaptive_Cruise_Control_Logic'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Apr  4 12:35:28 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Adaptive_Cruise_Control_Logic.h"
#include "Adaptive_Cruise_Control_Logic_private.h"

/* Named constants for Chart: '<S2>/ACC_Logic' */
#define Ada_IN_LeadVehicle_Not_Detected ((uint8_T)3U)
#define Adaptive_Cr_IN_ACC_STANDBY_MODE ((uint8_T)3U)
#define Adaptive_Cru_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Adaptive_Cruise_IN_ACC_OFF_MODE ((uint8_T)1U)
#define Adaptive_Cruise__IN_ACC_ON_MODE ((uint8_T)2U)
#define IN_LeadVehicle_Detected_Follow ((uint8_T)1U)
#define IN_LeadVehicle_Detected_Resume ((uint8_T)2U)
#define IN_LeadVehicle_Not_Detected_Res ((uint8_T)4U)
#define IN_LeadVehicle_Speed_equal_Set_ ((uint8_T)5U)
#define IN_LeadVehicle_Speed_lessthan_S ((uint8_T)6U)

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
uint8_T Acceleration_Mode;             /* '<S1>/Unit Delay' */

/* Block states (default storage) */
DW_Adaptive_Cruise_Control_Lo_T Adaptive_Cruise_Control_Logi_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Adaptive_Cruise_Control__T Adaptive_Cruise_Control_Logic_Y;

/* Real-time model */
static RT_MODEL_Adaptive_Cruise_Cont_T Adaptive_Cruise_Control_Logi_M_;
RT_MODEL_Adaptive_Cruise_Cont_T *const Adaptive_Cruise_Control_Logi_M =
  &Adaptive_Cruise_Control_Logi_M_;

/* Model step function */
void Adaptive_Cruise_Control_Logic_step(void)
{
  /* local block i/o variables */
  uint8_T LeadVehicle_Speed;
  uint8_T DriveVehicle_Speed;
  uint8_T LeadVehicle_Detected;

  /* Outputs for Atomic SubSystem: '<Root>/AdaptiveCruiseControl' */
  /* Sum: '<S4>/Add' incorporates:
   *  Inport: '<Root>/CameraInput_LeadVehicle'
   *  Inport: '<Root>/RadarInput_LeadVehicle'
   */
  LeadVehicle_Speed = (uint8_T)((uint32_T)CameraInput_LeadVehicle +
    RadarInput_LeadVehicle);

  /* UnitDelay: '<S1>/Unit Delay' */
  Acceleration_Mode = Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j;

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/CameraInput_DriveVehicle'
   *  Inport: '<Root>/RadarInput_DriveVehicle'
   */
  DriveVehicle_Speed = (uint8_T)((uint32_T)(uint8_T)((uint32_T)
    CameraInput_DriveVehicle + Acceleration_Mode) + RadarInput_DriveVehicle);

  /* SignalConversion: '<S3>/Signal Conversion' incorporates:
   *  Inport: '<Root>/RadarInput_DriveVehicle'
   */
  LeadVehicle_Detected = RadarInput_DriveVehicle;

  /* Chart: '<S2>/ACC_Logic' incorporates:
   *  Inport: '<Root>/CruiseSwitch'
   *  Inport: '<Root>/SetSwitch'
   *  Inport: '<Root>/Set_Gap'
   *  Inport: '<Root>/Set_Speed'
   *  Inport: '<Root>/Time_Gap'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  if (Adaptive_Cruise_Control_Logi_DW.is_active_c1_Adaptive_Cruise_Co == 0U) {
    Adaptive_Cruise_Control_Logi_DW.is_active_c1_Adaptive_Cruise_Co = 1U;
    Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L =
      Adaptive_Cruise_IN_ACC_OFF_MODE;
    Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 0U;
  } else {
    switch (Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L) {
     case Adaptive_Cruise_IN_ACC_OFF_MODE:
      Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 0U;
      if (CruiseSwitch) {
        Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L =
          Adaptive_Cr_IN_ACC_STANDBY_MODE;
        Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
      }
      break;

     case Adaptive_Cruise__IN_ACC_ON_MODE:
      if (!SetSwitch) {
        Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
          Adaptive_Cru_IN_NO_ACTIVE_CHILD;
        Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L =
          Adaptive_Cr_IN_ACC_STANDBY_MODE;
        Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
      } else if (!CruiseSwitch) {
        Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
          Adaptive_Cru_IN_NO_ACTIVE_CHILD;
        Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L =
          Adaptive_Cruise_IN_ACC_OFF_MODE;
        Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 0U;
      } else {
        switch (Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE) {
         case IN_LeadVehicle_Detected_Follow:
          Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 2U;
          if (LeadVehicle_Detected == 0) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              Ada_IN_LeadVehicle_Not_Detected;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
          } else if (((LeadVehicle_Detected == 1) && (DriveVehicle_Speed <
                       Set_Speed)) || (Time_Gap < Set_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Speed_lessthan_S;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 4U;
          }
          break;

         case IN_LeadVehicle_Detected_Resume:
          Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 3U;
          if ((DriveVehicle_Speed == Set_Speed) && (LeadVehicle_Speed >=
               Set_Speed) && (Time_Gap >= Set_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Detected_Follow;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 2U;
          } else if (LeadVehicle_Detected == 0) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Not_Detected_Res;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
          } else if (((DriveVehicle_Speed < Set_Speed) && (LeadVehicle_Speed >
                       DriveVehicle_Speed)) || (Time_Gap >= Set_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Speed_equal_Set_;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 5U;
          }
          break;

         case Ada_IN_LeadVehicle_Not_Detected:
          Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
          if ((LeadVehicle_Detected == 1) && (DriveVehicle_Speed == Set_Speed) &&
              (LeadVehicle_Speed >= Set_Speed) && (Time_Gap >= Set_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Detected_Follow;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 2U;
          } else if (((LeadVehicle_Detected == 1) && (DriveVehicle_Speed <
                       Set_Speed)) || (Time_Gap < Set_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Speed_lessthan_S;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 4U;
          }
          break;

         case IN_LeadVehicle_Not_Detected_Res:
          Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
          break;

         case IN_LeadVehicle_Speed_equal_Set_:
          Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 5U;
          if ((DriveVehicle_Speed < Set_Speed) && (LeadVehicle_Speed >
               DriveVehicle_Speed) && (Time_Gap >= Set_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Detected_Resume;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 3U;
          } else if ((LeadVehicle_Detected == 0) || (DriveVehicle_Speed <=
                      Set_Speed)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Not_Detected_Res;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
          } else if (((LeadVehicle_Speed < Set_Speed) && (LeadVehicle_Speed <
                       DriveVehicle_Speed)) || (0.75 * (real_T)Set_Gap ==
                      Time_Gap)) {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Speed_lessthan_S;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 4U;
          }
          break;

         default:
          /* case IN_LeadVehicle_Speed_lessthan_Set_Speed: */
          Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 4U;
          if ((LeadVehicle_Detected == 0) && (DriveVehicle_Speed == Set_Speed))
          {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              Ada_IN_LeadVehicle_Not_Detected;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;

            /*      */
          } else if (((real_T)LeadVehicle_Speed * 1.25 >= DriveVehicle_Speed) &&
                     ((real_T)LeadVehicle_Speed * 0.75 <= DriveVehicle_Speed) &&
                     (DriveVehicle_Speed < Set_Speed) && ((Time_Gap <= 1.25 *
                       (real_T)Set_Gap) && (Time_Gap >= 0.75 * (real_T)Set_Gap)))
          {
            Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
              IN_LeadVehicle_Speed_equal_Set_;
            Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 5U;
          }
          break;
        }
      }
      break;

     default:
      /* case IN_ACC_STANDBY_MODE: */
      Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 1U;
      if (!CruiseSwitch) {
        Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L =
          Adaptive_Cruise_IN_ACC_OFF_MODE;
        Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 0U;
      } else if (SetSwitch) {
        Adaptive_Cruise_Control_Logi_DW.is_c1_Adaptive_Cruise_Control_L =
          Adaptive_Cruise__IN_ACC_ON_MODE;
        Adaptive_Cruise_Control_Logi_DW.is_ACC_ON_MODE =
          IN_LeadVehicle_Detected_Follow;
        Adaptive_Cruise_Control_Logic_Y.Acceleration_Mode_j = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/ACC_Logic' */
  /* End of Outputs for SubSystem: '<Root>/AdaptiveCruiseControl' */
}

/* Model initialize function */
void Adaptive_Cruise_Control_Logic_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Adaptive_Cruise_Control_Logic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
