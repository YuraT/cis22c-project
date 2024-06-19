#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "HashTable.h"
#include "BinarySearchTree.h"
#include "CPU.h"

template<typename T>
class DisplayManager {
private:
    HashTable<T> *hashTable;
    BinarySearchTree<std::string> *bst;

public:
    DisplayManager(HashTable<T> *ht, BinarySearchTree<std::string> *bst);

    ~DisplayManager();

    void displayAll() const;

    void displayTree() const;
};

template<typename T>
DisplayManager<T>::DisplayManager(HashTable<T> *ht, BinarySearchTree<std::string> *bst) {
    this->hashTable = ht;
    this->bst = bst;
}

template<typename T>
DisplayManager<T>::~DisplayManager() {
    // No dynamic memory allocation, so no cleanup needed
}

template<typename T>
void DisplayManager<T>::displayAll() const {
    std::cout << "All CPUs in the database:" << std::endl;

    // Iterate over the HashTable and display each CPU
    for (int i = 0; i < hashTable->getCount(); i++) {
        if (hashTable->getItem(i) != nullptr) {
            std::cout << *(hashTable->getItem(i)) << std::endl;
        }
    }
}

template<typename T>
void DisplayManager<T>::displayTree() const {
    std::cout << "All CPUs: " << std::endl;

    static const std::vector<string> headers = {
            "CPU ID",
            "Release Year",
            "Core Count",
            "Architecture",
            "Base Clock (GHz)"
    };
    static const std::vector<int> widths = {20, 14, 12, 20, 18};
    printTableHeader(widths, headers);

    // Call the BST's inorder traversal method to display the tree
    bst->inOrder([this](const string &cpuId) {
        CPU cpu;
        cpu.setCpuId(cpuId);
        this->hashTable->search(cpu, cpu, key_to_index);
        rowDisplay(cpu, widths);
    });

    printTableFooter(widths);
}

#endif
