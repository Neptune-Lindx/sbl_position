/*
 * File: feedback_correction.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef FEEDBACK_CORRECTION_H
#define FEEDBACK_CORRECTION_H

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
feedback_correction(matlab_ESKF_process_variables_t *ESKF_process_variables,
                    matlab_his_physical_state_t *system_physical_state);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for feedback_correction.h
 *
 * [EOF]
 */
