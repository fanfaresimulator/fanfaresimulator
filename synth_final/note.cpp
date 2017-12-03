#include "note.hpp"

Note::Note(double timestamp, bool signal, Pupitre pupitre, int key, int velocity){
 this->timestamp = timestamp;
 this->signal = signal;
 this->pupitre = pupitre;
 this->key = key;
 this->velocity = velocity;
    };

bool Note::getSignal (){
 return signal;
};


double Note::getTime (){
 return timestamp;
};

int Note::getKey (){
 return key;
};

int Note::getVelocity (){
 return velocity;
};
