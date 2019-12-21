#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#define DELAY 2
//#define One
#define Two
int main(int argc,char* argv[])
{
    void child_node(int);
    void parent_node(int);
    int newpid;
    if((newpid = fork()) == -1)
        perror("fork");
    else if(newpid == 0)
        child_node(DELAY);
    else
        parent_node(newpid);
    
    return 0;
}
void child_node(int delay)
{
    printf("child %d here.will sleep for %d seconds\n",getpid(),delay);
    sleep(delay);
    printf("child done.about to exit\n");
    exit(17);
}
void parent_node(int childpid)
{
    #ifdef One
    int wait_rv;
    wait_rv = wait(NULL);//父进程等待子进程结束，返回值是子进程的pid
    printf("done waiting for %d.Wait returned:%d\n",childpid,wait_rv);
    #endif
    #ifdef Two
    int wait_rv;
    int child_status;
    int high_8,low_7,bit7;
    wait_rv = wait(&child_status);//父进程等待子进程结束，返回值是子进程的pid
    printf("done waiting for %d.Wait returned:%d\n",childpid,wait_rv); 
    high_8 = child_status>>8;
    low_7 = child_status & 0x7f;
    bit7 = child_status & 0x80;
    printf("status:exit = %d,sig = %d,core = %d\n",high_8,low_7,bit7);
    #endif
}