#include <stdio.h>
#include <stdarg.h>                 /* va_list, va_start, va_arg, va_end */

int add(int num, ...)
{
    int sum = 0, x;
    va_list arg_ptr;                //初始化指向可变参数列表的指针
    va_start(arg_ptr, num);         //将第一个可变参数的地址赋给arg_ptr，即arg_ptr指向可变参数列表的开始
    printf("sum of (");
    for(int i=0; i<num; i++)
    {
        x = va_arg(arg_ptr, int);   // 取出arg_ptr里面的值，即第i个可变参数 类型 int
        sum += x;
        printf("%d, ", x);
    }
    printf(") is: %d\n", sum);
    va_end(arg_ptr);                // End using variable argument list
    return sum;
}


int main(int argc, char* argv[], char* envp[])
{
    int sum = 0;
    sum = add(5, 1, 2, 3, 4, 5);
    sum = add(4, 2, 3, 4, 5);
    return 0;
}