#pragma once

#include <iostream>

#include "note.hpp"
#include "instrument.hpp"

// Waiting for implementation
class Obj {};


class Partition {
private:
	std::initializer_list <Note> listOfNotes;

public:
	std::initializer_list <Note> getNotes();

	// TODO: implement these
	// Partition();
	//
	// ~Partition();

	Partition getPartition(Instrument instrument);
};
