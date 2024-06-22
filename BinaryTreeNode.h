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


#ifndef INC_08_TEAM_PROJECT_BINARYTREENODE_H
#define INC_08_TEAM_PROJECT_BINARYTREENODE_H

template<typename T>
class BinaryTreeNode {
private:
    T item;        // Data portion
    BinaryTreeNode<T>* leftPtr;     // Pointer to left child
    BinaryTreeNode<T>* rightPtr;    // Pointer to right child

public:
    // constructors
    BinaryTreeNode(const T& anItem) { item = anItem; leftPtr = 0; rightPtr = 0; }
    BinaryTreeNode(const T& anItem,
        BinaryTreeNode<T>* left,
        BinaryTreeNode<T>* right) {
        item = anItem; leftPtr = left; rightPtr = right;
    }
    // setters
    void setItem(const T& anItem) { item = anItem; }
    void setLeftPtr(BinaryTreeNode<T>* left) { leftPtr = left; }
    void setRightPtr(BinaryTreeNode<T>* right) { rightPtr = right; }

    // getters
    T getItem() const { return item; }
    BinaryTreeNode<T>* getLeftPtr() const { return leftPtr; }
    BinaryTreeNode<T>* getRightPtr() const { return rightPtr; }

    // other functions
    bool isLeaf() const { return (leftPtr == 0 && rightPtr == 0); }

};

#endif //INC_08_TEAM_PROJECT_BINARYTREENODE_H
