#include <iostream>
#include <pthread.h>
#include <unistd.h>
int count = 0;
//#define SampleOne
//#define SampleTwo
#define SampleThree
struct User{
        char* name;
        int count;
};
int main(int argc,char* argv[])
{
    void* disp(void* msg);
    #ifdef SampleOne
    pthread_t t;
    pthread_create(&t,NULL,disp,NULL);
    for(int i = 0;i < 5;++i){
          ++count;
          sleep(1);
    }
    pthread_join(t,NULL);
    #endif
    #ifdef SampleTwo
    void* CountTest(void*);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,CountTest,NULL);
    pthread_create(&t2,NULL,CountTest,NULL);
    disp(NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    #endif
    #ifdef SampleThree
    void* CountTest(void*);
    User u1,u2;
    u1.count = u2.count = 0;
    pthread_t t1,t2;
    pthread_create(&t1,NULL,CountTest,(void*)&u1);
    pthread_create(&t2,NULL,CountTest,(void*)&u2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%d\n",u1.count+u2.count);
    #endif
    return 0;
}
void* disp(void*)
{
    for(int i = 0;i < 5;++i){
    printf("count = %d\n",count);
    sleep(1);
    }
    return NULL;
}
void* CountTest(void* u)
{
    User* user = (User*)u;
    for(int i = 0;i < 5;++i)
    {
        user->count++;
        sleep(1);
    }
}