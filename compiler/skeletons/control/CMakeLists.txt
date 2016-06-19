cmake_minimum_required(VERSION 3.5)
project(cpp_blackScholes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lOpenCL")

set(SOURCE_FILES
        Main.cpp
        Utils.cpp
        Utils.h Simulation.cpp Simulation.h NebController.cpp NebController.h DefaultController.cpp DefaultController.h Accelerators/cpp/CppAccelerator.cpp Accelerators/cpp/CppGenerated.h Accelerators/cpp/CppAccelerator.h Accelerators/NebAccelerator.cpp Accelerators/NebAccelerator.h Accelerators/openCL/OpenCLAccelerator.cpp Accelerators/openCL/OpenCLAccelerator.h Accelerators/openCL/OpenCLGenerated.h Accelerators/openCL/OpenCLGenerated.cpp Accelerators/openCL/CL)

add_executable(cpp_blackScholes ${SOURCE_FILES})