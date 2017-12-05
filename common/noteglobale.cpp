// Created by Thomas Bellotti on 02/12/2017

#include "../include/noteglobale.hpp"



NoteGlobale::NoteGlobale ()	{

}

NoteGlobale::NoteGlobale (std::list <Note> listOfNotesNew, int newKey, double newTimestamp, bool newSignal)	{

	listOfNotes = listOfNotesNew;
	key = newKey;
	timestamp = newTimestamp;
	signal = newSignal;
}


NoteGlobale::~NoteGlobale()	{
	delete listOfNotes;
	delete instrument;
}
