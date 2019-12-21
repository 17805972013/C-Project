#include "day37.h"
int main(int argc,char* argv[])
{
    A c;
    A a;
    A b(a);
    cout<<A::pi<<endl;
    A &d = b+a;
    cout<<"d.a = "<<d.a<<" , "<<"d.b = "<<d.b<<endl;
    cout<<a[0]<<endl;
   // ++a;
   // cout<<"a.a = "<<a.a<<" , "<<"a.b = "<<a.b<<endl;
    printf("hello...\n");
    return 0;
}
void A::disp()
{
    printf("a = %d , b = %d , p = %s\n",a,b,p);
}
double A::pi = 3.14;