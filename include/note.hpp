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
    Note(double timestamp, bool signal, Pupitre pupitre, int key, int velocity);

    bool getSignal ();

    double getTime ();

    Pupitre getPupitre();

    Instrument getInstrument();

    int getTrack();

    int getKey ();

    int getVelocity ();

    bool isEqual(Note note2); // Compare timestamp and key.

};
