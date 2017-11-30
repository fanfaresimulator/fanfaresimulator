#include "../include/partition.hpp"

Partition::Partition() {}

Partition::Partition(std::list<Note> listOfNotes) {}

Partition::~Partition() {}

std::list <Note> Partition::getNotes() {}

Partition Partition::getPartition(Instrument instrument) {}

// Partition length
double Partition::getLength() {}

// Divide time in frames.
std::list <double> Partition::frameDivision() {}

// Gives back events (notes) from time startTime to endTime
std::list <Note> Partition::buildPartitionInFrame(double startTime, double endTime) {}
