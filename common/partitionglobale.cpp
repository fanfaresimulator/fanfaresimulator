// Created by Thomas Bellotti on 02/12/2017


#include "../include/partitionglobale.hpp"
#include "../include/partition.hpp"




PartitionGlobale::PartitionGlobale ()	{

}

PartitionGlobale::PartitionGlobale (Partition mypartition)	{

	std::list <NoteGlobale> finalListOfNotes = new std::list<NoteGlobale>();
	std::list <double> frames = mypartition.frameDivision();

	std::list <Note> noteSet = new std::list<Note();


	for (std::list<double>::iterator temps=frames.begin(); temps != (frames.end()-1); temps++)	{

		double startTime = (*temps);
		double endTime = (*(temps+1));

		std::list <Note> actualSegment = mypartition.buildPartitionInFrame(startTime,endTime,noteSet);

		int randomKey = rand()%3 + 1;
		finalListOfNotes.push_back(new NoteGlobale(actualSegment, randomKey,startTime, true));
		finalListOfNotes.push_back(new NoteGlobale(actualSegment, randomKey,endTime,false));

	}

}

PartitionGlobale::~PartitionGlobale()	{
	delete listOfNotes;
}

