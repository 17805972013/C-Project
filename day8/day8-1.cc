#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <ctype.h>
//#define Stty
//#define Ioctl
#define CType
void print_screen_dimensions()
{
    struct winsize wbuf;
    if(ioctl(0,TIOCGWINSZ,&wbuf) != -1){
        printf("%d rows x %d cols\n",wbuf.ws_row,wbuf.ws_col);
        printf("%d wide x %d tall\n",wbuf.ws_xpixel,wbuf.ws_ypixel);
    }
}
int main(int argc,char* argv[])
{
    #ifdef Stty
    if(argc == 1)
    {
        perror("输入有误，请重新输入！\n");
        exit(0);
    }
    termios p;
    int rv;
    rv = tcgetattr(0,&p);
    if(rv == -1){
        perror("tcgetattr\n");
        exit(1);
    }
    if(argv[1][0] == 'y')
    {
        p.c_lflag |= ECHO;
    }
    else
    {
        p.c_lflag &= ~ECHO;
    }
    if(tcsetattr(0,TCSANOW,&p) == -1){
        perror("tcsetattr\n");
        exit(2);
    }
    #endif
    #ifdef Ioctl
    print_screen_dimensions();
    #endif
    #ifdef CType
    int c;
    while((c = getchar()) != EOF){
        if(c == 'z')
            c = 'a';
        else if(islower(c))
        c++;
        putchar(c);
    }
    #endif
    return 0;
}