#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
//#define MethodOne
#define MethodTwo
int main(int argc,char* argv[])
{

    #ifdef MethodOne
    int pid;
    pid = fork();
    disp("hello ");
    pid = fork();
    disp("world\n");
    #endif
    #ifdef MethodTwo
    pthread_t t1,t2;
    void* disp(void* msg);
    pthread_create(&t2,NULL,disp,(void*)"world\n");
    pthread_create(&t1,NULL,disp,(void*)"hello ");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    #endif
    return 0;
}
void* disp(void* msg)
{
    char *_msg = (char*)msg;
    for(int i = 0;i < 5;++i){
         printf("%s",_msg);
         fflush(stdout);//清空标准输出口
         sleep(1);
    }
    return NULL;
   
}