#ifndef UNDO_MANAGER_H
#define UNDO_MANAGER_H

#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Stack.h"
#include "CPU.h"

template<typename T>
class UndoManager {
private:
    HashTable<T> *hashTable;
    BinarySearchTree<std::string> *bst;
    Stack<T> *undoStack;

public:
    UndoManager(HashTable<T> *ht, BinarySearchTree<std::string> *bst);

    ~UndoManager();

    void addToUndoStack(const T &cpu);

    void undoDelete();

    void clearUndoStack();
};

template<typename T>
UndoManager<T>::UndoManager(HashTable<T> *ht, BinarySearchTree<std::string> *bst) {
    this->hashTable = ht;
    this->bst = bst;
    this->undoStack = new Stack<CPU>();
}

template<typename T>
UndoManager<T>::~UndoManager() {
    delete undoStack;
}

template<typename T>
void UndoManager<T>::addToUndoStack(const T &cpu) {
    undoStack->push(cpu);
}

template<typename T>
void UndoManager<T>::undoDelete() {
    if (!undoStack->isEmpty()) {
        T lastDeleted = undoStack->pop();

        // Check if the CPU is already in the HashTable
        T foundCPU;
        foundCPU.setCpuId(lastDeleted.getCpuId());
        if (hashTable->search(foundCPU, foundCPU, key_to_index) != -1) {
            std::cout << "Undo failed: CPU \"" << lastDeleted.getCpuId() << "\" already exists in the HashTable." << std::endl;
            return;
        }

        // Reinsert the CPU into the HashTable and BST
        hashTable->insert(lastDeleted, key_to_index);
        bst->insert(lastDeleted.getCpuId());

        std::cout << "Undo successful. CPU reinserted:" << std::endl;
        std::cout << lastDeleted << std::endl;
    } else {
        std::cout << "No deletions to undo." << std::endl;
    }
}

template<typename T>
void UndoManager<T>::clearUndoStack() {
    while (!undoStack->isEmpty()) {
        undoStack->pop();
    }
}

#endif
