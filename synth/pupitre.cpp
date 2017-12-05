#include "../include/pupitre.hpp"

Pupitre::Pupitre(){

};

Pupitre::Pupitre(int track, Instrument instrument){
  this->track = track;
  this->instrument = instrument;
};

int Pupitre::getTrack() const {
  return track;
};

Instrument Pupitre::getInstrument() const{
  return instrument;
};

bool Pupitre::isEqual(Pupitre p2){
  return (track == p2.track) && (instrument.isEqual(p2.instrument));
};

// added by team engine
bool Pupitre::operator<(const Pupitre &p) const {
  return (getInstrument().getNumber() <= p.getInstrument().getNumber());
}

bool Pupitre::operator==(const Pupitre &p) const {
    bool sameTrack = (getTrack() == p.getTrack());
    bool sameInstrument = (getInstrument().getNumber() == p.getInstrument().getNumber());
    return sameTrack && sameInstrument;
}