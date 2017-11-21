#ifndef FANFARESIMULATOR_NETWORKSERVER_HPP
#define FANFARESIMULATOR_NETWORKSERVER_HPP

#include "note.hpp"
#include "instrument.hpp"
#include "synthesizer.hpp"
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <QtNetwork>
#include <QObject>
#include <vector>

#define PORT_NO 15051

typedef enum {
  HELLO,
  NOTE,
  CHOICE_LOBBY,
  CHOICE_INSTRUMENT,
  READY,
  LOBBIES,
  INSTRUMENTS,
  PARTITION
} protocol_sig;

class NetworkServer : public QObject {
private:
  QTcpServer *server;
  std::vector<QTcpSocket*> clients;

  // std::queue<Note> incomingNotes;
  // Synthesizer synthesizer;

  std::map<std::string, Instrument> usrToInstrument; // key : username, value : Instrument
  std::map<Instrument, bool> instrumentMap; // key : Instrument, value : available

  void newConnection();
  void broadcast(std::string msg);

public:
  explicit NetworkServer(QObject *parent = Q_NULLPTR);
  void broadcastStart() const;
  void updateInstrumentMap(Instrument i);
  void sendPartition(std::string username);
  std::map<Instrument, bool> getInstrumentMap() const;
  std::vector<QTcpSocket> getClients();
};

#endif // FANFARESIMULATOR_NETWORKSERVER_HPP
