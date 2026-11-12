/*
 * File: quaternion2cbn.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "quaternion2cbn.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * 此函数为四元数转CNB矩阵，坐标轴XYZ定义为右前上，旋转顺序为ZXY
 *    此处显示详细说明
 *
 * Arguments    : const float q[4]
 *                float cbn[9]
 * Return Type  : void
 */
void quaternion2cbn(const float q[4], float cbn[9])
{
  float b_cbn_tmp;
  float c_cbn_tmp;
  float cbn_tmp;
  float d_cbn_tmp;
  float e_cbn_tmp;
  float f_cbn_tmp;
  float g_cbn_tmp;
  float h_cbn_tmp;
  cbn_tmp = q[0] * q[0];
  b_cbn_tmp = q[1] * q[1];
  c_cbn_tmp = q[2] * q[2];
  d_cbn_tmp = q[3] * q[3];
  cbn[0] = ((cbn_tmp + b_cbn_tmp) - c_cbn_tmp) - d_cbn_tmp;
  e_cbn_tmp = q[1] * q[2];
  f_cbn_tmp = q[0] * q[3];
  cbn[3] = 2.0F * (e_cbn_tmp - f_cbn_tmp);
  g_cbn_tmp = q[1] * q[3];
  h_cbn_tmp = q[0] * q[2];
  cbn[6] = 2.0F * (g_cbn_tmp + h_cbn_tmp);
  cbn[1] = 2.0F * (e_cbn_tmp + f_cbn_tmp);
  cbn_tmp -= b_cbn_tmp;
  cbn[4] = (cbn_tmp + c_cbn_tmp) - d_cbn_tmp;
  b_cbn_tmp = q[2] * q[3];
  e_cbn_tmp = q[0] * q[1];
  cbn[7] = 2.0F * (b_cbn_tmp - e_cbn_tmp);
  cbn[2] = 2.0F * (g_cbn_tmp - h_cbn_tmp);
  cbn[5] = 2.0F * (b_cbn_tmp + e_cbn_tmp);
  cbn[8] = (cbn_tmp - c_cbn_tmp) + d_cbn_tmp;
}

/*
 * File trailer for quaternion2cbn.c
 *
 * [EOF]
 */
