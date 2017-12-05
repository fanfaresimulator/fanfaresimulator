#include "../include/note.hpp"

Note::Note(double timestamp, bool signal, int instrument, int key, int velocity, int track){
 this->timestamp = timestamp;
 this->signal = signal;
 this->instrument = instrument;
 this->key = key;
 this->velocity = velocity;
 this->track = track;
    };

bool Note::getSignal (){
 return signal;
};


double Note::getTime (){
 return timestamp;
};

Instrument Note::getInstrument (){
 return instrument ;
};

int Note::getKey (){
 return key;
};

int Note::getVelocity (){
 return velocity;
};