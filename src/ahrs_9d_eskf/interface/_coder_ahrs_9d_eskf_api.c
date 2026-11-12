/*
 * File: _coder_ahrs_9d_eskf_api.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "_coder_ahrs_9d_eskf_api.h"
#include "_coder_ahrs_9d_eskf_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "ahrs_9d_eskf",                                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

static const char_T *sv[11] = {
    "time",      "cbn",          "q",        "gyro",   "dt", "F1", "F3",
    "bias_gyro", "correct_flag", "gyro_raw", "acc_raw"};

static const char_T *sv1[11] = {
    "time",      "cbn",          "q",        "gyro",   "dt", "F1", "F3",
    "bias_gyro", "correct_flag", "gyro_raw", "acc_raw"};

/* Function Declarations */
static uint64_T ab_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier);

static real32_T ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_system_physical_state_t *y);

static const mxArray *b_emlrt_marshallOut(const real32_T u[36]);

static real32_T (*bb_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[3];

static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[6]);

static uint64_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static const mxArray *c_emlrt_marshallOut(const int16_T u);

static real32_T (*cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[3];

static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[2]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[3]);

static const mxArray *d_emlrt_marshallOut(const uint64_T u);

static real32_T (*db_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[2];

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[4]);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[9]);

static const mxArray *e_emlrt_marshallOut(const real32_T u[9]);

static real32_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[2];

static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[12]);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier,
                             matlab_system_physical_state_t *y);

static const mxArray *
emlrt_marshallOut(const matlab_ESKF_process_variables_t *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[4]);

static const mxArray *f_emlrt_marshallOut(const real32_T u);

static uint8_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier);

static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[12]);

static uint8_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static const mxArray *g_emlrt_marshallOut(const uint8_T u);

static matlab_imu_m_now_t gb_emlrt_marshallIn(const emlrtStack *sp,
                                              const mxArray *nullptr,
                                              const char_T *identifier);

static real32_T (*gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[3];

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               matlab_ESKF_process_variables_t *y);

static const mxArray *h_emlrt_marshallOut(const matlab_ESKF_obs_variables_t *u);

static matlab_imu_m_now_t
hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                    const emlrtMsgIdentifier *parentId);

static real32_T (*hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[2];

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_ESKF_process_variables_t *y);

static const mxArray *i_emlrt_marshallOut(const real32_T u[4]);

static real32_T ib_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier);

static real32_T (*ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[9];

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[36]);

static const mxArray *
j_emlrt_marshallOut(const matlab_system_physical_state_t *u);

static real32_T (*jb_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[9];

static real32_T (*jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[4];

static int16_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static const mxArray *k_emlrt_marshallOut(const matlab_ESKF_config_t u);

static real32_T (*kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[9];

static real32_T (*kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[4];

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_his_physical_state_t y[20]);

static const mxArray *l_emlrt_marshallOut(const real32_T u[4]);

static int16_T lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier);

static real32_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static const mxArray *m_emlrt_marshallOut(const real32_T u[9]);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier,
                                matlab_his_physical_state_t *y);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[6]);

static const mxArray *n_emlrt_marshallOut(const matlab_his_physical_state_t *u);

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                matlab_his_physical_state_t *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               matlab_ESKF_obs_variables_t *y);

static const mxArray *o_emlrt_marshallOut(const real32_T u[3]);

static real32_T (*ob_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[4];

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_ESKF_obs_variables_t *y);

static void p_emlrt_marshallOut(const real32_T u[4], const mxArray *y);

static real32_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[4];

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_obs_his_obs_t y[2]);

static const mxArray *q_emlrt_marshallOut(const real32_T u[4]);

static real32_T (*qb_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[4];

static matlab_obs_his_obs_accel_t
r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                   const emlrtMsgIdentifier *parentId);

static void r_emlrt_marshallOut(const real32_T u[3], const mxArray *y);

static real32_T (*rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[4];

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[2]);

static uint64_T sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[4]);

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[3]);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_obs_accel_t *y);

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[9]);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[12]);

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[4]);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[12]);

static uint8_T wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

static matlab_ESKF_config_t x_emlrt_marshallIn(const emlrtStack *sp,
                                               const mxArray *nullptr,
                                               const char_T *identifier);

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[36]);

static matlab_ESKF_config_t
y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                   const emlrtMsgIdentifier *parentId);

static int16_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : uint64_T
 */
static uint64_T ab_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  uint64_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T
 */
static real32_T ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 0U,
                          (const void *)&dims);
  ret = *(real32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_system_physical_state_t *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_system_physical_state_t *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[13] = {"time",
                                         "euler",
                                         "cbn",
                                         "q",
                                         "bias_gyro",
                                         "gyro",
                                         "acc",
                                         "acc_correct_flag",
                                         "initial_alignment_flag",
                                         "last_integret_time",
                                         "del_att_integret",
                                         "ins_heart_beat",
                                         "correct_heart_beat"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 13,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "time";
  y->time = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "time")),
      &thisId);
  thisId.fIdentifier = "euler";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "euler")),
      &thisId, y->euler);
  thisId.fIdentifier = "cbn";
  e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "cbn")),
      &thisId, y->cbn);
  thisId.fIdentifier = "q";
  f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "q")),
      &thisId, y->q);
  thisId.fIdentifier = "bias_gyro";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "bias_gyro")),
      &thisId, y->bias_gyro);
  thisId.fIdentifier = "gyro";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "gyro")),
      &thisId, y->gyro);
  thisId.fIdentifier = "acc";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "acc")),
      &thisId, y->acc);
  thisId.fIdentifier = "acc_correct_flag";
  y->acc_correct_flag =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        7, "acc_correct_flag")),
                         &thisId);
  thisId.fIdentifier = "initial_alignment_flag";
  y->initial_alignment_flag = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8,
                                     "initial_alignment_flag")),
      &thisId);
  thisId.fIdentifier = "last_integret_time";
  y->last_integret_time =
      c_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtConstCTX)sp, u, 0, 9, "last_integret_time")),
                         &thisId);
  thisId.fIdentifier = "del_att_integret";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10,
                                                    "del_att_integret")),
                     &thisId, y->del_att_integret);
  thisId.fIdentifier = "ins_heart_beat";
  y->ins_heart_beat =
      c_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        11, "ins_heart_beat")),
                         &thisId);
  thisId.fIdentifier = "correct_heart_beat";
  y->correct_heart_beat = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 12,
                                     "correct_heart_beat")),
      &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[36]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real32_T u[36])
{
  static const int32_T iv[2] = {6, 6};
  const mxArray *m;
  const mxArray *y;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  real32_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0;
  for (b_i = 0; b_i < 6; b_i++) {
    for (c_i = 0; c_i < 6; c_i++) {
      pData[i + c_i] = u[c_i + 6 * b_i];
    }
    i += 6;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T (*)[3]
 */
static real32_T (*bb_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real32_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[6]
 * Return Type  : void
 */
static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[6])
{
  static const int32_T dims = 6;
  int32_T i;
  real32_T(*r)[6];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                          (const void *)&dims);
  r = (real32_T(*)[6])emlrtMxGetData(src);
  for (i = 0; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint64_T
 */
static uint64_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  uint64_T y;
  y = sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const int16_T u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const int16_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[3]
 */
static real32_T (*cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[3]
{
  real32_T(*y)[3];
  y = gc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[2]
 * Return Type  : void
 */
static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[2])
{
  static const int32_T dims = 2;
  real32_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                          (const void *)&dims);
  r = (real32_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[3]
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[3])
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const uint64_T u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const uint64_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
  *(uint64_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T (*)[2]
 */
static real32_T (*db_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real32_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = eb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[4]
 * Return Type  : void
 */
static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[4])
{
  static const int32_T dims[2] = {2, 2};
  real32_T(*r)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                          (const void *)&dims[0]);
  r = (real32_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[9]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[9])
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const real32_T u[9])
{
  static const int32_T iv[2] = {3, 3};
  const mxArray *m;
  const mxArray *y;
  int32_T b_i;
  int32_T i;
  real32_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    pData[i] = u[3 * b_i];
    pData[i + 1] = u[3 * b_i + 1];
    pData[i + 2] = u[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[2]
 */
static real32_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[2]
{
  real32_T(*y)[2];
  y = hc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[12]
 * Return Type  : void
 */
static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[12])
{
  static const int32_T dims[2] = {2, 6};
  int32_T i;
  real32_T(*r)[12];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                          (const void *)&dims[0]);
  r = (real32_T(*)[12])emlrtMxGetData(src);
  for (i = 0; i < 12; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                matlab_system_physical_state_t *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier,
                             matlab_system_physical_state_t *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const matlab_ESKF_process_variables_t *u
 * Return Type  : const mxArray *
 */
static const mxArray *
emlrt_marshallOut(const matlab_ESKF_process_variables_t *u)
{
  static const int32_T b_i = 6;
  static const int32_T i1 = 4;
  static const int32_T i2 = 3;
  static const int32_T i3 = 3;
  static const int32_T i4 = 3;
  static const int32_T i5 = 3;
  static const char_T *b_sv[6] = {
      "Q", "P", "his_in", "his_physical_state", "Xk", "correction_count"};
  matlab_his_physical_state_t b_u[20];
  const matlab_his_physical_state_t *r;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  real32_T *pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&b_sv[0]));
  emlrtSetFieldR2017b(y, 0, "Q", b_emlrt_marshallOut(u->Q), 0);
  emlrtSetFieldR2017b(y, 0, "P", b_emlrt_marshallOut(u->P), 1);
  emlrtSetFieldR2017b(y, 0, "his_in", c_emlrt_marshallOut(u->his_in), 2);
  memcpy(&b_u[0], &u->his_physical_state[0],
         20U * sizeof(matlab_his_physical_state_t));
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 20;
  emlrtAssign(&b_y,
              emlrtCreateStructArray(2, &iv[0], 11, (const char_T **)&sv1[0]));
  for (i = 0; i < 20; i++) {
    real32_T u_idx_0;
    real32_T u_idx_1;
    real32_T u_idx_2;
    real32_T u_idx_3;
    r = &b_u[i];
    emlrtSetFieldR2017b(b_y, i, "time", d_emlrt_marshallOut(r->time), 0);
    emlrtSetFieldR2017b(b_y, i, "cbn", e_emlrt_marshallOut(r->cbn), 1);
    u_idx_0 = r->q[0];
    u_idx_1 = r->q[1];
    u_idx_2 = r->q[2];
    u_idx_3 = r->q[3];
    d_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i1, mxSINGLE_CLASS, mxREAL);
    pData = (real32_T *)emlrtMxGetData(m);
    pData[0] = u_idx_0;
    pData[1] = u_idx_1;
    pData[2] = u_idx_2;
    pData[3] = u_idx_3;
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(b_y, i, "q", d_y, 2);
    u_idx_0 = r->gyro[0];
    u_idx_1 = r->gyro[1];
    u_idx_2 = r->gyro[2];
    e_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i2, mxSINGLE_CLASS, mxREAL);
    pData = (real32_T *)emlrtMxGetData(m);
    pData[0] = u_idx_0;
    pData[1] = u_idx_1;
    pData[2] = u_idx_2;
    emlrtAssign(&e_y, m);
    emlrtSetFieldR2017b(b_y, i, "gyro", e_y, 3);
    emlrtSetFieldR2017b(b_y, i, "dt", f_emlrt_marshallOut(r->dt), 4);
    emlrtSetFieldR2017b(b_y, i, "F1", f_emlrt_marshallOut(r->F1), 5);
    emlrtSetFieldR2017b(b_y, i, "F3", e_emlrt_marshallOut(r->F3), 6);
    u_idx_0 = r->bias_gyro[0];
    u_idx_1 = r->bias_gyro[1];
    u_idx_2 = r->bias_gyro[2];
    f_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i3, mxSINGLE_CLASS, mxREAL);
    pData = (real32_T *)emlrtMxGetData(m);
    pData[0] = u_idx_0;
    pData[1] = u_idx_1;
    pData[2] = u_idx_2;
    emlrtAssign(&f_y, m);
    emlrtSetFieldR2017b(b_y, i, "bias_gyro", f_y, 7);
    emlrtSetFieldR2017b(b_y, i, "correct_flag",
                        g_emlrt_marshallOut(r->correct_flag), 8);
    u_idx_0 = r->gyro_raw[0];
    u_idx_1 = r->gyro_raw[1];
    u_idx_2 = r->gyro_raw[2];
    g_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i4, mxSINGLE_CLASS, mxREAL);
    pData = (real32_T *)emlrtMxGetData(m);
    pData[0] = u_idx_0;
    pData[1] = u_idx_1;
    pData[2] = u_idx_2;
    emlrtAssign(&g_y, m);
    emlrtSetFieldR2017b(b_y, i, "gyro_raw", g_y, 9);
    u_idx_0 = r->acc_raw[0];
    u_idx_1 = r->acc_raw[1];
    u_idx_2 = r->acc_raw[2];
    h_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i5, mxSINGLE_CLASS, mxREAL);
    pData = (real32_T *)emlrtMxGetData(m);
    pData[0] = u_idx_0;
    pData[1] = u_idx_1;
    pData[2] = u_idx_2;
    emlrtAssign(&h_y, m);
    emlrtSetFieldR2017b(b_y, i, "acc_raw", h_y, 10);
  }
  emlrtSetFieldR2017b(y, 0, "his_physical_state", b_y, 3);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&b_i, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  for (i = 0; i < 6; i++) {
    pData[i] = u->Xk[i];
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "Xk", c_y, 4);
  emlrtSetFieldR2017b(y, 0, "correction_count",
                      c_emlrt_marshallOut(u->correction_count), 5);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[4]
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[4])
{
  vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u
 * Return Type  : const mxArray *
 */
static const mxArray *f_emlrt_marshallOut(const real32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : uint8_T
 */
static uint8_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  uint8_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = g_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[12]
 * Return Type  : void
 */
static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[12])
{
  static const int32_T dims[2] = {6, 2};
  int32_T i;
  real32_T(*r)[12];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                          (const void *)&dims[0]);
  r = (real32_T(*)[12])emlrtMxGetData(src);
  for (i = 0; i < 12; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T
 */
static uint8_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  uint8_T y;
  y = wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const uint8_T u
 * Return Type  : const mxArray *
 */
static const mxArray *g_emlrt_marshallOut(const uint8_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : matlab_imu_m_now_t
 */
static matlab_imu_m_now_t gb_emlrt_marshallIn(const emlrtStack *sp,
                                              const mxArray *nullptr,
                                              const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  matlab_imu_m_now_t y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = hb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[3]
 */
static real32_T (*gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  int32_T i;
  real32_T(*ret)[3];
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real32_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                matlab_ESKF_process_variables_t *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               matlab_ESKF_process_variables_t *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  i_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const matlab_ESKF_obs_variables_t *u
 * Return Type  : const mxArray *
 */
static const mxArray *h_emlrt_marshallOut(const matlab_ESKF_obs_variables_t *u)
{
  static const int32_T iv1[2] = {2, 6};
  static const int32_T iv2[2] = {6, 2};
  static const int32_T i1 = 2;
  static const int32_T i2 = 2;
  static const int32_T i3 = 6;
  static const char_T *b_sv1[5] = {"his_obs_index", "H", "K", "R", "Z"};
  static const char_T *b_sv[4] = {"his_obs", "Accel", "Xk", "P"};
  static const char_T *sv2[4] = {"index", "time", "Z", "R"};
  static const char_T *s = "Accel";
  matlab_obs_his_obs_t b_u[2];
  const matlab_obs_his_obs_t *r;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  real32_T *pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, (const char_T **)&b_sv[0]));
  memcpy(&b_u[0], &u->his_obs[0], 2U * sizeof(matlab_obs_his_obs_t));
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 2;
  emlrtAssign(&b_y, emlrtCreateStructArray(2, &iv[0], 1, (const char_T **)&s));
  for (i = 0; i < 2; i++) {
    uint64_T u_time;
    real32_T u_R[4];
    real32_T u_Z_idx_0;
    real32_T u_Z_idx_1;
    int16_T u_index;
    r = &b_u[i];
    u_index = r->Accel.index;
    u_time = r->Accel.time;
    u_Z_idx_0 = r->Accel.Z[0];
    u_Z_idx_1 = r->Accel.Z[1];
    u_R[0] = r->Accel.R[0];
    u_R[1] = r->Accel.R[1];
    u_R[2] = r->Accel.R[2];
    u_R[3] = r->Accel.R[3];
    e_y = NULL;
    emlrtAssign(&e_y,
                emlrtCreateStructMatrix(1, 1, 4, (const char_T **)&sv2[0]));
    emlrtSetFieldR2017b(e_y, 0, "index", c_emlrt_marshallOut(u_index), 0);
    emlrtSetFieldR2017b(e_y, 0, "time", d_emlrt_marshallOut(u_time), 1);
    g_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i1, mxSINGLE_CLASS, mxREAL);
    pData = (real32_T *)emlrtMxGetData(m);
    pData[0] = u_Z_idx_0;
    pData[1] = u_Z_idx_1;
    emlrtAssign(&g_y, m);
    emlrtSetFieldR2017b(e_y, 0, "Z", g_y, 2);
    emlrtSetFieldR2017b(e_y, 0, "R", i_emlrt_marshallOut(u_R), 3);
    emlrtSetFieldR2017b(b_y, i, "Accel", e_y, 0);
  }
  emlrtSetFieldR2017b(y, 0, "his_obs", b_y, 0);
  c_y = NULL;
  emlrtAssign(&c_y,
              emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&b_sv1[0]));
  emlrtSetFieldR2017b(c_y, 0, "his_obs_index",
                      c_emlrt_marshallOut(u->Accel.his_obs_index), 0);
  d_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0;
  for (b_i = 0; b_i < 6; b_i++) {
    c_i = b_i << 1;
    pData[i] = u->Accel.H[c_i];
    pData[i + 1] = u->Accel.H[c_i + 1];
    i += 2;
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(c_y, 0, "H", d_y, 1);
  f_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv2[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0;
  for (b_i = 0; b_i < 2; b_i++) {
    for (c_i = 0; c_i < 6; c_i++) {
      pData[i + c_i] = u->Accel.K[c_i + 6 * b_i];
    }
    i += 6;
  }
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(c_y, 0, "K", f_y, 2);
  emlrtSetFieldR2017b(c_y, 0, "R", i_emlrt_marshallOut(u->Accel.R), 3);
  h_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->Accel.Z[0];
  pData[1] = u->Accel.Z[1];
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(c_y, 0, "Z", h_y, 4);
  emlrtSetFieldR2017b(y, 0, "Accel", c_y, 1);
  i_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i3, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  for (b_i = 0; b_i < 6; b_i++) {
    pData[b_i] = u->Xk[b_i];
  }
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "Xk", i_y, 2);
  emlrtSetFieldR2017b(y, 0, "P", b_emlrt_marshallOut(u->P), 3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : matlab_imu_m_now_t
 */
static matlab_imu_m_now_t
hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"update_time", "gyro", "acc"};
  emlrtMsgIdentifier thisId;
  matlab_imu_m_now_t y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "update_time";
  y.update_time =
      c_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        0, "update_time")),
                         &thisId);
  thisId.fIdentifier = "gyro";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "gyro")),
      &thisId, y.gyro);
  thisId.fIdentifier = "acc";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "acc")),
      &thisId, y.acc);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[2]
 */
static real32_T (*hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims = 2;
  int32_T i;
  real32_T(*ret)[2];
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real32_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_ESKF_process_variables_t *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_ESKF_process_variables_t *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = {
      "Q", "P", "his_in", "his_physical_state", "Xk", "correction_count"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "Q";
  j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Q")),
      &thisId, y->Q);
  thisId.fIdentifier = "P";
  j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "P")),
      &thisId, y->P);
  thisId.fIdentifier = "his_in";
  y->his_in = k_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "his_in")),
      &thisId);
  thisId.fIdentifier = "his_physical_state";
  l_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3,
                                                    "his_physical_state")),
                     &thisId, y->his_physical_state);
  thisId.fIdentifier = "Xk";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "Xk")),
      &thisId, y->Xk);
  thisId.fIdentifier = "correction_count";
  y->correction_count =
      k_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        5, "correction_count")),
                         &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[4]
 * Return Type  : const mxArray *
 */
static const mxArray *i_emlrt_marshallOut(const real32_T u[4])
{
  static const int32_T iv[2] = {2, 2};
  const mxArray *m;
  const mxArray *y;
  real32_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u[0];
  pData[1] = u[1];
  pData[2] = u[2];
  pData[3] = u[3];
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T
 */
static real32_T ib_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = m_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[9]
 */
static real32_T (*ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[9]
{
  static const int32_T dims[2] = {3, 3};
  int32_T iv[2];
  real32_T(*ret)[9];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real32_T(*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[36]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[36])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const matlab_system_physical_state_t *u
 * Return Type  : const mxArray *
 */
static const mxArray *
j_emlrt_marshallOut(const matlab_system_physical_state_t *u)
{
  static const int32_T i = 3;
  static const int32_T i1 = 4;
  static const int32_T i2 = 3;
  static const int32_T i3 = 3;
  static const int32_T i4 = 3;
  static const int32_T i5 = 3;
  static const char_T *b_sv[13] = {"time",
                                   "euler",
                                   "cbn",
                                   "q",
                                   "bias_gyro",
                                   "gyro",
                                   "acc",
                                   "acc_correct_flag",
                                   "initial_alignment_flag",
                                   "last_integret_time",
                                   "del_att_integret",
                                   "ins_heart_beat",
                                   "correct_heart_beat"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  real32_T *pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 13, (const char_T **)&b_sv[0]));
  emlrtSetFieldR2017b(y, 0, "time", d_emlrt_marshallOut(u->time), 0);
  b_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->euler[0];
  pData[1] = u->euler[1];
  pData[2] = u->euler[2];
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "euler", b_y, 1);
  emlrtSetFieldR2017b(y, 0, "cbn", e_emlrt_marshallOut(u->cbn), 2);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->q[0];
  pData[1] = u->q[1];
  pData[2] = u->q[2];
  pData[3] = u->q[3];
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "q", c_y, 3);
  d_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->bias_gyro[0];
  pData[1] = u->bias_gyro[1];
  pData[2] = u->bias_gyro[2];
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "bias_gyro", d_y, 4);
  e_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i3, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->gyro[0];
  pData[1] = u->gyro[1];
  pData[2] = u->gyro[2];
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "gyro", e_y, 5);
  f_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i4, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->acc[0];
  pData[1] = u->acc[1];
  pData[2] = u->acc[2];
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "acc", f_y, 6);
  emlrtSetFieldR2017b(y, 0, "acc_correct_flag",
                      g_emlrt_marshallOut(u->acc_correct_flag), 7);
  emlrtSetFieldR2017b(y, 0, "initial_alignment_flag",
                      g_emlrt_marshallOut(u->initial_alignment_flag), 8);
  emlrtSetFieldR2017b(y, 0, "last_integret_time",
                      d_emlrt_marshallOut(u->last_integret_time), 9);
  g_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i5, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->del_att_integret[0];
  pData[1] = u->del_att_integret[1];
  pData[2] = u->del_att_integret[2];
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "del_att_integret", g_y, 10);
  emlrtSetFieldR2017b(y, 0, "ins_heart_beat",
                      d_emlrt_marshallOut(u->ins_heart_beat), 11);
  emlrtSetFieldR2017b(y, 0, "correct_heart_beat",
                      d_emlrt_marshallOut(u->correct_heart_beat), 12);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T (*)[9]
 */
static real32_T (*jb_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real32_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = kb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[4]
 */
static real32_T (*jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims = 4;
  int32_T i;
  real32_T(*ret)[4];
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real32_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int16_T
 */
static int16_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const matlab_ESKF_config_t u
 * Return Type  : const mxArray *
 */
static const mxArray *k_emlrt_marshallOut(const matlab_ESKF_config_t u)
{
  static const int32_T i = 3;
  static const int32_T i1 = 3;
  static const int32_T i2 = 2;
  static const char_T *b_sv[7] = {"software_version", "gyro_full_range",
                                  "acc_full_range",   "gyro_bias_noise",
                                  "angle_rand_walk",  "rp_obs_noise",
                                  "mag_noise"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  real32_T *pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&b_sv[0]));
  emlrtSetFieldR2017b(y, 0, "software_version",
                      f_emlrt_marshallOut(u.software_version), 0);
  emlrtSetFieldR2017b(y, 0, "gyro_full_range",
                      f_emlrt_marshallOut(u.gyro_full_range), 1);
  emlrtSetFieldR2017b(y, 0, "acc_full_range",
                      f_emlrt_marshallOut(u.acc_full_range), 2);
  b_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u.gyro_bias_noise[0];
  pData[1] = u.gyro_bias_noise[1];
  pData[2] = u.gyro_bias_noise[2];
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "gyro_bias_noise", b_y, 3);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u.angle_rand_walk[0];
  pData[1] = u.angle_rand_walk[1];
  pData[2] = u.angle_rand_walk[2];
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "angle_rand_walk", c_y, 4);
  d_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u.rp_obs_noise[0];
  pData[1] = u.rp_obs_noise[1];
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "rp_obs_noise", d_y, 5);
  emlrtSetFieldR2017b(y, 0, "mag_noise", f_emlrt_marshallOut(u.mag_noise), 6);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[9]
 */
static real32_T (*kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[9]
{
  real32_T(*y)[9];
  y = ic_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[4]
 */
static real32_T (*kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                      const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims[2] = {2, 2};
  int32_T iv[2];
  real32_T(*ret)[4];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real32_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_his_physical_state_t y[20]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_his_physical_state_t y[20])
{
  static const int32_T dims[2] = {1, 20};
  emlrtMsgIdentifier thisId;
  int32_T i;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 11,
                         (const char_T **)&sv[0], 2U, (const void *)&dims[0]);
  for (i = 0; i < 20; i++) {
    thisId.fIdentifier = "time";
    y[i].time = c_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "time")),
        &thisId);
    thisId.fIdentifier = "cbn";
    e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 1, "cbn")),
        &thisId, y[i].cbn);
    thisId.fIdentifier = "q";
    f_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "q")),
        &thisId, y[i].q);
    thisId.fIdentifier = "gyro";
    d_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 3, "gyro")),
        &thisId, y[i].gyro);
    thisId.fIdentifier = "dt";
    y[i].dt = m_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 4, "dt")),
        &thisId);
    thisId.fIdentifier = "F1";
    y[i].F1 = m_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 5, "F1")),
        &thisId);
    thisId.fIdentifier = "F3";
    e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 6, "F3")),
        &thisId, y[i].F3);
    thisId.fIdentifier = "bias_gyro";
    d_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i,
                                                      7, "bias_gyro")),
                       &thisId, y[i].bias_gyro);
    thisId.fIdentifier = "correct_flag";
    y[i].correct_flag =
        g_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b(
                               (emlrtConstCTX)sp, u, i, 8, "correct_flag")),
                           &thisId);
    thisId.fIdentifier = "gyro_raw";
    d_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 9, "gyro_raw")),
        &thisId, y[i].gyro_raw);
    thisId.fIdentifier = "acc_raw";
    d_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 10, "acc_raw")),
        &thisId, y[i].acc_raw);
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[4]
 * Return Type  : const mxArray *
 */
static const mxArray *l_emlrt_marshallOut(const real32_T u[4])
{
  static const int32_T i = 0;
  static const int32_T i1 = 4;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : int16_T
 */
static int16_T lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  int16_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = k_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T
 */
static real32_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real32_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *m_emlrt_marshallOut(const real32_T u[9])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 3};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                matlab_his_physical_state_t *y
 * Return Type  : void
 */
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier,
                                matlab_his_physical_state_t *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  nb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[6]
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[6])
{
  bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const matlab_his_physical_state_t *u
 * Return Type  : const mxArray *
 */
static const mxArray *n_emlrt_marshallOut(const matlab_his_physical_state_t *u)
{
  static const int32_T i = 4;
  static const int32_T i1 = 3;
  static const int32_T i2 = 3;
  static const int32_T i3 = 3;
  static const int32_T i4 = 3;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *m;
  const mxArray *y;
  real32_T *pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 11, (const char_T **)&sv1[0]));
  emlrtSetFieldR2017b(y, 0, "time", d_emlrt_marshallOut(u->time), 0);
  emlrtSetFieldR2017b(y, 0, "cbn", e_emlrt_marshallOut(u->cbn), 1);
  b_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->q[0];
  pData[1] = u->q[1];
  pData[2] = u->q[2];
  pData[3] = u->q[3];
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "q", b_y, 2);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->gyro[0];
  pData[1] = u->gyro[1];
  pData[2] = u->gyro[2];
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "gyro", c_y, 3);
  emlrtSetFieldR2017b(y, 0, "dt", f_emlrt_marshallOut(u->dt), 4);
  emlrtSetFieldR2017b(y, 0, "F1", f_emlrt_marshallOut(u->F1), 5);
  emlrtSetFieldR2017b(y, 0, "F3", e_emlrt_marshallOut(u->F3), 6);
  d_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->bias_gyro[0];
  pData[1] = u->bias_gyro[1];
  pData[2] = u->bias_gyro[2];
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "bias_gyro", d_y, 7);
  emlrtSetFieldR2017b(y, 0, "correct_flag",
                      g_emlrt_marshallOut(u->correct_flag), 8);
  e_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i3, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->gyro_raw[0];
  pData[1] = u->gyro_raw[1];
  pData[2] = u->gyro_raw[2];
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "gyro_raw", e_y, 9);
  f_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i4, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u->acc_raw[0];
  pData[1] = u->acc_raw[1];
  pData[2] = u->acc_raw[2];
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "acc_raw", f_y, 10);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_his_physical_state_t *y
 * Return Type  : void
 */
static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                matlab_his_physical_state_t *y)
{
  static const int32_T dims = 0;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 11,
                         (const char_T **)&sv[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "time";
  y->time = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "time")),
      &thisId);
  thisId.fIdentifier = "cbn";
  e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "cbn")),
      &thisId, y->cbn);
  thisId.fIdentifier = "q";
  f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "q")),
      &thisId, y->q);
  thisId.fIdentifier = "gyro";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "gyro")),
      &thisId, y->gyro);
  thisId.fIdentifier = "dt";
  y->dt = m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "dt")),
      &thisId);
  thisId.fIdentifier = "F1";
  y->F1 = m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "F1")),
      &thisId);
  thisId.fIdentifier = "F3";
  e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "F3")),
      &thisId, y->F3);
  thisId.fIdentifier = "bias_gyro";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "bias_gyro")),
      &thisId, y->bias_gyro);
  thisId.fIdentifier = "correct_flag";
  y->correct_flag =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        8, "correct_flag")),
                         &thisId);
  thisId.fIdentifier = "gyro_raw";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "gyro_raw")),
      &thisId, y->gyro_raw);
  thisId.fIdentifier = "acc_raw";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10, "acc_raw")),
      &thisId, y->acc_raw);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                matlab_ESKF_obs_variables_t *y
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               matlab_ESKF_obs_variables_t *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const real32_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *o_emlrt_marshallOut(const real32_T u[3])
{
  static const int32_T i = 0;
  static const int32_T i1 = 3;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T (*)[4]
 */
static real32_T (*ob_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real32_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = pb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_ESKF_obs_variables_t *y
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_ESKF_obs_variables_t *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[4] = {"his_obs", "Accel", "Xk", "P"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 4,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "his_obs";
  q_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "his_obs")),
      &thisId, y->his_obs);
  thisId.fIdentifier = "Accel";
  u_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "Accel")),
      &thisId, &y->Accel);
  thisId.fIdentifier = "Xk";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "Xk")),
      &thisId, y->Xk);
  thisId.fIdentifier = "P";
  j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "P")),
      &thisId, y->P);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[4]
 *                const mxArray *y
 * Return Type  : void
 */
static void p_emlrt_marshallOut(const real32_T u[4], const mxArray *y)
{
  static const int32_T i = 4;
  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, &i, 1);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[4]
 */
static real32_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[4]
{
  real32_T(*y)[4];
  y = jc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_obs_his_obs_t y[2]
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_obs_his_obs_t y[2])
{
  static const int32_T dims[2] = {1, 2};
  static const char_T *fieldNames = "Accel";
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 1,
                         (const char_T **)&fieldNames, 2U,
                         (const void *)&dims[0]);
  thisId.fIdentifier = "Accel";
  y[0].Accel = r_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Accel")),
      &thisId);
  thisId.fIdentifier = "Accel";
  y[1].Accel = r_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 1, 0, "Accel")),
      &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[4]
 * Return Type  : const mxArray *
 */
static const mxArray *q_emlrt_marshallOut(const real32_T u[4])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {2, 2};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T (*)[4]
 */
static real32_T (*qb_emlrt_marshallIn(const emlrtStack *sp,
                                      const mxArray *nullptr,
                                      const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real32_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = rb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : matlab_obs_his_obs_accel_t
 */
static matlab_obs_his_obs_accel_t
r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                   const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[4] = {"index", "time", "Z", "R"};
  emlrtMsgIdentifier thisId;
  matlab_obs_his_obs_accel_t y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 4,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "index";
  y.index = k_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "index")),
      &thisId);
  thisId.fIdentifier = "time";
  y.time = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "time")),
      &thisId);
  thisId.fIdentifier = "Z";
  s_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "Z")),
      &thisId, y.Z);
  thisId.fIdentifier = "R";
  t_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "R")),
      &thisId, y.R);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real32_T u[3]
 *                const mxArray *y
 * Return Type  : void
 */
static void r_emlrt_marshallOut(const real32_T u[3], const mxArray *y)
{
  static const int32_T i = 3;
  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, &i, 1);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[4]
 */
static real32_T (*rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                      const emlrtMsgIdentifier *parentId))[4]
{
  real32_T(*y)[4];
  y = kc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[2]
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[2])
{
  cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint64_T
 */
static uint64_T sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint64_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint64", false, 0U,
                          (const void *)&dims);
  ret = *(uint64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[4]
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[4])
{
  dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[3]
 * Return Type  : void
 */
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[3])
{
  static const int32_T dims = 3;
  real32_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                          (const void *)&dims);
  r = (real32_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                matlab_obs_accel_t *y
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               matlab_obs_accel_t *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = {"his_obs_index", "H", "K", "R", "Z"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 5,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "his_obs_index";
  y->his_obs_index =
      k_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        0, "his_obs_index")),
                         &thisId);
  thisId.fIdentifier = "H";
  v_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "H")),
      &thisId, y->H);
  thisId.fIdentifier = "K";
  w_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "K")),
      &thisId, y->K);
  thisId.fIdentifier = "R";
  t_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "R")),
      &thisId, y->R);
  thisId.fIdentifier = "Z";
  s_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "Z")),
      &thisId, y->Z);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[9]
 * Return Type  : void
 */
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[9])
{
  static const int32_T dims[2] = {3, 3};
  int32_T i;
  real32_T(*r)[9];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                          (const void *)&dims[0]);
  r = (real32_T(*)[9])emlrtMxGetData(src);
  for (i = 0; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[12]
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[12])
{
  ec_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[4]
 * Return Type  : void
 */
static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[4])
{
  static const int32_T dims = 4;
  real32_T(*r)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                          (const void *)&dims);
  r = (real32_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[12]
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[12])
{
  fc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T
 */
static uint8_T wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint8_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint8", false, 0U,
                          (const void *)&dims);
  ret = *(uint8_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : matlab_ESKF_config_t
 */
static matlab_ESKF_config_t x_emlrt_marshallIn(const emlrtStack *sp,
                                               const mxArray *nullptr,
                                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  matlab_ESKF_config_t y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = y_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[36]
 * Return Type  : void
 */
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real32_T ret[36])
{
  static const int32_T dims[2] = {6, 6};
  int32_T i;
  real32_T(*r)[36];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                          (const void *)&dims[0]);
  r = (real32_T(*)[36])emlrtMxGetData(src);
  for (i = 0; i < 36; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : matlab_ESKF_config_t
 */
static matlab_ESKF_config_t
y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                   const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[7] = {"software_version", "gyro_full_range",
                                        "acc_full_range",   "gyro_bias_noise",
                                        "angle_rand_walk",  "rp_obs_noise",
                                        "mag_noise"};
  emlrtMsgIdentifier thisId;
  matlab_ESKF_config_t y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "software_version";
  y.software_version =
      m_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        0, "software_version")),
                         &thisId);
  thisId.fIdentifier = "gyro_full_range";
  y.gyro_full_range =
      m_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        1, "gyro_full_range")),
                         &thisId);
  thisId.fIdentifier = "acc_full_range";
  y.acc_full_range =
      m_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        2, "acc_full_range")),
                         &thisId);
  thisId.fIdentifier = "gyro_bias_noise";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3,
                                                    "gyro_bias_noise")),
                     &thisId, y.gyro_bias_noise);
  thisId.fIdentifier = "angle_rand_walk";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4,
                                                    "angle_rand_walk")),
                     &thisId, y.angle_rand_walk);
  thisId.fIdentifier = "rp_obs_noise";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5,
                                                    "rp_obs_noise")),
                     &thisId, y.rp_obs_noise);
  thisId.fIdentifier = "mag_noise";
  y.mag_noise = m_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "mag_noise")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int16_T
 */
static int16_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  int16_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int16", false, 0U,
                          (const void *)&dims);
  ret = *(int16_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void ESKF_integrated_acc_api(const mxArray *const prhs[5], int32_T nlhs,
                             const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  real32_T(*Z)[2];
  int16_T syn_index;
  uint8_T enable_update_Pk1;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ESKF_process_variables",
                     &ESKF_process_variables);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_observation_variables",
                     &ESKF_observation_variables);
  Z = db_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Z");
  syn_index = lb_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "syn_index");
  enable_update_Pk1 =
      fb_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "enable_update_Pk1");
  /* Invoke the target function */
  syn_index =
      ESKF_integrated_acc(&ESKF_process_variables, &ESKF_observation_variables,
                          *Z, syn_index, enable_update_Pk1);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&ESKF_process_variables);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(&ESKF_observation_variables);
  }
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(syn_index);
  }
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void ESKF_variables_initial_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ESKF_process_variables",
                     &ESKF_process_variables);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_observation_variables",
                     &ESKF_observation_variables);
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ESKF_config");
  /* Invoke the target function */
  ESKF_variables_initial(&ESKF_process_variables, &ESKF_observation_variables,
                         &ESKF_config);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&ESKF_process_variables);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(&ESKF_observation_variables);
  }
  if (nlhs > 2) {
    plhs[2] = k_emlrt_marshallOut(ESKF_config);
  }
}

/*
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void acc_correct_api(const mxArray *const prhs[8], int32_T nlhs,
                     const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  uint64_T update_time;
  real32_T(*acc)[3];
  real32_T(*att_obs_noise)[2];
  uint8_T enable_update_Pk1;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "system_physical_state",
                   &system_physical_state);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_process_variables",
                     &ESKF_process_variables);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ESKF_observation_variables",
                     &ESKF_observation_variables);
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "ESKF_config");
  update_time = ab_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "update_time");
  acc = bb_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "acc");
  att_obs_noise =
      db_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "att_obs_noise");
  enable_update_Pk1 =
      fb_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "enable_update_Pk1");
  /* Invoke the target function */
  acc_correct(&system_physical_state, &ESKF_process_variables,
              &ESKF_observation_variables, &ESKF_config, update_time, *acc,
              *att_obs_noise, enable_update_Pk1);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&ESKF_process_variables);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(&ESKF_observation_variables);
  }
  if (nlhs > 2) {
    plhs[2] = j_emlrt_marshallOut(&system_physical_state);
  }
  if (nlhs > 3) {
    plhs[3] = k_emlrt_marshallOut(ESKF_config);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void ahrs_9d_eskf_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  ahrs_9d_eskf_xil_terminate();
  ahrs_9d_eskf_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void ahrs_9d_eskf_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void ahrs_9d_eskf_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void ahrs_initial_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_imu_m_now_t imu_m_now;
  matlab_system_physical_state_t system_physical_state;
  real32_T dt;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ESKF_process_variables",
                     &ESKF_process_variables);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_observation_variables",
                     &ESKF_observation_variables);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "system_physical_state",
                   &system_physical_state);
  imu_m_now = gb_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "imu_m_now");
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "ESKF_config");
  dt = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "dt");
  /* Invoke the target function */
  ahrs_initial(&ESKF_process_variables, &ESKF_observation_variables,
               &system_physical_state, &imu_m_now, &ESKF_config, dt);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&ESKF_process_variables);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(&ESKF_observation_variables);
  }
  if (nlhs > 2) {
    plhs[2] = j_emlrt_marshallOut(&system_physical_state);
  }
  if (nlhs > 3) {
    plhs[3] = k_emlrt_marshallOut(ESKF_config);
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void cbn2euler_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*cbn)[9];
  real32_T pitch;
  real32_T roll;
  real32_T yaw;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  cbn = jb_emlrt_marshallIn(&st, emlrtAlias(prhs), "cbn");
  /* Invoke the target function */
  cbn2euler(*cbn, &pitch, &roll, &yaw);
  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(pitch);
  if (nlhs > 1) {
    plhs[1] = f_emlrt_marshallOut(roll);
  }
  if (nlhs > 2) {
    plhs[2] = f_emlrt_marshallOut(yaw);
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void cbn2quaternion_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*cbn)[9];
  real32_T(*q)[4];
  st.tls = emlrtRootTLSGlobal;
  q = (real32_T(*)[4])mxMalloc(sizeof(real32_T[4]));
  /* Marshall function inputs */
  cbn = jb_emlrt_marshallIn(&st, emlrtAlias(prhs), "cbn");
  /* Invoke the target function */
  cbn2quaternion(*cbn, *q);
  /* Marshall function outputs */
  *plhs = l_emlrt_marshallOut(*q);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray **plhs
 * Return Type  : void
 */
void euler2cbn_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*cbn)[9];
  real32_T pitch;
  real32_T roll;
  real32_T yaw;
  st.tls = emlrtRootTLSGlobal;
  cbn = (real32_T(*)[9])mxMalloc(sizeof(real32_T[9]));
  /* Marshall function inputs */
  pitch = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "pitch");
  roll = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "roll");
  yaw = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "yaw");
  /* Invoke the target function */
  euler2cbn(pitch, roll, yaw, *cbn);
  /* Marshall function outputs */
  *plhs = m_emlrt_marshallOut(*cbn);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void feedback_correction_api(const mxArray *const prhs[2], int32_T nlhs,
                             const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_his_physical_state_t system_physical_state;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ESKF_process_variables",
                     &ESKF_process_variables);
  mb_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "system_physical_state",
                      &system_physical_state);
  /* Invoke the target function */
  feedback_correction(&ESKF_process_variables, &system_physical_state);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&ESKF_process_variables);
  if (nlhs > 1) {
    plhs[1] = n_emlrt_marshallOut(&system_physical_state);
  }
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[6]
 * Return Type  : void
 */
void get_his_physical_state_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  uint64_T gnss_time;
  uint64_T syn_time;
  real32_T(*cbn)[9];
  real32_T(*gyro)[3];
  int16_T syn_index;
  st.tls = emlrtRootTLSGlobal;
  cbn = (real32_T(*)[9])mxMalloc(sizeof(real32_T[9]));
  gyro = (real32_T(*)[3])mxMalloc(sizeof(real32_T[3]));
  /* Marshall function inputs */
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ESKF_process_variables",
                     &ESKF_process_variables);
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_config");
  gnss_time = ab_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "gnss_time");
  /* Invoke the target function */
  get_his_physical_state(&ESKF_process_variables, &ESKF_config, gnss_time, *cbn,
                         *gyro, &syn_time, &syn_index);
  /* Marshall function outputs */
  plhs[0] = m_emlrt_marshallOut(*cbn);
  if (nlhs > 1) {
    plhs[1] = o_emlrt_marshallOut(*gyro);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(&ESKF_process_variables);
  }
  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(syn_time);
  }
  if (nlhs > 4) {
    plhs[4] = c_emlrt_marshallOut(syn_index);
  }
  if (nlhs > 5) {
    plhs[5] = k_emlrt_marshallOut(ESKF_config);
  }
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void inertial_ahrs_update_api(const mxArray *const prhs[5], int32_T nlhs,
                              const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_imu_m_now_t imu_m_now;
  matlab_system_physical_state_t system_physical_state;
  real32_T dt;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "system_physical_state",
                   &system_physical_state);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_process_variables",
                     &ESKF_process_variables);
  imu_m_now = gb_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "imu_m_now");
  dt = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "dt");
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "ESKF_config");
  /* Invoke the target function */
  inertial_ahrs_update(&system_physical_state, &ESKF_process_variables,
                       &imu_m_now, dt, &ESKF_config);
  /* Marshall function outputs */
  plhs[0] = j_emlrt_marshallOut(&system_physical_state);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&ESKF_process_variables);
  }
  if (nlhs > 2) {
    plhs[2] = k_emlrt_marshallOut(ESKF_config);
  }
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray **plhs
 * Return Type  : void
 */
void inertial_arhs_repair_api(const mxArray *const prhs[2],
                              const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_process_variables_t ESKF_process_variables;
  int16_T k;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ESKF_process_variables",
                     &ESKF_process_variables);
  k = lb_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "k");
  /* Invoke the target function */
  inertial_arhs_repair(&ESKF_process_variables, k);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&ESKF_process_variables);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void load_ESKF_config_api(const mxArray *const prhs[2], int32_T nlhs,
                          const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_system_physical_state_t system_physical_state;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "system_physical_state",
                   &system_physical_state);
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_config");
  /* Invoke the target function */
  load_ESKF_config(&system_physical_state, &ESKF_config);
  /* Marshall function outputs */
  plhs[0] = j_emlrt_marshallOut(&system_physical_state);
  if (nlhs > 1) {
    plhs[1] = k_emlrt_marshallOut(ESKF_config);
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void physical_state_initial_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_system_physical_state_t system_physical_state;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs), "system_physical_state",
                   &system_physical_state);
  /* Invoke the target function */
  physical_state_initial(&system_physical_state);
  /* Marshall function outputs */
  *plhs = j_emlrt_marshallOut(&system_physical_state);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void quaternion2cbn_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*cbn)[9];
  real32_T(*q)[4];
  st.tls = emlrtRootTLSGlobal;
  cbn = (real32_T(*)[9])mxMalloc(sizeof(real32_T[9]));
  /* Marshall function inputs */
  q = ob_emlrt_marshallIn(&st, emlrtAlias(prhs), "q");
  /* Invoke the target function */
  quaternion2cbn(*q, *cbn);
  /* Marshall function outputs */
  *plhs = m_emlrt_marshallOut(*cbn);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void quaternion_normalize_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *prhs_copy_idx_0;
  real32_T(*q)[4];
  st.tls = emlrtRootTLSGlobal;
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs, 0, true, -1);
  /* Marshall function inputs */
  q = ob_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "q");
  /* Invoke the target function */
  quaternion_normalize(*q);
  /* Marshall function outputs */
  p_emlrt_marshallOut(*q, prhs_copy_idx_0);
  *plhs = prhs_copy_idx_0;
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void radians_conv_np_pi_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T radians_in;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  radians_in = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs), "radians_in");
  /* Invoke the target function */
  radians_in = radians_conv_np_pi(radians_in);
  /* Marshall function outputs */
  *plhs = f_emlrt_marshallOut(radians_in);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void reset_his_system_state_api(const mxArray *const prhs[2], int32_T nlhs,
                                const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "system_physical_state",
                   &system_physical_state);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_process_variables",
                     &ESKF_process_variables);
  /* Invoke the target function */
  reset_his_system_state(&system_physical_state, &ESKF_process_variables);
  /* Marshall function outputs */
  plhs[0] = j_emlrt_marshallOut(&system_physical_state);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&ESKF_process_variables);
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void reset_physical_state_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_system_physical_state_t system_physical_state;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs), "system_physical_state",
                   &system_physical_state);
  /* Invoke the target function */
  reset_physical_state(&system_physical_state);
  /* Marshall function outputs */
  *plhs = j_emlrt_marshallOut(&system_physical_state);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void reset_state_by_yaw_obs_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  real32_T yaw_obs;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  yaw_obs = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "yaw_obs");
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "system_physical_state",
                   &system_physical_state);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ESKF_process_variables",
                     &ESKF_process_variables);
  /* Invoke the target function */
  reset_state_by_yaw_obs(yaw_obs, &system_physical_state,
                         &ESKF_process_variables);
  /* Marshall function outputs */
  plhs[0] = j_emlrt_marshallOut(&system_physical_state);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&ESKF_process_variables);
  }
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                const mxArray **plhs
 * Return Type  : void
 */
void robust_igg3_inflate_R_api(const mxArray *const prhs[4],
                               const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*R_in)[4];
  real32_T(*R_out)[4];
  real32_T(*Z)[2];
  real32_T P11;
  real32_T P22;
  st.tls = emlrtRootTLSGlobal;
  R_out = (real32_T(*)[4])mxMalloc(sizeof(real32_T[4]));
  /* Marshall function inputs */
  Z = db_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Z");
  P11 = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "P11");
  P22 = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "P22");
  R_in = qb_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "R_in");
  /* Invoke the target function */
  robust_igg3_inflate_R(*Z, P11, P22, *R_in, *R_out);
  /* Marshall function outputs */
  *plhs = q_emlrt_marshallOut(*R_out);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void skew_symmetric_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*a_hat)[9];
  real32_T(*a)[3];
  st.tls = emlrtRootTLSGlobal;
  a_hat = (real32_T(*)[9])mxMalloc(sizeof(real32_T[9]));
  /* Marshall function inputs */
  a = bb_emlrt_marshallIn(&st, emlrtAlias(prhs), "a");
  /* Invoke the target function */
  skew_symmetric(*a, *a_hat);
  /* Marshall function outputs */
  *plhs = m_emlrt_marshallOut(*a_hat);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void so3_exp_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*R)[9];
  real32_T(*a)[3];
  st.tls = emlrtRootTLSGlobal;
  R = (real32_T(*)[9])mxMalloc(sizeof(real32_T[9]));
  /* Marshall function inputs */
  a = bb_emlrt_marshallIn(&st, emlrtAlias(prhs), "a");
  /* Invoke the target function */
  so3_exp(*a, *R);
  /* Marshall function outputs */
  *plhs = m_emlrt_marshallOut(*R);
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void system_state_push_api(const mxArray *const prhs[4], int32_T nlhs,
                           const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_imu_m_now_t imu_m_now;
  matlab_system_physical_state_t system_physical_state;
  real32_T dt;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "system_physical_state",
                   &system_physical_state);
  imu_m_now = gb_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "imu_m_now");
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ESKF_process_variables",
                     &ESKF_process_variables);
  dt = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "dt");
  /* Invoke the target function */
  system_state_push(&system_physical_state, &imu_m_now, &ESKF_process_variables,
                    dt);
  /* Marshall function outputs */
  plhs[0] = j_emlrt_marshallOut(&system_physical_state);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&ESKF_process_variables);
  }
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray **plhs
 * Return Type  : void
 */
void update_quaternion_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *prhs_copy_idx_0;
  real32_T(*q)[4];
  real32_T(*gyro)[3];
  st.tls = emlrtRootTLSGlobal;
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, -1);
  /* Marshall function inputs */
  q = ob_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "q");
  gyro = bb_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "gyro");
  /* Invoke the target function */
  update_quaternion(*q, *gyro);
  /* Marshall function outputs */
  p_emlrt_marshallOut(*q, prhs_copy_idx_0);
  *plhs = prhs_copy_idx_0;
}

/*
 * Arguments    : const mxArray * const prhs[9]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void yaw_bias_est_api(const mxArray *const prhs[9], int32_T nlhs,
                      const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_system_physical_state_t system_physical_state;
  const mxArray *prhs_copy_idx_0;
  uint64_T time_last;
  uint64_T time_now;
  real32_T(*yaw_bias_body)[3];
  real32_T last_yaw_imu;
  real32_T last_yaw_obs;
  real32_T yaw_bias_last;
  real32_T yaw_imu;
  real32_T yaw_obs;
  st.tls = emlrtRootTLSGlobal;
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, -1);
  /* Marshall function inputs */
  yaw_bias_body =
      bb_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "yaw_bias_body");
  yaw_bias_last =
      ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "yaw_bias_last");
  yaw_obs = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "yaw_obs");
  last_yaw_obs = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "last_yaw_obs");
  yaw_imu = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "yaw_imu");
  last_yaw_imu = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "last_yaw_imu");
  time_now = ab_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "time_now");
  time_last = ab_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "time_last");
  emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "system_physical_state",
                   &system_physical_state);
  /* Invoke the target function */
  yaw_bias_last = yaw_bias_est(*yaw_bias_body, yaw_bias_last, yaw_obs,
                               last_yaw_obs, yaw_imu, last_yaw_imu, time_now,
                               time_last, &system_physical_state);
  /* Marshall function outputs */
  r_emlrt_marshallOut(*yaw_bias_body, prhs_copy_idx_0);
  plhs[0] = prhs_copy_idx_0;
  if (nlhs > 1) {
    plhs[1] = f_emlrt_marshallOut(yaw_bias_last);
  }
}

/*
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void yaw_correct_api(const mxArray *const prhs[8], int32_T nlhs,
                     const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  matlab_ESKF_config_t ESKF_config;
  matlab_ESKF_obs_variables_t ESKF_observation_variables;
  matlab_ESKF_process_variables_t ESKF_process_variables;
  matlab_system_physical_state_t system_physical_state;
  uint64_T update_time;
  real32_T yaw_obs;
  real32_T yaw_obs_var;
  uint8_T yaw_align_flag;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "system_physical_state",
                   &system_physical_state);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ESKF_process_variables",
                     &ESKF_process_variables);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ESKF_observation_variables",
                     &ESKF_observation_variables);
  ESKF_config = x_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "ESKF_config");
  update_time = ab_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "update_time");
  yaw_obs = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "yaw_obs");
  yaw_obs_var = ib_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "yaw_obs_var");
  yaw_align_flag =
      fb_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "yaw_align_flag");
  /* Invoke the target function */
  yaw_correct(&system_physical_state, &ESKF_process_variables,
              &ESKF_observation_variables, &ESKF_config, update_time, yaw_obs,
              yaw_obs_var, &yaw_align_flag);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&ESKF_process_variables);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(&ESKF_observation_variables);
  }
  if (nlhs > 2) {
    plhs[2] = j_emlrt_marshallOut(&system_physical_state);
  }
  if (nlhs > 3) {
    plhs[3] = g_emlrt_marshallOut(yaw_align_flag);
  }
}

/*
 * File trailer for _coder_ahrs_9d_eskf_api.c
 *
 * [EOF]
 */
