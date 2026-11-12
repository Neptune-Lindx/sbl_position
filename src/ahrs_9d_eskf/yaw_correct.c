/*
 * File: yaw_correct.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "yaw_correct.h"
#include "ahrs_9d_eskf_types.h"
#include "cbn2euler.h"
#include "get_his_physical_state.h"
#include "inertial_arhs_repair.h"
#include "radians_conv_np_pi.h"
#include "reset_state_by_yaw_obs.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * 航向角观测更新。yaw_obs 为滤波器航向（rad，俯视顺时针为正，已折到 (-pi,
 * pi]）。 误差态与加速度计一致：C_new = (I+[phi x]) C，phi(3) = yaw_est -
 * yaw_obs。 首条航向直接对准（大角度不能走 so3 一阶近似）；之后按 1 维观测做
 * ESKF。 本函数只做量测更新，不重复加过程噪声（同一拍加速度计已经预测过 P）。
 *
 * Arguments    : matlab_system_physical_state_t *system_physical_state
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 *                matlab_ESKF_obs_variables_t *ESKF_observation_variables
 *                const matlab_ESKF_config_t *ESKF_config
 *                unsigned long long update_time
 *                float yaw_obs
 *                float yaw_obs_var
 *                unsigned char *yaw_align_flag
 * Return Type  : void
 */
void yaw_correct(matlab_system_physical_state_t *system_physical_state,
                 matlab_ESKF_process_variables_t *ESKF_process_variables,
                 matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                 const matlab_ESKF_config_t *ESKF_config,
                 unsigned long long update_time, float yaw_obs,
                 float yaw_obs_var, unsigned char *yaw_align_flag)
{
  static const signed char a[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  unsigned long long syn_time;
  float cbn[9];
  float a__1[3];
  float Z;
  float a__4;
  float yaw_est;
  int b_i;
  int i;
  int i1;
  short syn_index;
  get_his_physical_state(ESKF_process_variables, ESKF_config, update_time, cbn,
                         a__1, &syn_time, &syn_index);
  if ((syn_index >= 1) && (syn_index <= 20) && (syn_time != 0ULL)) {
    if (*yaw_align_flag == 0) {
      cbn2euler(cbn, &system_physical_state->euler[0],
                &system_physical_state->euler[1], &a__4);
      reset_state_by_yaw_obs(yaw_obs, system_physical_state,
                             ESKF_process_variables);
      /*  航向已被观测钉住，清掉航向失准角与其它状态的互相关 */
      for (i = 0; i < 6; i++) {
        ESKF_process_variables->P[6 * i + 2] = 0.0F;
      }
      for (i = 0; i < 6; i++) {
        ESKF_process_variables->P[i + 12] = 0.0F;
      }
      ESKF_process_variables->P[14] = yaw_obs_var;
      memcpy(&ESKF_observation_variables->P[0], &ESKF_process_variables->P[0],
             36U * sizeof(float));
      *yaw_align_flag = 1U;
    } else {
      cbn2euler(cbn, &a__4, &Z, &yaw_est);
      Z = radians_conv_np_pi(yaw_est - yaw_obs);
      /*  陀螺已经积分了转弯，新息只应是 1 s 内的漂移。过大视为野值，本拍不用 */
      if (!(fabsf(Z) > 0.785398185F)) {
        float c_I[36];
        float d_I[36];
        float K[6];
        short b_i1;
        short end_p;
        signed char b_I[36];
        if (Z > 0.261799395F) {
          Z = 0.261799395F;
        } else if (Z < -0.261799395F) {
          Z = -0.261799395F;
        }
        a__4 = 0.0F;
        for (i = 0; i < 6; i++) {
          yaw_est = 0.0F;
          for (i1 = 0; i1 < 6; i1++) {
            yaw_est += (float)a[i1] * ESKF_process_variables->P[i1 + 6 * i];
          }
          a__4 += yaw_est * (float)b_iv[i];
        }
        a__4 += yaw_obs_var;
        for (b_i = 0; b_i < 6; b_i++) {
          yaw_est = 0.0F;
          for (i = 0; i < 6; i++) {
            yaw_est += ESKF_process_variables->P[b_i + 6 * i] * (float)b_iv[i];
          }
          yaw_est /= a__4;
          K[b_i] = yaw_est;
          ESKF_process_variables->Xk[b_i] = yaw_est * Z;
        }
        for (i = 0; i < 36; i++) {
          b_I[i] = 0;
        }
        for (b_i = 0; b_i < 6; b_i++) {
          b_I[b_i + 6 * b_i] = 1;
        }
        for (i = 0; i < 6; i++) {
          for (i1 = 0; i1 < 6; i1++) {
            b_i = i1 + 6 * i;
            c_I[b_i] = (float)b_I[b_i] - K[i1] * (float)a[i];
          }
        }
        for (i = 0; i < 6; i++) {
          for (i1 = 0; i1 < 6; i1++) {
            yaw_est = 0.0F;
            for (b_i = 0; b_i < 6; b_i++) {
              yaw_est +=
                  c_I[i + 6 * b_i] * ESKF_process_variables->P[b_i + 6 * i1];
            }
            d_I[i + 6 * i1] = yaw_est;
          }
        }
        for (i = 0; i < 36; i++) {
          yaw_est = d_I[i];
          ESKF_process_variables->P[i] = yaw_est;
          ESKF_observation_variables->P[i] = yaw_est;
        }
        for (b_i = 0; b_i < 6; b_i++) {
          ESKF_observation_variables->Xk[b_i] = ESKF_process_variables->Xk[b_i];
        }
        ESKF_process_variables->correction_count = 1;
        b_i1 = syn_index;
        end_p = syn_index;
        while ((b_i1 >= syn_index) && (b_i1 <= end_p)) {
          short new_p;
          i = ESKF_process_variables->his_in - 1;
          if (i < -32768) {
            i = -32768;
          }
          if (ESKF_process_variables->his_in == 1) {
            new_p = 20;
          } else {
            new_p = (short)i;
          }
          end_p = syn_index;
          if ((syn_time <
               ESKF_process_variables->his_physical_state[new_p - 1].time) &&
              (syn_index < new_p)) {
            end_p = new_p;
          } else if ((syn_time <
                      ESKF_process_variables->his_physical_state[new_p - 1]
                          .time) &&
                     (syn_index > new_p)) {
            end_p = (short)(new_p + 20);
          }
          new_p = b_i1;
          if (b_i1 > 20) {
            new_p = (short)(b_i1 - 20);
          }
          inertial_arhs_repair(ESKF_process_variables, new_p);
          b_i1++;
        }
      }
    }
  }
}

/*
 * File trailer for yaw_correct.c
 *
 * [EOF]
 */
