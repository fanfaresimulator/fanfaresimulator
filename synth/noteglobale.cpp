#include "../include/synth/noteglobale.hpp"

NoteGlobale::NoteGlobale (std::vector <Note> listOfNotes, int key,
		double timestamp, bool signal, Pupitre pupitre) : listOfNotes(listOfNotes),
		key(key), timestamp(timestamp), signal(signal), pupitre(pupitre) {
	// Nothing to do
}

bool NoteGlobale::getSignal()	{
	return signal;
}

double NoteGlobale::getTime()	{
	return timestamp;
}

std::vector <Note>* NoteGlobale::getListOfNotes() {
	return &listOfNotes;
}

int NoteGlobale::getKey() {
	return key;
}
