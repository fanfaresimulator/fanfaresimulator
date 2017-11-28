#pragma once

#include <iostream>

#include "note.hpp"
#include "instrument.hpp"

class Partition {
private:
	std::initializer_list <Note> listOfNotes;

public:
	Partition();

	~Partition();

	std::initializer_list <Note> getNotes();


	Partition getPartition(Instrument instrument);

	double getLength (); // Partition length

	std::initializer_list <double> frameDivision (double endTime) // Divide time in frames.

};
