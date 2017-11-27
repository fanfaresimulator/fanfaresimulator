#include "../include/network_client.hpp"

/* PRIVATE */
void NetworkClient::sendJsonObject(QJsonObject o) {
  QJsonDocument doc = QJsonDocument(o);
  QByteArray msg = doc.toJson();
  socket.write(msg);
}

/* PUBLIC */
NetworkClient::NetworkClient(std::string username) {
  this->username = username;
}

void NetworkClient::sendHello() {
  QJsonObject obj;
  obj["type"] = SIG_HELLO;
  obj["data"] = QJsonValue(username.c_str());
  this->sendJsonObject(obj);
}

void NetworkClient::sendInstrumentChoice(Instrument instrument) {
  QJsonObject obj;
  obj["type"] = SIG_CHOICE_INSTRUMENT;
  obj["data"] = "NOT YET IMPLEMENTED";
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
  obj["data"] = "NOT YET IMPLEMENTED";
  this->sendJsonObject(obj);
}
