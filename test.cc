//用于C++简化编译
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
int main(int argc,char* argv[])
{
    stringstream ss;
    ss<<argv[1];
    string name,_name;
    ss>>_name;
    name = "g++ " + _name;
    ss.clear(); 
    for(int i = 0;i < strlen(argv[1]);++i){
        if(argv[1][i] == '.')
        break;
       ss<<argv[1][i];
     }
     name += " -o ";
     ss>>_name;
     ss.clear();
     name += _name;
     char command[50]={' '};
     for(int i = 0;i < name.size();++i)
     command[i] = name[i];
     system(command);
    return 0;
}