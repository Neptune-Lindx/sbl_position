/*
 * File: cbn2euler.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "cbn2euler.h"
#include "ahrs_9d_eskf_rtwutil.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * UNTITLED 此处显示有关此函数的摘要
 *    此处显示详细说明
 *
 * Arguments    : const float cbn[9]
 *                float *pitch
 *                float *roll
 *                float *yaw
 * Return Type  : void
 */
void cbn2euler(const float cbn[9], float *pitch, float *roll, float *yaw)
{
  *roll = rt_atan2f_snf(-cbn[2], cbn[8]);
  /*  asin 定义域为[-1,1]，数值误差可能导致|C32|>1产生复数 */
  if (cbn[5] >= 1.0F) {
    *pitch = 1.57079637F;
  } else if (cbn[5] <= -1.0F) {
    *pitch = -1.57079637F;
  } else {
    *pitch = asinf(cbn[5]);
  }
  *yaw = rt_atan2f_snf(cbn[3], cbn[4]);
}

/*
 * File trailer for cbn2euler.c
 *
 * [EOF]
 */
