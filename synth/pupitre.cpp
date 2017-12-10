#include "../include/pupitre.hpp"

Pupitre::Pupitre(int track, Instrument instrument) : track(track),
    instrument(instrument) {
  // Nothing to do
};

int Pupitre::getTrack() const {
  return track;
};

Instrument Pupitre::getInstrument() const {
  return instrument;
};

// should be removed if possible
bool Pupitre::isEqual(const Pupitre& p2) const {
  return (track == p2.track) && (this->getInstrument() == p2.getInstrument());
};

bool Pupitre::operator==(const Pupitre &other) const {
  return (track == other.track) && (this->getInstrument() == other.getInstrument());
}

bool Pupitre::operator<(const Pupitre &other) const {
  if (!(this->getInstrument() == other.getInstrument())) { // main comparing attribute
    return this->getInstrument() < other.getInstrument();
  } else { // if instruments are equal second comparing attribute
    return track < other.track;
  }
}
