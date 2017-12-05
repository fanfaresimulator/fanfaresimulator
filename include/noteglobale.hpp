#pragma once

#include <string>
#include <list>
#include "note.hpp"
#include "pupitre.hpp"

class NoteGlobale {
private:
	std::list <Note> listOfNotes;
	int key;			// from 1 to 4
	double timestamp;
	bool signal;
	Pupitre pupitre;

public:
	NoteGlobale();

	NoteGlobale(std::list <Note> listOfNotes, int key, double timestamp, bool signal, Pupitre pupitrenew);

	//~NoteGlobale();
	
};