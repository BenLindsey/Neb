//
// Created by bl2312 on 19/02/16.
//

#ifndef MLMC_MLMC_TEST_H_H
#define MLMC_MLMC_TEST_H_H

#include <stdio.h>

struct greeks {
    float alpha;
    float beta;
    float gamma;
};

greeks mlmc_regress_greeks(void (*mlmc_l)(int, int, double *), int M,int N,int L);

void regression(int N, float *x, float *y, float &a, float &b);

#endif //MLMC_MLMC_TEST_H_H
