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

    ~Stack() { throw std::logic_error("Not implemented: ~Stack()"); };

    [[nodiscard]] bool isEmpty() const { return count == 0; };

    [[nodiscard]] int getCount() const { return count; };

    void push(const T &data) { throw std::logic_error("Not implemented: Stack.push()"); };

    T pop() { throw std::logic_error("Not implemented: Stack.pop()"); };

    T peek() { throw std::logic_error("Not implemented: Stack.peek()"); };
};

#endif //INC_08_TEAM_PROJECT_STACK_H
