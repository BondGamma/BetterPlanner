#include <vector>
#include"planner.hpp"

class Project
{
    private:
        std::vector<Planner> m_plannersList;
        std::string m_projectName;
        int length;

    public:
        Project(std::string_view projectName)
            : m_projectName(projectName), m_plannersList(), length(-1)
        {
        }

        Project()
            :m_projectName("NoNAME"), m_plannersList(), length(-1)
        {            
        }
        
        ~Project()
        {
        }


        std::string getProjectName() const;
        void printProjectName() const;


        void printPlanners() const;
        void addPlanner(std::string_view plannnerName);
        Planner& getPlanner(int index);


};

void Project::addPlanner(std::string_view plannerName){
    m_plannersList.emplace_back(plannerName);
    ++length;
}

void Project::printPlanners() const{
    for (int i = 0; i < 2; i++){
        m_plannersList[i].printList();
    }
}

std::string Project::getProjectName() const{
    return m_projectName;
}

void Project::printProjectName() const {
    std::cout << getProjectName();
}


// RAW FUNCTION BE CAREFUL 
Planner& Project::getPlanner(int index) {
    return m_plannersList[index];
}
