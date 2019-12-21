#ifndef _DAY40_
#define _DAY40_
#include <iostream>
#include <string.h>
using namespace std;
//#define T1 //函数，类，派生类模板---泛型编程
//#define T2 //模板数组类
//#define T3 //C++类型转换
//#define T4 //异常基本语法
//#define T5 //栈解旋
//#define T6 //C++异常之异常接口声明
#define T7//异常基本语法复习
/*
    template<typename T> or template<class T>
    void Swap(T& a,T& b)
    {
        T c = a;
        a = b;
        b = c;
    }
    函数模板的使用
    分为自动调用和显示调用
    自动调用，编译器根据a和b的类型来推导
    显示调用，告诉编译器，调用的参数类型
    初探函数模板
    写两个函数模板，一个用来排序数组，一个用来打印数组
    为什么函数模板能够执行不同类型参数？
    1.编译器对函数模板进行了两次编译；
    2.第一次编译时，首先去检查函数模板本身有没有语法错误；
    3.第二次编译时，会去找调用函数模板的代码，然后通过代码真正
    真正的参数来生成真正的函数
    所以函数模板只是一个模具，当我们调用它时，编译器就会给
    我们生成正在的函数
    多参数函数模板
    template<class T1,class T2,class T3>
    T1 Add(T2 a,T3 b)
    {
        return static_cast<T1>(a+b);
    }
    注意：
    工程中一般将返回值参数作为第一个模板类型
    如果返回值参数作为了模板类型，则必须需要指定返回值模板类型
    重载函数模板
    1.函数模板可以像普通函数一样被重载
    2.函数模板不接受隐式转换
    3.当有函数模板，以及普通重载函数时，编译器会优先考虑
    普通函数
    4.如果普通函数的参数无法匹配，编译器会尝试进行隐式转换
    若转换成功，便调用普通函数，若转换失败，便调用函数模板；
    5.可以通过空模板实参列表来限定编译器只匹配函数模板
    int r1 = Max(1,2);
    double r2 = Max(0.5,0.8);//限定 编译器只匹配函数模板
*/
/*
    C++类型转换
    【1】隐式类型转换
    不需要用户干预，编译器默认进行的类型转换行为
    分为两种：内置数据类型，自定义数据类型
    1.内置数据类型
    例如混合类型的算术表达式中
    int a = 8;
    double b = 10.7;
    double c = a + b;//a 会被自动转换为double类型
    用转换的结果再与b相加
    由低精度向高精度的转换
    若不满足该原则，编译器会提示编译警告，如下述例子
    double a = 100.2;
    int b = a;
    若不想看到警告，可以选择显式类型转换(又称强制类型转换)
    double a = 100.2;
    int b = (int)a;
    类中要想禁止隐式类型转换，可以使用C++关键字explicit
    2.自定义数据类型
    ......
    【2】显式类型转换(强制类型转换)
    四中强制类型转换操作符：static_cast、const_cast
    dynamic_cast、reinterpret_cast
    2.1 static_cast
    (1)主要用于内置数据类型之间的相互转换，例如
    double a = 12.12;
    float b = 3.14;
    int c = static_cast<int> a;//12
    int d = static_cast<int> b;//3
    (2)也可以转换自定义类型。如果涉及到类,static_cast
    只能在相互联系(继承)的类型间进行转换，且不一定包含虚函数
    class A{};
    class B : public A{};
    class C{};
    void main()
    {
        A *pA = new A;
        B *pB = static_cast<B*>(pA);//编译不会报错，B类继承于A类
        pB = new B;
        pA = static_cast<A*>(pB);//编译不会报错，B类继承于A类
        C *pC = static_cast<C*>(pA);//编译报错
    }
    (3)把void类型指针转换成目标类型的指针(不安全)
    2.2 const_cast
    一、常量指针被转换为非常量指针，且仍然指向原来的对象
    二、常量引用被转换非常量引用，且仍然指向原来的对象
    三、常量对象被强转为非常量对象
    总结：将常量对象转换为可读可写的状态
    2.3 dynamic_cast
    (1)其他三种都是编译时完成的。dynamic_cast是运行时
    处理的，运行时要进行类型检查；
    (2)不能用于内置基本数据类型间的强制转换
    (3)使用dynamic_cast进行类转换时，基类中一定要有虚函数，否则编译不通过
    (4)dynamic_cast转换成功，返回的是指向类的指针或引用，若失败则会
    返回NULL;
    (5)在类层次间进行上行转换时,dynamic_cast和static_cast
    效果是一样的在进行下行转换时，dynamic_cast具有类型检查功能
    比static_cast更安全
    上行：子类指针转换为父类指针；
    下行
    2.4 reinterpret_cast
    它可以转换任何内置的数据类型为其他任何的数据类型，也可以
    转化为指针类型为其他的类型。
    无需考类类型安全或者常量的情形，不到万不得已绝对不用


*/
namespace DAY40
{
    template<class T> T sum(T t1,T t2);
    template<class T> class A{
        public:
        A(T _a,T _b);
        ~A();
        private:
        T a;
        T b;
    };
    template<class T> class B : public A<T>{
        public:
        B(T _a,T _b);
        ~B();
        void disp();
       
    };
}
namespace DAY40A
{
    template<class T,int N> void func(T* t);
}
namespace DAY40B
{
    class A{
        public:
        A():a(1),b(2)
        {
            cout<<"构造函数A\n";
        }
        int a;
        int b;
    };
    class B : public A
    {
        public:
        B() : c(3),d(4){
            cout<<"构造函数B!\n";
        }
        int c;
        int d;
    };
}
namespace DAY40C
{
    int function(int x,int y);
    void test01();
}
namespace DAY40D
{
    class A
    {
        public:
        A():a(1),b(2){
            cout<<"构造函数A!\n";
        }
        ~A()
        {
            cout<<"析构函数A!\n";
        }
        private:
        double a;
        double b;
    };
    double function(double x,double y)
    {
        if(y == 0)
        throw y;
        return x/y;
        }
    void test()
    {
        A p1,p2;
        try
        {
            function(2,0);
        }
        catch(double e)
        {
             cerr<<"除数为0\n";
        }
        catch(...)
        {
            cerr<<"其他异常"<<endl;
        }

    }
       
}
namespace DAY40E
{
    void func2(int a)throw()//声明函数不能抛出异常
    {
        cout<<"此函数不能抛出异常\n";
        /* if(a > 1)
        throw a;*/
    }
}
namespace DAY40F
{
    //栈解旋
    template<class T>
    class A
    {
        public:
        A();
        ~A();
    };
    void Exception_Test();
    void Devide(double x,double y);
}
#endif