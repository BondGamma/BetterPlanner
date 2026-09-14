#include <vector>
#include"planner.hpp"

class Project
{
    private:
        std::vector<Planner> m_plannersList;
        std::string m_projectName;
        int m_length;

    public:
        Project(std::string_view projectName)
            : m_projectName(projectName), m_plannersList(), m_length(-1)
        {
        }

        Project()
            :m_projectName("NoNAME"), m_plannersList(), m_length(-1)
        {            
        }
        
        ~Project()
        {
        }

        std::string& getProjectName();
        Planner& getPlanner(int index);
        int& getLength();

        void printProjectName();
        void printPlanners() const;

        void addPlanner(std::string_view plannnerName);
        bool deletePlanner(int index);

};

void Project::addPlanner(std::string_view plannerName){
    m_plannersList.emplace_back(plannerName);
    ++m_length;
}

bool Project::deletePlanner(int index){
    if (index < 0 || index >= m_length){
        return false;
    } 
    m_plannersList.erase(m_plannersList.begin() + index);
    return true;
}

void Project::printPlanners() const{
    for (int i = 0; i < m_length; i++){
        m_plannersList[i].printList();
    }
}

std::string& Project::getProjectName(){
    return m_projectName;
}

void Project::printProjectName() {
    std::cout << getProjectName();
}
 
Planner& Project::getPlanner(int index) {
    return m_plannersList[index];
}