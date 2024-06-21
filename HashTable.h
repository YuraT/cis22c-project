#ifndef INC_08_TEAM_PROJECT_HASHTABLE_H
#define INC_08_TEAM_PROJECT_HASHTABLE_H

#include <fstream>
#include <iostream>
#include <functional>
#include "HashNode.h"
#include "CPU.h"
#include "utils.h"

using namespace std;

// Forward declaration for friend function
template<typename T>
class HashTable;

template<typename T>
void writeToFile(const HashTable<T> &hashTable, const string &filename, string visit(const T &));

template<typename T>
class HashTable {
private:
    HashNode<T> *hashAry;
    int hashSize;
    int count;

    void _reHash(int h(const T &key, int size));

public:
    HashTable() {
        count = 0;
        hashSize = 7;
        hashAry = new HashNode<T>[hashSize];
    }

    HashTable(int n) {
        count = 0;
        hashSize = n;
        hashAry = new HashNode<T>[hashSize];
    }

    ~HashTable() { delete[] hashAry; }

    int getCount() const { return count; }

    int getHashSize() const { return hashSize; }

    double getLoadFactor() const { return 100.0 * count / hashSize; }

    bool isEmpty() const { return count == 0; }

    bool isFull() const { return count == hashSize; }

    int getTotalCollisions() const;

    int getMaxCollisions() const;

    bool insert(const T &itemIn, int h(const T &key, int size));

    bool remove(T &itemOut, const T &key, int h(const T &key, int size));

    int search(T &itemOut, const T &key, int h(const T &key, int size)) const;

    friend void writeToFile<T>(const HashTable<T> &hashTable, const string &filename, string visit(const T &));
};

/*~*~*~*
    Get total number of collisions throughout hash table
*~**/
template<typename T>
int HashTable<T>::getTotalCollisions() const {
    int total = 0;
    for (int i = 0; i < hashSize; i++) {
        if (hashAry[i].getOccupied() == 1) {
            total += hashAry[i].getNumCollisions();
        }
    }
    return total;
}

/*~*~*~*
    Get longest collision length in hash table
*~**/
template<typename T>
int HashTable<T>::getMaxCollisions() const {
    int high = 0;
    for (int i = 0; i < hashSize; i++) {
        if (hashAry[i].getOccupied() == 1 && hashAry[i].getNumCollisions() > high) {
            high = hashAry[i].getNumCollisions();
        }
    }
    return high;
}

/*~*~*~*
   Insert an item into the hash table
   It does not reject duplicates
*~**/
template<typename T>
bool HashTable<T>::insert(const T &itemIn, int h(const T &key, int size)) {

    if (getLoadFactor() >= 75) {
        cout << "Load factor is " << getLoadFactor() << ". Rehashing...\n";
        _reHash(key_to_index);
    }

    int ind = h(itemIn, hashSize);
    for (int i = 0; i < hashSize; i++) {
        if (hashAry[(ind + i) % hashSize].getOccupied() != 1) {
            hashAry[(ind + i) % hashSize].setOccupied(1);
            hashAry[(ind + i) % hashSize].setItem(itemIn);
            hashAry[(ind + i) % hashSize].setNumCollisions(i);
            count++;
            break;
        }
    }

    return true;
}

/*~*~*~*
   Removes the item with the matching key from the hash table
   if found:
     - copies data in the hash node to itemOut
     - replaces data in the hash node with an empty record (occupied = -1: deleted!)
     - returns true
   if not found:
     - returns false
*~**/
template<typename T>
bool HashTable<T>::remove(T &itemOut, const T &key, int h(const T &key, int size)) {
    int ind = h(key, hashSize);
    for (int i = 0; i < hashSize; i++) {
        if (hashAry[(ind + i) % hashSize].getOccupied() == 1) {
            if (hashAry[(ind + i) % hashSize].getItem() == key) {
                itemOut = hashAry[(ind + i) % hashSize].getItem();
                hashAry[(ind + i) % hashSize].setOccupied(-1);
                // Do not access a node with occupied of -1
                count--;
                return true;
            }
        } else if (hashAry[(ind + 1) % hashSize].getOccupied() == 0) {
            // If using linear probing and we come across a spot that has been empty since start, the item is not in the table
            break;
        }
    }

    return false;
}

/*~*~*~*
   hash search - linear probe
   if found:
      - copy data to itemOut
      - returns the number of collisions for this key
   if not found, returns -1
*~**/
template<typename T>
int HashTable<T>::search(T &itemOut, const T &key, int h(const T &key, int size)) const {
    int ind = h(key, hashSize);
    for (int i = 0; i < hashSize; i++) {
        if (hashAry[(ind + i) % hashSize].getOccupied() == 1) {
            if (hashAry[(ind + i) % hashSize].getItem() == key) {
                itemOut = hashAry[(ind + i) % hashSize].getItem();
                return hashAry[(ind + i) % hashSize].getNumCollisions();
            }
        } else if (hashAry[(ind + 1) % hashSize].getOccupied() == 0) {
            // If using linear probing and we come across a spot that has been empty since start, the item is not in the table
            break;
        }
    }

    return -1;
}

template<class T>
void HashTable<T>::_reHash(int h(const T &key, int size)) {

    int nHashSize = hashSize * 2;

    nHashSize = findNextPrime(nHashSize);

    HashNode<T> *nHashAry = new HashNode<T>[nHashSize];

    // Goes through each bucket and puts it in the new array
    T aT;
    for (int i = 0; i < hashSize; i++) {
        if (hashAry[i].getOccupied() == 1) {
            aT = hashAry[i].getItem();

            int nIndex = h(aT, nHashSize);

            for (int j = 0; j < nHashSize; j++) {
                if (nHashAry[nIndex].getOccupied() != 1) {
                    nHashAry[nIndex].setItem(aT);
                    nHashAry[nIndex].setOccupied(1);
                    nHashAry[nIndex].setNumCollisions(i);
                    break;
                }

                nIndex = (nIndex + 1) % hashSize;
            }
        }
    }

    hashAry = nHashAry;
    hashSize = nHashSize;
}

template<typename T>
void writeToFile(const HashTable<T> &hashTable, const string &filename, string visit(const T &)) {
    ofstream outputFile(filename);

    if (!outputFile.good()) {
        cout << "Error opening the output file: \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    outputFile.flush();

    T aT;

    for (int i = 0; i < hashTable.hashSize; i++) {
        if (hashTable.hashAry[i].getOccupied() == 1) {
            aT = hashTable.hashAry[i].getItem();
            outputFile << visit(aT) << '\n';
        }
    }

    outputFile.close();
}

#endif // INC_08_TEAM_PROJECT_HASHTABLE_H
