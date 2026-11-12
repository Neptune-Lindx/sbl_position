/*
 * File: euler2cbn.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "euler2cbn.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * 此函数为欧拉角转Cbn矩阵，坐标轴XYZ定义为右前上，旋转顺序为ZXY
 *    此处显示详细说明
 *
 * Arguments    : float pitch
 *                float roll
 *                float yaw
 *                float cbn[9]
 * Return Type  : void
 */
void euler2cbn(float pitch, float roll, float yaw, float cbn[9])
{
  float b_cbn_tmp;
  float cbn_tmp;
  float cos_pitch;
  float cos_roll;
  float cos_yaw;
  float sin_pitch;
  float sin_roll;
  float sin_yaw;
  /*  统一为 single，避免 codegen 时不同调用点传入 double/single 无法合并类型 */
  cos_roll = cosf(roll);
  sin_roll = sinf(roll);
  cos_pitch = cosf(pitch);
  sin_pitch = sinf(pitch);
  cos_yaw = cosf(yaw);
  sin_yaw = sinf(yaw);
  cbn_tmp = sin_roll * sin_pitch;
  cbn[0] = cos_roll * cos_yaw + cbn_tmp * sin_yaw;
  cbn[3] = sin_yaw * cos_pitch;
  b_cbn_tmp = cos_roll * sin_pitch;
  cbn[6] = sin_roll * cos_yaw - b_cbn_tmp * sin_yaw;
  cbn[1] = -cos_roll * sin_yaw + cbn_tmp * cos_yaw;
  cbn[4] = cos_yaw * cos_pitch;
  cbn[7] = -sin_roll * sin_yaw - b_cbn_tmp * cos_yaw;
  cbn[2] = -sin_roll * cos_pitch;
  cbn[5] = sin_pitch;
  cbn[8] = cos_roll * cos_pitch;
}

/*
 * File trailer for euler2cbn.c
 *
 * [EOF]
 */
