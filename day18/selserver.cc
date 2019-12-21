#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);
    //绑定
    if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)))
    {
        perror("bind");
        exit(0);
    }
    //接收数据
    char recvbuf[BUFSIZ];
    memset(recvbuf,'\0',BUFSIZ);
    struct sockaddr_in clientaddr;
    unsigned int length = sizeof(clientaddr);
    while(recvfrom(sockfd,recvbuf,BUFSIZ,0,(sockaddr*)&clientaddr,&length) > 0){
        printf("receive message from client : %s\n",recvbuf);

    }

    return 0;
}