/*
 * File: so3_exp.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "so3_exp.h"
#include "rt_nonfinite.h"
#include "skew_symmetric.h"

/* Function Definitions */
/*
 * 旋转矩阵   李代数->李群  指数映射
 *
 * Arguments    : const float a[3]
 *                float R[9]
 * Return Type  : void
 */
void so3_exp(const float a[3], float R[9])
{
  int i;
  signed char b_I[9];
  skew_symmetric(a, R);
  /*  R = single(eye(3))+A+single(0.5)*A*A+single((1/6))*A*A*A; %指数函数exp
   * 泰勒级数展开 */
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (i = 0; i < 9; i++) {
    R[i] += (float)b_I[i];
  }
  /* 指数函数exp 泰勒级数展开 */
}

/*
 * File trailer for so3_exp.c
 *
 * [EOF]
 */
