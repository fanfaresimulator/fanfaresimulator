#pragma once

#include <QJsonObject>

#include "network.hpp"
#include "serverconnection.hpp"
#include "server.hpp"

class SendAfter : public QThread {
  Q_OBJECT
private:
  QJsonObject obj;
  size_t time;
  ServerConnection *sc;

private slots:
  void run();

public:
  SendAfter(NetworkServer *server, QJsonObject msg, size_t time);

signals:
  void sendNow(QJsonObject obj);
};
