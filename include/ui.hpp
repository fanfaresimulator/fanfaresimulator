//
// Created Thomas Bellotti on 19/11/2017
//

#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"

// Waiting for implementation
class Obj{};

typedef Obj Keyboard;

//

typedef std::basic_string<char> string;

class UI {
private:
	Partition partition;
	Keyboard keyboard;

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

	string getUsername();
};

#endif // UI_HPP