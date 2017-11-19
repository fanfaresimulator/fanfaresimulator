#pragma once

#include <iostream>

#include <notes.hpp>
#include <instrument.hpp>

class Partition {
private:
	std::initializer_list <Note> listOfNotes;

public:
	std::initializer_list <Note> getNotes();

	Partition getPartition(Instrument instrument);
};