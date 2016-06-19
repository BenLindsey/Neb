#include <stdio.h>
#include <stdlib.h>

#include <memory.h>
#include <vector>
#include <chrono>
#include <ctime>

#include "utils.h"

#include "MonteCarlo.h"

void logResult(float* result, int width, int height, double totalTime, double setupTime, double runTime)
{
	LogInfo("{\n");

	LogInfo("  \"totalTime\": %f,\n", totalTime);
	LogInfo("  \"setupTime\": %f,\n", setupTime);
	LogInfo("  \"runTime\": %f,\n", runTime);


        #ifndef TIMEONLY
	for (int i = 0; i < width * height; i++)
	{
		if (i % width == 0) {
			LogInfo("  \"simulation_%d\": [\n", i / width);
			LogInfo("    %f,\n", (float)OUTPUT_INITIAL);
		}

		LogInfo("    %f%s", result[i], ((i + 1) % width == 0) ?
			(i + 1 == width * height) ? "\n  ]\n" : "\n  ],\n" : ",\n");
	}

        #endif
	LogInfo("}\n");
}

int main(int argc, char* argv[])
{
	std::chrono::time_point<std::chrono::system_clock> _startTime, _endTime, _setupTime;
	_startTime = std::chrono::system_clock::now();

	int arrayWidth = Steps;
	int arrayHeight = Simulations;

	INPUTS_SETUP

        _setupTime = std::chrono::system_clock::now();

	for (int i = 0; i < arrayHeight; i++) {
		runOnce(i, RUN_ARGS);
	}

	_endTime = std::chrono::system_clock::now();

	std::chrono::duration<double> total_seconds = _endTime - _startTime;
	std::chrono::duration<double> setup_seconds = _setupTime - _startTime;
        std::chrono::duration<double> run_seconds = _endTime - _setupTime;
     
	logResult(dst, arrayWidth, arrayHeight, total_seconds.count(), setup_seconds.count(), run_seconds.count());

	INPUTS_FREE

	return 0;
}

