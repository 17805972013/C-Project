#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define MethodOne
//#define MethodTwo
int main(int argc ,char* argv[])
{
    #ifdef MethodOne
    int fd;
    if(argc != 2)
    {
        perror("输入有误，请重新输入!\n");
        exit(1);
    }
    fd = open(argv[1],O_WRONLY);
    std::cout<<fd<<std::endl;
    char buf[BUFSIZ];
    int s;
    int result;
    s = fcntl(fd,F_GETFL);
    s |= O_APPEND;
    result = fcntl(fd,F_SETFL,s);
    std::cout<<"----"<<fd<<"---";
    if(result == -1)
    perror("setting APPEND");
    while(fgets(buf,BUFSIZ,stdin) != NULL){
        write(fd,buf,strlen(buf));
    }
    close(fd);
    #endif
    #ifdef MethodTwo
    char buf[BUFSIZ];
    while(scanf("%s",buf) != EOF){
         FILE *fp = fopen(argv[1],"a+");
         fprintf(fp,"%s\n",buf);
         fclose(fp);
    }
    #endif
    return 0;
}