#pragma once

/***********************/
/*    ENGINE SERVER    */
/***********************/

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <QObject>

#include "partition.hpp"
#include "note.hpp"
#include "network/server.hpp"
#include "pupitre.hpp"
#include "sound_player.hpp"

class Server : public QObject {
private:
    NetworkServer* server;
    Partition* mainPartition;
    Sound_player* sp;

    std::map<std::string, bool> clients;  // key : username, value isReady
    std::map<std::string, Pupitre> usrToPupitre;         // key : username, value : Instrument
    std::map<Pupitre, bool> pupitreMap;          // key : Instrument, value : available

    void broadcastStart();
    void updatePupitreMap(Pupitre p);
    bool everyoneReady();
    void sendPartition(std::string username, Partition partition);
    void sendPupitreMap(std::string username);

public:
    Server(NetworkServer& server, Partition& partition, Sound_player& sp);

public slots:
    void addClient(std::string username);
    void addPupitre(std::string username, Pupitre p);
    void playNote(std::string username, Note note);
    void clientReady(std::string username);
};
