#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
    int i = 0;
    printf("Command line arguments:\n");
    for(i=0; argv[i] != NULL; i++)
        printf("argv_%d: %s\n", i, argv[i]);
    printf("environment variables:\n");
    for(i=0; envp[i] != NULL; i++)
        printf("envp_%d: %s\n", i, envp[i]);

}