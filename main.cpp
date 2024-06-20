// # Project Requirements
//
// Begin by displaying some general information about the project, the names and tasks of the developers.
// Processing is to be menu-driven with the following options:
//
// - Add a new data item.
// - Add data from an input file (get the name of the input file from the user). (does it overwrite?)
// - Delete data (one item).
// - Find and display one element using the primary key.
// - List data sorted by the primary key.
// - Hidden print option (do not show it in the menu: details are given in Team Project- Part2).
//     - display the indented tree
// - Write data to a file.
// - Statistics (details are given in Team Project-Part2)
//     - load factor
//     - number of collisions (total)
//     - longest collision path
// - Hidden option (do not show it in the menu): when selected, display the names of the team members.
// - Help – to show the menu. Show the menu once, before the loop, then show the menu upon request: “Enter an option (H – for help): ”
// - Exit
//
// At the end of the program, the data are to be automatically written to a file.
// This is in addition to the menu write file option.
// The output file name does not have to be the same as the input file name,
// but the file format must be the same so that it can be read back into the program.

#include <iostream>
#include <string>
#include "utils.h"
#include "CPU.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Stack.h"
#include "fio.h"
#include "UndoManager.h"
#include "DisplayManager.h"
#include "SearchManager.h"

using namespace std;

const string DEFAULT_FILE = "out.txt";

void processInput(char command, HashTable<CPU> &table, BinarySearchTree<string> &tree,
                  UndoManager<CPU> &undoManager, DisplayManager<CPU> &displayManager,
                  SearchManager<CPU> &searchManager);

int main() {
    // Print help table for commands
    printHelp();

    int hashSize = findHashSize(DEFAULT_FILE);
    HashTable<CPU> cpuTable = HashTable<CPU>(hashSize == -1 ? 7 : hashSize);
    BinarySearchTree<string> cpuTree;

    // Read initial data from output file if it exists
    if (hashSize != -1) {
        insertFile(DEFAULT_FILE, cpuTree, cpuTable);
    } else {
        cout << "Could not open default file \"" << DEFAULT_FILE << "\". Starting with an empty database.\n";
    }

    DisplayManager<CPU> displayManager(&cpuTable, &cpuTree);
    SearchManager<CPU> searchManager(&cpuTable);
    UndoManager<CPU> undoManager(&cpuTable, &cpuTree);

    char command = ' ';
    while (command != 'Q') {
        cout << "Enter an option (H - for help): ";
        cin >> command;
        command = toupper(command, std::locale());
        // Temporary try catch block to handle unimplemented commands
        try {
            processInput(command, cpuTable, cpuTree, undoManager, displayManager, searchManager);
        }
        catch (std::logic_error &e) {
            cout << "Error: " << e.what() << '\n';
        }
    }
    // Quit command received
    writeToFile(cpuTable, DEFAULT_FILE, to_string);
    cout << "Exiting program...\n";

    return 0;
}

void handleInsert(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree);

void handleFileInput(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree);

void deleteCPU(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree, UndoManager<CPU> &undoManager);

void handleFileOutput(HashTable<CPU> &hashTable, UndoManager<CPU> &undoManager);

void processInput(char command, HashTable<CPU> &cpuTable, BinarySearchTree<string> &cpuTree,
                  UndoManager<CPU> &undoManager, DisplayManager<CPU> &displayManager,
                  SearchManager<CPU> &searchManager) {
    switch (command) {
        case 'H':
            printHelp();
            break;
        case 'I': // Insert a new record
            handleInsert(cpuTable, cpuTree);
            break;
        case 'F': // File input: add data from a file
            handleFileInput(cpuTable, cpuTree);
            undoManager.clearUndoStack();
            break;
        case 'D': // Delete one record
            deleteCPU(cpuTable, cpuTree, undoManager);
            break;
        case 'U': // Undo delete
            undoManager.undoDelete();
            break;
        case 'L': // List all CPUs sorted by primary key
            displayManager.displayTree();
            break;
        case 'S': // Search for a CPU by the primary key
            searchManager.searchCPU();
            break;
        case 'W': // Write data to a file
            handleFileOutput(cpuTable, undoManager);
            break;
        case 'T': // Hashtable statistics
            cout << "Load factor: " << cpuTable.getLoadFactor() << std::endl;
            cout << "Total number of collisions: " << cpuTable.getTotalCollisions() << std::endl;
            cout << "Longest collision path: " << cpuTable.getMaxCollisions() << std::endl;
            break;
        case 'P': // Print indented tree
            cpuTree.printTree(iDisplay);
            break;
        case 'Z': // Display names of team members
            printTeam();
            break;
        case 'Q': // Quit
            break;
        default:
            cout << "Invalid command. Press 'H' to view available commands.\n";
    }
}

void handleInsert(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree) {
    if (hashTable.getLoadFactor() >= 75) {
        cout << "Load factor is " << hashTable.getLoadFactor() << ". Rehashing...\n";
        hashTable.reHash(key_to_index);
    }
    insertCPU(tree, hashTable);
}

void handleFileInput(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    insertFile(filename, tree, hashTable);
}

void deleteCPU(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree, UndoManager<CPU> &undoManager) {
    string cpuId;
    cout << "Enter CPU ID to delete: ";
    cin.ignore();
    getline(cin, cpuId);

    CPU cpu(cpuId, 0, 0, "", 0.0);
    CPU cpuFound;
    if  (hashTable.search(cpuFound, cpu, key_to_index) == -1) {
        cout << "CPU ID \"" << cpuId << "\" not found.\n";
        return;
    }
    hashTable.remove(cpuFound, cpu, key_to_index);
    undoManager.addToUndoStack(cpuFound);
    tree.remove(cpuId);

    cout << "CPU ID \"" << cpuId << "\" deleted.\n";
}

void handleFileOutput(HashTable<CPU> &hashTable, UndoManager<CPU> &undoManager) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    writeToFile(hashTable, filename, to_string);
    undoManager.clearUndoStack();
    cout << "Data written to file \"" << filename << "\".\n";
}
