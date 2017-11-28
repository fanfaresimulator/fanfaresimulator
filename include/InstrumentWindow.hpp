//
// Created by steven athouel on 16/11/2017.
//

#include <string>
#include <map>
#include <vector>
using namespace std;

#ifndef FANFARESIMULATOR_INSTRUMENT_HPP
#define FANFARESIMULATOR_INSTRUMENT_HPP

class InstrumentWindow {

public:
	const std::vector<std::string> instruList = {"violon", "guitare", "violoncelle", "piano"};


	std::string chooseInstrument();
	void printInstrumentChosen();


};


#endif //FANFARESIMULATOR_INSTRUMENT_HPP
