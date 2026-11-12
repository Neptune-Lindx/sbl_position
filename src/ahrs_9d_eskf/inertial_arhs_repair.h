/*
 * File: inertial_arhs_repair.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef INERTIAL_ARHS_REPAIR_H
#define INERTIAL_ARHS_REPAIR_H

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
inertial_arhs_repair(matlab_ESKF_process_variables_t *ESKF_process_variables,
                     short k);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for inertial_arhs_repair.h
 *
 * [EOF]
 */
