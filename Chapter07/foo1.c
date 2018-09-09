#include <stdio.h>
#include "foo2.c"

int x = 15213;

int main()
{
    f();
    printf("global variable x will changed by f()\n");
    printf("x = %d\n", x);
    return 0;
}