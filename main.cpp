#include <iostream>
#include "UI/interface.hpp"

int main(){
    
    Interface* interface = new Interface();
    interface->addProject("A");
    interface->addProject("B");
    interface->addProject("C");
    interface->addProject("D");
    interface->addProject("E");
    interface->run();
    delete interface;

    return 0;
}