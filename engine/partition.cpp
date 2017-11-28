#include "../include/partition.hpp"




Partition::Partition (std::initializer_list <Note> newListOfNotes)	{

	listOfNotes = newListOfNotes; // ask more about this structure
}


std::initializer_list <Note> Partition::getNotes()	{

	return listOfNotes;
}




