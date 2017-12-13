#pragma once

#include <string>
#include <iostream>

#include "instrument.hpp"

class Pupitre {
private:
    int track;
    Instrument instrument;

public:
    Pupitre(int track, Instrument instrument);
    int getTrack() const;
    Instrument getInstrument() const;
    bool isEqual(const Pupitre &p2) const;
    bool operator==(const Pupitre &other) const;
    bool operator<(const Pupitre &other) const;
    void print();
};
