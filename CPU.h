#ifndef INC_08_TEAM_PROJECT_CPU_H
#define INC_08_TEAM_PROJECT_CPU_H

#include <string>

class CPU {
private:
    std::string cpuId;
    int releaseYear;
    int coreCount;
    std::string architecture;
    double baseClock;

public:
    CPU() : cpuId(""), releaseYear(0), coreCount(0), architecture(""), baseClock(0.0) {};

    CPU(std::string id, int year, int cores, std::string arch, double clock) :
            cpuId(std::move(id)),
            releaseYear(year),
            coreCount(cores),
            architecture(std::move(arch)),
            baseClock(clock) {};

    [[nodiscard]] std::string getCpuId() const { return cpuId; };

    [[nodiscard]] int getReleaseYear() const { return releaseYear; };

    [[nodiscard]] int getCoreCount() const { return coreCount; };

    [[nodiscard]] std::string getArchitecture() const { return architecture; };

    [[nodiscard]] double getBaseClock() const { return baseClock; };

    void setCpuId(std::string id) { cpuId = std::move(id); };

    void setReleaseYear(int year) { releaseYear = year; }

    void setCoreCount(int cores) { coreCount = cores; };

    void setArchitecture(std::string arch) { architecture = std::move(arch); }

    void setBaseClock(double clock) { baseClock = clock; }

    // Operator overloads
    bool operator<(const CPU &rhs) const {
        return cpuId < rhs.cpuId;
    };

    bool operator>(const CPU &rhs) const {
        return rhs < *this;
    };

    bool operator==(const CPU &rhs) const {
        return cpuId == rhs.cpuId;
    };

    // Friend function declarations
    friend void display(const CPU &cpu);

    friend void iDisplay(const CPU &cpu, int level) {
        for (int i = 1; i < level; i++)
            std::cout << "..";
        std::cout << level << "). " << cpu.cpuId << std::endl;
    };

    friend std::ostream &operator<<(std::ostream &os, const CPU &cpu);

    friend int key_to_index(const CPU &key, int size);

    friend std::string to_string(const CPU &cpu);

};

std::ostream &operator<<(std::ostream &os, const CPU &cpu);

/*~*~*~*
 Hash function: takes the key and returns the index in the hash table
 *~**/
int key_to_index(const CPU &key, int size);

std::string to_string(const CPU &cpu);

#endif // INC_08_TEAM_PROJECT_CPU_H
