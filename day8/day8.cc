#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
    int fd;
    struct termios info;
    int rv;
    rv = tcgetattr(0,&info);
    if(rv == -1){
        perror("tcgetattr");
        exit(1);
    }
    if(info.c_lflag & ECHO)
    printf("echo is on ,since its bit is 1\n");
    else
    {
        printf("echo is OFF,since its bit is 0\n");
    }
    
    return 0;
}