#include "../include/synth/note.hpp"

Note::Note(double timestamp, bool signal, Pupitre pupitre, int key,
		int velocity) : timestamp(timestamp), signal(signal), pupitre(pupitre),
		key(key), velocity(velocity) {
	// Nothing to do
}

bool Note::getSignal() {
	return signal;
}

void Note::setSignal(bool signal) {
	this->signal = signal;
}

int Note::getTrack() {
	return pupitre.getTrack();
}

double Note::getTime() {
	return timestamp;
}

Pupitre Note::getPupitre() {
	return pupitre;
}

int Note::getKey() {
	return key;
}

int Note::getVelocity() {
	return velocity;
}

bool Note::operator==(Note note2) {
	return (key == note2.key) && (velocity == note2.velocity);
}

void Note::print() {
	std::cout << "Note{ .timestamp=" << timestamp << "; .signal = " << signal <<
		"; .key = " << key << "; .velocity = " << velocity << " }" << std::endl;
}
