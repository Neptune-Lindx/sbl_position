/*
 * File: ESKF_variables_initial.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "ESKF_variables_initial.h"
#include "ahrs_9d_eskf_data.h"
#include "ahrs_9d_eskf_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : matlab_ESKF_process_variables_t *ESKF_process_variables
 *                matlab_ESKF_obs_variables_t *ESKF_observation_variables
 *                const matlab_ESKF_config_t *ESKF_config
 * Return Type  : void
 */
void ESKF_variables_initial(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_ESKF_obs_variables_t *ESKF_observation_variables,
    const matlab_ESKF_config_t *ESKF_config)
{
  static const float b_fv[9] = {0.00235044304F, 0.0F,           0.0F,
                                0.0F,           0.00235044304F, 0.0F,
                                0.0F,           0.0F,           0.00235044304F};
  int b_i;
  int i;
  int k;
  signed char b_I[36];
  memset(&ESKF_process_variables->Q[0], 0, 36U * sizeof(float));
  ESKF_process_variables->Q[0] = ESKF_config->angle_rand_walk[0];
  ESKF_process_variables->Q[7] = ESKF_config->angle_rand_walk[1];
  ESKF_process_variables->Q[14] = ESKF_config->angle_rand_walk[2];
  ESKF_process_variables->Q[21] = ESKF_config->gyro_bias_noise[0];
  ESKF_process_variables->Q[28] = ESKF_config->gyro_bias_noise[1];
  ESKF_process_variables->Q[35] = ESKF_config->gyro_bias_noise[2];
  for (i = 0; i < 36; i++) {
    b_I[i] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (i = 0; i < 36; i++) {
    ESKF_process_variables->P[i] = b_I[i];
  }
  for (i = 0; i < 3; i++) {
    ESKF_process_variables->P[6 * i] = fv[3 * i];
    k = 6 * (i + 3);
    ESKF_process_variables->P[k + 3] = b_fv[3 * i];
    b_i = 3 * i + 1;
    ESKF_process_variables->P[6 * i + 1] = fv[b_i];
    ESKF_process_variables->P[k + 4] = b_fv[b_i];
    b_i = 3 * i + 2;
    ESKF_process_variables->P[6 * i + 2] = fv[b_i];
    ESKF_process_variables->P[k + 5] = b_fv[b_i];
  }
  ESKF_process_variables->his_in = 1;
  for (b_i = 0; b_i < 20; b_i++) {
    signed char c_I[9];
    ESKF_process_variables->his_physical_state[b_i].time = 0ULL;
    for (i = 0; i < 9; i++) {
      c_I[i] = 0;
    }
    c_I[0] = 1;
    c_I[4] = 1;
    c_I[8] = 1;
    ESKF_process_variables->his_physical_state[b_i].q[0] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].q[1] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].q[2] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].q[3] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].gyro[0] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].gyro[1] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].gyro[2] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].dt = 0.02F;
    ESKF_process_variables->his_physical_state[b_i].F1 = 0.0F;
    for (i = 0; i < 9; i++) {
      ESKF_process_variables->his_physical_state[b_i].cbn[i] = c_I[i];
      ESKF_process_variables->his_physical_state[b_i].F3[i] = 0.0F;
    }
    ESKF_process_variables->his_physical_state[b_i].gyro_raw[0] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].acc_raw[0] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].bias_gyro[0] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].gyro_raw[1] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].acc_raw[1] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].bias_gyro[1] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].gyro_raw[2] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].acc_raw[2] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].bias_gyro[2] = 0.0F;
    ESKF_process_variables->his_physical_state[b_i].correct_flag = 0U;
  }
  for (b_i = 0; b_i < 2; b_i++) {
    ESKF_observation_variables->his_obs[b_i].Accel.index = 1;
    ESKF_observation_variables->his_obs[b_i].Accel.time = 0ULL;
    ESKF_observation_variables->his_obs[b_i].Accel.Z[0] = 0.0F;
    ESKF_observation_variables->his_obs[b_i].Accel.Z[1] = 0.0F;
    ESKF_observation_variables->his_obs[b_i].Accel.R[0] = 0.01F;
    ESKF_observation_variables->his_obs[b_i].Accel.R[1] = 0.0F;
    ESKF_observation_variables->his_obs[b_i].Accel.R[2] = 0.0F;
    ESKF_observation_variables->his_obs[b_i].Accel.R[3] = 0.01F;
  }
  ESKF_process_variables->correction_count = 0;
  for (b_i = 0; b_i < 6; b_i++) {
    ESKF_process_variables->Xk[b_i] = 0.0F;
    ESKF_observation_variables->Xk[b_i] = 0.0F;
  }
  memcpy(&ESKF_observation_variables->P[0], &ESKF_process_variables->P[0],
         36U * sizeof(float));
  for (i = 0; i < 12; i++) {
    ESKF_observation_variables->Accel.H[i] = 0.0F;
    ESKF_observation_variables->Accel.K[i] = 0.0F;
  }
  ESKF_observation_variables->Accel.H[0] = 1.0F;
  ESKF_observation_variables->Accel.H[1] = 0.0F;
  ESKF_observation_variables->Accel.H[2] = 0.0F;
  ESKF_observation_variables->Accel.H[3] = 1.0F;
  ESKF_observation_variables->Accel.R[0] = 0.0F;
  ESKF_observation_variables->Accel.R[1] = 0.0F;
  ESKF_observation_variables->Accel.R[2] = 0.0F;
  ESKF_observation_variables->Accel.R[3] = 0.0F;
  ESKF_observation_variables->Accel.his_obs_index = 1;
}

/*
 * File trailer for ESKF_variables_initial.c
 *
 * [EOF]
 */
