#include "../include/server.hpp"

#define PORT_NO 15051

Server::Server(QObject *parent) :
QObject(parent) {
  server = new QTcpServer(this);

  connect(server, &QTcpServer::newConnection, this, &Server::newConnection);

  if(server->listen(QHostAddress::Any, PORT_NO) == 0) {
    exit(EXIT_FAILURE);
  }
  // Server Online ! on port : PORT_NO
}

void Server::newConnection() {
  QTcpSocket *clientConnection = server->nextPendingConnection();
  connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);

  clientConnection->write("Hello you !\n");
  clientConnection->disconnectFromHost();
}
