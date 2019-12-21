/*
--ls功能的实现--
author:QingweiZeng
*/
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stack>
#include <sstream>
using namespace std;
void do_ls(const char *filename);
void see_ls(string pathname);
void ten_transform_two(int num);//十进制转二进制
int main(int argc,char* argv[])
{
    if(argc == 1)//显示当前目录信息
    {
        do_ls(".");

    }
    else//显示指定目录下的信息
    {
        while(--argc){
        cout<<*++argv<<endl;
        do_ls(*argv);
     }
    }
     return 0;
}
void do_ls(const char* filename)
{
    string pathname;
    DIR *_dir = opendir(filename);
    struct dirent* p;
    while((p = readdir(_dir)) != NULL){
        pathname = filename;
        pathname += "/";
        pathname += p->d_name;
        cout<<"文件名："<<p->d_name<<"  ";
        see_ls(pathname);
    }
}
void see_ls(string pathname)
{
    int result;
    struct stat statbuf;
    result = stat(pathname.c_str(),&statbuf);
    if(result == -1)
    cout<<"读取失败!\n";
    else
    cout<<"文件大小:"<<statbuf.st_size<<"  ";
    cout<<"权限:";
    ten_transform_two(statbuf.st_mode);
}
void ten_transform_two(int num)
{
    char str[12];
    str[0] = 'd';
    str[1] = 'c';
    str[2] = 'b';
    str[3] = 'r';
    str[4] = 'w';
    str[5] = 'x'; 
    str[6] = 'r';
    str[7] = 'w';
    str[8] = 'x'; 
    str[9] = 'r';
    str[10] = 'w';
    str[11] = 'x'; 
    stack<int> _buf;
    while(num){
        _buf.push(num%2);
        num /=2;
    }
    while(_buf.size() < 16){
        _buf.push(0);
    }
    num = 0;
    while(!_buf.empty()){
        if(num < 4){
         _buf.pop();
         ++num;
         continue;
        }
        if(str[num-4]*_buf.top() == 0)
        cout<<"-";
        else
        cout<<(char)(str[num-4] * _buf.top());
        ++num;
        _buf.pop();
    }
    cout<<endl;
}