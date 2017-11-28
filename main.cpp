#include <QApplication>
#include <QtWidgets/QApplication>
#include "gui/testwindow.hpp"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsView>
#include <iostream>
#include <QTextEdit>
#include <QInputDialog>
#include <QString>
#include "gui/Utilisateur.hpp"
#include "include/InstrumentWindow.hpp"

int main(int argc, char* argv[]) {
	
	QApplication app{ argc, argv };

	Utilisateur current; 


	std::string premier = current.askName();

	current.addName(premier);

	current.printWelcomeMessage();
	current.printInstrumentMessage();

	InstrumentWindow win;
	
	return app.exec();	
}

