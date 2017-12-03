#include "partition.hpp"

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
  this->listOfNotes = listOfPupitres;
};

Partition::Partition(std::string midiFileName){
  std::vector<Note> = midi_handler(midiFileName);

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
  this->listOfNotes = listOfPupitres;
};

Partition::~Partition(){}

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

// Partition length
double Partition::getLength() {
  double maxTime = 0.;
  for(int i = 0; i < this->listOfNotes.size(); i++){
    if(maxTime < this->listOfNotes[i].getTime()){
      maxTime = this->listOfNotes[i].getTime();
    }
  }
  return maxTime;
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
