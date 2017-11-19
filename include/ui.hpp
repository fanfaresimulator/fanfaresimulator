/* Created and edited by Thomas Bellotti on 19/11/2017 */

#ifndef UI_H
#define UI_H

#endif // UI_H

#include <iostream>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"

typedef std::basic_string<char> string;

class UI	{

private:

	Partition partition;
	Keyboard keyboard;

public:
	UI();

	~UI();

	void Draw();

	void Init();

	Instrument getInstrument();

	void updateInstrumentMap(Instrument);

	void notePressed(Note);

	void startPartition();

	void startStream();

	string getUsername();

};
