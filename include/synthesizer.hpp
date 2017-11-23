#pragma once

#include <iostream>
#include "instrument.hpp"
#include "note.hpp"
#include "partition.hpp"

class Synthesizer {
private:
	Partition mainPartition;

public:
	Synthesizer();

	Synthesizer(Partition mainPartition);

	~Synthesizer();

	Partition getPartition(Instrument instrument);

	void playNote(Note note);
};
