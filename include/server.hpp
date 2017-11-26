#pragma once

/***********************/
/*    ENGINE SERVER    */
/***********************/

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include "instrument.hpp"
#include "note.hpp"
#include "network_server.hpp"
#include "synthesizer.hpp"


class Server {
private:
    NetworkServer serveur;
    std::queue incomingNotes;
    Synthesizer synthesizer;

    std::map< std::string, std::pair< NetworkServer, bool > > clients;  // key : username, vale : (socket, isReady)
    std::map< std::string, Instrument > usrToInstrument;         // key : username, value : Instrument
    std::map< Instrument , bool > instrumentMap;          // key : Instrument, value : available

public:

    Server();

    Server(NetworkServer serverSocket);

    ~Server();

    void broadcastStart() const ;

    void updateInstrumentMap(Instrument i) ;

    bool addClient(std::string username) ;

    bool addClient(std::string username, Instrument i) ;

    void sendPartition(std::string username) ;

    std::map< Instrument , bool > getInstrumentMap() const ;

};
