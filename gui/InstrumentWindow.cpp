#include "../include/InstrumentWindow.hpp"
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <QString>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QPushButton>

using namespace std;

InstrumentWindow::InstrumentWindow() : QWidget() {
	QGroupBox *groupBox = new QGroupBox("Instruments :", this);
	groupBox->setAlignment(Qt::AlignRight);

	QVBoxLayout *vBox = new QVBoxLayout;

	for (int i = 0; i < nbInstru; i++) {
		std::string nameInstru = instruList[i];
		QRadioButton *b = new QRadioButton(QString(nameInstru.c_str()));
		buttons.push_back(b);
		vBox->addWidget(b);
	}

	groupBox->setLayout(vBox);
	QPushButton *valider = new QPushButton;
	QVBoxLayout *vBoxFen = new QVBoxLayout;

	QObject::connect(valider, &QPushButton::clicked, this, &InstrumentWindow::printInstrumentChosen);

	vBoxFen->addWidget(groupBox);
	vBoxFen->addWidget(valider);
	this->setLayout(vBoxFen);

	this->show();
}

void InstrumentWindow::chooseInstrument() {
	//std::cout << i2->isChecked() << std::endl;
}


void InstrumentWindow::printInstrumentChosen() {
	
	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i]->isChecked()) {
			std::cout << i << std::endl;
			emit instrumentChosen(i);
			break;
		}
	}
	this->hide();
}



