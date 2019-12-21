#ifndef _DAY39_
#define _DAY39_
#include <iostream>
//#define T1 //父类指针的步长和子类指针的步长问题
//#define T2 //抽象类基本语法
//#define T3 //函数指针
//#define T4//函数模板与类模板
#define T5 //类模板中的static关键字
using namespace std;
namespace DAY39
{
    class A
    {
        public:
        A() : a(100){
            cout<<"a:"<<a<<endl;
        }
        virtual void test()
        {
            cout<<"test!\n"<<endl;
        }
        private:
        int a;

    };
    class B : public A
    {
        public:
        B() : A(),a(10),b(10){
            cout<<"a:"<<a<<"b:"<<b<<endl;
        }
        void test()override{
            cout<<"children test!"<<endl;
        }
        private:
        int a;
        int b;
    };
}
namespace DAY39A
{
    class A//抽象类
    {
        public:
        A(){
            cout<<"抽象类A构造函数!\n";
        }
        virtual ~A()
        {
            cout<<"抽象类A析构函数!\n";
        }
        virtual void GetArea() = 0;//纯虚函数
        protected:

        private:
    };
    class B : public A//圆形
    {
        public:
        B(double _r = 1):r(_r),pi(3.1415926){
           GetArea();
        }
        ~B()
        {
            cout<<"析构函数B!\n";
        }
        virtual void GetArea()
        {
            cout<<"圆形的面积："<<pi*r*r<<endl;
        }
        private:
        double r;
        double pi;
    };
    class C : public A//矩形
    {
        public:
        C(double x,double y):a(x),b(y){
            GetArea();
        }
        virtual void GetArea()
        {
            cout<<"矩形的面积："<<a*b<<endl;
        }
        private:
        double a;//长
        double b;//宽

    };
    void disp(A* a)//发生多态现象
    {
        a->GetArea();
    }
}
namespace DAY39B
{
    int  (*A)();
    typedef int(*B)();
    int disp()
    {
       cout<<"函数指针！\n";
       return 2;
    }
}
namespace DAY39C
{
    /*类模板*/
    template<class T>class B
    {
        public:
        B();
        virtual ~B();
        private:
        T* a;
    };
    /*函数模板*/
    template<class T> T C(T t1,T t2);
    /*混合式模板*/
    template<class T> class A
    {
        public:
        void disp(T a);
    };
    /*派生类模板*/
    template<class T> class D : public B<T>
    {
        public:
        D();
        ~D();
    };
}
namespace DAY39D
{
    template<class T> 
    class A
    {
        public:
        A();
        ~A();
        static double pi;//static变量必须是确定的类型
    };
}
#endif