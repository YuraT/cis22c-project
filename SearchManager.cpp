#include "SearchManager.h"
#include <iostream>
#include <string>

SearchManager::SearchManager(HashTable* ht) {
    this->hashTable = ht;
}

SearchManager::~SearchManager() {
    // No dynamic memory allocation, so no cleanup needed
}

void SearchManager::searchCPU() const {
    std::string cpuID;
    std::cout << "Enter the CPU ID to search: ";
    std::cin >> cpuID;

    // Search for the CPU in the HashTable
    CPU* foundCPU = hashTable->search(cpuID);

    if (foundCPU != nullptr) {
        std::cout << "CPU found:" << std::endl;
        std::cout << *foundCPU << std::endl;
    } else {
        std::cout << "CPU not found." << std::endl;
    }
}