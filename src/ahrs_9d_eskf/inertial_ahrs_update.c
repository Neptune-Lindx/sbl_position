/*
 * File: inertial_ahrs_update.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "inertial_ahrs_update.h"
#include "ahrs_9d_eskf_types.h"
#include "cbn2euler.h"
#include "quaternion2cbn.h"
#include "rt_nonfinite.h"
#include "system_state_push.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : matlab_system_physical_state_t *system_physical_state
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 *                const matlab_imu_m_now_t *imu_m_now
 *                float dt
 *                const matlab_ESKF_config_t *ESKF_config
 * Return Type  : void
 */
void inertial_ahrs_update(
    matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    const matlab_imu_m_now_t *imu_m_now, float dt,
    const matlab_ESKF_config_t *ESKF_config)
{
  float q_root;
  float roll;
  float y_idx_0;
  int i;
  short last_p;
  (void)ESKF_config;
  /* 	惯性导航计算 */
  /*    system_physical_state 系统物理状态保存导航输出物理量结果 */
  /*    ESKF_process_variables ESKF计算过程变量，P Q R K等 */
  /*    imu_m_now 本次IMU测量数据 */
  /*    acc_arm 加速度计内杆臂 */
  /*    dt计算周期 */
  i = ESKF_process_variables->his_in - 1;
  if (i < -32768) {
    i = -32768;
  }
  last_p = (short)i;
  if (i == 0) {
    last_p = 20;
  }
  if ((ESKF_process_variables->his_physical_state[last_p - 1].time != 0ULL) &&
      (ESKF_process_variables->his_physical_state[last_p - 1].dt != 0.0F)) {
    unsigned long long q0;
    unsigned long long qY;
    float b_fv[16];
    float q[4];
    float f;
    float y_idx_1;
    float y_idx_2;
    /* 陀螺仪转换为弧度 */
    system_physical_state->time = imu_m_now->update_time;
    /* 更新四元数 */
    q_root =
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[0];
    roll = imu_m_now->gyro[0] - q_root;
    system_physical_state->gyro[0] = roll;
    system_physical_state->bias_gyro[0] = q_root;
    y_idx_0 = roll * dt;
    q_root =
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[1];
    roll = imu_m_now->gyro[1] - q_root;
    system_physical_state->gyro[1] = roll;
    system_physical_state->bias_gyro[1] = q_root;
    y_idx_1 = roll * dt;
    q_root =
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[2];
    roll = imu_m_now->gyro[2] - q_root;
    system_physical_state->gyro[2] = roll;
    system_physical_state->bias_gyro[2] = q_root;
    y_idx_2 = roll * dt;
    /* 	更新四元数一阶求解 */
    b_fv[0] = 0.0F;
    q_root = 0.5F * -y_idx_0;
    b_fv[4] = q_root;
    roll = 0.5F * -y_idx_1;
    b_fv[8] = roll;
    f = 0.5F * -y_idx_2;
    b_fv[12] = f;
    b_fv[1] = 0.5F * y_idx_0;
    b_fv[5] = 0.0F;
    b_fv[9] = 0.5F * y_idx_2;
    b_fv[13] = roll;
    b_fv[2] = 0.5F * y_idx_1;
    b_fv[6] = f;
    b_fv[10] = 0.0F;
    b_fv[14] = 0.5F * y_idx_0;
    b_fv[3] = 0.5F * y_idx_2;
    b_fv[7] = 0.5F * y_idx_1;
    b_fv[11] = q_root;
    b_fv[15] = 0.0F;
    for (i = 0; i < 4; i++) {
      q[i] =
          ESKF_process_variables->his_physical_state[last_p - 1].q[i] +
          (((b_fv[i] *
                 ESKF_process_variables->his_physical_state[last_p - 1].q[0] +
             b_fv[i + 4] *
                 ESKF_process_variables->his_physical_state[last_p - 1].q[1]) +
            b_fv[i + 8] *
                ESKF_process_variables->his_physical_state[last_p - 1].q[2]) +
           b_fv[i + 12] *
               ESKF_process_variables->his_physical_state[last_p - 1].q[3]);
    }
    /* 	四元数归一化 */
    /*    此处显示详细说明 */
    q_root = sqrtf(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3] * q[3]);
    if (q_root == 0.0F) {
      q_root = 1.0E-5F;
    }
    system_physical_state->q[0] = q[0] / q_root;
    system_physical_state->q[1] = q[1] / q_root;
    system_physical_state->q[2] = q[2] / q_root;
    system_physical_state->q[3] = q[3] / q_root;
    /* 更新姿态矩阵 */
    quaternion2cbn(system_physical_state->q, system_physical_state->cbn);
    /* 更新姿态 */
    cbn2euler(system_physical_state->cbn, &q_root, &roll, &y_idx_0);
    system_physical_state->euler[0] = q_root;
    system_physical_state->euler[1] = roll;
    system_physical_state->euler[2] = y_idx_0;
    /* 更新角速度 */
    system_physical_state->acc[0] = imu_m_now->acc[0];
    system_physical_state->acc[1] = imu_m_now->acc[1];
    system_physical_state->acc[2] = imu_m_now->acc[2];
    b_system_state_push(system_physical_state, imu_m_now->update_time,
                        imu_m_now->gyro, imu_m_now->acc, ESKF_process_variables,
                        dt);
    q0 = system_physical_state->ins_heart_beat;
    qY = q0 + 1ULL;
    if (q0 + 1ULL < q0) {
      qY = MAX_uint64_T;
    }
    system_physical_state->ins_heart_beat = qY;
  }
}

/*
 * File trailer for inertial_ahrs_update.c
 *
 * [EOF]
 */
