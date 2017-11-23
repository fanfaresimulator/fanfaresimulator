#pragma once

#include <iostream>
#include "instrument.hpp"
#include "note.hpp"
#include "partition.hpp"

class Synthesizer {
private:
	Partition mainPartition;

public:
	// TODO: implement these
	// Synthesizer();
	//
	// Synthesizer(Partition mainPartition);
	//
	// ~Synthesizer();

	Partition getPartition(Instrument instrument);

	void playNote(Note note);
};
