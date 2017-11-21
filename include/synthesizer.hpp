#pragma once

#include <iostream>
#include <instrument.hpp>
#include <note.hpp>
#include <partition.hpp>

// Waiting for implementation
class Obj {};

typedef Obj MainPartition; // Maybe a .midi file ?

class Synthesizer {
private : 
	MainPartition mainPartition;

public:
	Synthesizer();

	Synthesizer(MainPartition);

	~Synthesizer();

	Partition getPartition(Instrument);

	void playNote(Note);
};