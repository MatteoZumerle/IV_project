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
      "789ced5bbf73124114de38d1b1d084d1d1b1b075469b0c842424369a1c2430787009093f"
      "121c21b0070bf76bee0e42f20f585ada3bfe0199b1b173c6cecadec6"
      "c6cedac2ce1cc701b77107c21d046e769be5cd77ecf7f6edee37efde02988bb173008005"
      "60b6978cd9dfedd8be4e7f03d81b8ecf75fa3b986db59b60def63d0b",
      "7fd7e94bb2a4c3966e1a525184dd6f966511494549df3f552050a1260b4d586e233c12e0"
      "3e1261aadf481896b8dd07750d03323e335558aaa71a2250ab5acf43"
      "a1dfe8c6e39c30dff921e3c111e2e1c3f0a3c8ebf0f37c582e354428e9287f9088e5d962"
      "0569ba5a14607e391fbb888f20a0ca05faa609aba824402dafa8720d",
      "96f43c57d434245538158948474db8245afe2b0efdc76ddc7fabe72fd648482aba1167c3"
      "1b8bbfe090ff1691df44ca72e35880b3b65e78b47aeb5520f8b738a4"
      "ff78df7bfe76bbaf3ffed18626c5f7e2c34779927c56bb2ebe1661bc61f7df43029f0fc3"
      "d136bfbea3b32b9128d72c665a1cb7968ac6989e1fd63e25f10cf203",
      "10ec498d3f1be7787cbabb80d9b8ff16ae5f28088ba434140c5f06effb69d5dd0491cf8e"
      "3b5b2f7bb496c4c9e9c4a47517fefd447517b8afbb153fc79f650299"
      "4c40cd26e0a952e72207bb54773da3bb8b988dfb6fe156066709efacea6e92c867c7ddc9"
      "777bc2eb55dd3ddf784f75170cbfff1e10f87c189e0a9c34c2a596bc",
      "173c8986a07f65b90a1bc780eaeeb4e8aed37d707f80ff160e9b45a14bcfc890e7cdaacd"
      "75e9ef67877c29229f1d77b66eff899a91fc02efe6bfa52765aac3c0"
      "fdfcf760259b930301a60a6b1b213e9b91828727f1b07774d8e979de238cefc3707775b8"
      "e6ef1c67d7f6c3bd01f3b070bc9259f3dbfd2838f463d27a3c99f5bb",
      "1c357cfd0a043f67558f1f1d99af66548f87e31b568f45763513090a289ece89eb99d5b4"
      "76f66a7d739beaf1b4e9b1d3ba047e6f8acfc3c2fbdeb4db523cab75"
      "0996c867c75dab4b7496ccabfafb2dfb93e6c3600cf930b319429518cf2673f12d890f29"
      "62944944a8fe4e9bfed2fac4687cb43e311e3e5a9f301bad4f5c6d7c",
      "a7e7799730be0fc39d9de7942e2b8abd508ccdc3693e4c8a9b0febfbdfb40daf66351fe6"
      "301b60cf59b87b7509235adefd5ddab35f6fa9fe02f7f577275b29f1"
      "71357a56cf458e959cce04b460758beaefb4e92fcd8747e3a3f9f078f8683e6c369a0f5f"
      "6dfcd938cf97f4b85ba0b8cefb3ac32b7a5f374a5eecfdfbba2fbfbf",
      "533d06eeeb311bd4e3ec16c7e476f624556ea4831b0242b45e3c757aecb43e71d5fb3a4e"
      "d6e87dddd03adc8e96a7efeb9efef94af517b8afbfd9b5cc29cba148"
      "722da926c56679b5291f363cf4ff0dafe82fad4f8cc647eb13e3e1a3f509b3d1fac470e3"
      "ff03a5138158",
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
      emlrtCreateStructMatrix(1, 5, 8, (const char_T **)&epFieldName[0]);
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
                emlrtMxCreateDoubleScalar(739205.50730324071));
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
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 4, "Name", emlrtMxCreateString("v_opt_fun"));
  emlrtSetField(xEntryPoints, 4, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 4, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 4, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 4, "FullPath",
      emlrtMxCreateString("D:\\Documenti\\UNI\\Magistrale\\2\\Intelligent_"
                          "vehicles\\project\\v_opt_fun.m"));
  emlrtSetField(xEntryPoints, 4, "TimeStamp",
                emlrtMxCreateDoubleScalar(739211.50776620372));
  emlrtSetField(xEntryPoints, 4, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 4, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2365128 (R2023b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("O4Qt6hlYRwAXIlMChHCOFC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_primitives_info.c) */
