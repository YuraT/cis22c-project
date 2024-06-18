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
