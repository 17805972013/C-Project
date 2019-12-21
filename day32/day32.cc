#include "day32.h"
inline void printA()
{
    int a = 10;
    cout<<"a = "<<a<<endl;
}
int main(int argc,char* argv[])
{
   // printf("hello world!\n");
   // cout<<veins::pi<<endl;
    t1.age = 30;
    t1.weight = 101.22;
    int a = 20;
    int b = 30;
    /*C++对三目运算符的增强*/
    (a>b?a:b) = 50;
   // cout<<a<<"---"<<b<<endl; 
    /*引用--别名*/
    //c与d共享一个地址
    //普通引用必须初始化 
    int d;
    int &c=d;
    c=10;
    d=20;
    //cout<<"c="<<c<<"d="<<d<<endl;
    //常引用，不能通过y去修改x了
    int x = 20;
    const int &y = x; 
    //内联函数和函数的实现放在一块,编译器不一定会编译。
    //内敛函数省去了普通函数调用时压栈，跳转和返回的开销啊。

  //  printA();

    p.college = (char*)"Information Institute";
    p.name = (char*)"Qingwei Zeng";
    p.gender = (char*)"male";
    p.age = 24;
    p.constellation = (char*)"Aquarius";
    p.hobby = (char*)"Swimming, running, fitness, playing, traveling, etc.";
    p.Introduction();
    return 0;
}
