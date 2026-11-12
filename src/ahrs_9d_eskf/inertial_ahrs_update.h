/*
 * File: inertial_ahrs_update.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef INERTIAL_AHRS_UPDATE_H
#define INERTIAL_AHRS_UPDATE_H

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
inertial_ahrs_update(matlab_system_physical_state_t *system_physical_state,
                     matlab_ESKF_process_variables_t *ESKF_process_variables,
                     const matlab_imu_m_now_t *imu_m_now, float dt,
                     const matlab_ESKF_config_t *ESKF_config);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for inertial_ahrs_update.h
 *
 * [EOF]
 */
