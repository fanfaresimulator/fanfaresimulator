#include "../include/server.hpp"
#include <string>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

// EMITS will be uncommented after the implementation of dependencies will be done

Server::Server(NetworkServer& server, Partition& partition, Sound_player& sp) {
    this->server = &server;
    this->mainPartition = &partition;
    this->sp = &sp;

    this->clients = std::map< string, bool >();
    this->usrToPupitre = map< std::string, Pupitre >();
    this->pupitreMap = map< Pupitre , bool >();

    vector<Pupitre> plist = partition.getPupitre();
    for(Pupitre p : plist){
        pair< Pupitre, bool > pair = pair< Pupitre, bool >(p, false);
        this->pupitreMap.insert(pair);
    }
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
    updatePupitreMap(p);

//  send apropriate partition to user
    Partition partition = mainPartition->getPartition(p);
    sendPartition(username, partition);

}

void Server::playNote(std::string username, Note note){
    sp->playNote(&note);
}

void Server::sendPartition(std::string username, Partition partition){
    server->sendPartition(username, partition);

}

void Server::sendPupitreMap(std::string username, std::map< Pupitre , bool > pMap) {
    server->sendPupitres(username, pupitreMap);
}

void Server::clientReady(std::string username, Note note){
    // check if username exist in clients
    if ( clients.find(username) == clients.end() ) {
        // not found
        throw std::invalid_argument("Username not found in clients");
    }

    clients[username] = true;

    if(everyoneReady()) {
        broadcastStart();
    }
}





