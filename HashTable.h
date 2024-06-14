#ifndef INC_08_TEAM_PROJECT_HASHTABLE_H
#define INC_08_TEAM_PROJECT_HASHTABLE_H

#include <stdexcept>
#include "HashNode.h"

template<typename T>
class HashTable {
private:
    int hashSize;
    int count;
    HashNode<T> *hashAry;

public:
    HashTable() : hashSize(97), count(0) {
        hashAry = new HashNode<T>[hashSize];
    };

    ~HashTable() { delete[] hashAry; };

    [[nodiscard]] int getCount() const { return count; };

    [[nodiscard]] int getHashSize() const { return hashSize; };

    bool isEmpty() const { return count == 0; };

    bool isFull() const { return count == hashSize; };

    double getLoadFactor() const { throw std::logic_error("Not implemented: HashTable.getLoadFactor()"); };

    bool insert(const T &item, int h(const T&, int)) { throw std::logic_error("Not implemented: HashTable.insert()"); };

    bool remove(const T &item, int h(const T&), int) { throw std::logic_error("Not implemented: HashTable.remove()"); };

    bool search(const T &item, int h(const T&), int) { throw std::logic_error("Not implemented: HashTable.search()"); };

    int getTotalCollisions() const { throw std::logic_error("Not implemented: HashTable.getTotalCollisions()"); };

    int getMaxCollisions() const { throw std::logic_error("Not implemented: HashTable.getMaxCollisions()"); };
};

#endif //INC_08_TEAM_PROJECT_HASHTABLE_H
