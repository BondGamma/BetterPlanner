#ifndef PLANNER_HPP
#define PLANNER_HPP

#include "storagehandler.hpp"

template <typename T>
class Planner : public StorageInterface
{
    private:
        std::vector<std::string> m_tasks;
        std::string plannerName;
    public:
        Planner(std::string_view name)
            : plannerName(name){}

        Planner()
            : plannerName("NaaN"){}

        
        std::string& getName(){return plannerName;};
        std::vector<std::string>& getListTasks(){return m_tasks;}
        std::string& getTask(int index);
};

template <typename T>
std::string& Planner<T>::getTask(int index){
    return m_tasks.at(index);
}





#endif PLANNER_HPP