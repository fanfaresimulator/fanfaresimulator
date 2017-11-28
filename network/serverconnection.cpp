#include "../include/serverconnection.hpp"

/* PRIVATE */
void ServerConnection::readyRead() {
  std::cout << "Reading from " << username << std::endl << "##beg##\n";
  QByteArray msg = socket->readAll();
  std::cout <<  msg.toStdString() << std::endl << "##end##\n";

  QJsonParseError jerror;
  QJsonDocument doc = QJsonDocument::fromJson(msg, &jerror);
  if(jerror.errorString() != QJsonParseError::ParseError::NoError) {
    std::cout << jerror.errorString().toStdString() << std::endl;
    return;
  }
}

void ServerConnection::setUsername(std::string username) {
  this->username = username;
}


/* PUBLIC */
ServerConnection::ServerConnection(std::string username, QTcpSocket *socket) {
  this->username = username;
  this->socket = socket;
  connect(this->socket, &QIODevice::readyRead, this, &ServerConnection::readyRead);
}

void ServerConnection::write(QByteArray msg) {
  socket->write(msg);
}

std::string ServerConnection::getUsername() {
  return username;
}
