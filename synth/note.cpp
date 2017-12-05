#include "../include/note.hpp"

Note::~Note() {
	delete pupitre;
}

Note::Note(double timestamp, bool signal, Pupitre pupitredeux, int key, int velocity){
	this->timestamp = timestamp;
	this->signal = signal;
	this->pupitre = pupitredeux;
	this->key = key;
	this->velocity = velocity;
};

bool Note::getSignal(){
 return signal;
};


double Note::getTime(){
 return timestamp;
};

Instrument Note::getPupitre(){
 return pupitre ;
};

int Note::getKey(){
 return key;
};

int Note::getVelocity (){
 return velocity;
};

bool Note::operator== (Note note2) {
	return (key == note2.key);
}