/*
 * File: _coder_ahrs_9d_eskf_mex.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef _CODER_AHRS_9D_ESKF_MEX_H
#define _CODER_AHRS_9D_ESKF_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_ESKF_integrated_acc_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                            int32_T nrhs,
                                            const mxArray *prhs[5]);

void unsafe_ESKF_variables_initial_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                               int32_T nrhs,
                                               const mxArray *prhs[3]);

void unsafe_acc_correct_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                    int32_T nrhs, const mxArray *prhs[8]);

void unsafe_ahrs_initial_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                     int32_T nrhs, const mxArray *prhs[6]);

void unsafe_cbn2euler_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                  const mxArray *prhs[1]);

void unsafe_cbn2quaternion_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                       int32_T nrhs, const mxArray *prhs[1]);

void unsafe_euler2cbn_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[3]);

void unsafe_feedback_correction_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                            int32_T nrhs,
                                            const mxArray *prhs[2]);

void unsafe_get_his_physical_state_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                               int32_T nrhs,
                                               const mxArray *prhs[3]);

void unsafe_inertial_ahrs_update_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                             int32_T nrhs,
                                             const mxArray *prhs[5]);

void unsafe_inertial_arhs_repair_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                             int32_T nrhs,
                                             const mxArray *prhs[2]);

void unsafe_load_ESKF_config_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                         int32_T nrhs, const mxArray *prhs[2]);

void unsafe_physical_state_initial_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                               int32_T nrhs,
                                               const mxArray *prhs[1]);

void unsafe_quaternion2cbn_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                       int32_T nrhs, const mxArray *prhs[1]);

void unsafe_quaternion_normalize_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                             int32_T nrhs,
                                             const mxArray *prhs[1]);

void unsafe_radians_conv_np_pi_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[1]);

void unsafe_reset_his_system_state_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                               int32_T nrhs,
                                               const mxArray *prhs[2]);

void unsafe_reset_physical_state_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                             int32_T nrhs,
                                             const mxArray *prhs[1]);

void unsafe_reset_state_by_yaw_obs_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                               int32_T nrhs,
                                               const mxArray *prhs[3]);

void unsafe_robust_igg3_inflate_R_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                              int32_T nrhs,
                                              const mxArray *prhs[4]);

void unsafe_skew_symmetric_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                       int32_T nrhs, const mxArray *prhs[1]);

void unsafe_so3_exp_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                const mxArray *prhs[1]);

void unsafe_system_state_push_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                          int32_T nrhs, const mxArray *prhs[4]);

void unsafe_update_quaternion_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[2]);

void unsafe_yaw_bias_est_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                     int32_T nrhs, const mxArray *prhs[9]);

void unsafe_yaw_correct_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                    int32_T nrhs, const mxArray *prhs[8]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_ahrs_9d_eskf_mex.h
 *
 * [EOF]
 */
