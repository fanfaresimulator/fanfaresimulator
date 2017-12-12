#include "../include/network/server.hpp"
#include "../include/network/DelayEstimator.hpp"

/* PRIVATE */
void NetworkServer::newConnection() {
  QTcpSocket *clientConnection = server->nextPendingConnection();
  // The delete later is a problem for classes having a pointer to the client Socket (DelayEstimator)
  // connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);

  std::string username = "";
  ServerConnection *client = new ServerConnection(username, clientConnection, this);
  clients.push_back(client);
  std::cout << "new client" << std::endl;
}

void NetworkServer::sendJsonObject(std::string username, QJsonObject obj) {
  for (size_t i = 0; i < clients.size(); i++) {
    if (clients[i]->getUsername() == username) {
      clients[i]->write(obj);
      return;
    }
  }
  printf("Not such client found: %s\n", username.c_str());
}

void NetworkServer::broadcast(QJsonObject obj) {
  // for each element e of the Set clients
  for (size_t i = 0; i < clients.size(); i++) {
    clients[i]->write(obj);
  }
}

// Using the ping estimation so that clients receive the messages at the same time
void NetworkServer::synchronizedBroadcast(QJsonObject obj) {
  std::map<std::string, uint32_t> pings = delayEstimator->getPings();
  uint32_t maxPing = delayEstimator->maxPing();
  // std::vector<SendAfter*> senders;
  for (size_t i = 0; i < clients.size(); i++) {
    auto ping = pings.find(clients[i]->getUsername());
    if (ping != pings.end()) {
      SendAfter *s = new SendAfter(this, obj, maxPing - ping->second);
      connect(s, &SendAfter::sendNow, clients[i], &ServerConnection::sendNow);
      // senders.push_back();
    } else {
      std::cout << "Can't find "<< clients[i]->getUsername() << " in pings\n";
    }
  }
  emit sendAfterStart(QThread::NormalPriority);
  // emit startIn(maxPing) // for the bots to start
}

/* PUBLIC */
NetworkServer::NetworkServer() {
  server = new QTcpServer(this);
  delayEstimator = new DelayEstimator();

  connect(server, &QTcpServer::newConnection, this, &NetworkServer::newConnection);
  connect(this, &NetworkServer::helloRecv, this, &NetworkServer::handleHello);

  if(server->listen(QHostAddress::Any, PORT_NO) == 0) {
    exit(EXIT_FAILURE);
  }
  std::cout << "NetworkServer Online ! on port: " << PORT_NO << std::endl;
}

NetworkServer::~NetworkServer() {
  delete delayEstimator;
  delete server;
}

void NetworkServer::broadcastStart() {
  QJsonObject obj;
  obj["type"] = SIG_START;
  synchronizedBroadcast(obj);
}

void NetworkServer::sendPartition(std::string username, Partition partition) {
  QJsonObject obj;
  obj["type"] = SIG_PARTITION;
  obj["data"] = partitionToJson(partition);
  sendJsonObject(username, obj);
}

void NetworkServer::sendPupitres(std::string username, std::map<Pupitre, bool> pupitres) {
  QJsonObject obj;
  obj["type"] = SIG_PUPITRES;
  QJsonArray JsonPupitre;
  for (auto & pair : pupitres) {
    JsonPupitre.append(pupitreToJson(pair.first, pair.second));
  }
  obj["data"] = JsonPupitre;
  sendJsonObject(username, obj);
}

void NetworkServer::handleHello(std::string username) {
  for (size_t i = 0; i < clients.size(); i++) {
    if (clients[i]->getUsername() == username) {
      delayEstimator->addServerConnection(clients[i]);
    }
  }
}
