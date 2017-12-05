#include "../include/server.hpp"
#include <string>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

// EMITS will be uncommented after the implementation of dependencies will be done

Server::Server(NetworkServer& server, Partition& partition) {
    this->server = &server;
    this->mainPartition = &partition;
    this->clients = std::map< string, bool >();
    this->usrToPupitre = map< std::string, Pupitre >();
    this->pupitreMap = map< Pupitre , bool >();

    vector<Pupitre> plist = partition.getPupitre();
    for(Pupitre p : plist){
        pair< Pupitre, bool > pair = pair< Pupitre, bool >(p, false);
        this->pupitreMap.insert(pair);
    }
}

bool Server::everyoneReady() {
    for(pair clientPaire : clients){
        if(!clientPaire.second) return false;
    }
    return true;
}
// SLOTS

void Server::addClient(string username) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }
    pair< string, bool > p = pair<string, bool>(username, false);
    clients.insert(p);
}

void Server::addPupitre(string username, Pupitre p) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }

    // check if username exist in clients
    if ( clients.find(username) == clients.end() ) {
        // not found
        throw std::invalid_argument("Username not found in clients");
    }
    // found => insert in usrToPupitre
    pair< string, Pupitre > pair = pair<string, Pupitre >(username, p);
    usrToPupitre.insert(pair);

    // update pupitreMap
    pupitreMap[p] = true;

//    emit requestPartition(username, p);
}

void Server::playNote(std::string username, Note note){

//    emit playNote(note);
}

void Server::sendPartition(std::string username, Partition partition){
    // network need to change function signature in network_server
//    server->sendPartition(username, partition)

}

void Server::sendPupitreMap(std::string username, std::map< Pupitre , bool > pMap) {
    // change signature of server network + add signal to server network request instruments
//    server->sendInstruments(username, pupitreMap);
}

/* regular methods */

void Server::broadcastStart() {
    server->broadcastStart();
}


void Server::updatePupitreMap(Pupitre p) {
     // check if instrument exist in pupitreMap
     if ( pupitreMap.find(p) == pupitreMap.end() ) {
         // not found
         throw std::invalid_argument("Instrument not found in pupitreMap");
     }
     // found => update in pupitreMap
     pupitreMap[p] = true;
}
