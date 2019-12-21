#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) == -1){
        perror("socket");
        exit(0);
    }
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);
    //发送消息
    char buf[BUFSIZ];
    memset(buf,'\0',BUFSIZ);
    printf("请输入发送内容：\n");
    scanf("%s",buf);
    if(sendto(sockfd,buf,BUFSIZ,0,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) == -1){
        perror("sendto");
        exit(0);
    }
    //接收消息
    char recvbuf[BUFSIZ];
    memset(recvbuf,'\0',BUFSIZ);
    if(recvfrom(sockfd,recvbuf,BUFSIZ,0,(struct sockaddr*)NULL,(socklen_t*)NULL) == -1){
        perror("recvfrom");
        exit(0);
    }
    printf("receive message from server: %s",recvbuf);
    return 0;
}