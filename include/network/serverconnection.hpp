#pragma once

#include <string>
#include <iostream>
#include <QtNetwork>
#include <QByteArray>

class NetworkServer;

class ServerConnection : public QObject {
  Q_OBJECT
private:
  NetworkServer *server;
  QTcpSocket *socket;
  std::string username;
  QByteArray pending;
  int remainingBytes;

  void setUsername(std::string username);
  void handleJsonDoc(QJsonDocument doc);
  void readyRead();

public:
  ServerConnection(std::string username, QTcpSocket *socket, NetworkServer *server);
  void write(QByteArray msg);
  void write(int n);
  std::string getUsername();

signals:
  void pingRecv(std::string username);
};
