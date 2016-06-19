//
// Created by bl2312 on 19/02/16.
//

#ifndef MLMC_MLMC_H_H
#define MLMC_MLMC_H_H

float mlmc(int Lmin, int Lmax, int N0, float eps,
           void (*mlmc_l)(int, int, double *),
           float alpha_0,float beta_0,float gamma, int *Nl);

#endif //MLMC_MLMC_H_H
