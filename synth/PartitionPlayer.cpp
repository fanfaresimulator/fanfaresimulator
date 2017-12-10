#include "../include/PartitionPlayer.hpp"

PartitionPlayer::PartitionPlayer(Partition partition, Sound_player *sp) :
		QObject(), partition(partition), sp(sp) {
	timer.setSingleShot(true);
	connect(&timer, SIGNAL(timeout()), this, SLOT(playNextNote()));
}

void PartitionPlayer::start() {
	playNextNote();
}

void PartitionPlayer::playNextNote() {
	std::vector<Note> notes = partition.getNotes();
	if (next >= notes.size()) {
		return;
	}

	Note *n = &notes[next];
	sp->playNote(n);

	next++;
	if (next >= notes.size()) {
		return;
	}

	timer.start(1000 * (notes[next].getTime() - n->getTime()));
}
