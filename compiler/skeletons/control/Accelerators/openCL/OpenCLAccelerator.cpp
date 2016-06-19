//
// Created by bl2312 on 01/06/16.
//

#include <functional>
#include "OpenCLAccelerator.h"
#include "OpenCLGenerated.h"

void OpenCLAccelerator::setup() {
    std::function<void(float*, float, int, int)> handle = [&] (float* result, float OUTPUT_INITIAL, int Simulations, int Steps) {
        for(int path = 0; path < Simulations; path++ ) {
            paths.push_back({OUTPUT_INITIAL});

            for (int i = 0; i < Steps; i++) {
                paths[path].push_back(result[path * Steps + i]);
            }
        }
    };

    runCallback = OpenCLGenerated::setupKernel(handle);
}

void OpenCLAccelerator::run() {
    runCallback();
}

vector<vector<float>> const &OpenCLAccelerator::getPaths() {
    return NebAccelerator::getPaths();
}





