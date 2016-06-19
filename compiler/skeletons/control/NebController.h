//
// Created by bl2312 on 24/05/16.
//

#ifndef CPP_BLACKSCHOLES_NEBCONTROLLER_H
#define CPP_BLACKSCHOLES_NEBCONTROLLER_H

#include "Accelerators/NebAccelerator.h"
#include "Accelerators/cpp/CppAccelerator.h"
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

class NebController {
private:
    unordered_map<string, shared_ptr<NebAccelerator>> accelerators;
    shared_ptr<NebAccelerator> accelerator;
public:
    void addAccelerator(string name, shared_ptr<NebAccelerator> accelerator);
    void setAccelerator(string accelerator);

    void setup();
    void run();
    vector<vector<float>> const& getPaths();

    //Event handlers
    virtual void onStart() {};
    virtual void onEnd() {};

    virtual ~NebController() {};
};


#endif //CPP_BLACKSCHOLES_NEBCONTROLLER_H
