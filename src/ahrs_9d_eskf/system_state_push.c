/*
 * File: system_state_push.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "system_state_push.h"
#include "ahrs_9d_eskf_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const matlab_system_physical_state_t *system_physical_state
 *                unsigned long long imu_m_now_update_time
 *                const float imu_m_now_gyro[3]
 *                const float imu_m_now_acc[3]
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 *                float dt
 * Return Type  : void
 */
void b_system_state_push(
    const matlab_system_physical_state_t *system_physical_state,
    unsigned long long imu_m_now_update_time, const float imu_m_now_gyro[3],
    const float imu_m_now_acc[3],
    matlab_ESKF_process_variables_t *ESKF_process_variables, float dt)
{
  float b_ESKF_process_variables[9];
  int i;
  int i1;
  short last_p;
  /* 保留50次历史数据用来时间戳对齐 */
  for (i = 0; i < 9; i++) {
    ESKF_process_variables
        ->his_physical_state[ESKF_process_variables->his_in - 1]
        .cbn[i] = system_physical_state->cbn[i];
  }
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro[0] = system_physical_state->gyro[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro[1] = system_physical_state->gyro[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro[2] = system_physical_state->gyro[2];
  i = ESKF_process_variables->his_in - 1;
  ESKF_process_variables->his_physical_state[i].time = imu_m_now_update_time;
  i1 = i;
  if (i < -32768) {
    i1 = -32768;
  }
  last_p = (short)i1;
  if ((short)i1 == 0) {
    last_p = 20;
  }
  ESKF_process_variables->his_physical_state[i].correct_flag = 0U;
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .acc_raw[0] = imu_m_now_acc[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .acc_raw[1] = imu_m_now_acc[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .acc_raw[2] = imu_m_now_acc[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro_raw[0] = imu_m_now_gyro[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro_raw[1] = imu_m_now_gyro[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro_raw[2] = imu_m_now_gyro[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .bias_gyro[0] = system_physical_state->bias_gyro[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .bias_gyro[1] = system_physical_state->bias_gyro[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .bias_gyro[2] = system_physical_state->bias_gyro[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[0] = system_physical_state->q[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[1] = system_physical_state->q[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[2] = system_physical_state->q[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[3] = system_physical_state->q[3];
  ESKF_process_variables->his_physical_state[i].F1 =
      ESKF_process_variables->his_physical_state[last_p - 1].F1 + dt;
  for (i1 = 0; i1 < 9; i1++) {
    b_ESKF_process_variables[i1] =
        ESKF_process_variables->his_physical_state[last_p - 1].F3[i1] -
        system_physical_state->cbn[i1] * dt;
  }
  for (i1 = 0; i1 < 9; i1++) {
    ESKF_process_variables
        ->his_physical_state[ESKF_process_variables->his_in - 1]
        .F3[i1] = b_ESKF_process_variables[i1];
  }
  ESKF_process_variables->his_physical_state[i].dt = dt;
  i = ESKF_process_variables->his_in + 1;
  if (i > 32767) {
    i = 32767;
  }
  ESKF_process_variables->his_in = (short)i;
  /* 需要添加程序锁 */
  if (ESKF_process_variables->his_in == 21) {
    ESKF_process_variables->his_in = 1;
  }
}

/*
 * Arguments    : const matlab_system_physical_state_t *system_physical_state
 *                const matlab_imu_m_now_t *imu_m_now
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 *                float dt
 * Return Type  : void
 */
void system_state_push(
    const matlab_system_physical_state_t *system_physical_state,
    const matlab_imu_m_now_t *imu_m_now,
    matlab_ESKF_process_variables_t *ESKF_process_variables, float dt)
{
  float b_ESKF_process_variables[9];
  int i;
  int i1;
  short last_p;
  /* 保留50次历史数据用来时间戳对齐 */
  for (i = 0; i < 9; i++) {
    ESKF_process_variables
        ->his_physical_state[ESKF_process_variables->his_in - 1]
        .cbn[i] = system_physical_state->cbn[i];
  }
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro[0] = system_physical_state->gyro[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro[1] = system_physical_state->gyro[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro[2] = system_physical_state->gyro[2];
  i = ESKF_process_variables->his_in - 1;
  ESKF_process_variables->his_physical_state[i].time = imu_m_now->update_time;
  i1 = i;
  if (i < -32768) {
    i1 = -32768;
  }
  last_p = (short)i1;
  if ((short)i1 == 0) {
    last_p = 20;
  }
  ESKF_process_variables->his_physical_state[i].correct_flag = 0U;
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .acc_raw[0] = imu_m_now->acc[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .acc_raw[1] = imu_m_now->acc[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .acc_raw[2] = imu_m_now->acc[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro_raw[0] = imu_m_now->gyro[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro_raw[1] = imu_m_now->gyro[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .gyro_raw[2] = imu_m_now->gyro[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .bias_gyro[0] = system_physical_state->bias_gyro[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .bias_gyro[1] = system_physical_state->bias_gyro[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .bias_gyro[2] = system_physical_state->bias_gyro[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[0] = system_physical_state->q[0];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[1] = system_physical_state->q[1];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[2] = system_physical_state->q[2];
  ESKF_process_variables->his_physical_state[ESKF_process_variables->his_in - 1]
      .q[3] = system_physical_state->q[3];
  ESKF_process_variables->his_physical_state[i].F1 =
      ESKF_process_variables->his_physical_state[last_p - 1].F1 + dt;
  for (i1 = 0; i1 < 9; i1++) {
    b_ESKF_process_variables[i1] =
        ESKF_process_variables->his_physical_state[last_p - 1].F3[i1] -
        system_physical_state->cbn[i1] * dt;
  }
  for (i1 = 0; i1 < 9; i1++) {
    ESKF_process_variables
        ->his_physical_state[ESKF_process_variables->his_in - 1]
        .F3[i1] = b_ESKF_process_variables[i1];
  }
  ESKF_process_variables->his_physical_state[i].dt = dt;
  i = ESKF_process_variables->his_in + 1;
  if (i > 32767) {
    i = 32767;
  }
  ESKF_process_variables->his_in = (short)i;
  /* 需要添加程序锁 */
  if (ESKF_process_variables->his_in == 21) {
    ESKF_process_variables->his_in = 1;
  }
}

/*
 * File trailer for system_state_push.c
 *
 * [EOF]
 */
