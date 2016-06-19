//
// Created by bl2312 on 24/05/16.
//

#include "NebController.h"

void NebController::addAccelerator(string name, shared_ptr<NebAccelerator> accelerator) {
    accelerators[name] = accelerator;
}

void NebController::setAccelerator(string accelerator) {
    this->accelerator = accelerators[accelerator];
}

void NebController::setup() {
    accelerator->setup();
}

void NebController::run() {
    accelerator->run();
}

vector<vector<float>> const &NebController::getPaths() {
    return accelerator->getPaths();
}













