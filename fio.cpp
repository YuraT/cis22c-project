#include <sstream>
#include "fio.h"

bool isInteger(const string &str);

bool isDouble(const string &str);

using std::stringstream, std::ifstream, std::getline, std::cout, std::endl, std::stoi, std::stod, std::cin;

int findHashSize(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error opening the input file: \"" << filename << "\"" << endl;
        return -1;
    }
    cout << "Reading data from \"" << filename << "\"" << endl;

    int count = 0;
    string line;
    while (getline(inputFile, line)) {
        if (line.size() != 0) {
            count++;
        }
    }

    count *= 2;

    if (count < 5) {
        return 5;
    }

    bool found = false;

    while (!found) {
        // Every prime number occurs only 1 number before or after a multiple of six.  Every other number is divisible by either 2 or 3.
        if ((count % 6) == 1) {
            count += 4;
        } else if ((count % 6) == 5) {
            count += 2;
        } else if ((count % 6) >= 2) {
            count = count - (count % 6) + 5;
        } else {
            count += 1;
        }

        found = true;
        for (int i = 5; i < count / 2;) {
            if (count % i == 0) {
                found = false;
                break;
            }

            i += 2;

            if (count % i == 0) {
                found = false;
                break;
            }

            i += 4;
        }
    }

    return count;
}

void insertFile(const string& filename, BinarySearchTree<string> &bst, HashTable<CPU> &hash) {
    ifstream inputFile(filename);
    cout << "Reading data from \"" << filename << "\"" << endl;

    if (!inputFile) {
        cout << "Error opening the input file: \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(inputFile, line)) {
        int releaseYear, coreCount;
        string name, architecture, strToNum;
        double baseClock;

        stringstream temp(line);

        getline(temp, name, ';');

        temp.ignore();
        getline(temp, strToNum, ';');
        releaseYear = stoi(strToNum);

        temp.ignore();
        getline(temp, strToNum, ';');
        coreCount = stoi(strToNum);

        temp.ignore();
        getline(temp, architecture, ';');

        temp.ignore();
        getline(temp, strToNum, ';');
        baseClock = stod(strToNum);


        // create a CPU object and initialize it with data from file
        CPU aCPU(name, releaseYear, coreCount, architecture, baseClock);
        bst.insert(name);

        hash.insert(aCPU, key_to_index);
    }

    inputFile.close();
}


void insertCPU(BinarySearchTree<string> &bst, HashTable<CPU> &hash) {
    string tester, name, architecture;
    int releaseYear, coreCount;
    double baseClock;

    cout << "Please enter the name of the CPU: ";
    cin >> name;

    CPU key(name, -1, -1, "", -1);
    CPU checker;

    if (hash.search(checker, key, key_to_index) != -1) {
        cout << "Duplicate CPUs are not allowed!\n";
        return;
    }


    cout << "Please enter the year the CPU was released: ";
    cin >> tester;

    while (!(isInteger(tester))) {
        cout << "Please enter an integer: ";
        cin >> tester;
    }

    releaseYear = stoi(tester);


    cout << "Please enter the number of cores in the CPU: ";
    cin >> tester;

    while (!(isInteger(tester))) {
        cout << "Please enter an integer: ";
        cin >> tester;
    }

    coreCount = stoi(tester);


    // Strings don't need to be tested
    cout << "Please enter the architecture of the CPU: ";
    cin >> architecture;


    cout << "Please enter the base clock of the CPU: ";
    cin >> tester;

    while (!(isDouble(tester))) {
        cout << "Please enter a decimal: ";
        cin >> tester;
    }

    baseClock = stod(tester);


    CPU aCPU(name, releaseYear, coreCount, architecture, baseClock);
    bst.insert(name);

    hash.insert(aCPU, key_to_index);
}

bool isInteger(const string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (!(isdigit(str[i]))) {
            return false;
        }
    }

    return true;
}

bool isDouble(const string& str) {
    int chance = 0;

    for (int i = 0; i < str.length(); i++) {
        if (!(isdigit(str[i]))) {
            if (str[i] == '.') {
                if (chance >= 1) {
                    return false;
                } else {
                    chance++;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}