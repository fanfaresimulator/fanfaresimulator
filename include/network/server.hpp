#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <QtNetwork>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QByteArray>

#include "../instrument.hpp"
#include "../partition.hpp"
#include "../pupitre.hpp"
#include "../note.hpp"
#include "network.hpp"
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
  void sendPupitres(std::string username, std::map<Pupitre, bool> pupitres);

signals:
  void helloRecv(std::string username);
  void instrumentChoiceRecv(std::string username, Instrument instrument);
  void readyReceived(std::string username);
  void noteRecv(std::string username, Note note);
};
