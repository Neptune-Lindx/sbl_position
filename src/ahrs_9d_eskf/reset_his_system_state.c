/*
 * File: reset_his_system_state.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "reset_his_system_state.h"
#include "ahrs_9d_eskf_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const matlab_system_physical_state_t *system_physical_state
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 * Return Type  : void
 */
void reset_his_system_state(
    const matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables)
{
  int b_i;
  int i;
  for (i = 0; i < 20; i++) {
    if (ESKF_process_variables->his_physical_state[i].time != 0ULL) {
      for (b_i = 0; b_i < 9; b_i++) {
        ESKF_process_variables->his_physical_state[i].cbn[b_i] =
            system_physical_state->cbn[b_i];
      }
      ESKF_process_variables->his_physical_state[i].q[0] =
          system_physical_state->q[0];
      ESKF_process_variables->his_physical_state[i].q[1] =
          system_physical_state->q[1];
      ESKF_process_variables->his_physical_state[i].q[2] =
          system_physical_state->q[2];
      ESKF_process_variables->his_physical_state[i].q[3] =
          system_physical_state->q[3];
    }
  }
}

/*
 * File trailer for reset_his_system_state.c
 *
 * [EOF]
 */
