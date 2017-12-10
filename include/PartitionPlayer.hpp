#pragma once

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
	int next = 0;
	QTimer timer;
private slots:
	void playNextNote();
};
