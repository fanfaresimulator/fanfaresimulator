// Created by Thomas Bellotti on 02/12/2017

#include "../include/noteglobale.hpp"



NoteGlobale::NoteGlobale ()	{

}

NoteGlobale::NoteGlobale (std::vector <Note> listOfNotesNew, int newKey, double newTimestamp, bool newSignal, Pupitre pupitrenew)	{

	listOfNotes = listOfNotesNew;
	key = newKey;
	timestamp = newTimestamp;
	signal = newSignal;
	pupitre = pupitrenew;
}


bool NoteGlobale::getSignal()	{
	return signal;
}

double NoteGlobale::getTime()	{
	return timestamp;
}

/*NoteGlobale::~NoteGlobale()	{
	delete listOfNotes;
	delete pupitre;
}*/

std::vector <Note>* NoteGlobale::getListOfNotes() {
	return &listOfNotes;
}

int NoteGlobale::getKey() {
	return key;
}