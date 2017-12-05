#include "../include/note.hpp"

Note::~Note()	{
	delete Instrument;
}

Note::Note(double timestamp, bool signal, Pupitre pupitredeux, int key, int velocity){
 this->timestamp = timestamp;
 this->signal = signal;
 this->pupitre = pupitredeux;
 this->key = key;
 this->velocity = velocity;
 //this->track = track;
    };

    
// Cette egalite a ete redefinie pour utiliser une fonction de recherche
// dans une liste.
    
bool Note::operator== (Note note2)	{
	return (key==note2.key);
}


Instrument Note::getInstrument()	{
	return instrument;
}

int Note::getKey()	{
	return key;
}

int Note::getVelocity()	{
	return velocity;
}

int Note::getTrack()	{
	return track;
}

double Note::getTime()	{
	return timestamp;
}


bool Note::getSignal()	{
	return signal;
}
