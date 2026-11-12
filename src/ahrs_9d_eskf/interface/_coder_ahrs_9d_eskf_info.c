/*
 * File: _coder_ahrs_9d_eskf_info.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Nov-2026 16:35:46
 */

/* Include Files */
#include "_coder_ahrs_9d_eskf_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[17] = {
      "789ced9dcd92e25414c7333a7e55e9387eccacd4d25959a533dd304d038b290768ba810e"
      "d040d3cd606908e1120221a173131a283796eec7854b17b3b02ccb95"
      "0fe0ca2a1fc19d6b9f40f7361d32109a482070bb933e67930907eeffccbd757f7d727208"
      "d48d64fa064551b728dd7efe513fbe313abf3d3abe40996dda7f6374",
      "fc60eadcb097a89ba6cf19fea7a323274b2aeaa9fa89c4b6d1f34fd6e4b620b1927ad8ef"
      "204a415816bba876eea90b223a14daa8307992199eb577275ccf4f86"
      "aee1bf630dc4b50a5a9b521a781ca13879329e0f8bffef4d9bf311b3988fdb53fecfe35f"
      "6c34e436da905047d524745f14a45a6f032bdc469a5545b6bac13614",
      "7c3f5cbb8f70abbe216b6a475337588e6338595110a73e689be2ee398cfbee9cb80d3f8f"
      "54a62160a6d3e86381634506abac8ac671541cc6f1b2651cba07ab8a"
      "c6a963bd5f1dea652cf5ccfee5d66bf66c0d976ede7cbd6933fee9e3f8fdaf9e1f51f3df"
      "e6f0484aef7150798fa49e6197a5476adfe5b44441ea67f83c5b0bfa",
      "71cc1fa7eb2a4a8ce33898a3332f0ecae29cd4f8d795bb77e6c46df815b9aa61951178fe"
      "21234875f10c234c9e22c85d41e245b43aeea62df5ccfee5d66be66c"
      "9daf1c294ef81abf10e5ee77dfffe927a96798d7b9bb57663338d5f4279ba95a3b89e5b0"
      "58a2f7f680bb6ee7ee3b73e236fcf1c2feee194254c42b6710a93167",
      "1199e2a8388c8374bebb6fa967f62fb75e33666b6add2a16f1ad8a13df10ce77e58fbe7e"
      "4052cf30af7337bbcd1f64e265813fdca47372ad968ce4f23b51e0ae"
      "dbb9fbee9cb80dbf20214515ceae9859a5811905755841998ca3e2300ed2dca52df5ccfe"
      "e5d66bd66ce90b478a1315c2dcdd7ad4bb4752cf30b772d7ee7526ef",
      "cf0d72fd42bed4cc76a2a5b080c2ad81467987bb6edfc7a4f2de3a42b52acbb58c3f0382"
      "2c519371541cc6e1adbc77c66c11ce7ba31259fefefdc3c71f92d433"
      "ccebfc6d88e9684e9371618b6e8582dca02c17114f017faffa3eb61bff2b96f1eb1e2c3f"
      "6450af736975dd670ef53eb3d433fb975b9fd1ec9cad09290e3c2d1e",
      "12e5eae6efdfde21a967985bb96ab79e10de4b28695ecc3d0946fbdd449eae3dc9a5aa1e"
      "aae33eb3f8fc55ddb71d87f1de9a3a9f8ed7f0e3163a6570bfdd46aa"
      "22709777bfcc69bd67d752cfec5f727d4cb344b23f01f8ba5e3d527ced061207b2ac6e25"
      "e97c70f3a45cc844f9a3a39877f8eaf6bc95146fb9aae43fd1581529",
      "d279c900783b6bbdccb304bc05de2eca5b5adbe92991b8540c0adbe9405da4bb74b2e0a1"
      "7cd6adfb97d4fdb1b13a23c94a9b1585c1790bb55bfbc1d65b579f35"
      "5b64ef8f0177d7ab478abbaaafa8e080d069555b9d81985523ad9c4f8c7b87bb577b1faf"
      "fffed85b73e237fc5aa7366c2a9d4c75a9c9382a0ee320cddfa4a59e",
      "d9bfdcba5d98add1d509f017f8ab9b5dfe068afb7c1c274322573cca6c250b9954bebbed"
      "a1be30b7ef63c87f97d383fc77b57ac05fdd20ff5d6cfcabbd8fe7e7"
      "bfa4eabc63a2f8b92ad479e77277384b50e705de2ecadbea015d5742fb5cbde84b75f9d3"
      "ea51a498c8ee7887b74ef7ef8ec5f8b7a7fc4b7e0fe2ec3546908421",
      "73575b67b09be72a0823f5c2d316dcdb87bbdebf8fb3668b6c9efb88f0f720529ffef13a"
      "493dc3bcce5ddcf129ed53b57d944a6b285614caa7314ef1503f835b"
      "b9eb34bf7d6d4edc861f692252f4d4969ad4af38d4279ddf462cf5ccfee5d6e9f92c11af"
      "e7c2f315d6ab47ac9e9b0ca68ea35b75fff14928ac6d3e394e358f25",
      "c86f5dcf59e81733bf0ffac5ece9411d4137e8175b6c7cb77296d4faeb57c6c36711e23e"
      "56511b9edb38bf8e303d5b24b92b11ae233cb8f9173cb7915afdbed3"
      "ba83635c7a1809ec96aa4514de6623fe4d19f25bd773d76e9fd8243f988e861ba3d7ddca"
      "ddf5f6975c982de275852661eefef68ffa3e493dc3dcca5dbbcf5190",
      "f77be1a3362d46fc79c547974f8e0b9b2196f20e779dee63527d0a4300eb5d63d0a73bb4"
      "abcd5fe8d35db79e616ee52ff4e9eae676fe92aaef429f18f4894dea"
      "016f75833eb1c5c6bfeebcb5dbb730bc53747e577e74ee56de462cf5ccfee5efa79dcf12"
      "f42dac58cf30aff37667dba7d1276add471762a17856486dc5b229f8",
      "1ec495e12dd47797d383faee6af5a0beab1bd477171bdfe93e26717f5cdfc6d53ed3674f"
      "19b98a27af5b49e5bbd0a70b7dba937a90efea067dba8b8d7fdd790b"
      "fdbae6f741bfae3d3da8e7ea06fdba8b8def76de42dfee727ad0b7bb5a3de8dbd50dfa76"
      "171bff6af7ed0e815b1558cc20acaeb6aefbf69cb80dbfc2d60456c2",
      "0c274b5d46ea301d417fddad7d63294b3db37f49ee5e982da3d0408a135fdefdc9d67331"
      "bcc241d27aa4b83ba8f677437525942e96fc74b39ced97d4ddbe87ee"
      "ab5deddffd1d72773dbffb6b77fdf951fe36fdc41bc87767add7ecd92299ef22c2f9eee3"
      "a002f92eb5fa7d97d31205a99fe1f36c2de8c7317f9caeab2801dcbd",
      "6cee3aadeb42df98f97d861ffac6fe5f0feea3e9067d638b8def56ce92ade74e579621bf"
      "5db60e5fb1886f559cc084f3dbaf229fbc4852cf30b772d76ebf58ba"
      "11a0836c800e0573074ababc17407b87590ab8eb76ee423d775acfec877aae3d3dc3ae8b"
      "1ed4735733fe75e5aedde797cffac58ac9382a0ee3f0d6f3cbe7ffbe",
      "47c522be5571a24238dfdd7ad4bb4752cf30b772d76ebecbfb73835cbf902f35b39d6829"
      "2ca0706ba051eee7ee7f9cfd0994",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 42176U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
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
      emlrtCreateStructMatrix(1, 26, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("acc_correct"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/acc_correct.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.65553240746));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 1, "Name", emlrtMxCreateString("ahrs_initial"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/ahrs_initial.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64388888888));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 2, "Name", emlrtMxCreateString("cbn2euler"));
  emlrtSetField(xEntryPoints, 2, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 2, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 2, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 2, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/cbn2euler.m"));
  emlrtSetField(xEntryPoints, 2, "TimeStamp",
                emlrtMxCreateDoubleScalar(740241.74871527776));
  emlrtSetField(xEntryPoints, 2, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 2, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 3, "Name", emlrtMxCreateString("cbn2quaternion"));
  emlrtSetField(xEntryPoints, 3, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 3, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 3, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 3, "FullPath",
                emlrtMxCreateString("/home/neptune-lindx/src/Matlab/"
                                    "ahrs-9d-eskf/output/cbn2quaternion.m"));
  emlrtSetField(xEntryPoints, 3, "TimeStamp",
                emlrtMxCreateDoubleScalar(740176.46091435186));
  emlrtSetField(xEntryPoints, 3, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 3, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 4, "Name",
                emlrtMxCreateString("ESKF_integrated_acc"));
  emlrtSetField(xEntryPoints, 4, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 4, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 4, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 4, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "ESKF_integrated_acc.m"));
  emlrtSetField(xEntryPoints, 4, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64447916672));
  emlrtSetField(xEntryPoints, 4, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 4, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 5, "Name",
                emlrtMxCreateString("ESKF_variables_initial"));
  emlrtSetField(xEntryPoints, 5, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 5, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 5, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 5, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "ESKF_variables_initial.m"));
  emlrtSetField(xEntryPoints, 5, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64371527778));
  emlrtSetField(xEntryPoints, 5, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 5, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 6, "Name", emlrtMxCreateString("euler2cbn"));
  emlrtSetField(xEntryPoints, 6, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 6, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 6, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 6, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/euler2cbn.m"));
  emlrtSetField(xEntryPoints, 6, "TimeStamp",
                emlrtMxCreateDoubleScalar(740241.74871527776));
  emlrtSetField(xEntryPoints, 6, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 6, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 7, "Name",
                emlrtMxCreateString("feedback_correction"));
  emlrtSetField(xEntryPoints, 7, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 7, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 7, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 7, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "feedback_correction.m"));
  emlrtSetField(xEntryPoints, 7, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.65557870374));
  emlrtSetField(xEntryPoints, 7, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 7, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 8, "Name",
                emlrtMxCreateString("get_his_physical_state"));
  emlrtSetField(xEntryPoints, 8, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 8, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 8, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 8, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "get_his_physical_state.m"));
  emlrtSetField(xEntryPoints, 8, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.6441319444));
  emlrtSetField(xEntryPoints, 8, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 8, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 9, "Name",
                emlrtMxCreateString("inertial_ahrs_update"));
  emlrtSetField(xEntryPoints, 9, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 9, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 9, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 9, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "inertial_ahrs_update.m"));
  emlrtSetField(xEntryPoints, 9, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64403935184));
  emlrtSetField(xEntryPoints, 9, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 9, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 10, "Name",
                emlrtMxCreateString("inertial_arhs_repair"));
  emlrtSetField(xEntryPoints, 10, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 10, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 10, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 10, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "inertial_arhs_repair.m"));
  emlrtSetField(xEntryPoints, 10, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64407407411));
  emlrtSetField(xEntryPoints, 10, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 10, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 11, "Name",
                emlrtMxCreateString("load_ESKF_config"));
  emlrtSetField(xEntryPoints, 11, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 11, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 11, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 11, "FullPath",
                emlrtMxCreateString("/home/neptune-lindx/src/Matlab/"
                                    "ahrs-9d-eskf/output/load_ESKF_config.m"));
  emlrtSetField(xEntryPoints, 11, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.68609953707));
  emlrtSetField(xEntryPoints, 11, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 11, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 12, "Name",
                emlrtMxCreateString("physical_state_initial"));
  emlrtSetField(xEntryPoints, 12, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 12, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 12, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 12, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "physical_state_initial.m"));
  emlrtSetField(xEntryPoints, 12, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.6436689815));
  emlrtSetField(xEntryPoints, 12, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 12, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 13, "Name",
                emlrtMxCreateString("quaternion2cbn"));
  emlrtSetField(xEntryPoints, 13, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 13, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 13, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 13, "FullPath",
                emlrtMxCreateString("/home/neptune-lindx/src/Matlab/"
                                    "ahrs-9d-eskf/output/quaternion2cbn.m"));
  emlrtSetField(xEntryPoints, 13, "TimeStamp",
                emlrtMxCreateDoubleScalar(740176.46091435186));
  emlrtSetField(xEntryPoints, 13, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 13, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 14, "Name",
                emlrtMxCreateString("quaternion_normalize"));
  emlrtSetField(xEntryPoints, 14, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 14, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 14, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 14, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "quaternion_normalize.m"));
  emlrtSetField(xEntryPoints, 14, "TimeStamp",
                emlrtMxCreateDoubleScalar(740176.46091435186));
  emlrtSetField(xEntryPoints, 14, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 14, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 15, "Name",
                emlrtMxCreateString("radians_conv_np_pi"));
  emlrtSetField(xEntryPoints, 15, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 15, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 15, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 15, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "radians_conv_np_pi.m"));
  emlrtSetField(xEntryPoints, 15, "TimeStamp",
                emlrtMxCreateDoubleScalar(739267.56849537033));
  emlrtSetField(xEntryPoints, 15, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 15, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 16, "Name",
                emlrtMxCreateString("reset_his_system_state"));
  emlrtSetField(xEntryPoints, 16, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 16, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 16, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 16, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "reset_his_system_state.m"));
  emlrtSetField(xEntryPoints, 16, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64423611108));
  emlrtSetField(xEntryPoints, 16, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 16, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 17, "Name",
                emlrtMxCreateString("reset_physical_state"));
  emlrtSetField(xEntryPoints, 17, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 17, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 17, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 17, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "reset_physical_state.m"));
  emlrtSetField(xEntryPoints, 17, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.6436689815));
  emlrtSetField(xEntryPoints, 17, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 17, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 18, "Name",
                emlrtMxCreateString("reset_state_by_yaw_obs"));
  emlrtSetField(xEntryPoints, 18, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 18, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 18, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 18, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "reset_state_by_yaw_obs.m"));
  emlrtSetField(xEntryPoints, 18, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64429398149));
  emlrtSetField(xEntryPoints, 18, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 18, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 19, "Name",
                emlrtMxCreateString("robust_igg3_inflate_R"));
  emlrtSetField(xEntryPoints, 19, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 19, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 19, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 19, "FullPath",
      emlrtMxCreateString("/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/"
                          "robust_igg3_inflate_R.m"));
  emlrtSetField(xEntryPoints, 19, "TimeStamp",
                emlrtMxCreateDoubleScalar(740241.74871527776));
  emlrtSetField(xEntryPoints, 19, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 19, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 20, "Name",
                emlrtMxCreateString("skew_symmetric"));
  emlrtSetField(xEntryPoints, 20, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 20, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 20, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 20, "FullPath",
                emlrtMxCreateString("/home/neptune-lindx/src/Matlab/"
                                    "ahrs-9d-eskf/output/skew_symmetric.m"));
  emlrtSetField(xEntryPoints, 20, "TimeStamp",
                emlrtMxCreateDoubleScalar(740176.46091435186));
  emlrtSetField(xEntryPoints, 20, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 20, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 21, "Name", emlrtMxCreateString("so3_exp"));
  emlrtSetField(xEntryPoints, 21, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 21, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 21, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 21, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/so3_exp.m"));
  emlrtSetField(xEntryPoints, 21, "TimeStamp",
                emlrtMxCreateDoubleScalar(740176.46091435186));
  emlrtSetField(xEntryPoints, 21, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 21, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 22, "Name",
                emlrtMxCreateString("system_state_push"));
  emlrtSetField(xEntryPoints, 22, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 22, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 22, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 22, "FullPath",
                emlrtMxCreateString("/home/neptune-lindx/src/Matlab/"
                                    "ahrs-9d-eskf/output/system_state_push.m"));
  emlrtSetField(xEntryPoints, 22, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.6441898148));
  emlrtSetField(xEntryPoints, 22, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 22, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 23, "Name",
                emlrtMxCreateString("update_quaternion"));
  emlrtSetField(xEntryPoints, 23, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 23, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 23, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 23, "FullPath",
                emlrtMxCreateString("/home/neptune-lindx/src/Matlab/"
                                    "ahrs-9d-eskf/output/update_quaternion.m"));
  emlrtSetField(xEntryPoints, 23, "TimeStamp",
                emlrtMxCreateDoubleScalar(740176.46091435186));
  emlrtSetField(xEntryPoints, 23, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 23, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 9);
  emlrtSetField(xEntryPoints, 24, "Name", emlrtMxCreateString("yaw_bias_est"));
  emlrtSetField(xEntryPoints, 24, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(9.0));
  emlrtSetField(xEntryPoints, 24, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 24, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 24, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/yaw_bias_est.m"));
  emlrtSetField(xEntryPoints, 24, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.64439814817));
  emlrtSetField(xEntryPoints, 24, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 24, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 25, "Name", emlrtMxCreateString("yaw_correct"));
  emlrtSetField(xEntryPoints, 25, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 25, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 25, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 25, "FullPath",
      emlrtMxCreateString(
          "/home/neptune-lindx/src/Matlab/ahrs-9d-eskf/output/yaw_correct.m"));
  emlrtSetField(xEntryPoints, 25, "TimeStamp",
                emlrtMxCreateDoubleScalar(740298.6555555556));
  emlrtSetField(xEntryPoints, 25, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 25, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2365128 (R2023b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("iV7PZaZM9NMXBcPy0jWLzE"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_ahrs_9d_eskf_info.c
 *
 * [EOF]
 */
