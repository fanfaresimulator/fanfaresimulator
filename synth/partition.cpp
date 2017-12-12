#include "../include/synth/partition.hpp"

Partition::Partition(){
	this->listOfNotes = std::vector<Note>();
	this->listOfPupitres = std::vector<Pupitre>();
}

Partition::Partition(std::vector<Note> listOfNotes){
	this->listOfNotes = listOfNotes;

	std::vector<Pupitre> listOfPupitres;
	for(size_t i = 0; i < listOfNotes.size(); i++){
		bool pupitreIsAlreadyCounted = false;
		for(size_t j = 0; j < listOfPupitres.size(); j++){
			pupitreIsAlreadyCounted = pupitreIsAlreadyCounted || listOfPupitres[j].isEqual(listOfNotes[i].getPupitre());
		}
		if(!pupitreIsAlreadyCounted){
			listOfPupitres.push_back(listOfNotes[i].getPupitre());
		}
	}
	this->listOfPupitres = listOfPupitres;
}

Partition::Partition(std::string midiFileName){
	std::vector<Note> listOfNotes = midi_handler::midi_handler_fromString(midiFileName);

	this->listOfNotes = listOfNotes;

	std::vector<Pupitre> listOfPupitres;
	for(size_t i = 0; i < listOfNotes.size(); i++){
		bool pupitreIsAlreadyCounted = false;
		for(size_t j = 0; j < listOfPupitres.size(); j++){
			pupitreIsAlreadyCounted = pupitreIsAlreadyCounted || listOfPupitres[j].isEqual(listOfNotes[i].getPupitre());
		}
		if(!pupitreIsAlreadyCounted){
			listOfPupitres.push_back(listOfNotes[i].getPupitre());
		}
	}
	this->listOfPupitres = listOfPupitres;
}

std::vector<Note> Partition::getNotes() {
	return listOfNotes;
}

std::vector<Pupitre> Partition::getPupitre() {
	return listOfPupitres;
}

Partition Partition::getPartition(Pupitre pupitre) {
	std::vector<Note> listOfNotes;
	for(size_t i = 0; i < this->listOfNotes.size(); i++){
		if(pupitre.isEqual(this->listOfNotes[i].getPupitre())){
			listOfNotes.push_back(this->listOfNotes[i]);
		}
	}
	return Partition(listOfNotes);
}

//double Partition::getLength() {
//	double maxTime = 0.;
//	for(size_t i = 0; i < this->listOfNotes.size(); i++){
//		if(maxTime < this->listOfNotes[i].getTime()){
//			maxTime = this->listOfNotes[i].getTime();
//		}
//	}
//	return maxTime;
//}

double Partition::getLength() {
    std::vector<Note>::iterator it = listOfNotes.end();
    return (it-1)->getTime();
}

// generate rand val between 0 and 1
double getRand(double min, double max){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);

}

std::vector <double> Partition::frameDivision()	{

	double endTime = this->getLength();
	double actualTime = 0.0;

	std::vector<double> frames;

	frames.push_back(actualTime);

	while (actualTime < (endTime-MAX_FRAME_LENGTH) )	{
		// Sums the new time (random)
		actualTime+= MIN_FRAME_LENGTH+(MAX_FRAME_LENGTH-MIN_FRAME_LENGTH)*getRand(0.0, 1.0);
		//actualTime+= (MIN_FRAME_LENGTH + static_cast <float> (rand()) /(1+ static_cast <float> (RAND_MAX/(MAX_FRAME_LENGTH-MIN_FRAME_LENGTH))));// division par 0 !?!
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
		// maybe better
//		finalPartition.push_back(Note(startTime,true,bucketIter->getPupitre(), bucketIter->getKey(), bucketIter->getVelocity()));
	}

	for (std::vector<Note>::iterator iterAct=listOfNotes.begin(); iterAct != listOfNotes.end(); iterAct++)	{



		if (iterAct->getTime()>endTime || iterAct->getTime() < startTime )	{
			break;
		}

		if (iterAct->getSignal())	{
			noteSet.insert(noteSet.begin(),*iterAct);
			finalPartition.push_back(*iterAct);
		}
		else {

			// std::vector<Note>::iterator findIter = std::find(noteSet.begin(), noteSet.end(), (*iterAct));
			// iterate over note Set check for note father

			std::vector<Note>::iterator it;
			for (it = noteSet.begin(); it != noteSet.end(); it++){
				if((*it) == (*iterAct)) {
					break;
				}
			}
			noteSet.erase(it);

			// TODO: this segfaults
			//noteSet.erase(findIter);
			finalPartition.push_back(*iterAct);
		}
	}

	for (std::vector<Note>::iterator iterRest=noteSet.begin(); iterRest!=noteSet.end(); iterRest++)	{
		finalPartition.push_back(Note(endTime, false, iterRest->getPupitre(),iterRest->getKey(), iterRest->getVelocity()));
	}

	return finalPartition;

}

void Partition::print() {
	std::cout << "Pupitres:" << std::endl;
	for (std::vector<Pupitre>::iterator iter = listOfPupitres.begin(); iter != listOfPupitres.end(); iter++)	{
		iter->print();
	}
	std::cout << "Notes:" << std::endl;
	for (std::vector<Note>::iterator iter = listOfNotes.begin(); iter != listOfNotes.end(); iter++)	{
		iter->print();
	}
}
