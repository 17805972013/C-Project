#include "day55.h"
int main(int argc,char* argv[])
{
    FILE* fp = fopen("Sqdata.txt","r");
    int t,t1;
    Node p[240];
    while(fscanf(fp,"%d %d",&t,&t1) > 0)
    {
        for(int i = 65;i < 240;++i)
        if(t == i)
        {
           ++p[i].cnt;
        }
    }
    fclose(fp);
    FILE* _fp = fopen("Result.txt","a+");
    for(int i = 65;i < 240;++i){
        fprintf(_fp,"%d,%d\n",i,p[i].cnt);
    }
    printf("hello..\n");
    return 0;
}