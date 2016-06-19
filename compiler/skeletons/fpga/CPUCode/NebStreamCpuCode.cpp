#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

const int Simulations = 64;
const int Steps = 64;

inline void generateInput(float* r) {
  auto array_size = Simulations * Steps;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> rGen(0.5, 1.0);

  for (int i = 0; i < array_size; ++i) {
    r[i] = rGen(gen);
  }
}

void logResult(float* result, int width, int height, double totalTime, double setupTime, double runTime)
{
    LogInfo("{
");
    LogInfo("  \"totalTime\": %f,
", totalTime);
    LogInfo("  \"setupTime\": %f,
", setupTime);
    LogInfo("  \"runTime\": %f,
", runTime);
    #ifndef TIMEONLY
    for (int i = 0; i < width * height; i++)
    {
        if (i % width == 0) {
            LogInfo("  \"simulation_%d\": [
", i / width);
            LogInfo("    %f,
", (float)OUTPUT_INITIAL);
        }
       LogInfo("    %f%s", result[i], ((i + 1) % width == 0) ?
                (i + 1 == width * height) ? "
  ]
" : "
  ],
" : ",
");
    }
    #endif
    LogInfo("}
");
}

int main(void)
{
  int rSize = sizeof(float) * Simulations * Steps;
  float* r = (float*)malloc(rSize);

  generateInput(r);

  int outputSize = sizeof(float) * Simulations * Steps;
  float* output = (float*)malloc(outputSize);

  NebStream(r, output);

  logResult(output, Simulations, Steps, 0, 0, 0;

  return 0;
}
