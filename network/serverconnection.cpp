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
  QByteArray msg = socket->readAll();
  std::cout << "READING\n" <<  QString(msg).toStdString() << std::endl;

  bool ok;
  size_t objBeg = msg.indexOf(';');
  int size = msg.left(objBeg).toInt(&ok,10);
  std::cout << "size:" << size << std::endl;
  if (!ok) { // in the middle of the message
    size = msg.size(); // we take it all...
    objBeg = 0;        // ...from the begining
  }

  QByteArray content = msg.right(size - objBeg + 2); // +1 cannot bug
  pending.append(content);
  std::cout << "pending content" << QString(content).toStdString();
  std::cout << "pending size : "<< pending.size();
  if (pending.size() != size) { // only parts of the message has arrived
    return;
  }
  // message is arrived entirely
  QJsonParseError jerror;
  QJsonDocument doc = QJsonDocument::fromJson(pending, &jerror);
  if(jerror.error != QJsonParseError::ParseError::NoError) {
    std::cout << jerror.errorString().toStdString() << std::endl;
    return;
  }
  pending.clear();
  handleJsonDoc(doc);
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
