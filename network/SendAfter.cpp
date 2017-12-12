#include "../include/network/SendAfter.hpp"

void SendAfter::run() {
  sleep(time);
  emit sendNow(obj);
}

SendAfter::SendAfter(NetworkServer *server, QJsonObject msg, size_t time) {
  this->time = time;
  if (time > TIMEOUT_TIME) {
    std::cout << "Too much ping for " << sc->getUsername() << " "
              << TIMEOUT_TIME << " used instead" << std::endl;
    this->time = TIMEOUT_TIME;
  }
  this->obj = msg;
  connect(server, &NetworkServer::sendAfterStart, this, &SendAfter::start);
}
