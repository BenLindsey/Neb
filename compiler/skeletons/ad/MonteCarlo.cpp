#include <stdio.h>
#include <stdlib.h>

#include <memory.h>
#include <vector>
#include <chrono>
#include <ctime>

#include "utils.h"

#include "MonteCarlo.h"

void logResult(float result)
{
	LogInfo("{\n");

	LogInfo("  \"result\": %f,\n", result);

	LogInfo("}\n");
}

int main(int argc, char* argv[])
{
	INPUTS_SETUP        

	runOnce(RUN_ARGS);
	
	logResult(5);

	return 0;
}

