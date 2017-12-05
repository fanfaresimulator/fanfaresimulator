#pragma once

#include <string>
#include <note>
//#include "instrument.hpp"
#include "pupitre.hpp"

class NoteGlobale {
private:
	std::list <Note> listOfNotes;
	int key;			// from 0 to 3
	double timestamp;
	bool signal;
	Pupitre pupitre;

public:
	NoteGlobale();

	NoteGlobale(std::list <Note> listOfNotes, int key, double timestamp, bool signal, Pupitre pupitrenew);

	~NoteGlobale();
	
};
