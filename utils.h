// Contains utility functions mostly for printing tables and formatting.
// Written by: Iurii Tatishchev

#ifndef INC_08_TEAM_PROJECT_UTILS_H
#define INC_08_TEAM_PROJECT_UTILS_H

#include <vector>
#include <string>

using namespace std;

/*
 * Print a single row of a table, given the widths of each column and the data for the row.
 *
 * Example output:
 * | Value 1                                | Value 2  | 123                    | 10.0           |
 */
void printRow(const vector<int> &widths, const vector<string> &row);

/*
 * Print the header of a table, given the widths of each column and the headers for each column.
 * Unicode characters are used to draw the table.
 *
 * Example output:
 * ┌────────────────────────────────────────┬──────────┬────────────────────────┬────────────────┐
 * | Col1                                   | Col2     | Col3                   | Numeric Column |
 * +========================================+==========+========================+================+
 */
void printTableHeader(const vector<int> &widths, const vector<string> &headers);

/*
 * Print the footer of a table, given the widths of each column.
 *
 * Example output:
 * └────────────────────────────────────────┴──────────┴────────────────────────┴────────────────┘
 */
void printTableFooter(const vector<int> &widths);

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
void printTable(const vector<int> &widths, const vector<vector<string>> &data);

/*
 * Print a help table with all available commands and their descriptions.
 */
void printHelp();

/*
 * Print a table with the team members and their roles.
 */
void printTeam();

/*
 * Find the next prime number after n.
 *
 * Written by: Kevin Cremin
 * Modified by: Iurii Tatishchev
 */
int findNextPrime(int n);

/*
 * Add bold control characters around a string for terminal output.
 */
string boldStr(const string &str);

/*
 * Pad a string with spaces on both sides to center it in a string of a given width.
 */
string centeredStr(const string &str, int width);

#endif //INC_08_TEAM_PROJECT_UTILS_H
