/*文件的建立以及改变权限*/
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
void do_create(const char* pathname);
int main(int argc,char* argv[])
{
    if(argc == 1)
    {
        do_create(".");
    }
    else
        while(--argc)
            do_create(*++argv);
    return 0;
}
void do_create(const char* pathname)
{
    string _pathname = pathname;
    int result = creat(_pathname.c_str(),0744);
    if(result == -1)
    {
        perror("创建文件失败！\n");
        return;
    }
    cout<<"文件创建成功！\n";
}