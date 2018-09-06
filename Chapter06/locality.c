#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
利用空间局部性 依序 效率提升50%
*/


void sum_row(int row_n, int col_n, int arr[row_n][col_n])
{
    int sum = 0;
    for(int i=0; i<row_n; i++)
    {
        for(int j=0; j<col_n; j++)
            sum += arr[i][j];
    }
}

void sum_col(int row_n, int col_n, int arr[row_n][col_n])
{
    int sum = 0;
    for(int j=0; j<col_n; j++)
    {
        for(int i=0; i<row_n; i++)
            sum += arr[i][j];
    }
}


void timer(void(*func)(int row_n, int col_n, int arr[row_n][col_n]), int row_n, int col_n, int arr[row_n][col_n])
{   
    clock_t t_start, t_end;                     // clock类
    double use_time;                            // 耗时 毫秒
    t_start = clock();                          // 起始时间
    for (int i = 0; i < 200; i++)
        func(row_n, col_n, arr);
    t_end = clock();                            // 结束时间
    use_time = (double)(t_end - t_start);       // 使用时间
    printf("time: %.0f ms\n", use_time) ;
}

int main()
{   
    int row_n = 1024, col_n = 507;
    int arr[row_n][col_n];
    for(int i=0; i<row_n; i++)
    {
        for(int j=0; j<col_n; j++)
            arr[i][j] = 1;
    }
    timer(sum_row, row_n, col_n, arr);
    timer(sum_col, row_n, col_n, arr);
}