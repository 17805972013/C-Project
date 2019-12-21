#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define One
int main(int argc,char* argv[])
{
    #ifdef One
    if(argc != 2){
        perror("输入有误，请重新输入！\n");
        exit(1);
    }
    int fd;
    fd = open(argv[1],O_WRONLY | O_APPEND);
    int result;
    char buf[BUFSIZ];
    while(fgets(buf,BUFSIZ,stdin) != NULL){
        result = write(fd,buf,strlen(buf));
    }
    close(fd);
    #endif
    return 0;
}