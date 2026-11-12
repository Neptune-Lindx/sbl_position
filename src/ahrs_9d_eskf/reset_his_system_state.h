/*
 * File: reset_his_system_state.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef RESET_HIS_SYSTEM_STATE_H
#define RESET_HIS_SYSTEM_STATE_H

/* Include Files */
#include "ahrs_9d_eskf_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void reset_his_system_state(
    const matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for reset_his_system_state.h
 *
 * [EOF]
 */
