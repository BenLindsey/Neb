__constant int Simulations = 65536;
__constant int Steps = 1024;
__constant float vol = 0.2;
__constant float drift = -0.1;
__constant float dt = 0.2;

__kernel void Add(__global float* r, __global float* output) {
  const int currentHeight = get_global_id(1);
  const int width = get_global_size(1);

  float logspot = 100.0;

  for(int i = 0; i < Steps; i++) {
    const int id = currentHeight * Steps + i;

    float func0 = sqrt(dt);
    
    float logspotTemp = logspot + drift + vol * func0 * r[id];

    logspot = logspotTemp;

    output[id] = logspot;
  }
}
