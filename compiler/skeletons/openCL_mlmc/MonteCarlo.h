#include <stdlib.h>
#include <random>
#include "CL/cl_ext.h"

cl_int Simulations = 10;
cl_int Steps = 10;
float vol = 0.2;
float drift = -0.1;
float dt = 0.2;
float OUTPUT_INITIAL = 100.0;

inline void generateInput(float* r) {
  auto array_size = Simulations * Steps;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> rGen(0, 1);

  for (cl_int i = 0; i < array_size; ++i) {
    r[i] = rGen(gen);
  }
}

#define INPUTS_MEM cl_mem r; 

#define INPUTS_INIT r(NULL), 

#define INPUTS_ARGS float* r, 

#define INPUTS_RELEASE if (r) \
{\
	err = clReleaseMemObject(r);\
	if (CL_SUCCESS != err)\
	{\
		LogError("Error: clReleaseMemObject returned '%s'.\n", TranslateOpenCLError(err));\
	}\
}

#define INPUTS_BUFFER ocl->r = clCreateBuffer(ocl->context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, sizeof(float) * arrayWidth * arrayHeight, r, &err);\
if (CL_SUCCESS != err)\
{\
	LogError("Error: clCreateBuffer for srcA returned %s\n", TranslateOpenCLError(err));\
	return err;\
}

#define INPUTS_SET err = clSetKernelArg(ocl->kernel, 0, sizeof(cl_mem), (void *)&ocl->r);\
if (CL_SUCCESS != err)\
{\
	LogError("error: Failed to set argument r, returned %s\n", TranslateOpenCLError(err));\
	return err;\
}\
err = clSetKernelArg(ocl->kernel, 1, sizeof(cl_mem), (void *)&ocl->dstMem);\
if (CL_SUCCESS != err)\
{\
	LogError("error: Failed to set argument dstMem, returned %s\n", TranslateOpenCLError(err));\
	return err;\
}

#define INPUTS_MALLOC cl_uint rSize = sizeof(float) * arrayWidth * arrayHeight;\
float* r = (float*)malloc(rSize);\
cl_uint dstSize = sizeof(float) * arrayWidth * arrayHeight;\
float* dst = (float*)malloc(dstSize);\
if (NULL == r || NULL == dst)\
{\
	LogError("Error: _aligned_malloc failed to allocate buffers.\n");\
	return -1;\
}\
\
generateInput(r);

#define INPUTS_BUFFER_ARGS r, dst

#define INPUTS_FREE //free(r); free(dst);

