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
#include <vector>
#include "utils.h"
#include "CPU.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Stack.h"

using std::cin, std::cout, std::string, std::vector;

void processInput(char command, HashTable<CPU>& table, BinarySearchTree<string>& tree, Stack<CPU>& stack);

int main() {
    // Print help table for commands
    printHelp();

    HashTable<CPU> cpuTable;
    BinarySearchTree<string> cpuTree;
    Stack<CPU> undoStack;

    char command = ' ';
    while (command != 'Q') {
        cout << "Enter an option (H - for help): ";
        cin >> command;
        command = toupper(command, std::locale());
        // Temporary try catch block to handle unimplemented commands
        try {
            processInput(command, cpuTable, cpuTree, undoStack);
        } catch (std::logic_error& e) {
            cout << e.what() << '\n';
        }
    }
    // Quit command received
    // TODO: Write data to a file
    cout << "Exiting program...\n";

    return 0;
}

void insertCPU(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree);

void deleteCPU(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree, Stack<CPU> &undoStack);

void undoDelete(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree, Stack<CPU> &undoStack);

void processInput(char command, HashTable<CPU> &cpuTable, BinarySearchTree<string> &cpuTree, Stack<CPU> &undoStack) {
    switch (command) {
        case 'H':
            printHelp();
            break;
        case 'I': // Insert a new record
            insertCPU(cpuTable, cpuTree);
            break;
        case 'F': // File input: add data from a file
            throw std::logic_error("Not yet implemented: File input: add data from a file");
            break;
        case 'D': // Delete one record
            deleteCPU(cpuTable, cpuTree, undoStack);
            break;
        case 'U': // Undo delete
            undoDelete(cpuTable, cpuTree, undoStack);
            break;
        case 'L': // List all CPUs sorted by primary key
            throw std::logic_error("Not yet implemented: List all CPUs sorted by primary key");
            break;
        case 'S': // Search for a CPU by the primary key
            throw std::logic_error("Not yet implemented: Search for a CPU by the primary key");
            break;
        case 'W': // Write data to a file
            throw std::logic_error("Not yet implemented: Write data to a file");
            break;
        case 'T': // Hashtable statistics
            throw std::logic_error("Not yet implemented: Hashtable statistics");
            break;
        case 'P': // Print indented tree
            throw std::logic_error("Not yet implemented: Print indented tree");
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

void insertCPU(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree) {
    string cpuId;
    int releaseYear, coreCount;
    string architecture;
    double baseClock;
    cout << "Enter CPU ID: ";
    cin >> cpuId;
    cout << "Enter release year: ";
    cin >> releaseYear;
    cout << "Enter core count: ";
    cin >> coreCount;
    cout << "Enter architecture: ";
    cin >> architecture;
    cout << "Enter base clock: ";
    cin >> baseClock;
    CPU cpu(cpuId, releaseYear, coreCount, architecture, baseClock);

    hashTable.insert(cpu, key_to_index);
    tree.insert(cpuId);
}

void deleteCPU(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree, Stack<CPU> &undoStack) {
    string cpuId;
    cout << "Enter CPU ID to delete: ";
    cin >> cpuId;
    CPU cpu(cpuId, 0, 0, "", 0.0);
    CPU cpuFound;
    while (!hashTable.search(cpuFound, cpu, key_to_index)) {
        cout << "CPU ID not found. Enter a valid CPU ID: ";
        cin >> cpuId;
        cpu = CPU(cpuId, 0, 0, "", 0.0);
    }
    undoStack.push(cpuFound);
    hashTable.remove(cpu, key_to_index);
    tree.remove(cpuId);

    cout << "CPU ID \"" << cpuId << "\" deleted.\n";
}

void undoDelete(HashTable<CPU> &hashTable, BinarySearchTree<string> &tree, Stack<CPU> &undoStack) {
    if (undoStack.isEmpty()) {
        cout << "No deletions to undo.\n";
        return;
    }
    CPU cpu = undoStack.pop();
    hashTable.insert(cpu, key_to_index);
    tree.insert(cpu.getCpuId());
    cout << "Undo deletion of CPU ID \"" << cpu.getCpuId() << "\".\n";
}
