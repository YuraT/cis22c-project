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
    CPU(std::string id, int year, int cores, std::string arch, double clock) :
            cpuId(std::move(id)),
            releaseYear(year),
            coreCount(cores),
            architecture(std::move(arch)),
            baseClock(clock) {};

    std::string getCpuId() const;

    int getReleaseYear() const;

    int getCoreCount() const;

    std::string getArchitecture() const;

    double getBaseClock() const;

    void setCpuId(std::string id);

    void setReleaseYear(int year);

    void setCoreCount(int cores);

    void setArchitecture(std::string arch);

    void setBaseClock(double clock);

    // Operator overloads
    bool operator<(const CPU &rhs) const;

    bool operator>(const CPU &rhs) const;

    bool operator==(const CPU &rhs) const;

    // Friend function declarations
    friend void display(const CPU &cpu);

    friend void iDisplay(const CPU &cpu, int level);

    friend std::ostream &operator<<(std::ostream &os, const CPU &cpu);

    friend int key_to_index(const CPU &key, int size);
};

int key_to_index(const CPU &key, int size) {
    // TODO
    return key.coreCount % size;
};

#endif //INC_08_TEAM_PROJECT_CPU_H
