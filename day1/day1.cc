#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
using namespace std;
int main(int argc,char* argv[])
{
    int num;
    struct stat *statbuf = new struct stat;
    num = stat("/usr/bin",statbuf);
    if(num == -1){
    perror("打开失败！\n");
        return -1;
    }
    cout<<"用户ID："<<statbuf->st_uid<<"文件大小："<<statbuf->st_size<<endl;
    delete [] statbuf;
    statbuf = NULL;
    struct passwd *p = getpwuid(0);
    cout<<p->pw_name<<endl;
    return 0;
}