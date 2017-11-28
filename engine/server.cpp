#include "../include/server.hpp"

Server::Server(NetworkServer& server, Synthesizer& synthesizer) {
    this->server = &server;
    this->synthesizer = &synthesizer;

    this->incomingNotes = std::queue<Note>();
    this->clients = std::map< std::string, bool >();
    this->usrToInstrument = std::map< std::string, Instrument >();
    this->instrumentMap = std::map< Instrument , bool >();
}


bool Server::addClient(std::string username) {
    if (username == null){
        throw std::invalid_argument("Username null");
    }
    client.try_emplace(username,false);
    return true;
}

bool Server::addInstrument(std::string username, Instrument i) {
    if (username == null){
        throw std::invalid_argument("Username null");
    }
    // check if username exist in client
    if ( clients.find(username) == m.end() ) {
        // not found
        throw std::invalid_argument("Username not found in clients");
    }
    // found => insert in usrToInstrument
    usrToInstrument.try_emplace(username,i);
    return true;
}

void Server::broadcastStart() const {
    server->broadcastStart();
}

std::map< Instrument , bool > Server::getInstrumentMap() const {
    return std::map< Instrument , bool >();
}

void Server::sendPartition(std::string username) {
    // A vérifier ?
    // synthesizer::getPartition(usrToInstrument(username));
}

void Server::updateInstrumentMap(Instrument i) {
    // check if instrument exist in instrumentMap
    if ( instrumentMap.find(i) == m.end() ) {
        // not found
        throw std::invalid_argument("Instrument not found in instrumentMap");
    }
    // found => update in instrumentMap
    instrumentMap[i]= True;
}
