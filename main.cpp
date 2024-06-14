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

void printHelp() {
    static const vector<int> helpWidths = {5, 40};
    static const vector<vector<string>> helpData = {
            {"Key", "Command"},
            {"H",   "Help"},
            {"I",   "Insert a new record"},
            {"F",   "File input: add data from a file"},
            {"D",   "Delete one record"},
            {"U",   "Undo delete"},
            {"L",   "List all CPUs sorted by primary key"},
            {"S",   "Search for a CPU by the primary key"},
            {"W",   "Write data to a file"},
            {"T",   "Hashtable statistics"},
            {"Q",   "Quit"},
            {"P",   "Hidden print option (do not show it in the menu: print indented tree)"},
            {"Z",   "Hidden option (do not show it in the menu: display names of team members)"},
    };
    printTable(helpWidths, helpData);
}

void printTeam() {
    static const vector<int> teamWidths = {40};
    static const vector<vector<string>> teamData = {
            {"Team Members"},
            {"Kevin Cremin"},
            {"Kevin Galvan Serrano"},
            {"Joshiro Lawrence"},
            {"Tuhin Mondal"},
            {"Iurii Tatishchev"},
    };
    printTable(teamWidths, teamData);
}

void processInput(char command, HashTable<CPU>& table, BinarySearchTree<CPU>& tree, Stack<CPU>& stack);

CPU readCPUInfo();

int main() {
    // Print help table for commands
    printHelp();

    HashTable<CPU> cpuTable;
    BinarySearchTree<CPU> cpuTree;
    Stack<CPU> undoStack;

    char command = ' ';
    while (command != 'Q') {
        cout << "Enter an option (H - for help): ";
        cin >> command;
        // Temporary try catch block to handle unimplemented commands
        try {
            processInput(toupper(command, std::locale()), cpuTable, cpuTree, undoStack);
        } catch (std::logic_error& e) {
            cout << e.what() << '\n';
        }
    }
    // Quit command received
    // TODO: Write data to a file
    cout << "Exiting program...\n";

    return 0;
}

void insertCPU(HashTable<CPU> &hashTable, BinarySearchTree<CPU> &tree);

void processInput(char command, HashTable<CPU> &cpuTable, BinarySearchTree<CPU> &cpuTree, Stack<CPU> &undoStack) {
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
            throw std::logic_error("Not yet implemented: Delete one record");
            break;
        case 'U': // Undo delete
            throw std::logic_error("Not yet implemented: Undo delete");
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

void insertCPU(HashTable<CPU> &hashTable, BinarySearchTree<CPU> &tree) {
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
    tree.insert(cpu);
}
