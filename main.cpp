#include <iostream>
#include "interface.hpp"

int main(){

    Interface* interface = new Interface();
    interface->run();
    // NCURSES Testing
    // initscr();

    // noecho();
    // refresh();

    // WINDOW* win1 = newwin(5, 76, 1, 2);
    // WINDOW* win2 = newwin(15, 46, 6, 18);

    // wattron(win1, A_STANDOUT);
    // wmove(win1, 2, 22);
    // wprintw(win1, "ncurses"); 
    // wprintw(win1, " Environment Interrogator"); 
    // wattroff(win1, A_STANDOUT);
    // // box(win1, 0, 0);
    // wrefresh(win1);
    // refresh();
    // getch();
    // endwin();


    return 0;
}