#include "day33.h"
//内敛函数的编译规则
//1.不能出现任何形式的循环语句
//2.不能存在过多的条件判断语句
//3.函数体不能过于庞大
//4.不能对函数体进行取址操作
//5.函数内敛声明必须在调用语句之前
//6.编译器对于内敛函数的限制并不是绝对的，内敛函数相对于
//普通函数的优势只是省去了函数调用时压栈，跳转和返回的开销。
inline void Add(int a,int b)
{
    printf("a+b = %d\n",a+b);
}
//C++默认参数
//默认参数规则，如果默认参数出现，那么右边的都必须有默认参数
int myPrint2(int x=2,int y=3)
{
    printf("%d\n",x);
    return 0;
}
//函数指针概念---给函数取小名,三种形式
int (*fun)(int a,int b);
typedef int (Fun)(int a,int b);
typedef int (*Fun1)(int a,int b);
int main(int argc,char* argv[])
{
    //Add(1,2);
    Fun *l1;
    l1 = myPrint2;
    Fun1 l2;
    l2 = myPrint2;
    cout<<(*l1)(1,2)<<"l1"<<endl;
    cout<<l2(1,2)<<"l2"<<endl;
    myPrint2(1,2);
    fun = myPrint2;
    cout<<fun(1,2)<<endl;
    int a = 1;
    int b = 1;
    //宏替换并展开
    int c = MAX(++a,b);//++a>b?++a:b
    printf("%d\n",c);
    //函数重载概念
    //1.用同一个函数名定义不同的函数
    //2.参数不同，类型不同，参数个数不同，参数顺序不同

    //函数重载可以和函数指针一起用
    printf("hello world!\n");
    return 0;
}