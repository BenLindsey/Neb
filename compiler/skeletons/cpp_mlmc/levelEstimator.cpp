#include <stdio.h>
#include "levelEstimator.h"
#include "generated.h"

void estimateLevel(int l, int N, double *sums) {
    int nf = 1<<l;
    int nc = nf/2;

    state state(nf, nc);

    for (int k=0; k<6; k++) sums[k] = 0.0;

    printf("Level %d running with %d samples and %d steps!\n", l, N, nc);
    for (int np = 0; np<N; np++) {
        state.nextSample();

        if (l==0) {
            state.baseUpdate();
        } else {
            for (int n=0; n<nc; n++) {
                state.levelUpdate();
            }
        }

        float PayoffFine   = state.payoffFine();
        float PayoffCoarse = state.payoffCoarse();

        float PayoffDiff  = (l==0) ? PayoffFine : PayoffFine-PayoffCoarse;

        sums[0] += PayoffDiff;
        sums[1] += PayoffDiff*PayoffDiff;
        sums[2] += PayoffDiff*PayoffDiff*PayoffDiff;
        sums[3] += PayoffDiff*PayoffDiff*PayoffDiff*PayoffDiff;
        sums[4] += PayoffFine;
        sums[5] += PayoffFine*PayoffFine;
    }
}
