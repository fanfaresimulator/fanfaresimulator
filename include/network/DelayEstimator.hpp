#include <map>
#include <list>
#include <utility>

#include "serverconnection.hpp"
#include "network.hpp"

#define PING_COUNT 10
#define TIMEOUT_TIME 2000

typedef struct {
  ServerConnection *sc;
  size_t estimate;
  QDateTime lastSent;
  // std::map<ping, pair<t0,t1> > pings; // pings with send/receive time
  QDateTime lastEstimate;
} DelayConnection;

typedef std::pair<std::string, DelayConnection*> DE_element;
typedef std::map<std::string, DelayConnection*> DE_map;

class DelayEstimator : public QObject {
  Q_OBJECT
private:
  std::map<std::string, DelayConnection*> clients;
  QTimer *timer;

  DelayConnection *makeDelayConnection(ServerConnection *sc); // create the struct of estimation
  int maxPing(); // returns the max ping of all clients in millisecs
  void estimatePing();
  void update(DelayConnection *dc);

public:
  DelayEstimator();
  DelayEstimator(std::list<ServerConnection*> connections);
  ~DelayEstimator();
  bool addServerConnection(ServerConnection *sc);

public slots:
  void pingFrom(std::string username); // connect(sc, &pingRecv, this, &pingFrom);
};
