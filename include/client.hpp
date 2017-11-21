#ifndef FANFARESIMULATOR_CLIENT_HPP
#define FANFARESIMULATOR_CLIENT_HPP

/***********************/
/*    ENGINE CLIENT    */
/***********************/

#include <iostream>
#include <string>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

class Client {

private :
    NetworkClient net;              // !!! use the class Socket => Remark : waiting for the implementation
    string username;            // use nothing ?
    Instrument instrument;      // use the class Instrument
    Partition partition;        // Use the class Partition
    Keyboard keyboard;          // !!! Waiting for the class Keyboard

public:

    client();

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
