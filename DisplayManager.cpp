#include "DisplayManager.h"
#include <iostream>

DisplayManager::DisplayManager(HashTable* ht, BinarySearchTree* bst) {
    this->hashTable = ht;
    this->bst = bst;
}

DisplayManager::~DisplayManager() {
    // No dynamic memory allocation, so no cleanup needed
}

void DisplayManager::displayAll() const {
    std::cout << "All CPUs in the database:" << std::endl;
    
    // Iterate over the HashTable and display each CPU
    for (int i = 0; i < hashTable->getSize(); i++) {
        if (hashTable->getItem(i) != nullptr) {
            std::cout << *(hashTable->getItem(i)) << std::endl;
        }
    }
}

void DisplayManager::displayTree() const {
    std::cout << "CPU Binary Search Tree:" << std::endl;
    
    // Call the BST's inorder traversal method to display the tree
    bst->inorderTraversal();
}