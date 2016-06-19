cmake_minimum_required(VERSION 3.3)
project(cpp_mlmc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mlmc.cpp regression.cpp mlmc.h regression.h levelEstimator.cpp levelEstimator.h generated.h utils.h)
add_executable(cpp_mlmc ${SOURCE_FILES})