#ifndef _DAY32_
#include <iostream>
using namespace std;
namespace veins
{
    double pi = 3.1415926;
    void disp()
    {
        printf("hello namespace!\n");
    }
}
namespace B
{
    namespace C
    {
        struct Teacher
        {
            int age;
            double weight;
        };
    }
}
using namespace veins;
B::C::Teacher t1;//命名空间的第二种用法

namespace Arbitrary_door
{
    typedef struct Person   
    { 
        char* college;
        char* name;
        char* gender;
        unsigned int age;
        char* constellation;
        char* hobby;
        void Introduction()
        {
            printf("college:%s\n",college);
            printf("name:%s\n",name);
            printf("gender:%s\n",gender);
            printf("age:%d\n",age);
            printf("constellatuion:%s\n",constellation);
            printf("hobby:%s\n",hobby);

        }
    }person;
}
Arbitrary_door::person p;

#endif
