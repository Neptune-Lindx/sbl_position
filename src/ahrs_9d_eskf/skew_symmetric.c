/*
 * File: skew_symmetric.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "skew_symmetric.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * 求矩阵a的反对称矩阵
 *
 * Arguments    : const float a[3]
 *                float a_hat[9]
 * Return Type  : void
 */
void skew_symmetric(const float a[3], float a_hat[9])
{
  a_hat[0] = 0.0F;
  a_hat[3] = -a[2];
  a_hat[6] = a[1];
  a_hat[1] = a[2];
  a_hat[4] = 0.0F;
  a_hat[7] = -a[0];
  a_hat[2] = -a[1];
  a_hat[5] = a[0];
  a_hat[8] = 0.0F;
}

/*
 * File trailer for skew_symmetric.c
 *
 * [EOF]
 */
