/*
 * File: ahrs_initial.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "ahrs_initial.h"
#include "ahrs_9d_eskf_data.h"
#include "ahrs_9d_eskf_rtwutil.h"
#include "ahrs_9d_eskf_types.h"
#include "cbn2quaternion.h"
#include "euler2cbn.h"
#include "rt_nonfinite.h"
#include "system_state_push.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : matlab_ESKF_process_variables_t *ESKF_process_variables
 *                const matlab_ESKF_obs_variables_t *ESKF_observation_variables
 *                matlab_system_physical_state_t *system_physical_state
 *                const matlab_imu_m_now_t *imu_m_now
 *                const matlab_ESKF_config_t *ESKF_config
 *                float dt
 * Return Type  : void
 */
void ahrs_initial(matlab_ESKF_process_variables_t *ESKF_process_variables,
                  const matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                  matlab_system_physical_state_t *system_physical_state,
                  const matlab_imu_m_now_t *imu_m_now,
                  const matlab_ESKF_config_t *ESKF_config, float dt)
{
  static const float b_fv[9] = {2.35044295E-9F, 0.0F,           0.0F,
                                0.0F,           2.35044295E-9F, 0.0F,
                                0.0F,           0.0F,           2.35044295E-9F};
  int b_i;
  int i;
  (void)ESKF_observation_variables;
  (void)ESKF_config;
  if (system_physical_state->initial_alignment_flag == 0) {
    float pitch;
    float r;
    /* 计算欧拉角 */
    if (imu_m_now->acc[1] >= 9.80665F) {
      pitch = 1.57079637F;
    } else if (imu_m_now->acc[1] <= -9.80665F) {
      pitch = -1.57079637F;
    } else {
      pitch = asinf(imu_m_now->acc[1] / 9.80665F);
    }
    r = rt_atan2f_snf(imu_m_now->acc[0], imu_m_now->acc[2]);
    system_physical_state->last_integret_time = 0ULL;
    system_physical_state->del_att_integret[0] = 0.0F;
    system_physical_state->del_att_integret[1] = 0.0F;
    system_physical_state->del_att_integret[2] = 0.0F;
    system_physical_state->time = imu_m_now->update_time;
    for (i = 0; i < 36; i++) {
      ESKF_process_variables->P[i] = iv[i];
    }
    for (i = 0; i < 3; i++) {
      int i1;
      ESKF_process_variables->P[6 * i] = fv[3 * i];
      b_i = 6 * (i + 3);
      ESKF_process_variables->P[b_i + 3] = b_fv[3 * i];
      i1 = 3 * i + 1;
      ESKF_process_variables->P[6 * i + 1] = fv[i1];
      ESKF_process_variables->P[b_i + 4] = b_fv[i1];
      i1 = 3 * i + 2;
      ESKF_process_variables->P[6 * i + 2] = fv[i1];
      ESKF_process_variables->P[b_i + 5] = b_fv[i1];
    }
    /* 初始化欧拉角 */
    system_physical_state->euler[0] = pitch;
    system_physical_state->euler[1] = -r;
    system_physical_state->euler[2] = 0.0F;
    /* 初始化转换矩阵 */
    euler2cbn(pitch, -r, 0.0F, system_physical_state->cbn);
    /* 初始化四元数 */
    cbn2quaternion(system_physical_state->cbn, system_physical_state->q);
    system_physical_state->gyro[0] = imu_m_now->gyro[0];
    system_physical_state->acc[0] = imu_m_now->acc[0];
    system_physical_state->bias_gyro[0] = 0.0F;
    system_physical_state->gyro[1] = imu_m_now->gyro[1];
    system_physical_state->acc[1] = imu_m_now->acc[1];
    system_physical_state->bias_gyro[1] = 0.0F;
    system_physical_state->gyro[2] = imu_m_now->gyro[2];
    system_physical_state->acc[2] = imu_m_now->acc[2];
    system_physical_state->bias_gyro[2] = 0.0F;
    for (b_i = 0; b_i < 20; b_i++) {
      if (ESKF_process_variables->his_physical_state[b_i].time != 0ULL) {
        for (i = 0; i < 9; i++) {
          ESKF_process_variables->his_physical_state[b_i].cbn[i] =
              system_physical_state->cbn[i];
        }
        ESKF_process_variables->his_physical_state[b_i].q[0] =
            system_physical_state->q[0];
        ESKF_process_variables->his_physical_state[b_i].q[1] =
            system_physical_state->q[1];
        ESKF_process_variables->his_physical_state[b_i].q[2] =
            system_physical_state->q[2];
        ESKF_process_variables->his_physical_state[b_i].q[3] =
            system_physical_state->q[3];
      }
    }
    b_system_state_push(system_physical_state, imu_m_now->update_time,
                        imu_m_now->gyro, imu_m_now->acc, ESKF_process_variables,
                        dt);
    /* 更新初始化完成标志 */
    system_physical_state->initial_alignment_flag = 1U;
  }
}

/*
 * File trailer for ahrs_initial.c
 *
 * [EOF]
 */
