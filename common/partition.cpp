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

	while (actualTime<(endTime-MAX_FRAME_LENGTH))	{
		// Sums the new time (random)
		actualTime+= MIN_FRAME_LENGTH + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX_FRAME_LENGTH-MIN_FRAME_LENGTH)));
		frames.push_back(actualTime);
	}

	frames.push_back(endTime);

	return frames;
}

std::list<Note> Partition::buildPartitionInFrame(double startTime, double endTime)	{


	std::list <Note> finalPartition;

	// This is the set of notes for which we are not sure that they have an ON/OFF
	// in the current frame.
	std::list <Note> noteSet;

	for (std::list<Note>::iterator iterAct=listOfNotes.begin(); iterAct != listOfNotes.end(); iterAct++)	{
		if (iterAct->getTime()>endTime)	{
			break;
		}

		if (iterAct->getTime()>=startTime)	{
			if (iterAct->getSignal())	{
				noteSet.push_front(*iterAct);
				finalPartition.push_back(*iterAct);
			}
			else	{
				std::list<Note>::iterator findIter = std::find(noteSet.begin(), noteSet.end(), (*iterAct));
				if (findIter == noteSet.end())	{
					// pushes the ON of the current note.
					finalPartition.push_front(Note(startTime, true, iterAct->getInstrument() ,iterAct->getKey() , iterAct->getVelocity(), iterAct->getTrack()));
					finalPartition.push_back((*iterAct));
				}
				else	{
					noteSet.erase(findIter);
					finalPartition.push_back(*iterAct);
				}
			}

		}
	}

	for (std::list<Note>::iterator iterRest=noteSet.begin(); iterRest!=noteSet.end(); iterRest++)	{
		finalPartition.push_back(Note(endTime, false, iterRest->getInstrument(),iterRest->getKey(), iterRest->getVelocity(), iterRest->getTrack()));
	}

	return finalPartition;

}
