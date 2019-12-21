#ifndef _DAY36_
#define _DAY36_
#include <iostream>
#include <string.h>
using namespace std;
//友元函数的应用
//特点：
//1.友元函数定义在类外部，但有权访问类的所有私有成员
//和保护成员，友元函数并不是成员函数；
//2.友元可以是一个函数也可以是一个类---友元类
//运算符重载本质是函数调用
//重载方式分两种，一种是全局的友元重载函数方式，
//第二种是成员函数重载方式
//重载++与--需要注意的内容
//1.前置重载---
//友元重载friend A& operator++(A &l)
//成员函数重载 A& operator++()
//2.后置重载
//友元重载friend A& operator++(A& l,int)
//成员函数重载 A& operator++(int)
//<<和>>重载
//1.友元重载 friend ostream& operator<<(ostream& out,A& l)
//2.类成员函数无法实现<<操作符重载
class A
{
    public :
    //设置友元类
    friend class B;
    //设置友元函数
    friend void __disp(A& l);
    //构造函数
    A():a(1),b(2),p(new char[3]){
        strcpy(p,"he");
        cout<<"构造函数！\n";
        disp();
    }
    //拷贝构造函数
    A(const A& l){
        cout<<"拷贝构造函数！\n";     
    }
    ~A()
    {
        if(p != NULL){
            delete [] p;
            p = NULL;
        }
        cout<<"析构函数！\n";
    }
    /*成员变量*/
    int a;
    int b;
    char  *p;
    /*静态成员变量---全局变量*/
    //构造函数无法给静态成员变量进行初始化
    static double pi;
    /*成员函数*/
private:
    void disp()
    {
      
        printf("a = %d---b = %d---p = %s\n",a,b,p);
    }
protected:
    void _disp(){
        cout<<"hello friend!\n";
    }
    //析构函数
 public:   
    //成员函数重载=
    A& operator++()
    {
        ++a;
        ++b;
        return *this;
    }
    friend ostream& operator<<(ostream &out,A&l);
    friend istream& operator>>(istream& in,A&l);
    //友元重载方式
    //friend A& operator++(A& l);
    friend A& operator++(A& l,int);
    friend A& operator+(A& l,A& m);
    A& operator=(A& l){
        if(p != NULL)
        {
            delete [] p;
            p = NULL;  
        }
        cout<<"----\n";
        p = new char[3];
        strcpy(p,l.p);
        return *this;
    }
   /* int operator+(A& l)
    {
        return a+l.a;
    }*/
};
class B
{
public://类外部访问
void disp(A& l)
{
    l.disp();
    l._disp();
}
private://类内部访问

protected://类内部访问，子类也可以访问

};
//友元函数
void __disp(A& l){
    l.disp();
    l._disp();
}
//友元重载方式
A& operator+(A& l, A& m)
{
    m.a = l.a + m.a;
    m.b = l.b + m.b;
    return m;
}
/* A& operator++(A& l)
{
    ++l.a;
    ++l.b;
    return l;
}*/
A& operator++(A& l,int)
{
    l.a++;
    l.b++;
    return l;
}
ostream& operator<<(ostream& out,A& l)
{
    out<<l.p<<"ostream"<<endl;
    return out;
}
istream& operator>>(istream& in,A& l)
{
    cout<<"请输入l.a的值：\n";
    in>>l.a;
    cout<<"请输入l.b的值：\n";
    in>>l.b;
    return in;
}
#endif