#pragma once

#include <string>
#include "instrument.hpp"

class Pupitre {
private:
    int track;
    Instrument instrument;

public:
    Pupitre();

    Pupitre(int track, Instrument instrument);

    int getTrack();

    Instrument getInstrument() const;

    bool isEqual(Pupitre p2);

    // added by engine
    bool operator<(const Pupitre& p) const;
};
