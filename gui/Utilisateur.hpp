//
// Created by Elia Mazzoni on 28/11/2017.
//

#pragma once
#include <string>



class Utilisateur {

public:
	std::string  user_id_name;

	void printUtilisateur();
	std::string askName();
	//void removeName();
	void addName(std::string clientName);
	

protected:

private:

};



