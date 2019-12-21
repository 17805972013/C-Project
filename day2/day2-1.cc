/*
---改变权限---
<--author:by QingweiZeng
*/
#include <iostream>
#include <sstream>
#include <sys/stat.h>
int eight_transform_ten(int _num);//八进制转十进制
int main(int argc,char* argv[])
{
    std::stringstream ss;
    int temp;
    if(argc == 1)
    perror("输入权限！\n");
    else
    {
    /*处理argv[1]*/
     ss<<argv[1];//字符转数字
     ss>>temp;
     ss.clear();
     temp = eight_transform_ten(temp); 
    chmod(argv[2],temp);  
    std::cout<<temp<<std::endl;
    }
    return 0;
}
int eight_transform_ten(int _num)
{
    int num = 0;
    int temp;
    int cout = 1;
    while(_num)
    {
        temp = _num%10;
        _num /= 10;
        num += temp*cout;
        cout *= 8;
    }
    return num;
}
