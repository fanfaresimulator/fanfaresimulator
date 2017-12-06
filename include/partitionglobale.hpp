#pragma once

#include <iostream>
#include <vector>

#include "../include/noteglobale.hpp"
#include "../include/pupitre.hpp"
#include "../include/partition.hpp"
//#include "instrument.hpp"

class PartitionGlobale {
private:
	std::vector <NoteGlobale> listOfNotes;

public:
	PartitionGlobale();

	PartitionGlobale(Partition mypartition);

	~PartitionGlobale();

	std::vector <NoteGlobale> getNotes();


	Partition getPartition(Pupitre pupitre);

	// Cette fonction peut donner listOfNotes.end() lorsqu'on est a la fin de la partiture ... il faut le gerer.
	std::vector<NoteGlobale>::iterator getNextValidIterator(std::vector<NoteGlobale>::iterator iterActual, double actualTime);


};

