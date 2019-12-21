#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void handleMessage(int connectfd);
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd,connectfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //初始化
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8000);
    serveraddr.sin_addr.s_addr = htonl(0x7f000001);
    //绑定
    if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))){
        perror("bind");
        exit(0);
    }
    //监听
    if(listen(sockfd,10) == -1){
        perror("listen");
        exit(0);
    }
    int pid;
    while(printf("====waitting====\n"),1){
    //等待
    if((connectfd = accept(sockfd,NULL,NULL)) ==-1){
        perror("accept");
        continue;
    }
        printf("parentpid is %d\n",getpid());
        pid = fork();
        pid = fork();
        sleep(1);
        if(pid == 0){
            printf("mypid is %d ,mychild pid is %d\n",getpid(),pid);
            handleMessage(connectfd);
            exit(0);
        }
        else
        {
            int mypid;
            mypid = wait(NULL);
            printf("mypid is %d ,mychild pid is %d\n",getpid(),mypid);
            handleMessage(connectfd);
        }
        close(connectfd);
    }
    close(sockfd);
    return 0;
}
void handleMessage(int connectfd)
{
    //接收消息
        char recvbuf[BUFSIZ];
        if(recv(connectfd,recvbuf,BUFSIZ,0) == -1){
            perror("recv");
            exit(0);
        }
        printf("receive message from client: %s\n",recvbuf);
    //发送消息
        char buf[BUFSIZ];
        FILE* fp = popen("date","r");
        fgets(buf,BUFSIZ,fp);
        pclose(fp);
        if(send(connectfd,buf,strlen(buf),0) == -1){
            perror("send");
            exit(0);
        }
        close(connectfd);
}