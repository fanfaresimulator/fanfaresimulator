#pragma once

#include <iostream>
#include <list>
#include <cstdlib>

#include "noteglobale.hpp"
#include "instrument.hpp"
#include "partition.hpp"

class PartitionGlobale {
private:
	std::list <NoteGlobale> listOfNotes;

public:
	PartitionGlobale();

	PartitionGlobale(Partition mypartition);

	~PartitionGlobale();

//	std::list <NoteGlobale> getNotes();


//	Partition getPartition(Instrument instrument);



};

