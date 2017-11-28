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

public:

    Note(double timestamp, bool signal, Instrument instrument, int key, int velocity);

};
