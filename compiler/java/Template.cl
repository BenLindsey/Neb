__constant int Simulations = 65536;
__constant int Steps = 1024;
__constant float kappa[4] = {0.2, 0.3, 0.6, 0.7};
__constant float theta[4] = {-0.2, 0.8, 0.0, -0.3};
__constant float epsilon[4] = {0.1, 0.5, 0.3, 0.2};
__constant float dt[4] = {0.1, 0.9, 0.3, 0.4};
__constant float minVar = 0.0;

__kernel void Add(__global float* r, __global float* r2, __global float* output) {
  const int currentHeight = get_global_id(1);
  const int width = get_global_size(1);

  float logspot = 100.0;
  float variance = 5.0;

  for(int i = 0; i < Steps; i++) {
    const int id = currentHeight * Steps + i;

    float logspotTemp = logspot + 0.5 * dt[i % 3] * variance + sqrt(max(variance, minVar)) * sqrt(dt[i % 3]) * r[id];
    float varianceTemp = variance + 0.5 * kappa[i % 3] * (theta[i % 3] - max(variance, minVar)) + epsilon[i % 3] * sqrt(max(variance, minVar)) * sqrt(dt[i % 3]) * r2[id];

    logspot = logspotTemp;
    variance = varianceTemp;

    output[id] = logspot;
  }
}
