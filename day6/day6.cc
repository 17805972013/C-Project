#include <iostream>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int result;
    while(--argc){
        result = unlink(*++argv);
        if(result == 0)
        std::cout<<"文件删除成功"<<std::endl;
        else
        {
            perror("文件删除失败！\n");
        }
    }
    return 0;
}