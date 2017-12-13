#pragma once

#include <iostream>
#include <vector>

#include "../include/synth/noteglobale.hpp"
#include "../include/synth/pupitre.hpp"
#include "../include/synth/partition.hpp"
//#include "instrument.hpp"

class PartitionGlobale {
private:
	std::vector<NoteGlobale> listOfNotes;

public:
	PartitionGlobale();
	PartitionGlobale(Partition partition, int keys_nbr);
	std::vector <NoteGlobale> getNotes();
	Partition getPartition(Pupitre pupitre);
	// Cette fonction peut donner listOfNotes.end() lorsqu'on est a la fin de la partiture ... il faut le gerer.
	std::vector<NoteGlobale>::iterator getNextValidIterator(std::vector<NoteGlobale>::iterator iterActual, double actualTime);

	// DEBUG
	void print();
};
