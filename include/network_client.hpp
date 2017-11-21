#ifndef FANFARESIMULATOR_CLIENT_HPP
#define FANFARESIMULATOR_CLIENT_HPP

#include <iostream>
#include <string>
#include <QTcpSocket>

#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

class NetworkClient {

private:
  QTcpSocket socket;
  std::string username;

public:
  NetworkClient(std::string username);
  ~NetworkClient();

  void sendNote(Note note);
  void sendReady();
  void sendHello(std::string username);
  void sendInstrumentChoice(std::string username, Instrument instrument);
  void getPartition();

  Instrument setInstrument();
};


#endif //FANFARESIMULATOR_CLIENT_HPP
