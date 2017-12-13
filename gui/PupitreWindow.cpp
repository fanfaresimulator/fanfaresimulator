#include "../include/gui/PupitreWindow.hpp"

PupitreWindow::PupitreWindow(std::vector<Pupitre> pupitres) : QWidget() {
	this->pupitres = pupitres;

	QGroupBox *groupBox = new QGroupBox("Instruments :", this);
	groupBox->setAlignment(Qt::AlignRight);

	QVBoxLayout *vBox = new QVBoxLayout;

	for (size_t i = 0; i < pupitres.size(); i++) {
		std::string nameInstru = pupitres[i].getInstrument().getName();
		QRadioButton *b = new QRadioButton(QString(nameInstru.c_str()));
		buttons.push_back(b);
		vBox->addWidget(b);
	}

	groupBox->setLayout(vBox);

	QPushButton *valider = new QPushButton("Valider l'instrument");
	QObject::connect(valider, &QPushButton::clicked, this, &PupitreWindow::choosePupitre);

	QVBoxLayout *vBoxFen = new QVBoxLayout;
	vBoxFen->addWidget(groupBox);
	vBoxFen->addWidget(valider);
	this->setLayout(vBoxFen);
}

void PupitreWindow::choosePupitre() {
	for (size_t i = 0; i < buttons.size(); i++) {
		if (buttons[i]->isChecked()) {
			Pupitre p = this->pupitres[i];
			std::cout << "Instrument avec lequel vous allez jouer : "<< p.getInstrument().getName() << std::endl;
			this->hide();
			emit pupitreChosen(p);
			break;
		}
	}
}
