// Created by Thomas Bellotti on 02/12/2017

#include "../include/noteglobale.hpp"



NoteGlobale::NoteGlobale ()	{

}

NoteGlobale::NoteGlobale (std::list <Note> listOfNotesNew, int newKey, double newTimestamp, bool newSignal, Pupitre pupitrenew)	{

	listOfNotes = listOfNotesNew;
	key = newKey;
	timestamp = newTimestamp;
	signal = newSignal;
	pupitre = pupitrenew;
}


/*NoteGlobale::~NoteGlobale()	{
	delete listOfNotes;
	delete pupitre;
}*/
