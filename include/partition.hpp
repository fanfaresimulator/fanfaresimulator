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
};
