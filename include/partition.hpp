#pragma once

#include <iostream>

#include "note.hpp"
#include "instrument.hpp"

class Partition {
private:
	std::initializer_list <Note> listOfNotes;

public:
	Partition();

	Partition (std::initializer_list <Note> listOfNotes);

	~Partition();

	std::initializer_list <Note> getNotes();


	Partition getPartition(Instrument instrument);

	double getLength (); // Partition length

	std::initializer_list <double> frameDivision (double endTime); // Divide time in frames.

	// Gives back events (notes) from time startTime to endTime
	std::initializer_list <Note> getPartitionInFrame (double startTime, double endTime);

	// Gives back the partition from startTime to endTime, completing notes starting or ending
	// before of after the current frame.
	std::initializer_list <Note> buildPartitionInFrame (double startTime, double endTime);

};

