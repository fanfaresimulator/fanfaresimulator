#include "../include/InstrumentWindow.hpp"
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QPushButton>

using namespace std;

InstrumentWindow::InstrumentWindow() : QWidget() {
	QGroupBox *groupBox = new QGroupBox("Instruments :", this);
	groupBox->setAlignment(Qt::AlignRight);

	i1 = new QRadioButton("Guitare");
	QRadioButton *i2 = new QRadioButton("Piano");
	QRadioButton *i3 = new QRadioButton("Violon");
	QRadioButton *i4 = new QRadioButton("Violoncelle");
	QVBoxLayout *vBox = new QVBoxLayout;
	vBox->addWidget(i1);
	vBox->addWidget(i2);
	vBox->addWidget(i3);
	vBox->addWidget(i4);
	groupBox->setLayout(vBox);
	QPushButton *valider = new QPushButton;
	QVBoxLayout *vBoxFen = new QVBoxLayout;

	QObject::connect(valider, &QPushButton::clicked, this, &InstrumentWindow::chooseInstrument);

	vBoxFen->addWidget(groupBox);
	vBoxFen->addWidget(valider);
	this->setLayout(vBoxFen);

	this->show();
}

void InstrumentWindow::chooseInstrument() {
	std::cout << i1->isChecked() << std::endl;
}


void InstrumentWindow::printInstrumentChosen() {

}



