#include "instrument.hpp"
#include <string>
#include <map>
#include <list>
using namespace std;

class Instrument {
public:
	//fonction qui initialise tous les instruments disponibles
	map<string, string> Instrument::initInstru() {
		map<string, string> listeInstru;
		listeInstru['violon'] = NULL;
		listeInstru['violoncelle'] = NULL;
		listeInstru['piano'] = NULL;
		listeInstru['alto'] = NULL;
		return listeInstru;
	};

	//fonction qui va récuperer le username de celui utilisant instru
	std::string Instrument::getUsername(std::string instru, map<string, string> listeInstru) {
		return listeInstru[instru];
	};

	//fonction qui va sélectionner l'instrument instru_choisi pour l'username, et rendre instru_choisi indisponible
	map<string, string> Instrument::setInstru(std::string instru_choisi, std::string username, map<string, string> listeInstru) {
		listeInstru[instru_choisi] = username;
		return listeInstru;
	};

	//fonction qui rend instru libre à nouveau
	void Instrument::unsetInstru(std::string instru, map<string, string> listeInstru) {
		listeInstru[instru_choisi] = NULL;
		return listeInstru;
	};

	//fonction qui renvoie tous les instruments disponibles
	map<string, string> Instrument::getAvailableInstru(map<string, string> listeInstru) {
		std::list<string> instruAvailable;
		for (int i = 0; i < listeInstru.length(); i++) {
			if (listeInstru[i] == NULL){
				instruAvailable.push_front(i);
			};
		}
		return instruAvailable;
	};


};

