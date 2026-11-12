/*
 * File: yaw_bias_est.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "yaw_bias_est.h"
#include "ahrs_9d_eskf_types.h"
#include "radians_conv_np_pi.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float yaw_bias_body[3]
 *                float yaw_bias_last
 *                float yaw_obs
 *                float last_yaw_obs
 *                float yaw_imu
 *                float last_yaw_imu
 *                unsigned long long time_now
 *                unsigned long long time_last
 *                const matlab_system_physical_state_t *system_physical_state
 * Return Type  : float
 */
float yaw_bias_est(float yaw_bias_body[3], float yaw_bias_last, float yaw_obs,
                   float last_yaw_obs, float yaw_imu, float last_yaw_imu,
                   unsigned long long time_now, unsigned long long time_last,
                   const matlab_system_physical_state_t *system_physical_state)
{
  unsigned long long qY;
  float x;
  float yaw_bias;
  /*  us -> s */
  x = radians_conv_np_pi(radians_conv_np_pi(yaw_imu - last_yaw_imu) -
                         radians_conv_np_pi(yaw_obs - last_yaw_obs));
  qY = time_now - time_last;
  if (qY > time_now) {
    qY = 0ULL;
  }
  yaw_bias = yaw_bias_last + x / ((float)qY / 1.0E+6F);
  /*  天向偏置转到机体系：cbn第三行，避免欧拉角万向节死锁 */
  yaw_bias_body[0] = yaw_bias * system_physical_state->cbn[2];
  yaw_bias_body[1] = yaw_bias * system_physical_state->cbn[5];
  yaw_bias_body[2] = yaw_bias * system_physical_state->cbn[8];
  return yaw_bias;
}

/*
 * File trailer for yaw_bias_est.c
 *
 * [EOF]
 */
