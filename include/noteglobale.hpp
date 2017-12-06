#pragma once

#include <string>
#include <vector>
#include "note.hpp"
#include "pupitre.hpp"
#include "partition.hpp"

#define  USER_TOLL (MIN_FRAME_LENGTH/4) // Tolerace donnee a l'utilisateur
                                        // en appuyant les touches


class NoteGlobale {
private:
	std::vector <Note> listOfNotes;
	int key;			// from 1 to 4
	double timestamp;
	bool signal;
	Pupitre pupitre;

public:
	NoteGlobale();

	NoteGlobale(std::vector <Note> listOfNotes, int key, double timestamp, bool signal, Pupitre pupitrenew);

	bool getSignal();

	double getTime();

	int getKey();

	//~NoteGlobale();

	std::vector <Note>* getListOfNotes();
	
};
