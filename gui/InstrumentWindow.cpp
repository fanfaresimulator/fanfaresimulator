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
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>


using namespace std;

InstrumentWindow::InstrumentWindow(std::vector<std::string> allInstru) : QWidget() {
	this->instruList = allInstru;

	//showpicture();
	QGroupBox *groupBox = new QGroupBox("Instruments :", this);
	groupBox->setAlignment(Qt::AlignRight);

	QVBoxLayout *vBox = new QVBoxLayout;

	for (int i = 0; i < instruList.size(); i++) {
		std::string nameInstru = instruList[i];
		QRadioButton *b = new QRadioButton(QString(nameInstru.c_str()));
		buttons.push_back(b);
		vBox->addWidget(b);
	}

	groupBox->setLayout(vBox);
	QPushButton *valider = new QPushButton("Valider l'instrument");
	QVBoxLayout *vBoxFen = new QVBoxLayout;

	//QPushButton valider("Valider l'instrument");
	QObject::connect(valider, &QPushButton::clicked, this, &InstrumentWindow::printInstrumentChosen);

	vBoxFen->addWidget(groupBox);
	vBoxFen->addWidget(valider);
	this->setLayout(vBoxFen);

	this->show();
}

void InstrumentWindow::showpicture() {
	//QGraphicsScene scene;
	//QGraphicsView view(&scene);
	//QGraphicsPixmapItem item(QPixmap("..\\resources\\musical-instruments-intro.jpg"));
	//scene.addItem(&item);
	//view.show();
	//return;

	
}

void InstrumentWindow::printInstrumentChosen() {
	
	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i]->isChecked()) {
			std::cout << "Instrument avec lequel vous allez jouer : "<< this->instruList[i] << std::endl;
			emit instrumentChosen(i);
			break;
		}
	}
	this->hide();
}



