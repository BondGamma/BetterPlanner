#ifndef PLAN_HPP
#define PLAN_HPP

#include "task.hpp"
#include <string>

class Planner{
    private:
        Task* head;
        Task* tail;
        int length;
        std::string m_plannerName;

    public:
        Planner(std::string_view task, std::string_view plannerName)
            :   head(new Task(task)),
                m_plannerName(plannerName), 
                tail(head),
                length (1)
        {
        }

        Planner(std::string_view plannerName)
            :   head(nullptr), 
                m_plannerName(plannerName),
                tail(nullptr),
                length (0)
        {   
        }

        Planner()
            :   head(nullptr), 
                m_plannerName("Planner With No Name :c"),
                tail(nullptr),
                length (0)
        {   
        }

        ~Planner(){
            Task* temp = head;
            while(temp != nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        
        void printList() const;
        void printPlannerName() const;

        Task* getHead() const;
        Task* getTail() const;
        Task* getTask(int index);
        std::string getPlannerName() const;

        int getLength() const;
        bool setTask(int index, std::string_view task);
        bool swapTasks(int frstIndex, int secondIndex);
        
        void append(std::string_view task);
        void prepend(std::string_view task);
        bool insert(std::string_view, int index);

        void deleteFirst();
        void deleteLast();
        void deleteTask(int index);

};


std::string Planner::getPlannerName() const {
    return m_plannerName;
}

void Planner::printPlannerName() const {
    std::cout << getPlannerName();
}

Task* Planner::getHead() const {
    return head;
}

Task* Planner::getTail() const {
    return tail;
}

int Planner::getLength() const {
    return length;
}

Task* Planner::getTask(int index){
    if(index < 0 || index >= length){ 
        return nullptr;
    }
    Task* temp = head;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}

void Planner::printList() const {
    Task* temp = head;
    while(temp){
        std::cout << temp->m_value << '\n';
        temp = temp->next;
    }
}

void Planner::append(std::string_view task){
    Task* newTask = new Task(task);
    if(head == nullptr){
        head = newTask;
        tail = newTask;
        length++;
        return;
    }
    tail->next = newTask;
    tail = newTask;
    length++;
}

void Planner::prepend(std::string_view task){
    Task* newTask = new Task(task);
    if(head == nullptr){
        head = newTask;
        tail = newTask;
        length++;
        return;
    }
    Task* temp = head;
    newTask->next = head;
    head = newTask  ;
    length++;
    return;
}

bool Planner::insert(std::string_view task, int index){
    if (index < 0 || index > length){
        return false;
    }
    if (index == 0){
        prepend(task);
        return true;
    }
    if (index == length){
        append(task);
        return true;
    }
    Task* newTask = new Task(task);
    Task* temp = getTask(index - 1);
    newTask->next = temp->next;
    temp = newTask;
    length++;
    return true;
}

void Planner::deleteFirst(){
    if (!head){
        std::cerr << "Nothing to delete!\n";
        return;
    }
    Task* temp = head;
    if (length == 1){
        head = nullptr;
        tail = nullptr;
        return; 
    } else {
        head = head->next;
    }
    delete temp;
    length--;
}

void Planner::deleteLast(){
    if (!head) {
        std::cerr << "Nothing to delete!\n";
        return;
    }
    Task* temp = head;
    Task* pre = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
        return;
    } 
    while (temp->next){
        pre = temp;
        temp = temp->next;
    }
    tail = pre;
    tail->next = nullptr;
    delete temp;
    length--;
}

void Planner::deleteTask(int index) {
    if (!head) {
        std::cerr << "No tasks to delete\n";
        return;
    }
    if (index < 0 || index >= length) {
        std::cerr << "Incorrect task number\n";
        return;
    }
    if (index == 0) {
        return deleteFirst();
    }
    if (index == length - 1) {
        return deleteLast();
    }
    Task* prev = getTask(index - 1);
    Task* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
}

bool Planner::setTask(int index, std::string_view task){
    if (index < 0 || index >= length){
        return false;;
    }
    Task* temp = getTask(index);
    temp->m_value = task;
    return true; 
}


//TODO: CHANGE THE NODES
bool Planner::swapTasks(int firstIndex, int secondIndex){
    if (firstIndex < 0 || secondIndex < 0 || firstIndex >= length || secondIndex >= length){
        std::cerr << "Please choose correct task\n";
        return false; 
    }
    if (firstIndex == secondIndex){
        std::cerr << "Changing the same task? Okay..\n";
        return true;
    }
    Task* first = getTask(firstIndex);
    Task* second = getTask(secondIndex);
    std::swap(first->m_value, second->m_value);
    return true;
}

#endif
