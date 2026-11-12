/*
 * File: system_state_push.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef SYSTEM_STATE_PUSH_H
#define SYSTEM_STATE_PUSH_H

/* Include Files */
#include "ahrs_9d_eskf_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_system_state_push(
    const matlab_system_physical_state_t *system_physical_state,
    unsigned long long imu_m_now_update_time, const float imu_m_now_gyro[3],
    const float imu_m_now_acc[3],
    matlab_ESKF_process_variables_t *ESKF_process_variables, float dt);

extern void
system_state_push(const matlab_system_physical_state_t *system_physical_state,
                  const matlab_imu_m_now_t *imu_m_now,
                  matlab_ESKF_process_variables_t *ESKF_process_variables,
                  float dt);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for system_state_push.h
 *
 * [EOF]
 */
