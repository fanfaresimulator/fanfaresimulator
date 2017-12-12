#include "../include/network/DelayEstimator.hpp"

DelayConnection *DelayEstimator::makeDelayConnection(ServerConnection *sc) {
  DelayConnection *dc = new DelayConnection();
  dc->sc = sc;
  dc->estimate = TIMEOUT_TIME;
  dc->lastEstimate = QDateTime();
  return dc;
}

void DelayEstimator::estimatePing() {
  for (DE_element client : clients) {
    DelayConnection *dc = client.second;
    QJsonObject ping = pingToJson(0);
    QDateTime now = QDateTime::currentDateTime();
    dc->lastSent = now;
    try {
          dc->sc->write(ping);
    } catch (QException e) {

    }
  }
  // clear();
}

void DelayEstimator::update(DelayConnection *dc) {
  QDateTime now = QDateTime::currentDateTime();
  dc->estimate = dc->lastSent.msecsTo(now) / 2; // RTT /2
  dc->lastEstimate = now;
}

DelayEstimator::DelayEstimator() {
  this->timer = new QTimer();
  this->timer->setInterval(TIMEOUT_TIME);
  connect(timer, &QTimer::timeout, this, &DelayEstimator::estimatePing);
}

DelayEstimator::DelayEstimator(std::list<ServerConnection*> connections) {
  this->timer = new QTimer();
  this->timer->setInterval(TIMEOUT_TIME);
  connect(timer, &QTimer::timeout, this, &DelayEstimator::estimatePing);
  for (ServerConnection* sc : connections) {
    bool ok = addServerConnection(sc);
    if (!ok) {
      std::cout << sc->getUsername() << " already in DelayEstimator" << std::endl;
      return;
    }
  }
  timer->start();
}

DelayEstimator::~DelayEstimator() {
  for (DE_map::iterator i = clients.begin();
     i != clients.end(); i++) {
      delete (i->second);
  }
  delete timer;
}

bool DelayEstimator::addServerConnection(ServerConnection *sc) {
  std::string username = sc->getUsername();
  if (clients.find(username) != clients.end()) {
    std::cout << username <<" already in DelayEstimator" << std::endl;
    return false;
  }
  DE_element elt(sc->getUsername(), makeDelayConnection(sc));
  clients.insert(elt);
  connect(sc, &ServerConnection::pingRecv, this, &DelayEstimator::pingFrom);
  timer->start();
  return true;
}

map<std::string, size_t> DelayEstimator::getPings() {
  std::map<std::string, size_t> pings;
  for (DE_element client : clients) {
    std::pair<std::string, int> elt(client.first, client.second->estimate);
    pings.insert(elt);
  }
  return pings;
}

size_t DelayEstimator::maxPing() {
  size_t max = 0;
  for(auto & client : clients) {
    size_t estimate = client.second->estimate;
    if (estimate > max) {
      max = estimate;
    }
  }
  return max;
}

void DelayEstimator::pingFrom(std::string username) {
  DE_map::iterator client = clients.find(username);
  if (client == clients.end()) {
    std::cout << "Unknown client ("<< username <<")" << std::endl;
    return;
  }
  update(client->second);
}
