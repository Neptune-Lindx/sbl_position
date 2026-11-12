/*
 * File: robust_igg3_inflate_R.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "robust_igg3_inflate_R.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * ROBUST_IGG3_INFLATE_R  IGG3 抗差：按标准化新息膨胀 R
 *
 *   式(3.45)  tilde_v_i = v_i / sqrt(Q_v_i),  Q_ii = P_ii + R_ii（只用对角）
 *   式(3.46)  lambda_i = IGG3(k0,k1)
 *   迭代：每次只处理 |tilde_v| 最大的分量，最多 6 次（文中 3~8）
 *
 *   assert 固定类型，供 MATLAB Coder 入口/被调用都能推断
 *
 * Arguments    : const float Z[2]
 *                float P11
 *                float P22
 *                const float R_in[4]
 *                float R_out[4]
 * Return Type  : void
 */
void robust_igg3_inflate_R(const float Z[2], float P11, float P22,
                           const float R_in[4], float R_out[4])
{
  int it;
  unsigned char done;
  R_out[0] = R_in[0];
  R_out[1] = R_in[1];
  R_out[2] = R_in[2];
  R_out[3] = R_in[3];
  done = 0U;
  for (it = 0; it < 6; it++) {
    if (done == 0) {
      float vt1;
      float vt2;
      vt1 = fabsf(Z[0]) / sqrtf(fmaxf(P11 + R_out[0], 1.0E-12F));
      vt2 = fabsf(Z[1]) / sqrtf(fmaxf(P22 + R_out[3], 1.0E-12F));
      if ((vt1 <= 2.0F) && (vt2 <= 2.0F)) {
        done = 1U;
      } else {
        unsigned char use1;
        if (vt1 >= vt2) {
          vt2 = vt1;
          use1 = 1U;
        } else {
          use1 = 0U;
        }
        if (vt2 <= 2.0F) {
          vt1 = 1.0F;
        } else if (vt2 >= 5.0F) {
          vt1 = 1.0E+6F;
        } else if (5.0F - vt2 < 0.001F) {
          vt1 = 1.0E+6F;
        } else {
          vt1 = 3.0F / (5.0F - vt2);
          vt1 *= vt2 / 2.0F * vt1;
        }
        if (use1 == 1) {
          R_out[0] = vt1 * R_in[0];
        } else {
          R_out[3] = vt1 * R_in[3];
        }
      }
    }
  }
}

/*
 * File trailer for robust_igg3_inflate_R.c
 *
 * [EOF]
 */
