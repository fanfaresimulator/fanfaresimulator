#pragma once

#include <QJsonObject>

#include "network.hpp"
#include "serverconnection.hpp"
#include "server.hpp"

class SendAfter : public QObject {
  Q_OBJECT
private:
  QJsonObject obj;
  QTimer *timer;
  ServerConnection *sc;

private slots:
  void send();
  void start();

public:
  SendAfter(NetworkServer *server, QJsonObject msg, uint32_t time);

signals:
  void sendNow(QJsonObject obj);
};
