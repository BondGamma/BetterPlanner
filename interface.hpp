#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "project.hpp"
#include <ncurses.h>

class Interface{
    
    std::vector<Project> m_projects;
    std::string m_projectName;

    public:
        
        Interface(std::string_view projectName)
            : m_projectName(projectName)
        {
        }
        
        Interface()
            : m_projectName("NoProjectName")
        {
        }

        //To implement
        void run();

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

void Interface::run(){
    std::string mesg;
    std::cin >> mesg;
    int row, col;               /* to store the number of rows and *
                                 * the number of columns of the screen */
    initscr();                  /* start the curses mode */
    getmaxyx(stdscr, row, col); /* get the number of rows and columns */
    mvprintw(row / 2, (col - (int) strlen(mesg.data())) / 2, "%s", mesg.data());
    /* print the message at the center of the screen */
    mvprintw(row/2, 0, "This screen has %d rows and %d columns\n", row, col);
    printw("Try resizing your window(if possible) and then run this program again");
    refresh();
    getch();
    endwin();

}

#endif