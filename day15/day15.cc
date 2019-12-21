#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
int main(int argc,char*argv[])
{
    int sockfd;
    //创建套接字
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);
    //连接
    if(connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)))
    {
        perror("connect");
        exit(0);
    }
    //发送数据
    char buf[256];
    fgets(buf,256,stdin);
    if((send(sockfd,buf,strlen(buf),0)) == -1)
    {
        perror("send");
        exit(0);
    }
    //接收数据
    char recvbuf[256];
    if((recv(sockfd,recvbuf,256,0)) == -1)
    {
        perror("recv");
        exit(0);
    }
    printf("%s",recvbuf);
    close(sockfd);
    return 0;
}