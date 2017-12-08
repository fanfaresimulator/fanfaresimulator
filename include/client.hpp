#pragma once

/***********************/
/*    ENGINE CLIENT    */
/***********************/

#include <iostream>
#include <string>
#include <QObject>
#include <QApplication>
#include <QHostAddress>
#include "instrument.hpp"
#include "partition.hpp"
#include "note.hpp"
#include "network/client.hpp"
#include "network/discoverer.hpp"
#include "../gui/game_window.hpp"
#include "noteglobale.hpp"
#include "partitionglobale.hpp"
#include "state.hpp"
#include "PupitreWindow.hpp"

using namespace std;

class Client : public QObject {
private:
	QApplication *app;
	Discoverer *discoverer;
	NetworkClient *net;
	PupitreWindow *pupitreWindow;
	GameWindow *game;
	State *state;
	std::string username;            // use nothing ?
	Pupitre pupitre;      // use the class Instrument
	Partition partition;        // Use the class Partition
	PartitionGlobale partitionGlobale; //Use the class NoteGlobale

	// state functions
	void mainStateFunction();

	// send all notes after error from previous
	// it to next expected on note
	void sendNotesAfterError();
	void sendNotesUntilCurrentTime();
	void stateHandleError();

public:
	Client(QApplication *app, std::string username);

	vector<Pupitre> pupitreMapToVec(std::map<Pupitre, bool>);
	void sendAddClient(std::string username);
	void sendNote(Note note);
	void sendReady();

public slots:
	void connectToServer(QHostAddress addr, quint16 port);
	void forwardPupitreMap(std::map<Pupitre, bool>);
	void loadPartition(Partition partition);
	void choosePupitre(Pupitre p);
	void start();
};
