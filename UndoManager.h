#ifndef UNDO_MANAGER_H
#define UNDO_MANAGER_H

#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Stack.h"
#include "CPU.h"

template<typename T>
class UndoManager {
private:
    HashTable* hashTable;
    BinarySearchTree* bst;
    Stack<CPU>* undoStack;

public:
    UndoManager(HashTable* ht, BinarySearchTree* bst);
    ~UndoManager();

    void addToUndoStack(const CPU& cpu);
    void undoDelete();
    void clearUndoStack();
};

#endif