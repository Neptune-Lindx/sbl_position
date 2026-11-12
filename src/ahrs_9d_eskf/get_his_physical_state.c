/*
 * File: get_his_physical_state.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "get_his_physical_state.h"
#include "ahrs_9d_eskf_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : matlab_ESKF_process_variables_t *ESKF_process_variables
 *                const matlab_ESKF_config_t *ESKF_config
 *                unsigned long long gnss_time
 *                float cbn[9]
 *                float gyro[3]
 *                unsigned long long *syn_time
 *                short *syn_index
 * Return Type  : void
 */
void get_his_physical_state(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    const matlab_ESKF_config_t *ESKF_config, unsigned long long gnss_time,
    float cbn[9], float gyro[3], unsigned long long *syn_time, short *syn_index)
{
  int b_i;
  int i;
  short new_p;
  short out;
  signed char b_I[9];
  (void)ESKF_config;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (i = 0; i < 9; i++) {
    cbn[i] = b_I[i];
  }
  gyro[0] = 0.0F;
  gyro[1] = 0.0F;
  gyro[2] = 0.0F;
  *syn_time = 0ULL;
  *syn_index = 0;
  i = ESKF_process_variables->his_in - 1;
  b_i = i;
  if (i < -32768) {
    b_i = -32768;
  }
  if (ESKF_process_variables->his_in == 1) {
    new_p = 20;
  } else {
    new_p = (short)b_i;
  }
  b_i = ESKF_process_variables->his_in + 1;
  if (b_i > 32767) {
    b_i = 32767;
  }
  out = (short)b_i;
  if (b_i == 21) {
    out = 1;
  }
  if (ESKF_process_variables->his_physical_state[i].time > gnss_time) {
    for (b_i = 0; b_i < 9; b_i++) {
      cbn[b_i] = ESKF_process_variables->his_physical_state[i].cbn[b_i];
    }
    gyro[0] = ESKF_process_variables->his_physical_state[i].gyro[0];
    gyro[1] = ESKF_process_variables->his_physical_state[i].gyro[1];
    gyro[2] = ESKF_process_variables->his_physical_state[i].gyro[2];
    *syn_index = ESKF_process_variables->his_in;
    *syn_time = ESKF_process_variables->his_physical_state[i].time;
    ESKF_process_variables->his_physical_state[i].correct_flag = 1U;
  } else if (ESKF_process_variables->his_physical_state[new_p - 1].time <
             gnss_time) {
    for (i = 0; i < 9; i++) {
      cbn[i] = ESKF_process_variables->his_physical_state[new_p - 1].cbn[i];
    }
    gyro[0] = ESKF_process_variables->his_physical_state[new_p - 1].gyro[0];
    gyro[1] = ESKF_process_variables->his_physical_state[new_p - 1].gyro[1];
    gyro[2] = ESKF_process_variables->his_physical_state[new_p - 1].gyro[2];
    *syn_index = new_p;
    *syn_time = ESKF_process_variables->his_physical_state[new_p - 1].time;
    ESKF_process_variables->his_physical_state[new_p - 1].correct_flag = 1U;
  } else {
    bool exitg1;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 20)) {
      if (ESKF_process_variables->his_physical_state[out - 1].time >=
          gnss_time) {
        for (i = 0; i < 9; i++) {
          cbn[i] = ESKF_process_variables->his_physical_state[out - 1].cbn[i];
        }
        gyro[0] = ESKF_process_variables->his_physical_state[out - 1].gyro[0];
        gyro[1] = ESKF_process_variables->his_physical_state[out - 1].gyro[1];
        gyro[2] = ESKF_process_variables->his_physical_state[out - 1].gyro[2];
        *syn_index = out;
        *syn_time = ESKF_process_variables->his_physical_state[out - 1].time;
        ESKF_process_variables->his_physical_state[out - 1].correct_flag = 1U;
        exitg1 = true;
      } else {
        out++;
        if (out == 21) {
          out = 1;
        }
        i++;
      }
    }
  }
}

/*
 * File trailer for get_his_physical_state.c
 *
 * [EOF]
 */
