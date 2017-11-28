#pragma once

#include <iostream>
#include <string>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QByteArray>

#include "network_utils.hpp"
#include "instrument.hpp"
#include "partition.hpp"
#include "keyboard.hpp"
#include "note.hpp"

class NetworkClient : public QObject {
private:
  QTcpSocket socket;
  std::string username;

  void sendJsonObject(QJsonObject o);

public:
  NetworkClient(std::string username);

  void sendHello();
  void sendInstrumentChoice(Instrument instrument);
  void sendReady();
  void sendNote(Note note);

signals:
  /* Emit a signal that sends the partition */
  void partitionArrived(Partition partition);
};
