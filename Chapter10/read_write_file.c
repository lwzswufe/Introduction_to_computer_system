#include <stdio.h>
#include <sys/stat.h>           // stat
#include <unistd.h>             // ssize_t read write
#include <fcntl.h>              // O_WRONLY
#include <time.h>

/*
读函数read 
ssize_t read(int fd,void *buf,size_t nbyte) 
read函数是负责从fd中读取内容.成功时,read返回实际所读的字节数,如果返回的值是0,表示已经读到文件的结束了.
小于0表示出现了错误.如果错误为EINTR说明读是由中断引起的, 如果是ECONNREST表示网络连接出了问题

写函数write 
ssize_t write(int fd,const void *buf,size_t nbytes) 
write函数将buf中的nbytes字节内容写入文件描述符fd.成功时返回写的字节数.失败时返回-1. 并设置errno变量. 在网络程序中,当我们向套接字文件描述符写时有俩种可能.  
1)write的返回值大于0,表示写了部分或者是全部的数据.  
2)返回的值小于0,此时出现了错误.我们要根据错误类型来处理.  如果错误为EINTR表示在写的时候出现了中断错误.  
如果为EPIPE表示网络连接出现了问题(对方已经关闭了连接).

time_t就是long，函数返回从1970年1月1日（MFC是1899年12月31日）0时0分0秒，到现在的的秒数
*/
void timenum2str(char* timestr, time_t t)
{                                       // 时间(long)转字符串
    struct tm *p;
    p = gmtime(&t);
    sprintf(timestr, "%02d:%02d:%02d", p->tm_hour, p->tm_min, p->tm_sec);
}


int main()
{
    ssize_t fd_r, fd_w;
    size_t char_n = 16;
    char * filename = "a.txt", * context="test context\n", blank[char_n], timestr[8];
    struct stat file_stat;
    

    fd_w = open(filename, O_WRONLY|O_TRUNC, 0);
    write(fd_w, context, char_n);       // 若 char_n 大于context 多出部分会写null
    close(fd_w);

    fd_r = open(filename, O_RDONLY, 0);
    read(fd_r, blank, char_n);
    printf("we read: %s", blank);
    close(fd_r);

    stat(filename, &file_stat);
    printf("filesize: %dB\n", file_stat.st_size);
    printf("file last access: %d\n", file_stat.st_atime);
    time_t t = file_stat.st_mtime;
    timenum2str(timestr, t);
    printf("file last access: %s\n", timestr);
}

