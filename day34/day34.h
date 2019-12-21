#ifndef _DAY34_
#define _DAY34_
#include <iostream>
//1.构造函数是c++中用于初始化对象状态的特殊函数
//2.构造函数在创建对象时，自动被调用
//3.构造函数和普通成员函数都遵循重载原则
//4.拷贝构造函数是对象正确初始化的正确保障
//5.必要时候必须手动编写拷贝构造函数。
using namespace std;
class A
{
    public:
    //A(int a=1,int b=2){x1=a,x2=b,printf("x1 = %d---x2 = %d\n",x1,x2);}
    //构造函数固定参数初始化
    //explicit防止构造函数隐式转换。
    explicit A() : x1(1),x2(2){printf("x1 = %d --- x2 = %d\n",x1,x2);}
    A(const A &l){
        printf("拷贝构造函数！\n");
    }
    int operator++()
    {
        return ++x1;
    }
    int operator+(A &l1){
        
        return x1+l1.x1;
    }
    int Getsum(A a)
    {
        a.x1 = 100;
        return a.x1+a.x2;
    }
    int x1;
    int x2;
    //深浅拷贝
    //浅拷贝：将一个指针赋值给另一个指针，就会使得两个指针
    //指向同一块空间,这就产生了浅拷贝
    virtual ~A(){}//虚析构函数
};
#endif