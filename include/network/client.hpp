#pragma once

#include <iostream>
#include <string>
#include <map>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QByteArray>

#include "../instrument.hpp"
#include "../partition.hpp"
#include "../note.hpp"
#include "network.hpp"

class NetworkClient : public QObject {
private:
  QTcpSocket *socket;
  std::string username;

  void sendJsonObject(QJsonObject o);
  void handleJsonDoc(QJsonDocument doc);
  void readyRead();

public:
  explicit NetworkClient(std::string username, QObject *parent = Q_NULLPTR);
  void sendHello();
  void sendPupitreChoice(Pupitre pupitre);
  void sendReady();
  void sendNote(Note note);

signals:
  /* Emit a signal that sends the partition */
  void partitionRecv(Partition partition);
  void pupitresRecv(std::map<Pupitre, bool>);
  void startRecv();

};
