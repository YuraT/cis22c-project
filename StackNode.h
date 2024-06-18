#ifndef INC_08_TEAM_PROJECT_STACKNODE_H
#define INC_08_TEAM_PROJECT_STACKNODE_H

template<typename T>
class StackNode {
    T data;
    StackNode<T> *next;

    StackNode(const T &data) : data(data), next(nullptr) {}
};


#endif //INC_08_TEAM_PROJECT_STACKNODE_H
