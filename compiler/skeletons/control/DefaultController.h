//
// Created by bl2312 on 24/05/16.
//

#ifndef CPP_BLACKSCHOLES_DEFAULTCONTROLLER_H
#define CPP_BLACKSCHOLES_DEFAULTCONTROLLER_H


#include "NebController.h"

class DefaultController : public NebController {
public:
    void onStart();
    void onEnd();
};


#endif //CPP_BLACKSCHOLES_DEFAULTCONTROLLER_H
