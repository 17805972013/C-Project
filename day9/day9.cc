#include <iostream>
#include <signal.h>
#include <unistd.h>
#define Interrupt
//#define Ignore
int main(int argc,char* argv[])
{
    #ifdef Interrupt
    void f(int);//函数声明
    int i;
    signal(SIGINT,f);
    for(int i = 0;i < 5;i++){
        printf("hello\n");
        sleep(1);
    }
    #endif
    #ifdef Ignore
    signal(SIGINT,SIG_IGN);
    printf("you can't stop me!\n");
    while(1){
        sleep(1);
        printf("haha\n");
    }
    #endif
    return 0;
}
 void f(int signum)
{
    printf("OUCH!\n");
}
