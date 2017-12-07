#pragma once

#include <string>
#include <note>
#include "instrument.hpp"

class NoteGlobale {
private:
	std::initializer_list <Note> listOfNotes;
	int key;			// from 0 to 3
	double timestamp;
	bool signal;
	Instrument instrument;

public:
	NoteGlobale();

	NoteGlobale(std::initializer_list <Note> listOfNotes, double timestamp, bool signal);

	~NoteGlobale();

	int get_key();

	double get_timestamp();

	bool get_signal();
	
};