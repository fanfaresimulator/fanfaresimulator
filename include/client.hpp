#ifndef FANFARESIMULATOR_CLIENT_HPP
#define FANFARESIMULATOR_CLIENT_HPP

#include <iostream>
#include <string>
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

class client {

private:
  Socket socket;              // !!! use the class Socket => Remark : waiting for the implementation
  string username;            // use nothing ?
  Instrument instrument;      // use the class Instrument
  Partition partition;
  Keyboard keyboard;          // !!! Waiting for the class Keyboard

public:

  client();

  // Other constructer can be created

  ~client();

  void sendNote(Note note);
  void sendReady();
  void sendHello(string username);
  void sendInstrumentChoice(string username, Instrument instrument);
  void getPartition(Partition partition);

  Instrument setInstrument();
};


#endif //FANFARESIMULATOR_CLIENT_HPP
