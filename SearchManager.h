#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include "HashTable.h"
#include "CPU.h"

template<typename T>
class SearchManager {
private:
    HashTable<T> hashTable;

public:
    SearchManager(HashTable<T> &ht);

    void searchCPU() const;
};

template<typename T>
SearchManager<T>::SearchManager(HashTable<T> &ht) {
    this->hashTable = ht;
}

template<typename T>
void SearchManager<T>::searchCPU() const {
    std::string cpuID;
    std::cout << "Enter the CPU ID to search: ";
    std::cin >> cpuID;

    // Search for the CPU in the HashTable
    CPU *foundCPU = hashTable.search(cpuID);

    if (foundCPU != nullptr) {
        std::cout << "CPU found:" << std::endl;
        std::cout << *foundCPU << std::endl;
    } else {
        std::cout << "CPU not found." << std::endl;
    }
}

#endif
