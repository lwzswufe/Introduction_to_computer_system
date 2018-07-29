#include <stdio.h>

int main()
{
    short usi = 32768;          // short 的表示范围为 -32768 - 32767
    int i = usi;                // 位拓展  正数高位填充0 负数高位填充f
    int x = 65535, y;
    y = x * x;                  // x*x 越界
    printf("usi %4X\n",  usi);
    printf("i   %X\n",  i);
    printf("x   %8d  %8X\n",  x, x);
    printf("y   %8d  %X\n",  y, y);

    return 0;
}