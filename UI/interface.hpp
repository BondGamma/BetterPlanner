#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "../project.hpp"
#include <ncurses.h>

class Interface{
    private:   
        int m_yMax, m_xMax;
        int m_startx, m_starty, m_width, m_height;
        WINDOW* m_win;

    public:
        std::vector<Project> m_projects;
        std::string m_projectName;   
        int m_selected = 0;     


        Interface(std::string_view projectName)
            :   m_projectName(projectName), 
                m_win(nullptr)
        {
            initscr();
            clear();
            noecho();
            cbreak();
            m_height = 25;
            m_width = 610;
            m_starty = (LINES - m_height) / 2;
            m_startx = (COLS - m_width) / 2;
            m_win = newwin(m_height, m_width, m_starty, m_startx);
            getmaxyx(stdscr, m_yMax, m_xMax);
            refresh();
        }
        
        Interface()
            : m_projectName("NoProjectName"),
                m_win(nullptr)
        {
            initscr();
            clear();
            noecho();
            cbreak();
            m_height = 25;
            m_width = 60;
            m_starty = (LINES - m_height) / 2;
            m_startx = (COLS - m_width) / 2;
            m_win = newwin(m_height, m_width, m_starty, m_startx);
            getmaxyx(stdscr, m_yMax, m_xMax);
            refresh();
        }
        

        ~Interface()
        { 
            if (m_win){
                delwin(m_win);
            }
            endwin();
        }
        //To implement
        void run();

        void draw();
        int handleInput(int ch);
        int selected() const { return m_selected; }

        void addProject(std::string_view projectName);
        bool deleteProject(int index);

        Project& getProject(int index);
        std::vector<Project>& getProjectsList();
};


void Interface::addProject(std::string_view projectName){
    m_projects.emplace_back(projectName);
}

bool Interface::deleteProject(int index){
    if (index < 0 || index >= m_projects.size()){
        return false;
    }
    m_projects.erase(m_projects.begin() + index);
    return true;
}

Project& Interface::getProject(int index){
    return m_projects[index];
}

std::vector<Project>& Interface::getProjectsList(){
    return m_projects;
}

void Interface::draw(){
    werase(m_win);
    box(m_win,0,0);
    wrefresh(m_win);
    int y = 1;
    for (int i = 0; i < static_cast<int>(m_projects.size()); ++i){
        if (i==m_selected){
            wattron(m_win, A_REVERSE);
        }
        mvwprintw(m_win, y + i, 1, "%s", m_projects[i].getProjectName().c_str());
        if (i == m_selected){
            wattroff(m_win, A_REVERSE);
        }
        wrefresh(m_win);
    }
}

int Interface::handleInput(int ch){
    switch (ch)
    {
    case KEY_UP:
        if (m_selected > 0){
            --m_selected;
            break;
        }
    case KEY_DOWN:
        if (m_selected + 1 < static_cast<int>(m_projects.size())){
            ++m_selected;
            break;
        }
    case '\n':

    case KEY_ENTER:
        return m_selected;
    }
    return -1;
}

void Interface::run() {
    keypad(m_win, TRUE);
    bool running = true;
    while(running){
        draw();
        int ch = wgetch(m_win);
        int result = handleInput(ch);
        if (result == static_cast<int>(m_projects.size()) - 1){
            running = false;
        }
    }
}


#endif