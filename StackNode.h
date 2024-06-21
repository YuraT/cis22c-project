/*
Name: StackNode
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Represent a single node in the Stack data structure
Input: Template parameter T for the type of data stored in the node
Output: N/A
Procedure: Stores an element of data and a pointer to the next StackNode in the stack
*/

#ifndef INC_08_TEAM_PROJECT_STACKNODE_H
#define INC_08_TEAM_PROJECT_STACKNODE_H

template<typename T>
class StackNode {
public:
    T data;
    StackNode<T> *next;

    StackNode(const T &data) : data(data), next(nullptr) {}
};

#endif //INC_08_TEAM_PROJECT_STACKNODE_H
