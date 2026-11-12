/*
 * File: ESKF_integrated_acc.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef ESKF_INTEGRATED_ACC_H
#define ESKF_INTEGRATED_ACC_H

/* Include Files */
#include "ahrs_9d_eskf_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern short
ESKF_integrated_acc(matlab_ESKF_process_variables_t *ESKF_process_variables,
                    matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                    const float Z[2], short syn_index,
                    unsigned char enable_update_Pk1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ESKF_integrated_acc.h
 *
 * [EOF]
 */
