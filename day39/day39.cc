#include "day39.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    /*
        如果子类在继承了父类之后，没有增加属性，那么此时它们
        的步长一致，如果子类增加了属性那么子类的步长将大于父类
    */
    typedef DAY39::B B;
    typedef DAY39::A A;
    B b[] = {B(),B(),B()};
    B *c;
    A *a;
    c = b;
    a = b;
    c++;
    a++;
    c->test();
    //a->test();//这句话屏蔽，正常运行，放出来，代码运行错误
    //就是因为父类步长小,++之后访问子类属性出错
    #endif
    #ifdef T2
    /*
        在多态的基础上，将父类函数，用virtual修饰，并=0，形成
        纯虚函数，进而这个类也变为抽象类，为继承它类，提供统一
        接口，继承它的类，需要实现这个类，否则仍然是抽象类
        抽象类不能被实例化
        面向抽象类编程(面向一套预先定义好的接口编程)
    */
    typedef DAY39A::B B;
    typedef DAY39A::A A;
    typedef DAY39A::C C;
     B *b = new B(2);
     C *c = new C(2,3);
     DAY39A::disp(b);
     DAY39A::disp(c);
     delete b;
     delete c;
    #endif
    #ifdef T3
    //两种调用方式
    //1.
    DAY39B::A;
    DAY39B::A = DAY39B::disp;
    cout<<DAY39B::A()<<endl;
    //2.
    DAY39B::B l;
    l = DAY39B::disp;
    cout<<l()<<endl;
    #endif
    #ifdef T4
    DAY39C::A<string> a;
    a.disp("字符串");
    DAY39C::A<int> b;
    b.disp(2);
    DAY39C::B<int> c;
    cout<<DAY39C::C<string>("he","llo!\n");
    DAY39C::D<int> d;
    #endif
    #ifdef T5
    typedef DAY39D::A<double> A; 
    A a;
    cout<<A::pi<<endl;

    #endif
    return 0;
}
template<class T> void DAY39C::A<T>::disp(T a)
{
    cout<<a<<"类模板"<<endl;
}
template<class T> DAY39C::B<T>::B() : a(new T)
{
    cout<<"构造函数类B模板!"<<endl;
    cout<<"sizeof a:"<<sizeof(a)<<endl;
}
template<class T> DAY39C::B<T>::~B()
{
    if(a != NULL)
    {
        delete [] a;
        a = NULL;
        cout<<"析构函数类B!"<<endl;
    }
}
template<class T> T DAY39C::C(T t1,T t2)
{
    cout<<"函数类模板!\n";
    return t1+t2;
}
template<class T> DAY39C::D<T>::D()
{
    cout<<"构造函数D"<<endl;
}
template<class T> DAY39C::D<T>::~D()
{
    cout<<"析构函数D"<<endl;
}
template<class T> double DAY39D::A<T>::pi = 3.14;
template<class T>   DAY39D::A<T>::A()
{
    cout<<"构造函数A!\n";
}
template<class T> DAY39D::A<T>::~A()
{
    cout<<"析构函数A!\n";
}

