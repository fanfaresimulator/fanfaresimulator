//
// Created by steven athouel on 16/11/2017.
//

#include <string>
#include <map>
#include <vector>
#include <QWidget>
#include <QRadioButton>
using namespace std;

#ifndef FANFARESIMULATOR_INSTRUMENT_HPP
#define FANFARESIMULATOR_INSTRUMENT_HPP

class InstrumentWindow : public QWidget {

public:
	InstrumentWindow();

	const std::vector<std::string> instruList = {"violon", "guitare", "violoncelle", "piano"};
	QRadioButton *i1;

	void chooseInstrument();
	void printInstrumentChosen();
};


#endif //FANFARESIMULATOR_INSTRUMENT_HPP
