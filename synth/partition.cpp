#include "../include/partition.hpp"

Partition::Partition(){
	this->listOfNotes = std::vector<Note>();
	this->listOfPupitres = std::vector<Pupitre>();
};

Partition::Partition(std::vector<Note> listOfNotes){
	this->listOfNotes = listOfNotes;

	std::vector<Pupitre> listOfPupitres;
	for(int i = 0; i < listOfNotes.size(); i++){
		bool pupitreIsAlreadyCounted = false;
		for(int j = 0; j < listOfPupitres.size(); j++){
			pupitreIsAlreadyCounted = pupitreIsAlreadyCounted || listOfPupitres[j].isEqual(listOfNotes[i].getPupitre());
		}
		if(!pupitreIsAlreadyCounted){
			listOfPupitres.push_back(listOfNotes[i].getPupitre());
		}
	}
	this->listOfPupitres = listOfPupitres;
};

Partition::Partition(std::string midiFileName){
	std::vector<Note> listOfNotes = midi_handler::midi_handler_fromString(midiFileName);

	this->listOfNotes = listOfNotes;

	std::vector<Pupitre> listOfPupitres;
	for(int i = 0; i < listOfNotes.size(); i++){
		bool pupitreIsAlreadyCounted = false;
		for(int j = 0; j < listOfPupitres.size(); j++){
			pupitreIsAlreadyCounted = pupitreIsAlreadyCounted || listOfPupitres[j].isEqual(listOfNotes[i].getPupitre());
		}
		if(!pupitreIsAlreadyCounted){
			listOfPupitres.push_back(listOfNotes[i].getPupitre());
		}
	}
	this->listOfPupitres = listOfPupitres;
};

Partition::~Partition(){

	//delete listOfNotes;
	//delete listOfPupitres;
}

std::vector<Note> Partition::getNotes() {
	return listOfNotes;
}

std::vector<Pupitre> Partition::getPupitre() {
	return listOfPupitres;
}

Partition Partition::getPartition(Pupitre pupitre) {
	std::vector<Note> listOfNotes;
	for(int i = 0; i < this->listOfNotes.size(); i++){
		if(pupitre.isEqual(this->listOfNotes[i].getPupitre())){
			listOfNotes.push_back(this->listOfNotes[i]);
		}
	}
	return Partition(listOfNotes);
}

double Partition::getLength() {
	double maxTime = 0.;
	for(int i = 0; i < this->listOfNotes.size(); i++){
		if(maxTime < this->listOfNotes[i].getTime()){
			maxTime = this->listOfNotes[i].getTime();
		}
	}
	return maxTime;
}

std::vector <double> Partition::frameDivision()	{

	double endTime = this->getLength();
	double actualTime = 0.0;

	std::vector<double> frames;

	frames.push_back(actualTime);

	while (actualTime<(endTime-MAX_FRAME_LENGTH))	{
		// Sums the new time (random)
		actualTime+= (MIN_FRAME_LENGTH + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX_FRAME_LENGTH-MIN_FRAME_LENGTH))));
		frames.push_back(actualTime);
	}

	frames.push_back(endTime);

	return frames;
}

std::vector<Note> Partition::buildPartitionInFrame(double startTime, double endTime,std::vector<Note> noteSet)	{


	std::vector <Note> finalPartition;

	// This is the set of notes for which we are not sure that they have an ON/OFF
	// in the current frame.
	//std::list <Note> noteSet;

	for (std::vector<Note>::iterator bucketIter=noteSet.begin(); bucketIter!=noteSet.end(); bucketIter++)	{
		finalPartition.insert(finalPartition.begin(), Note(startTime,true,bucketIter->getPupitre(), bucketIter->getKey(), bucketIter->getVelocity()));
	}

	for (std::vector<Note>::iterator iterAct=listOfNotes.begin(); iterAct != listOfNotes.end(); iterAct++)	{



		if (iterAct->getTime()>endTime)	{
			break;
		}

		if (iterAct->getTime()>=startTime)	{
			if (iterAct->getSignal())	{
				noteSet.insert(noteSet.begin(),*iterAct);
				finalPartition.push_back(*iterAct);
			}
			else	{
				std::vector<Note>::iterator findIter = std::find(noteSet.begin(), noteSet.end(), (*iterAct));

				noteSet.erase(findIter);
				finalPartition.push_back(*iterAct);

			}

		}
	}

	for (std::vector<Note>::iterator iterRest=noteSet.begin(); iterRest!=noteSet.end(); iterRest++)	{
		finalPartition.push_back(Note(endTime, false, iterRest->getPupitre(),iterRest->getKey(), iterRest->getVelocity()));
	}

	return finalPartition;

}

