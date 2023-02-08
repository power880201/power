/*
 * File: Adaptive_Cruise_Control_Logic.h
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

#ifndef RTW_HEADER_Adaptive_Cruise_Control_Logic_h_
#define RTW_HEADER_Adaptive_Cruise_Control_Logic_h_
#ifndef Adaptive_Cruise_Control_Logic_COMMON_INCLUDES_
#define Adaptive_Cruise_Control_Logic_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                      /* Adaptive_Cruise_Control_Logic_COMMON_INCLUDES_ */

#include "Adaptive_Cruise_Control_Logic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c1_Adaptive_Cruise_Co;/* '<S2>/ACC_Logic' */
  uint8_T is_c1_Adaptive_Cruise_Control_L;/* '<S2>/ACC_Logic' */
  uint8_T is_ACC_ON_MODE;              /* '<S2>/ACC_Logic' */
} DW_Adaptive_Cruise_Control_Lo_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T Acceleration_Mode_j;         /* '<Root>/Acceleration_Mode' */
} ExtY_Adaptive_Cruise_Control__T;

/* Real-time Model Data Structure */
struct tag_RTM_Adaptive_Cruise_Contr_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Adaptive_Cruise_Control_Lo_T Adaptive_Cruise_Control_Logi_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Adaptive_Cruise_Control__T Adaptive_Cruise_Control_Logic_Y;

/* Model entry point functions */
extern void Adaptive_Cruise_Control_Logic_initialize(void);
extern void Adaptive_Cruise_Control_Logic_step(void);
extern void Adaptive_Cruise_Control_Logic_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern uint8_T Acceleration_Mode;      /* '<S1>/Unit Delay' */

/* Real-time Model object */
extern RT_MODEL_Adaptive_Cruise_Cont_T *const Adaptive_Cruise_Control_Logi_M;

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
 * '<Root>' : 'Adaptive_Cruise_Control_Logic'
 * '<S1>'   : 'Adaptive_Cruise_Control_Logic/AdaptiveCruiseControl'
 * '<S2>'   : 'Adaptive_Cruise_Control_Logic/AdaptiveCruiseControl/Adaptive_Cruise_Control_Algorithm'
 * '<S3>'   : 'Adaptive_Cruise_Control_Logic/AdaptiveCruiseControl/Drive_Vehicle'
 * '<S4>'   : 'Adaptive_Cruise_Control_Logic/AdaptiveCruiseControl/Lead_Vehicle'
 * '<S5>'   : 'Adaptive_Cruise_Control_Logic/AdaptiveCruiseControl/Adaptive_Cruise_Control_Algorithm/ACC_Logic'
 */
#endif                         /* RTW_HEADER_Adaptive_Cruise_Control_Logic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
