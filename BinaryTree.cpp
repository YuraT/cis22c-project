#include "BinaryTree.h"

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
void BinaryTree<T>::_inorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const
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

template<typename T>
void BinaryTree<T>::_printindented(void visit(const T&, int), BinaryTreeNode<T>* nodePtr) const {
    if (nodePtr) {
        T item = nodePtr->getItem();
        _printInnerNodes(visit, nodePtr->getLeftPtr());
        if (nodePtr->getLeftPtr() || nodePtr->getRightPtr()) visit(item);
        _printInnerNodes(visit, nodePtr->getRightPtr());
    }
}