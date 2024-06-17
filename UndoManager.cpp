#include "UndoManager.h"
#include <iostream>

UndoManager::UndoManager(HashTable* ht, BinarySearchTree* bst) {
    this->hashTable = ht;
    this->bst = bst;
    this->undoStack = new Stack<CPU>();
}

UndoManager::~UndoManager() {
    delete undoStack;
}

void UndoManager::addToUndoStack(const CPU& cpu) {
    undoStack->push(cpu);
}

void UndoManager::undoDelete() {
    if (!undoStack->isEmpty()) {
        CPU lastDeleted = undoStack->pop();

        // Reinsert the CPU into the HashTable and BST
        hashTable->insert(lastDeleted);
        bst->insert(lastDeleted);

        std::cout << "Undo successful. CPU reinserted:" << std::endl;
        std::cout << lastDeleted << std::endl;
    } else {
        std::cout << "No deletions to undo." << std::endl;
    }
}

void UndoManager::clearUndoStack() {
    while (!undoStack->isEmpty()) {
        undoStack->pop();
    }
}