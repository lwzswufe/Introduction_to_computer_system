#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void minmax_1(int arr_a[], int arr_b[], int N)
{   
    int temp;
    for(int i = 0; i < N; i++)
    {
        if (arr_a[i] >= arr_b[i])
        {
            temp = arr_a[i];
            arr_a[i] = arr_b[i];
            arr_b[i] = temp;
        }
    }
}


void minmax_2(int arr_a[], int arr_b[], int N)
{   
    int min_ab, max_ab;
    for(int i = 0; i < N; i++)
    {
        min_ab = arr_a[i] <  arr_b[i] ? arr_a[i] : arr_b[i];
        max_ab = arr_a[i] >= arr_b[i] ? arr_b[i] : arr_a[i];
        arr_a[i] = min_ab;
        arr_b[i] = max_ab;
    }
}


void timer(void(*func)(int[], int[], int), int arr_a[], int arr_b[], int N)
{   
    clock_t t_start, t_end;                     // clock类
    double use_time;                            // 耗时 毫秒
    t_start = clock();                          // 起始时间
    for (int i = 0; i < 200; i++)
        func(arr_a, arr_b+i, N);
    t_end = clock();                            // 结束时间
    use_time = (double)(t_end - t_start);       // 使用时间
    printf("time: %.0f ms\n", use_time) ;
}

int main()
{
    int N = 100000;
    int arr_a[N], arr_b[N];

    srand(145);
    for(int i = 0; i < N;  i++)
    {
        arr_a[i] = rand();
        arr_b[i] = rand();
        // printf("a: %d b: %d\n", arr_a[i], arr_b[i]) ;
    }
    timer(minmax_1, arr_a, arr_b, N-200);
    timer(minmax_2, arr_a, arr_b, N-200);
}