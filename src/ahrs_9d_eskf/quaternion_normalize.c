/*
 * File: quaternion_normalize.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "quaternion_normalize.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * 四元数归一化
 *    此处显示详细说明
 *
 * Arguments    : float q[4]
 * Return Type  : void
 */
void quaternion_normalize(float q[4])
{
  float q_root;
  q_root = sqrtf(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3] * q[3]);
  if (q_root == 0.0F) {
    q_root = 1.0E-5F;
  }
  q[0] /= q_root;
  q[1] /= q_root;
  q[2] /= q_root;
  q[3] /= q_root;
}

/*
 * File trailer for quaternion_normalize.c
 *
 * [EOF]
 */
