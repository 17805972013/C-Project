#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    int connectfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);
    //绑定
    if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) == -1){
        perror("bind");
        exit(0);
    }
    //监听
    if((listen(sockfd,10)) == -1)
    {
        perror("listen");
        exit(0);
    }
    //等待
    char buff[4096];
    int n;
    while(1){
        FILE *fp = popen("date","r");
        char timebuf[256];
        memset(timebuf,'\0',256);
        fgets(timebuf,256,fp);
        pclose(fp);
        if((connectfd = accept(sockfd,(struct sockaddr*)NULL,NULL)) == -1)
        {
            perror("accept");
            continue;
        }
         //向客户端发送回应数据
        if(!fork()){
            /**
             创建子进程
            **/
           if(send(connectfd,timebuf,256,0) == -1) 
           perror("send");
           close(connectfd);
           exit(0);
        }
        n = recv(connectfd,buff,4096,0);
        buff[n] = '\0';
        printf("recv msg from client: %s\n",buff);
        close(connectfd);
    }
    close(sockfd);
    return 0;
}