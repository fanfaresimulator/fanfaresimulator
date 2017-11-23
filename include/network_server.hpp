#pragma once

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <QtNetwork>
#include <QObject>
#include <vector>

#include "network_utils.hpp"
#include "note.hpp"
#include "instrument.hpp"

class NetworkServer : public QObject {
private:
  QTcpServer *server;
  std::vector<QTcpSocket*> clients;

  void newConnection();
  void broadcast(std::string msg);

public:
  explicit NetworkServer(QObject *parent = Q_NULLPTR);
  void broadcastStart() const;
  void sendPartition(std::string username);
  void sendInstruments(std::string username);

signals:
  void helloRecv(std::string username);
  void instrumentChoiceRecv(std::string username, Instrument instrument);
  void noteRecv(std::string username, Note note);

};
