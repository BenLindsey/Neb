//
// Created by bl2312 on 23/05/16.
//

#ifndef CPP_BLACKSCHOLES_SIMULATION_H
#define CPP_BLACKSCHOLES_SIMULATION_H

#include <chrono>
#include <string>
#include <memory>
#include "NebController.h"

using namespace std;

class Simulation {
private:
    chrono::time_point<chrono::system_clock> initialTime, endTime, setupTime;
    shared_ptr<NebController> controller;

    double getTotalDuration();
    double getSetupDuration();
    double getExecuteDuration();

    string toJSON(bool timeOnly);
public:
    Simulation(shared_ptr<NebController> controller);

    void run();

    string pathsToJSON();
    string timeToJSON();
};


#endif //CPP_BLACKSCHOLES_SIMULATION_H
