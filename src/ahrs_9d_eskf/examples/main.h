/*
 * File: main.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

#ifndef MAIN_H
#define MAIN_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern int main(int argc, char **argv);

extern void main_ESKF_integrated_acc(void);

extern void main_ESKF_variables_initial(void);

extern void main_acc_correct(void);

extern void main_ahrs_initial(void);

extern void main_cbn2euler(void);

extern void main_cbn2quaternion(void);

extern void main_euler2cbn(void);

extern void main_feedback_correction(void);

extern void main_get_his_physical_state(void);

extern void main_inertial_ahrs_update(void);

extern void main_inertial_arhs_repair(void);

extern void main_load_ESKF_config(void);

extern void main_physical_state_initial(void);

extern void main_quaternion2cbn(void);

extern void main_quaternion_normalize(void);

extern void main_radians_conv_np_pi(void);

extern void main_reset_his_system_state(void);

extern void main_reset_physical_state(void);

extern void main_reset_state_by_yaw_obs(void);

extern void main_robust_igg3_inflate_R(void);

extern void main_skew_symmetric(void);

extern void main_so3_exp(void);

extern void main_system_state_push(void);

extern void main_update_quaternion(void);

extern void main_yaw_bias_est(void);

extern void main_yaw_correct(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for main.h
 *
 * [EOF]
 */
