// Created by Thomas Bellotti on 02/12/2017


#include "../include/partitionglobale.hpp"
#include "../include/partition.hpp"




PartitionGlobale::PartitionGlobale ()	{

}

PartitionGlobale::PartitionGlobale (Partition mypartition)	{

	std::vector <NoteGlobale> finalListOfNotes;
	std::vector <double> frames = mypartition.frameDivision();

	std::vector <Note> noteSet;


	for (std::vector<double>::iterator temps=frames.begin(); temps != (frames.end()-1); temps++)	{

		double startTime = (*temps)+USER_TOLL/2;
		double endTime = (*(temps+1))-USER_TOLL/2;

		std::vector <Note> actualSegment = mypartition.buildPartitionInFrame(startTime,endTime,noteSet);

		int randomKey = rand()%3 + 1;
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,startTime, true, actualSegment.begin()->getPupitre()));
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,endTime,false,actualSegment.begin()->getPupitre()));

	}

}

PartitionGlobale::~PartitionGlobale()	{
	//delete listOfNotes;
}

