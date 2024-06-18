cmake_minimum_required(VERSION 3.28)
project(08_team_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(08_team_project main.cpp
        utils.h
        utils.cpp
        BinaryTreeNode.h
        BinaryTree.h
        BinarySearchTree.h
        HashNode.h
        HashTable.h
        CPU.h
        CPU.cpp
        Stack.h
        StackNode.h
        fio.h
        fio.cpp
        DisplayManager.h
        UndoManager.h
        SearchManager.h
)
