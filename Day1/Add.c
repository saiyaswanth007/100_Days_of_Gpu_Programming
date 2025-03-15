#include <stdio.h>
#include <cuda_runtime.h>
__global__ void add(int n,float* a, float* b , float* c){
    int i = blockIdx.x*blockDim.x + threadIdx.x;
    if(i<n){
    c[i] = a[i] + b[i];
    }
}
int main(){
    int n = 5;
    float a[5] = {3,5,6,2,7};
    float b[5] = {5,8,8,36,6};
    float c[5];
    float* d_a;
    float* d_b;
    float* d_c;
    //allocate memory on GPU
    cudaMalloc((void**)&d_a, n * sizeof(float));
    cudaMalloc((void**)&d_b, n * sizeof(float));
    cudaMalloc((void**)&d_c, n * sizeof(float));
    //copy the data fron host(Cpu) to device(Gpu)
    cudaMemcpy(d_a,a,n*sizeof(float),cudaMemcpyHostToDevice);
    cudaMemcpy(d_b,b,n*sizeof(float),cudaMemcpyHostToDevice);
    //Launch the kernal of 1 block of 5 threads
    add<<<1,5>>>(n,d_a,d_b,d_c);
    //copy the data from gpu(device) to gpu(host)
    cudaMemcpy(c,d_c,n*sizeof(float),cudaMemcpyDeviceToHost);
    for(int i = 0; i<n; i++){
        printf("%.2f ",c[i]);
    }
    printf("\n");
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

}