#pragma once

#include <string>
#include "pupitre.hpp"

class Note {
private:
	double timestamp;
	bool signal;                // on/off
	Pupitre pupitre;
	int key;                    // note 0 to 127
	int velocity;               // value 0 to 127

public:
	Note(double timestamp, bool signal, Pupitre pupitredeux, int key, int velocity);

	//~Note();

	bool getSignal ();

	double getTime ();

	Pupitre getPupitre();

	int getKey ();

	int getVelocity ();

	int getTrack();

	//bool isEqual(Note note2); // Compare timestamp and key.

	bool operator== (Note note2); // We surcharge the equality

	void print();
};
