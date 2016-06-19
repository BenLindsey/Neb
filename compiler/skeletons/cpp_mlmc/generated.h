#ifndef CPP_MLMC_GENERATED_H
#define CPP_MLMC_GENERATED_H

#include <random>

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
    constexpr static float EPS = 0.05f;   // Desired accuracy
    constexpr static float K   = 100.0f;  // Strike price
    constexpr static float X0  = 100.0f;  // Initial price
    constexpr static float T   = 2.0f;    // Expiry in years
    constexpr static float r   = 0.05f;   // risk free interest
    constexpr static float sig = 0.3f;    // the standard deviation of the stock's returns
};

static std::random_device rd;
static std::mt19937 gen(rd());
static std::normal_distribution<> randomGen(0, 1);

struct state {
    float logspot_hf;
    float logspot_hc;
    float logspot_xf;
    float logspot_xc;
    float dWf[2];

    state(int nf, int nc) {
        logspot_hf = _modelParams::T / ((float) nf);
        logspot_hc = _modelParams::T / ((float) nc);
    }

    void nextSample() {
        logspot_xf = 100.0;
        logspot_xc = 100.0;
    }

    void baseUpdate() {
        dWf[0] = sqrt(logspot_hf)*randomGen(gen);
        logspot_xf = stateUpdate(logspot_xf, logspot_hf, dWf[0]);
    }

    void levelUpdate() {
        dWf[0] = sqrt(logspot_hf)*randomGen(gen);
        dWf[1] = sqrt(logspot_hf)*randomGen(gen);

        for (int m=0; m<2; m++) {
            logspot_xf = stateUpdate(logspot_xf, logspot_hf, dWf[m]);
        }

        float dWc = dWf[0] + dWf[1];

        logspot_xc = stateUpdate(logspot_xc, logspot_hc, dWc);
    }

    float stateUpdate(float previous, float h, float dW) {
        return previous + _modelParams::r*previous*h + _modelParams::sig*previous*dW
               + 0.5f*_modelParams::sig*_modelParams::sig*previous*(dW*dW-h);
    }

    float payoff(float x) {
        return exp(-0.05f*_modelParams::T) * fmaxf(0.0f,x-_modelParams::K);
    }

    float payoffFine() {
        return exp(-_modelParams::r * _modelParams::T) * fmax(0.0, logspot_xf - _modelParams::K);
    }

    float payoffCoarse() {
        return exp(-_modelParams::r * _modelParams::T) * fmax(0.0, logspot_xc - _modelParams::K);
    }
};

#endif //CPP_MLMC_GENERATED_H
