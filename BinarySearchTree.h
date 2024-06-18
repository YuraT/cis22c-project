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

template<typename T>
void BinarySearchTree<T>::insert(const T& newEntry)
{
    BinaryTreeNode<T>* newNodePtr = new BinaryTreeNode<T>(newEntry);
    this->root = _insert(this->root, newNodePtr);
    this->size++;
}

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::_insert(BinaryTreeNode<T>* nodePtr, BinaryTreeNode<T>* newNodePtr) {
    BinaryTreeNode<T>* pWalk = nodePtr, * parent = nullptr;

    if (!nodePtr)
    {
        nodePtr = newNodePtr;
        return nodePtr;
    } else {
        while (pWalk)
        {
            parent = pWalk;
            if (pWalk->getItem() > newNodePtr->getItem())
                pWalk = pWalk->getLeftPtr();
            else
                pWalk = pWalk->getRightPtr();
        }
        if (parent->getItem() > newNodePtr->getItem())
            parent->setLeftPtr(newNodePtr);
        else
            parent->setRightPtr(newNodePtr);
    }

    return nodePtr;
}

template<typename T>
bool BinarySearchTree<T>::search(const T& target, T& returnedItem) const
{
    BinaryTreeNode<T>* temp = nullptr;

    temp = _search(this->root, target);
    if (temp) {
        returnedItem = temp->getItem();
        return true;
    }

    return false;
}

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::_search(BinaryTreeNode<T>* nodePtr, const T& target) const
{
    BinaryTreeNode<T>* found = nullptr;

    if (nodePtr) {
        if (target == nodePtr->getItem()) found = nodePtr;
        else if (target < nodePtr->getItem()) found = _search(nodePtr->getLeftPtr(), target);
        else found = _search(nodePtr->getRightPtr(), target);
    }

    return found;
}

#endif //INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H
