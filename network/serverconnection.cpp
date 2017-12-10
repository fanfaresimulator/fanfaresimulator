#include "../include/network/server.hpp"
#include "../include/network/serverconnection.hpp"

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
        emit server->helloRecv(name.toStdString());
        break;
      }
      case SIG_NOTE: {
        Note note = noteFromJson(objectFromJson(obj["data"]));
        emit server->noteRecv(username, note);
        break;
      }

      case SIG_CHOICE_LOBBY: {
        std::cout << "NOT YET IMPLEMENTED" << std::endl;
        break;
      }

      case SIG_CHOICE_PUPITRE: {
        // There is no bool n the Json Parsed but we don't need it (defaultValue = false)
        std::pair<Pupitre, bool> pair = pupitreFromJson(objectFromJson(obj["data"]));
        emit server->pupitreChoiceRecv(username, pair.first);
        break;
      }

      case SIG_READY: {
        emit server->readyRecv(username);
        break;
      }

      default:
        std::cout << "Unsupported type: " << type << std::endl;
        break;

    }
}

void ServerConnection::readyRead() {
  while (socket->bytesAvailable()) {
    if (remainingBytes == 0) {
      char b[sizeof(int)];
      socket->read(b, sizeof(int));
      memcpy(&remainingBytes, &b, sizeof(int));
      std::cout << "MSG size: " << remainingBytes << std::endl;
    }

    QByteArray buffer = socket->read(remainingBytes);
    pending.append(buffer);
    std::cout << "READING " << buffer.size() << "/" << remainingBytes << " from " << username << std::endl;
    remainingBytes -= buffer.size();

    if (remainingBytes != 0) { // message insn't complete
      return;
    }

    // message is arrived entirely
    QJsonParseError jerror;
    QJsonDocument doc = QJsonDocument::fromJson(pending, &jerror);
    if(jerror.error != QJsonParseError::ParseError::NoError) {
      std::cout << "QJsonParseError: "<< jerror.errorString().toStdString() << std::endl;
      std::cout << "With : "<< QString(pending).toStdString();
      return;
    }
    pending.clear();
    handleJsonDoc(doc);
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
  this->remainingBytes = 0;
  connect(this->socket, &QIODevice::readyRead, this, &ServerConnection::readyRead);
}

void ServerConnection::write(QByteArray msg) {
  socket->write(msg, msg.size());
}

void ServerConnection::write(int n) {
  char b[sizeof(int)];
  memcpy(&b, &n, sizeof(int));
  socket->write(b, sizeof(int));
}

std::string ServerConnection::getUsername() {
  return username;
}
