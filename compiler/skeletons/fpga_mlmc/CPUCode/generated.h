#ifndef CPP_MLMC_GENERATED_H
#define CPP_MLMC_GENERATED_H

struct _multilevel {
    constexpr static int N0    = 200;     // initial samples on each level
    constexpr static int Lmin  = 2;       // minimum refinement level
    constexpr static int Lmax  = 10;      // maximum refinement level
};

struct _regression {
    constexpr static int M = 2;           // Refinement Factor
    constexpr static int N = 20000;       // samples for convergence tests
    constexpr static int L = 8;           // levels for convergence tests
};

struct _modelParams { 
    constexpr static float EPS = 0.5f;   // Desired accuracy
    constexpr static float K   = 100.0f;  // Strike price
    constexpr static float X0  = 100.0f;  // Initial price
    constexpr static float T   = 2.0f;    // Expiry in years
    constexpr static float r   = 0.05f;   // risk free interest
    constexpr static float sig = 0.3f;    // the standard deviation of the stock's returns
};

#endif //CPP_MLMC_GENERATED_H
