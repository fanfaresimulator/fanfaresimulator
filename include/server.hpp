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
#include "synthesizer.hpp"
#include "pupitre.hpp"



class Server  : public QObject {

private:
    NetworkServer* server;
    Partition* mainPartition;

    std::map< std::string, bool > clients;  // key : username, value isReady
    std::map< std::string, Pupitre > usrToPupitre;         // key : username, value : Instrument
    std::map< Pupitre , bool > pupitreMap;          // key : Instrument, value : available

    void broadcastStart();
    void updatePupitreMap(Pupitre p);
    bool everyoneReady();
    // add method everyone ready

public:

    Server(NetworkServer& server, Partition& partition);

public slots:
    void pupitreMapInit(std::list<Pupitre>);
    void addClient(std::string username);
    void addPupitre(std::string username, Pupitre p);
    void playNote(std::string username, Note note);
    void sendPartition(std::string username, Partition partition);
    void sendPupitreMap(std::string username, std::map< Pupitre , bool > pMap);


signals:
    void playNote(Note note);
    void requestPartition(std::string username, Instrument i);
    void requestPupitreList();

};
