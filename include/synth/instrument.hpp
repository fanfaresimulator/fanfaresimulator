#pragma once

#include <string>

class Instrument {
private:
    int number;
    std::string name;

public:
    Instrument(int number);
    int getNumber();
    std::string getName();
    bool isEqual(Instrument i2);
    bool operator==(const Instrument &other);
    bool operator<(const Instrument &other);
};
