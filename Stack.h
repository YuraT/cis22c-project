/*
Name: Stack
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Implement a generic stack data structure
Input: Template parameter T for the type of elements stored in the stack
Output: N/A
Procedure: Uses a linked list of StackNodes to store elements in a Last-In-First-Out (LIFO) order
*/

/*
Name: push
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Add an element to the top of the stack
Input: Element of type T to be added
Output: None
Procedure: Creates a new StackNode with the input data and adds it to the top of the stack
*/

/*
Name: pop
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Remove and return the top element from the stack
Input: None
Output: Element of type T that was at the top of the stack
Procedure: Removes the top StackNode, returns its data, and updates the stack accordingly
*/

/*
Name: peek
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Return the top element of the stack without removing it
Input: None
Output: Element of type T that is at the top of the stack
Procedure: Returns the data of the top StackNode without modifying the stack
*/

/*
Name: isEmpty
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Check if the stack is empty
Input: None
Output: Boolean indicating whether the stack is empty
Procedure: Returns true if the stack contains no elements, false otherwise
*/

/*
Name: getCount
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Get the number of elements in the stack
Input: None
Output: Integer representing the number of elements in the stack
Procedure: Returns the count of elements currently in the stack
*/

#ifndef INC_08_TEAM_PROJECT_STACK_H
#define INC_08_TEAM_PROJECT_STACK_H

#include <stdexcept>
#include "StackNode.h"

template<typename T>
class Stack {
private:
    StackNode<T> *top;
    int count;

public:
    Stack() : top(nullptr), count(0) {};

    // Destructor
    ~Stack();

    // Check if the stack is empty
    [[nodiscard]] bool isEmpty() const { return count == 0; };

    // Get the number of elements in the stack
    [[nodiscard]] int getCount() const { return count; };

    // Push an element onto the stack
    void push(const T &data);

    // Pop the top element from the stack
    T pop();

    // Get the top element of the stack without removing it
    T peek();
};

template<typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T &data) {
    auto *newNode = new StackNode<T>(data);
    newNode->next = top;
    top = newNode;
    count++;
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    T data = top->data;
    StackNode<T> *temp = top;
    top = top->next;
    delete temp;
    count--;
    return data;
}

template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot peek.");
    }
    return top->data;
}

#endif //INC_08_TEAM_PROJECT_STACK_H
