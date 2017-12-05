#pragma once

#include <string>
#include <note>
#include "instrument.hpp"

class NoteGlobale {
private:
	std::list <Note> listOfNotes;
	int key;			// from 0 to 3
	double timestamp;
	bool signal;
	Instrument instrument;

public:
	NoteGlobale();

	NoteGlobale(std::list <Note> listOfNotes, int key, double timestamp, bool signal);

	~NoteGlobale();
	
};
