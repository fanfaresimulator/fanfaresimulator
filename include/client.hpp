//
// Created by Ragel on 21/11/2017.
//

#ifndef FANFARESIMULATOR_CLIENT_HPP
#define FANFARESIMULATOR_CLIENT_HPP

#include <iostream>
#include <string>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

// Waiting for implementation
class Obj_1{};

typedef Obj Socket;


//

class client {

private :
    Socket socket;              // !!! use the class Socket => Remark : waiting for the implementation
    string username;            // use nothing ?
    Instrument instrument;      // use the class Instrument
    Partition partition;        // Use the class Partition
    Keyboard keyboard;          // !!! Waiting for the class Keyboard

public:

    client();

    // Other constructer can be created

    ~client();

    void sendNote(Note note);

    void sendReady();

    void sendAddClient(string username);

    void sendAddInstrumentToClient(string username, Instrument instrument);

    void requestPartition(Partition partition);

    void loadPartition(Partition partition);

    Instrument setInstrument();


};


#endif //FANFARESIMULATOR_CLIENT_HPP
