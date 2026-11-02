// #include <functional>  // for function

#include <iostream>
#include <memory>  // for allocator, shared_ptr, __shared_ptr_access
#include <string>  // for operator+, string, char_traits, basic_string
 
#include "ftxui/component/app.hpp"             // for App
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Button, Vertical, Renderer
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/dom/elements.hpp"  // for separator, text, Element, operator|, vbox, border
#include "project.hpp"

enum class AppControl {ShutDown, Running};

struct ProjectData
{
    std::vector<std::unique_ptr<Project>> projects;
    std::vector<std::string> projectNames;    
};


void createProject(ProjectData& projectData){
    std::string projectName;
    std::cout << "What would you like to name your project? :";
    std::getline(std::cin, projectName);
    if (projectName == ""){
        projectData.projectNames.push_back("NoName");
    } else {
        projectData.projectNames.push_back(projectName);
    }
    projectData.projects.push_back(std::make_unique<Project>(projectName));
    
}

void printProjects(ProjectData& projectData){
    for (auto& i : projectData.projectNames){
        std::cout << i << std::endl;
    }
}

void handleUserInput(AppControl& appState,ProjectData& projectData){
    std::string userInput;
    std::cout << ":";
    std::getline(std::cin, userInput);
    if (userInput == "stop"){
        appState = AppControl::ShutDown;
    } else if (userInput == "names") {
        printProjects(projectData);
    } else {
        appState = AppControl::Running;
    }
}

void deleteProject(ProjectData& projectData){

}



int main()
{
    ProjectData projectData;
    auto appState = AppControl::Running;


    while (appState != AppControl::ShutDown){
        createProject(projectData);
        handleUserInput(appState, projectData);
    }



    return 0;
}