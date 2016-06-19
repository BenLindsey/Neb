__constant int Simulations = 3;
__constant int Steps = 1000;
__constant float a = 0.02;
__constant float b = 0.2;
__constant float c = -65.0;
__constant float d = 8.0;
__constant float I = 20.0;

__kernel void Add(__global float* r, __global float* output) {
  const int currentHeight = get_global_id(1);
  const int width = get_global_size(1);

  float v = -50.0;
  float u = 10.0;

  for(int i = 0; i < Steps; i++) {
    const int id = currentHeight * Steps + i;

    float vTemp = v >= 30 ? c : v + r[id] * (0.04 * v * v + 5 * v + 140 - u + I);
    float uTemp = v >= 30 ? u + d : u + r[id] * (a * (b * v - u));

    v = vTemp;
    u = uTemp;

    output[id] = v;
  }
}
