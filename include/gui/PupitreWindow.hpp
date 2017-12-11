#pragma once

#include <string>
#include <map>
#include <vector>
#include <QWidget>
#include <QRadioButton>
#include <list>
#include <iostream>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>

#include "../include/synth/pupitre.hpp"

class PupitreWindow : public QWidget {
	Q_OBJECT
public:
	PupitreWindow(std::vector<Pupitre> pupitres);

signals:
	void pupitreChosen(Pupitre p);

private:
	std::vector<Pupitre> pupitres;
	std::vector<QRadioButton*> buttons;

	void choosePupitre();
};
