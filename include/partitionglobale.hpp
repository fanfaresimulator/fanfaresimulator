#pragma once

#include <iostream>

#include "noteglobale.hpp"
#include "instrument.hpp"

class PartitionGlobale {
private:
	std::initializer_list <NoteGlobale> listOfNotes;

public:
	PartitionGlobale();

	PartitionGlobale(std::initializer_list <NoteGlobale> listOfNotes);

	~PartitionGlobale();

	std::initializer_list <NoteGlobale> getNotes();


	Partition getPartition(Instrument instrument);



};

