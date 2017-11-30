#include "../include/partition.hpp"

Partition::Partition() {}

Partition::Partition(std::list<Note> listOfNotes) {}

Partition::~Partition() {}

std::list <Note> Partition::getNotes() {
  return NULL;
}

Partition Partition::getPartition(Instrument instrument) {
  Partition p;
  return p;
}

// Partition length
double Partition::getLength() {
  return .0;
}

// Divide time in frames.
std::list <double> Partition::frameDivision() {
  return NULL;
}

// Gives back events (notes) from time startTime to endTime
std::list <Note> Partition::buildPartitionInFrame(double startTime, double endTime) {
  return NULL;
}
