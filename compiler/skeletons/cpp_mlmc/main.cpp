#include <sys/types.h>
#include <stdlib.h>
#include "regression.h"
#include "levelEstimator.h"
#include "mlmc.h"
#include "generated.h"

int main(int argc, char **argv)
{
    greeks greeks = mlmc_regress_greeks(estimateLevel, _regression::M, _regression::N, _regression::L);
    printf("alpha: %f\n", greeks.alpha);
    printf("beta: %f\n", greeks.beta);
    printf("gamma: %f\n", greeks.gamma);

    int *Nl = (int *)malloc((_multilevel::Lmax+1)*sizeof(int));

    float P = mlmc(_multilevel::Lmin, _multilevel::Lmax, _multilevel::N0, _modelParams::EPS,
                   estimateLevel, greeks.alpha, greeks.beta, greeks.gamma, Nl);

    printf("P: %f", P);
}