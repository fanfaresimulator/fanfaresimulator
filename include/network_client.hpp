#pragma once

#include <iostream>
#include <string>
#include <QTcpSocket>

#include "network_utils.hpp"
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

class NetworkClient {

private:
  QTcpSocket socket;
  std::string username;

  void sendMessage(std::string msg);

public:
  NetworkClient(std::string username);

  void sendHello(std::string username);
  void sendInstrumentChoice(Instrument instrument);
  void sendReady();
  void sendNote(Note note);

signals:
  /* Emit a signal that sends the partition */
  void partitionArrived(Partition partition);
};
