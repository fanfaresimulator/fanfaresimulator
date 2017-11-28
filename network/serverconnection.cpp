#include "../include/serverconnection.hpp"

ServerConnection::ServerConnection(std::string username, QTcpSocket *socket) {
  this->username = username;
  this->socket = socket;
  connect(this->socket, &QIODevice::readyRead, this, &ServerConnection::readyRead);
}


void ServerConnection::readyRead() {
  QByteArray msg = socket->readAll();
  std::cout << username << " is reading :" << std::endl;
  std::cout << msg.toStdString() << std::endl << "end\n";
}
