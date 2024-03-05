cmake_minimum_required(VERSION 3.27)
project(BST)

set(CMAKE_CXX_STANDARD 17)

add_executable(BST main.cpp
        BST.cpp
        BST.h
        Node.cpp
        Node.h
        analysis.cpp
        analysis.h)
