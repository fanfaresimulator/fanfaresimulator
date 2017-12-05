#include "../include/note.hpp"

Note::Note(double timestamp, bool signal, Instrument instrument, int key, int velocity, int track){
 this->timestamp = timestamp;
 this->signal = signal;
 this->instrument = instrument;
 this->key = key;
 this->velocity = velocity;
 this->track = track;
    };
