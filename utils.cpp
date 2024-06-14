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
