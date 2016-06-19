#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <random>
#include <algorithm>
#include <cmath>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

using namespace std;

inline void generateInput(uint array_size, float* r) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> rGen(0, 1);

	for (int i = 0; i < array_size; ++i) {
		r[i] = rGen(gen);
	}
}

void estimateLevel(int l, int N, double* sums)
{
        for (int i = 0; i < 6; i++) sums[i] = 0;

        printf("Estimating level %d with %d samples\n", l, N);
  
        int originalN = N;
        int offsetFrom16 = N % 16;
     
        if(offsetFrom16 > 0) {	
                int smoothN = N + (16 - offsetFrom16);
                printf("Smoothing %d to %d\n", N, smoothN);
                N = smoothN;
        }     

      	uint nf = 1 << l;
        uint nc = (l == 0) ? 1 : nf / 2; //todo check for l0

	float *r1 = (float*) malloc(sizeof(float) * N * nc);
        float *r2 = (float*) malloc(sizeof(float) * N * nc);

	float *diff = (float*) malloc(sizeof(float) * N);
	float *fine = (float*) malloc(sizeof(float) * N);

        printf("Generating input.\n");
	generateInput(N * nc, r1);
        generateInput(N * nc, r2);
        printf("Input generated\n");
      
        printf("Running on DFE.\n");
	NebMLMCStream(N, l, nc, r1, r2, diff, fine);

	for(int i = 0; i < originalN; ++i) {
		sums[0] += diff[i];
        	sums[1] += diff[i] * diff[i];
        	sums[2] += diff[i] * diff[i] * diff[i];
        	sums[3] += diff[i] * diff[i] * diff[i] * diff[i];
        	sums[4] += fine[i];
        	sums[5] += fine[i] * fine[i];
        }

        for(int i = 0; i < 6; i++) {
        	printf("sums[%d] = %f\n", i, sums[i]);
        }
 
        printf("Avg value: %f\n", sums[4] / (double)originalN);

	printf("Done.\n");
}
