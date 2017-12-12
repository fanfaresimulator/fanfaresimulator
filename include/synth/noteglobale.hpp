#pragma once

#include <string>
#include <vector>
#include "note.hpp"
#include "pupitre.hpp"
#include "partition.hpp"

#define  USER_TOLL (MIN_FRAME_LENGTH/3) // Tolerace donnee a l'utilisateur
                                        // en appuyant les touches

class NoteGlobale {
private:
	std::vector <Note> listOfNotes;
	int key; // from 0 to 4
	double timestamp;
	bool signal;
	Pupitre pupitre;

public:
	NoteGlobale(std::vector <Note> listOfNotes, int key, double timestamp, bool signal, Pupitre pupitrenew);
	bool getSignal();
	double getTime();
	int getKey();
	std::vector <Note>* getListOfNotes();
};
