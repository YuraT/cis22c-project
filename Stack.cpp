#include "Stack.h"

// Destructor
template<typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Push an element onto the stack
template<typename T>
void Stack<T>::push(const T &data) {
    auto *newNode = new StackNode<T>(data);
    newNode->next = top;
    top = newNode;
    count++;
}

// Pop the top element from the stack
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

// Get the top element of the stack without removing it
template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot peek.");
    }
    return top->data;
}

// Get the number of elements in the stack
template<typename T>
int Stack<T>::getCount() const {
    return count;
}

// Check if the stack is empty
template<typename T>
bool Stack<T>::isEmpty() const {
    return count == 0;
}

// Explicit instantiation of the template class for the desired type(s)
template class Stack<CPU>;