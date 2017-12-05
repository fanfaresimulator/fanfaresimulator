#include "../include/serverconnection.hpp"
#include "../include/network_server.hpp"
#include "../include/network_utils.hpp"

/* PRIVATE */
void ServerConnection::handleJsonDoc(QJsonDocument doc) {
    QJsonObject obj = doc.object();
    int type = obj["type"].toInt();

    switch (type) {
      case SIG_HELLO: {
        std::cout << "HELLO" << std::endl;
        QString name = obj["data"].toString();
        if (name.isEmpty()) {
          return;
        }
        setUsername(name.toStdString());
        break;
      }
      case SIG_NOTE: {

        break;
      }

      case SIG_CHOICE_LOBBY: {

        break;
      }

      case SIG_CHOICE_INSTRUMENT: {

        break;
      }

      case SIG_READY: {
        QString s = obj["data"].toString();
        if (s.isEmpty()) {
          return;
        }
        std::string username = s.toStdString();
        emit server->readyReceived(username);
        break;
      }

      default:
        std::cout << "Unsupported type: " << type << std::endl;
        break;

    }
}

void ServerConnection::readyRead() {
  std::cout << "Reading from " << username << std::endl << "##beg##\n";
  QByteArray msg = socket->readAll();
  std::cout <<  QString(msg).toStdString() << std::endl << "##end##\n";

  QJsonParseError jerror;
  QJsonDocument doc = QJsonDocument::fromJson(msg, &jerror);
  if(jerror.error != QJsonParseError::ParseError::NoError) {
    std::cout << jerror.errorString().toStdString() << std::endl;
    return;
  }
}

void ServerConnection::setUsername(std::string username) {
  this->username = username;
}


/* PUBLIC */
ServerConnection::ServerConnection(std::string username, QTcpSocket *socket, NetworkServer *server) {
  this->username = username;
  this->socket = socket;
  this->server = server;
  connect(this->socket, &QIODevice::readyRead, this, &ServerConnection::readyRead);
}

void ServerConnection::write(QByteArray msg) {
  socket->write(msg);
}

std::string ServerConnection::getUsername() {
  return username;
}
