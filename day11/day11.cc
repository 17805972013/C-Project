#include <iostream>
#include <unistd.h>
//#define TestOne
#define TestTwo
int main(int argc,char* argv[])
{
    #ifdef TestOne
    int ret_from_fork,mypid;
    mypid = getpid();
    printf("Before:my pid is %d\n",mypid);
    ret_from_fork = fork();
    sleep(1);
    printf("After: my pid is %d ,fork() said %d\n",getpid(),ret_from_fork);
    #endif
    #ifdef TestTwo
    printf("my pid is %d\n",getpid());
    fork();
    fork();
    fork();
    printf("mypid is %d\n",getpid());
    #endif
    return 0;
}