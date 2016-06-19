#include <stdlib.h>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

int Simulations = 3;
int Steps = 1000;
float a = 0.02;
float b = 0.2;
float c = -65.0;
float d = 8.0;
float I = 20.0;
float OUTPUT_INITIAL = -50.0;

inline void generateInput(float* r) {
  auto array_size = Simulations * Steps;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> rGen(0.02, 0.3);

  for (int i = 0; i < array_size; ++i) {
    r[i] = rGen(gen);
  }
}

inline void runOnce(int currentHeight, float* r, float* output) {
  float v = -50.0;
  float u = 10.0;

  for(int i = 0; i < Steps; i++) {
    const int id = currentHeight * Steps + i;

    float vTemp = v >= 30 ? c : v + r[id] * (0.04 * v * v + 5 * v + 140 - u + I);
    float uTemp = v >= 30 ? u + d : u + r[id] * (a * (b * v - u));

    v = vTemp;
    u = uTemp;

    output[id] = v;
  }
}

#define INPUTS_SETUP int rSize = sizeof(float) * arrayWidth * arrayHeight;\
float* r = (float*)malloc(rSize);\
int dstSize = sizeof(float) * arrayWidth * arrayHeight;\
float* dst = (float*)malloc(dstSize);\
if (NULL == r || NULL == dst)\
{\
	LogError("Error: _aligned_malloc failed to allocate buffers.\n");\
	return -1;\
}\
\
generateInput(r);


#define INPUTS_FREE free(r); free(dst);
#define RUN_ARGS r, dst
