#include <stdio.h>
#include <time.h>
// 计算器除法
int divide_1000_1(int a)
{
    return a / 1000;
}

int divide_1000_2(int a)
{   // 1024/1000 约= 1 + 1/32 - 1/128 = 1.02343
    return (a >> 10) + (a >> 15) - (a >> 17);
}

int divide_1000_3(int a) // 魔数除法 效率提升6%
{   // x/1000 = x/256 * 256/1000 = 16777 / 65535 = 4189 / FFFF    
    // 40 = 32 + 8  8 = log(32)
    return  ((__int64)a * 0x41894189) >> 40;
}

void timer(int(*func)(int), int loop_ed)
{   
    clock_t t_start, t_end;                     // clock类
    double use_time;                            // 耗时 毫秒
    t_start = clock();                          // 起始时间
    for (int i = 0; i < loop_ed; i++)
        func(i);
    t_end = clock();                            // 结束时间
    use_time = (double)(t_end - t_start);       // 使用时间
    printf("time: %f ms\n", use_time) ;
}

void test(int(*func)(int), int x)
{
    printf("%d / 1000 = %d\n", x, func(x));
}

int main()
{   
    int loop_ed = 100 * 1000 * 1000;
    test(&divide_1000_1, 3977400);
    test(&divide_1000_2, 3977400);
    test(&divide_1000_3, 3977400);
    timer(&divide_1000_1, loop_ed);
    timer(&divide_1000_2, loop_ed);
    timer(&divide_1000_3, loop_ed);
    return 0;
}