/*
Name: DisplayManager
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Manage the display of CPU information and the binary search tree
Input: HashTable and BinarySearchTree objects
Output: Displayed CPU information and tree structure
Procedure: Uses the HashTable and BinarySearchTree to retrieve and display information
*/

/*
Name: displayAll
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Display all CPUs in the database
Input: None
Output: List of all CPUs sorted by their ID
Procedure: Iterates through the HashTable and displays each CPU's information
*/

/*
Name: displayTree
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Display the BST as an indented tree
Input: None
Output: Indented representation of the binary search tree
Procedure: Performs an inorder traversal of the BST, displaying each node with appropriate indentation
*/

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
    std::vector<int> widths = {20, 14, 12, 20, 18};

    // Call the BST's inorder traversal method to calculate the column widths
    bst->inOrder([this, &widths](const string &cpuId) {
        CPU cpu;
        cpu.setCpuId(cpuId);
        this->hashTable->search(cpu, cpu, key_to_index);
        widths[0] = max(cpu.getCpuId().length() + 2, (size_t) widths[0]);
        widths[3] = max(cpu.getArchitecture().length() + 2, (size_t) widths[3]);
    });

    printTableHeader(widths, headers);
    // Call the BST's inorder traversal method to display the tree
    bst->inOrder([this, &widths](const string &cpuId) {
        CPU cpu;
        cpu.setCpuId(cpuId);
        this->hashTable->search(cpu, cpu, key_to_index);
        rowDisplay(cpu, widths);
    });

    printTableFooter(widths);
}

#endif
