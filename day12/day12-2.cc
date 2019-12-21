#include <iostream>
#include <unistd.h>
#include <string.h>
//#define One
#define Two
int main(int argc,char* argv[])
{
    #ifdef One
    if(argc == 1)
    exit(0);
    char* arglist[argc];
    arglist[0] = argv[0];
    for(int i = 1;i < argc;++i)
        arglist[i] = argv[i+1];
    execvp(argv[1],arglist);
    #endif
    #ifdef Two
    char*  arglist[3];
    arglist[0] = (char*)"ls";
    arglist[1] = (char*)"-l";
    arglist[2] = NULL;
    execvp(arglist[0],arglist);
    #endif
    return 0;
}