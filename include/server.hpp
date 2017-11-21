
#ifndef FANFARESIMULATOR_SERVER_HPP
#define FANFARESIMULATOR_SERVER_HPP

#include "note.hpp"
#include "instrument.hpp"
#include "synthesizer.hpp"
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <QtNetwork>
#include <QObject>
#include <vector>

typedef enum {
  HELLO,
  NOTE,
  CHOICE_LOBBY,
  CHOICE_INSTRUMENT,
  LOBBIES,
  INSTRUMENTS,
  PARTITION
} protocol_sig;

class Server : public QObject {
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
  explicit Server(QObject *parent = Q_NULLPTR);
  void broadcastStart() const;
  void updateInstrumentMap(Instrument i);
  void sendPartition(std::string username);
  std::map<Instrument, bool> getInstrumentMap() const;
  std::vector<QTcpSocket> getClients();
};

#endif // FANFARESIMULATOR_SERVER_HPP
