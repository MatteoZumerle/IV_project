/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * primitives.h
 *
 * Code generation for function 'primitives'
 *
 */

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void PassingPrimitive(double a0, double v0, double sf, double b_vmin,
                             double b_vmax, double Tmin, double Tmax,
                             double m1[6], double m2[6]);

extern void PassingPrimitivej0(double a0, double v0, double sf, double b_vmin,
                               double b_vmax, double m1[6]);

extern void StoppingPrimitive(double a0, double v0, double sf, double coeffs[6],
                              double *s_max, double *tf);

extern void StoppingPrimitivej0(double a0, double v0, double m[6],
                                double *s_max, double *tf);

extern void primitives_initialize(void);

extern void primitives_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (primitives.h) */
