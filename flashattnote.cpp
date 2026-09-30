#include <cuda_runtime.h>
__global__ void flashAttn(Q, K, V, O, Nquery, ndim)
{
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    int nL - blockDim.x;
    if(x < nL && y < ndim)
    {
        sram[0][threadIdx.y][threadIdx.x] = Q[x][y]
        sram[1][][]...= K[x][y]
        sram[2][][]...= V[x][y]
        sram[3][][] for O[x][y]
    }
    for(int i = 0; i < (int)Nquery/nL; i++)
    {
        doing MatrixMultiplication;
        sram[3][][] = sram[3][][] * diag(exp) + softmax(sram[0]*sram[1]) * sram[2];
        sync();
        if(x < nL && y < ndim)
        {
            reload K[i*nL:(i+1)*nL], V[i*nL, (i+1)*nL]
            sram[1][y][x] = K[x][y]
            sram[2][y][x] = V[x][y]
        }
        sync();
    }
    if(x < nL && y < ndim)
    {
        O[x][y] - sram[3][y][x]
    }
}

int main()
{
    const QueryNum = 900, ndim = 256;
    nL = (int)SRAMSize / (ndim * 4);
    gridsize = QueryNum / nL;
    dim3 blocksize(nL, ndim); 
    flashAttn <<<gridsize, blocksize>>> flashattn(QueryNum, ndim);
}
