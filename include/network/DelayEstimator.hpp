#pragma once

#include <map>
#include <list>
#include <utility>

#include "serverconnection.hpp"
#include "network.hpp"

#define PING_COUNT 10

typedef struct {
  ServerConnection *sc;
  uint32_t estimate;
  QTime lastSent;
  // std::map<ping, pair<t0,t1> > pings; // pings with send/receive time
  QTime lastEstimate;
} DelayConnection;

typedef std::pair<std::string, DelayConnection*> DE_element;
typedef std::map<std::string, DelayConnection*> DE_map;

class DelayEstimator : public QObject {
  Q_OBJECT
private:
  std::map<std::string, DelayConnection*> clients;
  QTimer *timer;

  DelayConnection *makeDelayConnection(ServerConnection *sc); // create the struct of estimation
  void estimatePing();
  void update(DelayConnection *dc);

public:
  DelayEstimator();
  DelayEstimator(std::list<ServerConnection*> connections);
  ~DelayEstimator();
  bool addServerConnection(ServerConnection *sc);
  map<std::string, uint32_t> getPings(); // returns <username, ping> foreach client
  uint32_t maxPing(); // returns the max ping of all clients in millisecs

public slots:
  void pingFrom(std::string username); // connect(sc, &pingRecv, this, &pingFrom);
};
