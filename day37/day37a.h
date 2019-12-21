#ifndef _DAY37A_
#define _DAY37A_
#include <iostream>
//组合关系：整体与部分的关系
//1.将其他类作为当前类的成员使用
//2.成员对象与当前类的对象生命、周期相同
//3.成员对象在用法上与普通对象完全一致
//继承关系:父子关系
//1.被继承的类叫父类(或基类),继承后的类叫子类
//2.子类拥有父类的所有属性和行为；
//3.子类对象可以当做父类对象使用
//4.子类中可以添加父类没有的方法和属性
//继承方式：
//public(公有继承):基类的公有成员和保护成员作为派生类的成员时
//它们都保持原有的状态，而基类的私有成员不能访问。
//protected(保护继承):继承父类的公有部分和保护部分
//基类的公有成员和保护成员都作为派生类的私有成员
//private(私有继承):继承父类的公有部分和保护部分
//多继承概念
//多继承就是将多个基类用逗号隔开即可，例如下面所示
//class D : public A,protected B,private C{};
//多继承形式下的构造函数和单继承形式基本相同，只是要在
//派生类中调用多个基类的构造函数。
//D(形参列表):A(实参列表),B(实参列表),C(实参列表){//其他参数}
//命名冲突问题，当两个或多个基类中有同名的成员时，如果直接
//访问该成员，就会产生命名冲突，编译器不知道使用哪个基类的成员
//这个时候需要在成员名字前面加上类名::disp(),以显式地指明
//使用哪个类的成员，消除二义性。
using namespace std;
class A
{
    public:
    int a;
    private:
    int b;
    protected:
    int c;
};
class B : protected A
{
    public:
    void disp(){
       cout<<a<<"---"<<c<<endl;
    }
    protected:
    /*A类的成员有
        a,b
    */
    private:
    /*A类的成员有*/

};
class C : public A
{
    public:
    /*A类的成员有
     a
    */
    void disp(){
        cout<<a<<"---"<<c<<endl;
    }
    protected:
    /*A类的成员有
    b
    
    */

    private:

};
class D : private A
{
    public:
    void disp(){
        cout<<a<<"---"<<c<<endl;
    }
    protected:

    private:
    /*A类的成员有
        a,b
    
    */

};

#endif