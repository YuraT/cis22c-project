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

    void clear() { destroyTree(root); root = 0; size = 0; }

    void preOrder(void visit(const T&)) const { _preorder(visit, root); }

    void inOrder(std::function<void(const T&)> visit) const { _inorder(visit, root); }

    void postOrder(void visit(const T&)) const { _postorder(visit, root); }

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
