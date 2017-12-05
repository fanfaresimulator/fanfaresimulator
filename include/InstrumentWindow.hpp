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

	std::vector<std::string> instruList;
	std::vector<QRadioButton*> buttons = {};

	InstrumentWindow(std::vector<std::string> instruList);

	

	
	
	void printInstrumentChosen();

	void showpicture();

signals:
	void instrumentChosen(int i);
};


#endif //FANFARESIMULATOR_INSTRUMENT_HPP
