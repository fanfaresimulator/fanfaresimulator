#include "../include/network_client.hpp"

/* PRIVATE */
void NetworkClient::sendJsonObject(QJsonObject o) {
  QJsonDocument doc = QJsonDocument(o);
  QByteArray msg = doc.toJson();
  socket->write(msg);
}

void NetworkClient::readyRead() {
  std::cout << "Client " << username << " is reading :" << std::endl;
  QByteArray msg = socket->readAll();
  std::cout <<  msg.toStdString() << std::endl << "end \n";
}

/* PUBLIC */
NetworkClient::NetworkClient(std::string username, QObject *parent) :
QObject(parent) {
  socket = new QTcpSocket(this);
  socket->connectToHost(QHostAddress("127.0.0.1"), 15051);
  // connect(socket, &QIODevice::readyRead, this, &NetworkClient::read);
  this->username = username;
  std::cout << "new client: " << username << std::endl;
}

void NetworkClient::sendHello() {
  QJsonObject obj;
  obj["type"] = SIG_HELLO;
  obj["data"] = QString::fromStdString(username);
  this->sendJsonObject(obj);
}

void NetworkClient::sendInstrumentChoice(Instrument instrument) {
  QJsonObject obj;
  obj["type"] = SIG_CHOICE_INSTRUMENT;
  obj["data"] = QString::fromStdString("NOT YET IMPLEMENTED");
  this->sendJsonObject(obj);
}

void NetworkClient::sendReady(){
  QJsonObject obj;
  obj["type"] = SIG_READY;
  this->sendJsonObject(obj);
}

void NetworkClient::sendNote(Note note) {
  QJsonObject obj;
  obj["type"] = SIG_NOTE;
  obj["data"] = QString::fromStdString("NOT YET IMPLEMENTED");
  this->sendJsonObject(obj);
}
