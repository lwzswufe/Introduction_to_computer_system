#include <stdio.h>

template <typename T>
int print(T x)
{
    printf("%8d\t%8X\n",  x, x);
}

template <>     //特例化版本
int print(float x)
{
    printf("%8f\t%8p\n",  x, x);
}

template <>     //特例化版本
int print(double x)
{
    printf("%8f\t%16p\n",  x, x);
}

int main()
{   
    unsigned ui = -32768;  
    short si = -32768;                      
    int i = 65535;
    char c = '@';
    float f = 1.1;
    double d =10.5;
    print(ui);
    print(si);
    print(i);
    print(c);
    print(f);
    print(d);
    return 0;
}