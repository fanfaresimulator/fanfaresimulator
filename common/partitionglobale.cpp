// Created by Thomas Bellotti on 02/12/2017


#include "../include/partitionglobale.hpp"
#include "../include/partition.hpp"




PartitionGlobale::PartitionGlobale ()	{

}

PartitionGlobale::PartitionGlobale (Partition mypartition)	{

	std::list <NoteGlobale> finalListOfNotes;
	std::list <double> frames = mypartition.frameDivision();

	for (temps=frames.begin(); temps != (frames.end()-1); temps++)	{

		double startTime = temps;
		double endTime = (temps+1);

		std::list <Note> actualSegment = mypartition.buildPartitionInFrame(startTime,endTime);

		int randomKey = rand()%3;
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,startTime, true));
		finalListOfNotes.push_back(NoteGlobale(actualSegment, randomKey,endTime,false));

	}

}

