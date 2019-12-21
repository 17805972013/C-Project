#include "day36.h"
//从重载运算符可以对运算符做出新的解释，但原有基本语义不变：
//1.不改变运算符的优先级
//2.不改变运算符的结合性
//3.不改变运算符所需要的操作数
//4.不能创建新的运算符
//运算符重载是一个函数；
//根据操作数，写出函数参数
//根据业务，完善函数的返回值，及实现函数业务
int main(int argc,char* argv[])
{
    A a;
    A b;
    A &c = a+b;
    cout<<a;
     cout<<c.a<<"---"<<c.b<<endl;
    ++a;
    cout<<a.a<<"---"<<a.b<<endl;
    a++;
    cout<<a.a<<"---"<<a.b<<endl;
    cin>>a;
    cout<<a.a<<"istream"<<a.b<<endl;
    printf("hello...\n");
    return 0;
}