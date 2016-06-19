//
// Created by bl2312 on 24/05/16.
//

#ifndef CPP_BLACKSCHOLES_NEBACCELERATOR_H
#define CPP_BLACKSCHOLES_NEBACCELERATOR_H

#include <vector>

using namespace std;

class NebAccelerator {
public:
    virtual vector<vector<float>> const& getPaths() {}

    virtual void setup() {}

    virtual void run() {}

    virtual ~NebAccelerator() {}
};


#endif //CPP_BLACKSCHOLES_NEBACCELERATOR_H
