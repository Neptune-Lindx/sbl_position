/*
 * File: update_quaternion.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "update_quaternion.h"
#include "quaternion_normalize.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * 更新四元数一阶求解
 *
 * Arguments    : float q[4]
 *                const float gyro[3]
 * Return Type  : void
 */
void update_quaternion(float q[4], const float gyro[3])
{
  float b_fv[16];
  float b_q[4];
  float f;
  float f1;
  float f2;
  int i;
  b_fv[0] = 0.0F;
  f = 0.5F * -gyro[0];
  b_fv[4] = f;
  f1 = 0.5F * -gyro[1];
  b_fv[8] = f1;
  f2 = 0.5F * -gyro[2];
  b_fv[12] = f2;
  b_fv[1] = 0.5F * gyro[0];
  b_fv[5] = 0.0F;
  b_fv[9] = 0.5F * gyro[2];
  b_fv[13] = f1;
  b_fv[2] = 0.5F * gyro[1];
  b_fv[6] = f2;
  b_fv[10] = 0.0F;
  b_fv[14] = 0.5F * gyro[0];
  b_fv[3] = 0.5F * gyro[2];
  b_fv[7] = 0.5F * gyro[1];
  b_fv[11] = f;
  b_fv[15] = 0.0F;
  for (i = 0; i < 4; i++) {
    b_q[i] =
        q[i] + (((b_fv[i] * q[0] + b_fv[i + 4] * q[1]) + b_fv[i + 8] * q[2]) +
                b_fv[i + 12] * q[3]);
  }
  q[0] = b_q[0];
  q[1] = b_q[1];
  q[2] = b_q[2];
  q[3] = b_q[3];
  quaternion_normalize(q);
}

/*
 * File trailer for update_quaternion.c
 *
 * [EOF]
 */
