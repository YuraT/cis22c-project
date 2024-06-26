#include <iostream>
#include "CPU.h"
#include "utils.h"

using namespace std;

void display(const CPU &cpu) {

    const int minTotalWidth = max((size_t) 38, cpu.cpuId.length() + 2);
    // Calculate total width, make sure architecture fits
    const vector<int> widths = {18, max(minTotalWidth - 19, (int) cpu.architecture.length() + 2)};
    const int totalWidth = widths[0] + widths[1];
    // CPU ID
    // width is different because bold characters are counted but invisible
    string boldCenteredCpuId = centeredStr(boldStr(cpu.cpuId), totalWidth + 8);
    printTableHeader({totalWidth + 1}, {boldCenteredCpuId});

    // Release Year
    cout << "| ";
    cout.width(widths[0] + 7);
    cout << left << boldStr("Release Year");
    cout << "|";
    cout.width(widths[1] - 1);
    cout << right << cpu.releaseYear;
    cout << " |\n";

    // Core Count
    cout << "| ";
    cout.width(widths[0] + 7);
    cout << left << boldStr("Core Count");
    cout << "|";
    cout.width(widths[1] - 1);
    cout << right << cpu.coreCount;
    cout << " |\n";

    // Architecture
    cout << "| ";
    cout.width(widths[0] + 7);
    cout << left << boldStr("Architecture");
    cout << "|";
    cout.width(widths[1] - 1);
    cout << right << cpu.architecture;
    cout << " |\n";

    // Base Clock
    cout << "| ";
    cout.width(widths[0] + 7);
    cout << left << boldStr("Base Clock (GHz)");
    cout << "|";
    cout.width(widths[1] - 1);
    cout.precision(2);
    cout << fixed << right << cpu.baseClock;
    cout << " |\n";

    printTableFooter(widths);
}

void iDisplay(const string &cpuId, int level) {
    for (int i = 0; i < level; i++)
        cout << "..";
    cout << level << ")." << cpuId << endl;
}

void rowDisplay(const CPU &cpu, const vector<int> &widths) {
    cout << "| ";
    cout.width(widths[0] - 1);
    cout << left << cpu.cpuId;
    cout << "|";

    cout.width(widths[1] - 1);
    cout << right << cpu.releaseYear;
    cout << " |";

    cout.width(widths[2] - 1);
    cout << right << cpu.coreCount;
    cout << " | ";

    cout.width(widths[3] - 1);
    cout << left << cpu.architecture;
    cout << "|";

    cout.width(widths[4] - 1);
    cout.precision(2);
    cout << fixed << right << cpu.baseClock;
    cout << " |\n";
}

ostream &operator<<(ostream &os, const CPU &cpu) {
    os << "CPU ID: " << cpu.cpuId << endl;
    return os;
}

int key_to_index(const CPU &key, int size) {
    string k = key.getCpuId();
    int sum = 0;
    for (int i = 0; k[i]; i++)
        sum += k[i];
    return sum % size;
}

string to_string(const CPU &cpu) {
    return cpu.cpuId + "; " +
           to_string(cpu.releaseYear) + "; " +
           to_string(cpu.coreCount) + "; " +
           cpu.architecture + "; " +
           to_string(cpu.baseClock) + ";";
}
