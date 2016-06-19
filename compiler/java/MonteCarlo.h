#include <stdlib.h>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

int Simulations = 65536;
int Steps = 1024;
float kappa[4] = {0.2, 0.3, 0.6, 0.7};
float theta[4] = {-0.2, 0.8, 0.0, -0.3};
float epsilon[4] = {0.1, 0.5, 0.3, 0.2};
float dt[4] = {0.1, 0.9, 0.3, 0.4};
float minVar = 0.0;
float OUTPUT_INITIAL = 100.0;

inline void generateInput(float* r, float* r2) {
  auto array_size = Simulations * Steps;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> rGen(0, 1);
  std::normal_distribution<> r2Gen(0, 1);

  for (int i = 0; i < array_size; ++i) {
    r[i] = rGen(gen);
    r2[i] = r2Gen(gen);
  }
}

inline void runOnce(int currentHeight, float* r, float* r2, float* output) {
  float logspot = 100.0;
  float variance = 5.0;

  for(int i = 0; i < Steps; i++) {
    const int id = currentHeight * Steps + i;

    float kappaNow = kappa[i % 3];
    float thetaNow = theta[i % 3];
    float epsilonNow = epsilon[i % 3];
    float dtNow = dt[i % 3];
    float bFunc0 = max(variance, minVar);
    float uFunc0 = sqrt(bFunc0);
    float uFunc1 = sqrt(dtNow);
    
    float logspotTemp = logspot + 0.5 * dtNow * variance + uFunc0 * uFunc1 * r[id];
    float varianceTemp = variance + 0.5 * kappaNow * (thetaNow - bFunc0) + epsilonNow * uFunc0 * uFunc1 * r2[id];

    logspot = logspotTemp;
    variance = varianceTemp;

    output[id] = logspot;
  }
}

#define INPUTS_SETUP int rSize = sizeof(float) * arrayWidth * arrayHeight;\
float* r = (float*)malloc(rSize);\
int r2Size = sizeof(float) * arrayWidth * arrayHeight;\
float* r2 = (float*)malloc(r2Size);\
int dstSize = sizeof(float) * arrayWidth * arrayHeight;\
float* dst = (float*)malloc(dstSize);\
if (NULL == r || NULL == r2 || NULL == dst)\
{\
	LogError("Error: _aligned_malloc failed to allocate buffers.\n");\
	return -1;\
}\
\
generateInput(r, r2);


#define INPUTS_FREE free(r); free(r2); free(dst);
#define RUN_ARGS r, r2, dst
