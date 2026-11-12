/*
 * File: inertial_arhs_repair.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "inertial_arhs_repair.h"
#include "ahrs_9d_eskf_types.h"
#include "feedback_correction.h"
#include "quaternion2cbn.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : matlab_ESKF_process_variables_t *ESKF_process_variables
 *                short k
 * Return Type  : void
 */
void inertial_arhs_repair(
    matlab_ESKF_process_variables_t *ESKF_process_variables, short k)
{
  int i;
  short last_p;
  /* 	惯性导航计算 */
  /*    system_physical_state 系统物理状态保存导航输出物理量结果 */
  /*    ESKF_process_variables ESKF计算过程变量，P Q R K等 */
  /*    imu_m_now 本次IMU测量数据 */
  /*    dt计算周期 */
  i = k - 1;
  if (k - 1 < -32768) {
    i = -32768;
  }
  last_p = (short)i;
  if ((short)i == 0) {
    last_p = 20;
  }
  if ((ESKF_process_variables->his_physical_state[last_p - 1].time != 0ULL) &&
      (ESKF_process_variables->his_physical_state[last_p - 1].dt != 0.0F)) {
    float b_fv[16];
    float q[4];
    float dt;
    float f;
    float f1;
    float f2;
    float f3;
    float gyro_idx_0;
    float gyro_idx_1;
    float q_root;
    float y_idx_1;
    float y_idx_2;
    dt = ESKF_process_variables->his_physical_state[last_p - 1].dt;
    /*  %反馈补偿 */
    feedback_correction(
        ESKF_process_variables,
        &ESKF_process_variables->his_physical_state[last_p - 1]);
    /* 陀螺仪转换为弧度   */
    f = ESKF_process_variables->his_physical_state[k - 1].gyro_raw[0] -
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[0];
    gyro_idx_0 = f;
    q_root = f * dt;
    f = ESKF_process_variables->his_physical_state[k - 1].gyro_raw[1] -
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[1];
    gyro_idx_1 = f;
    y_idx_1 = f * dt;
    f = ESKF_process_variables->his_physical_state[k - 1].gyro_raw[2] -
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[2];
    y_idx_2 = f * dt;
    /* 	更新四元数一阶求解 */
    b_fv[0] = 0.0F;
    f1 = 0.5F * -q_root;
    b_fv[4] = f1;
    f2 = 0.5F * -y_idx_1;
    b_fv[8] = f2;
    f3 = 0.5F * -y_idx_2;
    b_fv[12] = f3;
    b_fv[1] = 0.5F * q_root;
    b_fv[5] = 0.0F;
    b_fv[9] = 0.5F * y_idx_2;
    b_fv[13] = f2;
    b_fv[2] = 0.5F * y_idx_1;
    b_fv[6] = f3;
    b_fv[10] = 0.0F;
    b_fv[14] = 0.5F * q_root;
    b_fv[3] = 0.5F * y_idx_2;
    b_fv[7] = 0.5F * y_idx_1;
    b_fv[11] = f1;
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
    q[0] /= q_root;
    q[1] /= q_root;
    q[2] /= q_root;
    q[3] /= q_root;
    quaternion2cbn(q, ESKF_process_variables->his_physical_state[k - 1].cbn);
    ESKF_process_variables->his_physical_state[k - 1].bias_gyro[0] =
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[0];
    ESKF_process_variables->his_physical_state[k - 1].bias_gyro[1] =
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[1];
    ESKF_process_variables->his_physical_state[k - 1].bias_gyro[2] =
        ESKF_process_variables->his_physical_state[last_p - 1].bias_gyro[2];
    ESKF_process_variables->his_physical_state[k - 1].q[0] = q[0];
    ESKF_process_variables->his_physical_state[k - 1].q[1] = q[1];
    ESKF_process_variables->his_physical_state[k - 1].q[2] = q[2];
    ESKF_process_variables->his_physical_state[k - 1].q[3] = q[3];
    ESKF_process_variables->his_physical_state[k - 1].gyro[0] = gyro_idx_0;
    ESKF_process_variables->his_physical_state[k - 1].gyro[1] = gyro_idx_1;
    ESKF_process_variables->his_physical_state[k - 1].gyro[2] = f;
    ESKF_process_variables->his_physical_state[k - 1].F1 =
        ESKF_process_variables->his_physical_state[last_p - 1].F1 + dt;
    for (i = 0; i < 9; i++) {
      ESKF_process_variables->his_physical_state[k - 1].F3[i] =
          ESKF_process_variables->his_physical_state[last_p - 1].F3[i] -
          ESKF_process_variables->his_physical_state[k - 1].cbn[i] * dt;
    }
  }
}

/*
 * File trailer for inertial_arhs_repair.c
 *
 * [EOF]
 */
