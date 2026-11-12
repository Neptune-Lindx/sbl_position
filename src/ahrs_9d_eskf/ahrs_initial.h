/*
 * File: ahrs_initial.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef AHRS_INITIAL_H
#define AHRS_INITIAL_H

/* Include Files */
#include "ahrs_9d_eskf_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
ahrs_initial(matlab_ESKF_process_variables_t *ESKF_process_variables,
             const matlab_ESKF_obs_variables_t *ESKF_observation_variables,
             matlab_system_physical_state_t *system_physical_state,
             const matlab_imu_m_now_t *imu_m_now,
             const matlab_ESKF_config_t *ESKF_config, float dt);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ahrs_initial.h
 *
 * [EOF]
 */
