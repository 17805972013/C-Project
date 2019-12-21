#include <iostream>
#include <unistd.h>
int main(int argc,char* argv[])
{
    int result;
    const char* pathname = argv[1];
    ++argv;
    --argc;
    while(--argc)
    {
        result = link(pathname,*++argv);
        if(result == 0)
        std::cout<<"文件创建成功！\n";
        else
        {
            perror("文件创建失败！\n");
        }
    }
    return 0;
}