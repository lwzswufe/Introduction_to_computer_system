#include <stdio.h>
#include <stdlib.h>                             // malloc


void print_arr(short *p, short size)
{   // 打印数组
    for (short i=0; i<size; i++)
    {
        printf("%5d, ", *p);
        p++;
    }
    printf("\n");
}

void init_arr(short *p, short size)
{   // 初始化
    for (short i=0; i<size; i++)
    {
        *p = i;
        p++;
    }
}

void sub_fun(short * sp, short size)
{
    short *p;
    p = (short *)calloc(size, sizeof(short));
    init_arr(p, size);
    sp = p;
}

short* get_arr(int N)                           // 显式分配内存创建数组 并返回指针
{
    short *p;
    p = (short *)calloc(N, sizeof(short));
    init_arr(p, N);
    return p;
}

int main()
{   
    short *p, *pp, *p0, *sp, n = 7;
    p = (short *)malloc(n * sizeof(short));     // 显式分配内存给 p
    p0 = (short *)calloc(n, sizeof(short));      // 显示分配内存 初始化为0
    print_arr(p0, n);  
    print_arr(p, n);                            // p未初始化 值为随机值
    init_arr(p, n);                             // 初始化p
    print_arr(p, n);                            
    n += 2;     
    p = realloc(p, n * sizeof(short));          // 改变一个已分配的块的大小
    print_arr(p, n);                            // 
    pp = p;                                     // 将P的地址赋值给 pp
    print_arr(pp, n);
    free(p);                                    // 释放p指向的内存
    free(p0);
    print_arr(pp, n);                           // pp指向的地址变为内存里不可预测的值
    print_arr(sp, n);
    sub_fun(sp, n);
    print_arr(sp, n);

    short *p_new;                               // 使用函数创建数组
    p_new = get_arr(5);
    print_arr(p_new, 5);
    free(p_new);
}