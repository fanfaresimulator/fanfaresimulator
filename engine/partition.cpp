/* Created by Thomas Bellotti on 28/11/17 */

#include "../include/partition.hpp"




Partition::Partition (std::list <Note> newListOfNotes)	{

	listOfNotes = newListOfNotes; // ask more about this structure
}


std::list <Note> Partition::getNotes()	{

	return listOfNotes;
}

double Partition::getLength() {

	Note lastNote = listOfNotes.back();
}




