#include "../include/network/SendAfter.hpp"

void SendAfter::send() {
  // could be sending from here... but for now the ServerConnection handles it
  emit sendNow(obj);
  delete this;
}

void SendAfter::start() {
  timer->start();
}

SendAfter::SendAfter(NetworkServer *server, QJsonObject msg, uint32_t time) {
  uint32_t t = time;
  if (time > TIMEOUT_TIME) {
    std::cout << "Too much ping for " << sc->getUsername() << " "
              << TIMEOUT_TIME << " used instead" << std::endl;
    t = TIMEOUT_TIME;
  }
  this->timer = new QTimer();
  this->timer->setSingleShot(true);
  this->timer->setInterval(t);
  this->obj = msg;
  connect(server, &NetworkServer::sendAfterStart, this, &SendAfter::start);
  connect(this->timer, &QTimer::timeout, this, &SendAfter::send);
}
