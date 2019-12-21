#ifndef _DAY35_
#define _DAY35_
#include <iostream>
#include <string.h>
using namespace std;
/*构造函数与析构函数*/
class A
{
    public:
    //构造函数列表初始化，支持重载
    A():x1(1),x2(2),p(new char[2]){
        //p = (char*)"h";
        printf("构造函数\n");    
        disp();
    }
    //拷贝构造函数
    A(const A & l){
        printf("拷贝构造函数\n");
    }
    //操作符重载
    A& operator=(const A& l)
    {
        if(p != NULL)
        {
            delete [] p;
            p = NULL;
        }
        p = new char[2];
        strcpy(p,l.p);//将l对象中p的内容拷贝到p中
        return *this;
    }   
    int x1;
    int x2;
    char *p = NULL;
    void disp();
    ~A()//内存的释放
    {
        if(p != NULL)
        {
            delete [] p;
             p = NULL;
        }
       
        cout<<"析构函数\n";
    }
};
#endif