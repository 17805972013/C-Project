#include <iostream>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
/** 并行连接客户端 **/
struct ServerIP_Port
{
    int port;//端口号
    int addr;//IP地址
    char *name;
};
void* Create_Socket(void*);
int main(int argc,char* argv[])
{
    ServerIP_Port server1,server2;
    server1.name = (char*)"hello server1\n";
    server1.port = 8000;
    server1.addr = 0x7f000001;

    server2.name = (char*)"hello server2\n";
    server2.port = 8001;
    server2.addr = 0x7f000001;

    pthread_t t1,t2;
    pthread_create(&t1,NULL,Create_Socket,(void*)&server1);
    pthread_create(&t2,NULL,Create_Socket,(void*)&server2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    return 0;
}
void* Create_Socket(void* Server)
{
     /** 创建套接字 **/
    ServerIP_Port* server = (ServerIP_Port*)Server;
    int sockfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    /** 初始化服务器 **/
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(server->port);
    serveraddr.sin_addr.s_addr = htonl(server->addr);
    /** 连接服务器 **/
    if(connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))){
        perror("connect");
        exit(0);
    }
    /** 发送数据 **/
    char *buf = server->name;
    if(send(sockfd,buf,strlen(buf),0) == -1){
        perror("send");
        exit(0);
    }
    /** 接收数据 **/
    char recvbuf[BUFSIZ];
    if(recv(sockfd,recvbuf,BUFSIZ,0) == -1){
        perror("recv");
        exit(0);
    }
    printf("%s",recvbuf);
}