#pragma once

#include <string>
#include <iostream>
#include <QtNetwork>
#include <QByteArray>

class NetworkServer;

class ServerConnection : public QObject {
private:
  NetworkServer *server;
  QTcpSocket *socket;
  std::string username;
  QByteArray pending;

  void setUsername(std::string username);
  void handleJsonDoc(QJsonDocument doc);
  void readyRead();

public:
  ServerConnection(std::string username, QTcpSocket *socket, NetworkServer *server);
  void write(QByteArray msg);
  std::string getUsername();
};
