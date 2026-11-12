/*
 * File: ESKF_integrated_acc.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "ESKF_integrated_acc.h"
#include "ahrs_9d_eskf_data.h"
#include "ahrs_9d_eskf_types.h"
#include "inv.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : matlab_ESKF_process_variables_t *ESKF_process_variables
 *                matlab_ESKF_obs_variables_t *ESKF_observation_variables
 *                const float Z[2]
 *                short syn_index
 *                unsigned char enable_update_Pk1
 * Return Type  : short
 */
short ESKF_integrated_acc(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_ESKF_obs_variables_t *ESKF_observation_variables, const float Z[2],
    short syn_index, unsigned char enable_update_Pk1)
{
  float F[36];
  float b_F[36];
  float b_ESKF_observation_variables[12];
  float y_tmp[12];
  float b_fv[4];
  float c_ESKF_observation_variables[4];
  float f;
  float f1;
  int F_tmp;
  int i;
  int i1;
  int i2;
  signed char b_I[36];
  if (enable_update_Pk1 == 1) {
    short last_index;
    for (i = 0; i < 36; i++) {
      F[i] = iv[i];
    }
    for (i = 0; i < 3; i++) {
      F_tmp = 6 * (i + 3);
      F[F_tmp] =
          ESKF_process_variables->his_physical_state[syn_index - 1].F3[3 * i];
      F[F_tmp + 1] = ESKF_process_variables->his_physical_state[syn_index - 1]
                         .F3[3 * i + 1];
      F[F_tmp + 2] = ESKF_process_variables->his_physical_state[syn_index - 1]
                         .F3[3 * i + 2];
    }
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        f = 0.0F;
        for (i2 = 0; i2 < 6; i2++) {
          f += F[i + 6 * i2] * ESKF_process_variables->P[i2 + 6 * i1];
        }
        b_F[i + 6 * i1] = f;
      }
      for (i1 = 0; i1 < 6; i1++) {
        f = 0.0F;
        for (i2 = 0; i2 < 6; i2++) {
          f += b_F[i + 6 * i2] * F[i1 + 6 * i2];
        }
        i2 = i + 6 * i1;
        ESKF_observation_variables->P[i2] =
            f +
            ESKF_process_variables->Q[i2] *
                ESKF_process_variables->his_physical_state[syn_index - 1].F1;
      }
    }
    last_index = (short)(syn_index - 1);
    if ((short)(syn_index - 1) == 0) {
      last_index = 20;
    }
    ESKF_process_variables->his_physical_state[last_index - 1].F1 = 0.0F;
    for (i = 0; i < 9; i++) {
      ESKF_process_variables->his_physical_state[last_index - 1].F3[i] = 0.0F;
    }
  }
  /*  ESKF_observation_variables.K =
   * ESKF_observation_variables.P*ESKF_observation_variables.H'/(ESKF_observation_variables.H*ESKF_observation_variables.P*ESKF_observation_variables.H'+ESKF_observation_variables.R);
   */
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      F_tmp = i + (i1 << 1);
      y_tmp[i1 + 6 * i] = ESKF_observation_variables->Accel.H[F_tmp];
      f = 0.0F;
      for (i2 = 0; i2 < 6; i2++) {
        f += ESKF_observation_variables->Accel.H[i + (i2 << 1)] *
             ESKF_observation_variables->P[i2 + 6 * i1];
      }
      b_ESKF_observation_variables[F_tmp] = f;
    }
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 2; i1++) {
      f = 0.0F;
      for (i2 = 0; i2 < 6; i2++) {
        f += b_ESKF_observation_variables[i + (i2 << 1)] * y_tmp[i2 + 6 * i1];
      }
      F_tmp = i + (i1 << 1);
      c_ESKF_observation_variables[F_tmp] =
          f + ESKF_observation_variables->Accel.R[F_tmp];
    }
  }
  inv(c_ESKF_observation_variables, b_fv);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 2; i1++) {
      f = 0.0F;
      for (i2 = 0; i2 < 6; i2++) {
        f += ESKF_observation_variables->P[i + 6 * i2] * y_tmp[i2 + 6 * i1];
      }
      b_ESKF_observation_variables[i + 6 * i1] = f;
    }
    f = b_ESKF_observation_variables[i + 6];
    f1 = b_ESKF_observation_variables[i];
    ESKF_observation_variables->Accel.K[i] = f1 * b_fv[0] + f * b_fv[1];
    ESKF_observation_variables->Accel.K[i + 6] = f1 * b_fv[2] + f * b_fv[3];
  }
  for (i = 0; i < 36; i++) {
    b_I[i] = 0;
  }
  for (F_tmp = 0; F_tmp < 6; F_tmp++) {
    b_I[F_tmp + 6 * F_tmp] = 1;
  }
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i1 << 1;
      F_tmp = i + 6 * i1;
      F[F_tmp] =
          (float)b_I[F_tmp] - (ESKF_observation_variables->Accel.K[i] *
                                   ESKF_observation_variables->Accel.H[i2] +
                               ESKF_observation_variables->Accel.K[i + 6] *
                                   ESKF_observation_variables->Accel.H[i2 + 1]);
    }
    for (i1 = 0; i1 < 6; i1++) {
      f = 0.0F;
      for (i2 = 0; i2 < 6; i2++) {
        f += F[i + 6 * i2] * ESKF_observation_variables->P[i2 + 6 * i1];
      }
      b_F[i + 6 * i1] = f;
    }
  }
  memcpy(&ESKF_observation_variables->P[0], &b_F[0], 36U * sizeof(float));
  f = Z[0];
  f1 = Z[1];
  for (i = 0; i < 6; i++) {
    ESKF_observation_variables->Xk[i] =
        ESKF_observation_variables->Accel.K[i] * f +
        ESKF_observation_variables->Accel.K[i + 6] * f1;
  }
  return 1;
}

/*
 * File trailer for ESKF_integrated_acc.c
 *
 * [EOF]
 */
