//
// Created by bl2312 on 01/06/16.
//

#ifndef CPP_BLACKSCHOLES_OPENCLACCELERATOR_H
#define CPP_BLACKSCHOLES_OPENCLACCELERATOR_H


#include "../NebAccelerator.h"

class OpenCLAccelerator : public NebAccelerator {
private:
    vector<vector<float>> paths;
    std::function<int(void)> runCallback;
public:
    void setup();
    void run();

    vector<vector<float>> const& getPaths();
};


#endif //CPP_BLACKSCHOLES_OPENCLACCELERATOR_H
