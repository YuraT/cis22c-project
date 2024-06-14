#ifndef INC_08_TEAM_PROJECT_BINARYTREE_H
#define INC_08_TEAM_PROJECT_BINARYTREE_H

#include "BinaryTreeNode.h"

template<typename T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;
    int size;

public:
    BinaryTree() : root(nullptr), size(0) {};

    ~BinaryTree() { throw std::logic_error("Not implemented: ~BinaryTree()"); };

    [[nodiscard]] bool isEmpty() const { return size == 0; };

    [[nodiscard]] int getSize() const { return size; };

    void clear() { throw std::logic_error("Not implemented: BinaryTree.clear()"); };

    void preOrder(void visit(const T &)) { throw std::logic_error("Not implemented: BinaryTree.preOrder()"); };

    void postOrder(void visit(const T &)) { throw std::logic_error("Not implemented: BinaryTree.postOrder()"); };

    void inOrder(void visit(const T &)) { throw std::logic_error("Not implemented: BinaryTree.inOrder()"); };

    void printIndented(void visit(const T &, int)) { throw std::logic_error("Not implemented: BinaryTree.printIndented()"); };

};

#endif //INC_08_TEAM_PROJECT_BINARYTREE_H
