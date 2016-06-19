//
// Created by bl2312 on 24/05/16.
//

#ifndef CPP_BLACKSCHOLES_CPPACCELERATOR_H
#define CPP_BLACKSCHOLES_CPPACCELERATOR_H


#include "../NebAccelerator.h"
#include "CppGenerated.h"

class CppAccelerator : public NebAccelerator {
private:
    CPP_STATE
    vector<vector<float>> paths;
public:
    void setup();
    void run();

    vector<vector<float>> const& getPaths();
};


#endif //CPP_BLACKSCHOLES_CPPACCELERATOR_H
