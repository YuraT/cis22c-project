/* Unit 2: BST
*
* - Written in template format for flexibility
*
*   - In project, BST holds primary key of CPU IDs
*
* - Sorted based off string comparison
*
* - Has insert, search, and remove functionality
*
* - Has multiple transversal functions (inorder, preorder, postorder)
*
* - Has printTree function that prints all nodes in function
*
*   - In project, function pointer is used to print in indented format
*
* Written By: Tuhin Mondal
*/


#ifndef INC_08_TEAM_PROJECT_BINARYTREE_H
#define INC_08_TEAM_PROJECT_BINARYTREE_H

#include <functional>
#include "BinaryTreeNode.h"

template<typename T>
class BinaryTree {
protected:
    BinaryTreeNode<T> *root;
    int size;

public:

    BinaryTree() : root(nullptr), size(0) {};

    ~BinaryTree() { destroyTree(root); };

    [[nodiscard]] bool isEmpty() const { return size == 0; };

    [[nodiscard]] int getSize() const { return size; };

    // Caller function for private destroyTree() method
    void clear() { destroyTree(root); root = 0; size = 0; }

    // Caller function for private _preorder() method
    void preOrder(void visit(const T&)) const { _preorder(visit, root); }

    // Caller function for private _inorder() method
    void inOrder(std::function<void(const T&)> visit) const { _inorder(visit, root); }

    // Caller function for private _postorder() method
    void postOrder(void visit(const T&)) const { _postorder(visit, root); }

    // Caller function for private _printTree() method
    void printTree(void visit(const T&, int)) const { _printTree(visit, root, 1); }

    // abstract functions to be implemented by derived class
    virtual void insert(const T& newData) = 0;
    virtual bool remove(const T &data) = 0;
    virtual bool search(const T& target, T& returnedItem) const = 0;

private:
    // delete all nodes from the tree
    void destroyTree(BinaryTreeNode<T>* nodePtr);

    // internal traverse
    void _preorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const;

    void _inorder(std::function<void(const T&)> visit, BinaryTreeNode<T>* nodePtr) const;

    void _postorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const;

    void _printTree(void visit(const T&, int), BinaryTreeNode<T>* nodePtr, int level) const;

};

// Recursively deletes every node in the tree
template<class T>
void BinaryTree<T>::destroyTree(BinaryTreeNode<T>* nodePtr)
{
    if (nodePtr) // != NULL
    {
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}

// Traverses through tree in preorder
template<typename T>
void BinaryTree<T>::_preorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const
{
	if (nodePtr) {
		T item = nodePtr->getItem();
		visit(item);
		_preorder(visit, nodePtr->getLeftPtr());
		_preorder(visit, nodePtr->getRightPtr());
	}
}

// Traverses through tree in inorder
template<typename T>
void BinaryTree<T>::_inorder(std::function<void(const T&)> visit, BinaryTreeNode<T>* nodePtr) const
{
    if (nodePtr) // != NULL
    {
        T item = nodePtr->getItem();
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
    }
}

// Traverses through tree in postorder
template<typename T>
void BinaryTree<T>::_postorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const
{
    if (nodePtr) {
        T item = nodePtr->getItem();
        _postorder(visit, nodePtr->getLeftPtr());
        _postorder(visit, nodePtr->getRightPtr());
        visit(item);
    }
}

// Prints tree using function pointer
template<class T>
void BinaryTree<T>::_printTree(void visit(const T&, int), BinaryTreeNode<T>* nodePtr, int level) const
{
    if (nodePtr) {
        T item = nodePtr->getItem();
        visit(item, level);
        _printTree(visit, nodePtr->getRightPtr(), level + 1);
        _printTree(visit, nodePtr->getLeftPtr(), level + 1);
    }
}

#endif //INC_08_TEAM_PROJECT_BINARYTREE_H
