// Created by Thomas Bellotti on 02/12/2017


#include "../include/partitionglobale.hpp"
#include "../include/partition.hpp"

PartitionGlobale::PartitionGlobale() {}

std::vector<NoteGlobale> PartitionGlobale::getNotes() {
	return listOfNotes;
}

PartitionGlobale::PartitionGlobale(Partition mypartition) {
	// TODO: improve this
	std::vector<Note> notes = mypartition.getNotes();
	for (int i = 0; i < notes.size(); ++i) {
		Note *n = &notes[i];
		listOfNotes.push_back(NoteGlobale({*n}, n->getKey()%4, n->getTime(), n->getSignal(), n->getPupitre()));
	}

	/*std::vector <NoteGlobale> finalListOfNotes;
	std::vector <double> frames = mypartition.frameDivision();

	std::vector <Note> noteSet;
	for (std::vector<double>::iterator temps=frames.begin(); temps != (frames.end()-1); temps++)	{

		double startTime = (*temps)+USER_TOLL;
		double endTime = (*(temps+1))-USER_TOLL;

		std::vector <Note> actualSegment = mypartition.buildPartitionInFrame(startTime,endTime,noteSet);
		if (actualSegment.size() == 0) {
			continue;
		}

		int randomKey = rand()%3 + 1;
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,startTime, true, actualSegment.begin()->getPupitre()));
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,endTime,false,actualSegment.begin()->getPupitre()));

	}*/
}

std::vector<NoteGlobale>::iterator PartitionGlobale::getNextValidIterator(std::vector<NoteGlobale>::iterator iterActual, double actualTime) {

	std::vector<NoteGlobale>::iterator iterCurrent = iterActual;

	while (iterCurrent->getTime() < actualTime)	{
		iterCurrent++;
		if (iterCurrent == listOfNotes.end())	{
			// We have finished our score, so we return a listOFNotes.end()
			return iterCurrent;
		}
	}

	if (iterCurrent->getSignal())	{
		return iterCurrent;
	}
	else	{
		return (iterCurrent+1);
	}

}
