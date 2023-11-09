/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_info.c
 *
 * Code generation for function 'PassingPrimitive'
 *
 */

/* Include files */
#include "_coder_primitives_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ced584d8fd240181ecc6a4ccc421313cf66cf66b3013fc0db5a609748f9d88246acba"
      "b59dc2b8d30fdac2c21ebd79f207f8278c17fd2d26def4e04ff02685"
      "0ed089932596ed2e4de7f2f2e6a1f33c7d67e6e99b01a98a900200a4813f766661db4f39"
      "3f5e03c141e3293fdea07232ae83adc07304ffe847c5345c38726789",
      "21eb70fea46aeac8900db735b620b0a163e22154a78886306c211d8acb49cdcbf4f21234"
      "4f3cc8fbcdf7a072220e7460f79c8542bc9cccebf199f1be5b2bd6a3"
      "c1a80747e12f4baf8a8fa5a2a90c7468b8486ad72a92207791e3da32865256aa4cea8331"
      "ea4ed03743d8430a868e64d9e63ba8b85243761c64741b36d2918b86",
      "705727faad90fae99cd64fa23659235cb75cafce9e1ac27f1c929fb59f381f51cdc15b0c"
      "376dbde86a2dd6eb98a12fb3a27e3a2efe7f731ab3e9ef53282abe0f"
      "af33bfa2e423e3b2f8468cf956dd7f77187c1c858bb9e6f8b4f7e408f7f355dc2f68e8a9"
      "d82cf00b1d649fb278ced301187954f36fc639be38df4d5339ad9fe0",
      "eec44104643c83d8d372febebfaabe5b63f205f170eb15acd6ae1e9d4f44edbb3fb6ef26"
      "be0bd6efbb06aee97c4e16f8b6fd48cf1f58d54add80e5c477e3e2bb"
      "192aa7f5139c7470c47837d577eb4cbe20be9e7e7761bc71f5ddf7bffffc8c928f8cb8fb"
      "eebe21a0870fdad8c44a2fbb3f82ad4ebb332e26be7b557c37ec3eb8",
      "7d8e7e82c3a18ce7f4bc09356d766b7359fefb2d249fc8e40be2e1d6ed1f55f39a5f10df"
      "fef7cbad83c487c1fa7db8bea7aab933a570aa571bb074942db6a15a"
      "3a8c8f0f873dcf4dc6fc1c85873bcfa26b5a56d088a9f708db07b3eac65171f926d353b5"
      "a97d7034df4fba5af1bdf7fd74ef6be2bf60fdfe5b2e9cf55f5885fb",
      "e3438dcf5706c24967efb913a37bdfb8f86fd20fff1f5fd20f5f0c5fd20fcf46d20faf36"
      "ff5f1fe55241",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8728U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 2, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("PassingPrimitive"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("D:\\Documenti\\UNI\\Magistrale\\2\\Intelligent_"
                          "vehicles\\project\\PassingPrimitive.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739193.40942129632));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 1, "Name",
                emlrtMxCreateString("StoppingPrimitive"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "FullPath",
      emlrtMxCreateString("D:\\Documenti\\UNI\\Magistrale\\2\\Intelligent_"
                          "vehicles\\project\\StoppingPrimitive.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(739192.48822916672));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2365128 (R2023b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("te1vGkaAfctzWHTLSwX0lH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_primitives_info.c) */
