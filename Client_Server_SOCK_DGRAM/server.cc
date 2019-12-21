#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
/*服务端*/
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd,connectfd;
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
    //接收消息
        char recvbuf[256];
        struct sockaddr_in clientaddr;
        unsigned int length = sizeof(clientaddr);
        int n;
    while(recvfrom(sockfd,recvbuf,256,0,(struct sockaddr*)&clientaddr,&length) > 0){
           printf("receive message from client:%s\n",recvbuf);
    //发送数据
        char buf[4096];
        memset(buf,4096,'\0');
        FILE* fp = popen("date","r");
        fgets(buf,4096,fp);
        pclose(fp);
        if((sendto(sockfd,buf,strlen(buf),0,(struct sockaddr*)&clientaddr,length)) == -1){
            perror("sendto");
            exit(0);
        }
    }
     
        
    close(sockfd);
    return 0;
}