#include "pupitre.hpp"

Pupitre::Pupitre(int track, Instrument instrument){
  this->track = track;
  this->instrument = instrument;
};

int Pupitre::getTrack(){
  return track;
};

Instrument Pupitre::getInstrument(){
  return instrument;
};

bool Pupitre::isEqual(Pupitre p2){
  return (track == p2.track) && (instrument.isEqual(p2.instrument));
};
