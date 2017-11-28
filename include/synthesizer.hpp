#pragma once

#include <iostream>
#include <QObject>
#include "instrument.hpp"
#include "note.hpp"
#include "partition.hpp"

class Synthesizer  : public QObject
{

Q_OBJECT

private:
	Partition mainPartition;

public:
	Synthesizer();

	Synthesizer(Partition mainPartition);

	~Synthesizer();

	void playNote(Note note);

public slots:
	Partition getPartition(std::string username, Partition partition);

signals:
    void sendPartition(std::string username, Partition partition);
};
