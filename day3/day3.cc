#include <iostream>
#include <sys/types.h>
#include <utime.h>
#include <time.h>
int main(int argc,char* argv[])
{
    struct utimbuf _modifytime;
    struct tm* _transform1;
    struct tm* _transform2;
    
    int result = utime("/home/zqw/VSCODE/C++project/day1/day1.cc",&_modifytime);
    if(result != -1){
    _transform1 = gmtime(&(_modifytime.actime));
    _transform2 = gmtime(&(_modifytime.modtime));
    char s[80];
    strftime(s, 80, "%Y-%m-%d %H:%M:%S", _transform1);
    char _s[80];
    strftime(_s, 80, "%Y-%m-%d %H:%M:%S", _transform2);
    std::cout<<"接入时间："<<s<<"\n"
    "修改时间："<<_s<<std::endl;
    }
    else
    {
        perror("获取时间失败！\n");
    }
    return 0;
}