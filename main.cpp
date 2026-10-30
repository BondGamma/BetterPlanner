// #include <functional>  // for function

// // #include <iostream>  // for basic_ostream::operator<<, operator<<, endl, basic_ostream, basic_ostream<>::__ostream_type, cout, ostream
// // #include <string>    // for string, basic_string, allocator
// // #include <vector>    // for vector
 
// #include "ftxui/component/app.hpp"                // for App
// #include "ftxui/component/captured_mouse.hpp"     // for ftxui
// #include "ftxui/component/component.hpp"          // for Menu
// #include "ftxui/component/component_options.hpp"  // for MenuOption

#include <iostream>
#include "project.hpp"

enum class AppControl {ShutDown, Running};


void createProject(std::vector<std::unique_ptr<Project>>& projects){
    std::string projectName;
    std::cout << "What would you like to name your project?: ";
    std::getline(std::cin, projectName);
    projects.push_back(std::make_unique<Project>(projectName));
}

AppControl handleUserInput(){

}


int main()
{
    std::vector<std::unique_ptr<Project>> projects;
    AppControl appState = AppControl::Running;


    while (appState != AppControl::ShutDown){
        if ()
        createProject(projects);
    }



    return 0;
}