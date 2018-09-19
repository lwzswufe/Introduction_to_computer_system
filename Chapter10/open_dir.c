#include <stdio.h>
#include <dirent.h>                 // DIR
#include <errno.h>                  // errno

int main()
{   
    char *dir_name = "D:\\";
    DIR *dir_p;
    struct dirent *dep;

    dir_p = opendir(dir_name);      // 目录流
    errno = 0;
    dep = readdir(dir_p);           // 查找结束和查找错误均返回 NULL
    while (dep != NULL)
    {
        printf("Found file:%s\n", dep->d_name);
        dep = readdir(dir_p);
    }
    if (errno != 0)                 // 查找错误的情况 errno 会变化
        printf("Found file error:%d\n", errno);
    closedir(dir_p);
}