/*
Name: SearchManager
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Manage the search functionality for CPUs
Input: HashTable object
Output: Search results or error messages
Procedure: Prompts user for search criteria, uses the HashTable to find matching CPUs, and displays results
*/

/*
Name: searchCPU
Written By: Kevin Galvan Serrano
Modified By: 
Purpose: Search for a CPU by its ID
Input: CPU ID (string)
Output: CPU information if found, or a "not found" message
Procedure: Uses the HashTable's search function to find the CPU, then displays its information
*/


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
