//
// Created by Elia Mazzoni on 28/11/2017.
//

#pragma once
#include <string>

// La classe Utilisateur demande au client son username et le mémorise 

class Utilisateur {

public:
	std::string  user_id_name;

	void printUtilisateur();
	void printWelcomeMessage();
	void printInstrumentMessage();
	std::string askName();
	void addName(std::string clientName);
	

protected:

private:

};



