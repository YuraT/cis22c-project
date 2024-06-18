#include <iostream>
#include "utils.h"
using std::cout;

void printRow(const vector<int> &widths, const vector<string>& row) {
    cout << '|';
    for (int i = 0; i < widths.size(); i++) {
        cout << ' ';
        cout.width(widths[i] - 1);
        cout << std::left << row[i];
        cout << '|';
    }
    cout << '\n';
};

/*
 * Print ascii/unicode table with given column widths and data. For example:
 * ┌────────────────────────────────────────┬──────────┬────────────────────────┬────────────────┐
 * | Col1                                   | Col2     | Col3                   | Numeric Column |
 * +========================================+==========+========================+================+
 * | Value 1                                | Value 2  | 123                    | 10.0           |
 * | Separate                               | cols     | with a tab or 4 spaces | -2,027.1       |
 * | This is a row with only one cell       |          |                        |                |
 * └────────────────────────────────────────┴──────────┴────────────────────────┴────────────────┘
 */
void printTable(const vector<int>& widths, const vector<vector<string>>& data) {
    // Print top border
    cout << "┌";
    for (int width : widths) {
        for (int i = 0; i < width; i++) {
            cout << "─";
        }
        cout << "┬";
    }
    cout << "\b┐\n";

    // Print header
    cout << '|';
    for (int i = 0; i < widths.size(); i++) {
        cout << ' ';
        cout.width(widths[i] - 1);
        cout << std::left << data[0][i];
        cout << '|';
    }
    cout << '\n';

    // Print middle border
    cout << '+';
    for (int width : widths) {
        for (int i = 0; i < width; i++) {
            cout << '=';
        }
        cout << '+';
    }
    cout << '\n';

    // Print data
    for (int i = 1; i < data.size(); i++) {
        printRow(widths, data[i]);
    }

    // Print bottom border
    cout << "└";
    for (int width : widths) {
        for (int i = 0; i < width; i++) {
            cout << "─";
        }
        cout << "┴";
    }
    cout << "\b┘\n";
}

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

int findNextPrime(int n) {
    if (n < 5) {
        return 5;
    }

    bool found = false;

    while (!found) {
        // Every prime number occurs only 1 number before or after a multiple of six.  Every other number is divisible by either 2 or 3.
        if ((n % 6) == 1) {
            n += 4;
        } else if ((n % 6) == 5) {
            n += 2;
        } else if ((n % 6) >= 2) {
            n = n - (n % 6) + 5;
        } else {
            n += 1;
        }

        found = true;
        for (int i = 5; i < n / 2;) {
            if (n % i == 0) {
                found = false;
                break;
            }

            i += 2;

            if (n % i == 0) {
                found = false;
                break;
            }

            i += 4;
        }
    }

    return n;
}
