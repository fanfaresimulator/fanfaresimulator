#include "../include/client.hpp"

Client::Client(NetworkClient& network, Keyboard& keyboard) {
    this->net = &network;
    this->keyboard = &keyboard;

}


void Client::sendNote(Note note) {

}

void Client::sendReady() {

}

void Client::sendAddClient(std::string username) {

}

void Client::sendAddInstrumentToClient(std::string username, Instrument instrument) {

}

void Client::requestPartition(Partition partition) {

}

void Client::loadPartition(Partition partition) {

}

void Client::setInstrument(Instrument instrument) {
    this->instrument = instrument;
}
