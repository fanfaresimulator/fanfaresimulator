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



class Server  : public QObject
{
    Q_OBJECT

private:
    NetworkServer* server;
    Synthesizer* synthesizer;

    std::queue<Note> incomingNotes;
    std::map< std::string, bool > clients;  // key : username, vale : (socket, isReady)
    std::map< std::string, Instrument > usrToInstrument;         // key : username, value : Instrument
    std::map< Instrument , bool > instrumentMap;          // key : Instrument, value : available

public:

    Server(NetworkServer& server, Synthesizer& synthesizer);

    ~Server();

    void broadcastStart() const ;
    void updateInstrumentMap(Instrument i) ;
    void sendPartition(std::string username) ;
    std::map< Instrument , bool > getInstrumentMap() const;


public slots:
    bool addClient(std::string username);
    bool addInstrument(std::string username, Instrument i);
    void playNote(std::string username, Note note);

};
