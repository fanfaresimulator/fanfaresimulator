#include "../include/network_server.hpp"

void NetworkServer::newConnection() {
  QTcpSocket *clientConnection = server->nextPendingConnection();
  connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);

  clients.push_back(clientConnection);
  clientConnection->write("Hello you !\n");
  clientConnection->disconnectFromHost();
}

void NetworkServer::broadcast(std::string msg) {
    for (int i = 0; i < clients.size(); i++) {
      (clients[i])->write(msg.c_str());
    }
}

NetworkServer::NetworkServer(QObject *parent) :
QObject(parent) {
  server = new QTcpServer(this);

  connect(server, &QTcpServer::newConnection, this, &NetworkServer::newConnection);

  if(server->listen(QHostAddress::Any, PORT_NO) == 0) {
    exit(EXIT_FAILURE);
  }
  // NetworkServer Online ! on port : PORT_NO
}

void broadcastStart() {

}

void sendPartition(std::string username) {

}

void sendInstruments(std::string username) {

}

void helloRecv(std::string username) {

}

void instrumentChoiceRecv(std::string username, Instrument instrument) {

}

void noteRecv(std::string username, Note note) {
  
}
