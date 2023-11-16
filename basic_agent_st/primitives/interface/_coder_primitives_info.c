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
  const char_T *data[9] = {
      "789ced5a3d73124118de38f1a3d084d1514b0b9db1cb104288b19200e1231cdf84883842"
      "8e058edc17c741c03f60a556fe02c74a0b4b2b1b5b1bdb8cf6fe0c39"
      "e080dbb803e18e0b77b3db6cde79609ff7debd7de6e5d9809530b50200580383f1cc3798"
      "6f0d63c770be02b403c55786f34d2456c755b0aaf99e8abf1fceb4c0",
      "cbb0230f02bec4c1d137cb02c7f0255ece74450824d814d8362cf7910ac3c20cc3c1f464"
      "1053226e7f021a050aa4fcedab41fa24dde280546b8e33642783513d"
      "be629e7775c67a2430f57020f88bc04bffd3825fa05b1ce465a6908d850b54a9ca3465a9"
      "c4c282ab10eed58765996a0f7dd58635866661b3204a421dd2722151",
      "6a3619be9a90188e919936dce0d4fc459df9a3319abf3a577a7bc4c64559a9b3928dca5f"
      "d4c97f0dcb3f40ca42eb988556db2fb45ae3fd2a62f25b9f317f741e"
      "7ffe467ffe72ffac0f99c577fde7f7df66f2a9e3b2f83a98f5667dffee61f81c08ce96f3"
      "1eafbb553f62e151c39563a5e0261d088ef350df531ccfb43c002636",
      "6b7d6b9ce3c5e9ee1a12a3f9abb8dc53108ae10f21abe432fdbd5f56dd8d61f9b4b8befd"
      "d2566b83334f27ccd6ddc79fce88ee02e375177aa227de46bebbefe4"
      "5e773a5e5f758f6af988eeda4677d79118cd5fc5d50e4e155eabea6e1ccba7c58de977c7"
      "c26b57ddddfbf181e82e305e77a3db1e8a77fa6a99a0c405d85c53ca",
      "0553a28fe8eeb2e8aedef7e0ce94fc551cb64bec88de27c04a65e0da5c96fe7ed3c997c6"
      "f269717dfbf69faa29cd2fb06ffffbf0e303a2c360f6f7f02e86cf81"
      "e0622492a6ebad9d831c8c30815c38dd0d0a6d601f1dd67b9e5398f51d086eac0ed79dc3"
      "e36cd8fb707bca73a838ea64d69dda3c8a3af3305b8fcdd9bff35543",
      "f7af88c9d3aa7afc2efdf98f997ceab0aa1ecfda17b7bbd1a89f17774f3dd56c2893943c"
      "f44ebe6ea3bed81ae779ba1eebf525d07b53f439547ce297765f8aad"
      "ea4b50583e2d6e982f31dc32bbea6fa59825fa0b8cd7dfad74743b72908c1cedd299863b"
      "b4751c0fb6366de407db457f893f311f1ff12716c347fc89c120fec4",
      "c5d6d77b9e9398f51d08aeef3ca7654114b54631f21c7afb615cdd1cc83cf94b5bc9caaa"
      "fd70028901f2391537ce9750aa65dfff4bcbb724a2bfc0f87ed87d42"
      "e56afbb543baea7dde86ae50dc95e2227ea2bfcba6bfa41f9e8f8ff4c38be123fdf06090"
      "7ef862eb5be33c9fd3e391417199f7754a56e4be6e9ebed8fef7756f",
      "df3c227e3130be3fce1f65f3b56a76339615126272e789fb20560f86881e2f9b1eebf527"
      "2e7a5f97109ae4be6e661dee57cbd6f7757f7fad12fd05c6eb2fe5a9"
      "e522c9c429e4b36caa5bc9d61b7b398adcd72d9dfe127f623e3ee24f2c868ff8138341fc"
      "89d9d6ff076b0888bd",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 17240U, &nameCaptureInfo);
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
      emlrtCreateStructMatrix(1, 4, 8, (const char_T **)&epFieldName[0]);
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
                emlrtMxCreateDoubleScalar(739205.46898148151));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 1, "Name",
                emlrtMxCreateString("PassingPrimitivej0"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "FullPath",
      emlrtMxCreateString("D:\\Documenti\\UNI\\Magistrale\\2\\Intelligent_"
                          "vehicles\\project\\PassingPrimitivej0.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(739205.46925925929));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 2, "Name",
                emlrtMxCreateString("StoppingPrimitive"));
  emlrtSetField(xEntryPoints, 2, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 2, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 2, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 2, "FullPath",
      emlrtMxCreateString("D:\\Documenti\\UNI\\Magistrale\\2\\Intelligent_"
                          "vehicles\\project\\StoppingPrimitive.m"));
  emlrtSetField(xEntryPoints, 2, "TimeStamp",
                emlrtMxCreateDoubleScalar(739205.46915509261));
  emlrtSetField(xEntryPoints, 2, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 2, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 3, "Name",
                emlrtMxCreateString("StoppingPrimitivej0"));
  emlrtSetField(xEntryPoints, 3, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 3, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 3, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 3, "FullPath",
      emlrtMxCreateString("D:\\Documenti\\UNI\\Magistrale\\2\\Intelligent_"
                          "vehicles\\project\\StoppingPrimitivej0.m"));
  emlrtSetField(xEntryPoints, 3, "TimeStamp",
                emlrtMxCreateDoubleScalar(739205.469363426));
  emlrtSetField(xEntryPoints, 3, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 3, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2365128 (R2023b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("tjW6ubnNTB5z7qxfVdJU3F"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_primitives_info.c) */
