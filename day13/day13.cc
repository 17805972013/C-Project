#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#define MAIN
#define Test
#define oops(m,x){perror(m);exit(x);}
void fatal(const char* mess);
void be_dc(int in[2],int out[2]);
void be_bc(int todc[2],int fromdc[2]);
int main(int argc,char* argv[])
{
     #ifdef MAIN
    int pid,todc[2],fromdc[2];/*equipment*/
    /*make two pipes*/
    if(pipe(todc) == -1 || pipe(fromdc) == -1)
    oops("pipe failed",1);
    /*get a process for user interface*/
    if((pid == fork()) == -1)
    oops("cannot fork",2);
    if(pid == 0)
    be_dc(todc,fromdc);
    else
    {
        be_bc(todc,fromdc);
        wait(NULL);
    }
    #endif
    #ifdef Test
    int fd;
    char line[50];
    fd = open("test.txt",O_RDONLY);
    FILE *fp = fdopen(fd,"r");
    fscanf(fp,"%s",line);
    fclose(fp);
    close(fd);
    printf("%s\n",line);
    #endif
    
    return 0;
}
void be_dc(int in[2],int out[2])
{
    /*setup stdin from pipein*/
    if(dup2(out[1],1) == -1)
        oops("dc:cannot redirect stdout",4);
        close(out[1]);
        close(out[0]);
    /*now execl dc with the-option*/
    execlp("dc","dc","-",NULL);
    oops("Cannot run dc",5);
}
void be_bc(int todc[2],int fromdc[2])
{
    int num1,num2;
    char operation[BUFSIZ],message[BUFSIZ];
    FILE *fpout,*fpin;
    /*setup*/
    close(todc[0]);
    close(fromdc[1]);
    fpout = fdopen(todc[1],"w");
    fpin = fdopen(fromdc[0],"r");
    if(fpout == NULL || fpin == NULL)
    fatal("Error convering pipes to streams");
    /*main loop*/
    while(printf("tinybc:"),fgets(message,BUFSIZ,stdin) != NULL)
    {
        /*parse input*/
        if(sscanf(message,"%d%[- + * / ^]%d",&num1,operation,&num2) != 3){
            printf("syntax error\n");
            continue;
        }
        if(fprintf(fpout,"%d\n%d\n%c\np\n",num1,num2,*operation) == EOF)
        fatal("Error writing");
        fflush(fpout);
        if(fgets(message,BUFSIZ,fpin) == NULL)
        break;
        printf("%d %c % d = %s",num1,*operation,num2,message);
    }
    fclose(fpout);/*close pipe*/
    fclose(fpin);/*dc will see EOF*/
}
void fatal(const char *mess)
{
    fprintf(stderr,"Error:%s\n",mess);
    exit(1);
}