#ifndef _DAY38_
#define _DAY38_
#include <iostream>
#include <string.h>
//#define AuthorityClass//子类继承后的权限情况
//#define T1//基类指针引用指向子类对象 
//#define T2//继承中的构造析构函数调用原则
//#define T3//继承和组合混搭下的构造和析构
//#define T4//初始化静态成员变量
//#define T5//虚继承概念的引入
//#define T6//多态的实现以及原理
//#define T7//实现多态的一个例子
//#define T8//虚析构函数的应用
//#define T9//虚指针存在证明及虚函数表
#define T10//构造函数中是否能实现多态
using namespace std;//多继承和虚继承
//类型(赋值)兼容性原则
//1.子类对象可以当做父类的对象使用(子类是特殊的父类)
//2.子类对象可以直接赋值父类对象
//3.子类对象可以直接初始化父类对象
//4.父类指针可以直接指向子类对象
//5.父类引用可以直接引用子类对象
//基类指针(引用)指向子类对象
//P* p = NULL;
//C c;
//p = &c;
//继承中的对象模型(内存模型)
//1.普通的成员变量存储在变量中；
//2.静态的成员变量存储在全局区；
//3.成员函数存储在代码片段区.
//继承中的析构函数调用原则
//1.子类对象在创建时会首先调用父类的构造函数
//2.父类构造函数执行完毕后，执行子类的构造函数
//3.当父类的构造函数有参数时，必须在子类的初始化列表中调用；
//析构函数执行的顺序和构造函数的顺序相反。
//继承和组合混搭下的构造和析构
//1.先调用父类的构造函数，再调用组合对象的构造函数，最后再调用自己的构造函数
//2.先调用自己的析构函数，再调用组合对象的析构函数，最后调用父类的析构函数
//总结：构造函数调用和析构函数调用顺序相反。
//父类>组合类>子类
//继承中国同名的成员函数和成员变量处理方法
//1.子类的成员变量和父类的成员变量同名时子类依然从父类中
//继承同名变量，但是子类同名变量会屏蔽父类的同名变量，调用方法
//父类::同名变量or函数
//继承中的static关键字
//1.基类定义的静态成员被所有的派生类共享；
//2.根据static成员自身的访问特性和派生类的继承方式
//在类中具有不同的访问性质；
//派生类中访问静态成员，使用以下两种形式：
//数据类型 类名::成员名
//数据类型 对象名.成员名
//注意静态变量是属于全局变量，初始化必须在类外进行，构造
//多继承概念
//class 派生类名 : 访问控制符 基类名1,访问控制符 基类名2
//虚继承的引入
//C++多态的实现及原理
//1.用virtual关键字申明的函数叫做虚函数
//2.存在虚函数的类都有一个一维的虚函数表叫做虚表，类的对象
//有一个指向虚表开始的虚指针.虚表是类对应的，虚表指针是和对象
//相对应的。
//3.多态性是一个接口多种实现，是面向对象的核心，分为类的
//多态性和函数的多态性；
//4.多态用虚函数来实现，结合动态绑定；
//5.纯虚函数是虚函数再加上=0;
//6.抽象类是指包括至少一个纯虚函数的类。
//virtual实现多态机制实现机制
//1.编译器在编译的时候，发现Father中有虚函数，此时编译器会为每个包含
//虚函数的类创建一个虚表，该表是一个一维数，在这个数组中
//存放每个虚函数的地址
//2.初始化父类对象的虚表指针，该虚表指针指向父类的虚表
//当执行子类的构造函数时，子类对象的虚表指针被初始化，
//指向自身的虚表
//实现多态的三个条件
//1.要有继承
//2.要有虚函数重写
//3.用父类指针指向子类对象
//虚析构函数的使用
//为了防止资源释放不完全的情况
//在销毁子类时，如果不加virtual对象销毁只调用了父类的析构函数
//这时子类释放内存时可能造成内存泄露
//总结---重载、重写、重定义
//重载
//1.同一个类中的同名函数会重载；
//2.重载函数的函数名相同，参数不同，不能用返回值判断是否是
//函数重载;
//3.在不同类中的同名函数不是重载。
//重写
//1.重写发生在派生类和基类之间；
//2.若派生类和基类有函数相同的成员函数，并用virtual关键字声明，则
//此成员函数为重写
//3.若派生类和基类有函数原型相同的成员函数，但没有virtual
//关键字声明，则为重定义;
//重写的派生类成员函数会覆盖与原型相同的基类成员函数。
//重定义
//1.重定义发生在派生类和基类之间；
//2.若派生类和基类有函数原型相同的成员函数，但没有virtual关键
//字声明，则派生类成员函数为重定义；
//3.若派生类和基类有函数名相同但参数不同地成员函数，则派生类成员函数
//为重定义
//4.重定义的派生类成员函数会隐藏相应的基类成员数。
//覆盖和隐藏
//覆盖：基类定义的虚函数会被子类所修改覆盖
//隐藏:基类和子类定义相同的函数时，派生类的成员函数会隐藏基类的成员函数。
//多态实现原理探究
//编译器为每个对象分配了一个虚表指针，每个调用虚函数都是通过
//虚表指针来索引；
//C++多态性就是通过晚绑定技术来实现。
//虚指针存在证明及虚函数表
//子类的虚函数指针是分布初始化的_多态面试题
//1.要初始化子类，初始化是分布的
//2.当执行父类的构造函数时，子类虚指针指向父类的虚函数表
//当父类的构造函数运行完毕后，会把子类的虚指针指向子类的虚函数表
//vptr->父类虚函数表->子类虚函数表,所以不可能发生多态现象
//指针能够直接指向其他派生类可称为多态，即
//S son;
//P* p = &son
namespace _DAY38
{
    class A{
       public:
       static double pi;
       //构造函数
       A(int _a,int _b,int _c):a(_a),b(_b),c(_c){
           cout<<"构造函数A"<<endl;
           printf("a = %d , b = %d , c = %d\n",a,b,c);
       }
       ~A(){
           cout<<"析构函数A!\n";
       }
       void disp();
       //成员函数重载
       A& operator=(A& l)
       {
           a = l.a;
           b = l.b;
           c = l.c;
           return *this;
       }
            int a;
       protected:
            int b;
      private:
            int c;
    };
    class B : public A
    {
        public:
        B(int _a,int _b,int _c):A(_a,_b,_c){cout<<"B构造函数！\n";}
        ~B(){
                cout<<"析构函数B！\n";
            }
        void disp();


    };
class C : protected A
    {
        public:
         C(int _a,int _b,int _c):A(_a,_b,_c){cout<<"C构造函数！\n";}
        ~C(){
                cout<<"析构函数C！\n";
        }
        void disp();
    };
class D : private A
    {
        public:
        D(int _a,int _b,int _c):A(_a,_b,_c){cout<<"D构造函数！\n";}
        ~D(){
                cout<<"析构函数D！\n";
        }
        void disp();
    };
    class E : public A{
        public:
        E(int _a,int _b,int _c):A(_a,_b,_c),b(_a,_b,_c){
            cout<<"构造函数E!\n";
        }
        ~E(){
            cout<<"析构函数E!\n";
        }
        //成员变量
        B b;
            };
}
namespace __DAY38{

    class A{
        public:
        A():a(1),b(2),c(3){
            printf("a = %d , b = %d , c = %d\n",a,b,c);
            cout<<"构造函数A!\n";
        }
        ~A()
        {
            cout<<"析构函数A!\n";
        }
        int a;
        protected:
        int b;
        private:
        int c;
    };
     class B{
        public:
        B():a(2),b(3),c(4){
            printf("a = %d , b = %d , c = %d\n",a,b,c);
            cout<<"构造函数B!\n";
        }
        ~B()
        {
            cout<<"析构函数B!\n";
        }
        int a;
        protected:
        int b;
        private:
        int c;
    };
    class C : public A,protected B
    {
        public:
        C():A(),B(){
            cout<<"构造函数C!\n";
        }
        ~C()
        {
            cout<<"析构函数C!\n";
        }
        void disp();

    };
}
namespace DAY38A
{
    class A
    {
        public:
        A(int _a,int _b,int _c):a(_a),b(_b),c(_c){
            printf("a = %d , b = %d , c = %d\n",a,b,c);
            cout<<"构造函数A!\n";
        }
        ~A(){

            cout<<"析构函数A！\n";
        }
        int a;
        protected:
        int b;
        private:
        int c;
    };
    class B : public A{
        public:
        B():A(1,2,3){
            cout<<"构造函数B!\n";
        };
        ~B(){
            cout<<"析构函数B!\n";
        }
    };
    class C : public A{
        public:
        C():A(2,3,4){
            cout<<"构造函数C!\n";
        }
        ~C(){
            cout<<"析构函数C!\n";
        }
    };
    class D : public B,public C{
         public:
        D():B(),C(){
            cout<<"构造函数D!\n";
        }
        ~D(){
            cout<<"析构函数D!\n";
        }
        void disp();

    };
}
namespace DAY38B
{
    class A{
        public:
        A() : a(1),b(2),c(3){
            cout<<"构造函数A!\n";
        }
        ~A(){
            cout<<"析构函数A！\n";
        }
        int a;
        virtual void disp();
        protected:
        int b;
        private:
        int c;
    };
    class B : public A{
        public:
        B():A(){
            cout<<"构造函数B！\n";
        }
        ~B(){
            cout<<"析构函数B!\n";
        }
        void disp();

    };
}
namespace DAY38C
{
    class Herio
    {
        public:
        Herio(int _power = 10) : power(_power){
            printf("初代英雄！\n");
        }
        ~Herio(){
            printf("析构函数Herio!\n");
        }
        int power;
        virtual int Power() 
        {
            return power;
        }

    };
    class Fighter
    {
        public:
        int power;
        Fighter() : power(15){
            printf("初代敌人！\n");
        }
        ~Fighter(){
            printf("析构函数Fighter!\n");
        }
        virtual int Power()
        {
            return power;
        }
    };
    class Herio2 : public Herio
    {
        public:
        int Power()override
        {
            return 20;
        }
    };
    class Herio3 : public Herio
    {
        public:
        int Power()override
        {
            return 30;
        }
    };
    void Result(Herio *herio,Fighter *fighter);
}
namespace DAY38D
{
    class A
    {
        public:
        A() : p(new char[3]){
            strcpy(p,"Hi");
            cout<<"构造函数A!"<<endl;
        }
        virtual ~A(){
                cout<<"析构函数A!\n";
        }
        char *p;
    };
    class B : public A
    {
        public:
        B(){
            cout<<"构造函数B!\n";
        }
        ~B(){
            cout<<"析构函数B!\n";  
        }
    };
}
namespace DAY38E
{
    class A
    {
        public:
        virtual ~A(){}
        private:
        int a;
    };
    class B
    {
        public:
        ~B(){}
        private:
        int a;
    };

}
namespace DAY38F
{
    class A{
        public:
        A(){
            cout<<"构造函数A\n";
            disp();
        }
        virtual void disp()
        {
            cout<<"I am Father!\n";
        }
    };
    class B : public A
    {
        public:
        B(){
            cout<<"构造函数B!\n";
            disp();
        }
         void disp()
        {
            cout<<"I am Son!\n";
        }
    };
}
using namespace _DAY38;
double A::pi = 3.14159;//初始化静态变量，实则是全局变量
#endif