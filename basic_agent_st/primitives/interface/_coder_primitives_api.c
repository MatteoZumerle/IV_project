/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_api.c
 *
 * Code generation for function 'PassingPrimitive'
 *
 */

/* Include files */
#include "_coder_primitives_api.h"
#include "_coder_primitives_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "primitives",                                         /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const real_T u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u[6]);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[6])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 6};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void PassingPrimitive_api(const mxArray *const prhs[7], int32_T nlhs,
                          const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*m1)[6];
  real_T(*m2)[6];
  real_T Tmax;
  real_T Tmin;
  real_T a0;
  real_T b_vmax;
  real_T b_vmin;
  real_T sf;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  m1 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  m2 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a0");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  b_vmin = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vmin");
  b_vmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vmax");
  Tmin = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Tmin");
  Tmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "Tmax");
  /* Invoke the target function */
  PassingPrimitive(a0, v0, sf, b_vmin, b_vmax, Tmin, Tmax, *m1, *m2);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*m1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*m2);
  }
}

void PassingPrimitivej0_api(const mxArray *const prhs[5], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*m1)[6];
  real_T a0;
  real_T b_vmax;
  real_T b_vmin;
  real_T sf;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  m1 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a0");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  b_vmin = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vmin");
  b_vmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vmax");
  /* Invoke the target function */
  PassingPrimitivej0(a0, v0, sf, b_vmin, b_vmax, *m1);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*m1);
}

void StoppingPrimitive_api(const mxArray *const prhs[3], int32_T nlhs,
                           const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*coeffs)[6];
  real_T a0;
  real_T s_max;
  real_T sf;
  real_T tf;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  coeffs = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a0");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  /* Invoke the target function */
  StoppingPrimitive(a0, v0, sf, *coeffs, &s_max, &tf);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*coeffs);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(s_max);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(tf);
  }
}

void StoppingPrimitivej0_api(const mxArray *const prhs[2], int32_T nlhs,
                             const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*m)[6];
  real_T a0;
  real_T s_max;
  real_T tf;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  m = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a0");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  /* Invoke the target function */
  StoppingPrimitivej0(a0, v0, *m, &s_max, &tf);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*m);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(s_max);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(tf);
  }
}

void primitives_atexit(void)
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
  primitives_xil_terminate();
  primitives_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void primitives_initialize(void)
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

void primitives_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_primitives_api.c) */
