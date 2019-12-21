#include <iostream>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
    void showdata(char*fname,int fd);
    int fd1,fd2;
    int retval;/* return from select */
    int maxfd;/* max fd plus 1 */
    struct timeval timeout;/* how long to wait */
    fd_set readfds;
    if((fd1 = open(argv[1],O_RDONLY)) == -1)
    {
        perror(argv[1]);
        exit(0);
    }
    if((fd2 = open(argv[2],O_RDONLY)) == -1)
    {
        perror(argv[2]);
        exit(0);
    }
    while(1){
        /** make a list of file descriptors to watch **/
        FD_ZERO(&readfds);
        FD_SET(fd1,&readfds);
        FD_SET(fd2,&readfds);
        timeout.tv_sec = 10;/* set seconds */
        timeout.tv_usec = 0;/* no useconds */
        /** wait for input **/
        retval = select(maxfd,&readfds,NULL,NULL,&timeout);
        std::cout<<fd1<<"----\n";
        std::cout<<fd2<<"-----\n";
        std::cout<<maxfd<<"------"<<std::endl;
        if(retval == -1){
            perror("select");
            exit(0);
        }
        if(retval > 0){
            /** check bits for each fd **/
            if(FD_ISSET(fd1,&readfds))
            showdata(argv[1],fd1);
            if(FD_ISSET(fd2,&readfds))
            showdata(argv[2],fd2);
        }
        else
        {
            printf("no input after %d seconds\n",10);
        }
        
    }
    close(fd1);
    close(fd2);
    return 0;
}
void showdata(char* fname,int fd)
{
    char buf[BUFSIZ];
    int n;
    fflush(stdout);
    n = read(fd,buf,BUFSIZ);
    printf("%s: %d\n",fname,n);
    if(n == -1){
        perror("read");
        exit(0);
    }
    write(fd,buf,n);
    write(fd,"\n",1);
}