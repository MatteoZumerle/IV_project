/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_api.h
 *
 * Code generation for function 'PassingPrimitive'
 *
 */

#ifndef _CODER_PRIMITIVES_API_H
#define _CODER_PRIMITIVES_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void PassingPrimitive(real_T a0, real_T v0, real_T sf, real_T b_vmin,
                      real_T b_vmax, real_T Tmin, real_T Tmax, real_T m1[6],
                      real_T m2[6]);

void PassingPrimitive_api(const mxArray *const prhs[7], int32_T nlhs,
                          const mxArray *plhs[2]);

void PassingPrimitivej0(real_T a0, real_T v0, real_T sf, real_T b_vmin,
                        real_T b_vmax, real_T m1[6]);

void PassingPrimitivej0_api(const mxArray *const prhs[5], const mxArray **plhs);

void StoppingPrimitive(real_T a0, real_T v0, real_T sf, real_T coeffs[6],
                       real_T *s_max, real_T *tf);

void StoppingPrimitive_api(const mxArray *const prhs[3], int32_T nlhs,
                           const mxArray *plhs[3]);

void StoppingPrimitivej0(real_T a0, real_T v0, real_T m[6], real_T *s_max,
                         real_T *tf);

void StoppingPrimitivej0_api(const mxArray *const prhs[2], int32_T nlhs,
                             const mxArray *plhs[3]);

void primitives_atexit(void);

void primitives_initialize(void);

void primitives_terminate(void);

void primitives_xil_shutdown(void);

void primitives_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_primitives_api.h) */
