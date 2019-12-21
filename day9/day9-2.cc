#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10
//#define ACTION
#define SLeep
int main(int argc ,char *argv[])
{
    #ifdef ACTION
    char message[6] = "hello";
    char blank[6] = "     ";
    int dir = 1;
    int pos = LEFTEDGE;
    initscr();//初始化
    clear();//清除屏幕
    while(1){
        move(ROW,pos);
        addstr(message);
        move(LINES-1,COLS-1);
        refresh();
        sleep(1);
        move(ROW,pos);
        addstr(blank);
        pos += dir;
        if(pos >= RIGHTEDGE)
             dir = -1;
        if(pos <= LEFTEDGE)
             dir = +1;
    }
    #endif
    #ifdef SLeep
    void wakeup(int);
    printf("about to sleep for 4 seconds\n");
    alarm(4);//闹钟
    signal(SIGALRM,wakeup);
    pause();
    printf("Morning so soon?\n");
    pause();//可用来调试
    #endif
    return 0;
}
void wakeup(int signum)
{
    #ifndef SHHHH
    printf("Alarm received from kernel!\n");
    #endif

}