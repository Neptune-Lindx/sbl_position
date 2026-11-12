/*
 * File: reset_state_by_yaw_obs.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef RESET_STATE_BY_YAW_OBS_H
#define RESET_STATE_BY_YAW_OBS_H

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
reset_state_by_yaw_obs(float yaw_obs,
                       matlab_system_physical_state_t *system_physical_state,
                       matlab_ESKF_process_variables_t *ESKF_process_variables);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for reset_state_by_yaw_obs.h
 *
 * [EOF]
 */
