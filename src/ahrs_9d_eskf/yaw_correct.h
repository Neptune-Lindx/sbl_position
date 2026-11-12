/*
 * File: yaw_correct.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef YAW_CORRECT_H
#define YAW_CORRECT_H

/* Include Files */
#include "ahrs_9d_eskf_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void yaw_correct(matlab_system_physical_state_t *system_physical_state,
                        matlab_ESKF_process_variables_t *ESKF_process_variables,
                        matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                        const matlab_ESKF_config_t *ESKF_config,
                        unsigned long long update_time, float yaw_obs,
                        float yaw_obs_var, unsigned char *yaw_align_flag);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for yaw_correct.h
 *
 * [EOF]
 */
