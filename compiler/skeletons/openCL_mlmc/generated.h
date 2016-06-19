#ifndef CPP_MLMC_GENERATED_H
#define CPP_MLMC_GENERATED_H

struct _multilevel {
    constexpr static int N0    = 200;     // initial samples on each level
    constexpr static int Lmin  = 2;       // minimum refinement level
    constexpr static int Lmax  = 15;      // maximum refinement level
};

struct _regression {
    constexpr static int M = 2;           // Refinement Factor
    constexpr static int N = 20000;       // samples for convergence tests
    constexpr static int L = 8;           // levels for convergence tests
};

struct _modelParams { 
    constexpr static float EPS = 0.01f;   // Desired accuracy
};

#endif //CPP_MLMC_GENERATED_H
