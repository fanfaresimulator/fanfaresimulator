#pragma once

#include <string>
#include <map>
#include <vector>
#include <QWidget>
#include <QRadioButton>

using namespace std;

class InstrumentWindow : public QWidget {
	Q_OBJECT
public:
	InstrumentWindow();

	std::vector<std::string> instruList = {"violon", "guitare", "violoncelle", "piano"};
	//liste vide de radio button a ajouter dans le cpp
	std::vector<QRadioButton*> buttons = {};

	void printInstrumentChosen();
signals:
	void instrumentChosen(int i);
};
