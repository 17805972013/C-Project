#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd,connectfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
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
    //监听
    if((listen(sockfd,10)) == -1){
        perror("listen");
        exit(0);
    }
    while(printf("====== waiting ======\n"),1){
        //等待
        if((connectfd = accept(sockfd,NULL,NULL)) == -1){
            perror("accept");
            continue;
        }
        //接收信息
        char recvbuf[BUFSIZ];
        memset(recvbuf,'\0',BUFSIZ);
        if(recv(connectfd,recvbuf,BUFSIZ,0) == -1){
            perror("recv");
            exit(0);
        }
        printf("receive message from client: %s\n",recvbuf);
        //发送信息
        char buf[BUFSIZ];
        memset(buf,'\0',BUFSIZ);
        FILE* fp = popen("date","r");
        fgets(buf,BUFSIZ,fp);
        pclose(fp);
        if(send(connectfd,buf,strlen(buf),0) == -1){
            perror("send");
            exit(0);
        }
        close(connectfd);
    }
    close(sockfd);
    return 0;
}
