#include "../include/synth/partitionglobale.hpp"

PartitionGlobale::PartitionGlobale() {
	listOfNotes = {};
}

std::vector<NoteGlobale> PartitionGlobale::getNotes() {
	return listOfNotes;
}

PartitionGlobale::PartitionGlobale(Partition mypartition, int keys_nbr) {
	// TODO: improve this
	std::vector<Note> notes = mypartition.getNotes();
	std::vector<int> pressed(keys_nbr, -1);
	for (size_t i = 0; i < notes.size(); ++i) {
		Note *n = &notes[i];

		// Check availability of each key, starting from n->getKey() % keys_nbr
		bool added = false;
		for (int j = n->getKey(); j < n->getKey() + keys_nbr; ++j) {
			int key = j % keys_nbr;

			if (n->getSignal()) {
				if (pressed[key] >= 0) {
					continue; // This key is busy with another note
				}
				pressed[key] = n->getKey(); // This key is now supposed to press this note
			} else {
				if (pressed[key] != n->getKey()) {
					continue;
				}
				pressed[key] = -1; // This key is no longer supposed to press this note
			}

			NoteGlobale ng = NoteGlobale({*n}, key, n->getTime(), n->getSignal(), n->getPupitre());
			listOfNotes.push_back(ng);

			added = true;
			break;
		}

		if (!added && n->getSignal()) {
			std::cout << "Warning: more than " << keys_nbr << " notes pressed at the same time, skipping one note:" << std::endl;
			n->print();
		}
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

void PartitionGlobale::print() {
	for (NoteGlobale n : listOfNotes) {
		n.print();
	}
}
