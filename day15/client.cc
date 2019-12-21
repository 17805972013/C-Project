#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
//#define MethodOne
#define MethodTwo
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    /*将8000端口转换成二进制数 0001 1111 0100 0000-->0x1f40*/
    serveraddr.sin_port = htons(0x1f40);
    #ifdef MethodOne
    char* c_ipAddr = (char*)"127.0.0.1";
    if(inet_pton(AF_INET,c_ipAddr,&serveraddr.sin_addr) <= 0){
        perror("inet_pton");
        exit(0);
    }
    #endif
    #ifdef MethodTwo
    /*将127.0.0.1转换成二进制数0111 1111 0000 0000 0000 0000 0000 0001*/
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);//0x7f000001表示的是ip地址127.0.0.1
    #endif
    //连接
    int n;
    if((n = connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)))){
        perror("connect");
        exit(0);
    }
    char buf[4096];
    sprintf(buf,"hello world!");
    if(send(sockfd,buf,4096,0) == -1){
        perror("send");
        exit(0);
    }
    char recvbuf[4096];
    if(recv(sockfd,recvbuf,4096,0) == -1){
        perror("recv");
        exit(0);
    }
    printf("%s",recvbuf);
    close(sockfd);

    return 0;
}