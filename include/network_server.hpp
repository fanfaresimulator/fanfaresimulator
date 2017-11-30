#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <QtNetwork>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QByteArray>

#include "network_utils.hpp"
#include "note.hpp"
#include "instrument.hpp"
#include "partition.hpp"
#include "serverconnection.hpp"

class NetworkServer : public QObject {
  Q_OBJECT
private:
  QTcpServer *server;
  std::vector<ServerConnection*> clients; //<username, name+socket>

  void newConnection();
  void sendJsonObject(std::string username, QJsonObject obj);
  void broadcast(QJsonObject obj);

public:
  explicit NetworkServer(QObject *parent = Q_NULLPTR);
  void broadcastStart();
  void sendPartition(std::string username, Partition partition);
  void sendInstruments(std::string username, std::list<Instrument> instruments);

signals:
  void helloRecv(std::string username);
  void instrumentChoiceRecv(std::string username, Instrument instrument);
  void readyReceived(std::string username);
  void noteRecv(std::string username, Note note);
};
