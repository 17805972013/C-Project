#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
//#define MethodOne
//#define MethodTwo
#define Test
int main(int argc,char* argv[])
{
    #ifdef Method
    if(argc != 2)
    std::cout<<"操作有误，请重新输入！\n";
    int fd;
    fd = open(argv[1],O_WRONLY);
    int s;//设置追加模式
    s = fcntl(fd,F_GETFL);
    s |= O_APPEND;
    fcntl(fd,F_SETFL,s);
    char buf[BUFSIZ];
    while(fgets(buf,BUFSIZ,stdin) != NULL){
        write(fd,buf,strlen(buf));
    }
    close(fd);
    #endif
    #ifdef MethodTwo
    if(argc != 2)
    std::cout<<"操作有误，请重新输入！\n";
    int fd;
    fd = open(argv[1],O_WRONLY | O_APPEND);
    char buf[BUFSIZ];
    while(fgets(buf,BUFSIZ,stdin) != NULL){
        write(fd,buf,strlen(buf));
    }
    #endif
    #ifdef Test
    int fd;
    char buf[BUFSIZ];
    fd = open("/dev/pts/0",O_WRONLY | O_APPEND);
    while(fgets(buf,BUFSIZ,stdin) != NULL){
        write(fd,buf,strlen(buf));
    }
    #endif
    return 0;
}