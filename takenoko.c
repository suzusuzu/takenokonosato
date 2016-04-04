#include <ncurses.h>
#include <locale.h>
#include <signal.h>
#include <unistd.h>
#include "takenoko.h"

int gizagiza(void);
void title(int);
void takenoko(int, int);

int main(){
    setlocale(LC_ALL,"");
    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);
    for(int i=COLS-12;i>2;i--){
        erase();
        title(i%2);
        takenoko(i, gizagiza());
        refresh();
        usleep(50000);
    }
    endwin();
    return 0;
}

void takenoko(int x, int y){
    move(LINES/2-3+y, x);
    addstr(TAKENOKO1);
    move(LINES/2-2+y, x);
    addstr(TAKENOKO2);
    move(LINES/2-1+y, x);
    addstr(TAKENOKO3);
    move(LINES/2+y, x);
    addstr(TAKENOKO4);
    move(LINES/2+1+y, x);
    addstr(TAKENOKO5);
    move(LINES/2+2+y, x);
    addstr(TAKENOKO6);
    move(LINES/2+3+y, x);
    addstr(TAKENOKO7);
}

void title(int display_flg){
    if(display_flg)return;
    int x = (COLS-TITLE_COLS_COUNT)/2;
    move(0, x);
    addstr(TITLE1);
    move(1, x);
    addstr(TITLE2);
    move(2, x);
    addstr(TITLE3);
    move(3, x);
    addstr(TITLE4);
    move(4, x);
    addstr(TITLE5);
    move(5, x);
    addstr(TITLE6);
}

int gizagiza(){
    static int x;
    static int incflg;
    if(x>=LINES/5){
        incflg = 0;
    }else if(x<=-LINES/5){
        incflg = 1; }

    if(incflg){
        x++;
    }else{
        x--;
    }
    return x;
}
