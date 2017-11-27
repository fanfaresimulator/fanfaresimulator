#include "../include/network_server.hpp"

/* PRIVATE */
void NetworkServer::newConnection() {
  QTcpSocket *clientConnection = server->nextPendingConnection();
  connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);

  std::string username;
  clients[username] = clientConnection;
  clientConnection->write("Hello you !\n");
  clientConnection->disconnectFromHost();
}

void NetworkServer::sendJsonObject(std::string username, QJsonObject obj) {
  for (size_t i = 0; i < clients.size(); i++) {
    auto search = clients.find(username);
    if (search != clients.end()) {
      QJsonDocument doc = QJsonDocument(obj);
      QByteArray msg = doc.toJson();
      search->second->write(msg);
    }
  }
  // error
  printf("Not such client found: %s\n", username);
}

void NetworkServer::broadcast(QJsonObject obj) {
  QJsonDocument doc = QJsonDocument(obj);
  QByteArray msg = doc.toJson();
  // for each element e of the HashMap clients
  for (const auto& e : clients) {
    e.second->write(msg);
  }
}

/* PUBLIC */
NetworkServer::NetworkServer(QObject *parent) :
QObject(parent) {
  server = new QTcpServer(this);

  connect(server, &QTcpServer::newConnection, this, &NetworkServer::newConnection);

  if(server->listen(QHostAddress::Any, PORT_NO) == 0) {
    exit(EXIT_FAILURE);
  }
  // NetworkServer Online ! on port : PORT_NO
}

void NetworkServer::broadcastStart() {
  QJsonObject obj;
  obj["type"] = SIG_START;
  broadcast(obj);
}

void NetworkServer::sendPartition(std::string username) {
  QJsonObject obj;
  obj["type"] = SIG_PARTITION;
  obj["data"] = "NOT YET IMPLEMENTED";
  sendJsonObject(username, obj);
}

void NetworkServer::sendInstruments(std::string username) {
  QJsonObject obj;
  obj["type"] = SIG_INSTRUMENTS;
  obj["data"] = "NOT YET IMPLEMENTED";
  sendJsonObject(username, obj);
}
