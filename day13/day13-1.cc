#include <iostream>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    FILE* fp = popen("who | sort","r");
    char buf[BUFSIZ];
    int i = 0;
    while(fgets(buf,BUFSIZ,fp) != NULL)
    {
        printf("%3d %s",i++,buf);
    }
    pclose(fp);
    return 0;
}