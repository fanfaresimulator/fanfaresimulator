#pragma once

#include <iostream>
#include <string>
#include <list>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QByteArray>

#include "../instrument.hpp"
#include "../partition.hpp"
#include "../keyboard.hpp"
#include "../note.hpp"
#include "network.hpp"

class NetworkClient : public QObject {
  Q_OBJECT
private:
  QTcpSocket *socket;
  std::string username;

  void sendJsonObject(QJsonObject o);
  void handleJsonDoc(QJsonDocument doc);
  void readyRead();

public:
  explicit NetworkClient(std::string username, QObject *parent = Q_NULLPTR);
  void sendHello();
  void sendInstrumentChoice(Instrument instrument);
  void sendReady();
  void sendNote(Note note);

signals:
  /* Emit a signal that sends the partition */
  void partitionRecv(Partition partition);
  void pupitresRecv(std::list<Pupitre>);
  void startRecv();
};
