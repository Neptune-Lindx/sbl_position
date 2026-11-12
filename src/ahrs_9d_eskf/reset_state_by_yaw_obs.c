/*
 * File: reset_state_by_yaw_obs.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "reset_state_by_yaw_obs.h"
#include "ahrs_9d_eskf_types.h"
#include "cbn2quaternion.h"
#include "euler2cbn.h"
#include "reset_his_system_state.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float yaw_obs
 *                matlab_system_physical_state_t *system_physical_state
 *                matlab_ESKF_process_variables_t *ESKF_process_variables
 * Return Type  : void
 */
void reset_state_by_yaw_obs(
    float yaw_obs, matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables)
{
  /* 用yaw_obs直接复位状态估计值 */
  system_physical_state->euler[2] = yaw_obs;
  euler2cbn(system_physical_state->euler[0], system_physical_state->euler[1],
            yaw_obs, system_physical_state->cbn);
  cbn2quaternion(system_physical_state->cbn, system_physical_state->q);
  reset_his_system_state(system_physical_state, ESKF_process_variables);
}

/*
 * File trailer for reset_state_by_yaw_obs.c
 *
 * [EOF]
 */
