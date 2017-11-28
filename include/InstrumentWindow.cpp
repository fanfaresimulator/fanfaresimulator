#include "InstrumentWindow.hpp"
#include <string>
#include <map>
#include <list>
#include <QGroupBox>
using namespace std;


const std::vector<std::string> instruList = { "violon", "guitare", "violoncelle", "piano" };

std::string InstrumentWindow::chooseInstrument() {
	QWidget fenetre;

	QGroupBox *groupBox = new QGroupBox("Instruments :", &fenetre);
	groupBox->setAlignment(Qt::AlignRight);

	QRadioButton *i1 = new QRadioButton("Guitare");
	QRadioButton *i2 = new QRadioButton("Piano");
	QRadioButton *i3 = new QRadioButton("Violon");
	QRadioButton *i4 = new QRadioButton("Violoncelle");
	QVBoxLayout *vBox = new QVBoxLayout;
	vBox->addWidget(i1);
	vBox->addWidget(i2);
	vBox->addWidget(i3);
	vBox->addWidget(i4);
	groupBox->setLayout(vBox);
	QPushButton bouton("Valider", &fenetre);
	QVBoxLayout *vBoxFen = new QVBoxLayout;

	vBoxFen->addWidget(groupBox);
	vBoxFen->addWidget(&bouton);
	fenetre.setLayout(vBoxFen);

	fenetre.show();
}


void InstrumentWindow::printInstrumentChosen() {

}



