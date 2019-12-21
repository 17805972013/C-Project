#include <iostream>
#include <unistd.h>
//#define _VOID
using namespace std;
void A(void* _message);
int main()
{
    #ifdef _VOID
    int p;
    p = 12;
    cout<<&p<<endl;
    A(&p);
    #endif
    char *p;
    int result = read(0,p,4);
    cout<<result<<endl;
    return 0;
}
void A(void* _message)
{

    int *p = (int*)_message;//强制性转换
    cout<<*p<<endl;
}