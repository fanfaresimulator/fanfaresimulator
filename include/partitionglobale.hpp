#pragma once

#include <iostream>
#include <list>

#include "noteglobale.hpp"
#include "instrument.hpp"

class PartitionGlobale {
private:
	std::list <NoteGlobale> listOfNotes;

public:
	PartitionGlobale();

	PartitionGlobale(std::list <NoteGlobale> listOfNotes);

	~PartitionGlobale();

	std::list <NoteGlobale> getNotes();


	Partition getPartition(Instrument instrument);



};

