#include "day38.h"
int main(int argc,char* argv[])
{
    #ifdef AuthorityClass
    B b(1,2,3);
    cout<<"B外部:"<<b.a<<endl;
    b.disp();
    C c(1,2,3);
    cout<<"C外部:"<<endl;
    D d(1,2,3);
    cout<<"D外部:"<<endl;
    #endif
    #ifdef T1
    A *a = NULL;
    B b(1,2,3);
    a = &b;
    //子类对象初始化父类对象
    A c = b;
    //子类对象赋值父类对象,可以考虑加入重载
    A l(2,3,4);
    l = b;
    l.disp();
    #endif
    #ifdef T2
    B b(1,2,3);
    #endif
    #ifdef T3
    E e(1,2,3);
    #endif
    #ifdef T4
    __DAY38::C c;
    c.disp();
    #endif 
    #ifdef T5
    DAY38A::D d;
    d.disp();
    #endif
    #ifdef T6
    DAY38B::B b;
    DAY38B::A *a = &b;
    /*
    当把函数disp()去掉virtual,输出的是I am Father!
    原理：
    子类
    初始化顺序:父类，子类
    ---父类：初始化虚表地址(虚函数地址)
    ---自身增加部分
    ---子类:初始化虚表地址(虚函数地址)
    因此能够解释为何不加virtual输出的是I am Father!
    */
    a->disp();
    #endif
    #ifdef T7
    DAY38C::Herio h;
    DAY38C::Herio2 h2;
    DAY38C::Fighter f;
    DAY38C::Herio3 h3;
    DAY38C::Result(&h,&f);
    DAY38C::Result(&h2,&f);
    DAY38C::Result(&h3,&f);
    #endif
    #ifdef T8
    /*
    虚析构函数使用的意义：---多态的条件下(子类是特殊的基类)
    如果将基类的析构函数去掉virtual，则子类释放内存时
    只会释放基类，从而导致内存泄露。
    */
    DAY38D::A* a = new DAY38D::A();
    DAY38D::A* b = new DAY38D::B();//子类是特殊的基类
    delete a;
    delete b;
    #endif
    #ifdef T9
    /*
        在平时设计代码时尽量不要使用虚函数，主要原因
        1.虚指针调用虚函数是在程序执行时进行的，必须通过寻址
        的操作才能找到真正应该调用的函数
        2.由于它会在虚函数表中多占领一块内存空间，浪费空间
    */
    printf("calss A size = %d\nclass B size = %d\n",(int)sizeof(DAY38E::A),(int)sizeof(DAY38E::B));
    #endif
    #ifdef T10
    DAY38F::B b;
    #endif




    cout<<"hello..\n";
    return 0;
}
void A::disp()
{
    printf("a = %d , b = %d , c = %d , pi = %f\n",a,b,c,pi);
}
void B::disp()
{
    cout<<"B内部:"<<"public--"<<a<<",protected--"<<b<<endl;
}
void C::disp()
{
    cout<<"C内部:"<<"protected--"<<a<<","<<b<<endl;
}
void D::disp()
{
    cout<<"C内部:"<<"private--"<<a<<","<<b<<endl;
}
void __DAY38::C::disp()
{
    cout<<"A::a = "<<A::a<<" , "
    "A::b = "<<A::b<<"\nB::a = "<<B::a<<"B::b = "
    <<B::b<<endl;
}
void DAY38A::D::disp()
{
    //产生二义性的解决方式1
    cout<<"B::a = "<<B::a<<"C::a = "<<C::a<<endl;
    cout<<"B::b = "<<B::b<<"C::b = "<<C::b<<endl;
    //解决方式2
    /*
        1.对象B,c虚继承A，使得这个公共基类成为虚基类
        2.在对象D中产生一个公共对象成员变量
    */
}
void DAY38B::A::disp()
{
    cout<<"I am Father!\n";
}
void DAY38B::B::disp()
{
    cout<<"I am Son!\n";
}
void DAY38C::Result(Herio *herio,Fighter *fighter)
{
    if(herio->Power() > fighter->Power())
    {
        printf("Herio Win!\n");
    }
    else
    {
        printf("Herio Failed!\n");
    }
}