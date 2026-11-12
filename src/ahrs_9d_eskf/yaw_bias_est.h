/*
 * File: yaw_bias_est.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef YAW_BIAS_EST_H
#define YAW_BIAS_EST_H

/* Include Files */
#include "ahrs_9d_eskf_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern float
yaw_bias_est(float yaw_bias_body[3], float yaw_bias_last, float yaw_obs,
             float last_yaw_obs, float yaw_imu, float last_yaw_imu,
             unsigned long long time_now, unsigned long long time_last,
             const matlab_system_physical_state_t *system_physical_state);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for yaw_bias_est.h
 *
 * [EOF]
 */
