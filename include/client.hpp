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

class Client {

private :
    NetworkClient net;              // !!! use the class Socket => Remark : waiting for the implementation
    std::string username;            // use nothing ?
    Instrument instrument;      // use the class Instrument
    Partition partition;        // Use the class Partition
    Keyboard keyboard;          // !!! Waiting for the class Keyboard

public:

    Client();

    ~Client();

    void sendNote(Note note);

    void sendReady();

    void sendAddClient(std::string username);

    void sendAddInstrumentToClient(std::string username, Instrument instrument);

    void requestPartition(Partition partition);

    void loadPartition(Partition partition);

    Instrument setInstrument();

};
