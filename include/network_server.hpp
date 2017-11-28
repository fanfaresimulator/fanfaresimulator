#pragma once

#include <string>
#include <iostream>
#include <unordered_set>
#include <functional>
#include <QtNetwork>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QByteArray>

#include "network_utils.hpp"
#include "note.hpp"
#include "instrument.hpp"
#include "serverconnection.hpp"

class NetworkServer : public QObject {
private:
  QTcpServer *server;
  std::unordered_set<ServerConnection*> clients;

  void newConnection();
  void sendJsonObject(std::string username, QJsonObject obj);
  void broadcast(QJsonObject obj);

public:
  explicit NetworkServer(QObject *parent = Q_NULLPTR);
  void broadcastStart();
  void sendPartition(std::string username);
  void sendInstruments(std::string username);

signals:
  void helloRecv(std::string username);
  void instrumentChoiceRecv(std::string username, Instrument instrument);
  void noteRecv(std::string username, Note note);

};
