#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

/*
struct  hostent
{
  char    *h_name;                  official name of host 
  char    **h_aliases;              alias list 
  int     h_addrtype;               host address type 
  int     h_length;                 length of address 
  char    **h_addr_list;            list of addresses from name server 
  #define h_addr  h_addr_list[0]    address, for backward compatiblity 
};
void bcopy(char *s1, char *s2, int length)
*/

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int buffer_size = 256;
    char buffer[buffer_size];
    if (argc < 3)                               // default args
    {   
       // fprintf(stderr,"usage %s hostname port\n", argv[0]);
       // exit(0);
       portno = 8888;
       server = gethostbyname("127.0.0.1");
    }
    else
    {
        portno = atoi(argv[2]);
        server = gethostbyname(argv[1]);
    }
    printf("wait for connect....\r\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);       // 获取文件描述符
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));  //0初始化
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    printf("wait for connect....\r\n");
    printf("server address:%s:%d \r\n", server->h_name, ntohs(serv_addr.sin_port));

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        sleep(100);                                 // wait for connect

    printf("connect successful\n");
    sprintf(buffer, "Hello I'm Server");
    n = write(sockfd, buffer, strlen(buffer));      // send data
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer, buffer_size);
    n = read(sockfd, buffer, buffer_size);          // recv data
    if (n < 0) 
         error("ERROR reading from socket");
    printf("recv: %s\n",buffer);
    close(sockfd);
    return 0;
}