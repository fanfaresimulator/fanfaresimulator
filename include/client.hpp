#pragma once

/***********************/
/*    ENGINE CLIENT    */
/***********************/

#include <iostream>
#include <string>
#include "instrument.hpp"
#include "partition.hpp"
#include "note.hpp"
#include "network/client.hpp"
#include "noteglobale.hpp"
#include "partitionglobale.hpp"
#include "state.hpp"

using namespace std;

class Client : public QObject {
	Q_OBJECT
private :
	NetworkClient* net;              // !!! use the class Socket => Remark : waiting for the implementation
	State* state;
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

	Client(NetworkClient& network, std::string username);

	vector<string> pupitreMapToNameVec(std::map<Pupitre, bool>);

	void sendAddClient(std::string username);

	void choosePupitre(Pupitre p);

	void sendNote(Note note);

	void sendReady();


public slots:

	void loadPartition(Partition partition);
	void forwardPupitreMap(std::map<Pupitre, bool>);
	void start();

};
