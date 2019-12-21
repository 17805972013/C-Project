#include <iostream>
#include <unistd.h>
int main(int argc,char* argv[])
{
    printf("***About to exec ls -l\n");
    execvp("ls",argv);
    printf("***ls is done.bye\n");
    return 0;
}