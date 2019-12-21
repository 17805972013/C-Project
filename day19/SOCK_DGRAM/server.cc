#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd == -1){
        perror("socket");
        exit(0);
    }
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //绑定
    if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))){
        perror("bind");
        exit(0);
    }
    //接收数据
    char recvbuf[BUFSIZ];
    memset(recvbuf,'\0',BUFSIZ);
    struct sockaddr_in clientaddr;
    unsigned int length = sizeof(clientaddr);
    while(recvfrom(sockfd,recvbuf,BUFSIZ,0,(struct sockaddr*)&clientaddr,&length) > 0){
        printf("receive message from client: %s",recvbuf);
    //发送数据
    char buf[BUFSIZ];
    FILE* fp = popen("date","r");
    fgets(buf,BUFSIZ,fp);
    pclose(fp);
    if(sendto(sockfd,buf,BUFSIZ,0,(struct sockaddr*)&clientaddr,length) == -1){
        perror("sendto");
        exit(0);
    }
    }
    close(sockfd);
    return 0;
}