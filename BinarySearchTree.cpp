#include "BinarySearchTree.h"

template<typename T>
void BinarySearchTree<T>::insert(const T& newEntry)
{
    BinaryTreeNode<T>* newNodePtr = new BinaryTreeNode<T>(newEntry);
    this->rootPtr = _insert(this->rootPtr, newNodePtr);
    this->count++;
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
    BinarySearchTree<T>* temp = nullptr;

    temp = _search(this->rootPtr, target);
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
        if (target.getCode() == nodePtr->getItem().getCode()) found = nodePtr;
        else if (target.getCode() < nodePtr->getItem().getCode()) found = _search(nodePtr->getLeftPtr(), target);
        else found = _search(nodePtr->getRightPtr(), target);
    }

    return found;
}