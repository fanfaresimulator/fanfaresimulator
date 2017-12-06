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

    int getTrack() const;

    Instrument getInstrument() const;

    bool isEqual(const Pupitre &p2) const;

    bool operator==(const Pupitre &other) const;

    bool operator<(const Pupitre &other) const;

    // Probably works, doesn't need to be used
    // because operators (==) and (<) are implemented
    struct PupitreCompare {
       bool operator() (const Pupitre &lhs, const Pupitre &rhs) const {
          if (!(lhs.getInstrument() == rhs.getInstrument())) { // main comparing attribute
            return lhs.getInstrument() < rhs.getInstrument();
          } else { // if instruments are equal second comparing attribute
            return lhs.getTrack() < rhs.getTrack();
          }
       }
    };
};
