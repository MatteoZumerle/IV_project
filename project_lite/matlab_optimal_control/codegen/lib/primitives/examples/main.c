/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "primitives.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static double argInit_real_T(void);

/* Function Definitions */
static double argInit_real_T(void)
{
  return 0.0;
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_PassingPrimitive();
  main_PassingPrimitivej0();
  main_StoppingPrimitive();
  main_StoppingPrimitivej0();
  main_v_opt_fun();
  /* Terminate the application.
You do not need to do this more than one time. */
  primitives_terminate();
  return 0;
}

void main_PassingPrimitive(void)
{
  double m1[6];
  double m2[6];
  double a0_tmp;
  /* Initialize function 'PassingPrimitive' input arguments. */
  a0_tmp = argInit_real_T();
  /* Call the entry-point 'PassingPrimitive'. */
  PassingPrimitive(a0_tmp, a0_tmp, a0_tmp, a0_tmp, a0_tmp, a0_tmp, a0_tmp, m1,
                   m2);
}

void main_PassingPrimitivej0(void)
{
  double m1[6];
  double a0_tmp;
  /* Initialize function 'PassingPrimitivej0' input arguments. */
  a0_tmp = argInit_real_T();
  /* Call the entry-point 'PassingPrimitivej0'. */
  PassingPrimitivej0(a0_tmp, a0_tmp, a0_tmp, a0_tmp, a0_tmp, m1);
}

void main_StoppingPrimitive(void)
{
  double coeffs[6];
  double s_max;
  double tf;
  double v0_tmp;
  /* Initialize function 'StoppingPrimitive' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'StoppingPrimitive'. */
  StoppingPrimitive(v0_tmp, v0_tmp, v0_tmp, coeffs, &s_max, &tf);
}

void main_StoppingPrimitivej0(void)
{
  double m[6];
  double a0_tmp;
  double s_max;
  double tf;
  /* Initialize function 'StoppingPrimitivej0' input arguments. */
  a0_tmp = argInit_real_T();
  /* Call the entry-point 'StoppingPrimitivej0'. */
  StoppingPrimitivej0(a0_tmp, a0_tmp, m, &s_max, &tf);
}

void main_v_opt_fun(void)
{
  double t_tmp;
  /* Initialize function 'v_opt_fun' input arguments. */
  t_tmp = argInit_real_T();
  /* Call the entry-point 'v_opt_fun'. */
  t_tmp = v_opt_fun(t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp);
}

/* End of code generation (main.c) */
