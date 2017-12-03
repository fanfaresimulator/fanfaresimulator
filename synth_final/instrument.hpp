// VIELLE CLASSE DE STEVEN
//#pragma once

//typedef int Instrument;
// enum Instrument{
//
// };

#pragma once

#include <string>

class Instrument {
private:
    int number;
    std::string name;

public:
    Instrument(int number);

    int getNumber();

    std::string getname();

    bool isEqual(Instrument i2);
};
