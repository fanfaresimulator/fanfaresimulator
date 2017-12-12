#include "../include/synth/partitionglobale.hpp"

int getRand(int min, int max);

PartitionGlobale::PartitionGlobale() {
	listOfNotes = {};
}

std::vector<NoteGlobale> PartitionGlobale::getNotes() {
	return listOfNotes;
}

PartitionGlobale::PartitionGlobale(Partition mypartition, int keys_nbr) {

	std::vector <NoteGlobale> finalListOfNotes;
	std::vector <double> frames = mypartition.frameDivision();

	std::vector <Note> noteSet;

    int previousKey = -1;
	for (std::vector<double>::iterator temps=frames.begin(); temps != (frames.end()-2); temps++)	{

//		double startTime = (*temps)+USER_TOLL;
//		double endTime = (*(temps+1))-USER_TOLL;
		// DEBUG
		double startTime = (*temps);
		double endTime = (*(temps+1));


		std::vector <Note> actualSegment = mypartition.buildPartitionInFrame(startTime,endTime,noteSet);


		if (actualSegment.size() == 0) {
			// choose min frame in order to avoid this case
			cout << "ERROR !! actual segement size == 0 in partition global cpp" << endl;
			continue;
		}


        int randomKey = getRand(0, 3);
        while((randomKey == previousKey) && (previousKey != -1)){
            randomKey = getRand(0, 3);
        }

		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,startTime, true, actualSegment.begin()->getPupitre()));
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,endTime,false, actualSegment.begin()->getPupitre()));
        previousKey = randomKey;
	}

    listOfNotes = finalListOfNotes;
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
	vector<NoteGlobale>::iterator it;
	int i ;
	for (it = listOfNotes.begin(), i = 0; it != listOfNotes.end(); it+=2, i++) {
		cout << "Note Globale " << i << ":" << endl;
		cout << "start : " << it->getTime() << endl;
		cout << "end : " << (it+1)->getTime() << endl;
		cout << "key : " << it->getKey() << endl;
	}
}

int getRand(int min, int max){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}