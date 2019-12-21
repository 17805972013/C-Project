#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        exit(0);
    }
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);
    //连接
    if(connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) == -1){
        perror("connect");
        exit(0);
    }
    //发送消息
    while(1){
    char buf[BUFSIZ];
    printf("请输入发送的消息：\n");
    scanf("%s",buf);
    if(send(sockfd,buf,BUFSIZ,0) == -1){
        perror("send");
        exit(0);
    }
    //接收消息
    char recvbuf[BUFSIZ];
    memset(recvbuf,'\0',BUFSIZ);
    if(recv(sockfd,recvbuf,BUFSIZ,0) == -1){
        perror("recv");
        exit(0);
    }
    printf("receive message from server: %s",recvbuf);
    }
    close(sockfd);
    return 0;
}
