#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <ctime>
#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

const int Simulations = 65536;
const int Steps = 1024;

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

void logResult(float* result, int width, int height, double totalTime, double setupTime, double runTime)
{
    printf("{\n");
    printf("  \"totalTime\": %f,\n", totalTime);
    printf("  \"setupTime\": %f,\n", setupTime);
    printf("  \"runTime\": %f,\n", runTime);
    #ifndef TIMEONLY
    for (int i = 0; i < width * height; i++)
    {
        if (i % width == 0) {
            printf("  \"simulation_%d\": [\n", i / width);
            printf("    %f,\n", (float)OUTPUT_INITIAL);
        }
       printf("    %f%s", result[i], ((i + 1) % width == 0) ?
                (i + 1 == width * height) ? "\n  ]\n" : "\n  ],\n" : ",\n");
    }
    #endif
    printf("}\n");
}

int main(void)
{
  std::chrono::time_point<std::chrono::system_clock> _startTime, _endTime, _setupTime;
  _startTime = std::chrono::system_clock::now();
  int rSize = sizeof(float) * Simulations * Steps;
  float* r = (float*)malloc(rSize);
  int r2Size = sizeof(float) * Simulations * Steps;
  float* r2 = (float*)malloc(r2Size);

  generateInput(r, r2);

  int outputSize = sizeof(float) * Simulations * Steps;
  float* output = (float*)malloc(outputSize);

  _setupTime = std::chrono::system_clock::now();
  NebStream(r, r2, output);

  _endTime = std::chrono::system_clock::now();

  std::chrono::duration<double> total_seconds = _endTime - _startTime;
  std::chrono::duration<double> setup_seconds = _setupTime - _startTime;
  std::chrono::duration<double> run_seconds = _endTime - _setupTime;
  logResult(output, Steps, Simulations, total_seconds.count(), setup_seconds.count(), run_seconds.count());

  return 0;
}
