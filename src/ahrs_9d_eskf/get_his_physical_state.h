/*
 * File: get_his_physical_state.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef GET_HIS_PHYSICAL_STATE_H
#define GET_HIS_PHYSICAL_STATE_H

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
get_his_physical_state(matlab_ESKF_process_variables_t *ESKF_process_variables,
                       const matlab_ESKF_config_t *ESKF_config,
                       unsigned long long gnss_time, float cbn[9],
                       float gyro[3], unsigned long long *syn_time,
                       short *syn_index);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for get_his_physical_state.h
 *
 * [EOF]
 */
