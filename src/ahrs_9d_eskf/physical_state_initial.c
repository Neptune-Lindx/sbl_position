/*
 * File: physical_state_initial.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "physical_state_initial.h"
#include "ahrs_9d_eskf_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : matlab_system_physical_state_t *system_physical_state
 * Return Type  : void
 */
void physical_state_initial(
    matlab_system_physical_state_t *system_physical_state)
{
  int i;
  signed char b_I[9];
  system_physical_state->time = 0ULL;
  system_physical_state->euler[0] = 0.0F;
  system_physical_state->euler[1] = 0.0F;
  system_physical_state->euler[2] = 0.0F;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (i = 0; i < 9; i++) {
    system_physical_state->cbn[i] = b_I[i];
  }
  system_physical_state->q[0] = 1.0F;
  system_physical_state->q[1] = 0.0F;
  system_physical_state->q[2] = 0.0F;
  system_physical_state->q[3] = 0.0F;
  system_physical_state->acc_correct_flag = 0U;
  system_physical_state->initial_alignment_flag = 0U;
  system_physical_state->last_integret_time = 0ULL;
  system_physical_state->bias_gyro[0] = 0.0F;
  system_physical_state->gyro[0] = 0.0F;
  system_physical_state->acc[0] = 0.0F;
  system_physical_state->del_att_integret[0] = 0.0F;
  system_physical_state->bias_gyro[1] = 0.0F;
  system_physical_state->gyro[1] = 0.0F;
  system_physical_state->acc[1] = 0.0F;
  system_physical_state->del_att_integret[1] = 0.0F;
  system_physical_state->bias_gyro[2] = 0.0F;
  system_physical_state->gyro[2] = 0.0F;
  system_physical_state->acc[2] = 9.81F;
  system_physical_state->del_att_integret[2] = 0.0F;
  system_physical_state->ins_heart_beat = 0ULL;
  system_physical_state->correct_heart_beat = 0ULL;
}

/*
 * File trailer for physical_state_initial.c
 *
 * [EOF]
 */
