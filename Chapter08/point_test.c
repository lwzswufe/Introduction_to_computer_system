#include <stdio.h>


void init(int a_ptr[], int size)
{   
    for(int i=0; i<size; i++)
    {
        a_ptr[i] = i;
    }
}


int main()
{
    int size = 10;
    int a_ptr[size];
    printf("arr is not init:\n");
    for(int i=0; i<size; i++)
    {
        printf("%8d, ", a_ptr[i]);
    } 
    printf("\ninit arr:\n");
    init(a_ptr, size);
    for(int i=0; i<size; i++)
    {
        printf("%8d, ", a_ptr[i]);
    } 
}