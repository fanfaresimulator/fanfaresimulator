#include "../include/server.hpp"

Server::Server(NetworkServer& server, Synthesizer& synthesizer) {
    this->server = &server;
    this->synthesizer = &synthesizer;
    this->incomingNotes = new std::queue<Note>();
}


bool Server::addClient(std::string username) {
    return false;
}

bool Server::addInstrument(std::string username, Instrument i) {
    return false;
}

void Server::broadcastStart() const {

}

std::map< Instrument , bool > Server::getInstrumentMap() const {
    return std::map< Instrument , bool >();
}

void Server::sendPartition(std::string username) {

}

void Server::updateInstrumentMap(Instrument i) {

}
