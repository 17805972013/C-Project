#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stack>
//#define Cpwd//方式1
#define Mypwd//方式2
typedef std::stack<std::string> Path;
Path current_dir_path;//用于存取目录
void Attach(const char* pathname,long  _inode);
int main(int argc,char* argv[])
{
    #ifdef Cpwd
    char _dirname[50];
    sprintf(_dirname,"%s",get_current_dir_name());
    std::cout<<_dirname<<std::endl;
    #endif
    #ifdef Mypwd
    std::string path1,path2;
    path1 = ".";
    path2 = "..";
    int result1,result2;
    struct stat _dir;
    struct stat __dir;
    result1 = stat(".",&_dir);
    result2 = stat("..",&__dir);
    while(_dir.st_ino != __dir.st_ino){
        Attach(path2.c_str(),_dir.st_ino);
        path1 = "../"+path1;
        path2 = "../"+path2;
        stat(path1.c_str(),&_dir);
        stat(path2.c_str(),&__dir);
    }
    while(!current_dir_path.empty()){
        std::cout<<current_dir_path.top();
        current_dir_path.pop();
    }
    std::cout<<std::endl;
    #endif
    return 0;
}
void Attach(const char* pathname,long _inode)
{
    char temp[300];
    DIR *_dirname = opendir(pathname);
    struct dirent *__dirname;
    while(__dirname =  readdir(_dirname)){
            if(__dirname->d_ino == _inode){
                sprintf(temp,"/%s",__dirname->d_name);
                current_dir_path.push(temp);
                break;
            }
    }
}