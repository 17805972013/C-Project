#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
/* person1 */
int main(int argc,char* argv[])
{
    //创建套接字
    int sockfd;
    fcntl(sockfd,O_NONBLOCK);
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    //初始化
    struct sockaddr_in person2addr;
    person2addr.sin_family = AF_INET;
    person2addr.sin_port = htons(8000);
    person2addr.sin_addr.s_addr = htonl(0x7f000001);
    //绑定
    if(bind(sockfd,(struct sockaddr*)&person2addr,sizeof(person2addr)))
    {
        perror("bind");
        exit(0);
    }
    char recvbuf[4096];
    char buf[4096];
    memset(recvbuf,'\0',4096);
    memset(buf,'\0',4096);
    struct sockaddr_in whoaddr;
    socklen_t length = sizeof(whoaddr);
    while(printf("====== waiting ======\n"),recvfrom(sockfd,recvbuf,sizeof(recvbuf),0,(struct sockaddr*)&whoaddr,&length) > 0){
        printf("receive message from person2: %s",recvbuf);
        //发送消息
        FILE* fp = popen("date","r");
        fgets(buf,sizeof(buf),fp);
        fclose(fp);
        if(sendto(sockfd,buf,strlen(buf),0,(sockaddr*)&whoaddr,length) == -1){
            perror("sendto");
            exit(0);
        }
    }
    close(sockfd);
    return 0;
}