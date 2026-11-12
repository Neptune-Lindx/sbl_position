/*
 * File: cbn2quaternion.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "cbn2quaternion.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * UNTITLED8 此处显示有关此函数的摘要
 *    此处显示详细说明
 *
 * Arguments    : const float cbn[9]
 *                float q[4]
 * Return Type  : void
 */
void cbn2quaternion(const float cbn[9], float q[4])
{
  float q0;
  float q1;
  float q2;
  float q3;
  float qq4;
  if (cbn[0] >= cbn[4] + cbn[8]) {
    q1 = 0.5F * sqrtf(((cbn[0] + 1.0F) - cbn[4]) - cbn[8]);
    qq4 = 4.0F * q1;
    q0 = (cbn[5] - cbn[7]) / qq4;
    q2 = (cbn[1] + cbn[3]) / qq4;
    q3 = (cbn[2] + cbn[6]) / qq4;
  } else if (cbn[4] >= cbn[0] + cbn[8]) {
    q2 = 0.5F * sqrtf(((1.0F - cbn[0]) + cbn[4]) - cbn[8]);
    qq4 = 4.0F * q2;
    q0 = (cbn[6] - cbn[2]) / qq4;
    q1 = (cbn[1] + cbn[3]) / qq4;
    q3 = (cbn[5] + cbn[7]) / qq4;
  } else if (cbn[8] >= cbn[0] + cbn[4]) {
    q3 = 0.5F * sqrtf(((1.0F - cbn[0]) - cbn[4]) + cbn[8]);
    qq4 = 4.0F * q3;
    q0 = (cbn[1] - cbn[3]) / qq4;
    q1 = (cbn[2] + cbn[6]) / qq4;
    q2 = (cbn[5] + cbn[7]) / qq4;
  } else {
    q0 = 0.5F * sqrtf(((cbn[0] + 1.0F) + cbn[4]) + cbn[8]);
    qq4 = 4.0F * q0;
    q1 = (cbn[5] - cbn[7]) / qq4;
    q2 = (cbn[6] - cbn[2]) / qq4;
    q3 = (cbn[1] - cbn[3]) / qq4;
  }
  /* 	四元数归一化 */
  /*    此处显示详细说明 */
  qq4 = sqrtf(((q0 * q0 + q1 * q1) + q2 * q2) + q3 * q3);
  if (qq4 == 0.0F) {
    qq4 = 1.0E-5F;
  }
  q[0] = q0 / qq4;
  q[1] = q1 / qq4;
  q[2] = q2 / qq4;
  q[3] = q3 / qq4;
}

/*
 * File trailer for cbn2quaternion.c
 *
 * [EOF]
 */
