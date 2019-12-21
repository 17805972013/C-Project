#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
int main(int argc,char* argv[])
{
    void handleMessage(int);
    initscr();
    clear();
    for(int i = 0;i < LINES;++i){
        clear();
       // sleep(1);
        alarm(2);
        signal(SIGALRM,handleMessage);
        pause();
        move(i,i+1);
        if(i%2 == 1)
        standout();
        addstr("hello");
        if(i%2 == 1)
        standend();
        refresh();
    }
    refresh();
    getch();//判断是否有按键按下,不回显函数
    endwin();
    return 0;
}
void handleMessage(int)
{
    printf("闹钟响了！\n");
}