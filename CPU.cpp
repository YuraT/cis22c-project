#include <iostream>
#include "CPU.h"

using std::string, std::ostream, std::endl;

ostream &operator<<(ostream &os, const CPU &cpu) {
    os << "CPU ID: " << cpu.cpuId << std::endl;
    return os;
}

int key_to_index(const CPU &key, int size) {
    std::string k = key.getCpuId();
    int sum = 0;
    for (int i = 0; k[i]; i++)
        sum += k[i];
    return sum % size;
}

std::string to_string(const CPU &cpu) {
    return cpu.cpuId + "; " +
           std::to_string(cpu.releaseYear) + "; " +
           std::to_string(cpu.coreCount) + "; " +
           cpu.architecture + "; " +
           std::to_string(cpu.baseClock) + ";";
}
