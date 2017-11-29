#include "../include/network_client.hpp"

/* PRIVATE */
void NetworkClient::sendJsonObject(QJsonObject o) {
  QJsonDocument doc = QJsonDocument(o);
  QByteArray msg = doc.toJson();
  std::cout << "sending: " << QString(msg).toStdString() << std::endl;
  socket->write(msg);
}

void NetworkClient::readyRead() {
  std::cout << "Client " << username << " is reading :" << std::endl << "##beg##\n";
  QByteArray msg = socket->readAll();
  std::cout <<  QString(msg).toStdString() << std::endl << "##end##\n";

  // parse JSON
  QJsonParseError jerror;
  QJsonDocument doc = QJsonDocument::fromJson(msg, &jerror);
  if(jerror.errorString() != QJsonParseError::ParseError::NoError) {
    std::cout << jerror.errorString().toStdString() << std::endl;
    //return;
  }

  sendHello();
}

/* PUBLIC */
NetworkClient::NetworkClient(std::string username, QObject *parent) :
QObject(parent) {
  this->socket = new QTcpSocket(this);
  // socket->connectToHost(QHostAddress("127.0.0.1"), PORT_NO);
  this->socket->connectToHost(QHostAddress::SpecialAddress::LocalHost, PORT_NO);
  connect(socket, &QIODevice::readyRead, this, &NetworkClient::readyRead);
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
