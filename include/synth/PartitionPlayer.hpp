#pragma once

#include <QTime>
#include <QTimer>
#include "partition.hpp"
#include "sound_player.hpp"

class PartitionPlayer : public QObject {
	Q_OBJECT
public:
	PartitionPlayer(Partition partition, Sound_player *sp);
	void start();
private:
	Partition partition;
	Sound_player *sp;
	size_t next = 0;
	QTime t0;
	QTimer timer;
private slots:
	void playNextNote();
	void scheduleNextNote();
};
