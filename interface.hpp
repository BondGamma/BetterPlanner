#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "project.hpp"
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
            getmaxyx(stdscr, m_yMax, m_xMax);
            m_height = std::min(25, m_yMax);
            m_width = std::min(60, m_xMax);
            m_starty = (LINES - m_height) / 2;
            m_startx = (COLS - m_width) / 2;
            m_win = newwin(m_height, m_width, m_starty, m_startx);
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
            getmaxyx(stdscr, m_yMax, m_xMax);
            m_height = std::min(25, m_yMax);
            m_width = std::min(60, m_xMax);
            m_starty = (LINES - m_height) / 2;
            m_startx = (COLS - m_width) / 2;
            m_win = newwin(m_height, m_width, m_starty, m_startx);
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

        void drawProjects();

        template <typename T> 
        int handleInputOptions(int ch, std::vector<T>& container);

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

void Interface::drawProjects(){
    werase(m_win);
    box(m_win,0,0);
    wrefresh(m_win);
    if (m_projects.size() != 0){
        int y = 1;
        for (int i = 0; i < static_cast<int>(m_projects.size()); ++i){
            if (i==m_selected){
                wattron(m_win, A_REVERSE);
            }
            mvwprintw(m_win, y + i, 1, "%s", m_projects[i].getProjectName().c_str());
            
            if (i == m_selected){
                wattroff(m_win, A_REVERSE);
            }
    
            wmove(m_win, y + m_selected, 1);
            wrefresh(m_win);
        }
    }
}

void Interface::run() {
    keypad(m_win, TRUE);
    bool running = true;
    while(running){
        drawProjects();
        int ch = wgetch(m_win);
        int result = handleInputOptions(ch, m_projects);
        if (result == -2){
            running = false;
            keypad(m_win, FALSE);
        }
    }
}


#endif