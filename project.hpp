#include <vector>
#include"planner.hpp"

class Project
{
    private:
        std::vector<Planner> m_plannersList;
        std::string m_projectName;

    public:
        Project(std::string_view projectName)
            : m_projectName(projectName), m_plannersList()
        {
        }

        Project()
            :m_projectName("NoNAME"), m_plannersList()
        {            
        }
        
        ~Project()
        {
        }

        std::string& getProjectName();
        Planner& getPlanner(int index);
        int& getLength();

        void printAllTasks();
        void printProjectName();
        void printPlanners();

        void addPlanner(std::string_view plannnerName);
        bool deletePlanner(int index);

};

void Project::addPlanner(std::string_view plannerName){
    m_plannersList.emplace_back(plannerName);
}

bool Project::deletePlanner(int index){
    if (index < 0 || index >= m_plannersList.size()){
        return false;
    } 
    m_plannersList.erase(m_plannersList.begin() + index);
    return true;
}

void Project::printPlanners(){
    for (int i = 0; i <= m_plannersList.size(); i++){
        m_plannersList[i].printPlannerName();
        std::cout << '\n';
    }
}
void Project::printAllTasks(){
    for (int i = 0; i <= m_plannersList.size(); i++){
        m_plannersList[i].printTasks();
        std::cout << '\n';
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