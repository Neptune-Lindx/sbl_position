/*
 * File: acc_correct.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "acc_correct.h"
#include "ahrs_9d_eskf_data.h"
#include "ahrs_9d_eskf_types.h"
#include "cbn2quaternion.h"
#include "inv.h"
#include "norm.h"
#include "quaternion2cbn.h"
#include "robust_igg3_inflate_R.h"
#include "rt_nonfinite.h"
#include "so3_exp.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const matlab_system_physical_state_t *system_physical_state
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 *                matlab_ESKF_obs_variables_t *ESKF_observation_variables
 *                const matlab_ESKF_config_t *ESKF_config
 *                unsigned long long update_time
 *                const float acc[3]
 *                const float att_obs_noise[2]
 *                unsigned char enable_update_Pk1
 * Return Type  : void
 */
void acc_correct(const matlab_system_physical_state_t *system_physical_state,
                 matlab_ESKF_process_variables_t *ESKF_process_variables,
                 matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                 const matlab_ESKF_config_t *ESKF_config,
                 unsigned long long update_time, const float acc[3],
                 const float att_obs_noise[2], unsigned char enable_update_Pk1)
{
  unsigned long long syn_time;
  float P_rkf[36];
  float b_P_rkf[36];
  float b_ESKF_observation_variables[12];
  float y_tmp[12];
  float cbn[9];
  float R_igg3[4];
  float c_ESKF_observation_variables[4];
  float acc_err[3];
  float acc_n[3];
  float gyro[3];
  float P_rkf_tmp;
  float acc_err_tmp;
  float f;
  float q_root;
  int b_i;
  int i;
  int i1;
  int i2;
  int i3;
  short b_i1;
  short end_p;
  short new_p;
  short out;
  short syn_index;
  signed char c_I[36];
  signed char b_I[9];
  bool acc_dyn;
  bool exitg1;
  (void)system_physical_state;
  (void)ESKF_config;
  /* 根据时间戳获取和GNSS数据对齐的惯导数据 */
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
  syn_time = 0ULL;
  syn_index = 0;
  i = ESKF_process_variables->his_in - 1;
  i1 = i;
  if (i < -32768) {
    i1 = -32768;
  }
  if (ESKF_process_variables->his_in == 1) {
    new_p = 20;
  } else {
    new_p = (short)i1;
  }
  i1 = ESKF_process_variables->his_in + 1;
  if (i1 > 32767) {
    i1 = 32767;
  }
  out = (short)i1;
  if (i1 == 21) {
    out = 1;
  }
  if (ESKF_process_variables->his_physical_state[i].time > update_time) {
    for (i1 = 0; i1 < 9; i1++) {
      cbn[i1] = ESKF_process_variables->his_physical_state[i].cbn[i1];
    }
    gyro[0] = ESKF_process_variables->his_physical_state[i].gyro[0];
    gyro[1] = ESKF_process_variables->his_physical_state[i].gyro[1];
    gyro[2] = ESKF_process_variables->his_physical_state[i].gyro[2];
    syn_index = ESKF_process_variables->his_in;
    syn_time = ESKF_process_variables->his_physical_state[i].time;
    ESKF_process_variables->his_physical_state[i].correct_flag = 1U;
  } else if (ESKF_process_variables->his_physical_state[new_p - 1].time <
             update_time) {
    for (i1 = 0; i1 < 9; i1++) {
      cbn[i1] = ESKF_process_variables->his_physical_state[new_p - 1].cbn[i1];
    }
    gyro[0] = ESKF_process_variables->his_physical_state[new_p - 1].gyro[0];
    gyro[1] = ESKF_process_variables->his_physical_state[new_p - 1].gyro[1];
    gyro[2] = ESKF_process_variables->his_physical_state[new_p - 1].gyro[2];
    syn_index = new_p;
    syn_time = ESKF_process_variables->his_physical_state[new_p - 1].time;
    ESKF_process_variables->his_physical_state[new_p - 1].correct_flag = 1U;
  } else {
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 20)) {
      if (ESKF_process_variables->his_physical_state[out - 1].time >=
          update_time) {
        for (i1 = 0; i1 < 9; i1++) {
          cbn[i1] = ESKF_process_variables->his_physical_state[out - 1].cbn[i1];
        }
        gyro[0] = ESKF_process_variables->his_physical_state[out - 1].gyro[0];
        gyro[1] = ESKF_process_variables->his_physical_state[out - 1].gyro[1];
        gyro[2] = ESKF_process_variables->his_physical_state[out - 1].gyro[2];
        syn_index = out;
        syn_time = ESKF_process_variables->his_physical_state[out - 1].time;
        ESKF_process_variables->his_physical_state[out - 1].correct_flag = 1U;
        exitg1 = true;
      } else {
        out++;
        if (out == 21) {
          out = 1;
        }
        b_i++;
      }
    }
  }
  /* 误差Z */
  /*  %计算欧拉角 */
  f = acc[0];
  acc_err_tmp = acc[1];
  P_rkf_tmp = acc[2];
  for (i1 = 0; i1 < 3; i1++) {
    acc_n[i1] =
        (cbn[i1] * f + cbn[i1 + 3] * acc_err_tmp) + cbn[i1 + 6] * P_rkf_tmp;
  }
  q_root = b_norm(acc_n);
  acc_n[0] /= q_root;
  acc_n[1] /= q_root;
  acc_n[2] /= q_root;
  q_root = acc_n[1] - acc_n[2] * 0.0F;
  acc_err[0] = q_root;
  acc_err_tmp = acc_n[2] * 0.0F - acc_n[0];
  acc_err[1] = acc_err_tmp;
  acc_err[2] = acc_n[0] * 0.0F - acc_n[1] * 0.0F;
  ESKF_observation_variables->Accel.Z[0] = q_root;
  ESKF_observation_variables->Accel.Z[1] = acc_err_tmp;
  /* 更新RTK测量噪声 */
  ESKF_observation_variables->Accel.R[0] = att_obs_noise[0];
  ESKF_observation_variables->Accel.R[3] = att_obs_noise[1];
  /*  抗差：线加速度时膨胀 R。纯转动 |acc|≈g 的突变靠下面 Z 限幅，不按陀螺关观测
   */
  /*  无条件调用 IGG3，避免 Coder 因示例 |acc|≈g 走不到分支而无法推断类型 */
  acc_dyn = (fabsf(b_norm(acc) - 9.80665F) >= 0.25F);
  memcpy(&P_rkf[0], &ESKF_process_variables->P[0], 36U * sizeof(float));
  if ((enable_update_Pk1 == 1) && (syn_index >= 1)) {
    P_rkf_tmp = ESKF_process_variables->his_physical_state[syn_index - 1].F1;
    P_rkf[0] =
        ESKF_process_variables->P[0] + ESKF_process_variables->Q[0] * P_rkf_tmp;
    P_rkf[7] =
        ESKF_process_variables->P[7] + ESKF_process_variables->Q[7] * P_rkf_tmp;
  }
  robust_igg3_inflate_R(&acc_err[0], P_rkf[0], P_rkf[7],
                        ESKF_observation_variables->Accel.R, R_igg3);
  if (acc_dyn) {
    ESKF_observation_variables->Accel.R[0] = R_igg3[0];
    ESKF_observation_variables->Accel.R[1] = R_igg3[1];
    ESKF_observation_variables->Accel.R[2] = R_igg3[2];
    ESKF_observation_variables->Accel.R[3] = R_igg3[3];
    if ((R_igg3[0] > 100.0F * att_obs_noise[0]) ||
        (R_igg3[3] > 100.0F * att_obs_noise[1])) {
      ESKF_process_variables->P[0] =
          fminf(ESKF_process_variables->P[0] + 4.87387879E-5F, 0.0109662274F);
      ESKF_process_variables->P[7] =
          fminf(ESKF_process_variables->P[7] + 4.87387879E-5F, 0.0109662274F);
    }
  } else if ((b_norm(gyro) < 0.35F) && ((fabsf(q_root) > 0.0174532924F) ||
                                        (fabsf(acc_err_tmp) > 0.0174532924F))) {
    /*  静止且新息仍大：略抬 P，加快最后 1~3° 拉回（原 3° 门限太高，尾段几乎不抬
     * P） */
    ESKF_process_variables->P[0] =
        fminf(ESKF_process_variables->P[0] + 0.000438649091F, 0.0109662274F);
    ESKF_process_variables->P[7] =
        fminf(ESKF_process_variables->P[7] + 0.000438649091F, 0.0109662274F);
  }
  /*  转动时限幅 4°；全局不超过 6°（原先单次可到 15~20°） */
  if (acc_dyn || (b_norm(gyro) >= 1.0F)) {
    if (q_root > 0.0698131695F) {
      ESKF_observation_variables->Accel.Z[0] = 0.0698131695F;
    } else if (q_root < -0.0698131695F) {
      ESKF_observation_variables->Accel.Z[0] = -0.0698131695F;
    }
    if (acc_err_tmp > 0.0698131695F) {
      ESKF_observation_variables->Accel.Z[1] = 0.0698131695F;
    } else if (acc_err_tmp < -0.0698131695F) {
      ESKF_observation_variables->Accel.Z[1] = -0.0698131695F;
    }
  }
  if (ESKF_observation_variables->Accel.Z[0] > 0.104719758F) {
    ESKF_observation_variables->Accel.Z[0] = 0.104719758F;
  } else if (ESKF_observation_variables->Accel.Z[0] < -0.104719758F) {
    ESKF_observation_variables->Accel.Z[0] = -0.104719758F;
  }
  if (ESKF_observation_variables->Accel.Z[1] > 0.104719758F) {
    ESKF_observation_variables->Accel.Z[1] = 0.104719758F;
  } else if (ESKF_observation_variables->Accel.Z[1] < -0.104719758F) {
    ESKF_observation_variables->Accel.Z[1] = -0.104719758F;
  }
  i1 = ESKF_observation_variables->Accel.his_obs_index - 1;
  ESKF_observation_variables->his_obs[i1].Accel.index = syn_index;
  ESKF_observation_variables->his_obs[i1].Accel.time = syn_time;
  ESKF_observation_variables
      ->his_obs[ESKF_observation_variables->Accel.his_obs_index - 1]
      .Accel.Z[0] = ESKF_observation_variables->Accel.Z[0];
  ESKF_observation_variables
      ->his_obs[ESKF_observation_variables->Accel.his_obs_index - 1]
      .Accel.Z[1] = ESKF_observation_variables->Accel.Z[1];
  ESKF_observation_variables
      ->his_obs[ESKF_observation_variables->Accel.his_obs_index - 1]
      .Accel.R[0] = ESKF_observation_variables->Accel.R[0];
  ESKF_observation_variables
      ->his_obs[ESKF_observation_variables->Accel.his_obs_index - 1]
      .Accel.R[1] = ESKF_observation_variables->Accel.R[1];
  ESKF_observation_variables
      ->his_obs[ESKF_observation_variables->Accel.his_obs_index - 1]
      .Accel.R[2] = ESKF_observation_variables->Accel.R[2];
  ESKF_observation_variables
      ->his_obs[ESKF_observation_variables->Accel.his_obs_index - 1]
      .Accel.R[3] = ESKF_observation_variables->Accel.R[3];
  i1 = ESKF_observation_variables->Accel.his_obs_index + 1;
  if (i1 > 32767) {
    i1 = 32767;
  }
  ESKF_observation_variables->Accel.his_obs_index = (short)i1;
  /* 线程锁需要加到此处后面，防止数据加载进来，his_in还没加1，然后被其他线程抢占了。
   */
  if (ESKF_observation_variables->Accel.his_obs_index == 3) {
    ESKF_observation_variables->Accel.his_obs_index = 1;
  }
  memcpy(&ESKF_observation_variables->P[0], &ESKF_process_variables->P[0],
         36U * sizeof(float));
  if (enable_update_Pk1 == 1) {
    for (i1 = 0; i1 < 36; i1++) {
      P_rkf[i1] = iv[i1];
    }
    for (i1 = 0; i1 < 3; i1++) {
      b_i = 6 * (i1 + 3);
      P_rkf[b_i] =
          ESKF_process_variables->his_physical_state[syn_index - 1].F3[3 * i1];
      P_rkf[b_i + 1] = ESKF_process_variables->his_physical_state[syn_index - 1]
                           .F3[3 * i1 + 1];
      P_rkf[b_i + 2] = ESKF_process_variables->his_physical_state[syn_index - 1]
                           .F3[3 * i1 + 2];
    }
    for (i1 = 0; i1 < 6; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        f = 0.0F;
        for (i3 = 0; i3 < 6; i3++) {
          f += P_rkf[i1 + 6 * i3] * ESKF_process_variables->P[i3 + 6 * i2];
        }
        b_P_rkf[i1 + 6 * i2] = f;
      }
      for (i2 = 0; i2 < 6; i2++) {
        f = 0.0F;
        for (i3 = 0; i3 < 6; i3++) {
          f += b_P_rkf[i1 + 6 * i3] * P_rkf[i2 + 6 * i3];
        }
        i3 = i1 + 6 * i2;
        ESKF_observation_variables->P[i3] =
            f +
            ESKF_process_variables->Q[i3] *
                ESKF_process_variables->his_physical_state[syn_index - 1].F1;
      }
    }
    out = (short)(syn_index - 1);
    if ((short)(syn_index - 1) == 0) {
      out = 20;
    }
    ESKF_process_variables->his_physical_state[out - 1].F1 = 0.0F;
    for (i1 = 0; i1 < 9; i1++) {
      ESKF_process_variables->his_physical_state[out - 1].F3[i1] = 0.0F;
    }
  }
  /*  ESKF_observation_variables.K =
   * ESKF_observation_variables.P*ESKF_observation_variables.H'/(ESKF_observation_variables.H*ESKF_observation_variables.P*ESKF_observation_variables.H'+ESKF_observation_variables.R);
   */
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 6; i2++) {
      b_i = i1 + (i2 << 1);
      y_tmp[i2 + 6 * i1] = ESKF_observation_variables->Accel.H[b_i];
      f = 0.0F;
      for (i3 = 0; i3 < 6; i3++) {
        f += ESKF_observation_variables->Accel.H[i1 + (i3 << 1)] *
             ESKF_observation_variables->P[i3 + 6 * i2];
      }
      b_ESKF_observation_variables[b_i] = f;
    }
  }
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      f = 0.0F;
      for (i3 = 0; i3 < 6; i3++) {
        f += b_ESKF_observation_variables[i1 + (i3 << 1)] * y_tmp[i3 + 6 * i2];
      }
      b_i = i1 + (i2 << 1);
      c_ESKF_observation_variables[b_i] =
          f + ESKF_observation_variables->Accel.R[b_i];
    }
  }
  inv(c_ESKF_observation_variables, R_igg3);
  for (i1 = 0; i1 < 6; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      f = 0.0F;
      for (i3 = 0; i3 < 6; i3++) {
        f += ESKF_observation_variables->P[i1 + 6 * i3] * y_tmp[i3 + 6 * i2];
      }
      b_ESKF_observation_variables[i1 + 6 * i2] = f;
    }
    f = b_ESKF_observation_variables[i1 + 6];
    acc_err_tmp = b_ESKF_observation_variables[i1];
    ESKF_observation_variables->Accel.K[i1] =
        acc_err_tmp * R_igg3[0] + f * R_igg3[1];
    ESKF_observation_variables->Accel.K[i1 + 6] =
        acc_err_tmp * R_igg3[2] + f * R_igg3[3];
  }
  for (i1 = 0; i1 < 36; i1++) {
    c_I[i1] = 0;
  }
  for (b_i = 0; b_i < 6; b_i++) {
    c_I[b_i + 6 * b_i] = 1;
  }
  for (i1 = 0; i1 < 6; i1++) {
    for (i2 = 0; i2 < 6; i2++) {
      i3 = i2 << 1;
      b_i = i1 + 6 * i2;
      P_rkf[b_i] =
          (float)c_I[b_i] - (ESKF_observation_variables->Accel.K[i1] *
                                 ESKF_observation_variables->Accel.H[i3] +
                             ESKF_observation_variables->Accel.K[i1 + 6] *
                                 ESKF_observation_variables->Accel.H[i3 + 1]);
    }
    for (i2 = 0; i2 < 6; i2++) {
      f = 0.0F;
      for (i3 = 0; i3 < 6; i3++) {
        f += P_rkf[i1 + 6 * i3] * ESKF_observation_variables->P[i3 + 6 * i2];
      }
      b_P_rkf[i1 + 6 * i2] = f;
    }
  }
  memcpy(&ESKF_observation_variables->P[0], &b_P_rkf[0], 36U * sizeof(float));
  for (i1 = 0; i1 < 6; i1++) {
    ESKF_observation_variables->Xk[i1] = 0.0F;
    ESKF_observation_variables->Xk[i1] +=
        ESKF_observation_variables->Accel.K[i1] *
        ESKF_observation_variables->Accel.Z[0];
    ESKF_observation_variables->Xk[i1] +=
        ESKF_observation_variables->Accel.K[i1 + 6] *
        ESKF_observation_variables->Accel.Z[1];
  }
  memcpy(&ESKF_process_variables->P[0], &ESKF_observation_variables->P[0],
         36U * sizeof(float));
  ESKF_process_variables->correction_count = 1;
  /*  加速度计只修正倾斜和水平陀螺零偏。航向失准角、天向零偏留给航向观测。 */
  for (b_i = 0; b_i < 6; b_i++) {
    ESKF_process_variables->Xk[b_i] = ESKF_observation_variables->Xk[b_i];
  }
  ESKF_process_variables->Xk[2] = 0.0F;
  q_root = (cbn[2] * ESKF_process_variables->Xk[3] +
            ESKF_process_variables->Xk[4] * cbn[5]) +
           ESKF_process_variables->Xk[5] * cbn[8];
  ESKF_process_variables->Xk[3] -= cbn[2] * q_root;
  ESKF_process_variables->Xk[4] -= cbn[5] * q_root;
  ESKF_process_variables->Xk[5] -= cbn[8] * q_root;
  for (b_i = 0; b_i < 6; b_i++) {
    ESKF_observation_variables->Xk[b_i] = ESKF_process_variables->Xk[b_i];
  }
  b_i1 = syn_index;
  end_p = syn_index;
  while ((b_i1 >= syn_index) && (b_i1 <= end_p)) {
    matlab_his_physical_state_t r;
    /*  for i1=syn_index:end_p */
    if (ESKF_process_variables->his_in == 1) {
      new_p = 20;
      /* 队列中最新的imu状态值 */
    } else {
      i1 = i;
      if (i < -32768) {
        i1 = -32768;
      }
      new_p = (short)i1;
    }
    end_p = syn_index;
    if ((syn_time <
         ESKF_process_variables->his_physical_state[new_p - 1].time) &&
        (syn_index < new_p)) {
      end_p = new_p;
    } else if ((syn_time <
                ESKF_process_variables->his_physical_state[new_p - 1].time) &&
               (syn_index > new_p)) {
      end_p = (short)(new_p + 20);
    }
    new_p = b_i1;
    if (b_i1 > 20) {
      new_p = (short)(b_i1 - 20);
    }
    if ((b_i1 > syn_index) &&
        (ESKF_process_variables->his_physical_state[new_p - 1].correct_flag ==
         1)) {
      int b_i3;
      b_i3 = 0;
      exitg1 = false;
      while ((!exitg1) && (b_i3 < 2)) {
        if (ESKF_observation_variables->his_obs[b_i3].Accel.time ==
            ESKF_process_variables->his_physical_state[new_p - 1].time) {
          ESKF_observation_variables->Accel.R[0] =
              ESKF_observation_variables->his_obs[b_i3].Accel.R[0];
          ESKF_observation_variables->Accel.R[1] =
              ESKF_observation_variables->his_obs[b_i3].Accel.R[1];
          ESKF_observation_variables->Accel.R[2] =
              ESKF_observation_variables->his_obs[b_i3].Accel.R[2];
          ESKF_observation_variables->Accel.R[3] =
              ESKF_observation_variables->his_obs[b_i3].Accel.R[3];
          for (i1 = 0; i1 < 36; i1++) {
            P_rkf[i1] = iv[i1];
          }
          for (i1 = 0; i1 < 3; i1++) {
            b_i = 6 * (i1 + 3);
            P_rkf[b_i] = ESKF_process_variables->his_physical_state[new_p - 1]
                             .F3[3 * i1];
            P_rkf[b_i + 1] =
                ESKF_process_variables->his_physical_state[new_p - 1]
                    .F3[3 * i1 + 1];
            P_rkf[b_i + 2] =
                ESKF_process_variables->his_physical_state[new_p - 1]
                    .F3[3 * i1 + 2];
          }
          for (i1 = 0; i1 < 6; i1++) {
            for (i2 = 0; i2 < 6; i2++) {
              f = 0.0F;
              for (i3 = 0; i3 < 6; i3++) {
                f +=
                    P_rkf[i1 + 6 * i3] * ESKF_process_variables->P[i3 + 6 * i2];
              }
              b_P_rkf[i1 + 6 * i2] = f;
            }
            for (i2 = 0; i2 < 6; i2++) {
              f = 0.0F;
              for (i3 = 0; i3 < 6; i3++) {
                f += b_P_rkf[i1 + 6 * i3] * P_rkf[i2 + 6 * i3];
              }
              i3 = i1 + 6 * i2;
              ESKF_observation_variables->P[i3] =
                  f +
                  ESKF_process_variables->Q[i3] *
                      ESKF_process_variables->his_physical_state[new_p - 1].F1;
            }
          }
          out = (short)(new_p - 1);
          if ((short)(new_p - 1) == 0) {
            out = 20;
          }
          ESKF_process_variables->his_physical_state[out - 1].F1 = 0.0F;
          for (i1 = 0; i1 < 9; i1++) {
            ESKF_process_variables->his_physical_state[out - 1].F3[i1] = 0.0F;
          }
          /*  ESKF_observation_variables.K =
           * ESKF_observation_variables.P*ESKF_observation_variables.H'/(ESKF_observation_variables.H*ESKF_observation_variables.P*ESKF_observation_variables.H'+ESKF_observation_variables.R);
           */
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < 6; i2++) {
              b_i = i1 + (i2 << 1);
              y_tmp[i2 + 6 * i1] = ESKF_observation_variables->Accel.H[b_i];
              f = 0.0F;
              for (i3 = 0; i3 < 6; i3++) {
                f += ESKF_observation_variables->Accel.H[i1 + (i3 << 1)] *
                     ESKF_observation_variables->P[i3 + 6 * i2];
              }
              b_ESKF_observation_variables[b_i] = f;
            }
          }
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < 2; i2++) {
              f = 0.0F;
              for (i3 = 0; i3 < 6; i3++) {
                f += b_ESKF_observation_variables[i1 + (i3 << 1)] *
                     y_tmp[i3 + 6 * i2];
              }
              b_i = i1 + (i2 << 1);
              c_ESKF_observation_variables[b_i] =
                  f + ESKF_observation_variables->Accel.R[b_i];
            }
          }
          inv(c_ESKF_observation_variables, R_igg3);
          for (i1 = 0; i1 < 6; i1++) {
            for (i2 = 0; i2 < 2; i2++) {
              f = 0.0F;
              for (i3 = 0; i3 < 6; i3++) {
                f += ESKF_observation_variables->P[i1 + 6 * i3] *
                     y_tmp[i3 + 6 * i2];
              }
              b_ESKF_observation_variables[i1 + 6 * i2] = f;
            }
            f = b_ESKF_observation_variables[i1 + 6];
            acc_err_tmp = b_ESKF_observation_variables[i1];
            ESKF_observation_variables->Accel.K[i1] =
                acc_err_tmp * R_igg3[0] + f * R_igg3[1];
            ESKF_observation_variables->Accel.K[i1 + 6] =
                acc_err_tmp * R_igg3[2] + f * R_igg3[3];
          }
          for (i1 = 0; i1 < 36; i1++) {
            c_I[i1] = 0;
          }
          for (b_i = 0; b_i < 6; b_i++) {
            c_I[b_i + 6 * b_i] = 1;
          }
          for (i1 = 0; i1 < 6; i1++) {
            for (i2 = 0; i2 < 6; i2++) {
              i3 = i2 << 1;
              b_i = i1 + 6 * i2;
              P_rkf[b_i] = (float)c_I[b_i] -
                           (ESKF_observation_variables->Accel.K[i1] *
                                ESKF_observation_variables->Accel.H[i3] +
                            ESKF_observation_variables->Accel.K[i1 + 6] *
                                ESKF_observation_variables->Accel.H[i3 + 1]);
            }
            for (i2 = 0; i2 < 6; i2++) {
              f = 0.0F;
              for (i3 = 0; i3 < 6; i3++) {
                f += P_rkf[i1 + 6 * i3] *
                     ESKF_observation_variables->P[i3 + 6 * i2];
              }
              b_P_rkf[i1 + 6 * i2] = f;
            }
          }
          memcpy(&ESKF_observation_variables->P[0], &b_P_rkf[0],
                 36U * sizeof(float));
          for (i1 = 0; i1 < 6; i1++) {
            ESKF_observation_variables->Xk[i1] = 0.0F;
            ESKF_observation_variables->Xk[i1] +=
                ESKF_observation_variables->Accel.K[i1] *
                ESKF_observation_variables->his_obs[b_i3].Accel.Z[0];
            ESKF_observation_variables->Xk[i1] +=
                ESKF_observation_variables->Accel.K[i1 + 6] *
                ESKF_observation_variables->his_obs[b_i3].Accel.Z[1];
          }
          ESKF_process_variables->correction_count = 1;
          exitg1 = true;
        } else {
          b_i3++;
        }
      }
    }
    /* 	惯性导航计算 */
    /*    system_physical_state 系统物理状态保存导航输出物理量结果 */
    /*    ESKF_process_variables ESKF计算过程变量，P Q R K等 */
    /*    imu_m_now 本次IMU测量数据 */
    /*    dt计算周期 */
    i1 = new_p - 1;
    if (new_p - 1 < -32768) {
      i1 = -32768;
    }
    out = (short)i1;
    if ((short)i1 == 0) {
      out = 20;
    }
    r = ESKF_process_variables->his_physical_state[out - 1];
    if ((r.time != 0ULL) &&
        (ESKF_process_variables->his_physical_state[out - 1].dt != 0.0F)) {
      float b_fv[16];
      float dt;
      dt = ESKF_process_variables->his_physical_state[out - 1].dt;
      /*  %反馈补偿 */
      /*  第二个入参实际是 his_physical_state
       * 的一个元素，与系统状态不是同一个结构体。 */
      if (ESKF_process_variables->correction_count > 0) {
        i1 = ESKF_process_variables->correction_count - 1;
        if (i1 < -32768) {
          i1 = -32768;
        }
        ESKF_process_variables->correction_count = (short)i1;
        /*  Xk(3) 为航向失准角。加速度计更新前会把它和天向零偏增量清掉； */
        /*  航向更新保留这两项，天向陀螺零偏由航向观测估计。 */
        so3_exp(&ESKF_process_variables->Xk[0], cbn);
        for (i1 = 0; i1 < 3; i1++) {
          f = cbn[i1];
          acc_err_tmp = cbn[i1 + 3];
          P_rkf_tmp = cbn[i1 + 6];
          for (i2 = 0; i2 < 3; i2++) {
            r.cbn[i1 + 3 * i2] =
                (f * ESKF_process_variables->his_physical_state[out - 1]
                         .cbn[3 * i2] +
                 acc_err_tmp *
                     ESKF_process_variables->his_physical_state[out - 1]
                         .cbn[3 * i2 + 1]) +
                P_rkf_tmp * ESKF_process_variables->his_physical_state[out - 1]
                                .cbn[3 * i2 + 2];
          }
        }
        cbn2quaternion(r.cbn, r.q);
        r.bias_gyro[0] =
            ESKF_process_variables->his_physical_state[out - 1].bias_gyro[0] +
            ESKF_process_variables->Xk[3];
        r.bias_gyro[1] =
            ESKF_process_variables->his_physical_state[out - 1].bias_gyro[1] +
            ESKF_process_variables->Xk[4];
        r.bias_gyro[2] =
            ESKF_process_variables->his_physical_state[out - 1].bias_gyro[2] +
            ESKF_process_variables->Xk[5];
      }
      ESKF_process_variables->his_physical_state[out - 1] = r;
      /* 陀螺仪转换为弧度   */
      f = ESKF_process_variables->his_physical_state[new_p - 1].gyro_raw[0] -
          ESKF_process_variables->his_physical_state[out - 1].bias_gyro[0];
      gyro[0] = f;
      acc_n[0] = f * dt;
      f = ESKF_process_variables->his_physical_state[new_p - 1].gyro_raw[1] -
          ESKF_process_variables->his_physical_state[out - 1].bias_gyro[1];
      gyro[1] = f;
      acc_n[1] = f * dt;
      f = ESKF_process_variables->his_physical_state[new_p - 1].gyro_raw[2] -
          ESKF_process_variables->his_physical_state[out - 1].bias_gyro[2];
      acc_n[2] = f * dt;
      /* 	更新四元数一阶求解 */
      b_fv[0] = 0.0F;
      acc_err_tmp = 0.5F * -acc_n[0];
      b_fv[4] = acc_err_tmp;
      P_rkf_tmp = 0.5F * -acc_n[1];
      b_fv[8] = P_rkf_tmp;
      q_root = 0.5F * -acc_n[2];
      b_fv[12] = q_root;
      b_fv[1] = 0.5F * acc_n[0];
      b_fv[5] = 0.0F;
      b_fv[9] = 0.5F * acc_n[2];
      b_fv[13] = P_rkf_tmp;
      b_fv[2] = 0.5F * acc_n[1];
      b_fv[6] = q_root;
      b_fv[10] = 0.0F;
      b_fv[14] = 0.5F * acc_n[0];
      b_fv[3] = 0.5F * acc_n[2];
      b_fv[7] = 0.5F * acc_n[1];
      b_fv[11] = acc_err_tmp;
      b_fv[15] = 0.0F;
      for (i1 = 0; i1 < 4; i1++) {
        R_igg3[i1] =
            ESKF_process_variables->his_physical_state[out - 1].q[i1] +
            (((b_fv[i1] *
                   ESKF_process_variables->his_physical_state[out - 1].q[0] +
               b_fv[i1 + 4] *
                   ESKF_process_variables->his_physical_state[out - 1].q[1]) +
              b_fv[i1 + 8] *
                  ESKF_process_variables->his_physical_state[out - 1].q[2]) +
             b_fv[i1 + 12] *
                 ESKF_process_variables->his_physical_state[out - 1].q[3]);
      }
      /* 	四元数归一化 */
      /*    此处显示详细说明 */
      q_root = sqrtf(((R_igg3[0] * R_igg3[0] + R_igg3[1] * R_igg3[1]) +
                      R_igg3[2] * R_igg3[2]) +
                     R_igg3[3] * R_igg3[3]);
      if (q_root == 0.0F) {
        q_root = 1.0E-5F;
      }
      R_igg3[0] /= q_root;
      R_igg3[1] /= q_root;
      R_igg3[2] /= q_root;
      R_igg3[3] /= q_root;
      quaternion2cbn(R_igg3,
                     ESKF_process_variables->his_physical_state[new_p - 1].cbn);
      ESKF_process_variables->his_physical_state[new_p - 1].bias_gyro[0] =
          ESKF_process_variables->his_physical_state[out - 1].bias_gyro[0];
      ESKF_process_variables->his_physical_state[new_p - 1].bias_gyro[1] =
          ESKF_process_variables->his_physical_state[out - 1].bias_gyro[1];
      ESKF_process_variables->his_physical_state[new_p - 1].bias_gyro[2] =
          ESKF_process_variables->his_physical_state[out - 1].bias_gyro[2];
      ESKF_process_variables->his_physical_state[new_p - 1].q[0] = R_igg3[0];
      ESKF_process_variables->his_physical_state[new_p - 1].q[1] = R_igg3[1];
      ESKF_process_variables->his_physical_state[new_p - 1].q[2] = R_igg3[2];
      ESKF_process_variables->his_physical_state[new_p - 1].q[3] = R_igg3[3];
      ESKF_process_variables->his_physical_state[new_p - 1].gyro[0] = gyro[0];
      ESKF_process_variables->his_physical_state[new_p - 1].gyro[1] = gyro[1];
      ESKF_process_variables->his_physical_state[new_p - 1].gyro[2] = f;
      ESKF_process_variables->his_physical_state[new_p - 1].F1 =
          ESKF_process_variables->his_physical_state[out - 1].F1 + dt;
      for (i1 = 0; i1 < 9; i1++) {
        cbn[i1] =
            ESKF_process_variables->his_physical_state[out - 1].F3[i1] -
            ESKF_process_variables->his_physical_state[new_p - 1].cbn[i1] * dt;
      }
      for (i1 = 0; i1 < 9; i1++) {
        ESKF_process_variables->his_physical_state[new_p - 1].F3[i1] = cbn[i1];
      }
    }
    i1 = b_i1 + 1;
    if (b_i1 + 1 > 32767) {
      i1 = 32767;
    }
    b_i1 = (short)i1;
  }
}

/*
 * File trailer for acc_correct.c
 *
 * [EOF]
 */
