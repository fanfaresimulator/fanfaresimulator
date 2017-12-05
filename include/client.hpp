#pragma once

/***********************/
/*    ENGINE CLIENT    */
/***********************/

#include <iostream>
#include <string>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"
#include "network/client.hpp"
#include "noteglobale.hpp"
#include "partitionglobale.hpp"

class Client : public QObject {

private :
    NetworkClient* net;              // !!! use the class Socket => Remark : waiting for the implementation
    Keyboard* keyboard;          // !!! Waiting for the class Keyboard
    std::string username;            // use nothing ?
    Pupitre pupitre;      // use the class Instrument
    Partition partition;        // Use the class Partition
	PartitionGlobale partitionglobale; //Use the class NoteGlobale


public:

	// need to check with keyboard team !
    //Client(NetworkClient& network, Keyboard& keyboard);
	Client(NetworkClient& network, std::string username);

    void sendAddClient(std::string username);

    void choosePupitre(Pupitre p);

    void sendNote(Note note);

    void sendReady();


public slots:

    void loadPartition(Partition partition);
	void forwardPupitreMap(std::map<Pupitre, bool>);
	void start();

};
