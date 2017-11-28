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
	return lastNote.getTime ();

}


std::list <double> Partition::frameDivision()	{

	double endTime = this->getLength();
	double actualTime = 0.0;

	std::list<double> frames;

	frames.push_front(actualTime);

	while (actualTime<(endTime-maxFrameLength))	{
		// Sums the new time (random)
		actualTime+= minFrameLength + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxFrameLength-minFrameLength)));
		frames.push_back(actualTime);
	}

	frames.push_back(endTime);

	return frames;
}





