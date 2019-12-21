#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
/*客户端*/
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
    //发送数据
    char buf[4096];
    printf("请输入发送的信息：\n");
    fgets(buf,4096,stdin);
    if((sendto(sockfd,buf,strlen(buf),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr))) == -1){
        perror("sendto");
        exit(0);
    }
    //接收数据
    char recvbuf[4096];
    socklen_t length;
    length = sizeof(serveraddr);
    if((recvfrom(sockfd,recvbuf,4096,0,NULL,NULL)) == -1){
        perror("recvfrom");
        exit(0);
    }
    printf("receive:%s",recvbuf);
    return 0;
}
