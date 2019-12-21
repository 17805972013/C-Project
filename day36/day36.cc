#include "day36.h"
//A::pi = 3.14;
 /*静态成员变量全局且共享，即所有该类共享这资源*/
double A::pi = 3.14;
int main(int argc,char*argv[])
{
    
   
    A a;
    A b;
    b = a;
    A d;
    B c;
    //友元类访问私有成员,保护成员
    a.pi = 3.1415926;
    c.disp(a);
    __disp(a);
    printf("pi = %f\n",A::pi);
  //  printf("d.pi = %f\n",d.pi);
    printf("hello..\n");
    return 0;
}