#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include "HashTable.h"
#include "CPU.h"

template<typename T>
class SearchManager {
private:
    HashTable<T> *hashTable;

public:
    SearchManager(HashTable<T> *ht);

    void searchCPU() const;
};

template<typename T>
SearchManager<T>::SearchManager(HashTable<T> *ht) {
    this->hashTable = ht;
}

template<typename T>
void SearchManager<T>::searchCPU() const {
    std::string cpuID;
    std::cout << "Enter the CPU ID to search: ";
    std::cin.ignore();
    getline(std::cin, cpuID);

    // Search for the CPU in the HashTable
    CPU foundCPU;
    foundCPU.setCpuId(cpuID);
    int collisionCount = hashTable->search(foundCPU, foundCPU, key_to_index);

    if (collisionCount != -1) {
        std::cout << "CPU found:" << std::endl;
        display(foundCPU);
    } else {
        std::cout << "CPU not found." << std::endl;
    }
}

#endif
