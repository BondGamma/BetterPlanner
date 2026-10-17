#include <iostream>
#include "interface.hpp"

int main(){
    
    Interface* interface = new Interface();
    // interface->addProject("A");
    interface->run();
    delete interface;

    return 0;
}





/*

1) Select the project
    1) a) if exists then select
    1)  b) if not then create a project
2) left options - right planners with tasks (can change the privacy)
3)









*/