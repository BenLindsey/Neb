#include <vector>

#include "Utils.h"

#include "Simulation.h"
#include "DefaultController.h"
#include "Accelerators/openCL/OpenCLAccelerator.h"

int main(int argc, char* argv[])
{
	// Initialise the controller with available accelerators.
	shared_ptr<NebController> controller(new DefaultController);
	controller->addAccelerator("CPU", shared_ptr<NebAccelerator>(new CppAccelerator));
	controller->addAccelerator("GPU", shared_ptr<NebAccelerator>(new OpenCLAccelerator));

	// Execute on the CPU by default.
	controller->setAccelerator("GPU");

	Simulation simulation(controller);

	simulation.run();

	LogInfo(simulation.timeToJSON());

	return 0;
}

