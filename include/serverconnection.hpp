#pragma once

#include <string>
#include <iostream>
#include <QtNetwork>

class ServerConnection : public QObject {
private:
  QTcpSocket *socket;
  std::string username;

  void readyRead();
  void setUsername(std::string username);

public:
  ServerConnection(std::string username, QTcpSocket *socket);

};
