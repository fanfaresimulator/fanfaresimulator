#pragma once

#include <string>
#include "instrument.hpp"

class Note {
private:
    double timestamp;
    bool signal;                // on/off
    Instrument instrument;      // channel
    int key;                    // note 0 to 127
    int velocity;               // value 0 to 127
    int track;					// value 0 to #track

public:
    Note(double timestamp, bool signal, Instrument instrument, int key, int velocity, int track);

    ~Note();

    double getTime ();

    bool getSignal();

    Instrument getInstrument();

    int getKey();

    int getVelocity();

    int getTrack();

    bool isEqual(Note note2); // Compare timestamp and key.

    bool operator== (Note note2); // We surcharge the equality

};
