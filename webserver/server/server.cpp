#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "tools.h"
#include <iostream>
#include <unistd.h>

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    errif(sockfd == -1, "socket create error");
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    errif(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1,"socket bind error");
    errif(listen(sockfd, SOMAXCONN) == -1, "socket listen error");

    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_len = sizeof(clnt_addr);
    bzero(&clnt_addr, sizeof(clnt_addr));
    int clnt_sockfd = accept(sockfd, (struct sockaddr *)&clnt_addr, &clnt_addr_len);
    errif(clnt_sockfd == -1, "socket accept error");

    printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));

    processEcho(clnt_sockfd);


    return 0;
}


static void processEcho(int sockfd){
    while(true){
        char buf[1024];
        bzero(&buf, sizeof(buf));
        ssize_t read_size = read(sockfd,buf,sizeof(buf));
        if(read_size > 0){
            std::cout << "message from clent fd "<< sockfd << std::endl;
        }
    }
}