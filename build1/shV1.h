//
// MATLAB コンパイラー:5.1 (R2014a)
// 日付:Sun Jun 08 12:17:06 2014
// 引数: "-B" "macro_default" "-B" "cpplib:shV1" "-W" "cpplib:shV1" "-T"
// "link:lib" "-d" "shV1" "shPars.m" "shModelV1Linear.m"
// "shModelFullWaveRectification.m" "shModelV1Blur.m"
// "shModelV1Normalization.m" "-a" "defaultParameters.mat" 
//

#ifndef __shV1_h
#define __shV1_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_shV1
#define PUBLIC_shV1_C_API __global
#else
#define PUBLIC_shV1_C_API /* No import statement needed. */
#endif

#define LIB_shV1_C_API PUBLIC_shV1_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_shV1
#define PUBLIC_shV1_C_API __declspec(dllexport)
#else
#define PUBLIC_shV1_C_API __declspec(dllimport)
#endif

#define LIB_shV1_C_API PUBLIC_shV1_C_API


#else

#define LIB_shV1_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_shV1_C_API 
#define LIB_shV1_C_API /* No special import/export declaration */
#endif

extern LIB_shV1_C_API 
bool MW_CALL_CONV shV1InitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_shV1_C_API 
bool MW_CALL_CONV shV1Initialize(void);

extern LIB_shV1_C_API 
void MW_CALL_CONV shV1Terminate(void);



extern LIB_shV1_C_API 
void MW_CALL_CONV shV1PrintStackTrace(void);

extern LIB_shV1_C_API 
bool MW_CALL_CONV mlxShPars(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_shV1_C_API 
bool MW_CALL_CONV mlxShModelV1Linear(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_shV1_C_API 
bool MW_CALL_CONV mlxShModelFullWaveRectification(int nlhs, mxArray *plhs[], int nrhs, 
                                                  mxArray *prhs[]);

extern LIB_shV1_C_API 
bool MW_CALL_CONV mlxShModelV1Blur(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_shV1_C_API 
bool MW_CALL_CONV mlxShModelV1Normalization(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                            *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_shV1
#define PUBLIC_shV1_CPP_API __declspec(dllexport)
#else
#define PUBLIC_shV1_CPP_API __declspec(dllimport)
#endif

#define LIB_shV1_CPP_API PUBLIC_shV1_CPP_API

#else

#if !defined(LIB_shV1_CPP_API)
#if defined(LIB_shV1_C_API)
#define LIB_shV1_CPP_API LIB_shV1_C_API
#else
#define LIB_shV1_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_shV1_CPP_API void MW_CALL_CONV shPars(int nargout, mwArray& pars);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Linear(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Linear(int nargout, mwArray& varargout);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Linear(const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Linear();

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelFullWaveRectification(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelFullWaveRectification(int nargout, mwArray& varargout);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelFullWaveRectification(const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelFullWaveRectification();

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Blur(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Blur(int nargout, mwArray& varargout);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Blur(const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Blur();

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Normalization(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Normalization(int nargout, mwArray& varargout);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Normalization(const mwArray& varargin);

extern LIB_shV1_CPP_API void MW_CALL_CONV shModelV1Normalization();

#endif
#endif
