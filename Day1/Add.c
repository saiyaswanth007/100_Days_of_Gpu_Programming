#include <stdio.h>
#include <cudaruntime.h>
<__global__ void add(int n,float* a, float* b , float* c){
    i = blockIdx.x*blockDim.x + threadIdx.x
    if(i<n){
    c[i] = a[i] + b[i];
    }
}
int main(){
    float a[5] = [3,5,6,2,7];
    float b[5] = [5,8,8,36,6];
    float c[5];
    float* d_a,float* d_b,float*d_c;
    d_a = cudaMalloc((void**)&d_a sizeof(n*sizeof(float)));
    d_b = cudaMalloc((void**)&d_b sizeof(n*sizeof(float)));
    d_c = cudaMalloc((void**)&d_c sizeof(n*sizeof(float)));
    //copy the data fron host(Cpu) to device(Gpu)
    cudaMemcpy(d_a,a,n*sizeof(float),cudaMemcpyHostToDevice);
    cudaMemcpy(d_b,b,n*sizeof(float),cudaMemcpyHostToDevice);
    //copy the data from gpu(device) to gpu(host)
    cudaMemcpy(c,d_c,n*sizeof(float),n*sizeof(float),cudaMemcpyDeviceToHost);
    for(i = 0;i<n;i++){
        prinf("%f ",&c[i]);
    }
    printf("\n");
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

}