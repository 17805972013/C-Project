#include "day35.h"
int main(int argc,char *argv[])
{
    //浅拷贝问题抛出，例如同样的变量被删除两次
    //执行浅拷贝，把指针变量的值拷贝过去，并没
    //有另外开辟一块内存
    //解决方案：重载=操作符
    A a;
    A b = a;
    A c = a;
    printf("hello...\n");
    return 0;
}
void A::disp()
{
    printf("x1 = %d,x2 = %d\n",x1,x2);
}