#include <string>
#include <vector>

#include <curses.h>
#include <menu.h>

namespace {

constexpr int CTRLD = 4;

const std::vector<std::string> choices = {
    "Choice 1",  "Choice 2",  "Choice 3",  "Choice 4",  "Choice 5",
    "Choice 6",  "Choice 7",  "Choice 8",  "Choice 9",  "Choice 10",
    "Choice 11", "Choice 12", "Choice 13", "Choice 14", "Choice 15",
    "Choice 16", "Choice 17", "Choice 18", "Choice 19", "Choice 20",
    "Exit",
};

} // namespace

int main() {
    /* ---- Initialize curses ---- */
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED,  COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);

    /* ---- Build the item array ----
       new_menu() needs a NULL-terminated ITEM* array, so allocate
       size() + 1 and leave the last slot as nullptr. */
    const int n_choices = static_cast<int>(choices.size());
    std::vector<ITEM*> my_items(n_choices + 1, nullptr);
    for (int i = 0; i < n_choices; ++i) {
        my_items[i] = new_item(choices[i].c_str(), choices[i].c_str());
    }

    /* ---- Create the menu ---- */
    MENU* my_menu = new_menu(my_items.data());

    /* Don't show the item descriptions */
    menu_opts_off(my_menu, O_SHOWDESC);

    /* ---- Window that hosts the menu ---- */
    WINDOW* my_menu_win = newwin(10, 70, 4, 4);
    keypad(my_menu_win, TRUE);

    /* Main window and sub window */
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 68, 3, 1));
    set_menu_format(my_menu, 5, 3);   // 5 rows, 3 columns
    set_menu_mark(my_menu, " * ");

    /* ---- Decoration ---- */
    box(my_menu_win, 0, 0);

    attron(COLOR_PAIR(2));
    mvprintw(LINES - 3, 0, "Use PageUp and PageDown to scroll");
    mvprintw(LINES - 2, 0, "Use Arrow Keys to navigate (F1 to Exit)");
    attroff(COLOR_PAIR(2));
    refresh();

    /* ---- Post the menu ---- */
    post_menu(my_menu);
    wrefresh(my_menu_win);

    /* ---- Event loop ---- */
    int c;
    while ((c = wgetch(my_menu_win)) != KEY_F(1)) {
        switch (c) {
            case KEY_DOWN:  menu_driver(my_menu, REQ_DOWN_ITEM); break;
            case KEY_UP:    menu_driver(my_menu, REQ_UP_ITEM);   break;
            case KEY_LEFT:  menu_driver(my_menu, REQ_LEFT_ITEM); break;
            case KEY_RIGHT: menu_driver(my_menu, REQ_RIGHT_ITEM);break;
            case KEY_NPAGE: menu_driver(my_menu, REQ_SCR_DPAGE); break;
            case KEY_PPAGE: menu_driver(my_menu, REQ_SCR_UPAGE); break;
            default: break;
        }
        wrefresh(my_menu_win);
    }

    /* ---- Tear down ---- */
    unpost_menu(my_menu);
    free_menu(my_menu);
    for (ITEM* item : my_items) {
        if (item) free_item(item);
    }
    endwin();

    return 0;
}