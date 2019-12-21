#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAXLINE 4096
int main(int argc,char* argv[])
{
    int sockfd,n,rec_len;
    int i_port = 8000;//默认8000端口
    
    char recvline[4096],sendline[4096];
    char buf[MAXLINE];
    char *c_ipAddr = (char*)"127.0.0.1";
    struct sockaddr_in servaddr;
    if(argc == 1){
        printf("This client will connect server message : IP = 127.0.0.1,port = 8000\n");
    }
    else if(argc == 2)
    {
        c_ipAddr = argv[1];
        printf("This client will connect server message : IP = %s,port = 8000\n",c_ipAddr);
    }
    else if(argc == 3)
    {
        c_ipAddr = argv[1];
        i_port = atoi(argv[2]);
       printf("This client will connect server message : IP = %s,port = %d\n",c_ipAddr,i_port);
    }
    else
    {
        perror("input failed");
        exit(0);
    }
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket");
        exit(0);
    }
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(i_port);
    if(inet_pton(AF_INET,c_ipAddr,&servaddr.sin_addr) <= 0){
        perror("inet_pton");
        exit(0);
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))){
        perror("connect");
        exit(0);
    }
    printf("send msg to server:\n");
    fgets(sendline,4096,stdin);
    if(send(sockfd,sendline,strlen(sendline),0) < 0){
        perror("send");
        exit(0);
    }
    if((rec_len = recv(sockfd,buf,MAXLINE,0)) == -1){
        perror("recv");
        exit(1);
    }
    buf[rec_len] = '\0';
    printf("Received : %s",buf);
    close(sockfd);
    return 0;
}