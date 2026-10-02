#include <iostream>
#include "UI/interface.hpp"

int main(){

    Interface* interface = new Interface();
    interface->addProject("Test1");
    interface->addProject("Test2");
    interface->addProject("Test3");
    interface->addProject("Test4");
    interface->addProject("Test5");
    interface->addProject("Test6");
    
    interface->run();
    
    return 0;
}