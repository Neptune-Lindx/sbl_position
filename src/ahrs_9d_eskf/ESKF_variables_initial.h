/*
 * File: ESKF_variables_initial.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef ESKF_VARIABLES_INITIAL_H
#define ESKF_VARIABLES_INITIAL_H

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
ESKF_variables_initial(matlab_ESKF_process_variables_t *ESKF_process_variables,
                       matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                       const matlab_ESKF_config_t *ESKF_config);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ESKF_variables_initial.h
 *
 * [EOF]
 */
