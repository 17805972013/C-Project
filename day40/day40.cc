#include "day40.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    /*
        函数，类，派生类模板
    */
    cout<<DAY40::sum<string>("he","llo\n");
    DAY40::A<string> a("","llo");
    DAY40::B<int> b(1,2);
    #endif
    #ifdef T2
    double a[10] = {0};
    DAY40A::func<double,10>(a);
    #endif
    #ifdef T3
    typedef  DAY40B::A A;
    typedef  DAY40B::B B;
    A *a = new B;
    A *b;
    b = static_cast<B*>(a);
   // b = dynamic_cast<B*>(a);会报错
    cout<<b->a<<endl;
    #endif
    #ifdef T4
    /*
    catch是严格按照类型匹配
    异常可以跨越函数 
    基本语法块
        try
        {
            throw y
        }
        catch(参数类型 e)
        {
            //异常处理方法
        }
        catch(...)
        {
            //其他异常处理方式
            throw;//继续往外抛
        }
    
    */
    DAY40C::test01();
    #endif
    #ifdef T5
    /*
        当函数发生异常的时候，函数内部的变量或者对象内存都
        会被析构掉，这样的现象叫做栈解旋
        栈解旋官方定义：当异常被抛出后，从进入try块起，到异常被抛出
        前，这期间在栈上构造的所有对象，都会被自动析构，析构的顺序与构造期间
        顺序相反。这一过程被称为栈解旋
    */
    DAY40D::test();
    #endif
    #ifdef T6
    /*
        异常接口声明:提供了一种方案能够随着函数声明列出该函数
        可能抛出的异常保证函数不会抛出任何其他类型的异常
        void func()throw(int,float,char);
        这个函数只能抛出这三种类型的错误，抛出其他就报错
        void func2()throw()
        这个函数不能抛出异常
    */
    try
    {
        DAY40E::func2(2);
    }
    catch(int e)
    {
        cerr<<"int型类型错误\n";
    }
    catch(...)
    {
        cerr<<"未知类型错误！"<<endl;
    }
    
    #endif
    #ifdef T7
    DAY40F::Exception_Test();
    #endif
    cout<<"hello..."<<endl;
    return 0;

}
template<typename T> T DAY40::sum(T t1,T t2)
{
    return t1+t2;
}
template<typename T> DAY40::A<T>::A(T t1,T t2):a(t1),b(t2)
{
    cout<<"构造函数A"<<a+b<<endl;
}
template<class T> DAY40::A<T>::~A()
{
    cout<<"析构函数A"<<endl;
}
template<class T> DAY40::B<T>::B(T t1,T t2) : A<T>(t1,t2)
{
    cout<<"构造函数B"<<endl;
}
template<class T>DAY40::B<T>::~B()
{
    cout<<"析构函数B"<<endl;
}
template<class T,int N> void DAY40A::func(T* _t)
{
    T a[N];
    for(int i = 0;i < N;++i){
        a[i] = _t[i]+1;
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    
}
int DAY40C::function(int x,int y)
{
    if(y ==0)
    throw y;
    return x/y;
}
void DAY40C::test01()
{
    try
    {
        function(10,0);
    }
    catch(int e)
    {
        std::cerr << "除数为0！" << '\n';
    }
    
}
void DAY40F::Exception_Test()
{
    try
    {
        //DAY40F::Devide(3,4);
        DAY40F::Devide(10,0);
    }
    catch(double e)
    {
        cerr<<"除数为0！\n";
    }
    catch(...)
    {
        cerr<<"其他类型错误！\n";
    }
}
void DAY40F::Devide(double x,double y)
{
    A<int> p1;
    A<double> p2;
    if(y == 0)
    throw y;
    cout<<"结果为:"<<x/y<<endl;;
}
template<class T> DAY40F::A<T>::A()
{
    cout<<"构造模板函数A!\n";
}
template<class T> DAY40F::A<T>::~A()
{
    cout<<"构造析构函数A!\n";
}