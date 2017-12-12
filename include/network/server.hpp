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

#include "../synth/instrument.hpp"
#include "../synth/partition.hpp"
#include "../synth/pupitre.hpp"
#include "../synth/note.hpp"
#include "serverconnection.hpp"
#include "network.hpp"
#include "SendAfter.hpp"
#include "DelayEstimator.hpp"

class NetworkServer : public QObject {
  Q_OBJECT
private:
  QTcpServer *server;
  std::vector<ServerConnection*> clients; //<username, name+socket>
  DelayEstimator *delayEstimator;

  void newConnection();
  void sendJsonObject(std::string username, QJsonObject obj);
  void broadcast(QJsonObject obj);
  uint32_t synchronizedBroadcast(QJsonObject obj);

public:
  NetworkServer();
  ~NetworkServer();
  void broadcastStart();
  void sendPartition(std::string username, Partition partition);
  void sendPupitres(std::string username, std::map<Pupitre, bool> pupitres);

signals:
  void helloRecv(std::string username);
  void pupitreChoiceRecv(std::string username, Pupitre pupitre);
  void readyRecv(std::string username);
  void noteRecv(std::string username, Note note);
  void sendAfterStart(QThread::Priority p);
  void started();

public slots:
  void handleHello(std::string username);
};
