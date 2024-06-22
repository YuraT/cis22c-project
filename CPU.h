// CPU class
//
// Written by: Kevin Galvan Serrano
// Modified by: Iurii Tatishchev

#ifndef INC_08_TEAM_PROJECT_CPU_H
#define INC_08_TEAM_PROJECT_CPU_H

#include <string>
#include <vector>

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

    friend void iDisplay(const CPU &cpu, int level);

    // Display the CPU object as a table row
    friend void rowDisplay(const CPU &cpu, const std::vector<int> &widths);

    friend std::ostream &operator<<(std::ostream &os, const CPU &cpu);

    friend int key_to_index(const CPU &key, int size);

    friend std::string to_string(const CPU &cpu);

};

/*
 * Display the CPU object as a table.
 *
 * Written by: Iurii Tatishchev
 */
void display(const CPU &cpu);

/*
 * Display the CPU object as part of an indented tree.
 *
 * Written by: Tuhin Mondal
 */
void iDisplay(const std::string &cpuId, int level);

/*
 * Display the CPU object as a table row.
 *
 * Written by: Iurii Tatishchev
 */
void rowDisplay(const CPU &cpu, const std::vector<int> &widths);

/*
 * Overload the << operator to display the CPU object.
 *
 * Written by: Iurii Tatishchev
 */
std::ostream &operator<<(std::ostream &os, const CPU &cpu);

/*~*~*~*
 Hash function: takes the key and returns the index in the hash table.

 Written by: Joshiro Lawrence
 *~**/
int key_to_index(const CPU &key, int size);

/*~*~*~*
 Converts the CPU object to a string.

 Written by: Iurii Tatishchev
 *~**/
std::string to_string(const CPU &cpu);

#endif // INC_08_TEAM_PROJECT_CPU_H
