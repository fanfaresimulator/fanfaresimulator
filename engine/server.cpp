#include "../include/server.hpp"
#include <string>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

// EMITS will be uncommented after the implementation of dependencies will be done

Server::Server(NetworkServer& server) {
    this->server = &server;

    this->clients = std::map< string, bool >();
    this->usrToInstrument = map< std::string, Instrument >();
//    emit requestInstrumentList();

}

/* SLOTS */

void Server::instrumentMapInit(std::list<Instrument> ilist) {
    this->instrumentMap = map< Instrument, bool>();
    for (Instrument i: ilist){
        pair<Instrument, bool> p = pair<Instrument, bool>(i, false);
        this->instrumentMap.insert(p);
    }
}

void Server::addClient(string username) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }
    pair< string, bool > p = pair<string, bool>(username, false);
    clients.insert(p);
}

void Server::addInstrument(string username, Instrument i) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }
    if (i < 0 || i >= INSTRUMENT_NUMBER) {
        throw std::invalid_argument("wrong instrument");
    }
    // check if username exist in clients
    if ( clients.find(username) == clients.end() ) {
        // not found
        throw std::invalid_argument("Username not found in clients");
    }
    // found => insert in usrToInstrument
    pair< string, Instrument > p = pair<string, Instrument >(username, i);
    usrToInstrument.insert(p);

//    emit requestPartiton(username, i);
}

void Server::playNote(std::string username, Note note){

//    emit playNote(note);
}

void Server::sendPartition(std::string username, Partition partition){
    // network need to change function signature in network_server
//    server->sendPartition(username, partition)
}

void Server::sendInstrumentMap(std::map<Instrument, bool> imap) {
//    emit sendInstruments(imap);
}

/* regular methods */

void Server::broadcastStart() {
    server->broadcastStart();
}


void Server::updateInstrumentMap(Instrument i) {
    // check if instrument exist in instrumentMap
    if ( instrumentMap.find(i) == instrumentMap.end() ) {
        // not found
        throw std::invalid_argument("Instrument not found in instrumentMap");
    }
    // found => update in instrumentMap
    instrumentMap[i]= true;
}