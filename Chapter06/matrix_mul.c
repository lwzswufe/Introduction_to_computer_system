#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*
改变程序的循环方式 减少内存未命中次数
*/

double mat_mul_0(int M, int N, int K, double mat_a[M][N], double mat_b[N][K])
{
    double sum = 0;
    for (int i=0; i<M; i++)
    {
        for(int j=0; j<K; j++)                  // mat_a 按行逐次读取数据
        {
            for(int k=0; k<N; k++)              // mat_b 按列逐次读取数据 低效率
                sum += mat_a[i][k] * mat_b[k][j];
        }
    }
    return sum;
}


double mat_mul_1(int M, int N, int K, double mat_a[M][N], double mat_b[N][K])
{
    double r, sum = 0;
    for (int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {   
            r = mat_a[i][j];                    // 缓存r mat_a 和 mat_b 都是按行逐次读取数据
            for(int k=0; k<K; k++)
                sum += r * mat_b[j][k]; 
        }
    }
    return sum;
}

void timer(double(*func)(int M, int N, int K, double mat_a[M][N], double mat_b[N][K]),
                         int M, int N, int K, double mat_a[M][N], double mat_b[N][K])
{   
    clock_t t_start, t_end;                     // clock类
    double use_time, sum;                       // 耗时 毫秒
    t_start = clock();                          // 起始时间
    sum = func(M, N, K, mat_a, mat_b);
    t_end = clock();                            // 结束时间
    use_time = (double)(t_end - t_start);       // 使用时间
    printf("time: %.0f ms and sum:%4f\n", use_time, sum) ;
}


int main()
{
    int M = 256, N = 512, K = 128;
    double mat_a[M][N], mat_b[N][K];

    srand(145);
    double int_max = 2147483647;

    for(int i=0; i<M; i++)                      // 初始化
    {   
        for (int j=0; j<N; j++)
            mat_a[i][j] = rand() * 1.0 / RAND_MAX; 
    }

    for(int i=0; i<N; i++)
    {   
        for (int j=0; j<K; j++)
            mat_b[i][j] = rand() / int_max; 
    }
    
    timer(mat_mul_0, M, N, K, mat_a, mat_b);
    timer(mat_mul_1, M, N, K, mat_a, mat_b);
}