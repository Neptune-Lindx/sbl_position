/*
 * File: radians_conv_np_pi.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "radians_conv_np_pi.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * UNTITLED9 此处显示有关此函数的摘要
 *    此处显示详细说明
 *
 * Arguments    : float radians_in
 * Return Type  : float
 */
float radians_conv_np_pi(float radians_in)
{
  float radians_out;
  for (radians_out = radians_in; radians_out > 3.14159274F;
       radians_out -= 6.28318548F) {
  }
  while (radians_out < -3.14159274F) {
    radians_out += 6.28318548F;
  }
  return radians_out;
}

/*
 * File trailer for radians_conv_np_pi.c
 *
 * [EOF]
 */
