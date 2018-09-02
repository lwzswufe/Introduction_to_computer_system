#include <stdio.h>
#include <time.h>

/*
通过展开循环 和 使用中间变量 来提高运算速度
*/
void loop_1(int N, int arr[])
{
    long sum;
    for(int i=0; i< N; i++)
    {
        sum = sum + arr[i];
    }
}


void loop_2(int N, int arr[])
{
    long sum;
    for(int i=0; i< N; i+=2)
    {
        sum = sum + arr[i];
        sum = sum + arr[i + 1];
    }
}


void loop_4(int N, int arr[])
{
    long sum;
    long temp;
    for(int i=0; i< N; i+=4)
    {
        sum += arr[i];
        sum += arr[i + 1];
        sum += arr[i + 2];
        sum += arr[i + 3];
    }
}


void loop_4_(int N, int arr[])
{
    long sum;
    long temp_1, temp_2;
    for(int i=0; i< N; i+=4)
    {
        temp_1 = arr[i] + arr[i + 1];
        sum += temp_1;
        temp_2 = arr[i + 2] + arr[i + 3];
        sum += temp_2;
    }
}

void loop_8(int N, int arr[])
{
    long sum;
    long temp_1, temp_2, temp_3, temp_4;
    for(int i=0; i< N; i+=8)
    {
        temp_1 = arr[i] + arr[i + 1];
        sum += temp_1;
        temp_2 = arr[i + 2] + arr[i + 3];
        sum += temp_2;
        temp_3 = arr[i + 4] + arr[i + 5];
        sum += temp_3;
        temp_4 = arr[i + 6] + arr[i + 7];
        sum += temp_4;
    }
}

void loop_8_(int N, int arr[])
{
    long sum;
    long temp_1, temp_2, temp_3, temp_4;
    for(int i=0; i< N; i+=8)
    {
        temp_1 = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
        temp_2 = arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7];
        temp_3 = temp_1 + temp_2;
        sum += temp_3;
    }
}

void loop_12(int N, int arr[])
{
    long sum;
    long temp_1, temp_2, temp_3, temp_4, temp_5, temp_6;
    for(int i=0; i< N; i+=12)
    {
        temp_1 = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
        temp_2 = arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7];
        temp_3 = arr[i + 8] + arr[i + 9] + arr[i + 10] + arr[i + 11];
        temp_4 = temp_1 + temp_2;
        temp_5 = temp_3 + temp_4;
        sum += temp_5;
    }
}

void loop_16(int N, int arr[])
{
    long sum;
    long temp_1, temp_2, temp_3, temp_4, temp_5, temp_6, temp_7;
    for(int i=0; i< N; i+=16)
    {
        temp_1 = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
        temp_2 = arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7];
        temp_3 = arr[i + 8] + arr[i + 9] + arr[i + 10] + arr[i + 11];
        temp_3 = arr[i + 12] + arr[i + 13] + arr[i + 14] + arr[i + 15];
        temp_5 = temp_1 + temp_2;
        temp_6 = temp_3 + temp_4;
        temp_7 = temp_5 + temp_6;
        sum += temp_7;
    }
}
                                                // 参数 函数指针 void(*func)(int, int[])  
                                                // 返回类型void 函数别名func 参数类型(int, int[])
void timer(void(*func)(int, int[]), int N, int arr[])
{   
    clock_t t_start, t_end;                     // clock类
    double use_time;                            // 耗时 毫秒
    t_start = clock();                          // 起始时间
    for (int i = 0; i < 200; i++)
        func(N, arr);
    t_end = clock();                            // 结束时间
    use_time = (double)(t_end - t_start);       // 使用时间
    printf("time: %f ms\n", use_time) ;
}

int main()
{
    int N = 500000;
    int arr[N];

    for(int i = 0; i < N;  i++)
    {
        arr[i] = 7;
    }
    void (*f_1)(int, int[]) = &loop_1;          // 函数指针类returntype (*funname)(argtype1, argtype2...)          
    void (*f_2)(int, int[]) = &loop_2;
    void (*f_3)(int, int[]) = &loop_4;
    void (*f_4)(int, int[]) = &loop_4_;
    timer(f_1, N, arr);
    timer(f_2, N, arr);
    timer(f_3, N, arr);
    timer(loop_4_, N, arr);
    timer(loop_8, N, arr);                      // 直接传函数 隐含转换为函数指针
    timer(loop_8_, N, arr);
    timer(loop_12, N, arr);
    timer(loop_16, N, arr);
}