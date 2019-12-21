#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc,char* argv[])
{
    int mypid;
    mypid = getpid();
    printf("before:mypid = %d\n",mypid);
    mypid = fork();
    mypid = fork();
    mypid = fork();
    mypid = fork();
    if(mypid == 0)
    {
        printf("mypid is %d ,my childpid is %d\n",getpid(),mypid);
        exit(0);
    }
    else
    {
        int pid;
        pid = wait(NULL);
        printf("mypid is %d ,my childpid is %d\n",getpid(),pid);
    }
    //sleep(1);
    //printf("after mypid is %d ,fork said  is %d\n",getpid(),pid);
    return 0;
}