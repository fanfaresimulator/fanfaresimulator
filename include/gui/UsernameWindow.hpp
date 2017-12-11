#pragma once

#include <string>
#include <iostream>
#include <list>
#include <QInputDialog>

// La classe UsernameWindow demande au client son username et le mémorise
class UsernameWindow {

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
