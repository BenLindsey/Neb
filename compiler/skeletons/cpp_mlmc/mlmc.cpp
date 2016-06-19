#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mlmc.h"
#include "regression.h"

float mlmc(int Lmin, int Lmax, int N0, float eps,
           void (*mlmc_l)(int, int, double *),
           float alpha_0,float beta_0,float gamma, int *Nl) {

  double sums[6], suml[3][21];
  float  ml[21], Vl[21], Cl[21], x[21], y[21], alpha, beta, sum, theta;
  int    dNl[21], L, converged;

  //
  // check input parameters
  //

  if (Lmin<2) {
    fprintf(stderr,"error: needs Lmin >= 2 \n");
    exit(1);
  }
  if (Lmax<Lmin) {
    fprintf(stderr,"error: needs Lmax >= Lmin \n");
    exit(1);
  }

  if (N0<=0 || eps<=0.0f || gamma <= 0.0f) {
    fprintf(stderr,"error: needs N>0, eps>0, gamma>0 \n");
    exit(1);
  }

  //
  // initialisation
  //

  alpha = fmax(0.0f,alpha_0);
  beta  = fmax(0.0f,beta_0);
  theta = 0.25f;             // MSE split between bias^2 and variance

  L = Lmin;
  converged = 0;

  for(int l=0; l<=Lmax; l++) {
    Nl[l] = 0;
    Cl[l] = powf(2.0f,(float)l*gamma);

    for(int n=0; n<3; n++) {
      suml[n][l] = 0.0;
    }
  }

  for(int l=0; l<=Lmin; l++) {
    dNl[l] = N0;
  }

  while (!converged) {

    //
    // update sample sums
    //

    for (int l=0; l<=L; l++) {
      if (dNl[l]>0) {
        mlmc_l(l,dNl[l],sums);
        suml[0][l] += (float) dNl[l];
        suml[1][l] += sums[0];
        suml[2][l] += sums[1];
      }
    }

    //
    // compute absolute average and variance,
    // correct for possible under-sampling,
    // and set optimal number of new samples
    //

    sum = 0.0f;

    for (int l=0; l<=L; l++) {
      ml[l] = fabs(suml[1][l]/suml[0][l]);
      Vl[l] = fmaxf(suml[2][l]/suml[0][l] - ml[l]*ml[l], 0.0f);
      if (l>1) {
        ml[l] = fmaxf(ml[l],  0.5f*ml[l-1]/powf(2.0f,alpha));
        Vl[l] = fmaxf(Vl[l],  0.5f*Vl[l-1]/powf(2.0f,beta));
      }

      sum += sqrtf(Vl[l]*Cl[l]);
    }

    for (int l=0; l<=L; l++) {
      dNl[l] = ceilf( fmaxf( 0.0f, 
                       sqrtf(Vl[l]/Cl[l])*sum/((1.0f-theta)*eps*eps)
                     - suml[0][l] ) );
    }

    //
    // use linear regression to estimate alpha, beta if not given
    //

    if (alpha_0 <= 0.0f) {
      printf("dead code?\n");
      for (int l=1; l<=L; l++) {
        x[l-1] = l;
        y[l-1] = - log2f(ml[l]);
      }
      regression(L,x,y,alpha,sum);
    }

    if (beta_0 <= 0.0f) {
      printf("beta\n");
      for (int l=1; l<=L; l++) {
        x[l-1] = l;
        y[l-1] = - log2f(Vl[l]);
      }
      regression(L,x,y,beta,sum);
    }

    //
    // if (almost) converged, estimate remaining error and decide 
    // whether a new level is required
    //

    sum = 0.0;
      for (int l=0; l<=L; l++)
        sum += fmaxf(0.0f, (float)dNl[l]-0.01f*suml[0][l]);

    if (sum==0) {
      converged = 1;
      float rem = ml[L] / (powf(2.0f,gamma)-1.0f);

      if (rem > sqrtf(theta)*eps) {
        if (L==Lmax)
          printf("*** failed to achieve weak convergence *** \n");
        else {
          converged = 0;
          L++;

          sum = 0.0f;
          for (int l=0; l<=L; l++) sum += sqrtf(Vl[l]*Cl[l]);
          for (int l=0; l<=L; l++)
            dNl[l] = ceilf( fmaxf( 0.0f, 
                            sqrtf(Vl[l]/Cl[l])*sum/((1.0f-theta)*eps*eps)
                          - suml[0][l] ) );
        }
      }
    }
  }

  //
  // finally, evaluate multilevel estimator
  //

  float P = 0.0f;
  for (int l=0; l<=L; l++) {
    P    += suml[1][l]/suml[0][l];
    Nl[l] = suml[0][l];
  }

  return P;
}