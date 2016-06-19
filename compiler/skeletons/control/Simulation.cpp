//
// Created by bl2312 on 23/05/16.
//

#include <sstream>
#include <vector>
#include "Simulation.h"

Simulation::Simulation(shared_ptr<NebController> controller) {
    this->controller = controller;
}

void Simulation::run() {
    initialTime = std::chrono::system_clock::now();

    controller->setup();

    setupTime = std::chrono::system_clock::now();

    controller->run();

    endTime = std::chrono::system_clock::now();
}


double Simulation::getTotalDuration() {
    chrono::duration<double> range = endTime - initialTime;

    return range.count();
}

double Simulation::getSetupDuration() {
    chrono::duration<double> range = setupTime - initialTime;

    return range.count();
}

double Simulation::getExecuteDuration() {
    chrono::duration<double> range = endTime - setupTime;

    return range.count();
}

string Simulation::pathsToJSON() {
    return toJSON(false);
}

string Simulation::timeToJSON() {
    return toJSON(true);
}

string Simulation::toJSON(bool timeonly) {
    stringstream result;

    result << "{\n";

    result << "  \"totalDuration\": " << getTotalDuration() << ",\n";
    result << "  \"setupDuration\": " << getSetupDuration() << ",\n";
    result << "  \"executeDuration\": " << getExecuteDuration() << ",\n";

    vector<vector<float>> const& paths = controller->getPaths();

    
    if(!timeonly) {
        for(int i = 0; i < paths.size(); i++) {
            result << "  \"simulation_" << i << "\": [\n";

            vector<float> const& path = paths[i];

            for(int j = 0; j < path.size(); j++) {
                result << "    " << path[j] << (j + 1 == path.size() ? "" : ",") << "\n";
            }

            result << "  ]" << (i + 1 == paths.size() ? "" : ",") << "\n";
        }
    }

    result << "}\n";

    return result.str();
}












