/*
 * File: acc_correct.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef ACC_CORRECT_H
#define ACC_CORRECT_H

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
acc_correct(const matlab_system_physical_state_t *system_physical_state,
            matlab_ESKF_process_variables_t *ESKF_process_variables,
            matlab_ESKF_obs_variables_t *ESKF_observation_variables,
            const matlab_ESKF_config_t *ESKF_config,
            unsigned long long update_time, const float acc[3],
            const float att_obs_noise[2], unsigned char enable_update_Pk1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for acc_correct.h
 *
 * [EOF]
 */
