//
// Created by steven athouel on 16/11/2017.
//

#ifndef FANFARESIMULATOR_SERVER_HPP
#define FANFARESIMULATOR_SERVER_HPP

#include <iostream>
#include <queue>
#include <map>
#include "instrument.hpp"

typedef std::basic_string<char> string;

// Waiting for implementation
class Obj{};

typedef Obj ServerSocket;
typedef Obj Socket;
typedef Obj Synthesizer;

//

class Server {
private:
    ServerSocket serverSocket;
    std::queue incomingNotes;
    Synthesizer synthesizer;

    std::map< string, std::pair< Socket, bool > > clients;  // key : username, vale : (socket, isReady)
    std::map< string, Instrument > usrToInstrument;         // key : username, value : Instrument
    std::map< Instrument , bool > instrumentMap;          // key : Instrument, value : available

public:

    Server();

    Server(ServerSocket serverSocket);

    ~Server();

    void broadcastStart() const ;

    void updateInstrumentMap(Instrument i) ;

    bool addClient(string username) ;

    bool addClient(string username, Instrument i) ;

    void sendPartition(string username) ;

    std::map< Instrument , bool > getInstrumentMap() const ;



};




#endif //FANFARESIMULATOR_SERVER_HPP
