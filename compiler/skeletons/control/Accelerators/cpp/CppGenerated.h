#pragma once

#include <stdlib.h>
#include <random>
#include <algorithm>
#include <cmath>
#include "../../Utils.h"

using namespace std;

class CppGenerated {
private:
    static constexpr int Simulations = 1024;
    static constexpr int Steps = 1024;
    static constexpr float vol = 0.2;
    static constexpr float drift = -0.1;
    static constexpr float dt = 0.2;
    static constexpr float OUTPUT_INITIAL = 100.0;

public:
    static inline void generateInput(vector<float> &r) {
      auto array_size = Simulations * Steps;

      std::random_device rd;
      std::mt19937 gen(rd());
      std::normal_distribution<> rGen(0, 1);

      for (int i = 0; i < array_size; ++i) {
        r.push_back(rGen(gen)); //todo check conversion
      }
    }

    static inline void runOnce(int currentHeight, vector<float> const &r, vector<vector<float>> &paths) {
      float logspot = 100.0;

      paths.push_back({ OUTPUT_INITIAL });

      for (int i = 0; i < Steps; i++) {
        const int id = currentHeight * Steps + i;

        float func0 = sqrt(dt);

        float logspotTemp = logspot + drift + vol * func0 * r[id];

        logspot = logspotTemp;

        paths[currentHeight].push_back(logspot);
      }
    }

    static void run(vector<float> const &r, vector<vector<float>> &paths) {
      for (int i = 0; i < Simulations; i++) {
        runOnce(i, r, paths);
      }
    }
};

#define CPP_STATE vector<float> r;
#define CPP_SETUP CppGenerated::generateInput(r);
#define CPP_RUN CppGenerated::run(r, paths);
