#pragma once

#include <string>
//#include "instrument.hpp"
#include "pupitre.hpp"

class Note {
private:
    double timestamp;
    bool signal;                // on/off
    Pupitre pupitre;      // channel
    int key;                    // note 0 to 127
    int velocity;               // value 0 to 127
    //int track;					// value 0 to #track

public:
    Note(double timestamp, bool signal, Pupitre pupitredeux, int key, int velocity, int track);

    ~Note();

    double getTime ();

    bool getSignal();

    Pupitre getPupitre();

    int getKey();

    int getVelocity();

   // int getTrack();

    bool isEqual(Note note2); // Compare timestamp and key.

    bool operator== (Note note2); // We surcharge the equality

};
