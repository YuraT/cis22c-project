// Unit 5: File I/O
// - Determine hash size based on the number of records in the file
// - Read data from the input file and insert them into the hash table and BST
// - Save to file (in hash table sequence)
// - Re-hashing
//
// Written by: Kevin Cremin

#ifndef INC_08_TEAM_PROJECT_FIO_H
#define INC_08_TEAM_PROJECT_FIO_H

#include <string>
#include <fstream>
#include <iostream>
#include "CPU.h"
#include "HashTable.h"
#include "BinarySearchTree.h"

using std::string;

int findHashSize(const string& filename);

void insertFile(const string& filename, BinarySearchTree<string> &bst, HashTable<CPU> &hash);

void insertCPU(BinarySearchTree<string> &bst, HashTable<CPU> &hash);

#endif //INC_08_TEAM_PROJECT_FIO_H
