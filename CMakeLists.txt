cmake_minimum_required(VERSION 3.26)
project(CSC402Project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSC402Project2 main.cpp
        Employee.cpp
        Employee.h
        myQueue.cpp
        myQueue.h
        myStack.cpp
        myStack.h)
