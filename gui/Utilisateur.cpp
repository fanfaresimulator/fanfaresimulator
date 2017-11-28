//
// Created by Elia Mazzoni on 28/11/2017.
//

#include "Utilisateur.hpp"
#include <string>
#include <iostream>
#include <list>
#include <QInputDialog>


std::string Utilisateur::askName() {

	// fonction qui demande à l'utilisateur son nom et le renvoie sous forme de string

	//QApplication app{ argc, argv };

	bool dialogResult;


	// QInputDialog sert à demander le nom au client qui utilise l'interface
	QInputDialog *renameDialog = new QInputDialog();
	renameDialog->setTextValue("Test"); // has no effect

	//renameDialog -> show();
	// username est le nom du client en format QString
	QString username = renameDialog->getText(0, "Rename Label", "username:", QLineEdit::Normal,
		"", &dialogResult);
	

	// nom_client est le nom du client en format string


	//std::string nom_client = username.toLocal8Bit().constData();

	std::string nom_client = username.toStdString();


	//std::cout << username << std::endl;   //This is not being ouputted. 
	//MainWindow w;
	
	//app -> close();

	return nom_client;
}

void Utilisateur::addName(std::string clientName) {
	
	this->user_id_name = clientName;
	return;
}//

//void Utilisateur::removeName() {
	// fonction qui élimine le nom de l'utilisateur de la liste globale
//	this -> user_id_name = NULL;
	//return;
//}

void Utilisateur::printUtilisateur() {
	std::cout << this -> user_id_name << "\n";
	return;
	}


