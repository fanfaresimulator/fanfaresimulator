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

#include "../synth/instrument.hpp"
#include "../synth/partition.hpp"
#include "../synth/note.hpp"
#include "network.hpp"

class NetworkClient : public QObject {
  Q_OBJECT
private:
  QTcpSocket *socket;
  std::string username;
  QByteArray pending;
  int remainingBytes;

  void sendJsonObject(QJsonObject o);
  void handleJsonDoc(QJsonDocument doc);
  void readyRead();

public:
  explicit NetworkClient(QHostAddress addr, quint16 port, std::string username, QObject *parent = Q_NULLPTR);
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
