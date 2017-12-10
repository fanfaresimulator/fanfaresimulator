#include "../include/PartitionPlayer.hpp"

PartitionPlayer::PartitionPlayer(Partition partition, Sound_player *sp) :
		QObject(), partition(partition), sp(sp) {
	timer.setSingleShot(true);
	connect(&timer, SIGNAL(timeout()), this, SLOT(playNextNote()));
}

void PartitionPlayer::start() {
	t0.start();
	scheduleNextNote();
}

void PartitionPlayer::scheduleNextNote() {
	std::vector<Note> notes = partition.getNotes();
	if (next >= notes.size()) {
		return;
	}

	int dt = 1000 * notes[next].getTime() - t0.elapsed();
	if (dt < 0) {
		dt = 0;
	}
	timer.start(dt);
}

void PartitionPlayer::playNextNote() {
	std::vector<Note> notes = partition.getNotes();
	if (next >= notes.size()) {
		return;
	}

	Note *n = &notes[next];
	sp->playNote(n);

	next++;
	scheduleNextNote();
}
