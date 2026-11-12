/*
 * File: _coder_ahrs_9d_eskf_api.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef _CODER_AHRS_9D_ESKF_API_H
#define _CODER_AHRS_9D_ESKF_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_matlab_ESKF_config_t
#define typedef_matlab_ESKF_config_t
typedef struct {
  real32_T software_version;
  real32_T gyro_full_range;
  real32_T acc_full_range;
  real32_T gyro_bias_noise[3];
  real32_T angle_rand_walk[3];
  real32_T rp_obs_noise[2];
  real32_T mag_noise;
} matlab_ESKF_config_t;
#endif /* typedef_matlab_ESKF_config_t */

#ifndef typedef_matlab_imu_m_now_t
#define typedef_matlab_imu_m_now_t
typedef struct {
  uint64_T update_time;
  real32_T gyro[3];
  real32_T acc[3];
} matlab_imu_m_now_t;
#endif /* typedef_matlab_imu_m_now_t */

#ifndef typedef_matlab_system_physical_state_t
#define typedef_matlab_system_physical_state_t
typedef struct {
  uint64_T time;
  real32_T euler[3];
  real32_T cbn[9];
  real32_T q[4];
  real32_T bias_gyro[3];
  real32_T gyro[3];
  real32_T acc[3];
  uint8_T acc_correct_flag;
  uint8_T initial_alignment_flag;
  uint64_T last_integret_time;
  real32_T del_att_integret[3];
  uint64_T ins_heart_beat;
  uint64_T correct_heart_beat;
} matlab_system_physical_state_t;
#endif /* typedef_matlab_system_physical_state_t */

#ifndef typedef_matlab_his_physical_state_t
#define typedef_matlab_his_physical_state_t
typedef struct {
  uint64_T time;
  real32_T cbn[9];
  real32_T q[4];
  real32_T gyro[3];
  real32_T dt;
  real32_T F1;
  real32_T F3[9];
  real32_T bias_gyro[3];
  uint8_T correct_flag;
  real32_T gyro_raw[3];
  real32_T acc_raw[3];
} matlab_his_physical_state_t;
#endif /* typedef_matlab_his_physical_state_t */

#ifndef typedef_matlab_ESKF_process_variables_t
#define typedef_matlab_ESKF_process_variables_t
typedef struct {
  real32_T Q[36];
  real32_T P[36];
  int16_T his_in;
  matlab_his_physical_state_t his_physical_state[20];
  real32_T Xk[6];
  int16_T correction_count;
} matlab_ESKF_process_variables_t;
#endif /* typedef_matlab_ESKF_process_variables_t */

#ifndef typedef_matlab_obs_his_obs_accel_t
#define typedef_matlab_obs_his_obs_accel_t
typedef struct {
  int16_T index;
  uint64_T time;
  real32_T Z[2];
  real32_T R[4];
} matlab_obs_his_obs_accel_t;
#endif /* typedef_matlab_obs_his_obs_accel_t */

#ifndef typedef_matlab_obs_his_obs_t
#define typedef_matlab_obs_his_obs_t
typedef struct {
  matlab_obs_his_obs_accel_t Accel;
} matlab_obs_his_obs_t;
#endif /* typedef_matlab_obs_his_obs_t */

#ifndef typedef_matlab_obs_accel_t
#define typedef_matlab_obs_accel_t
typedef struct {
  int16_T his_obs_index;
  real32_T H[12];
  real32_T K[12];
  real32_T R[4];
  real32_T Z[2];
} matlab_obs_accel_t;
#endif /* typedef_matlab_obs_accel_t */

#ifndef typedef_matlab_ESKF_obs_variables_t
#define typedef_matlab_ESKF_obs_variables_t
typedef struct {
  matlab_obs_his_obs_t his_obs[2];
  matlab_obs_accel_t Accel;
  real32_T Xk[6];
  real32_T P[36];
} matlab_ESKF_obs_variables_t;
#endif /* typedef_matlab_ESKF_obs_variables_t */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int16_T
ESKF_integrated_acc(matlab_ESKF_process_variables_t *ESKF_process_variables,
                    matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                    real32_T Z[2], int16_T syn_index,
                    uint8_T enable_update_Pk1);

void ESKF_integrated_acc_api(const mxArray *const prhs[5], int32_T nlhs,
                             const mxArray *plhs[3]);

void ESKF_variables_initial(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_ESKF_obs_variables_t *ESKF_observation_variables,
    matlab_ESKF_config_t *ESKF_config);

void ESKF_variables_initial_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[3]);

void acc_correct(matlab_system_physical_state_t *system_physical_state,
                 matlab_ESKF_process_variables_t *ESKF_process_variables,
                 matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                 matlab_ESKF_config_t *ESKF_config, uint64_T update_time,
                 real32_T acc[3], real32_T att_obs_noise[2],
                 uint8_T enable_update_Pk1);

void acc_correct_api(const mxArray *const prhs[8], int32_T nlhs,
                     const mxArray *plhs[4]);

void ahrs_9d_eskf_atexit(void);

void ahrs_9d_eskf_initialize(void);

void ahrs_9d_eskf_terminate(void);

void ahrs_9d_eskf_xil_shutdown(void);

void ahrs_9d_eskf_xil_terminate(void);

void ahrs_initial(matlab_ESKF_process_variables_t *ESKF_process_variables,
                  matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                  matlab_system_physical_state_t *system_physical_state,
                  matlab_imu_m_now_t *imu_m_now,
                  matlab_ESKF_config_t *ESKF_config, real32_T dt);

void ahrs_initial_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[4]);

void cbn2euler(real32_T cbn[9], real32_T *pitch, real32_T *roll, real32_T *yaw);

void cbn2euler_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

void cbn2quaternion(real32_T cbn[9], real32_T q[4]);

void cbn2quaternion_api(const mxArray *prhs, const mxArray **plhs);

void euler2cbn(real32_T pitch, real32_T roll, real32_T yaw, real32_T cbn[9]);

void euler2cbn_api(const mxArray *const prhs[3], const mxArray **plhs);

void feedback_correction(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_his_physical_state_t *system_physical_state);

void feedback_correction_api(const mxArray *const prhs[2], int32_T nlhs,
                             const mxArray *plhs[2]);

void get_his_physical_state(
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_ESKF_config_t *ESKF_config, uint64_T gnss_time, real32_T cbn[9],
    real32_T gyro[3], uint64_T *syn_time, int16_T *syn_index);

void get_his_physical_state_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[6]);

void inertial_ahrs_update(
    matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables,
    matlab_imu_m_now_t *imu_m_now, real32_T dt,
    matlab_ESKF_config_t *ESKF_config);

void inertial_ahrs_update_api(const mxArray *const prhs[5], int32_T nlhs,
                              const mxArray *plhs[3]);

void inertial_arhs_repair(
    matlab_ESKF_process_variables_t *ESKF_process_variables, int16_T k);

void inertial_arhs_repair_api(const mxArray *const prhs[2],
                              const mxArray **plhs);

void load_ESKF_config(matlab_system_physical_state_t *system_physical_state,
                      matlab_ESKF_config_t *ESKF_config);

void load_ESKF_config_api(const mxArray *const prhs[2], int32_T nlhs,
                          const mxArray *plhs[2]);

void physical_state_initial(
    matlab_system_physical_state_t *system_physical_state);

void physical_state_initial_api(const mxArray *prhs, const mxArray **plhs);

void quaternion2cbn(real32_T q[4], real32_T cbn[9]);

void quaternion2cbn_api(const mxArray *prhs, const mxArray **plhs);

void quaternion_normalize(real32_T q[4]);

void quaternion_normalize_api(const mxArray *prhs, const mxArray **plhs);

real32_T radians_conv_np_pi(real32_T radians_in);

void radians_conv_np_pi_api(const mxArray *prhs, const mxArray **plhs);

void reset_his_system_state(
    matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables);

void reset_his_system_state_api(const mxArray *const prhs[2], int32_T nlhs,
                                const mxArray *plhs[2]);

void reset_physical_state(
    matlab_system_physical_state_t *system_physical_state);

void reset_physical_state_api(const mxArray *prhs, const mxArray **plhs);

void reset_state_by_yaw_obs(
    real32_T yaw_obs, matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_process_variables_t *ESKF_process_variables);

void reset_state_by_yaw_obs_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[2]);

void robust_igg3_inflate_R(real32_T Z[2], real32_T P11, real32_T P22,
                           real32_T R_in[4], real32_T R_out[4]);

void robust_igg3_inflate_R_api(const mxArray *const prhs[4],
                               const mxArray **plhs);

void skew_symmetric(real32_T a[3], real32_T a_hat[9]);

void skew_symmetric_api(const mxArray *prhs, const mxArray **plhs);

void so3_exp(real32_T a[3], real32_T R[9]);

void so3_exp_api(const mxArray *prhs, const mxArray **plhs);

void system_state_push(matlab_system_physical_state_t *system_physical_state,
                       matlab_imu_m_now_t *imu_m_now,
                       matlab_ESKF_process_variables_t *ESKF_process_variables,
                       real32_T dt);

void system_state_push_api(const mxArray *const prhs[4], int32_T nlhs,
                           const mxArray *plhs[2]);

void update_quaternion(real32_T q[4], real32_T gyro[3]);

void update_quaternion_api(const mxArray *const prhs[2], const mxArray **plhs);

real32_T yaw_bias_est(real32_T yaw_bias_body[3], real32_T yaw_bias_last,
                      real32_T yaw_obs, real32_T last_yaw_obs, real32_T yaw_imu,
                      real32_T last_yaw_imu, uint64_T time_now,
                      uint64_T time_last,
                      matlab_system_physical_state_t *system_physical_state);

void yaw_bias_est_api(const mxArray *const prhs[9], int32_T nlhs,
                      const mxArray *plhs[2]);

void yaw_correct(matlab_system_physical_state_t *system_physical_state,
                 matlab_ESKF_process_variables_t *ESKF_process_variables,
                 matlab_ESKF_obs_variables_t *ESKF_observation_variables,
                 matlab_ESKF_config_t *ESKF_config, uint64_T update_time,
                 real32_T yaw_obs, real32_T yaw_obs_var,
                 uint8_T *yaw_align_flag);

void yaw_correct_api(const mxArray *const prhs[8], int32_T nlhs,
                     const mxArray *plhs[4]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_ahrs_9d_eskf_api.h
 *
 * [EOF]
 */
