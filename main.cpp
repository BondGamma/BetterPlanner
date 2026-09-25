#include <iostream>
#include "interface.hpp"

int main(){

    Project* newProject = new Project();
    newProject->printProjectName();
    std::cout << "\n";
    newProject->addPlanner("Test 1");
    newProject->addPlanner("Test 2");
    newProject->addPlanner("Test 3");
    newProject->printPlanners();
    std::cout << '\n';
    newProject->getPlanner(0).append("Drink Water");
    newProject->getPlanner(0).append("Do Homework");
    newProject->getPlanner(0).append("Something else");
    newProject->getPlanner(0).append("Study");
    newProject->getPlanner(1).append("A");
    newProject->getPlanner(1).append("B");
    newProject->getPlanner(1).append("C");
    newProject->getPlanner(1).append("D");
    newProject->printAllTasks();
    
    // Project newProject("Gangsta");
    // // newProject.printProjectName();
    // newProject.addPlanner("1");
    // newProject.getPlanner(0).printPlannerName();
    // std::cout << '\n';
    // newProject.addPlanner("2");
    // newProject.getPlanner(1).printPlannerName();
    // std::cout << '\n';
    // newProject.deletePlanner(0);
    // newProject.getPlanner(0).printPlannerName();



    // Planner& x = newProject.getPlanner(0);
    // Planner& y = newProject.getPlanner(1);

    // x.append("A");
    // x.append("B");
    // x.append("C");

    // y.append("X");
    // y.append("Y");
    // y.append("Z");

    // std::cout << newProject.getProjectName();

    // Planner class testing
    // Planner* newPlanner = new Planner("Hello");
    // Planner* testingEmpty = new Planner();
    // newPlanner->append("My name is");
    // newPlanner->append("Artem");
    // newPlanner->append("I like this");
    // newPlanner->append("APA");
    // newPlanner->printList();
    // std::cerr << '\n';
    // newPlanner->swapTasks(1,3);     
    // newPlanner->printList();



    // NCURSES Testing
    // initscr();

    // noecho();
    // refresh();

    // WINDOW* win1 = newwin(5, 76, 1, 2);
    // WINDOW* win2 = newwin(15, 46, 6, 18);

    // wattron(win1, A_STANDOUT);
    // wmove(win1, 2, 22);
    // wprintw(win1, "ncurses"); 
    // wprintw(win1, " Environment Interrogator"); 
    // wattroff(win1, A_STANDOUT);
    // // box(win1, 0, 0);
    // wrefresh(win1);
    // refresh();
    // getch();
    // endwin();


    return 0;
}