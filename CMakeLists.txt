cmake_minimum_required(VERSION 3.28)
project(08_team_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(08_team_project main.cpp
        utils.h
        utils.cpp
        BinaryTreeNode.h
        BinaryTree.cpp
        BinaryTree.h
        BinarySearchTree.cpp
        BinarySearchTree.h
        HashNode.h
        HashTable.h
        CPU.h
        Stack.cpp
        Stack.h
        StackNode.cpp
        StackNode.h
        fio.h
        fio.cpp
)
