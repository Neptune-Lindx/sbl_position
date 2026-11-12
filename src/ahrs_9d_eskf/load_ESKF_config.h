/*
 * File: load_ESKF_config.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef LOAD_ESKF_CONFIG_H
#define LOAD_ESKF_CONFIG_H

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
load_ESKF_config(const matlab_system_physical_state_t *system_physical_state,
                 matlab_ESKF_config_t *ESKF_config);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for load_ESKF_config.h
 *
 * [EOF]
 */
