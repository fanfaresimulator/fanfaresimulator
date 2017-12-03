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


Pupitre Note::getPupitre(){
 return pupitre;
};

int Note::getKey (){
 return key;
};

int Note::getVelocity (){
 return velocity;
};

bool Note::isEqual(Note note2){
 return (note2.getTime == timestamp && note2.getKey() == key);
};