#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void dotprod(double arr_a[], double arr_b[], int N)
{   
    double sum = 0;
    for(int i = 0; i < N; i++)
    {   
        sum += arr_a[i] * arr_b[i];
    }
}


void timer(void(*func)(double[], double[], int), double arr_a[], double arr_b[], int N)
{   
    clock_t t_start, t_end;                     // clock类
    double use_time;                            // 耗时 毫秒
    t_start = clock();                          // 起始时间
    for (int i = 0; i < 10000000; i++)
        func(arr_a, arr_b, N);
    t_end = clock();                            // 结束时间
    use_time = (double)(t_end - t_start);       // 使用时间
    printf("time: %.0f ms\n", use_time) ;
}

int main()
{
    int M = 4, N = M + 2;
    double arr_a[N], arr_b[N];
    double arr_c[M], arr_d[M];

    srand(145);
    for(int i = 0; i < N;  i++)
    {
        arr_a[i] = rand();
        arr_b[i] = rand();
        // printf("a: %d b: %d\n", arr_a[i], arr_b[i]) ;
    }
    for(int i = 0; i < M;  i++)
    {
        arr_c[i] = rand();
        arr_d[i] = rand();
        // printf("a: %d b: %d\n", arr_a[i], arr_b[i]) ;
    }
    timer(dotprod, arr_a, arr_b, M);
    timer(dotprod, arr_c, arr_d, M);
}