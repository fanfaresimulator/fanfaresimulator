#pragma once

#include <iostream>
#include "instrument.hpp"
//#include "note.hpp" Waiting for implementation
#include "partition.hpp"

// Waiting for implementation
class Obj {};

typedef Obj Note;

class Synthesizer {
private : 
	Partition mainPartition;

public:
	Synthesizer();

	Synthesizer(Partition mainPartition);

	~Synthesizer();

	Partition getPartition(Instrument instrument);

	void playNote(Note note);
};