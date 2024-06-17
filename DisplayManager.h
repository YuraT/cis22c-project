#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "HashTable.h"
#include "BinarySearchTree.h"
#include "CPU.h"

template<typename T>
class DisplayManager {
private:
    HashTable* hashTable;
    BinarySearchTree* bst;

public:
    DisplayManager(HashTable* ht, BinarySearchTree* bst);
    ~DisplayManager();

    void displayAll() const;
    void displayTree() const;
};

#endif