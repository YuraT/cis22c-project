#ifndef INC_08_TEAM_PROJECT_BINARYTREE_H
#define INC_08_TEAM_PROJECT_BINARYTREE_H

#include "BinaryTreeNode.h"

template<typename T>
class BinaryTree {
protected:
    BinaryTreeNode<T> *root;
    int size;

public:

    BinaryTree() : root(nullptr), size(0) {};

    BinaryTree(const BinaryTree<T>& tree) { }

    ~BinaryTree() { destroyTree(root); };

    [[nodiscard]] bool isEmpty() const { return size == 0; };

    [[nodiscard]] int getSize() const { return size; };

    void clear() { destroyTree(root); root = 0; size = 0; }

    void preOrder(void visit(const T&)) const { _preorder(visit, root); }

    void inOrder(void visit(const T&)) const { _inorder(visit, root); }

    void postOrder(void visit(const T&)) const { _postorder(visit, root); }

    void printIndented(void visit(const T&)) const { _printindented(visit, root, 0); }

    // abstract functions to be implemented by derived class
    virtual void insert(const T& newData) = 0;
    //virtual bool remove(const T &data) = 0;
    virtual bool search(const T& target, T& returnedItem) const = 0;

private:
    // delete all nodes from the tree
    void destroyTree(BinaryTreeNode<T>* nodePtr);

    // internal traverse
    void _preorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const;

    void _inorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const;

    void _postorder(void visit(const T&), BinaryTreeNode<T>* nodePtr) const;

    void _printindented(void visit(const T&, int), BinaryTreeNode<T>* nodePtr) const;

};

#endif //INC_08_TEAM_PROJECT_BINARYTREE_H
