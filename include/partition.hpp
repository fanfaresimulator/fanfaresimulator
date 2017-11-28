#pragma once

#include <iostream>
#include <list>
#include <cstdlib>

#include "note.hpp"
#include "instrument.hpp"

class Partition {
private:
	std::list <Note> listOfNotes;
	
	const double minFrameLength = 0.5; // Minimum frame duration
	const double maxFrameLength = 3.0; // Maximum frame duration



public:
	Partition();

	Partition(std::list<Note> listOfNotes);

	~Partition();

	std::list <Note> getNotes();


	Partition getPartition(Instrument instrument); // What is that function? What does it should do?

	double getLength(); // Partition length

	std::list <double> frameDivision(); // Divide time in frames.

										// Gives back events (notes) from time startTime to endTime
	//std::list <Note> getPartitionInFrame(double startTime, double endTime);

	// Gives back the partition from startTime to endTime, completing notes starting or ending
	// before of after the current frame.
	std::list <Note> buildPartitionInFrame(double startTime, double endTime);

};

