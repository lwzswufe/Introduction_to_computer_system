#include <stdio.h>
#include <stdlib.h>                 // define
#include <sys/types.h>              // difine pid_t
#include <sys/wait.h>               // difine WIFEXITED
#include <unistd.h>

#define N 3

int main()
{
    int status, i, count;
    pid_t pid[N], retpid;

    count = 0;
    for(i = 0; i < N; i++)
    {
        if((pid[i] = fork()) == 0)  // children
        {   
            printf("child get pid:%d  i:%d\n", pid[i], i);
            exit(100 + i);          // child exit
        }
        else                        // parent
        {   
            count++;
            printf("parent get pid: %d  i:%d\n", pid[i], i);
        }
    }
    printf("count:%d\n", count);
    i = 0;                          
                                    // waitpid  会在status里放上关于导致返回的状态信息
                                    // waitpid  parent阻塞block等待子线程退出exit
    while ((retpid = waitpid(pid[i++], &status, 0)) >0)
    {
        if (WIFEXITED(status))      // child end success
            printf("child %d terminated with exit status=%d\n"
                   , retpid, WIFEXITED(status));
        else                        // child end 
            printf("child %d terminated abnormally\n"
                   , retpid);
    }

    //if (errno != ECHILD)
    //    unix_error("waitpid error");
    printf("end");
    exit(0);
}