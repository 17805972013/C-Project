#include <iostream>
#include <curses.h>
#include <unistd.h>
//#define HELLO1
#define HELLO2
int main(int argc,char* argv[])
{
    #ifdef HELLO1
    initscr();/*turn on curses*/
              /*send requests*/
    clear();/*clear screen*/
    move(10,20);/*row10,col20*/
    addstr("hello,world");/*add a string*/
    move(LINES-1,0);/*move to LL*/
    refresh();/*update the screen*/
    getch();/*wait for user input*/
    endwin();
    #endif
    #ifdef HELLO2
    initscr();
    for(int i = 0;i < LINES;++i){
        clear();
        move(i,i+i);
        if(i%2 == 1)
        standout();
        addstr("hello,world");
        if(i%2 == 1)
        standend();
        sleep(1);
        refresh();
    }
    getch();
    endwin();
    #endif
    return 0;
}
