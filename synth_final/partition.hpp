#pragma once

#include <iostream>
#include <list>
#include <cstdlib>

#include "note.hpp"
#include "midi_handler.hpp"

#define  MIN_FRAME_LENGTH 0.5; // Minimum frame duration
#define  MAX_FRAME_LENGTH 0.5; // Maximum frame duration

class Partition {
private:
	std::vector<Note> listOfNotes;
  std::vector<Pupitre> listOfPupitres;

public:

  Partition();

	Partition(std::vector<Note> listOfNotes);

  Partition(std::string midiFileName);

	~Partition();

	std::vector<Note> getNotes();

  std::vector<Pupitre> getPupitre();

	Partition getPartition(Pupitre pupitre); // What is that function? What does it should do?

	double getLength(); // Partition length

	std::vector<double> frameDivision(); // Divide time in frames.

										// Gives back events (notes) from time startTime to endTime
	//std::list <Note> getPartitionInFrame(double startTime, double endTime);

	// Gives back the partition from startTime to endTime, completing notes starting or ending
	// before of after the current frame.
	std::vector<Note> buildPartitionInFrame(double startTime, double endTime);

};
