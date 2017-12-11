#include "../include/server.hpp"
#include <iostream>
#include <utility>
#include <map>
#include <QTimer>

using namespace std;

Server::Server(NetworkServer& server, Partition& partition, Sound_player& sp) {
    this->server = &server;
    this->mainPartition = &partition;
    this->sp = &sp;

    this->clients = std::map< string, bool >();
    this->usrToPupitre = map< std::string, Pupitre >();
    this->pupitreMap = map< Pupitre , bool >();

    vector<Pupitre> plist = partition.getPupitre();
    std::cout << "Number of pupitres: " << plist.size() << std::endl;
    for (Pupitre p : plist) {
        pair< Pupitre, bool > pair(p, false);
        this->pupitreMap.insert(pair);
    }
}

/* regular methods */


void Server::updatePupitreMap(Pupitre p) {
    // check if instrument exist in pupitreMap
    if ( pupitreMap.find(p) == pupitreMap.end() ) {
        // not found
        throw std::invalid_argument("Instrument not found in pupitreMap");
    }
    // found => update in pupitreMap
    pupitreMap[p] = true;
}

void Server::setPlayersNbr(int playersNbr) {
    this->playersNbr = playersNbr;
    if (everyoneReady()) {
        broadcastStart();
    }
}

bool Server::everyoneReady() {
    size_t n = 0;
    for (pair<std::string, bool> clientPaire : clients) {
        if (clientPaire.second) {
            n++;
        }
    }
    if (playersNbr >= 0) {
        return ((int)n == playersNbr);
    }
    return (clients.size() > 0 && n == clients.size());
}

void Server::broadcastStart() {
    server->broadcastStart();

    // TODO: this delay is hardcoded :(
    QTimer *timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &Server::startBots);
    timer->start(500);
}

void Server::startBots() {
    for (pair<Pupitre, bool> p : pupitreMap) {
        if (!p.second) {
            Partition partition = mainPartition->getPartition(p.first);
            PartitionPlayer *pp = new PartitionPlayer(partition, sp);
            bots.push_back(pp);
            pp->start();
        }
    }
}

void Server::sendPartition(std::string username, Partition partition){
    server->sendPartition(username, partition);
}

void Server::sendPupitreMap(std::string username) {
    server->sendPupitres(username, pupitreMap);
}

// SLOTS

void Server::addClient(std::string username) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }
    pair< string, bool > p = pair<string, bool>(username, false);
    clients.insert(p);

    // send pupitre map to client
    sendPupitreMap(username);
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
    pair< string, Pupitre > pair(username, p);
    usrToPupitre.insert(pair);

    // update pupitreMap
    updatePupitreMap(p);

//  send apropriate partition to user
    Partition partition = mainPartition->getPartition(p);
    sendPartition(username, partition);

}

void Server::clientReady(std::string username){
    if (username.empty()) {
        throw std::invalid_argument("Username null");
    }
    // check if username exist in clients
    if ( clients.find(username) == clients.end() ) {
        // not found
        throw std::invalid_argument("Username not found in clients");
    }

    clients[username] = true;

    if (everyoneReady()) {
        std::cout << "Everyone is ready, starting the party NOW!" << std::endl;
        broadcastStart();
    }
}

void Server::playNote(std::string username, Note note){
    sp->playNote(&note);
}
