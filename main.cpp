#include <iostream>
#include "interface.hpp"

int main(){



    Interface* test = new Interface();

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
    // newPlanner->swapTasks(0,4);
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
