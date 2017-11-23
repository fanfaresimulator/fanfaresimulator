#include "../include/network_client.hpp"

void NetworkClient::sendMessage(std::string msg) {

}

NetworkClient::NetworkClient(std::string username) {
  this->username = username;
}

void NetworkClient::sendHello(std::string username) {
  std::string msg = "";
  this->sendMessage(msg);
}

void NetworkClient::sendInstrumentChoice(Instrument instrument) {

}

void NetworkClient::sendReady(){
  std::string msg = "";
  this->sendMessage(msg);
}

void NetworkClient::sendNote(Note note) {

}
