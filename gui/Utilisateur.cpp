//
// Created by Elia Mazzoni on 28/11/2017.
//

// La classe Utilisateur demande au client son username et le mémorise 


#include "Utilisateur.hpp"
#include <string>
#include <iostream>
#include <list>
#include <QInputDialog>


std::string Utilisateur::askName() {

	// fonction qui demande à l'utilisateur son nom et le renvoie sous forme de string

	// ce booléen tient en compte la possibilité de fermer la fenêtre sans y écrire son nom
	bool dialogResult;


	// QInputDialog sert à demander le nom au client qui utilise l'interface
	QInputDialog *renameDialog = new QInputDialog();
	renameDialog->setTextValue("Test"); 

	// username est le nom du client en format QString
	QString username = renameDialog->getText(0, "Username for fanfaresimulator", "Please insert your username:", QLineEdit::Normal,
		"", &dialogResult);
	

	// nom_client est le nom du client en format string
	std::string nom_client = username.toStdString();

	return nom_client;
}


// fonction qui met le nom en input comme username de la classe Utilisateur
void Utilisateur::addName(std::string clientName) {
	
	this->user_id_name = clientName;
	return;
}

// fonction qui affiche le nom de l'utilisateur
void Utilisateur::printUtilisateur() {
	std::cout << this -> user_id_name << "\n";
	return;
	}

// fonction qui affiche un message de bienvenue pour l'utilisateur
void Utilisateur::printWelcomeMessage() {
	std::cout << "Hi " << this->user_id_name << ", welcome to fanfare simulator!" "\n";
	return;
}


void Utilisateur::printInstrumentMessage() {
	std::cout << "You will have first to choose an instrument and then to play it" "\n";
	return;
}


