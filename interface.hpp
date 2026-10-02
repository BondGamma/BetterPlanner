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

}


#endif