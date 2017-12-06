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



};

