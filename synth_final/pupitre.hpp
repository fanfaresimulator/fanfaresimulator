#pragma once

#include <string>
#include "instrument.hpp"

class Pupitre {
private:
    int track;
    Instrument instrument;

public:
    Pupitre(int track, Instrument instrument);

    int getTrack();

    Instrument getInstrument();

    bool isEqual(Pupitre p2);
};
