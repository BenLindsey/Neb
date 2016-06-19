#include <stdlib.h>
#include <math.h>

#include "regression.h"

greeks mlmc_regress_greeks(void (*mlmc_l)(int, int, double *), int M,int N,int L) {

  double sums[6];
  float *del1 = (float *)malloc((L+1)*sizeof(float));
  float *var1 = (float *)malloc((L+1)*sizeof(float));

  for (int l=0; l<=L; l++) {
    mlmc_l(l,N,sums);

    for (int m=0; m<6; m++) sums[m] = sums[m]/N;

    del1[l] = sums[0];
    var1[l] = fmax(sums[1]-sums[0]*sums[0], 1e-10);
  }

  //
  // use linear regression to estimate alpha, beta
  //

  greeks result;
  float foo;
  float *x = (float *)malloc(L*sizeof(float));
  float *y = (float *)malloc(L*sizeof(float));

  for (int l=1; l<=L; l++) {
    x[l-1] = l;
    y[l-1] = - log2f(fabsf(del1[l]));
  } 
  regression(L,x,y,result.alpha,foo);

  for (int l=1; l<=L; l++) {
    x[l-1] = l;
    y[l-1] = - log2f(var1[l]);
  } 
  regression(L,x,y,result.beta,foo);

  result.gamma = log2f((float) M);

  return result;
}

void regression(int N, float *x, float *y, float &a, float &b) {

    float sum0=0.0f, sum1=0.0f, sum2=0.0f, sumy0=0.0f, sumy1=0.0f;

    for (int i=1; i<N; i++) {
        sum0  += 1.0f;
        sum1  += x[i];
        sum2  += x[i]*x[i];

        sumy0 += y[i];
        sumy1 += y[i]*x[i];
    }

    a = (sum0*sumy1 - sum1*sumy0) / (sum0*sum2 - sum1*sum1);
    b = (sum2*sumy0 - sum1*sumy1) / (sum0*sum2 - sum1*sum1);
}

