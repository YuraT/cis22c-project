// Unit 5: File I/O
// - Determine hash size based on the number of records in the file
// - Read data from the input file and insert them into the hash table and BST
// - Save to file (in hash table sequence) (in HashTable.h)
// - Re-hashing (in HashTable.h)
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

/*
 * Name: findHashSize
 * Written By: Kevin Cremin
 * Modified By: Iurii Tatishchev
 * Purpose: Find the the necessary initial size of the hash table
 * Input: Name of file
 * Output: Appropriate size of hash array based on how many items are in the fileName
 * Procedure: Multiplies number of items in file by two, then finds next prime number
 */
int findHashSize(const string &filename);

/*
 * Name: insertFile
 * Written By: Kevin Cremin
 * Modified By: Iurii Tatishchev
 * Purpose: Input all items in the file into the program.
 * Input: Name of file, the Binary Search Tree, and the Hash Table
 * Output: N/A
 * Procedure: Goes through each item in the file and inputs them into the table and tree,
 * verifying that there are no duplicate keys.
 */
void insertFile(const string &filename, BinarySearchTree<string> &bst, HashTable<CPU> &hash);

/*
 * Name: insertCPU
 * Written By: Kevin Cremin
 * Modified By:
 * Purpose: Input an individual CPU from the user
 * Input: The Binary Search Tree and the Hash Table
 * Output: N/A
 * Procedure: Requests information from the user, making sure that it is not a duplicate,
 * and that all inputs are the correct data type.
 */
void insertCPU(BinarySearchTree<string> &bst, HashTable<CPU> &hash);

#endif //INC_08_TEAM_PROJECT_FIO_H
