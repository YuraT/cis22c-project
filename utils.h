#ifndef INC_08_TEAM_PROJECT_UTILS_H
#define INC_08_TEAM_PROJECT_UTILS_H

#include <vector>
#include <string>

using std::vector, std::string;

void printRow(const vector<int> &widths, const vector<string> &row);

void printTableHeader(const vector<int> &widths, const vector<string> &headers);

void printTableFooter(const vector<int> &widths);

void printTable(const vector<int> &widths, const vector<vector<string>> &data);

void printHelp();

void printTeam();

int findNextPrime(int n);

string boldStr(const string &str);

string centeredStr(const string &str, int width);

#endif //INC_08_TEAM_PROJECT_UTILS_H
