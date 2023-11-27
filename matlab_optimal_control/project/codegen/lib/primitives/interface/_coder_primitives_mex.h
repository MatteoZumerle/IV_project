/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_mex.h
 *
 * Code generation for function 'PassingPrimitive'
 *
 */

#ifndef _CODER_PRIMITIVES_MEX_H
#define _CODER_PRIMITIVES_MEX_H

/* Include files */
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

void unsafe_PassingPrimitive_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                         int32_T nrhs, const mxArray *prhs[7]);

void unsafe_PassingPrimitivej0_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[5]);

void unsafe_StoppingPrimitive_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                          int32_T nrhs, const mxArray *prhs[3]);

void unsafe_StoppingPrimitivej0_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                            int32_T nrhs,
                                            const mxArray *prhs[2]);

void unsafe_v_opt_fun_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[7]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_primitives_mex.h) */
