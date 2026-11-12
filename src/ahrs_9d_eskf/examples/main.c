/*
 * File: main.c
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

/* Include Files */
#include "main.h"
#include "ESKF_integrated_acc.h"
#include "ESKF_variables_initial.h"
#include "acc_correct.h"
#include "ahrs_9d_eskf_terminate.h"
#include "ahrs_9d_eskf_types.h"
#include "ahrs_initial.h"
#include "cbn2euler.h"
#include "cbn2quaternion.h"
#include "euler2cbn.h"
#include "feedback_correction.h"
#include "get_his_physical_state.h"
#include "inertial_ahrs_update.h"
#include "inertial_arhs_repair.h"
#include "load_ESKF_config.h"
#include "physical_state_initial.h"
#include "quaternion2cbn.h"
#include "quaternion_normalize.h"
#include "radians_conv_np_pi.h"
#include "reset_his_system_state.h"
#include "reset_physical_state.h"
#include "reset_state_by_yaw_obs.h"
#include "robust_igg3_inflate_R.h"
#include "rt_nonfinite.h"
#include "skew_symmetric.h"
#include "so3_exp.h"
#include "system_state_push.h"
#include "update_quaternion.h"
#include "yaw_bias_est.h"
#include "yaw_correct.h"
#include <string.h>

/* Function Declarations */
static void argInit_2x1_real32_T(float result[2]);

static void argInit_2x6_real32_T(float result[12]);

static void argInit_3x1_real32_T(float result[3]);

static void argInit_3x3_real32_T(float result[9]);

static void argInit_4x1_real32_T(float result[4]);

static void argInit_6x1_real32_T(float result[6]);

static void argInit_6x6_real32_T(float result[36]);

static short argInit_int16_T(void);

static matlab_ESKF_config_t argInit_matlab_ESKF_config_t(void);

static matlab_imu_m_now_t argInit_matlab_imu_m_now_t(void);

static void argInit_matlab_obs_accel_t(matlab_obs_accel_t *result);

static matlab_obs_his_obs_t argInit_matlab_obs_his_obs_t(void);

static float argInit_real32_T(void);

static unsigned long long argInit_uint64_T(void);

static unsigned char argInit_uint8_T(void);

static void
c_argInit_1x20_matlab_his_physi(matlab_his_physical_state_t result[20]);

static void c_argInit_1x2_matlab_obs_his_ob(matlab_obs_his_obs_t result[2]);

static void
c_argInit_matlab_ESKF_obs_varia(matlab_ESKF_obs_variables_t *result);

static void
c_argInit_matlab_ESKF_process_v(matlab_ESKF_process_variables_t *result);

static void
c_argInit_matlab_his_physical_s(matlab_his_physical_state_t *result);

static matlab_obs_his_obs_accel_t c_argInit_matlab_obs_his_obs_ac(void);

static void
c_argInit_matlab_system_physica(matlab_system_physical_state_t *result);

/* Function Definitions */
/*
 * Arguments    : float result[2]
 * Return Type  : void
 */
static void argInit_2x1_real32_T(float result[2])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[12]
 * Return Type  : void
 */
static void argInit_2x6_real32_T(float result[12])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 12; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[3]
 * Return Type  : void
 */
static void argInit_3x1_real32_T(float result[3])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[9]
 * Return Type  : void
 */
static void argInit_3x3_real32_T(float result[9])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 9; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[4]
 * Return Type  : void
 */
static void argInit_4x1_real32_T(float result[4])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[6]
 * Return Type  : void
 */
static void argInit_6x1_real32_T(float result[6])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[36]
 * Return Type  : void
 */
static void argInit_6x6_real32_T(float result[36])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 36; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real32_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : short
 */
static short argInit_int16_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : matlab_ESKF_config_t
 */
static matlab_ESKF_config_t argInit_matlab_ESKF_config_t(void)
{
  matlab_ESKF_config_t result;
  float result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real32_T();
  result.gyro_full_range = result_tmp;
  result.acc_full_range = result_tmp;
  argInit_3x1_real32_T(result.gyro_bias_noise);
  result.mag_noise = result_tmp;
  result.software_version = result_tmp;
  argInit_2x1_real32_T(result.rp_obs_noise);
  result.angle_rand_walk[0] = result.gyro_bias_noise[0];
  result.angle_rand_walk[1] = result.gyro_bias_noise[1];
  result.angle_rand_walk[2] = result.gyro_bias_noise[2];
  return result;
}

/*
 * Arguments    : void
 * Return Type  : matlab_imu_m_now_t
 */
static matlab_imu_m_now_t argInit_matlab_imu_m_now_t(void)
{
  matlab_imu_m_now_t result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_3x1_real32_T(result.gyro);
  result.update_time = argInit_uint64_T();
  result.acc[0] = result.gyro[0];
  result.acc[1] = result.gyro[1];
  result.acc[2] = result.gyro[2];
  return result;
}

/*
 * Arguments    : matlab_obs_accel_t *result
 * Return Type  : void
 */
static void argInit_matlab_obs_accel_t(matlab_obs_accel_t *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result->his_obs_index = argInit_int16_T();
  argInit_2x6_real32_T(result->H);
  argInit_2x6_real32_T(result->K);
  argInit_4x1_real32_T(result->R);
  argInit_2x1_real32_T(result->Z);
}

/*
 * Arguments    : void
 * Return Type  : matlab_obs_his_obs_t
 */
static matlab_obs_his_obs_t argInit_matlab_obs_his_obs_t(void)
{
  matlab_obs_his_obs_t result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result.Accel = c_argInit_matlab_obs_his_obs_ac();
  return result;
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : unsigned long long
 */
static unsigned long long argInit_uint64_T(void)
{
  return 0ULL;
}

/*
 * Arguments    : void
 * Return Type  : unsigned char
 */
static unsigned char argInit_uint8_T(void)
{
  return 0U;
}

/*
 * Arguments    : matlab_his_physical_state_t result[20]
 * Return Type  : void
 */
static void
c_argInit_1x20_matlab_his_physi(matlab_his_physical_state_t result[20])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 20; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    c_argInit_matlab_his_physical_s(&result[idx1]);
  }
}

/*
 * Arguments    : matlab_obs_his_obs_t result[2]
 * Return Type  : void
 */
static void c_argInit_1x2_matlab_obs_his_ob(matlab_obs_his_obs_t result[2])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_matlab_obs_his_obs_t();
  }
}

/*
 * Arguments    : matlab_ESKF_obs_variables_t *result
 * Return Type  : void
 */
static void c_argInit_matlab_ESKF_obs_varia(matlab_ESKF_obs_variables_t *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  c_argInit_1x2_matlab_obs_his_ob(result->his_obs);
  argInit_matlab_obs_accel_t(&result->Accel);
  argInit_6x1_real32_T(result->Xk);
  argInit_6x6_real32_T(result->P);
}

/*
 * Arguments    : matlab_ESKF_process_variables_t *result
 * Return Type  : void
 */
static void
c_argInit_matlab_ESKF_process_v(matlab_ESKF_process_variables_t *result)
{
  short result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_6x6_real32_T(result->Q);
  result_tmp = argInit_int16_T();
  result->correction_count = result_tmp;
  result->his_in = result_tmp;
  c_argInit_1x20_matlab_his_physi(result->his_physical_state);
  argInit_6x1_real32_T(result->Xk);
  memcpy(&result->P[0], &result->Q[0], 36U * sizeof(float));
}

/*
 * Arguments    : matlab_his_physical_state_t *result
 * Return Type  : void
 */
static void c_argInit_matlab_his_physical_s(matlab_his_physical_state_t *result)
{
  float result_tmp;
  int i;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real32_T();
  result->F1 = result_tmp;
  argInit_3x3_real32_T(result->cbn);
  argInit_3x1_real32_T(result->gyro);
  result->time = argInit_uint64_T();
  argInit_4x1_real32_T(result->q);
  result->dt = result_tmp;
  result->correct_flag = argInit_uint8_T();
  for (i = 0; i < 9; i++) {
    result->F3[i] = result->cbn[i];
  }
  result->bias_gyro[0] = result->gyro[0];
  result->gyro_raw[0] = result->gyro[0];
  result->acc_raw[0] = result->gyro[0];
  result->bias_gyro[1] = result->gyro[1];
  result->gyro_raw[1] = result->gyro[1];
  result->acc_raw[1] = result->gyro[1];
  result->bias_gyro[2] = result->gyro[2];
  result->gyro_raw[2] = result->gyro[2];
  result->acc_raw[2] = result->gyro[2];
}

/*
 * Arguments    : void
 * Return Type  : matlab_obs_his_obs_accel_t
 */
static matlab_obs_his_obs_accel_t c_argInit_matlab_obs_his_obs_ac(void)
{
  matlab_obs_his_obs_accel_t result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result.index = argInit_int16_T();
  result.time = argInit_uint64_T();
  argInit_2x1_real32_T(result.Z);
  argInit_4x1_real32_T(result.R);
  return result;
}

/*
 * Arguments    : matlab_system_physical_state_t *result
 * Return Type  : void
 */
static void
c_argInit_matlab_system_physica(matlab_system_physical_state_t *result)
{
  unsigned long long b_result_tmp;
  unsigned char result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_3x1_real32_T(result->euler);
  result_tmp = argInit_uint8_T();
  result->initial_alignment_flag = result_tmp;
  b_result_tmp = argInit_uint64_T();
  result->last_integret_time = b_result_tmp;
  result->ins_heart_beat = b_result_tmp;
  result->correct_heart_beat = b_result_tmp;
  result->time = b_result_tmp;
  argInit_3x3_real32_T(result->cbn);
  argInit_4x1_real32_T(result->q);
  result->acc_correct_flag = result_tmp;
  result->bias_gyro[0] = result->euler[0];
  result->gyro[0] = result->euler[0];
  result->acc[0] = result->euler[0];
  result->del_att_integret[0] = result->euler[0];
  result->bias_gyro[1] = result->euler[1];
  result->gyro[1] = result->euler[1];
  result->acc[1] = result->euler[1];
  result->del_att_integret[1] = result->euler[1];
  result->bias_gyro[2] = result->euler[2];
  result->gyro[2] = result->euler[2];
  result->acc[2] = result->euler[2];
  result->del_att_integret[2] = result->euler[2];
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_acc_correct();
  main_ahrs_initial();
  main_cbn2euler();
  main_cbn2quaternion();
  main_ESKF_integrated_acc();
  main_ESKF_variables_initial();
  main_euler2cbn();
  main_feedback_correction();
  main_get_his_physical_state();
  main_inertial_ahrs_update();
  main_inertial_arhs_repair();
  main_load_ESKF_config();
  main_physical_state_initial();
  main_quaternion2cbn();
  main_quaternion_normalize();
  main_radians_conv_np_pi();
  main_reset_his_system_state();
  main_reset_physical_state();
  main_reset_state_by_yaw_obs();
  main_robust_igg3_inflate_R();
  main_skew_symmetric();
  main_so3_exp();
  main_system_state_push();
  main_update_quaternion();
  main_yaw_bias_est();
  main_yaw_correct();
  /* Terminate the application.
You do not need to do this more than one time. */
  ahrs_9d_eskf_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ESKF_integrated_acc(void)
{
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  float b_fv[2];
  short correction_count;
  /* Initialize function 'ESKF_integrated_acc' input arguments. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'ESKF_observation_variables'. */
  /* Initialize function input argument 'Z'. */
  /* Call the entry-point 'ESKF_integrated_acc'. */
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  c_argInit_matlab_ESKF_obs_varia(&ESKF_observation_variables);
  argInit_2x1_real32_T(b_fv);
  correction_count =
      ESKF_integrated_acc(&ESKF_process_variables, &ESKF_observation_variables,
                          b_fv, argInit_int16_T(), argInit_uint8_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ESKF_variables_initial(void)
{
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  /* Initialize function 'ESKF_variables_initial' input arguments. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'ESKF_observation_variables'. */
  /* Initialize function input argument 'ESKF_config'. */
  /* Call the entry-point 'ESKF_variables_initial'. */
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  c_argInit_matlab_ESKF_obs_varia(&ESKF_observation_variables);
  ESKF_config = argInit_matlab_ESKF_config_t();
  ESKF_variables_initial(&ESKF_process_variables, &ESKF_observation_variables,
                         &ESKF_config);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_acc_correct(void)
{
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  float b_fv[3];
  float fv1[2];
  /* Initialize function 'acc_correct' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'ESKF_observation_variables'. */
  /* Initialize function input argument 'ESKF_config'. */
  /* Initialize function input argument 'acc'. */
  /* Initialize function input argument 'att_obs_noise'. */
  /* Call the entry-point 'acc_correct'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  c_argInit_matlab_ESKF_obs_varia(&ESKF_observation_variables);
  ESKF_config = argInit_matlab_ESKF_config_t();
  argInit_3x1_real32_T(b_fv);
  argInit_2x1_real32_T(fv1);
  acc_correct(&system_physical_state, &ESKF_process_variables,
              &ESKF_observation_variables, &ESKF_config, argInit_uint64_T(),
              b_fv, fv1, argInit_uint8_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ahrs_initial(void)
{
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_imu_m_now_t r;
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'ahrs_initial' input arguments. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'ESKF_observation_variables'. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'imu_m_now'. */
  /* Initialize function input argument 'ESKF_config'. */
  /* Call the entry-point 'ahrs_initial'. */
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  c_argInit_matlab_ESKF_obs_varia(&ESKF_observation_variables);
  c_argInit_matlab_system_physica(&system_physical_state);
  ESKF_config = argInit_matlab_ESKF_config_t();
  r = argInit_matlab_imu_m_now_t();
  ahrs_initial(&ESKF_process_variables, &ESKF_observation_variables,
               &system_physical_state, &r, &ESKF_config, argInit_real32_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_cbn2euler(void)
{
  float b_fv[9];
  float pitch;
  float roll;
  float yaw;
  /* Initialize function 'cbn2euler' input arguments. */
  /* Initialize function input argument 'cbn'. */
  /* Call the entry-point 'cbn2euler'. */
  argInit_3x3_real32_T(b_fv);
  cbn2euler(b_fv, &pitch, &roll, &yaw);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_cbn2quaternion(void)
{
  float b_fv[9];
  float q[4];
  /* Initialize function 'cbn2quaternion' input arguments. */
  /* Initialize function input argument 'cbn'. */
  /* Call the entry-point 'cbn2quaternion'. */
  argInit_3x3_real32_T(b_fv);
  cbn2quaternion(b_fv, q);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_euler2cbn(void)
{
  float cbn[9];
  float pitch_tmp;
  /* Initialize function 'euler2cbn' input arguments. */
  pitch_tmp = argInit_real32_T();
  /* Call the entry-point 'euler2cbn'. */
  euler2cbn(pitch_tmp, pitch_tmp, pitch_tmp, cbn);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_feedback_correction(void)
{
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_his_physical_state_t system_physical_state;
  /* Initialize function 'feedback_correction' input arguments. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Call the entry-point 'feedback_correction'. */
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  c_argInit_matlab_his_physical_s(&system_physical_state);
  feedback_correction(&ESKF_process_variables, &system_physical_state);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_get_his_physical_state(void)
{
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  unsigned long long syn_time;
  float cbn[9];
  float gyro[3];
  short syn_index;
  /* Initialize function 'get_his_physical_state' input arguments. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'ESKF_config'. */
  /* Call the entry-point 'get_his_physical_state'. */
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  ESKF_config = argInit_matlab_ESKF_config_t();
  get_his_physical_state(&ESKF_process_variables, &ESKF_config,
                         argInit_uint64_T(), cbn, gyro, &syn_time, &syn_index);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_inertial_ahrs_update(void)
{
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_imu_m_now_t r;
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'inertial_ahrs_update' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'imu_m_now'. */
  /* Initialize function input argument 'ESKF_config'. */
  /* Call the entry-point 'inertial_ahrs_update'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  ESKF_config = argInit_matlab_ESKF_config_t();
  r = argInit_matlab_imu_m_now_t();
  inertial_ahrs_update(&system_physical_state, &ESKF_process_variables, &r,
                       argInit_real32_T(), &ESKF_config);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_inertial_arhs_repair(void)
{
  matlab_ESKF_process_variables_t ESKF_process_variables;
  /* Initialize function 'inertial_arhs_repair' input arguments. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Call the entry-point 'inertial_arhs_repair'. */
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  inertial_arhs_repair(&ESKF_process_variables, argInit_int16_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_load_ESKF_config(void)
{
  matlab_ESKF_config_t ESKF_config;
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'load_ESKF_config' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'ESKF_config'. */
  /* Call the entry-point 'load_ESKF_config'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  ESKF_config = argInit_matlab_ESKF_config_t();
  load_ESKF_config(&system_physical_state, &ESKF_config);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_physical_state_initial(void)
{
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'physical_state_initial' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Call the entry-point 'physical_state_initial'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  physical_state_initial(&system_physical_state);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_quaternion2cbn(void)
{
  float cbn[9];
  float b_fv[4];
  /* Initialize function 'quaternion2cbn' input arguments. */
  /* Initialize function input argument 'q'. */
  /* Call the entry-point 'quaternion2cbn'. */
  argInit_4x1_real32_T(b_fv);
  quaternion2cbn(b_fv, cbn);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_quaternion_normalize(void)
{
  float q[4];
  /* Initialize function 'quaternion_normalize' input arguments. */
  /* Initialize function input argument 'q'. */
  /* Call the entry-point 'quaternion_normalize'. */
  argInit_4x1_real32_T(q);
  quaternion_normalize(q);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_radians_conv_np_pi(void)
{
  float radians_out;
  /* Initialize function 'radians_conv_np_pi' input arguments. */
  /* Call the entry-point 'radians_conv_np_pi'. */
  radians_out = radians_conv_np_pi(argInit_real32_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_reset_his_system_state(void)
{
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'reset_his_system_state' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Call the entry-point 'reset_his_system_state'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  reset_his_system_state(&system_physical_state, &ESKF_process_variables);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_reset_physical_state(void)
{
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'reset_physical_state' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Call the entry-point 'reset_physical_state'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  reset_physical_state(&system_physical_state);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_reset_state_by_yaw_obs(void)
{
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'reset_state_by_yaw_obs' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Call the entry-point 'reset_state_by_yaw_obs'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  reset_state_by_yaw_obs(argInit_real32_T(), &system_physical_state,
                         &ESKF_process_variables);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_robust_igg3_inflate_R(void)
{
  float R_out[4];
  float fv1[4];
  float b_fv[2];
  float P11_tmp;
  /* Initialize function 'robust_igg3_inflate_R' input arguments. */
  /* Initialize function input argument 'Z'. */
  P11_tmp = argInit_real32_T();
  /* Initialize function input argument 'R_in'. */
  /* Call the entry-point 'robust_igg3_inflate_R'. */
  argInit_2x1_real32_T(b_fv);
  argInit_4x1_real32_T(fv1);
  robust_igg3_inflate_R(b_fv, P11_tmp, P11_tmp, fv1, R_out);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_skew_symmetric(void)
{
  float a_hat[9];
  float b_fv[3];
  /* Initialize function 'skew_symmetric' input arguments. */
  /* Initialize function input argument 'a'. */
  /* Call the entry-point 'skew_symmetric'. */
  argInit_3x1_real32_T(b_fv);
  skew_symmetric(b_fv, a_hat);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_so3_exp(void)
{
  float R[9];
  float b_fv[3];
  /* Initialize function 'so3_exp' input arguments. */
  /* Initialize function input argument 'a'. */
  /* Call the entry-point 'so3_exp'. */
  argInit_3x1_real32_T(b_fv);
  so3_exp(b_fv, R);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_system_state_push(void)
{
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_imu_m_now_t r;
  matlab_system_physical_state_t system_physical_state;
  /* Initialize function 'system_state_push' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'imu_m_now'. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Call the entry-point 'system_state_push'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  r = argInit_matlab_imu_m_now_t();
  system_state_push(&system_physical_state, &r, &ESKF_process_variables,
                    argInit_real32_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_update_quaternion(void)
{
  float q[4];
  float b_fv[3];
  /* Initialize function 'update_quaternion' input arguments. */
  /* Initialize function input argument 'q'. */
  /* Initialize function input argument 'gyro'. */
  /* Call the entry-point 'update_quaternion'. */
  argInit_4x1_real32_T(q);
  argInit_3x1_real32_T(b_fv);
  update_quaternion(q, b_fv);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_yaw_bias_est(void)
{
  matlab_system_physical_state_t r;
  unsigned long long time_now_tmp;
  float yaw_bias_body[3];
  float yaw_bias_last_tmp;
  /* Initialize function 'yaw_bias_est' input arguments. */
  /* Initialize function input argument 'yaw_bias_body'. */
  yaw_bias_last_tmp = argInit_real32_T();
  time_now_tmp = argInit_uint64_T();
  /* Initialize function input argument 'system_physical_state'. */
  /* Call the entry-point 'yaw_bias_est'. */
  argInit_3x1_real32_T(yaw_bias_body);
  c_argInit_matlab_system_physica(&r);
  yaw_bias_last_tmp = yaw_bias_est(
      yaw_bias_body, yaw_bias_last_tmp, yaw_bias_last_tmp, yaw_bias_last_tmp,
      yaw_bias_last_tmp, yaw_bias_last_tmp, time_now_tmp, time_now_tmp, &r);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_yaw_correct(void)
{
  matlab_ESKF_config_t r;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  float yaw_obs_tmp;
  unsigned char yaw_align_flag;
  /* Initialize function 'yaw_correct' input arguments. */
  /* Initialize function input argument 'system_physical_state'. */
  /* Initialize function input argument 'ESKF_process_variables'. */
  /* Initialize function input argument 'ESKF_observation_variables'. */
  /* Initialize function input argument 'ESKF_config'. */
  yaw_obs_tmp = argInit_real32_T();
  /* Call the entry-point 'yaw_correct'. */
  c_argInit_matlab_system_physica(&system_physical_state);
  c_argInit_matlab_ESKF_process_v(&ESKF_process_variables);
  c_argInit_matlab_ESKF_obs_varia(&ESKF_observation_variables);
  yaw_align_flag = argInit_uint8_T();
  r = argInit_matlab_ESKF_config_t();
  yaw_correct(&system_physical_state, &ESKF_process_variables,
              &ESKF_observation_variables, &r, argInit_uint64_T(), yaw_obs_tmp,
              yaw_obs_tmp, &yaw_align_flag);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
