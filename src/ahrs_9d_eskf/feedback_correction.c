/*
 * File: feedback_correction.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "feedback_correction.h"
#include "ahrs_9d_eskf_types.h"
#include "cbn2quaternion.h"
#include "rt_nonfinite.h"
#include "so3_exp.h"

/* Function Definitions */
/*
 * 第二个入参实际是 his_physical_state 的一个元素，与系统状态不是同一个结构体。
 *
 * Arguments    : matlab_ESKF_process_variables_t *ESKF_process_variables
 *                matlab_his_physical_state_t *system_physical_state
 * Return Type  : void
 */
void feedback_correction(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_his_physical_state_t *system_physical_state)
{
  int i;
  int i1;
  if (ESKF_process_variables->correction_count > 0) {
    float a[9];
    float b_a[9];
    i = ESKF_process_variables->correction_count - 1;
    if (i < -32768) {
      i = -32768;
    }
    ESKF_process_variables->correction_count = (short)i;
    /*  Xk(3) 为航向失准角。加速度计更新前会把它和天向零偏增量清掉； */
    /*  航向更新保留这两项，天向陀螺零偏由航向观测估计。 */
    so3_exp(&ESKF_process_variables->Xk[0], a);
    for (i = 0; i < 3; i++) {
      float f;
      float f1;
      float f2;
      f = a[i];
      f1 = a[i + 3];
      f2 = a[i + 6];
      for (i1 = 0; i1 < 3; i1++) {
        b_a[i + 3 * i1] = (f * system_physical_state->cbn[3 * i1] +
                           f1 * system_physical_state->cbn[3 * i1 + 1]) +
                          f2 * system_physical_state->cbn[3 * i1 + 2];
      }
    }
    for (i = 0; i < 9; i++) {
      system_physical_state->cbn[i] = b_a[i];
    }
    cbn2quaternion(system_physical_state->cbn, system_physical_state->q);
    system_physical_state->bias_gyro[0] += ESKF_process_variables->Xk[3];
    system_physical_state->bias_gyro[1] += ESKF_process_variables->Xk[4];
    system_physical_state->bias_gyro[2] += ESKF_process_variables->Xk[5];
  }
}

/*
 * File trailer for feedback_correction.c
 *
 * [EOF]
 */
