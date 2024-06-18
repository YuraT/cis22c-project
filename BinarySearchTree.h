#ifndef INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H
#define INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H

#include "BinaryTree.h"

template<typename T>
class BinarySearchTree: public BinaryTree<T> {
private:
    BinaryTreeNode<T>* _insert(BinaryTreeNode<T>* nodePtr, BinaryTreeNode<T>* newNode);

    BinaryTreeNode<T>* _search(BinaryTreeNode<T>* treePtr, const T& target) const;

    //BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool& success);

public:
    void insert(const T& item);

    void remove(const T &item) { throw std::logic_error("Not implemented: BinarySearchTree.remove()"); };

    bool search(const T& target, T& returnedItem) const;
};

#endif //INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H
