cmake_minimum_required(VERSION 3.27)
project(Task-Managment)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task-Managment main.cpp
        LinkedList.tpp
        LinkedList.h
        Node.tpp
        Node.h
        Task.cpp
        Task.h
        PriorityTask.cpp
        PriorityTask.h
        Project.cpp
        Project.h
        tester.cpp
        tester.h

)