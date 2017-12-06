#pragma once

#include <string>

class Instrument {
private:
    int number;
    std::string name;

public:
    Instrument();

    Instrument(int number);

    int getNumber();

    std::string getname();

    bool isEqual(Instrument i2);

    bool operator==(const Instrument &other);

    bool operator<(const Instrument &other);
};
