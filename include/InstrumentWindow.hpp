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

	int nbInstru = 4;

	std::vector<std::string> instruList = {"violon", "guitare", "violoncelle", "piano"};
	//liste vide de radio button a ajouter dans le cpp
	std::vector<QRadioButton*> buttons = {};
	
	void printInstrumentChosen();
signals:
	void instrumentChosen(int i);
};


#endif //FANFARESIMULATOR_INSTRUMENT_HPP
