#include <stdio.h>
#include "foo2.c"

int x;

int main()
{   
    x = 15213;
    f();
    printf("global variable x will changed by f()\n");
    printf("x = %d\n", x);
    return 0;
}