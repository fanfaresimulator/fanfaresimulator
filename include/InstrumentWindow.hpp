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

	std::vector<std::string> instruList;
	std::vector<QRadioButton*> buttons = {};

	InstrumentWindow(std::vector<std::string> instruList);	

	void printInstrumentChosen();

signals:
	void instrumentChosen(int i);
};
