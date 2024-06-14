#ifndef INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H
#define INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H

#include "BinaryTree.h"

template<typename T>
class BinarySearchTree: public BinaryTree<T> {
private:

public:
    BinarySearchTree() : BinaryTree<T>() {};

    ~BinarySearchTree() { throw std::logic_error("Not implemented: ~BinarySearchTree()"); };

    void insert(const T &item) { throw std::logic_error("Not implemented: BinarySearchTree.insert()"); };

    void remove(const T &item) { throw std::logic_error("Not implemented: BinarySearchTree.remove()"); };

    BinaryTreeNode<T> *search(const T &item) { return _search(this->root, item); };
};

#endif //INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H
