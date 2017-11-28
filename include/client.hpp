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
#include "network_client.hpp"
#include "noteglobale.hpp"
#include "partitionglobale.hpp"

class Client {

private :
    NetworkClient* net;              // !!! use the class Socket => Remark : waiting for the implementation
    Keyboard* keyboard;          // !!! Waiting for the class Keyboard
    std::string username;            // use nothing ?
    Instrument instrument;      // use the class Instrument
    Partition partition;        // Use the class Partition
	PartitionGlobale partitionglobale; //Use the class NoteGlobale


public:

    Client(NetworkClient& network, Keyboard& keyboard);

    ~Client();

    void sendNote(Note note);

    void sendReady();

    void sendAddClient(std::string username);

    void sendAddInstrumentToClient(std::string username, Instrument instrument);

    void requestPartition(Partition partition);

    void loadPartition(Partition partition);

    void setInstrument(Instrument instrument);

	PartitionGlobale setPartitionGlobale();

};
