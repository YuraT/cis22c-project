#ifndef INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H
#define INC_08_TEAM_PROJECT_BINARYSEARCHTREE_H

#include "BinaryTree.h"

template<typename T>
class BinarySearchTree: public BinaryTree<T> {
private:
    BinaryTreeNode<T>* _insert(BinaryTreeNode<T>* nodePtr, BinaryTreeNode<T>* newNode);

    BinaryTreeNode<T>* _search(BinaryTreeNode<T>* treePtr, const T& target) const;

    BinaryTreeNode<T>* _remove(BinaryTreeNode<T>* nodePtr, const T& target);

public:
    void insert(const T& item);

    bool remove(const T& item);

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
bool BinarySearchTree<T>::remove(const T& item) {
    BinaryTreeNode<T>* removed = _remove(this->root, item);
    if (removed) {
        this->size--;
        return true;
    }
    return false;
}

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::_remove(BinaryTreeNode<T>* nodePtr, const T& target) {
    BinaryTreeNode<T>* parNode = nullptr;
    BinaryTreeNode<T>* currNode = nodePtr;
    
    while (currNode) {
        if (currNode->getItem() == target) {
            if (!currNode->getLeftPtr() && !currNode->getRightPtr()) {    // if target is leaf node
                if (!parNode) this->root = nullptr;
                else if (parNode->getLeftPtr() == currNode) parNode->setLeftPtr(nullptr);
                else parNode->setRightPtr(nullptr);
            }
            else if (!currNode->getRightPtr()) {     // if target has only left child
                if (!parNode) this->root = currNode->getLeftPtr();
                else if (parNode->getLeftPtr() == currNode) parNode->setLeftPtr(currNode->getLeftPtr());
                else parNode->setRightPtr(currNode->getLeftPtr());
            }
            else if (!currNode->getLeftPtr()) {     // if target has only right child
                if (!parNode) this->root = currNode->getRightPtr();
                else if (parNode->getLeftPtr() == currNode) parNode->setLeftPtr(currNode->getRightPtr());
                else parNode->setRightPtr(currNode->getRightPtr());
            }
            else {  // if target has both left and right child
                BinaryTreeNode<T>* sucNode = currNode->getRightPtr();
                while (sucNode->getLeftPtr()) 
                    sucNode = sucNode->getLeftPtr();
                T sucData = sucNode->getItem();
                _remove(this->root, sucData);
                currNode->setItem(sucData);
            }
            return currNode;
        }
        else if (currNode->getItem() < target) {
            parNode = currNode;
            currNode = currNode->getRightPtr();
        }
        else {
            parNode = currNode;
            currNode = currNode->getLeftPtr();
        }
    }
    return nullptr;
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
