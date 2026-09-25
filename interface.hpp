#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "project.hpp"

class Interface{
    
    std::vector<Project> m_projects;
    int m_length;
    std::string m_projectName;

    public:
        
        Interface(std::string_view projectName)
            : m_projectName(projectName), m_length(-1)
        {
        }
        
        Interface()
            : m_projectName("NoProjectName"), m_length(-1)
        {
        }

        void addProject(std::string_view projectName);
        Project& getProject(int index);

};

void Interface::addProject(std::string_view projectName){
    m_projects.emplace_back(projectName);
    ++m_length;
}

Project& Interface::getProject(int index){
    return m_projects[index];
}

#endif
