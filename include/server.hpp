#pragma once

/***********************/
/*    ENGINE SERVER    */
/***********************/

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <QObject>

#include "instrument.hpp"
#include "note.hpp"
#include "network_server.hpp"
#include "synthesizer.hpp"



class Server  : public QObject {

private:
    NetworkServer* server;

    std::map< std::string, bool > clients;  // key : username, value isReady
    std::map< std::string, Instrument > usrToInstrument;         // key : username, value : Instrument
    std::map< Instrument , bool > instrumentMap;          // key : Instrument, value : available

    void broadcastStart();
    void updateInstrumentMap(Instrument i);

public:

    Server(NetworkServer& server);

public slots:
    void instrumentMapInit(std::list<Instrument>);
    void addClient(std::string username);
    void addInstrument(std::string username, Instrument i);
    void playNote(std::string username, Note note);
    void sendPartition(std::string username, Partition partition);
    void sendInstrumentMap(std::string username);


signals:
    void playNote(Note note);
    void requestPartition(std::string username, Instrument i);
    void requestInstrumentList();

};
