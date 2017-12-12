#pragma once

/***********************/
/*    ENGINE CLIENT    */
/***********************/

#include <iostream>
#include <string>
#include <QObject>
#include <QApplication>
#include <QHostAddress>
#include <cmath>
#include <QTimer>

#include "synth/instrument.hpp"
#include "synth/partition.hpp"
#include "synth/note.hpp"
#include "synth/noteglobale.hpp"
#include "synth/partitionglobale.hpp"
#include "network/client.hpp"
#include "network/discoverer.hpp"
#include "gui/game_window.hpp"
#include "gui/PupitreWindow.hpp"
#include "engine/state.hpp"

using namespace std;

// Number of keyboard keys
#define KEYS_NUMBER 4

class Client : public QObject {
private:
	QApplication *app;
	QTimer * timer;
	std::string username;
	Discoverer *discoverer = nullptr;
	NetworkClient *net = nullptr;
	PupitreWindow *pupitreWindow = nullptr;
	GameWindow *game = nullptr;
	State *state = nullptr;
	Pupitre *pupitre = nullptr;
	Partition *partition = nullptr;
	PartitionGlobale *partitionGlobale = nullptr;
	// For each key, gives the currently pressed Note
	std::vector<Note *> pressedNotes = std::vector<Note *>(KEYS_NUMBER, nullptr);

	// send all notes after error from previous
	// it to next expected on note
	void sendNotesAfterError();
	void sendNotesUntilCurrentTime();
	void stateHandleError();

	vector<Pupitre> pupitreMapToVec(std::map<Pupitre, bool>);
	void sendAddClient(std::string username);
	void sendNote(Note note);
	void sendReady();

public:
	Client(QApplication *app, std::string username);

public slots:
	void timerSendNotes();
	void connectToServer(QHostAddress addr, quint16 port);
	void forwardPupitreMap(std::map<Pupitre, bool>);
	void loadPartition(Partition partition);
	void choosePupitre(Pupitre p);
	void start();
	void pressKey(int key, double t, bool pressed);
};
