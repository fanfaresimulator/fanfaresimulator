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
#include "music_line.hpp"
#include "gui_note.hpp"

//using namespace std;

class UI {
private:
	PartitionGlobale partition;
	//Keyboard keyboard;
	GameWindow* window;

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
