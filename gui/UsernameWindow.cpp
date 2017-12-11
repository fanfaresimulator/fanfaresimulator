#include "../include/gui/UsernameWindow.hpp"


std::string UsernameWindow::askName() {

	bool dialogResult;

	// QInputDialog sert � demander le nom au client qui utilise l'interface
	QInputDialog *renameDialog = new QInputDialog();
	renameDialog->setTextValue("Test");

	// username est le nom du client en format QString
	QString username = renameDialog->getText(0, "Username for fanfaresimulator", "Please insert your username:", QLineEdit::Normal,
		"", &dialogResult);


	// nom_client est le nom du client en format string
	std::string nom_client = username.toStdString();

	return nom_client;
}


// fonction qui met le nom en input comme username de la classe UsernameWindow
void UsernameWindow::addName(std::string clientName) {

	this->user_id_name = clientName;
	return;
}

// fonction qui affiche le nom de l'utilisateur
void UsernameWindow::printUtilisateur() {
	std::cout << this -> user_id_name << "\n";
	return;
	}

// fonction qui affiche un message de bienvenue pour l'utilisateur
void UsernameWindow::printWelcomeMessage() {
	std::cout << "Hi " << this->user_id_name << ", welcome to fanfare simulator!" "\n";
	return;
}


void UsernameWindow::printInstrumentMessage() {
	std::cout << "You will have first to choose an instrument and then to play it" "\n";
	return;
}
