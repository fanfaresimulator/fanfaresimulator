#include <iostream>
#include "../include/note.hpp"

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

int Note::getTrack() {
	return pupitre.getTrack();
}

double Note::getTime(){
	return timestamp;
};

Pupitre Note::getPupitre(){
	return pupitre;
};

int Note::getKey(){
	return key;
};

int Note::getVelocity (){
	return velocity;
};

bool Note::operator==(Note note2) {
	return (key == note2.key);
}

void Note::print() {
	std::cout << "Note{ .timestamp=" << timestamp << "; .signal = " << signal <<
		"; .key = " << key << "; .velocity = " << velocity << " }" << std::endl;
}
