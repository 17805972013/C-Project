#ifndef _DAY37_
#define _DAY37_
#include <iostream>
#include <string.h>
#define Friend
//#define NoFriend
//操作符重载---=必须是成员变量函数
//重载返回引用本身
using namespace std;
class A
{
    public:
    //构造函数
    A():a(1),b(2),p(new char[3]){
        cout<<"构造函数！\n";
        strcpy(p,"he");
        disp();
    }
    //拷贝构造函数
    A(const A& l){
        if(p != NULL)
        {
            delete [] p;
            p = NULL;
        }
        a = l.a;
        b = l.b;
        p = new char[3];
        strcpy(p,l.p);
        cout<<"拷贝构造函数!\n";
    }
    //析构函数
    ~A()
    {
        cout<<"析构函数！\n";
        if(p != NULL){
            delete [] p;
            p = NULL;
        }
    }
    //成员变量
    static double pi;
    int a;
    int b;
    char* p;
    //成员函数
    void disp();
    //操作符重载
    //深度拷贝
    int operator[](int i)
    {
        return i;
    }
    A& operator=(A& l)
    {
        if(p != NULL)
        {
            delete [] p;
            p = NULL;
        }
        a = l.a;
        b = l.b;
        p = new char[3];
        strcpy(p,l.p);
        return *this;
    }
    //友元函数重载
    #ifdef Friend
    friend A& operator+(A& l,A& m);
    #endif
    #ifdef NoFriend
    //成员函数重载
    A& operator+(const A& l)
    {
        a += l.a;
        b += l.b;
        if(p != NULL)
        {
            delete [] p;
            p = NULL;
        }
        p = new char[3];
        strcpy(p,l.p);
        return *this;
    }
    //前置 ++
    A& operator++()
    {
        ++a;
        ++b;
        return *this;
    }
    #endif
};
A& operator+(A& l,A& m)
{
    l.a = l.a + m.a;
    l.b = l.b + l.b;
    return l;
}
#endif