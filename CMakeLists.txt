cmake_minimum_required(VERSION 4.4)
project(planner)

add_executable(planner main.cpp)
target_link_libraries(planner ncurses menu)
