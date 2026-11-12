/*
 * File: ahrs_9d_eskf_types.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

#ifndef AHRS_9D_ESKF_TYPES_H
#define AHRS_9D_ESKF_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_matlab_ESKF_config_t
#define typedef_matlab_ESKF_config_t
typedef struct {
  float software_version;
  float gyro_full_range;
  float acc_full_range;
  float gyro_bias_noise[3];
  float angle_rand_walk[3];
  float rp_obs_noise[2];
  float mag_noise;
} matlab_ESKF_config_t;
#endif /* typedef_matlab_ESKF_config_t */

#ifndef typedef_matlab_imu_m_now_t
#define typedef_matlab_imu_m_now_t
typedef struct {
  unsigned long long update_time;
  float gyro[3];
  float acc[3];
} matlab_imu_m_now_t;
#endif /* typedef_matlab_imu_m_now_t */

#ifndef typedef_matlab_system_physical_state_t
#define typedef_matlab_system_physical_state_t
typedef struct {
  unsigned long long time;
  float euler[3];
  float cbn[9];
  float q[4];
  float bias_gyro[3];
  float gyro[3];
  float acc[3];
  unsigned char acc_correct_flag;
  unsigned char initial_alignment_flag;
  unsigned long long last_integret_time;
  float del_att_integret[3];
  unsigned long long ins_heart_beat;
  unsigned long long correct_heart_beat;
} matlab_system_physical_state_t;
#endif /* typedef_matlab_system_physical_state_t */

#ifndef typedef_matlab_his_physical_state_t
#define typedef_matlab_his_physical_state_t
typedef struct {
  unsigned long long time;
  float cbn[9];
  float q[4];
  float gyro[3];
  float dt;
  float F1;
  float F3[9];
  float bias_gyro[3];
  unsigned char correct_flag;
  float gyro_raw[3];
  float acc_raw[3];
} matlab_his_physical_state_t;
#endif /* typedef_matlab_his_physical_state_t */

#ifndef typedef_matlab_ESKF_process_variables_t
#define typedef_matlab_ESKF_process_variables_t
typedef struct {
  float Q[36];
  float P[36];
  short his_in;
  matlab_his_physical_state_t his_physical_state[20];
  float Xk[6];
  short correction_count;
} matlab_ESKF_process_variables_t;
#endif /* typedef_matlab_ESKF_process_variables_t */

#ifndef typedef_matlab_obs_his_obs_accel_t
#define typedef_matlab_obs_his_obs_accel_t
typedef struct {
  short index;
  unsigned long long time;
  float Z[2];
  float R[4];
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
  short his_obs_index;
  float H[12];
  float K[12];
  float R[4];
  float Z[2];
} matlab_obs_accel_t;
#endif /* typedef_matlab_obs_accel_t */

#ifndef typedef_matlab_ESKF_obs_variables_t
#define typedef_matlab_ESKF_obs_variables_t
typedef struct {
  matlab_obs_his_obs_t his_obs[2];
  matlab_obs_accel_t Accel;
  float Xk[6];
  float P[36];
} matlab_ESKF_obs_variables_t;
#endif /* typedef_matlab_ESKF_obs_variables_t */

#endif
/*
 * File trailer for ahrs_9d_eskf_types.h
 *
 * [EOF]
 */
