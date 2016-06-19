__constant float K   = 100.0f;  // Strike price
__constant float X0  = 100.0f;  // Initial price
__constant float T   = 1.0f;    // Expiry in years
__constant float r   = 0.05f;   // risk free interest
__constant float sig = 0.3f;    // the standard deviation of the stock's returns

float stateUpdate(float previous, float h, float dW) {
    return previous + r*previous*h + sig*previous*dW
          + 0.5f*sig*sig*previous*(dW*dW-h);
}

float payoff(float x) {
    return exp(-r*T) * max(0.0f,x-K);
}

__kernel void Add(__global float* r1, __global float* r2, __global float* diff, __global float* fine, __global int* lp) {
  const int currentHeight = get_global_id(1);
  const int width = get_global_size(1);

  int l = lp[0];

  int nf = 1<<l;
  int nc = nf/2;


  float hf = T / ((float) nf);
  float hc = T / ((float) nc);

  float dWf[2];

  float Xf = X0;      
  float Xc = Xf;

  if (l==0) {
    dWf[0] = sqrt(hf) * r1[currentHeight];
    Xf = stateUpdate(Xf, hf, dWf[0]); 
  } else {
    for (int n=0; n<nc; n++) {      
      int id = currentHeight * nc + n;
      dWf[0] = sqrt(hf)*r1[id];
      dWf[1] = sqrt(hf)*r2[id];

      for (int m=0; m<2; m++) {
        Xf = stateUpdate(Xf, hf, dWf[m]);
      }

      float dWc = dWf[0] + dWf[1];

      Xc = stateUpdate(Xc, hc, dWc);
    }
  }

  float PayoffFine   = payoff(Xf);
  float PayoffCoarse = payoff(Xc);

  float PayoffDiff  = (l==0) ? PayoffFine : PayoffFine-PayoffCoarse; 

  diff[currentHeight] = PayoffDiff;
  fine[currentHeight] = PayoffFine;
}

