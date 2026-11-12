/*
 * File: load_ESKF_config.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "load_ESKF_config.h"
#include "ahrs_9d_eskf_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const matlab_system_physical_state_t *system_physical_state
 *                matlab_ESKF_config_t *ESKF_config
 * Return Type  : void
 */
void load_ESKF_config(
    const matlab_system_physical_state_t *system_physical_state,
    matlab_ESKF_config_t *ESKF_config)
{
  (void)system_physical_state;
  ESKF_config->software_version = 4.08F;
  /*  ESKF_config.software_version='v4.0.07.11172025_alpha'; */
  /*  ESKF_config.discription='fuse baro +gnss vertical speed'; */
  /*  ESKF_config.latest_edited='2025-11-17 18:00'; */
  ESKF_config->gyro_full_range = 2000.0F;
  ESKF_config->acc_full_range = 156.96F;
  /*  水平零偏过程噪声保持 1e-6。天向略加大，让 1 Hz
   * 航向在起始几秒把天向零偏学出来。 */
  ESKF_config->gyro_bias_noise[0] = 1.0E-6F;
  ESKF_config->angle_rand_walk[0] = 1.5E-5F;
  ESKF_config->gyro_bias_noise[1] = 1.0E-6F;
  ESKF_config->angle_rand_walk[1] = 1.5E-5F;
  ESKF_config->gyro_bias_noise[2] = 2.0E-6F;
  ESKF_config->angle_rand_walk[2] = 1.5E-5F;
  ESKF_config->rp_obs_noise[0] = 0.0304617416F;
  ESKF_config->rp_obs_noise[1] = 0.0304617416F;
  /*  1 Hz 航向观测标准差 0.5°。原先 2° 时起始航向每秒只拉回一半，前 8 s
   * 误差约 2.3°。 */
  ESKF_config->mag_noise = 7.61543561E-5F;
}

/*
 * File trailer for load_ESKF_config.c
 *
 * [EOF]
 */
