#pragma once

//
// Created by Thomas Bellotti on 19/11/2017
//

#include <iostream>
#include <string>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

class UI {
private:
	Partition partition;
	//Keyboard keyboard;

public:
	UI();

	~UI();

	void Draw();

	void Init();

	Instrument getInstrument();

	void updateInstrumentMap(Instrument instrument);

	void notePressed(Note note);

	void startPartition();

	void startStream();

	std::string getUsername();
};
