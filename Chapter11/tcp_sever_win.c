#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

//#pragma comment(lib, "ws2_32")  //手动连接编译wsock动态库 
// 编译时需要在exe后面加入参数 "-lwsock32", "-lws2_32"
// 在Settinngs里的coderunner里面加入:
// {"code-runner.executorMap": {"c": "cd $dir && gcc -g -Wall -lm $fileName -o $fileNameWithoutExt -lwsock32 -lws2_32 && $dir$fileNameWithoutExt"}}
#include <stdio.h>
#include <windows.h>
#include <winsock2.h> 
#include <ws2tcpip.h>
 
#define PORT    "32001"         /* Port to listen on */
#define BACKLOG 10              /* Passed to listen() */
 
void handle(SOCKET newsock)
{
    /* send(), recv(), closesocket() */
}
 
int main(void)
{   
    // wVersion = MAKEWORD(2, 2); 2版本Winsock
    WORD wVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    int iResult;
    SOCKET sock;
    struct addrinfo hints, *res;
    int reuseaddr = 1; /* True */
     
    /* Initialise Winsock */
    // WSA(Windows Sockets Asynchronous，Windows异步套接字)的启动命令
    if ((iResult = WSAStartup(wVersion, &wsaData)) != 0) 
    {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }
 
    /* Get the address info */
    // ZeroMemory 用0初始化
    ZeroMemory(&hints, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(NULL, PORT, &hints, &res) != 0) 
    {
        perror("getaddrinfo");
        return 1;
    }
 
    /* Create the socket */
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == INVALID_SOCKET) 
    {
        perror("socket");
        WSACleanup();
        return 1;
    }
 
    /* Enable the socket to reuse the address */
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuseaddr, sizeof(int)) == SOCKET_ERROR) 
    {
        perror("setsockopt");
        WSACleanup();
        return 1;
    }
 
    /* Bind to the address */
    if (bind(sock, res->ai_addr, res->ai_addrlen) == SOCKET_ERROR) 
    {
        perror("bind");
        WSACleanup();
        return 1;
    }
 
    /* Listen */
    if (listen(sock, BACKLOG) == SOCKET_ERROR) 
    {
        perror("listen");
        WSACleanup();
        return 1;
    }
 
    freeaddrinfo(res);
 
    /* Main loop */
    while(1) 
    {
        int size = sizeof(struct sockaddr);
        struct sockaddr_in their_addr;
        SOCKET newsock;
 
        ZeroMemory(&their_addr, sizeof (struct sockaddr));
        newsock = accept(sock, (struct sockaddr*)&their_addr, &size);
        if (newsock == INVALID_SOCKET) 
        {
            perror("accept\n");
        }
        else 
        {
            printf("Got a connection from %s on port %d\n", 
                inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));
 
            handle(newsock);
        }
    }
 
    /* Clean up */
    closesocket(sock);
    WSACleanup();
 
    return 0;
}