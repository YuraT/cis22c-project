#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include "HashTable.h"
#include "CPU.h"

template<typename T>
class SearchManager {
private:
    HashTable* hashTable;

public:
    SearchManager(HashTable* ht);
    ~SearchManager();

    void searchCPU() const;
};

#endif